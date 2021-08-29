#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;
};

// comaprator to sort array of type class
bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight; // to sort in increasing array
}

int findParent(int v, int *parent)
{
    // agar index and data ke val same hui i.e 0 ka parent 0 means we got topmost parent
    if (parent[v] == v)
    {
        return v;
    }

    return findParent(parent[v], parent);
}
void kruskals(Edge *input, int n, int e)
{
    // cout << "inside start" << endl;

    //sort thr input array in asec order based on weights
    sort(input, input + e, compare);

    Edge *output = new Edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while (count != n - 1)
    {
        Edge currentEdge = input[i]; // min edge aagayi isme
        cout << "inside start " << i << " " << count << " " << n - 1 << endl;

        // check if we can add current edge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.destination, parent);

        if (sourceParent != destParent)
        {
            // output[i] = input[i]; we can't use i bcz input mai hum thode chize skip kare hai
            cout << "inside end " << i << " " << count << " " << n - 1 << endl;

            output[count] = currentEdge;
            count++;
            parent[sourceParent] = destParent;
        }
        i++;
        // Edge currentEdge = input[i];
        // int sourceParent = findParent(currentEdge.source , parent);
        // int destParent = findParent(currentEdge.destination , parent);

        // if(sourceParent != destParent){
        //     output[count] = currentEdge;
        //     count++;
        //     parent[sourceParent] = destParent;
        // }
        // i++;
    }
    cout << "inside end 2" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].destination)
        {
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
    // cout << "inside 3" << endl;
}

int main()
{
    // Write your code here
    int n, e;
    cin >> n >> e;

    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    // cout << "before" << endl;
    kruskals(input, n, e);
    // cout << "after" << endl;
}
