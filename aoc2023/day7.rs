use std::io::*;
use std::fs::File;

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);

    for line in reader.lines() {
        let text: &str = &line.unwrap();
        println!("{:?}", text);
    }
}
