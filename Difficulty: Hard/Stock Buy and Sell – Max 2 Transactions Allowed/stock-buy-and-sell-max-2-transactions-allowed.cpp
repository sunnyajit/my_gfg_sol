//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





class Solution {
public: // code written by sunny
    int maxProfit(vector<int>& prices) {
        int firstBuy = INT_MAX, firstProfit = 0;
        int secondBuy = INT_MAX, secondProfit = 0;

        for (int price : prices) {
            firstBuy = min(firstBuy, price);                
            firstProfit = max(firstProfit, price - firstBuy); 

            secondBuy = min(secondBuy, price - firstProfit); 
            secondProfit = max(secondProfit, price - secondBuy); 
        }

        return secondProfit; 
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends