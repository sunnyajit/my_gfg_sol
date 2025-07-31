class Solution {
public: // code written by sunny
    int countBalanced(vector<string>& arr) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;  
        int prefixSum = 0;
        int result = 0;

        for (const string& s : arr) {
            int diff = 0;
            for (char c : s) {
                if (isVowel(c)) diff++;
                else diff--;
            }
            prefixSum += diff;
            result += prefixCount[prefixSum];
            prefixCount[prefixSum]++;
        }

        return result;
    }

private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
};
