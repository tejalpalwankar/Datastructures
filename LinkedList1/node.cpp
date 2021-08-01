// because we don't have a inbuilt datatype to store int as well as address we make our own class for it

class Node{
    public :
    int data;
    Node *next; //the datatype is node since we have to store the address of int and address together

    // constructor of this class so whenever anyone calls they have to pass data
    Node(int data){
        this -> data = data;
        next = NULL;
    }
};