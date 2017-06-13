const N = 100000;
let memo = [];

let ans = 0;
for (let i = 3; i < N; i++) {
  let ret = 0, s = '' + i;
  for (let j = 0; j < s.length; j++)
    ret += fact(+s[j]);
  if (ret === i)
    ans += i;
}
console.log(ans);

function fact(n) {
  if (memo[n])
    return memo[n];
  else if (n === 0 || n === 1)
    return memo[n] = 1;
  else
    return memo[n] = fact(n-1) * n;
}
