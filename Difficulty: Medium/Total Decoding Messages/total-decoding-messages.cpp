//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public: // code written by sunny
    int countWays(string &digits) {
        int n = digits.size();
        if (n == 0 || digits[0] == '0') return 0;   

        int prev2 = 1, prev1 = 1;  

        for (int i = 1; i < n; i++) {
            int curr = 0;
            int oneDigit = digits[i] - '0';
            int twoDigit = (digits[i - 1] - '0') * 10 + oneDigit;

            if (oneDigit >= 1) {
                curr += prev1;  
            }
            if (twoDigit >= 10 && twoDigit <= 26) {
                curr += prev2;  
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};





















































//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends