/*Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If n is divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If n is divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
Input format :
The first and the only line of input contains an integer value, 'n'.
Output format :
Print the minimum number of steps.
Constraints :
1 <= n <= 10 ^ 6
Time Limit: 1 sec
Sample Input 1 :
4
Sample Output 1 :
2 
Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 
Sample Input 2 :
7
Sample Output 2 :
3
Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  

*/

int countStepsToOne(int n){
    int ans[n+1];
    for(int i=0;i<=n;i++){
        ans[i]=-1;
    }
    ans[1]=0;
    ans[2]=1;
    ans[3]=1;
    for(int i=4;i<=n;i++){
        int x=INT_MAX;int y=INT_MAX;
        if(i%2==0){
            x=1+ans[i/2];
        }
        if(i%3==0){
            y=1+ans[i/3];
        }
        int z=1+ans[i-1];
        ans[i]=min(x,min(y,z));
    }
    return ans[n];
}
// memoization solution
// int helper_count(int n,int ans[]){
//     if(n==2 || n==3){
//         return 1;
//     }
//     if(ans[n]!=-1){
//         return ans[n];
//     }
//     int x=INT_MAX;int y=INT_MAX;
//     if(n%3==0){
//         x= 1+helper_count(n/3,ans);
//     }
//     if(n%2==0){
//         y= 1+helper_count(n/2,ans);
//     }
//     int z= 1+helper_count(n-1,ans);
//     ans[n]= min(x,min(y,z));
//     return ans[n];
// }
// int countStepsToOne(int n)
// {
// 	//Write your code here
//     if(n==1){
//         return 0;
//     }
//     int soln[n+1];
//     for(int i=0;i<=n;i++){
//         soln[i]=-1;
//     }
//     return helper_count(n,soln);
// }