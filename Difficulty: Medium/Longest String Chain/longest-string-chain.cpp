//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends






 

class Solution {
  public: // code written by sunny
    int longestStringChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        unordered_map<string, int> dp;  
        int maxLength = 1;   
        for (const string& word : words) {
            dp[word] = 1;  
            for (int i = 0; i < word.size(); i++) {
                string pred = word.substr(0, i) + word.substr(i + 1);  
                if (dp.count(pred)) { 
                    dp[word] = max(dp[word], dp[pred] + 1);
                }
            } 
            maxLength = max(maxLength, dp[word]);
        }

        return maxLength;  
    }
};

 






























//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends