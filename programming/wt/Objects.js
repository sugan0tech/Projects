// ways to initialize objects
// let obj = new Object()
// let obj = {}
// let obj = Object.create({})
let obj = {
    name: "value",
    field: "fieldValue",
    arr: ["val", "val"],
    obj: {
        name: "tst"
    },
    fun: function() {
        console.log("function inside object");
    }
}
obj.tst = 4;
console.log(obj.obj.phone = 82838);
console.log(obj);
obj.fun();