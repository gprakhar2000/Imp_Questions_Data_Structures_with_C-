/*Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :
The first and the only line of input contains an integer value, 'N'.
 Output format :
Print the minimum count of numbers required.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :
12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1

*/

//dynamic programming
int minCount(int n){
    int ans[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2]=2;
    ans[3]=3;
    for(int i=4;i<=n;i++){
        ans[i]=i;
        for(int j=1;j<=sqrt(i);j++){
            if(j*j>i){
                break;
            }
            else{
                ans[i]=min(ans[i],1+ans[i-j*j]);
            }
        }
    }
    return ans[n];
}





//memoization
// int minCount(int n,int arr[]){
//     if(n<=3){
//         return n;
//     }
//     if(arr[n]!=-1){
//         return arr[n];
//     }
//     arr[n]=n;
//     for(int i=1;i<=sqrt(n);i++){
//         if(i*i>n){
//             break;
//         }
//         else{
//             arr[n]=min(arr[n],1+minCount(n-i*i,arr));
//         }
//     }
//     return arr[n];
// }
// int minCount(int n){
//     int arr[n+1];
//     for(int i=0;i<=n;i++){
//         arr[i]=-1;
//     }
//     return minCount(n,arr);
// }







//Brute force
// int minCount(int n)
// {
// 	//Write your code here
//     if(sqrt(n)-floor(sqrt(n))==0){
//         return 1;
//     }
//     if(n<=3){
//         return n;
//     }
//     int min_count=n;
//     for(int i=1;i<=sqrt(n);i++){
//         if(i*i>n){
//             break;
//         }
//         else{
//             min_count=min(min_count,1+minCount(n-i*i));
//         }
//     }
//     return min_count;
// }