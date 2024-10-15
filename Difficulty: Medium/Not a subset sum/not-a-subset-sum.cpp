//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// User function template for C++

class Solution {
  public:
    long long findSmallest(vector<int> &arr) {
        // code written by sunny
         long long smallest_missing = 1;  
        
        for (int num : arr) {
            if (num > smallest_missing) {
                break; 
            }
            smallest_missing += num;
        }
        
        return smallest_missing;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        auto ans = ob.findSmallest(arr);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends