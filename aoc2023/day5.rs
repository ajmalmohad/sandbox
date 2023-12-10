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

fn do_range_mapping(ranges: &mut Vec<(u64, u64)>, map: &Vec<Vec<u64>>) -> Vec<(u64, u64)> {
    let mut new_ranges: Vec<(u64, u64)> = vec![];
    let mut i = 0;

    while i < ranges.len() {
        let mut matched = false;
        for entity in map {
            let entity_range = (entity[1], entity[1] + entity[2]);
            let os = cmp::max(ranges[i].0, entity_range.0);
            let oe = cmp::min(ranges[i].1, entity_range.1);
            if os < oe {
                new_ranges.push((os - entity[1] + entity[0], oe - entity[1] + entity[0]));
                matched = true;
                // Check these again for other matches
                if os > ranges[i].0 { ranges.push((ranges[i].0, os)); }
                if ranges[i].1 > oe { ranges.push((oe, ranges[i].1)); }
                // If a match found we can break
                break;
            }
        }
        if !matched {new_ranges.push((ranges[i].0, ranges[i].1));}
        i+=1;
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

    ranges = do_range_mapping(&mut ranges, &soils);
    ranges = do_range_mapping(&mut ranges, &fertilizers);
    ranges = do_range_mapping(&mut ranges, &waters);
    ranges = do_range_mapping(&mut ranges, &lights);
    ranges = do_range_mapping(&mut ranges, &temperatures);
    ranges = do_range_mapping(&mut ranges, &humiditys);
    ranges = do_range_mapping(&mut ranges, &locations);
    ranges.sort();

    println!("Part 1: {}", part1);
    println!("Part 2: {:?}", ranges[0].0);
    let duration = start.elapsed();
    println!("Time elapsed: {:?}", duration);
}
