use proconio::input;

fn main() {
    input! {
        n: usize,
        d: usize,
        tl: [(usize, usize); n],
    }
    
    for k in 1..=d {
        let mut max_weight = 0;
        for i in 0..n {
            max_weight = max_weight.max(tl[i].0 * (tl[i].1 + k));
        }
        println!("{max_weight}");
    }
}
