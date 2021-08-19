#include <vector>

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
        
        int childIndex = pq.size() -1;
        
        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;
            
            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
        
    }

    int getSize() { 
        return pq.size();
    }
    
    int getMax() {
        if (isEmpty())
        {
            return 0;
        }
        // it will be root thus will pe kept at 0th index
        return pq[0];
    }

    int removeMax() {
        int ans = pq[0];
        pq[0] = pq[pq.size() -1];
        pq.pop_back();
        
        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;
        
        while(leftChildIndex < pq.size() ){
            int minIndex = parentIndex;
            if(pq[parentIndex] < pq[rightChildIndex]){
                minIndex = rightChildIndex;
            }
            if(pq[parentIndex] < pq[leftChildIndex]){
                minIndex = leftChildIndex;
            }
            if(minIndex == parentIndex){
                break;
            }
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;
            
        }
        
        return ans;
    }

    

    bool isEmpty() {
        return pq.size() == 0;

    }
};