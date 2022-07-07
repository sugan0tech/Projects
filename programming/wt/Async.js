// console.log("tst")
// async function tst() {
//     for (let i = 0; i < 4000000; i++) {}
//     console.log("Say hi in Async");

// }
// tst().then(() => {
//     for (let i = 0; i < 4000000; i++) {}
//     console.log("runned");
// })
// console.log("hi");

async function one() {
    for (let i = 0; i < 4000000; i++) {}
    return 1;
}
async function two() {
    let b = await one();
    console.log(b);
}
console.log("end")