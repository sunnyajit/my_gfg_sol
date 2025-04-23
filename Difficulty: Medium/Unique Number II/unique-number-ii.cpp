//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
  public: // code written by sunny
    vector<int> singleNum(vector<int>& arr) {
        int xorAll = 0;
        for (int num : arr)
            xorAll ^= num; 
        int setBit = xorAll & ~(xorAll - 1);

        int num1 = 0, num2 = 0;
        for (int num : arr) {
            if (num & setBit)
                num1 ^= num;
            else
                num2 ^= num;
        }

        if (num1 < num2)
            return {num1, num2};
        else
            return {num2, num1};
    }
};













































//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends