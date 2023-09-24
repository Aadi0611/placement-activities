class Solution {
    public int[] countBits(int n) {
        int res[] = new int[n + 1];
        
        for(int i = 0; i <= n; i++){
            res[i] = solve(i);
        }
        return res;
    }
    public int solve(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(n % 2 == 0) return solve(n / 2); 
        else return 1 + solve(n / 2); 
    }
}