//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++



class Solution {
  public: // code written by sunny
    int maxSubarraySum(vector<int> &arr) {
        int max_sum = INT_MIN; 
        int current_sum = 0;   

        for (int num : arr) {
            current_sum += num;          
            max_sum = max(max_sum, current_sum);  
            if (current_sum < 0) {         
                current_sum = 0;
            }
        }

        return max_sum; 
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends