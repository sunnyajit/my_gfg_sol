//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

 

class Solution {
public: // code written by sunny
    vector<int> sumClosest(vector<int>& arr, int target) {
        if (arr.size() < 2) {
            return {};
        }

        sort(arr.begin(), arr.end());

        int left = 0, right = arr.size() - 1;
        int closestSum = INT_MAX;
        int maxAbsDiff = -1;
        vector<int> result;

        while (left < right) {
            int sum = arr[left] + arr[right];
            int absDiff = arr[right] - arr[left];

            if (abs(target - sum) < abs(target - closestSum) || 
                (abs(target - sum) == abs(target - closestSum) && absDiff > maxAbsDiff)) {
                closestSum = sum;
                maxAbsDiff = absDiff;
                result = {arr[left], arr[right]};
            }

            if (sum < target) {
                left++;
            } else {
                right--;
            }
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends