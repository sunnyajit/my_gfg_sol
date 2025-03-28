//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public: // code written by sunny
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>> activities; 
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        } 
        sort(activities.begin(), activities.end());

        int count = 1;  
        int lastFinishTime = activities[0].first;
        for (int i = 1; i < n; i++) {
            if (activities[i].second > lastFinishTime) {  
                count++;
                lastFinishTime = activities[i].first;
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends