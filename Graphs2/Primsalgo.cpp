#include <iostream>
#include <climits>
using namespace std;

int minWeightVertex(bool* visited, int* weights , int n){
    
    int minVertex = -1;
    // initially minVertex -1 hoga tabhi hum kisse compare karenge
    for(int i =0 ; i< n ; i++){
        if(!visited[i] && (minVertex == -1 ||  weights[i] < weights[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void Prims(int **edges, int n){
    bool *visited = new bool[n];
    int *weights = new int[n];
    int *parents = new int[n];
    
    // setting default values for all
    for(int i =0 ; i < n ; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    // initializing the 1st vertex
    parents[0] = -1;
    weights[0] = 0;

    for(int i = 0 ; i < n - 1 ; i++){
        // Find minVertex
        int minVertex = minWeightVertex(visited,weights,  n);
        visited[minVertex] = true;

        //Explore unvisited neighbbours
        for(int j =0 ; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weights[j]){  // if humare paas better weight aaya toh usse pick karo
                    weights[j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }

    for(int i = 1; i < n ; i++){
        if(parents[i] < i){
            cout << parents[i] << " "<< i << " " << weights[i] << endl;
        }
        else{
            cout << i << " "<< parents[i] << " " << weights[i] << endl;

        }
    }

}

int main() {
    // Write your code here
    int n , e;
    cin >> n >> e;
    
    // making the matrix and removing garbage
    int **edges = new int *[n];
    for(int i =0 ; i < n ; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    //taking input
    for (int i = 0; i < e; i++)
    {
        int f, s, w; // f -first vertex , s- second vertex
        cin >> f >> s >> w;
        edges[f][s] = w; // denoting we have a edge
        edges[s][f] = w; // (0,1) and (1,0) dono edges honge
    }

cout << endl;
Prims(edges , n);

for(int i =0 ;i < n ; i++){
    delete [] edges[i];
}
delete [] edges;
    
}





