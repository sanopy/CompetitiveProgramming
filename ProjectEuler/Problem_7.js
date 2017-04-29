const N = 10001;
const M = 100000000000;

let num = [];
let prime = [];

for (let i = 2; i <= Math.sqrt(M); i++) {
  if (!num[i]) {
    prime.push(i);
    for (let j = 2; i*j <= Math.sqrt(M); j++) {
      num[i*j] = true;
    }
  }
}

console.log(prime[N-1]);