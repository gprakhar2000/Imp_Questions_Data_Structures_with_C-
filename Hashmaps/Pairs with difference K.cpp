/*You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.
Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K. 
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6

*/

#include<bits/stdc++.h>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	// Write your code here
    unordered_map<int,int> count;
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    int pair_count=0;
    for(int i=0;i<n;i++){
        if(k==0){
            int n=count[arr[i]];
            pair_count+=n*(n-1)/2;
        }
        else{
            int complement1=(arr[i]-k);
            int complement2=(arr[i]+k);
            if(count.find(complement1)!=count.end()){
                pair_count+=count[complement1]*count[arr[i]];
            }
            if(count.find(complement2)!=count.end()){
                pair_count+=count[complement2]*count[arr[i]];
            }
            
        }
        count.erase(arr[i]);
    }
    return pair_count;
}