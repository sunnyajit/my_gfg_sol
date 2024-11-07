//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    vector<int> findSplit(vector<int>& arr) {
        // code written by sunny
        int n = arr.size();
        int totalSum = 0;
        for (int num : arr) {
            totalSum += num;
        }
        if (totalSum % 3 != 0) {
            return {-1, -1};
        }
        int targetSum = totalSum / 3;
        int runningSum = 0;
        int i = -1, j = -1;
        for (int k = 0; k < n; ++k) {
            runningSum += arr[k];
            if (runningSum == targetSum) {
                i = k;
                break;
            }
        }
        if (i == -1) return {-1, -1};
        runningSum = 0;
        for (int k = i + 1; k < n; ++k) {
            runningSum += arr[k];
            if (runningSum == targetSum) {
                j = k;
                break;
            }
        }
        if (j != -1 && j < n - 1) {
            return {i, j};
        } else {
            return {-1, -1};
        }
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
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends