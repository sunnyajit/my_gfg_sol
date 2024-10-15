//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public: // code written by sunny
     static bool comp(pair<int,int> m, pair<int,int>n){
        if(m.second==n.second) return m.first<n.first;
        return m.second>n.second;
    }
    
    vector<int> sortByFreq(vector<int>& num) {
        vector<int>part;
        unordered_map<int,int> map;
        for(auto it:num){
            map[it]++;
        }
        vector<pair<int,int>> v;
        for(auto it:map){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),comp);
        
        for(auto it:v){
            int count=it.second;
            while(count--) part.push_back(it.first);
        }
        return part;
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
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends