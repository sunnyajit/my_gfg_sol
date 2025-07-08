#include <bits/stdc++.h>
using namespace std;

class Solution {
  public: // code written by sunny
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        unordered_map<int, int> freq;
         
        for (int num : arr) {
            freq[num]++;
        }

        stack<int> st; 
        for (int i = n - 1; i >= 0; i--) {
            int currFreq = freq[arr[i]]; 
            while (!st.empty() && freq[st.top()] <= currFreq) {
                st.pop();
            } 
            if (!st.empty()) {
                res[i] = st.top();
            }
            st.push(arr[i]);
        }

        return res;
    }
};
