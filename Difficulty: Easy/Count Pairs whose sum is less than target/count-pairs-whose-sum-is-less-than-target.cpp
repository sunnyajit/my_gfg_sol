//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
 
 
 class Solution {
  public: // code written by sunn
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;
        int count = 0;

        while (left < right) {
            if (arr[left] + arr[right] < target) {
                count += (right - left);
                ++left;
            } else {
                --right;
            }
        }

        return count;
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
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends