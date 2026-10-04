Network Delay Time

(numbered from 0 to V-1) and E number of directed connections, described by an array edges[], where each element {u, v, w} specifies that a signal requires w units of time to propagate from node u to node v.

A signal is transmitted from the source node src. Return the minimum time it takes for all the nodes to receive the signal. If any node remains unreachable, return -1.

Note: There are no multiple edge connections in the network.

Examples:

Input: V = 3, edges[][] = [[0, 2, 1], [2, 1, 2], [0, 1, 4]], src = 0
Output: 3
Explanation: In 3 units of time the signal can cover all the nodes by following this path: 0 -> 2 -> 1.
Input: V = 2, edges[][] = [[0, 1, 5]], src = 1
Output: -1
Explanation: There is no connection from 1 to 0.
Constraint:

0 ≤ src < V ≤ 103
1 ≤ E ≤ 105
0 ≤ edges[i][0], edges[i][1] < V
0 ≤ edges[i][2] ≤ 105
