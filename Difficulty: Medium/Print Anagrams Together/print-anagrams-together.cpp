//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public: // code written by sunny
    vector<vector<string>> anagrams(vector<string>& arr) {
        unordered_map<string, vector<string>> pm;
        for(int j = 0; j< arr.size(); j++){
            string temp = arr[j];
            sort(temp.begin(), temp.end());
            pm[temp].push_back(arr[j]);
            
        }
        vector<vector<string>> result;
        for(auto& entry : pm){
            result.push_back(entry.second);
        }
        return result;
        
    }
};











































//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends