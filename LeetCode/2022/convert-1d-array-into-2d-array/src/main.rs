impl Solution {
    pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();

        if original.len() != (m * n) as usize {
            return res;
        }

        let mut v: Vec<i32> = Vec::new();
        let mut cnt = 0;
        for x in original.iter() {
            if cnt == n {
                res.push(v);
                v = Vec::new();
                cnt = 0;
            }
            v.push(*x);
            cnt += 1;
        }
        res.push(v);

        return res;
    }
}

// ---------------------------------------------------------------------------------------

struct  Solution;

fn main() {
    println!("{:?}", Solution::construct2_d_array(vec![1, 2, 3, 4], 2, 2));
    println!("{:?}", Solution::construct2_d_array(vec![1, 2, 3], 1, 3));
    println!("{:?}", Solution::construct2_d_array(vec![1, 2], 1, 1));
}
