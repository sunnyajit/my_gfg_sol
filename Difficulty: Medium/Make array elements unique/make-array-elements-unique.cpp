//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code written by sunny
        sort(arr.begin(), arr.end());
        int increments = 0;
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] <= arr[i - 1]) {
                increments += (arr[i - 1] - arr[i] + 1);
                arr[i] = arr[i - 1] + 1;
            }
        }
        return increments;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        int ans = ob.minIncrements(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends