/*Implement the function RemoveMin for the min priority queue class.
For a minimum priority queue, write the function for removing the minimum element present. Remove and return the minimum element.
Note : main function is given for your reference which we are using internally to test the code.

*/

#include<bits/stdc++.h>
#include <vector>

class PriorityQueue {
    vector<int> pq;

   public:
    bool isEmpty() { 
        return pq.size() == 0; 
    }

    int getSize() { 
        return pq.size(); 
    }

    int getMin() {
        if (isEmpty()) {
            return 0;
        }

        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            } else {
                break;
            }

            childIndex = parentIndex;
        }
    }

    int removeMin() {
        // Write your code here
        int ans=pq[0];
        swap(pq[0],pq[pq.size()-1]);
        pq.pop_back();
        int parent_index=0;
        int LCI=2*parent_index+1;
        int RCI=2*parent_index+2;
        while(LCI<pq.size()){
            int min_index=parent_index;
            if(pq[min_index]>pq[LCI]){
                min_index=LCI;
            }
            if(RCI<pq.size() && pq[LCI]>pq[RCI]){
                min_index=RCI;
            }
            if(min_index==parent_index){
                break;
            }
            swap(pq[parent_index],pq[min_index]);
            parent_index=min_index;
            LCI=2*parent_index+1;
            RCI=2*parent_index+2;
            
        }
        return ans;
        
    }
};