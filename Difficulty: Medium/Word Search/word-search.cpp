//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution { 
public:  /// code written by sunny
    bool dfs(vector<vector<char>>& mat, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) {
            return true;
        } 
        if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size() || visited[i][j] || mat[i][j] != word[index]) {
            return false;
        } 
        visited[i][j] = true;
         
        bool found = dfs(mat, word, i+1, j, index+1, visited) ||
                     dfs(mat, word, i-1, j, index+1, visited) ||
                     dfs(mat, word, i, j+1, index+1, visited) ||
                     dfs(mat, word, i, j-1, index+1, visited);
         
        visited[i][j] = false;
        
        return found;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size(); 
        vector<vector<bool>> visited(n, vector<bool>(m, false));
         
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == word[0] && dfs(mat, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        
        return false; 
    }
};

























//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends