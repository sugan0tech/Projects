var express = require('express');
var db = require('./db');
var app = express();

app.use(express.urlencoded({
    extended: true
}))

app.post('/', function(req, res) {
    res.status(200).send("accepted")
    req.body.password = db.hsh(req.body.password)
    db.auth(`${req.body.user_name}`,`${req.body.password}`, (boo) => {
        if(boo)
        db.ad(`${req.body.user_name}`,`${req.body.password}`)
        else
        console.log("user already exists")
    })
})

app.post('/auth', function(req, res) {
    res.status(200).send("accepted")
    console.log(req.body.user_name, req.body.password)
    req.body.password = db.hsh(req.body.password)
    db.auth(`${req.body.user_name}`,`${req.body.password}`, (boo) => {
        if(boo)
        console.log("user already exists")
    })
})

app.post('/get', function(req, res) {
    res.status(200).send("accepted")
    console.log(req.body)
    db.get()
})

app.post('/del', function(req, res) {
    req.body.password = db.hsh(req.body.password)
    var tmp = db.del(req.body.name,req.body.password)  
    res.status(200).send(["accepted", tmp])
})

app.listen(5000)