use proconio::input;
use proconio::marker::Chars;

fn main() {
	input! {
		n: usize,
		d: usize,
		tl: [(i32, i32); n],
	}
	let mut t = vec![0 as i32; n];
	let mut l = vec![0 as i32; n];
	for (i, &(t, l)) in tl.iter().enumerate() {
		t[i] = t;
		l[i] = l;
	}
	
	for k in 1..=d {
		println!("{k}");
	}
}