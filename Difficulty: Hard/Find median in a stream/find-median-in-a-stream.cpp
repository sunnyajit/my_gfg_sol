//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



 
class Solution {
  public: // code written by sunny
    vector<double> getMedian(vector<int> &arr) {
        vector<double> medians;
        priority_queue<int> maxHeap;  
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap for upper half
        
        for (int num : arr) {
          
            maxHeap.push(num);
 
            minHeap.push(maxHeap.top());
            maxHeap.pop(); 
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            } 
            if (maxHeap.size() > minHeap.size()) 
                medians.push_back(maxHeap.top());
            else 
                medians.push_back((maxHeap.top() + minHeap.top()) / 2.0);
        }

        return medians;
    }
};

 

































//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends