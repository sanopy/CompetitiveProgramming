const N = 10000;

let memo = [];

let sum = 0;
for (let i = 0; i < N; i++) {
  const s = properDivisorsSum(i);
  if (properDivisorsSum(s) === i && s != i)
    sum += i;
}

console.log(sum);

function properDivisorsSum(x) {
  if (memo[x])
    return memo[x];

  let ret = 0;
  for (let i = 1; i*i <= x; i++) {
    if (x % i === 0) {
      ret += i;
      if (i !== x/i && x/i !== x)
        ret += x/i;
    }
  }
  return memo[x] = ret;
}