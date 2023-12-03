use std::collections::HashMap;

use anyhow::{Result, bail};
use regex::Regex;



fn main() -> Result<()> {
    let input = std::fs::read_to_string("input")?;
    let mut part1_answer = 0;
    let mut part2_answer = 0;

    for line in input.lines() {
        let mut line = line.to_string();

        let re_game_num = Regex::new("(?:Game) ([0-9]+)")?;

        let game_num = re_game_num.captures(&line).unwrap().extract::<1>().1[0];
        let game_num = game_num.parse::<u32>()?;

        let re_game = Regex::new("([0-9]+) (red|blue|green)")?;
        let mut possible = true;

        let mut max = (0, 0, 0);

        for (_, [count, color]) in re_game.captures_iter(&line).map(|c| c.extract()) {
            let count = count.parse::<u32>()?;
            match color {
                "red" => {
                    if count > 12 {
                        possible = false;
                    }
                    if max.0 < count {
                        max.0 = count;
                    }
                }
                "green" => {
                    if count > 13 {
                        possible = false;
                    }
                    if max.1 < count {
                        max.1 = count;
                    }
                    
                }
                "blue" => {
                    if count > 14 {
                        possible = false;
                    }
                    if max.2 < count {
                        max.2 = count;
                    }
                }
                t => bail!("owo not gud: {t:?}")
            }
        }

        if possible {
            part1_answer += game_num;
        }

        part2_answer += max.0 * max.1 * max.2;

    }

    println!("part1 answer: {}", part1_answer);
    println!("part2 answer: {}", part2_answer);

    Ok(())
}

