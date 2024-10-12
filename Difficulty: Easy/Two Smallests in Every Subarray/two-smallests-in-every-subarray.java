//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            String[] s = br.readLine().trim().split(" ");
            int[] a = new int[s.length];
            for (int i = 0; i < s.length; i++) a[i] = Integer.parseInt(s[i]);

            Solution obj = new Solution();
            int res = obj.pairWithMaxSum(a);
            System.out.println(res);
        }
    }
}

// } Driver Code Ends





// code written by sunny
class Solution {
    public int pairWithMaxSum(int[] arr) {
        // code here
        int n = arr.length;
        if(n<=1){
            return -1;
        }
        int ans = 0;
        for(int i=0; i<n-1; i++){
            int  sum  = arr[i]+arr[i+1];
            ans = Math.max(ans, sum);
        }
        return ans;
    }
}
