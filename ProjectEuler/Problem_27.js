const N = 1000;
const M = 1000000;

let prime = [];

prime[0] = prime[1] = false;
for (let i = 2; i <= M; i++)
  prime[i] = true;

for (let i = 2; i <= M; i++) {
  if (prime[i]) {
    for (let j = 2; i*j <= M; j++) {
      prime[i*j] = false;
    }
  }
}

let max = 0, _a, _b;
for (let a = -N+1; a < N; a++) {
  for (let b = -N; b <= N; b++) {
    for (let n = 0; prime[n*n + a*n + b]; n++) {
      if (max < n) {
        max = n;
        _a = a; _b = b;
      }
    }
  }
}

console.log(_a *_b);