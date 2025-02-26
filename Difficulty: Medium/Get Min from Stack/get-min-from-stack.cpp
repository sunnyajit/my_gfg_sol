//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

 class Solution {
private: // code written by sunny
    stack<int> s;        
    stack<int> minStack;  

public:
    Solution() {
         
    }
 
    void push(int x) {
        s.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }
 
    void pop() {
        if (!s.empty()) {
            if (s.top() == minStack.top()) {
                minStack.pop();
            }
            s.pop();
        }
    } 
    int peek() {
        return s.empty() ? -1 : s.top();
    } 
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};












































//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMin() << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends