//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
 

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public: // code written by sunny
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end()); 
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) {
            freeRooms.push(i);
        } 
        typedef pair<long long, int> RoomInfo;
        priority_queue<RoomInfo, vector<RoomInfo>, greater<RoomInfo>> busyRooms;

        vector<int> count(n, 0); 

        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];
            long long duration = end - start; 
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int roomNumber = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(roomNumber);
            }

            if (!freeRooms.empty()) { 
                int room = freeRooms.top(); freeRooms.pop();
                busyRooms.push(make_pair((long long)end, room));
                count[room]++;
            } else { 
                RoomInfo earliest = busyRooms.top(); busyRooms.pop();
                long long availableTime = earliest.first;
                int room = earliest.second;
                busyRooms.push(make_pair(availableTime + duration, room));
                count[room]++;
            }
        } 
        int maxCount = 0, roomUsed = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                roomUsed = i;
            }
        }

        return roomUsed;
    }
};
 



















//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends