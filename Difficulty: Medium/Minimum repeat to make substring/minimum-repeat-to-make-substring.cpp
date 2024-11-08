//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code written by sunny
         int repeatCount = (s2.size() + s1.size() - 1) / s1.size();
        string repeated_s1 = "";
        for (int i = 0; i < repeatCount; ++i) {
            repeated_s1 += s1;
        }
        if (repeated_s1.find(s2) != string::npos) {
            return repeatCount;
        }
        repeated_s1 += s1;
        if (repeated_s1.find(s2) != string::npos) {
            return repeatCount + 1;
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends