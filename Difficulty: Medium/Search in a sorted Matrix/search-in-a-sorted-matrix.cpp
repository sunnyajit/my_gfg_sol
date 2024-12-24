//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


 
class Solution {
public: // code written by sunny
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();    
        int m = mat[0].size();  
        int left = 0, right = n * m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int row = mid / m;
            int col = mid % m;
            int midValue = mat[row][col];
            
            if (midValue == x) {
                return true;
            } else if (midValue < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;  
    }
};





































//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int n, m;
        cin >> n >> m;
        vector<vector<int> > matrix(n);

        for (int i = 0; i < n; i++) {
            matrix[i].assign(m, 0);
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        int x;
        cin >> x;
        Solution obj;
        if (obj.searchMatrix(matrix, x))
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends