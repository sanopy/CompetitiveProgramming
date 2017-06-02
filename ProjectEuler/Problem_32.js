const N = 9;
const M = 1000;

let ans = 0;
let memo = [];
for (let i = 1; i < M; i++) {
  for (let j = i; (''+i+j+(i*j)).length <= N; j++) {
    const s = '' + i + j + (i*j);
    if (isPandigital(s) && !memo[i*j]) {
      memo[i*j] = true;
      ans += i*j;
    }
  }
}
console.log(ans);

function isPandigital(s) {
  if (s.length != N)
    return false;
  for (let i = 1; i <= N; i++)
    if (s.indexOf(''+i) === -1)
      return false;
  return true;
}