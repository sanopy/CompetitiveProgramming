const N = 1000;

let arr = [1];
for (let i = 0; i < N; i++) {
  for (let j = arr.length-1; j >= 0; j--) {
    arr[j] *= 2;
    if (arr[j] >= 10) {
      const carry = Math.floor(arr[j] / 10);
      arr[j] %= 10;
      arr[j+1] = j === arr.length-1 ? carry : arr[j+1] + carry;
    }
  }
}

let ans = 0;
for (let i = 0; i < arr.length; i++)
  ans += arr[i];

console.log(ans);