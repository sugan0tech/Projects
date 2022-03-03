const express = require('express')
const app = express()
const morgan = require('morgan')
const { logger, logger2, usr } = require("./call_back")

// app.use(morgan('tiny'))
app.use(express.static('./public2'))


app.use(express.urlencoded({ extended: false }))
    /* for api */

app.use(express.json())

app.get('/api/people', (req, res) => {
    res.status(200).json({ success: true, data: usr })
})


/* for root */
app.get('/', (req, res) => {
    console.log(req.body);
    res.send()
})


app.get('/about/:id', (request, response) => {
    response.send('about')
})



app.post("/login", (req, res) => {
    const { name } = req.body;
    console.log(req.body);
    if (name) {
        console.log(name);
        res.status(201).send(`hi ${name}`)
    }
})

app.post("/api/people", (req, res) => {
    res.status(201).send('success')
    console.log(req.body)
})


app.listen(5000, () => {
    console.log("server is running on port 5000....")
})