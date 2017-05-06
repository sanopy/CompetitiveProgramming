const N = 20;

console.log(combination(N*2, N));

function combination(n, r) {
  let ret = 1;

  for (let i = 1; i <= r; i++) {
    ret *= n--;
    ret /= i;   
  }

  return ret;
}