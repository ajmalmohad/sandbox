use std::io;

fn find_number(matrix: &mut Vec<Vec<char>>, i:usize, j:usize, dim:usize) -> i32 {
    let mut start = j;
    let mut end = j;
    while start > 0 && matrix[i][start].is_numeric() {
        start -= 1;
    }

    if !matrix[i][start].is_numeric() {
        start += 1;
    }

    while end <= dim - 1 && matrix[i][end].is_numeric() {
        end += 1;
    }

    let res: String = matrix[i][start..end].iter().cloned().collect::<String>();

    for k in start..end {
        matrix[i][k] = '.';
    }

    return res.parse().unwrap();
}

fn calculate_value(matrix: &mut Vec<Vec<char>>, dim: usize) {
    let mut count: i32 = 0;
    let mut gears: i32 = 0;

    for i in 0..matrix.len() {
        for j in 0..matrix[i].len() {
            if !matrix[i][j].is_numeric() && matrix[i][j] != '.' {
                let mut temp: i32;
                let star: bool;
                let mut adjacent: i32 = 0;
                let mut gearratio: i32 = 1;

                if matrix[i][j] == '*' {
                    star = true;
                } else {
                    star = false;
                }

                if i > 0 && j > 0 && matrix[i-1][j-1].is_numeric() {
                    temp = find_number(matrix, i-1, j-1, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }

                if i > 0 && matrix[i-1][j].is_numeric() {
                    temp = find_number(matrix, i-1, j, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }

                if i > 0 && j < dim - 1 && matrix[i-1][j+1].is_numeric() {
                    temp = find_number(matrix, i-1, j+1, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }  

                if j > 0 && matrix[i][j-1].is_numeric() {
                    temp = find_number(matrix, i, j-1, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }

                if j < dim - 1 && matrix[i][j+1].is_numeric() {
                    temp = find_number(matrix, i, j+1, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }

                if j < dim - 1 && i < dim - 1 && matrix[i+1][j+1].is_numeric() {
                    temp = find_number(matrix, i+1, j+1, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }

                if i < dim - 1 && matrix[i+1][j].is_numeric() {
                    temp = find_number(matrix, i+1, j, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }

                if i < dim - 1 && j > 0 && matrix[i+1][j-1].is_numeric() {
                    temp = find_number(matrix, i+1, j-1, dim);
                    count += temp;
                    if star && adjacent < 2 {
                        gearratio *= temp;
                    }
                    adjacent += 1;
                }

                if star && adjacent == 2 {
                    gears += gearratio;
                }
            }
        }
    }

    print!("Part 1: {}\n",count);
    print!("Part 2: {}",gears);
}

fn main() {
    let mut input = String::new();

    println!("Enter dimension: ");
    io::stdin().read_line(&mut input).expect("Failed to read input");
    let dimension: usize = input.trim().parse().expect("Invalid input");

    let mut matrix = vec![vec![' '; dimension]; dimension];
    println!("Enter {} strings with {} characters each:", dimension, dimension);

    for i in 0..dimension {
        let mut row_input = String::new();
        io::stdin().read_line(&mut row_input).expect("Failed to read input");
        row_input.truncate(dimension);
        for (j, ch) in row_input.chars().enumerate() {
            matrix[i][j] = ch;
        }
    }

   calculate_value(&mut matrix, dimension);
}
