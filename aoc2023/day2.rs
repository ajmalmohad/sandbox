use std::io::*;
use std::fs::File;

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);
    let mut total = 0;
    let mut total1 = 0;
    let mut gameno = 0;

    for line in reader.lines() {
        let text: &str = &line.unwrap();
        let parts: Vec<&str> = text.split(':').collect();
        let mut all_games: Vec<(u32, u32, u32)> = vec![];
        gameno += 1;

        let games: Vec<&str> = parts[1]
        .split(';')
        .map(|x| x.trim())
        .collect::<Vec<&str>>();

        for game in &games {
            let mut tup: (u32, u32, u32) = (0, 0, 0);

            let items: Vec<&str> = game
            .split('"')
            .collect();

            for item in &items {
                
                let atoms: Vec<&str> = item
                .split(',')
                .map(|x| x.trim())
                .collect();

                for atom in &atoms {

                    let proton: Vec<&str> = atom
                    .split(' ')
                    .collect();

                    match proton[1] {
                        "red" => {tup.0 = proton[0].parse().unwrap()}
                        "green" => {tup.1 = proton[0].parse().unwrap()}
                        "blue" => {tup.2 = proton[0].parse().unwrap()}
                        &_ => {}
                    }
                }

            }
            
            all_games.push(tup);
        }

        let mut mincol: (u32, u32, u32) = (0, 0, 0);
        let mut is_valid = true;
        for game in &all_games {

            if game.0 > 12 || game.1 > 13 || game.2 > 14 {
                is_valid = false;
            }

            if game.0 > mincol.0 {
                mincol.0 = game.0;
            }
            
            if game.1 > mincol.1 {
                mincol.1 = game.1;
            }

            if game.2 > mincol.2 {
                mincol.2 = game.2;
            }
        }

        if is_valid {
            total1 += gameno;
        }

        total += mincol.0 * mincol.1 * mincol.2;
    }

    println!("Part 1: {}", total1);
    println!("Part 2: {}", total);
}