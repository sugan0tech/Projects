function fun(a)
{
    var b = a;
    while (a) {
        a--;
    }
    console.log("done uuh", b);
}
fun(1000000000);
fun(2);