"use strict";
const express = require("express");
const router = express.Router();
router.route("/")
    .get((req, res) => {})
    .post("/login", (req, res) => {
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

module.exports = router