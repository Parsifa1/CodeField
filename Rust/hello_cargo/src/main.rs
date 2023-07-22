fn solve() {
    let mut a = 0;
    let mut b = 1;
    let mut c = 0;
    let mut sum = 0;
    while c < 4000000 {
        c = a + b;
        a = b;
        b = c;
        if c % 2 == 0 {
            sum += c;
        }
    }
    println!("{}", sum);
}
fn main() {
    //输入T，并循环T次solve
    let mut t = String::new();
    std::io::stdin().read_line(&mut t).unwrap();
    let t: i32 = t.trim().parse().unwrap();
    for _ in 0..t {
        solve();
    }

}
