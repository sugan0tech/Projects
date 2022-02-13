const express = require("express");
const app = express();
const mongoose = require("mongoose");
const url = "mongodb://localhost:27017/test";
const login = require("./routes/login");
const register = require("./routes/register");

mongoose.connect(url, () => {
    console.log("Database Conected")
}, (err) => {
    console.log("Not Connected to Database err occured");
});

// middlewares
//routes
app.use("/login", login);
app.use("/register", register);

app.get("/", (req, res) => {
    res.status(200).send("<h1>this is the default page</h1>");
})

app.listen(5000);
console.log("listening on port 5000");