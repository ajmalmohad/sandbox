use std::fs::File;
use std::io::*;

fn parse_values(text: &str) -> Vec<u64> {
    return text
    .split(':')
    .nth(1)
    .unwrap_or("")
    .split_whitespace()
    .map(|x| x.parse::<u64>().unwrap_or(0))
    .collect();
}

fn parse_int(text: &str) -> u64 {
    return text
    .split(':')
    .nth(1)
    .unwrap_or("")
    .split_whitespace()
    .collect::<String>()
    .parse::<u64>()
    .unwrap_or(0);
}

fn is_higher(hold: u64, duration: u64, record: u64) -> bool{
    if hold * (duration - hold) > record {
        return true;
    }else{
        return false;
    }
}

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);

    let mut first = true;
    let mut time: Vec<u64> = vec![];
    let mut record: Vec<u64> = vec![];

    for line in reader.lines() {
        let text: &str = &line.unwrap();
        if first { 
            time = parse_values(text); 
            time.push(parse_int(text));
        }
        else { 
            record = parse_values(text); 
            record.push(parse_int(text));
        }
        first = false;
    }

    let mut total =  1;
    for i in 0..time.len() {

        let mut curr = 0;
        for j in 1..=(time[i]/2) {
            if is_higher(j, time[i], record[i]) { curr += 1; }
        }
        curr *= 2;

        if time[i]%2 == 0 && is_higher(time[i]/2, time[i], record[i]) { 
            curr -= 1; 
        }
        
        if i == time.len() - 1 {
            println!("Part 1: {}", total);
            println!("Part 2: {}", curr);
        }else if curr > 0 { 
            total *= curr; 
        }
    }
}