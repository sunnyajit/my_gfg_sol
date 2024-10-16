//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int s) {
        // code written by sunny
         int n = arr.size();
        int left = 0, current_sum = 0;

        for (int right = 0; right < n; ++right) {
            current_sum += arr[right];
            while (current_sum > s && left <= right) {
                current_sum -= arr[left];
                left++;
            }
            if (current_sum == s) {
                return {left + 1, right + 1};  
            }
        }
        return {-1};  
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends