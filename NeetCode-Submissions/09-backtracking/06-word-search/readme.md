# Word Search

## Problem Statement

Given an `m × n` grid of characters `board` and a string `word`, determine if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are **horizontally or vertically neighboring**. The same cell cannot be used more than once in a single path.

---

## Example

### Input

```text
board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

word = "ABCCED"
```

### Output

```text
true
```

---

## Intuition

The problem requires checking whether a word can be formed by moving through adjacent cells in the grid.

A brute-force approach would try every possible path, resulting in many unnecessary explorations.

Instead, we use **Depth First Search (DFS)** with **Backtracking**:

- Start searching from every cell that matches the first character.
- Recursively explore the four neighboring cells.
- Keep track of visited cells so that a cell is not reused.
- If the current path cannot form the word, backtrack and try another path.

---

## Approach

1. Iterate through every cell in the grid.
2. Whenever the current cell matches the first character of the word, start a DFS.
3. During DFS:
   - Check boundary conditions.
   - Ensure the cell is not already visited.
   - Verify the current character matches the word.
4. Mark the current cell as visited.
5. Explore all four directions:
   - Up
   - Right
   - Down
   - Left
6. If any recursive call returns `true`, the word exists.
7. Otherwise, backtrack by unmarking the current cell and continue searching.

---

## Algorithm

1. Traverse every cell of the board.
2. If the cell matches the first character:
   - Start DFS.
3. In DFS:
   - If all characters are matched, return `true`.
   - If indices are out of bounds, return `false`.
   - If the current cell is already visited, return `false`.
   - If characters do not match, return `false`.
   - Mark the cell as visited.
   - Explore all four directions recursively.
   - Backtrack by unmarking the cell.
4. If no path matches the word, return `false`.

---

## C++ Solution

```cpp
class Solution {
public:
    bool find(vector<vector<char>>& board, string word, int index,
              int i, int j, int m, int n,
              vector<vector<int>>& vis) {

        if (index == word.size())
            return true;

        if (i < 0 || i >= m || j < 0 || j >= n ||
            vis[i][j] || board[i][j] != word[index])
            return false;

        vis[i][j] = 1;

        bool found =
            find(board, word, index + 1, i - 1, j, m, n, vis) ||
            find(board, word, index + 1, i, j + 1, m, n, vis) ||
            find(board, word, index + 1, i + 1, j, m, n, vis) ||
            find(board, word, index + 1, i, j - 1, m, n, vis);

        vis[i][j] = 0;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {
                    if (find(board, word, 0, i, j, m, n, visited))
                        return true;
                }
            }
        }

        return false;
    }
};
```

---

## Dry Run

### Board

```text
A B C E
S F C S
A D E E
```

### Word

```text
ABCCED
```

### Search Path

```text
A
↓
B
→
C
↓
C
←
E
←
D
```

The recursion successfully reaches the end of the word, so the answer is:

```text
true
```

---

## Backtracking Visualization

```text
Start

A
│
B
│
C
├── Wrong Path ❌
│
Backtrack
│
C
│
E
│
D
│
Success ✅
```

Whenever a path fails:

- Remove the current cell from the visited path.
- Return to the previous cell.
- Explore another direction.

This is the essence of **backtracking**.

---

## Why Backtracking?

Without backtracking:

- A visited cell would remain permanently marked.
- Other valid paths would never be explored.

Backtracking restores the board's state after exploring each path, allowing all possible valid paths to be checked.

---

## Complexity Analysis

Let:

- `m` = number of rows
- `n` = number of columns
- `L` = length of the word

### Time Complexity

```text
O(m × n × 4^L)
```

- There are `m × n` possible starting positions.
- From each position, DFS explores up to four directions.
- The recursion depth is at most `L`.

---

### Space Complexity

```text
O(m × n + L)
```

- `O(m × n)` for the visited matrix.
- `O(L)` for the recursion stack.

> If the board itself is modified temporarily (instead of using a visited matrix), the auxiliary space reduces to **O(L)**.

---

## Key Takeaways

- Uses **DFS + Backtracking**.
- Start DFS only from cells matching the first character.
- Mark cells as visited to avoid reuse.
- Backtrack after exploring each path.
- Stop immediately once the complete word is found.
