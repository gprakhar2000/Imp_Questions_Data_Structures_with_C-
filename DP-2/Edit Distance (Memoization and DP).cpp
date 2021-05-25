/*You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character
Note :
Strings don't contain spaces in between.
 Input format :
The first line of input contains the string S of length M.

The second line of the input contains the String T of length N.
Output format :
Print the minimum 'Edit Distance' between the strings.
Constraints :
0 <= M <= 10 ^ 3
0 <= N <= 10 ^ 3

Time Limit: 1 sec
Sample Input 1 :
abc
dc
Sample Output 1 :
2
 Explanation to the Sample Input 1 :
 In 2 operations we can make string T to look like string S.
First, insert character 'a' to string T, which makes it "adc".

And secondly, replace the character 'd' of string T with 'b' from the string S. This would make string T as "abc" which is also string S. 

Hence, the minimum distance.
Sample Input 2 :
whgtdwhgtdg
aswcfg
Sample Output 2 :
9
*/
int editDistance(string s1, string s2)
{
	//Write your code here
    int m=s1.size();
    int n=s2.size();
    int output[m+1][n+1];
    output[0][0]=0;
    for(int i=1;i<=m;i++){
        output[i][0]=i;
    }
    for(int j=1;j<=n;j++){
        output[0][j]=j;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[m-i]==s2[n-j]){
                output[i][j]=output[i-1][j-1];
            }
            else{
                int x=1+output[i-1][j];
                int y=1+output[i-1][j-1];
                int z=1+output[i][j-1];
                output[i][j]=min(x,min(y,z));
            }
        }
    }
    return output[m][n];
}