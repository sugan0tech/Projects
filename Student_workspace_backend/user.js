const mongoose = require("mongoose");
const userSchema = mongoose.Schema({
    name: {
        type: String,
        required: true,
    },
    password: {
        type: String,
        required: true,
    },
    age: {
        type: Number,
        min: 18,
        max: 100
    },
    createdAt: {
        type: Date,
        default: new Date,
        immutable: false
    },
    changedAt: {
        type: Date,
        default: new Date,
        immutable: true,
    }
})

module.exports = mongoose.model("User", userSchema)