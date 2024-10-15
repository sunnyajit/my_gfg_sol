//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int subArraySum(vector<int>& arr, int tar) {
        // code written by sunny
        unordered_map<int, int> sumCount;
        int currentSum = 0;
        int result = 0;
        sumCount[0] = 1;

        for (int num : arr) {
            currentSum += num;
            if (sumCount.find(currentSum - tar) != sumCount.end()) {
                result += sumCount[currentSum - tar];
            }
            sumCount[currentSum]++;
        }

        return result;
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
        string ks;
        getline(cin, ks);
        int tar = stoi(ks);
        Solution obj;
        int res = obj.subArraySum(arr, tar);
        cout << res << endl;
    }
    return 0;
}
// } Driver Code Ends