#include <climits>
template <typename T>


class stackUsingArray
{
    T *data;
    int nextIndex;
    int capacity;

public:
    stackUsingArray(int totalSize)
    {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    //return the number of elements present in our stack
    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        /*   if(nextIndex == 0){
            return true;
        }
        else{
            return false;
        } */
        // OR
        return nextIndex == 0;
    }

    //insert elemnt
    void push(T element)
    {
       if (nextIndex == capacity)
        {
            T *newData = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete[] data;
            data = newData;
        }

        data[nextIndex] = element;
        nextIndex++;
    }

    //delete element
    T pop()
    {   
        if(isEmpty()){
            cout << "stack is empty" << endl;
            return 0; 
    }
        nextIndex--;
        return data[nextIndex];
    }

    T top(){
         if(isEmpty()){
            cout << "stack is empty" << endl;
            return 0; 
        }
        return data[nextIndex - 1];
    }
};