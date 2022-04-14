const test = "hiow"
const regrex = /^([\w])+/i;
console.log(regrex.test(test))

var val = /^w[abc]$/


let userName = /^([\w]){8, 12}/
let password = /^([\w]||[\d]){8,12}/i
let mail = /^\w([\w\d])+@\w([\w])+([.\w])+$/
console.log()
console.log(password.test("passwordsi"))
console.log(mail.test("sugan@gmail.com.in"))