const N = 100;

let s = 0, t = 0;
for (let i = 1; i <= N; i++) {
  s += i*i;
  t += i;
}
t *= t;

console.log(t-s);