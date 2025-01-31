use proconio::input;

fn main() {
	input! {
		n: usize,
		a: [usize; n],
	}
	
	let mut get = 0;
	let mut d_get = vec![0; n + 1];
	for i in 0..n {
		get += d_get[i];
		let mut numof_stones = a[i] + get;
		let give_until = std::cmp::min(n - 1, i + numof_stones);
		d_get[i + 1] += 1;
		d_get[give_until + 1] -= 1;
		numof_stones -= give_until - i;
		print!("{} ", numof_stones);
	}
	println!();
}
