const express = require("express");
const router = express.Router();
const func = require("../functions/auth_func");

router.use((req, res, callback) => {
    console.log(req.url + "@" + new Date);
    callback();
})
router.use(express.json());
router.use(express.urlencoded({ extended: true }));

router.route("/")
    .get((req, res) => {
        res.status(200).send("<h1>register page<h1>");
    })
    .post((req, res) => {
        console.log(req.body);
        func.push(req.body).then(
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

module.exports = router