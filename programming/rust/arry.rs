fn main(){
    let mut arr:[i8;10] = [0;10];
    let val:f32 = 2.3;
    arr[1] = 2;
    arr[3] =127;
    println!("{:?}", arr);
    println!("{}", val);
    for elem in arr.iter() {
        println!("element is {}", elem);
    }

    // let mut line:String = String::new();
    let mut line:String = String::with_capacity(4);
    println!("Enter your name :");
    let b1 = std::io::stdin().read_line(&mut line).unwrap();
    let num:i32 = line.trim().parse().unwrap();
    println!("{}", num);
    println!("Hello , {}", line);
    println!("no of bytes read , {}", b1);
}