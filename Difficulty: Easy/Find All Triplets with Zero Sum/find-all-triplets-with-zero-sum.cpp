//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution { 
public: // code written by sunny
    vector<vector<int>> findTriplets(vector<int> &arr) {
        vector<vector<int>> sol;
        int m = arr.size();
        for(int x = 0; x < m; x++) {
            int first = arr[x];
            for(int y = x + 1; y < m; y++) {
                int second = arr[y];
                for(int z = y + 1; z < m; z++) {
                    int third = arr[z];
                    if(first + second + third == 0) {
                        sol.push_back({x, y, z});
                    }
                }
            }
        }
        return sol;
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends