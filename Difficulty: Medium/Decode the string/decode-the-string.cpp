//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
 class Solution {
  public: // cpde written by sunny
    string decodedString(string &s) {
        stack<string> strStack;
        stack<int> numStack;
        string currStr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '[') {
                numStack.push(num);
                strStack.push(currStr);
                num = 0;
                currStr = "";
            } 
            else if (c == ']') {
                string temp = currStr;
                int repeatTimes = numStack.top();
                numStack.pop();
                currStr = strStack.top();
                strStack.pop();
                
                while (repeatTimes--) {
                    currStr += temp;
                }
            } 
            else {
                currStr += c;
            }
        }
        return currStr;
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
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends