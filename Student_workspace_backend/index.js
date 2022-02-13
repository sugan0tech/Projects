const express = require("express");
const app = express();
const mongoose = require("mongoose");
const user = require("./models/user");
const url = "mongodb://localhost:27017/test";
const hash = require("./hash").hash;
const login = require("./routes/login");

mongoose.connect(url, () => {
    console.log("Database Conected")
}, (err) => {
    console.log("Not Connected to Database err occured");
});

app.use("/login", login);
// middlewares
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

app.get("/", (req, res) => {
    res.status(200).send("<h1>this is the default page</h1>");
})

app.post("/login", (req, res) => {
    console.log(req.body);
    check(req.body.name, req.body.password).then(
        (value) => {
            if (value == false)
                res.send("not found");
            else
                res.send("found it");
        },
        (err) => {
            console.log("error occured");
            res.send("error occured in login");
        }
    );
})

app.post("/register", (req, res) => {
    push(req.body).then(
        (value) => {
            if (value)
                res.send("data updated successfully");
            else
                res.send("user already exists");
        },
        (err) => {
            res.send("Error occured in updation");
        }

    );
})

async function push(data) {
    try {
        const valid = await user.exists({ $and: [{ name: data.name }, { password: hash(data.password) }] });
        if (valid == null) {
            data.password = hash(data.password);
            const newUser = new user(data);
            await newUser.save();
            return true;
        }
    } catch (e) {
        console.log(e);
    }
    return false;
}

async function check(userName, userPassword) {

    try {
        const valid = await user.exists({ $and: [{ name: userName }, { password: hash(userPassword) }] });
        if (valid == null) {
            console.log("not found ");
            return false;
        }
    } catch (e) {
        console.log(e);
    }
    return true;
}

app.listen(5000);
console.log("listening on port 5000");