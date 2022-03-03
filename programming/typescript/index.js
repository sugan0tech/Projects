"use strict";
exports.__esModule = true;
var express_1 = require("express");
(0, express_1["default"])().get("/", function (req, res) {
    res.send("hi");
});
(0, express_1["default"])().listen(5000);
console.log("listening on port 5000");
