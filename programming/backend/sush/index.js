const express = require("express");
const app = express();

app.use(express.json())
app.use(express.urlencoded({ extended: false }))
app.get("/", (request, response) => {
    console.log(request.body);
})

app.post("/", (request, response) => {
    console.log(request.body);
    response.status(200).send(request.body);

})

app.listen(5000, () => { console.log("listening on port 5000") });