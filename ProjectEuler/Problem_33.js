const N = 100;

let mole = 1, deno = 1;
for (let i = 10; i < N; i++) {
  for (let j = i+1; j < N; j++) {
    const d1 = i / j;
    let is = ''+i, js = ''+j;
    for (let k = 0; k < is.length; k++) {
      for (let l = 0; l < js.length; l++) {
        if (is[k] === js[l] && is[k] !== '0') {
          const d2 = eval(is[(k+1)%2] + '/' + js[(l+1)%2]);
          if (d1 === d2)
            mole *= i, deno *= j;
        }
      }
    }
  }
}

console.log(deno / gcd(deno, mole));

function gcd(x, y) {
  if (y === 0)
    return x;
  else
    return gcd(y, x % y);
}
