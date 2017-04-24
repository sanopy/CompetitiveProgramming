const N = 4000000;
let fib = [0, 1, 2]
let ans = 2;

for (let i = 3; ; i++) {
  fib[i] = fib[i-1] + fib[i-2];
  if (fib[i] > N)
    break;
  if (fib[i] % 2 === 0)
    ans += fib[i];
}

console.log(ans);