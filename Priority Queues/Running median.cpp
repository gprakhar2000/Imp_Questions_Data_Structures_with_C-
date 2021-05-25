/*You are given a stream of N integers. For every i-th integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer N, denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10^5
1 <= Ai <= 10^5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/

#include<bits/stdc++.h>
void printRunningMedian(int *arr, int n) {
    // Write your code here
    if(n==0){
        return;
    }
    priority_queue<int> s; //max heap to store element just greater on left side
    priority_queue<int,vector<int>,greater<int>> g;
    int med=arr[0];
    cout<<arr[0]<<" ";
    s.push(arr[0]);
    for(int i=1;i<n;i++){
        if(s.size()>g.size()){
            if(arr[i]<s.top()){
                g.push(s.top());
                s.pop();
                s.push(arr[i]);
            }
            else{
                g.push(arr[i]);
            }
            med=(s.top()+g.top())/2;
        }
        else if(s.size()==g.size()){
            if(arr[i]<s.top()){
                s.push(arr[i]);
                med=s.top();
            }
            else{
                g.push(arr[i]);
                med=g.top();
            }
        }
        else{
            if(arr[i]>g.top()){
                s.push(g.top());
                g.pop();
                g.push(arr[i]);
            }
            else{
                s.push(arr[i]);
            }
             med=(s.top()+g.top())/2;
        }
        cout<<med<<" ";
        
    }
}