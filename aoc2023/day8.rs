use std::fs::File;
use std::io::*;
use std::collections::HashMap;

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);

    let mut movements: Vec<char> = vec![];
    let mut moves: HashMap<String, (String, String)> = HashMap::new();

    let mut index = 0;
    for line in reader.lines() {
        let textline = line.unwrap();
        let text: &str = &textline;
        if text.is_empty() { continue; }

        if index == 0 {
            movements = text.chars().collect();
        }else{
            let parts: Vec<&str> = text
            .split(['=',','])
            .map(|s| s.trim_matches(['(',')',' '].as_ref()))
            .collect();
            moves.insert(parts[0].to_string(), (parts[1].to_string(), parts[2].to_string()));
        }

        index += 1;
    }

    index = 0;
    let mut steps = 0;
    let mut ans:String = "AAA".to_string();
    let targ:String = "ZZZ".to_string();
    while ans != targ {
        let dirn = movements[index];
        if dirn == 'L' {
            ans = moves.get(&ans).unwrap().0.to_string();
        }else{ 
            ans = moves.get(&ans).unwrap().1.to_string();
        }
        index = (index + 1) % movements.len();
        steps += 1;
    }

    println!("Part 1: {}", steps);   
}