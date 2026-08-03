# 46. Permutations

## Problem

Given an array `nums` of **distinct integers**, return all possible permutations.

### Example

**Input**
```text
nums = [1,2,3]
```

**Output**
```text
[
 [1,2,3],
 [1,3,2],
 [2,1,3],
 [2,3,1],
 [3,1,2],
 [3,2,1]
]
```

---

# Approach

This problem is solved using **Backtracking + DFS**.

At every recursive call:

1. Iterate through every element.
2. If an element has not been used (`visited[i] == false`):
   - Mark it as visited.
   - Add it to the current permutation.
   - Recurse to build the remaining permutation.
3. After recursion:
   - Remove the last element.
   - Mark it as unvisited.
   - This is the **backtracking** step.

The recursion continues until the current permutation contains all `n` elements.

---

# Recursion Tree

For

```text
nums = [1,2,3]
```

```text
[]
│
├── 1
│   ├── 2
│   │   └── 3 → [1,2,3]
│   └── 3
│       └── 2 → [1,3,2]
│
├── 2
│   ├── 1
│   │   └── 3 → [2,1,3]
│   └── 3
│       └── 1 → [2,3,1]
│
└── 3
    ├── 1
    │   └── 2 → [3,1,2]
    └── 2
        └── 1 → [3,2,1]
```

---

# Algorithm

1. Create an empty vector `ds` to store the current permutation.
2. Maintain a `visited` array to track used elements.
3. If `ds.size() == nums.size()`:
   - Store the permutation.
4. Otherwise:
   - Iterate through every element.
   - Skip already visited elements.
   - Choose the current element.
   - Recurse.
   - Backtrack.

---

# C++ Solution

```cpp
class Solution {
public:
    void solve(vector<vector<int>>& res,
               vector<int>& ds,
               vector<bool>& vis,
               int n,
               vector<int>& nums) {

        if (ds.size() == n) {
            res.push_back(ds);
            return;
        }

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                vis[i] = true;
                ds.push_back(nums[i]);

                solve(res, ds, vis, n, nums);

                ds.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> ds;
        vector<bool> vis(nums.size(), false);

        solve(res, ds, vis, nums.size(), nums);

        return res;
    }
};
```

---

# Dry Run

### Initial State

```text
ds = []
visited = [F F F]
```

Choose `1`

```text
ds = [1]
visited = [T F F]
```

Choose `2`

```text
ds = [1,2]
visited = [T T F]
```

Choose `3`

```text
ds = [1,2,3]
visited = [T T T]
```

Store answer.

Backtrack

```text
pop 3
visited = [T T F]
```

Try another choice

```text
ds = [1,3]
visited = [T F T]
```

Continue similarly until every permutation is generated.

---

# Complexity Analysis

### Time Complexity

There are **n!** permutations.

Each permutation takes **O(n)** time to copy into the result.

**Overall Time Complexity**

```text
O(n × n!)
```

---

### Space Complexity

- Recursion Stack: **O(n)**
- Visited Array: **O(n)**
- Current Permutation: **O(n)**

Ignoring the output array,

```text
O(n)
```

Including the output,

```text
O(n × n!)
```

---

# Key Takeaways

- Uses **Depth First Search (DFS)**.
- Uses **Backtracking** to explore every possible arrangement.
- `visited[]` ensures every element is used only once in a permutation.
- After recursion, undo the choice (**backtracking**) to explore the next possibility.
- Generates exactly **n!** permutations.