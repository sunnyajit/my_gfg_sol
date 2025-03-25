//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// // User function Template for C++
// #include <bits/stdc++.h>
// using namespace std;


// #include <bits/stdc++.h>
// using namespace std;

class Solution {
public: // code written by sunny
    unordered_map<string, long long> dp;  

    long long solve(string &s, int i, int j, bool isTrue) {
        if (i > j) return 0;
        if (i == j) { 
            if (isTrue) return s[i] == 'T';
            else return s[i] == 'F';
        }

        string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);
        if (dp.find(key) != dp.end()) return dp[key];

        long long ways = 0;
        for (int k = i + 1; k < j; k += 2) {  
            long long leftTrue = solve(s, i, k - 1, true);
            long long leftFalse = solve(s, i, k - 1, false);
            long long rightTrue = solve(s, k + 1, j, true);
            long long rightFalse = solve(s, k + 1, j, false);

            if (s[k] == '&') {
                if (isTrue) ways += leftTrue * rightTrue;
                else ways += leftFalse * rightFalse + leftTrue * rightFalse + leftFalse * rightTrue;
            } else if (s[k] == '|') {
                if (isTrue) ways += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftFalse * rightFalse;
            } else if (s[k] == '^') {
                if (isTrue) ways += leftTrue * rightFalse + leftFalse * rightTrue;
                else ways += leftTrue * rightTrue + leftFalse * rightFalse;
            }
        }

        return dp[key] = ways;  
    }

    int countWays(string &s) {
        dp.clear();
        return solve(s, 0, s.length() - 1, true);
    }
};
 




































//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends