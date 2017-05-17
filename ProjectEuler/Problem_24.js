const S = '0123456789';
const N = 1000000;
let perm = [];

permutationOfDigits(S, '');
perm.sort();
console.log(perm[N-1]);

function permutationOfDigits(s, t) {
  if (s.length === 0) {
    perm.push(t);
    return;
  }

  for (let i = 0; i < s.length; i++) {
    permutationOfDigits(s.replace(s[i], ''), t+s[i]);
  }

  return;
}