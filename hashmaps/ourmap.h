#include <string>
using namespace std;

template <typename V>
class MapNode
{
public:
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~MapNode()
    {
        delete next;
    }
};

template <typename V>
class ourmap
{
    MapNode<V> **buckets;
    int count;
    int numBuckets;

public:
    ourmap()
    {
        count = 0;
        numBuckets = 5;
        buckets = new MapNode<V> *[numBuckets];
        // we are intializing by null as it is going to store garbage initially
        for (int i = 0; i < numBuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    ~ourmap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // to del the LL
        }
        delete[] buckets; // to delete the array
    }

    int size()
    {
        return count;
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0;
    }

private:
    int getBucketIndex(string key)
    {
        int hashCode = 0;

        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += key[i] * currentCoeff;
            hashCode = hashCode % numBuckets; // for compression of large values
            currentCoeff *= 37;
            currentCoeff = currentCoeff % numBuckets; // for compression of large values
        }

        return hashCode % numBuckets;
    }

    void rehash(){
        MapNode<V>** temp = buckets;
        buckets = new MapNode<V>*[2*numBuckets];
        for (int i = 0; i < 2*numBuckets; i++){
            buckets[i] = NULL;
        }
        int oldBucketCount = numBuckets;
        numBuckets *=2;
        count = 0;

        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V>* head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }
        for (int i = 0; i < oldBucketCount; i++){
            MapNode<V>* head = temp[i];
            delete head;
        }
        delete [] temp;
        
    }



public:

    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            // to check if the value is already exsisting in the LL and update that val
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucketIndex];
        MapNode<V> *node = new MapNode<V>(key, value);
        node->next = head; // to connect node w the head
        buckets[bucketIndex] = node;
        count++;
        double loadFactor = (1.0*count)/numBuckets;// since it is int/int so 0.3 ka 0 aayega isiliye mult
        if(loadFactor > 0.7){
            rehash();
        }
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex( key);
        MapNode<V> *head = buckets[bucketIndex];
        MapNode<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                // if we found head as our 1st ele
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value; // to not loose the val
                head->next == NULL;    // to not loose the other LL
                delete head;           //memory free
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0;
    }
};