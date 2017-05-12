const N = 100;

let arr = [1];
for (let i = 2; i <= N; i++) {
  let prev = [];
  for (let j = 0; j < arr.length; j++)
    prev[j] = arr[j];

  for (let j = 1; j < i; j++) {
    for (let k = prev.length-1; k >= 0; k--) {
      let l = k;
      arr[k] += prev[k];

      while (arr[l] >= 10) {
        const carry = Math.floor(arr[l] / 10);
        arr[l] %= 10;
        arr[l+1] = l === arr.length-1 ? carry : arr[l+1] + carry;
        l++;
      }
    }
  }
}

let ans = 0;
for (let i = 0; i < arr.length; i++)
  ans += arr[i];

console.log(ans);