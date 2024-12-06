//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public: // code written by sunny
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());
        
        int hIndex = 0;
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] >= i + 1) {
                hIndex = i + 1; 
            } else {
                break; 
            }
        }
        
        return hIndex;
    }
};




//{ Driver Code Starts.

int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends