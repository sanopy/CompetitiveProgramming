impl Solution {
  pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
    return Self::add(l1, l2, false);
  }

  fn add(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, c: bool) -> Option<Box<ListNode>> {
    match (l1, l2) {
      (None, None) => return if c { Some(Box::new(ListNode::new(1))) } else { None },
      (None, Some(l2)) => {
        let (mut l, c) = Self::add_carry(l2.val, c);
        l.next = Self::add(None, l2.next, c);
        return Some(l);
      },
      (Some(l1), None) => {
        let (mut l, c) = Self::add_carry(l1.val, c);
        l.next = Self::add(None, l1.next, c);
        return Some(l);
      },
      (Some(l1), Some(l2)) => {
        let x = l1.val + l2.val + if c { 1 } else { 0 };
        let s = x % 10;
        let mut l = Box::new(ListNode::new(s));
        l.next = Self::add(l1.next, l2.next, x >= 10);
        return Some(l);
      },
    }
  }

  fn add_carry(val: i32, c: bool) -> (Box<ListNode>, bool) {
    let x = val + if c { 1 } else { 0 };
    let s = x % 10;
    return (Box::new(ListNode::new(s)), x >= 10);
  }
}

// -----------------------------------------------------------------------------------------------------------------

struct Solution;

// Definition for singly-linked list.
#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }

  fn push(&mut self, val: i32) {
    match &mut self.next {
      None => self.next = Some(Box::new(ListNode::new(val))),
      Some(next) => Self::push(next, val),
    }
  }
}

fn main() {
  let mut l1 = Box::new(ListNode::new(3));
  l1.push(4);
  l1.push(2);
  let mut l2 = Box::new(ListNode::new(5));
  l2.push(6);
  l2.push(4);
  println!("{:?}", Solution::add_two_numbers(Some(l1), Some(l2)));

  l1 = Box::new(ListNode::new(0));
  l2 = Box::new(ListNode::new(0));
  println!("{:?}", Solution::add_two_numbers(Some(l1), Some(l2)));

  l1 = Box::new(ListNode::new(9));
  l1.push(9);
  l1.push(9);
  l1.push(9);
  l1.push(9);
  l1.push(9);
  l1.push(9);
  l2 = Box::new(ListNode::new(9));
  l2.push(9);
  l2.push(9);
  l2.push(9);
  println!("{:?}", Solution::add_two_numbers(Some(l1), Some(l2)));
}
