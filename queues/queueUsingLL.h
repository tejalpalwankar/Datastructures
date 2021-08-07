template <typename T>

class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this->data = data;
        next = NULL;
    }
};

template <typename T>
class queueUsingLL{
    Node<T> *head;
    Node<T> *tail;
    int size;

    public:

    queueUsingLL(){
        head = NULL;
        tail = NULL;
        size =0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    void enqueue(T element){
        Node<T> *newNode = new Node<T>(element);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{tail -> next = newNode;
        tail = newNode;}
        size++;
    }

    T front(){
        if(isEmpty()){
            return 0;
        }
        return head -> data;
    }

    T dequeue(){
        if(isEmpty()){
            return 0;
        }
        Node<T> *temp = head;
        T ans = head ->data ;
        temp = temp -> next;
        delete head;
        head = temp;
        size--;
        return ans;
    }

};