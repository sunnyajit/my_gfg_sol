//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




 class Solution {
  public: // CODE WRITTEN BY SUNNY
    bool isValid(vector<vector<int>> &mat, int row, int col, int num) {
        for (int i = 0; i < 9; i++) {
            if (mat[row][i] == num) return false;
        }
        for (int i = 0; i < 9; i++) {
            if (mat[i][col] == num) return false;
        } 
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (mat[startRow + i][startCol + j] == num) return false;
            }
        }
        
        return true;
    }
    
    bool solve(vector<vector<int>> &mat) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (mat[row][col] == 0) {  
                    for (int num = 1; num <= 9; num++) {
                        if (isValid(mat, row, col, num)) {
                            mat[row][col] = num;
                            if (solve(mat)) return true;
                            mat[row][col] = 0; 
                        }
                    }
                    return false;
                }
            }
        }
        return true; 
    }
    
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
}; 
template <typename T>
void printMatrix(const vector<vector<T>> &mat) {
    for (const auto &row : mat) {
        for (const auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}






































//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends