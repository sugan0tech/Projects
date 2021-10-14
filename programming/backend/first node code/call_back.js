const usr_data = [
    {
        id : 1,
        name : "sugan",
        age : 17,
        size : 32
    },
    {
        id : 2,
        name : "don",
        age : 12,
        size : 30
    },
    {
        id : 3,
        name : "gym hacker",
        age : 21,
        size : 35
    },
    {
        id : 4,
        name : "ryder",
        age : 18,
        size : 50
    },
]

const usr = [
    {name : 'sugan', id : 1},
    {name : 'don', id : 2},
    {name : 'gym  hacker ', id : 3},
    {name : 'ryder', id : 4},
]

const logger = (req, res, next) => {
    const method = req.method
    const url = req.url
    const time = new Date().getFullYear()
    console.log(method, url, time)
    next()
}

const logger2 = (req, res, next) => {
    console.log(req.params)
    next()
}

module.exports = {usr, usr_data, logger, logger2}