const N = 1000;
let ans = 1;

for (let i = N-1; i > 0; i--) {
  for (let j = N-1; j > 0; j--) {
    if (i*j > ans) {
      let s = '' + (i*j);
      let t = '';
      for (let k = s.length-1; k >= 0; k--)
        t += s[k];

      if (s === t)
        ans = i*j;
    }
  }
}

console.log(ans);