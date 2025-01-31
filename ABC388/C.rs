use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [usize; n],
    }
    
    let mut larger = 0;
    let mut count = 0;
    for smaller in 0..n {
    	while larger < n && a[smaller] * 2 > a[larger] {larger += 1;}
    	if (larger == n) {break;}
    	count += n - larger;
    }
    
    println!("{}", count);
}
