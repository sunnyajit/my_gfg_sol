//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


 

class Solution {
public:  // code  written by sunny
    char nonRepeatingChar(string &s) {
        unordered_map<char, int> charCount;  
        for (char ch : s) {
            charCount[ch]++;
        } 
        for (char ch : s) {
            if (charCount[ch] == 1) {
                return ch;  
            }
        } 
        return '$';
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends