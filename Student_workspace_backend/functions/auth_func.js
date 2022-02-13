const user = require("../models/user");
const hash = require("./hash").hash;
const chalk = require("chalk");
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
        console.log(chalk.bold.red.inverse("Error !!! in auth function"));
    }
    return false;
}

async function check(userName, userPassword) {

    try {
        const valid = await user.exists({ $and: [{ name: userName }, { password: hash(userPassword) }] });
        if (valid == null) {
            return false;
        }
    } catch (e) {
        console.log(e);
        console.log(chalk.bold.red.inverse("Error !!! in auth function"));
    }
    return true;
}

async function update(data) {
    try {
        const updateUsr = await user.updateOne(data);
        console.log(updateUsr);
        console.log(chalk.green.bold("\n\t User updated successfully"));

    } catch (e) {
        console.log(e);
        console.log(chalk.bold.red.inverse("Error !!! in auth function"));

    }
}

module.exports = { push, check, update }