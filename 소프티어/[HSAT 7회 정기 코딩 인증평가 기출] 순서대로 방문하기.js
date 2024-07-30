const fs = require("fs");
const path = require("path");

const inputPath = path.resolve(__dirname, "input.txt");
let input = fs.readFileSync(inputPath, "utf8").toString().trim().split("\n");

let [N, M] = input[0].split(" ").map(Number);
let arr = [];
let visited = Array(N)
  .fill()
  .map(() => Array(N).fill(false));
let goal = [];
let dx = [1, -1, 0, 0];
let dy = [0, 0, 1, -1];
let res = 0;
let idx = 1;

for (let i = 0; i < N; i++) {
  arr.push(input[idx].split(" ").map(Number));
  idx++;
}

for (let i = 0; i < M; i++) {
  let [x, y] = input[idx].split(" ").map(Number);
  goal.push([x - 1, y - 1]);
  idx++;
}

const dfs = (cur, nextIdx) => {
  if (cur[0] === goal[nextIdx][0] && cur[1] === goal[nextIdx][1]) {
    if (nextIdx === M - 1) {
      res++;
      return;
    }
    nextIdx++;
  }

  let x = cur[0];
  let y = cur[1];

  visited[x][y] = true;
  for (let i = 0; i < 4; i++) {
    let nx = x + dx[i];
    let ny = y + dy[i];

    if (
      0 <= nx &&
      nx < N &&
      0 <= ny &&
      ny < N &&
      !visited[nx][ny] &&
      arr[nx][ny] === 0
    ) {
      dfs([nx, ny], nextIdx);
    }
  }
  visited[x][y] = false;
  return;
};

dfs(goal[0], 1);
console.log(res);
