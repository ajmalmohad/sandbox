use std::io;
use std::collections::HashMap;

fn cached_card(cardno: u32, carddp: &Vec<u32>) -> u32 {
    if carddp[cardno as usize] != 0 {
        return carddp[cardno as usize];
    }else{
        return 0;
    }
}

fn calculate_card(card: Vec<&str>, carddp: &mut Vec<u32>) -> u32 {
    let cardno: u32 = card[0].split_whitespace().collect::<Vec<&str>>()[1].parse().unwrap();
    let winning: Vec<u32> = card[1].split_whitespace().map(|s| s.parse().unwrap()).collect();
    let mynums: Vec<u32> = card[2].split_whitespace().map(|s| s.parse().unwrap()).collect();

    let mut foundwin = HashMap::new();
    let mut wincount:u32 = 0;

    for num in winning {
        foundwin.insert(num, true);
    }

    for num in mynums {
        match foundwin.get(&num) {
            Some(&_) => wincount+=1,
            _ => {},
        }
    }

    carddp[cardno as usize] = wincount;
    return wincount;
}

fn main() {
    let mut input = String::new();
    let mut total = 0;

    println!("Enter number of cards: ");
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let cards: u32 = input.trim().parse().expect("Invalid input");
    
    let mut carddp = vec![0u32; (cards + 1) as usize];
    let mut cardcount = vec![0u32; (cards + 1) as usize];

    for i in 1..=cards {
        input.clear();
        io::stdin().read_line(&mut input).expect("Failed to read input");
        
        let card: Vec<&str> = input.trim().split([':','|']).collect();
        cardcount[i as usize] = 1;
        let count:u32 = calculate_card(card,&mut carddp);

        if count > 0 {
            total +=  1 << (count - 1);
        }
    }

    for i in 1..=cards {
        let matches:u32 = cached_card(i, &carddp);
        let end_range = std::cmp::min(i + matches, cards);
        let no_of_cards = cardcount[i as usize];

        for _ in 0..no_of_cards {
            for j in (i+1)..=end_range {
                cardcount[j as usize] += 1;
            }
        }
    }

    let mut all_cards = 0;
    for i in 1..=cards { 
        all_cards += cardcount[i as usize];
    }

    println!("Part 1: {}", total);
    println!("Part 2: {}", all_cards);
}