function canWinNim(n: number): boolean {
  if (n <= 3) return true;

  const bufferLength = 3;
  const buffer = new Array<boolean>(bufferLength);

  buffer.fill(true);

  for (let i = 4; i <= n; i++) {
    const canWin = !buffer[0] || !buffer[1] || !buffer[2];

    for (let j = 1; j < 3; j++) buffer[j - 1] = buffer[j];
    buffer[2] = canWin;
  }

  return buffer[2];
}

(function main() {
  console.log(canWinNim(4));
})();
