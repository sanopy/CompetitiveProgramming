use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::new();
        for (i, &v) in nums.iter().enumerate() {
            let x = target - v;
            if map.contains_key(&x) {
                return vec![map[&x], i as i32];
            }
            map.insert(v, i as i32);
        }
        return vec![];
    }
}

// -----------------------------------------------------------------------------------------------------------------

struct Solution;

fn main() {
    println!("{:?}", Solution::two_sum( vec![2, 7, 11, 15], 9));
    println!("{:?}", Solution::two_sum( vec![3, 2, 4], 6));
    println!("{:?}", Solution::two_sum( vec![3, 3], 6));
}
