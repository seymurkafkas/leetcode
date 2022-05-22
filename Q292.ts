const ACTION_SET = [1, 2, 3];

const memoizedResults = {};

function canWinNim(n: number): boolean {
  if (n <= 3) return true;

  const memoizedResult = memoizedResults[n];
  if (memoizedResult !== undefined) return memoizedResult;

  let canWin: boolean = false;

  for (const action of ACTION_SET) {
    const canOpponentWin = canWinNim(n - action);

    canWin = !canOpponentWin;
    if (canWin) break;
  }

  memoizedResults[n] = canWin;
  return canWin;
}

(function main() {
  console.log(canWinNim(1348820612));
})();
