const N = 1000000;

let memo = [];
let ans, max = 0;

for (let i = 1; i <= N; i++) {
  let ret = collatz_chain(i);
  if (ret > max) {
    max = ret;
    ans = i;
  }
}

console.log(ans);

function collatz_chain(n) {
  if (memo[n])
    return memo[n];
  else if (n === 1)
    return memo[n] = 1;
  else if (n % 2 === 0)
    return memo[n] = collatz_chain(n/2) + 1;
  else
    return memo[n] = collatz_chain(3*n + 1) + 1;
}