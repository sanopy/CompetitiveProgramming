const N = 20;
let memo = {};

console.log(solve(1, 1));

function solve(num, mul) {
  if (memo[[num, mul]])
    return memo[[num, mul]];

  if (num > N) {
    for (let i = 1; i <= N; i++) {
      if (mul % i !== 0)
        return memo[[num, mul]] = Infinity;
    }
    return mul;
  } else {
    return memo[[num, mul]] = Math.min(solve(num+1, mul), solve(num+1, mul*num));
  }
}