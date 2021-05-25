/*Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.

*/

#include<bits/stdc++.h>
int MAX=1005;

int solve(string s, string v) {
    int m=s.size();
    int n=v.size();
    int output[m+1][n+1];
    // Write your code here
    for(int i=0;i<=m;i++){
        output[i][0]=1;
    }
    for(int j=0;j<=n;j++){
        output[0][j]=MAX;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char ch=s[i-1];
            int k;
            for(k=j-1;k>=0;k--){
                if(v[k]==ch){
                    break;
                }
            }
            if(k==-1){
                output[i][j]=1;
            }
            else{
                output[i][j]=min(output[i-1][j],1+output[i-1][k]);
            }
        }
    }
    int ans=output[m][n];
    if(ans>MAX){
        return -1;
    }
    return ans;

}