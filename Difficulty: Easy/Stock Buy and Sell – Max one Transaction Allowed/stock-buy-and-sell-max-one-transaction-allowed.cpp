//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public: // code written by sunny
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) return 0;  
        int minPrice = INT_MAX;  
        int maxProfit = 0;       
        for (int price : prices) {
            minPrice = min(minPrice, price);             
            maxProfit = max(maxProfit, price - minPrice);  
        }

        return maxProfit;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends