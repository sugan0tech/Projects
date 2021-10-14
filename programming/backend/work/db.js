var mysql = require('mysql');
var crypto = require('crypto');
var connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: '',
    port: 3307,
    database:'user'
})

function hsh(str)
{
    return crypto.createHash('md5').update(str).digest('hex')
}

function dd(tmp)
{
    var middle = JSON.stringify(tmp)
    return JSON.parse(middle)
}

function ad(user, password) {
    connection.query(`INSERT INTO user_info VALUES ("${user}", "${password}");`, function (err,rows, fields) {
        if (err)
            console.error("error in add")
        else
            var tmp = {"user_name":user, "password":password}
            console.log("updated",tmp) 
    })
}

function auth(user, password, callback) {
    connection.query(`SELECT * FROM user_info WHERE name = "${user}" AND password = "${password}";`, function (err, rows, fields) {
        if(err)
            console.log("Error in Auth")
        else
            if (rows[0]) 
            {
                console.log("found in db", dd(rows[0]))
                return callback(false)
            }
            else
            {
                console.log(hsh(password))
                console.log("Not Found in DB")
                return callback(true)
            }
    })
}

function get(){
    connection.query(`SELECT * FROM user_info`, function (err,rows) {
        if (err)
            console.error("error in add")
        else
            console.log(dd(rows))
    })
}

function del(user, password)
{
    connection.query(`DELETE FROM user_info WHERE name = "${user}" AND password = "${password}"`, function (err,rows) {
        if(err)
        console.log(err)
        else
        console.log("Deleted ", `${user}`, `${password}`, dd(rows))
        return {"status": "Deleted ", "name ": `${user}`, "hash":`${password}` }
    })

}

module.exports = {ad, auth, get, hsh, del}