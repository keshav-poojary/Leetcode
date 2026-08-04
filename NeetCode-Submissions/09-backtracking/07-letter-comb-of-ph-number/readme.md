# Letter Combinations of a Phone Number

## Problem
Given a string containing digits from **2-9**, return all possible letter combinations that the number could represent based on the telephone keypad.

### Phone Keypad Mapping

| Digit | Letters |
|-------|---------|
| 2 | abc |
| 3 | def |
| 4 | ghi |
| 5 | jkl |
| 6 | mno |
| 7 | pqrs |
| 8 | tuv |
| 9 | wxyz |

---

## Approach (Backtracking)

We generate every possible combination by choosing one character for each digit.

1. Store the mapping of digits to letters.
2. Start from the first digit.
3. For every letter corresponding to the current digit:
   - Add the letter to the current string.
   - Recursively process the next digit.
   - Remove the last letter (backtracking).
4. Once all digits are processed, store the generated string.

---

## Algorithm

- Create a map for digit-to-letter mapping.
- Initialize an empty output string.
- Use recursion:
  - If all digits are processed, add the output string to the answer.
  - Otherwise, iterate over every character mapped to the current digit.
  - Append the character.
  - Recurse for the next digit.
  - Remove the character before trying the next one.

---

## Dry Run

### Input
```
digits = "23"
```

### Steps

```
Start ""

Digit '2' -> abc

Choose 'a'
    Digit '3' -> def
        ad
        ae
        af

Choose 'b'
    bd
    be
    bf

Choose 'c'
    cd
    ce
    cf
```

### Output

```
["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

---

## Time Complexity

Let:

- `N` = number of digits
- Each digit has at most 4 letters.

**Time Complexity:** `O(4^N × N)`

- There are at most `4^N` combinations.
- Each combination takes `O(N)` to construct.

---

## Space Complexity

- Recursive stack: **O(N)**
- Output storage: **O(4^N × N)**

Ignoring the output list, the auxiliary space is **O(N)**.

---

