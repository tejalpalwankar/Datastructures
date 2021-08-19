#include <vector>

class priorityQueue
{
    vector<int> pq;

public:
    priorityQueue()
    {
    }

    bool isEmpty()
    {
        // if 0 then true else false
        return pq.size() == 0;
    }

    // return size of pq - no. of elements
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        // it will be root thus will pe kept at 0th index
        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childIndex = pq.size() - 1;

        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;

            if (pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }
            childIndex = parentIndex;
        }
    }

    int removeMin()
    {
        // Write your code here
         if (isEmpty())
        {
            return 0;
        }

        int ans = pq[0];
        int remove = pq.size() - 1;
        pq[0] = pq[remove];
        pq.pop_back();

        int PI = 0;        
        int LeftChildIndex = 2 * PI + 1;
        int RightChildIndex = 2 * PI + 2;
        while (LeftChildIndex < pq.size())
        {   int minIndex = PI;

            if(pq[minIndex] > pq[LeftChildIndex]){
                minIndex = LeftChildIndex;
            }
            if(pq[minIndex] > pq[RightChildIndex] && RightChildIndex < pq.size()){
                minIndex = RightChildIndex;
            }
            if(minIndex == PI){
                break; 
            }
            int temp = pq[PI];
            pq[PI] = pq[minIndex];
            pq[minIndex] = temp;

            PI = minIndex;
            LeftChildIndex = 2 * PI + 1;
            RightChildIndex = 2 * PI + 2;
        }
        return ans;
    }


};