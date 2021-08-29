#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv, bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty())
    {
        int currentVertex = pendingVertices.front();
        cout << currentVertex << endl;
        pendingVertices.pop();
        for (int i = 0; i < n; i++)
        {
            // lets not check 0 ka 0 se edge hai kya
            if (i == currentVertex)
            {
                continue;
            }
            //agar edge hai and visisted nai hai
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(edges, n, i, visited);
        }
    }
    delete[] visited;
}

vector<int> *getPathHelper(int **edges, int n, int sv, int ev, bool *visited)
{
    if (sv == ev)
    {
        vector<int> *output = new vector<int>();
        output->push_back(ev);
        return output;
    }

    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] && !visited[i])
        {
            vector<int> *smallOutput = getPathHelper(edges, n, i, ev, visited);
            if (smallOutput != NULL)
            {
                smallOutput->push_back(sv);
                return smallOutput;
            }
        }
    }
    return NULL;
}

vector<int> *getPath(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<int> *output = getPathHelper(edges, n, sv, ev, visited);
    delete[] visited;
    return output;
}

vector<int> *getPathBFS(int **edges, int n, int sv, int ev)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    pendingVertices.push(sv);
    visited[sv] = true;
    unordered_map<int , int> parent;

    bool done = false;
    while (!pendingVertices.empty() && !done)
    {
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        for (int i = 0; i < n; i++)
        {
            if (edges[currentVertex][i] == 1 && !visited[i])
            {   
                parent[i] = currentVertex;
                pendingVertices.push(i);
                visited[i] = true;
                if (i == ev)
                {
                    done = true; // to come out of while
                    break;
                }
            }
        }
    }
    delete [] visited;

    if (done == false)
    {
        return NULL;
    }
    else{
    vector<int> *output = new vector<int>();
    output->push_back(ev);
    int currentVertex = ev;
    while (currentVertex != sv)
    {
        currentVertex  = parent[currentVertex];
        output->push_back(currentVertex);
    }
    return output;
    }
}

vector<int>* printConnectedHelper(int** edges , int n , int sv , bool* visited){
    vector<int>* smallop;
    visited[sv] = true;
    for(int i =0 ; i < n ; i++){
        if(edges[sv][i] && !visited[i]){
            smallop->push_back(i);
            visited[i]= true;
        }
    }
    return smallop;
}

vector<vector<int>>* printConnected(int** edges , int n , int sv ){
    vector<vector<int>>* ans;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

 ;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                vector<int>* component = printConnectedHelper(edges ,n , i , visited);
				ans->push_back(component);
            }
        }

    return ans;
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    // creating a 2D matrix and initializing it by 0
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        //to remove the garbage vals
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    // taking input the edges and putting them in the matrix
    for (int i = 0; i < e; i++)
    {
        int f, s; // f -first vertex , s- second vertex
        cin >> f >> s;
        edges[f][s] = 1; // denoting we have a edge
        edges[s][f] = 1; // (0,1) and (1,0) dono edges honge
    }

    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    // cout << "DFS " << endl;
    // DFS(edges, n);
    // cout << "BFS " << endl;
    // BFS(edges, n);

    // cout << "enter 1st and last vertex" << endl;
    // int sv, ev;
    // cin >> sv >> ev;
    // vector<int> *output = getPathBFS(edges, n, sv, ev);
    // if (output != NULL)
    // {
    //     cout << "path :" << endl;
    //     for (int i = 0; i < output->size(); i++)
    //     {
    //         cout << output->at(i) << " ";
    //     }
    //     delete output;
    // }
    // else
    // {
    //     cout << " No path found" << endl;
    // }

        vector<vector<int>>* output = printConnected(edges, n, 0);
    if (output != NULL)
    {
        for (int i = 0; i < output->size(); i++)
        {
            for(int j = 0 ; j < output[i]->size() ; i++){
            cout << output[i][j] << " ";
        }
            cout << endl;
        }
    }

    //delete everything

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}
