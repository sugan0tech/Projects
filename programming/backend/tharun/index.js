const express = require("express");
const app = express();
app.get("/home", (req, res) => {
    res.status(200).send("<h1> Im tharun</h1>");

});

app.listen(5000);