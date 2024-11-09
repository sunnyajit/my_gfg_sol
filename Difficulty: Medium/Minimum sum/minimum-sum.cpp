//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public: /// code written by sunny
     string minSum(vector<int> &arr) {
         sort(arr.begin(), arr.end());
          string num1, num2;
        for (int i = 0; i < arr.size(); ++i) {
            if (i % 2 == 0) {
                num1 +=  to_string(arr[i]);
            } else {
                num2 += to_string(arr[i]);
            }
        }
         string result = addStrings(num1, num2);
        result.erase(0, result.find_first_not_of('0'));
        return result.empty() ? "0" : result;
    }

private:
     string addStrings(const  string &num1, const  string &num2) {
         string result;
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
       reverse(result.begin(), result.end());
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends