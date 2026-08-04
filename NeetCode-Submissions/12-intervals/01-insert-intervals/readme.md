# Insert Interval

## Intuition

Since the intervals are already sorted and non-overlapping, we can process them in one pass. The idea is to first add all intervals that come before the new interval, then merge every overlapping interval, and finally append the remaining intervals.

## Approach

- Traverse the intervals and add all intervals that end before the new interval begins.
- Initialize the merged interval using `newInterval`.
- Merge all intervals that overlap by updating:
  - `start = min(start, currentStart)`
  - `end = max(end, currentEnd)`
- Add the merged interval to the answer.
- Append all remaining intervals.

## Algorithm

1. Add all non-overlapping intervals on the left.
2. Merge all overlapping intervals.
3. Insert the merged interval.
4. Add all remaining intervals.
5. Return the final list.

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(n)`

## Key Concepts

- Greedy
- Interval Merging
- Arrays
- Linear Traversal