fn main(){
    let arr:[i32; 10] = [0; 10];
    println!("array : {:?}", arr);
    let st:&str = "string";
    let val:i8 = 2;
    if val > 3{
        println!("Worked");
    }
    else{
        println!("Not worked");
    }
    for x in 1..22{
        println!("x as {}", x);
    }
    let emoji:char = '😁';
    println!("{}", emoji);
    println!("{}", st);
    println!("{}", val);
    println!("hi there");
    println!("returned value{}", test(4));
}

fn test(val : i32) -> i32{
    println!("test function");
    val
}