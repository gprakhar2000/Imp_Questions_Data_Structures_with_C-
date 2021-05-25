/*A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
Output format :
Print the the maximum money that can be looted.
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, and all the other possible combinations would result in less than 90.
*/

//DP solution
int maxMoneyLooted(int *arr, int n){
    int ans[n+1];
    ans[0]=0;
    ans[1]=arr[0];
    for(int i=2;i<=n;i++){
        ans[i]=max(arr[i-1]+ans[i-2],ans[i-1]);
    }
    return ans[n];
}


//memoized solution
// int maxMoneyLooted(int *arr, int n,int *output)
// {
// 	//Write your code here
//     if(n==0){
//         return 0;
//     }
//     if(n==1){
//         return arr[0];
//     }
//     if(output[n-1]!=-1){
//         return output[n-1];
//     }
    
//     int x=maxMoneyLooted(arr+1,n-1,output);
//     int y=arr[0]+maxMoneyLooted(arr+2,n-2,output);
//     int ans= max(x,y);
//     output[n-1]=ans;
//     return ans;
// }
// int maxMoneyLooted(int *arr, int n){
//     int *output=new int[n+1];
//     for(int i=0;i<=n;i++){
//         output[i]=-1;
//     }
//     return maxMoneyLooted(arr,n,output);
// }