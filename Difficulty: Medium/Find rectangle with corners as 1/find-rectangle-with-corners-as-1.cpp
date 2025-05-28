class Solution {
  public: // code written by sunny
    bool ValidCorner(vector<vector<int> >& mat) {
        int n = mat.size();
        if (n == 0) return false;
        int m = mat[0].size(); 
         
        unordered_map<int, unordered_set<int>> seen;

        for (int i = 0; i < n; i++) {
            for (int c1 = 0; c1 < m; c1++) {
                if (mat[i][c1] == 1) {
                    for (int c2 = c1 + 1; c2 < m; c2++) {
                        if (mat[i][c2] == 1) {
                            
                            if (seen[c1].count(c2)) {
                                return true;
                            }
                             seen[c1].insert(c2);
                        }
                    }
                }
            }
        }
        
        return false;  
    }
};
