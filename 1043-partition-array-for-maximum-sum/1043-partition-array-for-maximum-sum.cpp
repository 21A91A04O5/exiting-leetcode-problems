class Solution {
public:
    int maxSub(int i,int j,vector<int>& arr){
        int maxi=0;
        for(int k=i;k<=j;k++){
            maxi=max(maxi,arr[k]);
        }
        return maxi;
    }
    int fun(int i,int k,vector<int>& arr,vector<int>&dp){
        if(dp[i]!=-1)
           return dp[i];
        if(i>=arr.size())
            return 0;
        int pick=0;
        for(int j=1;j<=k;j++){
            if(i+j-1<arr.size()){
                pick=max(pick,j*maxSub(i,i+j-1,arr)+fun(i+j,k,arr,dp));
            }
        }
        return dp[i]=pick;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
       vector<int>dp(arr.size()+1,-1);
       return fun(0,k,arr,dp);
    }
};