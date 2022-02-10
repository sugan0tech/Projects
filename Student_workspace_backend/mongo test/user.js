const mongoose = require('mongoose');

const userSchema = mongoose.Schema({
    name: String,
    passord: String,
    age: Number,
    dept: String,
    created_at: Date,
    updated_at: Date,
    associates: mongoose.SchemaTypes.ObjectId,
    assignments: [mongoose.SchemaTypes.ObjectId]
})

module.exports = mongoose.model("User", userSchema);