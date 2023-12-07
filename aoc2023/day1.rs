use std::io::*;
use std::fs::File;

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);
    let numbers = vec!["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4", "5", "6", "7", "8", "9"];
    let mut count = 0;

    for line in reader.lines() {
        let text: &str = &line.unwrap();
        let mut minm = text.len();
        let mut minmnum = 0;
        let mut maxm = 0;
        let mut maxmnum = 10;

        for i in 0..numbers.len() {
            match text.find(numbers[i]) {
                Some(idx) => {
                    if idx < minm {
                        minm = idx;
                        minmnum = i+1;
                        if i > 8 {
                            minmnum -= 9;
                        }
                    }                 
                },
                _ => {},
            }

            match text.rfind(numbers[i]) {
                Some(idx) => {
                    if idx >= maxm {
                        maxm = idx;
                        maxmnum = i+1;
                        if i > 8 {
                            maxmnum -= 9;
                        }
                    }                 
                },
                _ => {},
            }
        }

        if maxmnum == 10 {
            maxmnum = minmnum;
        }

        count += minmnum*10 + maxmnum;
    }

    println!("Part 2: {}", count);
}
