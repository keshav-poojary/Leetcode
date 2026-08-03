# Generate Parentheses

## Problem Statement

Given `n` pairs of parentheses, generate all combinations of **well-formed (balanced)** parentheses.

### Example

**Input**
```text
n = 3
```

**Output**
```text
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

---

# Intuition

At every position, we have two possible choices:

- Add an opening bracket `'('`
- Add a closing bracket `')'`

However, not every choice is valid. We must ensure the generated sequence is always balanced.

Instead of generating all possible strings and checking validity later, we generate **only valid sequences** using recursion.

---

# Observations

Let:

- `open` = number of `'('` remaining
- `close` = number of `')'` remaining

### Case 1: `open == close`

All previously placed brackets are balanced.

We **cannot** place `')'` because there is no unmatched `'('`.

Only one choice:

```text
(
```

---

### Case 2: `open == 0`

No opening brackets remain.

Only choice:

```text
)
```

---

### Case 3: `close == 0`

No closing brackets remain.

Only choice:

```text
(
```

---

### Case 4: `open < close`

Both choices are valid.

```text
(
or
)
```

---

### Base Case

When

```text
open == 0 && close == 0
```

a valid parentheses sequence has been formed.

Store it in the answer.

---

# Recursive Tree (n = 3)

```text
                    ""
                 (3,3)
                    |
                    (
                 (2,3)
               /       \
             (         )
         (1,3)       (2,2)
         /   \          |
      (0,3) (1,2)      (1,2)
        |     / \       / \
      ...   ... ...   ... ...
```

Every recursive call reduces either `open` or `close` until both become `0`.

---

# Algorithm

1. Start with an empty string.
2. Keep track of remaining opening and closing brackets.
3. If both counts become `0`, store the string.
4. If `open == close`, only add `'('`.
5. If `open == 0`, only add `')'`.
6. If `close == 0`, only add `'('`.
7. Otherwise, recursively try both choices.

---

# C++ Solution

```cpp
class Solution {
public:
    void solve(string op, int open, int close, vector<string> &ans) {

        if (open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }

        if (open == close) {
            string op1 = op;
            op1.push_back('(');
            solve(op1, open - 1, close, ans);
        }
        else if (open == 0) {
            string op1 = op;
            op1.push_back(')');
            solve(op1, open, close - 1, ans);
        }
        else if (close == 0) {
            string op1 = op;
            op1.push_back('(');
            solve(op1, open - 1, close, ans);
        }
        else {
            string op1 = op;
            string op2 = op;

            op1.push_back('(');
            op2.push_back(')');

            solve(op1, open - 1, close, ans);
            solve(op2, open, close - 1, ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("", n, n, ans);
        return ans;
    }
};
```

---

# Dry Run (`n = 2`)

```text
solve("",2,2)

↓

"("
(1,2)

├── "(("
│      ↓
│    "(())"
│
└── "()"
       ↓
     "()()"
```

Final Answer

```text
[
"(())",
"()()"
]
```

---

# Complexity Analysis

Let `N = 2 × n` (length of each valid string).

### Time Complexity

- Number of valid combinations = **Catalan Number**

\[
C_n = \frac{1}{n+1}\binom{2n}{n}
\]

Each valid string has length `2n`.

Overall complexity:

```text
O(Cn × N)
```

or approximately

```text
O(Cn × 2n)
```

where `Cn` is the nth Catalan number.

---

### Space Complexity

```text
O(N)
```

- Recursive stack depth = `2n`
- Current string length = `2n`

(Excluding the output vector.)

---

# Key Takeaways

- Classic **Backtracking / Recursion** problem.
- Never generate invalid states.
- Keep track of remaining opening and closing brackets.
- Only place `')'` when there is an unmatched `'('`.
- Generates only valid parentheses combinations, making it much more efficient than brute force.

---
