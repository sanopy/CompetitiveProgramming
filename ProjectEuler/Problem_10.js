const N = 2000000;

let num = [];
let ans = 0;

for (let i = 2; i <= N; i++) {
  if (!num[i]) {
    ans += i;
    for (let j = 2; i*j <= N; j++) {
      num[i*j] = true;
    }
  }
}

console.log(ans);