type DiffCount = number | null;

interface DiffMap {
  [index: string]: number;
}

class FrequencyDiffMap {
  private _map: DiffMap = {};
  private _diffCount: DiffCount = null;

  constructor(diffReference: string) {
    this._diffCount = 0;
    for (const char of diffReference) this.remove(char);
  }

  insert(char: string) {
    if (this._map[char] === undefined) this._map[char] = 0;
    const prevCharCount = this._map[char];
    this._map[char] += 1;
    const diffChange = prevCharCount < 0 ? -1 : 1;
    this._diffCount += diffChange;
  }

  remove(char: string) {
    if (this._map[char] === undefined) this._map[char] = 0;
    const prevCharCount = this._map[char];
    this._map[char] -= 1;
    const diffChange = prevCharCount > 0 ? -1 : 1;
    this._diffCount += diffChange;
  }

  getOccurrence(char: string) {
    const value = this._map[char];

    if (value === undefined) return 0;

    return value;
  }

  public get diffCount() {
    return this._diffCount;
  }
}

function findAnagrams(s: string, p: string): number[] {
  const results: number[] = [];
  const length = s.length;
  const queryLength = p.length;

  if (queryLength > length) return [];

  const frequencyMap = new FrequencyDiffMap(p);

  for (let i = 0; i < queryLength; i++) {
    const currentCharacter = s[i];
    frequencyMap.insert(currentCharacter);
  }

  if (frequencyMap.diffCount === 0) results.push(0);

  for (let i = queryLength; i < length; i++) {
    const currentCharacter = s[i];
    const leftMostCharacter = s[i - queryLength];

    frequencyMap.insert(currentCharacter);
    frequencyMap.remove(leftMostCharacter);

    if (frequencyMap.diffCount === 0) results.push(i - queryLength + 1);
  }

  return results;
}

function main() {
  const first = "cbaebabacd";
  const second = "abc";

  const results = findAnagrams(first, second);

  console.log(results);
}

main();
