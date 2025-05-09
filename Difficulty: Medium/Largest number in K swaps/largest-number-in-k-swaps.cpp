//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
class Solution {
  public: // code written by sunny
    void solve(string &s, int k, string &maxNum, int idx) {
        if (k == 0) return;

        int n = s.length();
        char maxDigit = s[idx]; 
        for (int i = idx + 1; i < n; ++i) {
            if (s[i] > maxDigit) {
                maxDigit = s[i];
            }
        } 
        if (maxDigit != s[idx]) k--; 
        for (int i = n - 1; i >= idx; --i) {
            if (s[i] == maxDigit) {
                swap(s[i], s[idx]);
                if (s > maxNum) maxNum = s;

                solve(s, k, maxNum, idx + 1);  

                swap(s[i], s[idx]); 
            }
        }
    }

    string findMaximumNum(string& s, int k) {
        string maxNum = s;
        solve(s, k, maxNum, 0);
        return maxNum;
    }
};


















































//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends