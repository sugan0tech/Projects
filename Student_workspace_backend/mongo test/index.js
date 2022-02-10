const express = require("express");
const app = express();
const mongo = require("mongoose");
const User = require("./user");
const classwork = require("./classwork");
const url = "mongodb://localhost:27017/test";

app.use(express.json());
app.use(express.urlencoded({ extended: true }));
mongo.connect(url, () => console.log("connected"), (err) => console.log("error"));

app.get("/", (req, res) => {
    res.status(200).send("<h1>yo what's up <h1>");
})
app.post("/", (req, res) => {
    console.log(req.body);
    res.send("post");
})
const user = new User({ name: "sugan", age: 18, sex: 1, address: "nothing", phone: 8123423 });
console.log(user);

user.save().then(() => console.log("saved"));

app.listen(5000, () => { console.log("listening on port no 5000") });