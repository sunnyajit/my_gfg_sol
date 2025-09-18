class Solution {
  public://  code written by sunny
    vector<int> nextGreater(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);   
        stack<int> st;          
        for (int i = 0; i < 2 * n; i++) {
            int curr = arr[i % n];  
            while (!st.empty() && arr[st.top()] < curr) {
                res[st.top()] = curr;
                st.pop();
            } 
            if (i < n) st.push(i);
        }

        return res;
    }
};
