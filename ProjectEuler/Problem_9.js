const N = 1000;

for (let a = 1; a <= N; a++) {
  for (let b = a+1; a+b <= N; b++) {
    let c = N - (a + b);
    if (c <= b)
      break;
    if (a*a + b*b === c*c)
      console.log(a*b*c);
  }
}