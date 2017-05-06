let N = 1000;
let ans = 0;

for (let i = 0; i < N; i++) {
  if (i % 3 === 0 || i % 5 === 0)
    ans += i;
}

console.log(ans);
