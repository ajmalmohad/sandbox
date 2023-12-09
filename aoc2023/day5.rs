use std::io::*;
use std::fs::File;
use std::cmp;
use std::time::{Instant};

fn parse_tuple(text: &str) -> Vec<u64> {
    return text
    .trim()
    .split(' ')
    .filter(|x| !x.is_empty())
    .map(|x| x.parse::<u64>().unwrap())
    .take(3)
    .collect();
}

fn parse_seeds(text: &str) -> Vec<u64> {
    return text
    .split(":")
    .collect::<Vec<&str>>()[1]
    .trim().split(' ')
    .filter(|x| !x.is_empty())
    .map(|x| x.parse::<u64>()
    .unwrap()).collect();
}

fn do_mapping(current: u64, map: &Vec<Vec<u64>>) -> u64 {
    let mut value: u64 = current;
    for entity in map {
        if value >= entity[1] && value < entity[1] + entity[2] {
            value = entity[0] + (value - entity[1]);
            break;
        }
    }
    return value;
}

fn do_range_mapping(ranges: Vec<(u64, u64)>, map: &Vec<Vec<u64>>) -> Vec<(u64, u64)> {
    let mut new_ranges: Vec<(u64, u64)> = vec![];
    let mut others: Vec<(u64, u64)> = vec![];

    for range in &ranges{
        let mut matched = false;
        for entity in map {
            let entity_range = (entity[1], entity[1] + entity[2]);
            let os = cmp::max(range.0, entity_range.0);
            let oe = cmp::min(range.1, entity_range.1);
            if os < oe {
                new_ranges.push((os - entity[1] + entity[0], oe - entity[1] + entity[0]));
                matched = true;
                if os > range.0 {
                    others.push((range.0, os));
                }
                if range.1 > oe {
                    others.push((oe, range.1));
                }
                break;
            }
        }
        if !matched {new_ranges.push((range.0, range.1));}
    }

    for range in &others{
        for entity in map {
            let entity_range = (entity[1], entity[1] + entity[2]);
            let os = cmp::max(range.0, entity_range.0);
            let oe = cmp::min(range.1, entity_range.1);
            if os < oe {
                let ans = (os - entity_range.0 + entity[0], oe - entity_range.0 + entity[0]);
                new_ranges.push(ans);
            }
        }
    }
        
    return new_ranges;
}

fn main() {
    let file = File::open("./input.txt").unwrap();
    let reader = BufReader::new(file);
    let mut mode: u64 = 0;
    let mut part1: u64 = std::u64::MAX;

    let mut seeds: Vec<u64> = vec![];
    let mut soils: Vec<Vec<u64>> = Vec::new();
    let mut fertilizers: Vec<Vec<u64>> = Vec::new();
    let mut waters: Vec<Vec<u64>> = Vec::new();
    let mut lights: Vec<Vec<u64>> = Vec::new();
    let mut temperatures: Vec<Vec<u64>> = Vec::new();
    let mut humiditys: Vec<Vec<u64>> = Vec::new();
    let mut locations: Vec<Vec<u64>> = Vec::new();

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
        let mut current: u64 = *seed;
        current = do_mapping(current, &soils);
        current = do_mapping(current, &fertilizers);
        current = do_mapping(current, &waters);
        current = do_mapping(current, &lights);
        current = do_mapping(current, &temperatures);
        current = do_mapping(current, &humiditys);
        current = do_mapping(current, &locations);
        part1 = cmp::min(part1, current);
    }

    let mut ranges: Vec<(u64, u64)> = vec![];
    for seed_pair in seeds.chunks(2) {
        ranges.push((seed_pair[0], seed_pair[0] + seed_pair[1] - 1));
    }

    ranges = do_range_mapping(ranges, &soils);
    ranges = do_range_mapping(ranges, &fertilizers);
    ranges = do_range_mapping(ranges, &waters);
    ranges = do_range_mapping(ranges, &lights);
    ranges = do_range_mapping(ranges, &temperatures);
    ranges = do_range_mapping(ranges, &humiditys);
    ranges = do_range_mapping(ranges, &locations);
    ranges.sort();

    println!("Part 1: {}", part1);
    println!("Part 2: {:?}", ranges[0].0);
    let duration = start.elapsed();
    println!("Time elapsed: {:?}", duration);
}
