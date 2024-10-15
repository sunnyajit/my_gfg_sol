//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code written by sunny
        unordered_map<int, pair<int, int>> positions;  
        int maxDist = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (positions.find(arr[i]) == positions.end()) {
                positions[arr[i]] = {i, i};
            } else {
                positions[arr[i]].second = i;
            }
        }
        for (const auto& entry : positions) {
            int distance = entry.second.second - entry.second.first;  
            maxDist = max(maxDist, distance);
        }
        return maxDist;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends