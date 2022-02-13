const mongoose = require("mongoose");
const url = "mongodb://localhost:27017/test";
mongoose.connect(url, () => {
    console.log("Database Conected")
}, (err) => {
    console.log("Not Connected to Database err occured");
});

module.exports = mongoose;