//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
 // User function template for C++
class Solution {
  public:
    // code written by sunny
    int missingNumber(int n, vector<int>& arr) {
    int xor_full = 0;
    int xor_arr = 0;
    for (int i = 1; i <= n; ++i) {
        xor_full ^= i;
    }
    for (int num : arr) {
        xor_arr ^= num;
    }
    return xor_full ^ xor_arr;
 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; ++i)
            cin >> arr[i];
        Solution obj;
        cout << obj.missingNumber(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends