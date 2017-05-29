const N = 5;
const M = 1000000;

let ans = 0;
for (let i = 2; i < M; i++) {
  let j = i, res = 0;
  while (j > 0) {
    res += Math.pow(j % 10, N);
    j = Math.floor(j / 10);
  }
  if (i === res)
    ans += i;
}

console.log(ans);