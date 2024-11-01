//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public: // code written by sunny
     long long maxSum(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        long long totalSum = 0;
        for (int i = 0; i < size / 2; i++) {
            totalSum += 2 * static_cast<long long>(nums[size - i - 1]);  
            totalSum -= 2 * static_cast<long long>(nums[i]);           
        }
        
        return totalSum;  
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends