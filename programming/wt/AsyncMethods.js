setTimeout(() => {
    console.log("OnSetTimeOut");
}, 2000);
console.log("statement 1");

setInterval(() => {
    console.log(new Date().getTime());
}, 1000);