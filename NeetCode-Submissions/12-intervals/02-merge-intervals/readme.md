# Merge Intervals

## Problem
Given an array of intervals where `intervals[i] = [start, end]`, merge all overlapping intervals and return a list of non-overlapping intervals covering all the given intervals.

### Example
```text
Input:
[[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]
```

---

## Approach

1. Sort the intervals based on their starting time.
2. Initialize the result with the first interval.
3. Traverse the remaining intervals:
   - If the current interval overlaps with the last interval in the result, merge them by updating the ending point.
   - Otherwise, add the current interval to the result.
4. Return the merged intervals.

---

## Algorithm

- Sort the intervals.
- Store the first interval in the result.
- For every remaining interval:
  - If `currentStart <= lastMergedEnd`, merge:
    - `lastMergedEnd = max(lastMergedEnd, currentEnd)`
  - Else:
    - Add the current interval to the result.
- Return the result.

---

## Dry Run

### Input
```text
[[1,3],[2,6],[8,10],[15,18]]
```

### After Sorting
```text
[[1,3],[2,6],[8,10],[15,18]]
```

### Processing

- Result = [[1,3]]

- Compare [2,6] with [1,3]
  - Overlap ✅
  - Merge → [1,6]

- Compare [8,10] with [1,6]
  - No Overlap ❌
  - Add → [[1,6],[8,10]]

- Compare [15,18] with [8,10]
  - No Overlap ❌
  - Add → [[1,6],[8,10],[15,18]]

### Final Output
```text
[[1,6],[8,10],[15,18]]
```

---

## Complexity Analysis

- **Time Complexity:** `O(n log n)`
  - Sorting takes `O(n log n)`.
  - Single traversal takes `O(n)`.

- **Space Complexity:** `O(n)`
  - Extra space for the result vector.

---

## Key Idea

The intervals are first sorted so that any overlapping intervals become adjacent. Then, by comparing each interval with the last merged interval, overlapping intervals are combined efficiently in a single pass.

---

## C++ Solution

```cpp
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= res.back()[1])
            {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};
```