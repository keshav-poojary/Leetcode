class Solution {
  public:
  
    int solve(int i, int j, int m,int n, int dp[101][101]){
        if(i>= m || j>= n){
            return 0;
        }
        
        if(i == m-1 && j== n-1){
            return 1;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j] = solve(i+1,j,m,n,dp) + solve(i,j+1,m,n,dp);
    }
    int numberOfPaths(int m, int n) {
        // code here
        int dp[101][101];
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j]=-1;
            }
        }
        return solve(0,0,m,n, dp);
    }
};
