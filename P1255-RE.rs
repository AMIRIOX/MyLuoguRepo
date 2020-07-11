use std::io;
fn main() {
    // fn to_usize(val: i32)-> usize {
    //     return val: i32 as usize;
    // }
    let mut n = String::new();
    io::stdin().read_line(& mut n).expect("input error");
    let mut n : usize = n.trim().parse().expect("cast error");
    let mut f : Vec<i64> = vec![0,1,2];
    for i in 3..n+2 {
        // let a: usize = to_usize(i-1);
        // let b:usize = to_usize(i-2);
        let index_i: usize = i-1;
        let index_j:usize = i-2;
        let a = f[index_i];
        let b = f[index_j];
        {
            f.push(a+b);
        }
    }
    println!("{}",f[n]);
}