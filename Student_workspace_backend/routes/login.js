const express = require("express");
const router = express.Router();
const func = require("../functions/auth_func");

router.use((req, res, callback) => {
    console.log(req.url + "@" + new Date);
    callback();
})
router.use(express.json())
router.use(express.urlencoded({ extended: true }))

router.route("/")
    .get((req, res) => {
        res.send("<h1>login page<h1>");
    })
    .post((req, res) => {
        console.log(req.body);
        func.check(req.body.name, req.body.password).then(
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