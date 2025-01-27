use proconio::input;
use proconio::marker::Chars;

fn main() {
	input! {
		s: Chars,
	}
	let upc: String = format!("{}UPC", s[0]);
	println!("{upc}");
}