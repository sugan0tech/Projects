const sql = require("mysql");

const connection = sql.createConnection({
  host:'localhost',
  user:'root',
  port: 3306,
  password: '',
  database: "SW"
})
connection.query("SELECT * FROM user_info;");


function insert(id, name, hash){
  connection.query(`INSERT INTO user_info VALUES (${id}, '${name}', '${hash}');`);
}

function drop(){
  connection.query("DELETE FROM user_info;");
}


module.exports = {insert, drop}