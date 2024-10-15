//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++

// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code written by sunny
         vector<int> pos,neg;
        for(auto y:arr){
            if(y>=0)pos.push_back(y);
            else neg.push_back(y);
        }
        int a=0,b=0,c=0;
        while(a<pos.size() and b<neg.size()){
            if(c%2)arr[c++]=neg[b++];
            else arr[c++]=pos[a++];
        }
        while(a<pos.size())arr[c++]=pos[a++];
        while(b<neg.size())arr[c++]=neg[b++];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends