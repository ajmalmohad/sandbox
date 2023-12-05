use std::io::*;
use std::fs::File;
use std::cmp;
use std::time::{Duration, Instant};

fn parse_tuple(text: &str) -> Vec<u32> {
    return text
    .trim()
    .split(' ')
    .filter(|x| !x.is_empty())
    .map(|x| x.parse::<u32>().unwrap())
    .take(3)
    .collect();
}

fn parse_seeds(text: &str) -> Vec<u32> {
    return text
    .split(":")
    .collect::<Vec<&str>>()[1]
    .trim().split(' ')
    .filter(|x| !x.is_empty())
    .map(|x| x.parse::<u32>()
    .unwrap()).collect();
}

fn do_mapping(current: u32, map: &Vec<Vec<u32>>) -> u32 {
    let mut value: u32 = current;
    for entity in map {
        if value >= entity[1] && value < entity[1] + entity[2] {
            value = entity[0] + (value - entity[1]);
            break;
        }
    }
    return value;
}

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);
    let mut mode: u32 = 0;
    let mut part1: u32 = std::u32::MAX;
    let mut part2: u32 = std::u32::MAX;

    let mut seeds: Vec<u32> = vec![];
    let mut soils: Vec<Vec<u32>> = Vec::new();
    let mut fertilizers: Vec<Vec<u32>> = Vec::new();
    let mut waters: Vec<Vec<u32>> = Vec::new();
    let mut lights: Vec<Vec<u32>> = Vec::new();
    let mut temperatures: Vec<Vec<u32>> = Vec::new();
    let mut humiditys: Vec<Vec<u32>> = Vec::new();
    let mut locations: Vec<Vec<u32>> = Vec::new();

    let start = Instant::now();
    for line in reader.lines() {
        let text: &str = &line.unwrap();
        if text == "" { continue; }

        if text.contains("seeds:") { mode = 0; }
        else if text == "seed-to-soil map:" { mode = 1; continue; }
        else if text == "soil-to-fertilizer map:" { mode = 2; continue; }
        else if text == "fertilizer-to-water map:" { mode = 3; continue; }
        else if text == "water-to-light map:" { mode = 4; continue; }
        else if text == "light-to-temperature map:" { mode = 5; continue; }
        else if text == "temperature-to-humidity map:" { mode = 6; continue; }
        else if text == "humidity-to-location map:" { mode = 7; continue; }

        match mode{
            0 => {seeds.extend(parse_seeds(text))}
            1 => {soils.push(parse_tuple(text));}
            2 => {fertilizers.push(parse_tuple(text));}
            3 => {waters.push(parse_tuple(text));}
            4 => {lights.push(parse_tuple(text));}
            5 => {temperatures.push(parse_tuple(text));}
            6 => {humiditys.push(parse_tuple(text));}
            7 => {locations.push(parse_tuple(text));}
            _ => {}, 
        }
    }

    for seed in &seeds {
        let mut current: u32 = *seed;
        current = do_mapping(current, &soils);
        current = do_mapping(current, &fertilizers);
        current = do_mapping(current, &waters);
        current = do_mapping(current, &lights);
        current = do_mapping(current, &temperatures);
        current = do_mapping(current, &humiditys);
        current = do_mapping(current, &locations);
        part1 = cmp::min(part1, current);
    }

    for seed_pair in seeds.chunks(2) {
        let start = seed_pair[0];
        let end = seed_pair[0] + seed_pair[1];
        // for num in seed_pair[0]..seed_pair[0]+seed_pair[1]+1 {
        //     let mut current: u32 = num;
        //     current = do_mapping(current, &soils);
        //     current = do_mapping(current, &fertilizers);
        //     current = do_mapping(current, &waters);
        //     current = do_mapping(current, &lights);
        //     current = do_mapping(current, &temperatures);
        //     current = do_mapping(current, &humiditys);
        //     current = do_mapping(current, &locations);
        //     part2 = cmp::min(part2, current);
        // }
    }

    println!("Part 1: {}", part1);
    let duration = start.elapsed();

    println!("Time elapsed: {:?}", duration);
    // println!("Part 2: {}", part2);
}
