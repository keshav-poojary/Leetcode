#include <bits/stdc++.h>
using namespace std;

string getAlienLanguage(vector<string> &dictionary, int k)
{
    // Write your code here.
    vector<vector<int>> adjList(k);

    for (int i = 0; i < dictionary.size() - 1; i++)
    {
        string s1 = dictionary[i];
        string s2 = dictionary[i + 1];

        int len = min(s1.length(), s2.length());

        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                adjList[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }

    vector<int> topoSort;

    vector<int> indegree(k);

    for (auto list : adjList)
    {
        for (auto ele : list)
        {
            indegree[ele]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < k; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        topoSort.push_back(top);

        for (auto ngbr : adjList[top])
        {
            indegree[ngbr]--;
            if (indegree[ngbr] == 0)
            {
                q.push(ngbr);
            }
        }
    }

    string ans = "";

    for (auto data : topoSort)
    {
        ans += (data + 'a');
    }

    return ans;
}

// time complexity: O(N * M + K), where N is the number of words in the dictionary, M is the average length of the words, and K is the number of characters in the alien language. The first part of the time complexity comes from building the adjacency list, and the second part comes from performing a topological sort on the graph.
// space complexity: O(K + E), where K is the number of characters in the alien