
use std::io::stdin;
// use std::cmp::min;
fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).expect("Error read line");
    let t: i32 = input.trim().parse().expect("Error parse");
    for _ in 0..t {
        let mut input = String::new();
        stdin().read_line(&mut input).expect("Error read line");
        let mut iter = input.split_whitespace();
        let n: i64 = iter.next().unwrap().parse().expect("Error parse");
        let c: i128 = iter.next().unwrap().parse().expect("Error parse");
        let mut input = String::new();
        stdin().read_line(&mut input).expect("Error read line");
        let mut iter = input.split_whitespace();
        let mut s: Vec<i64> = vec![];
        for _ in 0..n {
            let num: i64 = iter.next().unwrap().parse().expect("Error parse");
            s.push(num);
        }
        let mut ans: i128 = 0;
        // 二分答案
        let mut l: i64 = 1;
        let mut r: i64 = (c as f64).sqrt() as i64 + 1;
        while l <= r {
            let mid: i64 = l + (r - l) / 2;
            ans = 0;
            for i in 0..n {
                ans += (s[i as usize] + 2 * mid).pow(2) as i128;
            }
            if ans < c {
                l = mid;
            } else if ans > c {
                r = mid;
            } else {
                break;
            }
        }
        let ans = l;
        println!("{}", ans);
    }
}
