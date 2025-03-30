//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public: // code written by sunny
    int maxPartitions(string &s) {
        unordered_map<char, int> lastIndex;
        int n = s.size(); 
        for (int i = 0; i < n; i++) {
            lastIndex[s[i]] = i;
        }  
        int partitions = 0, maxLastIndex = 0;
        for (int i = 0; i < n; i++) {
            maxLastIndex = max(maxLastIndex, lastIndex[s[i]]);
            if (i == maxLastIndex) {
                partitions++;
            }
        }

        return partitions;
    }
};
 




























//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends