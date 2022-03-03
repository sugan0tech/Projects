import express from 'express';
express().get("/", (req:express.Request , res:express.Response ) =>
{
  res.send("hi");
})

express().listen(5000);
console.log("listening on port 5000");
