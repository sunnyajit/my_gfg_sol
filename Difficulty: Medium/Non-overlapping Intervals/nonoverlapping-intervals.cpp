//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



 class Solution {
  public:
    int minRemoval(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
        });

        int countToRemove = 0;  
        int prevEnd = intervals[0][1];  
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < prevEnd) { 
                countToRemove++;
            } else { 
                prevEnd = intervals[i][1];
            }
        }

        return countToRemove;
    }
};







//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends