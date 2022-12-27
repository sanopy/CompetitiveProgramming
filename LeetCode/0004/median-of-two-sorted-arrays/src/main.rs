impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let mid = (nums1.len() + nums2.len()) / 2;
        let is_odd = (nums1.len() + nums2.len()) % 2 == 1;
        let (mut prev1, mut prev2) = (0, 0);
        let (mut i, mut j, mut k) = (0usize, 0usize, 0usize);

        while k <= mid {
            prev2 = prev1;
            if i < nums1.len() && j < nums2.len() {
                if nums1[i] < nums2[j] {
                    prev1 = nums1[i];
                    i += 1;
                } else {
                    prev1 = nums2[j];
                    j += 1;
                }
            } else if i < nums1.len() {
                prev1 = nums1[i];
                i += 1;
            } else {
                prev1 = nums2[j];
                j += 1;
            }
            k += 1;
        }

        if is_odd {
            return prev1 as f64;
        } else {
            return (prev1 + prev2) as f64 / 2.0;
        }
    }
}

// --------------------------------------------------------------------------------------------

struct Solution;

fn main() {
    let v1 = vec![1, 3];
    let v2 = vec![2];
    println!("{}", Solution::find_median_sorted_arrays(v1, v2));

    let v3 = vec![1, 2];
    let v4 = vec![3, 4];
    println!("{}", Solution::find_median_sorted_arrays(v3, v4));
}
