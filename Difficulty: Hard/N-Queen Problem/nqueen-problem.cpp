//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        // code written by sunny
         vector<vector<int>> results;
        vector<int> current(n, 0);
        set<int> cols, diag1, diag2;
        backtrack(0, n, current, results, cols, diag1, diag2);
        return results;
    }
    private:
    void backtrack(int row, int n, vector<int>& current, vector<vector<int>>& results,
                   set<int>& cols, set<int>& diag1, set<int>& diag2) {
        if (row == n) {
            results.push_back(current);
            return;
        }
        for (int col = 0; col < n; ++col) {
            if (cols.count(col) || diag1.count(row - col) || diag2.count(row + col)) {
                continue;
            }
            current[row] = col + 1;  
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            backtrack(row + 1, n, current, results, cols, diag1, diag2);
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends