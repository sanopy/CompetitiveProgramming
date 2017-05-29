const N = 200;
const C = [1, 2, 5, 10, 20, 50, 100, 200];

function counting(idx, sum) {
  if (idx < 0 && sum === N)
    return 1;
  if (idx < 0 || sum > N)
    return 0;
  let ret = 0;
  for (let i = 0; sum + C[idx]*i <= N; i++)
    ret += counting(idx-1, sum + C[idx]*i);
  return ret;
}

console.log(counting(C.length-1, 0));