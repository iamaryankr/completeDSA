#include<bits/stdc++.h>
using namespace std;

class Maxcostofrodcutting{
public:
    //memoized
    int cutRodUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp){
        if(ind == 0){
            return N*price[0];
        }
        if(dp[ind][N]!=-1) return dp[ind][N];
    
        int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
        int taken = INT_MIN;
        int rodLength = ind+1;
        if(rodLength <= N)
            taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);
            
        return dp[ind][N] = max(notTaken,taken);
    }


    int cutRod(vector<int>& price,int N) {

        vector<vector<int>> dp(N,vector<int>(N+1,-1));
        return cutRodUtil(price,N-1,N,dp);
    }

    //tabulation
    int cutRod(vector<int>& price,int N) {

        vector<vector<int>> dp(N,vector<int>(N+1,-1));
        
        for(int i=0; i<=N; i++){
            dp[0][i] = i*price[0];
        }
        
        for(int ind=1; ind<N; ind++){
            for(int length =0; length<=N; length++){
            
                int notTaken = 0 + dp[ind-1][length];
        
                int taken = INT_MIN;
                int rodLength = ind+1;
                if(rodLength <= length)
                    taken = price[ind] + dp[ind][length-rodLength];
            
                dp[ind][length] = max(notTaken,taken);   
            }
        }
        
        return dp[N-1][N];
        }

    //space optimized
    int cutRodUtil(vector<int>& price, int ind, int N, vector<vector<int>>& dp){

        if(ind == 0){
            return N*price[0];
        }
        
        if(dp[ind][N]!=-1)
            return dp[ind][N];
            
        int notTaken = 0 + cutRodUtil(price,ind-1,N,dp);
        
        int taken = INT_MIN;
        int rodLength = ind+1;
        if(rodLength <= N)
            taken = price[ind] + cutRodUtil(price,ind,N-rodLength,dp);
            
        return dp[ind][N] = max(notTaken,taken);
    }


    int cutRod(vector<int>& price,int N) {

        vector<int> cur (N+1,0);
        
        for(int i=0; i<=N; i++){
            cur[i] = i*price[0];
        }
        
        for(int ind=1; ind<N; ind++){
            for(int length =0; length<=N; length++){
            
                int notTaken = 0 + cur[length];
        
                int taken = INT_MIN;
                int rodLength = ind+1;
                if(rodLength <= length)
                    taken = price[ind] + cur[length-rodLength];
            
                cur[length] = max(notTaken,taken);   
            }
        }
        
        return cur[N];
    }

};