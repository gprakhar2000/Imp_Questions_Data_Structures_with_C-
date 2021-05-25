/*Implement the class for Max Priority Queue which includes following functions -
1. getSize -
Return the size of priority queue i.e. number of elements present in the priority queue.
2. isEmpty -
Check if priority queue is empty or not. Return true or false accordingly.
3. insert -
Given an element, insert that element in the priority queue at the correct position.
4. getMax -
Return the maximum element present in the priority queue without deleting. Return -Infinity if priority queue is empty.
5. removeMax -
Delete and return the maximum element present in the priority queue. Return -Infinity if priority queue is empty.
Note : main function is given for your reference which we are using internally to test the class.

*/

#include<bits/stdc++.h>
class PriorityQueue {
    // Declare the data members here
   vector<int> pq;
   public:
    PriorityQueue() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        // Implement the insert() function here
        pq.push_back(element);
        int child_index=pq.size()-1;
        while(child_index>0){
            int parent_index=(child_index-1)/2;
            if(pq[parent_index] < pq[child_index]){
                swap(pq[parent_index],pq[child_index]);
            }
            else{
                break;
            }
            child_index=parent_index;
           
        }
    }

    int getMax() {
        // Implement the getMax() function here
        if(pq.size()==0){
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        // Implement the removeMax() function here
        int ans=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int parent_index=0;
        int LCI=2*parent_index+1;
        int RCI=2*parent_index+2;
        while(LCI<pq.size()){
            int max_index=parent_index;
            if(pq[LCI]>pq[max_index]){
                max_index=LCI;
            }
            if(RCI<pq.size() && pq[RCI]>pq[max_index]){
                max_index=RCI;
            }
            if(max_index==parent_index){
                break;
            }
            swap(pq[parent_index],pq[max_index]);
            parent_index=max_index;
            LCI=2*parent_index+1;
        	RCI=2*parent_index+2;
        }
        return ans;
    }

    int getSize() { 
        // Implement the getSize() function here
        return pq.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here
        return pq.size()==0;
    }
};