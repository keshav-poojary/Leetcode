#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int>s;
        
        int i = k;
        while(i!=0){
            s.push(q.front());
            q.pop();
            i--;
        }
        
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        for(int i=0;i<q.size()-k;i++){
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};