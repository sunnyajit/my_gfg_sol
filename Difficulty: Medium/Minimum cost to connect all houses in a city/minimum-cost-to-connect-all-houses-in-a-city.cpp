//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
 
 
 
 
 
 
 
class Solution {
  public: // code written by sunny
    int minCost(vector<vector<int>>& houses) {
        int n = houses.size();
        vector<bool> visited(n, false);
        vector<int> minDist(n, INT_MAX); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push(make_pair(0, 0));  
        minDist[0] = 0;

        int totalCost = 0;

        while (!pq.empty()) {
            pair<int, int> current = pq.top();
            pq.pop();

            int cost = current.first;
            int u = current.second;

            if (visited[u]) continue;

            visited[u] = true;
            totalCost += cost;

            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int dist = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    if (dist < minDist[v]) {
                        minDist[v] = dist;
                        pq.push(make_pair(dist, v));
                    }
                }
            }
        }

        return totalCost;
    }
};
 







































































//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends