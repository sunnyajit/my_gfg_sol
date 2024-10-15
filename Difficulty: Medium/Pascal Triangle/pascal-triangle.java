//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    // Driver code
    public static void main(String[] args) throws Exception {
        BufferedReader br =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            ArrayList<Long> ans = new Solution().nthRowOfPascalTriangle(n);
            printAns(ans);
        }
    }
    public static void printAns(ArrayList<Long> ans) {
        for (Long x : ans) {
            System.out.print(x + " ");
        }
        System.out.println();
    }
}

// } Driver Code Ends


// User function Template for Java


// User function Template for Java

class Solution {
    ArrayList<Long> nthRowOfPascalTriangle(int n) {
        // code written by sunny
        ArrayList<Long> prev = new ArrayList<>();
        prev.add(1L);
        
        
        for(int i=1; i<n; i++){
            ArrayList<Long> next = new ArrayList<>();
            next.add(1L);
            
            for(int j=1; j<prev.size(); j++){
                next.add((prev.get(j)+prev.get(j-1))%1000000007);
            }
            next.add(1L);
            prev = next;
        }
        
        return prev;
    }
}