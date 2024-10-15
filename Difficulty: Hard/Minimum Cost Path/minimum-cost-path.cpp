//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends



typedef pair<int, pair<int, int>> pii;
class Solution
{ // code written by sunny
    public:
    int minimumCostPath(vector<vector<int>>& grid) 
    {
            int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];
    vector<int> directions = {-1, 0, 1, 0, 0, -1, 0, 1};

    while (!pq.empty()) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == n - 1 && y == n - 1) return cost;

        for (int i = 0; i < 4; ++i) {
            int nx = x + directions[i * 2];
            int ny = y + directions[i * 2 + 1];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                int newCost = cost + grid[nx][ny];
                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }
    return -1; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends