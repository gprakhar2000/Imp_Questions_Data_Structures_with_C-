/*Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:
The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].
Output Format:
The first and only line of output prints the minimum number of multiplication needed.
Constraints :
1 <= n <= 100
Time limit: 1 second
Sample Input 1:
3
10 15 20 25
Sample Output 1:
8000
Sample Output Explanation:
There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 15000.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 

*/

#include<bits/stdc++.h>
//memoized solution
int matrixChainMultiplicationRec(int* arr, int i,int j,int **output){
    if(i>=j){
        return 0;
    }
    if(output[i][j]!=-1){
        return output[i][j];
    }
    int temp;
    int min=INT_MAX;
    for(int k=i;k<j;k++){
        temp=matrixChainMultiplicationRec(arr,i,k,output)+matrixChainMultiplicationRec(arr,k+1,j,output)
            +arr[i-1]*arr[k]*arr[j];
        if(temp<min){
             min=temp;
        }
    }
    output[i][j]=min;
    return output[i][j];
}
int matrixChainMultiplication(int* arr, int n) {
    
    // Write your code here
    int **output=new int*[n+1];
    for(int i=0;i<n+1;i++){
        output[i]=new int[n+1];
        for(int j=0;j<n+1;j++){
            output[i][j]=-1;
        }
    }
    return matrixChainMultiplicationRec(arr,1,n,output);
    
}