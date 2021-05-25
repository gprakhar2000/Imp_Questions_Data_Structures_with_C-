/*A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
Input format :
The first and the only line of input contains an integer value, 'n', denoting the total number of steps.
Output format :
Print the total possible number of ways.
 Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1:
4
Sample Output 1:
7
Sample Input 2:
10
Sample Output 2:
274

*/

long staircase(int n)
{
	//Write your code here
    long int ans[n+1];
    for(long int i=0;i<=n;i++){
        ans[i]=-1;
    }
    ans[0]=1;
    ans[1]=1;
    ans[2]=2;
    for(int i=3;i<=n;i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
    
}