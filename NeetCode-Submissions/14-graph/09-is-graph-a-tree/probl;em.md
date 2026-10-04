Graph is Tree or Not

Given an undirected graph which consists of n nodes (numbered from 0 to n-1) and m edges. Return true if the graph is a tree, else return false.

Note: The input graph can have self-loops and multiple edges.

Examples:

Input: n = 4, m = 4, edges = [[0, 1], [0, 2], [1, 2], [2, 3]]

Output: false
Explanation: The graph contains a cycle, therefore it is not a tree.
Input: n = 4, m = 3, edges = [[0, 1], [1, 2], [2, 3]]

Output: true
Explanation: Every node is connected and the graph has no cycles, so it is a tree.
Constraints:

1 ≤ n ≤ 2*105
0 ≤ m ≤ 2*105
edges.size() = m
