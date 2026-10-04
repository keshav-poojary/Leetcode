# Valid Parentheses

## Category
- Stack

## Problem Summary
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid. An input string is valid if: Open brackets must be closed by the same type of brackets.

## Files
- solution.cpp

## Approach
Use stack-based state tracking to handle order-sensitive operations and nested structure problems.

## Solution Trace
1. Analyze the input and identify the key invariant or constraint the solution must maintain.
2. Transform the problem into a compact state representation that makes the decision easy to evaluate.
3. Apply the selected algorithm and update the answer as the scan progresses.
4. Validate the result against special cases such as empty input, duplicates, boundaries, and single-element cases.

## Code Trace
1. `Each node starts as its own parent or root in the disjoint-set structure.`
2. `For every edge, the code merges the two endpoints into the same connected component with union/find.`
3. `The root representative for each node determines whether two vertices are connected.`
4. `The final answer is the count of distinct roots left after all unions are processed.`

## Code Walkthrough
- Each node starts as its own parent or root in the disjoint-set structure.
- For every edge, the code merges the two endpoints into the same connected component with union/find.
- The root representative for each node determines whether two vertices are connected.
- The final answer is the count of distinct roots left after all unions are processed.

## Mermaid Diagram
```mermaid
flowchart TD
    A[Initialize parent/root for each node] --> B[For each edge, call union]
    B --> C{Same root?}
    C -- No --> D[Merge components]
    C -- Yes --> E[Skip duplicate connection]
    D --> F{All edges processed?}
    E --> F
    F -- No --> B
    F -- Yes --> G[Count number of distinct roots]
    G --> H[Return connected component count]
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
- 01.valid-parenthesis
