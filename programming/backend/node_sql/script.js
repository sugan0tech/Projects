var express = require('express');
var mysql = require('mysql');
var app = express();


var connection = mysql.createConnection({
    host     : 'localhost',
    user     : 'root',
    password : '',
    port     :3306,
    database : 'sampledb' 
});

connection.connect(function(error) {
    if (error) {
        console.log(error);
    }
    else {
        console.log('connected')
    }
});

app.use(express.urlencoded({extended: true}));

app.get('/', function(req, res) {
    res.status(200).send("hi")
    connection.query("SELECT * FROM sample_table;", function(error, rows, fields) {
        if(error)
        {
            console.log("error in querry");
            console.log(error)
        }
        else
        {
            console.log("successfull query");
            console.log(rows, fields)
        }
    })
})

app.get('/do/:id/:text', function(req, res) {
    res.status(200).send("updated")
    console.log(req.params)
    connection.query(`INSERT INTO sample_table VALUES (${req.params.id}, ${req.params.text});`, function(error, rows,fields){
        if (error)
        {
            console.log("erro in updation")
            console.log(error)
        }
        else
        {
            console.log("successfull updated")
        }
    })
})

app.post('/update', function(req, res) {
    res.status(200).send("updated")
    console.log(req.body, res.header, req.url)
    // connection.query(`INSERT INTO sample_table VALUES (${req.params.id}, ${req.params.text});`, function(error, rows,fields){
    //     if (error)
    //     {
    //         console.log("erro in updation")
    //         console.log(error)
    //     }
    //     else
    //     {
    //         console.log("successfull updated")
    //     }
    // })
})
app.listen(1337)