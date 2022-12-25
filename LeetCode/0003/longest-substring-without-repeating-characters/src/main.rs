use std::cmp;
use std::collections::HashMap;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut res = 0;
        let mut head = 0;
        let mut used = HashMap::new();

        for (i, c) in s.chars().enumerate() {
            match used.get(&c) {
                Some(pos) => head = cmp::max(head, *pos as i32 + 1),
                _ => (),
            }
            res = cmp::max(res, (i as i32 + 1) - head);
            used.insert(c, i);
        }

        return res;
    }
}

// --------------------------------------------------------------------------------------

struct Solution;

fn main() {
    println!("{}", Solution::length_of_longest_substring("abcabcbb".to_string()));
    println!("{}", Solution::length_of_longest_substring("bbbbb".to_string()));
    println!("{}", Solution::length_of_longest_substring("pwwkew".to_string()));
}
