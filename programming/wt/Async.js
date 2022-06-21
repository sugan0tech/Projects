console.log("tst")
async function tst() {
    console.log("Say hi in Async");
}
tst().then(() => {
    for (let i = 0; i < 4000000000; i++) {}
    console.log("runned");
})
console.log("hi");