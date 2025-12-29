use std::{cmp::max, collections::HashMap};

impl Solution {
    pub fn ways_to_partition(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut head = vec![0i64; n];
        let mut tail = vec![0i64; n];

        head[0] = nums[0] as i64;
        tail[n-1] = nums[n-1] as i64;
        for i in 1..n {
            head[i] = head[i-1] + nums[i] as i64;
            tail[n-i-1] = tail[n-i] + nums[n-i-1] as i64;
        }

        let mut cnt = HashMap::new();
        for i in 1..n {
            let d = head[i-1] - tail[i];
            *cnt.entry(d).or_insert(0) += 1;
        }

        let mut used = HashMap::new();
        let mut res = *cnt.get(&0).unwrap_or(&0);
        for i in 0..n {
            let d = (k - nums[i]) as i64;
            let v1 = *cnt.get(&-d).unwrap_or(&0);
            let v2 = *used.get(&d).unwrap_or(&0);
            res = max(res, v1 + v2);

            if i < n-1 {
                let s = head[i] - tail[i+1];
                if let Some(v) = cnt.get_mut(&s) {
                    *v -= 1;
                }
                *used.entry(s).or_insert(0) += 1;
            }
        }

        return res;
    }
}

// -----------------------------------------------------------------------------------------------------------------

struct Solution;

fn main() {
    println!("{}", Solution::ways_to_partition(vec![2, -1, 2], 3));
    println!("{}", Solution::ways_to_partition(vec![0, 0, 0], 1));
    println!("{}", Solution::ways_to_partition(vec![22, 4, -25, -20, -15, 15, -16, 7, 19, -10, 0, -13, -14], -33));
}
