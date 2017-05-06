const N = 500;
const M = 100000;

let tri = [];

tri.push(0);
for (let i = 1; i <= M; i++) {
  tri.push(tri[i-1] + i);
  if (divisor_num(tri[i]) > N) {
    console.log(tri[i]);
    break;
  }
}

function divisor_num(x) {
  let ret = 0;
  for (let i = 1; i*i <= x; i++) {
    if (x % i === 0) {
      ret++;
      if (i !== x/i)
        ret++;
    }
  }
  return ret;
}