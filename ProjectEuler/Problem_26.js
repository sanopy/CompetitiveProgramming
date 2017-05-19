const N = 1000;

let ans, max = 0;
for (let d = 2; d < N; d++) {
  let n = 1, q, arr = [];
  do {
    q = n % d;
    n = q * 10;
    if (arr.includes(q))
      break;
    arr.push(q);
  } while (q !== 0);
  if (q !== 0 && max < arr.length-arr.indexOf(q)) {
    max = arr.length-arr.indexOf(q);
    ans = d;
  }
}

console.log(ans);