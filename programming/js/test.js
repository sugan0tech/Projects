function test() {
    console.log("hi")
}

function test2(fun) {
    fun();
}

test2(() => { console.log("HI") });