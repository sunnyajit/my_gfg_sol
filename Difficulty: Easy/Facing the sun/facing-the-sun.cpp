//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// User function template for C++
class Solution {
  public:
    int countBuildings(vector<int> &height) {
        // code written by sunny
         if (height.empty()) return 0;
        int count = 1; 
        int max_height = height[0];  
        for (int i = 1; i < height.size(); ++i) {
            if (height[i] > max_height) {
                count++;
                max_height = height[i]; 
            }
        }

        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> height;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            height.push_back(number);
        }
        Solution ob;
        int ans = ob.countBuildings(height);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends