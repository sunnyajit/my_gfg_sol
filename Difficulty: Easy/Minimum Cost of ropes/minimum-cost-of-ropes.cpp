//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
   // code written by sunny
    long long minCost(vector<long long>& arr) {
        long long p = 0;
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        for(auto x:arr)pq.push(x);
        while(pq.size()!=1){
            long long f  = pq.top();
            pq.pop();
            long long s = pq.top();
            pq.pop();
            long long total =  f+s;
            pq.push(total);
            p+=total;
        }
        return p;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends