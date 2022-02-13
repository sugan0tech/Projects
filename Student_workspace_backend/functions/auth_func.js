const user = require("../models/user");
const hash = require("./hash").hash;
async function push(data) {
    try {
        const valid = await user.exists({ $and: [{ name: data.name }, { password: hash(data.password) }] });
        console.log(data);
        if (valid == null) {
            data.password = hash(data.password);
            const newUser = new user(data);
            await newUser.save();
            return true;
        }
    } catch (e) {
        console.log(e);
    }
    return false;
}

async function check(userName, userPassword) {

    try {
        const valid = await user.exists({ $and: [{ name: userName }, { password: hash(userPassword) }] });
        if (valid == null) {
            console.log("not found ");
            return false;
        }
    } catch (e) {
        console.log(e);
    }
    return true;
}

module.exports = { push, check }