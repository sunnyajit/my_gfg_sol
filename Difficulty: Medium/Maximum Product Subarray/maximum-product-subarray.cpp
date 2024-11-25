//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++




class Solution {
public: // code written by sunny
    int maxProduct(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) return 0;
        int maxProduct = arr[0], minProduct = arr[0], globalMax = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] < 0) {
                swap(maxProduct, minProduct);
            }
            maxProduct = max(arr[i], maxProduct * arr[i]);
            minProduct = min(arr[i], minProduct * arr[i]);
            globalMax = max(globalMax, maxProduct);
        }

        return globalMax;
    }
};







//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends