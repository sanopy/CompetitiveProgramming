const N = 1000;
const numbers = [
  [
    '', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten',
    'eleven', 'twelve', 'thirteen', 'fourteen', 'fifteen', 'sixteen', 'seventeen', 'eighteen', 'nineteen'
  ],
  ['', '', 'twenty', 'thirty', 'forty', 'fifty', 'sixty', 'seventy', 'eighty', 'ninety'],
  [
    '', 'onehundred', 'twohundred', 'threehundred', 'fourhundred', 'fivehundred',
    'sixhundred', 'sevenhundred', 'eighthundred', 'ninehundred'
  ],
  ['', 'onethousand']
];

let ans = 0;
for (let i = 1; i < N; i++) {
  let _1   = i % 10;
  let _10  = i % 100;
  let _100 = Math.floor(i / 100);

  let s;

  if (_100 > 0 && (_10 > 0 || _1 > 0))
    s = numbers[2][_100] + 'and';
  else
    s = numbers[2][_100];

  if (_10 < numbers[0].length) {
    s += numbers[0][_10];
  } else {
    _10 = Math.floor((i % 100) / 10);
    s += numbers[1][_10] + numbers[0][_1];
  }

  ans += s.length;
}
ans += numbers[3][1].length;

console.log(ans);