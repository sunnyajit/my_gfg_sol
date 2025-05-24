 
 
 
 
 
 
class Solution {
  public: // code written by sunny
    int sumSubstrings(string &s) {
        int n = s.length();
        long long result = 0;
        long long prev = 0;

        for (int i = 0; i < n; ++i) {
            int digit = s[i] - '0';
            prev = prev * 10 + (long long)(i + 1) * digit;
            result += prev;
        }

        return (int)result; 
    }
};
 