//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{   // code written by sunny
    public:
    string smallestWindow (string s, string p)
    {
        if (s.size() < p.size()) return "-1";   

    vector<int> freq_p(26, 0), window_freq(26, 0);
    for (char c : p) {
        freq_p[c - 'a']++;
    }
    
    int start = 0, min_len = INT_MAX, min_start = -1, matched = 0;
    int required = 0;   
    for (int i = 0; i < 26; ++i) {
        if (freq_p[i] > 0) required++;
    }
    for (int end = 0; end < s.size(); ++end) {
        char end_char = s[end];
        window_freq[end_char - 'a']++;
        if (freq_p[end_char - 'a'] > 0 && window_freq[end_char - 'a'] == freq_p[end_char - 'a']) {
            matched++;
        }
        while (matched == required) {
            if (end - start + 1 < min_len) {
                min_len = end - start + 1;
                min_start = start;
            }
            char start_char = s[start];
            window_freq[start_char - 'a']--;
            if (freq_p[start_char - 'a'] > 0 && window_freq[start_char - 'a'] < freq_p[start_char - 'a']) {
                matched--;
            }
            start++;
        }
    }
    return min_start == -1 ? "-1" : s.substr(min_start, min_len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends