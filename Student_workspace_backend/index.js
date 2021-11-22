const chalk = require('chalk');
const db = require('./db');
const express = require('express');
const app = express();

console.log(chalk.green.inverse.bold("Listening on port 5000"));

app.use(express.urlencoded({extended : false}))
db.insert(2, "kali", "saamplehas");


app.post("/", (req, res) => {
    res.status(200);
    res.send("hi there");
    console.log("got you");
    var tmp = req.body;
    if(tmp.flag == "insert")
        db.insert(tmp.id, tmp.name, tmp.hash);
    else
        db.drop();
})

app.listen(5000)