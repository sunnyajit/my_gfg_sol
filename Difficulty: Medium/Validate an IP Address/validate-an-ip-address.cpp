//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


// User function Template for C++
class Solution {
  public: // code written by sunny..
    int isValid(string str) {
    // code here
    stringstream ss(str);
    string segment;
    int count = 0;
    while (getline(ss, segment, '.')) {
        if (segment.empty() || segment.length() > 3 || segment[0] == '0' && segment.length() > 1) {
            return false;
        }
        for (char c : segment) {
            if (!isdigit(c)) {
                return false;
            }
        }
        int num = stoi(segment);
        if (num < 0 || num > 255) {
            return false;
        }
        
        count++;
    }
    return count == 4;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends