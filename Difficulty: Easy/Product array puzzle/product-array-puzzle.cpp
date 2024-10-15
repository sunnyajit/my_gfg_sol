//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


// User function template for C++

class Solution {
  public:
     // code written by sunny..
    vector<long long int> productExceptSelf(vector<long long int>& arrs) {
        int m=arrs.size();
        vector<long long int> val(m,1);
        long long int lft=1;
        for(int j=0;j<m;j++){
            val[j]=lft;
            lft=lft*arrs[j];
        }
        long long int rt=1;
        for(int j=m-1;j>=0;j--){
            val[j]*=rt;
            rt=rt*arrs[j];
        }
        return val;
    }
};

//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends