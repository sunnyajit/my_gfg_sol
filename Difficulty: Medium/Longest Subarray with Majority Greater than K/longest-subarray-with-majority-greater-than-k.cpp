//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
 class Solution {
  public: // code written by sunny
    int longestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> firstOccurrence;
        int prefixSum = 0;
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            if (arr[i] > k)
                prefixSum += 1;
            else
                prefixSum -= 1; 
            if (prefixSum > 0) {
                maxLength = i + 1;
            } else {
                if (firstOccurrence.find(prefixSum - 1) != firstOccurrence.end()) {
                    maxLength = max(maxLength, i - firstOccurrence[prefixSum - 1]);
                }
            } 
            if (firstOccurrence.find(prefixSum) == firstOccurrence.end()) {
                firstOccurrence[prefixSum] = i;
            }
        }

        return maxLength;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends