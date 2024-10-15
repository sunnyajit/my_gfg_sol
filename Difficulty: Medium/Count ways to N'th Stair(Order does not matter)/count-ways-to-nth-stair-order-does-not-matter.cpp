//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
	public:
		int nthStair(int n){
		    //  Code written by sunny
		     int count = 0;
            for (int y = 0; y <= n / 2; ++y) {
            int x = n - 2 * y; 
            if (x >= 0) {
                ++count;
            }
        }
        
        return count;
		}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.nthStair(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends