let p = new Promise((resolve, reject) => {
    let a = 1 + 1;
    if (a == 2)
        resolve("success");
    else
        resolve("failed");
})

p.then((message) => {
    console.log(message);
    for (let i = 0; i < 1000000000; i++) {}
}).catch((message) => {
    console.log(message);
})


async function fun() {
    const res = await p;
    console.log(res);
}