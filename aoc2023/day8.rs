use std::fs::File;
use std::io::*;
use std::collections::HashMap;

fn step(current: String, dirn: char, moves: &HashMap<String, (String, String)>) -> String {
    if dirn == 'L' { return moves.get(&current).unwrap().0.to_string(); }
    else{ return moves.get(&current).unwrap().1.to_string(); }
}

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);
    let prob_parts = vec![2];

    let mut movements: Vec<char> = vec![];
    let mut moves: HashMap<String, (String, String)> = HashMap::new();
    let mut movers: Vec<String> = vec![];

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
            if parts[0].ends_with("A") { movers.push(parts[0].to_string()); }
        }

        index += 1;
    }

    if prob_parts.contains(&1) {
        index = 0;
        let mut steps = 0;
        let mut ans:String = "AAA".to_string();
        let targ:String = "ZZZ".to_string();
        while ans != targ {
            let dirn = movements[index];
            ans = step(ans, dirn, &moves);
            index = (index + 1) % movements.len();
            steps += 1;
        }

        println!("Part 1: {}", steps); 
    }
    
    // Brute force - Too long to run
    if prob_parts.contains(&2){
        let mut idx: usize = 0;
        let mut steps = 0;
        let start_a_count = movers.len();
        let mut end_z_count = 0;
        let mut dirn;
        let mut ans;
        while start_a_count != end_z_count {
            end_z_count = 0;
            for i in 0..movers.len() {
                dirn = movements[idx];
                ans = step(movers[i].to_string(), dirn, &moves);
                if ans.ends_with("Z") { end_z_count += 1; }
                movers[i] = ans;
            }
            steps += 1;
            idx = (idx + 1) % movements.len();
        }
        
        println!("Part 2: {}", steps); 
    }
}