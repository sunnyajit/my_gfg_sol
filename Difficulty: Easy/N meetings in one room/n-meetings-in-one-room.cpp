//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
     // code written by sunny...
    int maxMeetings(int n, int start[], int end[]) {
    vector<pair<int, int>> meetings;
    for (int i = 0; i < n; ++i) {
        meetings.push_back({end[i], start[i]});
    }
    sort(meetings.begin(), meetings.end());
    int count = 0;
    int lastEndTime = -1;
    for (const auto& meeting : meetings) {
        if (meeting.second > lastEndTime) {
            ++count;
            lastEndTime = meeting.first;
        }
    }
    
    return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends