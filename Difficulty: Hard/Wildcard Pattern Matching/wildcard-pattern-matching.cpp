//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        // CODE WRITTEN BY SUNNY 
    int m = pattern.length();
    int n = str.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;  
    for (int i = 1; i <= m; i++) {
        if (pattern[i - 1] == '*') {
            dp[i][0] = dp[i - 1][0];  
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pattern[i - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else if (pattern[i - 1] == '?' || pattern[i - 1] == str[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 0;  
            }
        }
    }
    return dp[m][n];
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends