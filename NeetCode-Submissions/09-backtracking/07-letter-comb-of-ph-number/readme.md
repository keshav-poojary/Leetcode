# Letter Combinations of a Phone Number

## Category
- Backtracking

## Problem Summary
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order. A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

## Files
- solution.cpp

## Approach
Explore candidate choices recursively and backtrack once a branch is invalid or complete.

## Solution Trace
1. Analyze the input and identify the key invariant or constraint the solution must maintain.
2. Transform the problem into a compact state representation that makes the decision easy to evaluate.
3. Apply the selected algorithm and update the answer as the scan progresses.
4. Validate the result against special cases such as empty input, duplicates, boundaries, and single-element cases.

## Code Trace
1. `A hash map stores counts, indices, or state information keyed by the processed value.`
2. `As the scan continues, the map reveals whether a value has already appeared or if a state must be updated.`
3. `The current element is compared against the map to decide whether the operation should continue or terminate.`
4. `The final result is computed from the map state after the full pass is complete.`

## Code Walkthrough
- A hash map stores counts, indices, or state information keyed by the processed value.
- As the scan continues, the map reveals whether a value has already appeared or if a state must be updated.
- The current element is compared against the map to decide whether the operation should continue or terminate.
- The final result is computed from the map state after the full pass is complete.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Create map for counts or state] --> B[Scan each element]
    B --> C{Key seen before?}
    C -- Yes --> D[Update or compare]
    C -- No --> E[Insert key]
    D --> F{More elements?}
    E --> F
    F -- Yes --> B
    F -- No --> G[Return computed result]
```

## Algorithm
1. Read the problem constraints and identify the correct state to track.
2. Choose the most fitting pattern for the data structure involved.
3. Process the collection or graph in a single pass where possible.
4. Maintain the answer and verify correctness against edge cases.
5. Return the final value or structure after the traversal is complete.

## Complexity Analysis
- Time Complexity: O(n) or O(n log n), depending on the exact operation pattern used in the solution.
- Space Complexity: O(n) or O(1) auxiliary space, based on the chosen data structure and recursion/stack usage.

## Core Intuition
The solution reduces the problem to a smaller, trackable state and then uses the correct structural pattern to process the input efficiently. This keeps the implementation both easy to follow and correct for the constraints.

## Edge Cases
- Empty input or single-element input
- Duplicate values or repeated edges
- Boundary values and extreme indices
- Already-sorted or reverse-sorted scenarios
- Cycles, null nodes, or disconnected components when relevant

## Folder
- 07-letter-comb-of-ph-number
