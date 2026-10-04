# Generate Parentheses

## Category
- Backtracking

## Problem Summary
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

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
1. `If the value is new, it is inserted into the tracking structure so it can be compared later in the scan.`

## Code Walkthrough
- If the value is new, it is inserted into the tracking structure so it can be compared later in the scan.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Choose a candidate] --> B[Recurse]
    B --> C{Valid branch?}
    C -- Yes --> D[Record choice]
    C -- No --> E[Backtrack]
    D --> F[Explore next choice]
    E --> F
    F --> G{All options done?}
    G -- No --> A
    G -- Yes --> H[Return valid solutions]
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
- 05-generate-parenthesis
