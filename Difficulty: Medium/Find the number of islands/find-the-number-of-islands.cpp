//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    // code written by sunny
     void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,int n, int m){
        if(i>=n||j>=m||i<0||j<0||grid[i][j]=='0'||vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        dfs(grid,vis,i+1,j,n,m);
        dfs(grid,vis,i-1,j,n,m);
        dfs(grid,vis,i,j+1,n,m);
        dfs(grid,vis,i,j-1,n,m);
        dfs(grid,vis,i+1,j+1,n,m);
        dfs(grid,vis,i-1,j-1,n,m);
        dfs(grid,vis,i+1,j-1,n,m);
        dfs(grid,vis,i-1,j+1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    dfs(grid,vis,i,j,n,m);
                    ans++;
                }
            }
        }
        return ans;
    }  
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends