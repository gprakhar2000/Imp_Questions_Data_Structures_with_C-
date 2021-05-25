/*Given an integer array of size N. Sort this array (in decreasing order) using heap sort.
Note: Space complexity should be O(1).
Input Format:
The first line of input contains an integer, that denotes the value of the size of the array or N.
The following line contains N space separated integers, that denote the value of the elements of the array.
Output Format :
The first and only line of output contains array elements after sorting. The elements of the array in the output are separated by single space.
Constraints :
1 <= n <= 10^6
Time Limit: 1 sec
Sample Input 1:
6 
2 6 8 5 4 3
Sample Output 1:
8 6 5 4 3 2
*/

#include<bits/stdc++.h>
using namespace std;
void heapSort(int arr[], int n) {
    // Write your code
    //insert part
    for(int i=1;i<n;i++){
        int child_index=i;
        while(child_index>0){
            int parent_index=(child_index-1)/2;
            if(arr[child_index]<arr[parent_index]){
                swap(arr[child_index],arr[parent_index]);
            }
            else{
                break;
            }
            child_index=parent_index;
        }
        
    }
    //remove min part
    int size=n;
    while(size>1){
        swap(arr[0],arr[size-1]);
        size--;
        int parent_index=0;
        int LCI=2*parent_index+1;
        int RCI=2*parent_index+2;
        while(LCI < size){
            int min_index=parent_index;
            if(arr[LCI]<arr[min_index]){
                min_index=LCI;
            }
            if(RCI < size && arr[RCI]<arr[min_index]){
                min_index=RCI;
            }
            if(min_index==parent_index){
                break;
            }
            swap(arr[min_index],arr[parent_index]);
            parent_index=min_index;
            LCI=2*parent_index+1;
            RCI=2*parent_index+2;
    	} 
    }
    
}