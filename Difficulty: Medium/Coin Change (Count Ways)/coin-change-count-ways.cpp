//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public: // code written by sunny
    int count(vector<int>& coins, int sum) {
        vector<int> dp(sum + 1, 0); 
        dp[0] = 1;
         for (int coin : coins) {
            for (int i = coin; i <= sum; ++i) {
                dp[i] += dp[i - coin];
            }
        } 
        return dp[sum];
    }
};





















































//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends