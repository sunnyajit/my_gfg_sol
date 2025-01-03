//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends





 

class Solution {
  public: // code written by sunny
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> prefixXORFreq;
        long count = 0;
        int prefixXOR = 0;
        
        for (int num : arr) {
            prefixXOR ^= num;
            if (prefixXOR == k) count++;
            int target = prefixXOR ^ k;
            if (prefixXORFreq.find(target) != prefixXORFreq.end()) {
                count += prefixXORFreq[target];
            }
            prefixXORFreq[prefixXOR]++;
        }
        
        return count;
    }
};


























































//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends