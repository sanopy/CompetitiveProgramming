const N = 10001;
const M = 1000000;

let num = [];
let prime = [];

for (let i = 2; i <= M; i++) {
  if (!num[i]) {
    prime.push(i);
    for (let j = 2; i*j <= M; j++) {
      num[i*j] = true;
    }
  }
}

console.log(prime[N-1]);