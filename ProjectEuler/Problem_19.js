const start = {Y: 1901, M:  1, D: 1};
const end   = {Y: 2000, M: 12, D: 1};

let ans = 0;
for (let y = start.Y; y <= end.Y; y++)
  for (let m = (y === start.Y ? start.M : 1); m <= (y === end.Y ? end.M : 12); m++)
    if (zeller(y, m, 1) === 1)
      ans += 1;

console.log(ans);

function zeller(y, m, d) {
  const Y = y % 100;
  const C = Math.floor(y/100);

  if (m === 1 || m === 2) {
    y -= 1; m += 12;
  }

  return (d + Math.floor((26*(m+1))/10) + Y + Math.floor(Y/4) + 5*C + Math.floor(C/4)) % 7;
}