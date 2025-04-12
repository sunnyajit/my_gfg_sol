//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: // code written by sunny
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int newColor) {
        int n = image.size();
        int m = image[0].size();
 
        if (sr < 0 || sc < 0 || sr >= n || sc >= m) return;
     
        if (image[sr][sc] != color || image[sr][sc] == newColor) return; 
        image[sr][sc] = newColor; 
        dfs(image, sr + 1, sc, color, newColor);
        dfs(image, sr - 1, sc, color, newColor);
        dfs(image, sr, sc + 1, color, newColor);
        dfs(image, sr, sc - 1, color, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
};

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends