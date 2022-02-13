"use strict";
const express = require("express");
const router = express.Router();
const functions = require("../functions/login_func");
router.route("/")
    .get((req, res) => {})
    .post((req, res) => {
        console.log(req.body);
        functions.check(req.body.name, req.body.password).then(
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