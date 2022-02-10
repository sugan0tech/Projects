const mongoose = require('mongoose');

const userSchema = mongoose.Schema({
    name: String,
    passord: String,
    age: Number,
    sex: String,
    birth_date: Date,
    hobbies: [String], // array
    address: {
        door_number: Number,
        city: String,
        pin_code: Number
    },
    created_at: Date,
    updated_at: Date,
    phone: Number,
    associates: mongoose.SchemaTypes.ObjectId // reference to another object

})

module.exports = mongoose.model("User", userSchema);