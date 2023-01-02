impl Solution {
    pub fn num_of_pairs(nums: Vec<String>, target: String) -> i32 {
        let mut res = 0;

        for i in 0..nums.len() {
            for j in (0..nums.len()).rev() {
                if i == j {
                    continue;
                }
                let s = nums[i].clone() + &nums[j];
                if s == target {
                    res += 1;
                }
            }
        }

        return res;
    }
}

// --------------------------------------------------------------------------------------------------------------

struct  Solution;

fn main() {
    println!("{}", Solution::num_of_pairs(
        vec![
            String::from("777"),
            String::from("7"),
            String::from("77"),
            String::from("77")
        ],
       String::from("7777")
    ));

    println!("{}", Solution::num_of_pairs(
        vec![
            String::from("123"),
            String::from("4"),
            String::from("12"),
            String::from("34")
        ],
       String::from("1234")
    ));

    println!("{}", Solution::num_of_pairs(
        vec![
            String::from("1"),
            String::from("1"),
            String::from("1")
        ],
       String::from("11")
    ));
}
