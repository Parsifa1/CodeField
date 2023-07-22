use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("failed to read input");
    let t: i32 = input.trim().parse().expect("failed to parse input");
    for _i in 0..t {
        input.clear();
        io::stdin().read_line(&mut input).expect("failed to read input");
        let mut iter = input.split_whitespace();
        let n: i64 = iter.next().unwrap().parse().expect("failed to parse input");
        let c: i128 = iter.next().unwrap().parse().expect("failed to parse input");
        input.clear();
        io::stdin().read_line(&mut input).expect("failed to read input");
        let mut iter = input.split_whitespace();
        let mut s: Vec<i64> = Vec::new();
        for _j in 0..n {
            let x: i64 = iter.next().unwrap().parse().expect("failed to parse input");
            s.push(x);
        }
        let mut l: i64 = 1;
        let mut r: i64 = (c as f64).sqrt() as i64 + 1;
        let mut ans: i64 = 0;
        while l <= r {
            let mid: i64 = l + (r - l) / 2;
            let mut ans128: i128 = 0;
            for i in 0..n as usize {
                ans128 += (s[i] + 2 * mid) as i128 * (s[i] + 2 * mid) as i128;
            }
            if ans128 < c {
                l = mid + 1;
                ans = mid;
            } else if ans128 > c {
                r = mid - 1;
            } else {
                ans = mid;
                break;
            }
        }
        println!("{}", ans);
    }
}