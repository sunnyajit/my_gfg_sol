//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 
 
//  #include <iostream>
// using namespace std;

class Solution {
  public: // coode written by sunny
    int countPS(string &s) {
        int n = s.size();
        int count = 0; 
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 >= 2)   
                    count++;
                left--;
                right++;
            }
        }; 
        for (int i = 0; i < n; i++) {
            expand(i, i);      
            expand(i, i + 1);  
        }

        return count;
    }
};

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends