const N = 1000;
let ans;

let arr1 = [0];
let arr2 = [1];
for (let i = 2; ; i++) {
  let tmp = [];
  for (let j = 0; j < arr2.length; j++)
    tmp[j] = arr2[j];

  for (let j = 0; j < arr2.length; j++) {
    if (j < arr1.length)
      arr2[j] += arr1[j];
    if (arr2[j] >= 10) {
      const carry = Math.floor(arr2[j] / 10);
      arr2[j] %= 10;
      arr2[j+1] = j === arr2.length-1 ? carry : arr2[j+1] + carry;
    }
  }

  arr1 = tmp;

  if (arr2.length >= N) {
    ans = i;
    break;
  }
}

console.log(ans);