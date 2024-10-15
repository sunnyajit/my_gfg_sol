//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.lang.*;
import java.util.*;

class GFG implements Runnable {
    public void run() {
        try {
            BufferedReader in;
            PrintWriter out;
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            int t = Integer.parseInt(in.readLine());

            while (t-- > 0) {
                int n = Integer.parseInt(in.readLine().trim());

                Solution g = new Solution();
                out.println(g.countWays(n));
            }
            out.close();
        } catch (Exception e) {
            ;
        }
    }

    public static void main(String args[]) throws IOException {
        new Thread(null, new GFG(), "whatever", 1 << 26).start();
    }
}
// } Driver Code Ends



class Solution
{
    static long countWays(int n)
    {
        // code written by sunny
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 4;
        long a=1, b=2, c=4, ans=0;
        
        for(int i=4; i<=n; i++){
            ans = (a+b+c)%1000000007;
            a=b;
            b=c;
            c=ans;
        }
        
        return ans;
        
        
    }
    
}