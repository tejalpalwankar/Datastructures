class TrieNode{
    public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data){
        this->data = data;
        children = new TrieNode*[26];// 26 is for 26 lower case alphabets
        // we are initializing with null so that itdoes not contain garbage
        for(int i=0; i< 26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};