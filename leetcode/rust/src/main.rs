fn contains_duplicate(mut nums: Vec<i32>) -> bool {
    nums.sort();

    for i in 0..nums.len() - 1 {
        if nums.get(i).unwrap() == nums.get(i + 1).unwrap() {
            return true;
        }
    }

    return false;
}

fn main() {
    assert_eq!(contains_duplicate(vec![1, 2, 3, 2, 1]), true);
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn first_test() {
        assert_eq!(contains_duplicate(vec![1, 2, 3, 2, 1]), false);
    }
}
