let input = require("fs")
  .readFileSync("/dev/stdin")
  .toString()
  .trim()
  .split("\n");

let L = Number(input[0]);
let string = input[1];
let H = 0;
let M = 1234567891;
let r = 1;

for (let i = 0; i < L; i++) {
  H += (string[i].charCodeAt() - 96) * r;
  H %= M;
  r *= 31;
  r %= M;
}

console.log(H);
