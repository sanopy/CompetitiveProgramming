const fs = require('fs');

const alph = {
  A: 1, B: 2, C: 3, D: 4, E: 5, F: 6, G: 7, H: 8, I: 9, J: 10,
  K: 11, L: 12, M: 13, N: 14, O: 15, P: 16, Q: 17, R: 18, S: 19,
  T: 20, U: 21, V: 22, W: 23, X: 24, Y: 25, Z: 26
};
fs.readFile('input/p022_names.txt', 'ascii', (err, data) => {
  if (err) throw err;
  data = data.replace(/"/g, '').split(',').sort();
  let ans = 0;
  for (let i = 0; i < data.length; i++) {
    let s = 0;
    for (let j = 0; j < data[i].length; j++) {
      s += alph[data[i][j]];
    }
    ans += s * (i+1);
  }
  console.log(ans);
});