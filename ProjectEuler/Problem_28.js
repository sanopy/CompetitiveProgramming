const N = 1001;

let nums = [];
for (let i = 0; i < N; i++)
  nums[i] = [];

const RIGHT = 0;
const DOWN  = 1;
const LEFT  = 2;
const UP    = 3;

const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

let x, y, dir;
x = y = Math.floor(N/2);
dir = RIGHT;
for (let i = 1; i <= N*N; i++) {
  nums[y][x] = i;
  x += dx[dir]; y += dy[dir];

  if (dir === RIGHT && !nums[y+1][x])
    dir = DOWN;
  else if (dir === DOWN && !nums[y][x-1])
    dir = LEFT;
  else if (dir === LEFT && !nums[y-1][x])
    dir = UP;
  else if (dir === UP && !nums[y][x+1])
    dir = RIGHT;
}

let ans = 0;
for (let i = 0; i < N; i++) {
  ans += nums[i][i];
  ans += nums[i][N-i-1];
}
ans -= 1; // because 1 is added two times

console.log(ans);