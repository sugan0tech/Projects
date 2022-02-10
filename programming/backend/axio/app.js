const express = require('express');
const path = require('path');
const app = express();


app.use(express.json())
app.use(express.urlencoded({ extended: false }))

app.get("/", (req, res) => {
    res.status(200).send("Dude you just got me")
})

//route for /api/people
app.post("/api/people", async(req, res) => {
    res.status(200).send(" got it")
    console.log(req.body)
})

console.log("listenin on port 5000")
app.listen(5000)