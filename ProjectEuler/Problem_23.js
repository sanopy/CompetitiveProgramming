const N = 28123;

let perfect_number = [];
for (let i = 1; i <= N; i++) {
  if (i < properDivisorsSum(i))
    perfect_number.push(i);
}

let memo = [];
for (let i = 0; i <= N; i++)
  memo[i] = false;

for (let i = 0; i < perfect_number.length; i++)
  for (let j = 0; j < perfect_number.length; j++)
    memo[perfect_number[i] + perfect_number[j]] = true;

let sum = 0;
for (let i = 1; i <= N; i++)
  if (memo[i] === false)
    sum += i;

console.log(sum);

function properDivisorsSum(x) {
  let ret = 0;
  for (let i = 1; i*i <= x; i++) {
    if (x % i === 0) {
      ret += i;
      if (i !== x/i && x/i !== x)
        ret += x/i;
    }
  }
  return ret;
}