//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code written by sunny
         int n = str.length();
        vector<int> dp(n, 0);  
        int maxLength = 0;
 
        for (int i = 1; i < n; i++) {
            if (str[i] == ')') {
               
                if (str[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                }
                else if (i - dp[i - 1] > 0 && str[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
               
                maxLength = max(maxLength, dp[i]);
            }
        }
        
        return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends