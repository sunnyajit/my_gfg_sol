//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string reverseWords(string str) {
        // code written by sunny4
    vector< string> words;
     stringstream ss(str);
    string word;
    while ( getline(ss, word, '.')) {
        words.push_back(word);
    }
    reverse(words.begin(), words.end());
     string result;
    for (size_t i = 0; i < words.size(); ++i) {
        result += words[i];
        if (i < words.size() - 1) {
            result += '.';  
        }
    }

    return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends