//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

 

class Solution {
public: // code written by sunny
    string addBinary(string& s1, string& s2) {
        int i = s1.size() - 1; 
        int j = s2.size() - 1; 
        int carry = 0;      
        string result = "";     
 
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry; 
            if (i >= 0) sum += s1[i--] - '0';
            if (j >= 0) sum += s2[j--] - '0';
 
            result += (sum % 2) + '0';
 
            carry = sum / 2;
        } 
        reverse(result.begin(), result.end());
        int start = 0;
        while (start < result.size() && result[start] == '0') {
            start++;
        } 
        return start == result.size() ? "0" : result.substr(start);
    }
};


 
 
 
 
 
 
 
 
 


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends