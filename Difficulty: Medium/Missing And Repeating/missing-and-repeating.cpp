//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& num) {
        // code written by sunny
         int m=num.size();
        vector<int> sol;
        for(int j=0;j<m;j++){
            int element = abs(num[j]);
            if(num[element-1]<0)sol.push_back(element);
            else num[element-1]*=-1;
        }
        for(int j=0;j<m;j++){
            if(num[j]>0)sol.push_back(j+1);
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
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends