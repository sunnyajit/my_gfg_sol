//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public: // code written by sunny
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        bool row0 = false, col0 = false;

        for (int i = 0; i < n; i++) {
            if (mat[i][0] == 0) col0 = true;
        }
        for (int j = 0; j < m; j++) {
            if (mat[0][j] == 0) row0 = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] == 0) {
                    mat[i][0] = 0;
                    mat[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][0] == 0 || mat[0][j] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        if (row0) {
            for (int j = 0; j < m; j++) mat[0][j] = 0;
        }
        if (col0) {
            for (int i = 0; i < n; i++) mat[i][0] = 0;
        }
    }
};






//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        ob.setMatrixZeroes(arr);
        for (auto x : arr) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends