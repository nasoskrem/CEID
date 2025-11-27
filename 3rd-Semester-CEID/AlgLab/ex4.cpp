///////////////////////////////////////////////////////////////////////////////////
//
// ONOMA:   ΑΘΑΝΑΣΙΟΣ
// ΕΠΩΝΥΜΟ: ΚΡΕΜΑΝΤΑΛΑΣ
// ΑΜ:      
// ΕΤΟΣ:    2ο ΕΤΟΣ
// ΑΣΚΗΣΗ ΕΡΓΑΣΤΗΡΙΟΥ |4|
//
///////////////////////////////////////////////////////////////////////////////////

// ΚΩΔΙΚΑΣ ΛΥΣΗΣ //


#include <iostream>
#include <list>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

// Global variables for DFS
vector<bool> discovered;
vector<int> discoveryTime;
vector<int> finishTime;
vector<int> parent;
int timer;

// Vectors to store different types of edges
vector<pair<int, int>> treeEdges;
vector<pair<int, int>> forwardEdges;
vector<pair<int, int>> backEdges;
vector<pair<int, int>> crossEdges;

void displayGraph(list<int> graph[], int v) {
    for (int i = 1; i < v; i++) {
        cout << i << " ---> ";
        for (auto it = graph[i].begin(); it != graph[i].end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

void insert_edge(list<int> graph[], int u, int v) {
    graph[u].push_back(v);
}

// Sort all adjacency lists in ascending order
void sortGraph(list<int> graph[], int v) {
    for (int i = 1; i < v; i++) {
        graph[i].sort();
    }
}

void DFS_Visit(list<int> graph[], int u) {
    timer++;
    discoveryTime[u] = timer;
    discovered[u] = true;

    for (auto v : graph[u]) {
        if (!discovered[v]) {
            // Tree Edge
            treeEdges.push_back({u, v});
            parent[v] = u;
            DFS_Visit(graph, v);
        } else if (finishTime[v] == 0) {
            // Back Edge - v is discovered but not finished (in recursion stack)
            backEdges.push_back({u, v});
        } else if (discoveryTime[u] < discoveryTime[v]) {
            // Forward Edge - u is ancestor of v in DFS tree
            forwardEdges.push_back({u, v});
        } else {
            // Cross Edge
            crossEdges.push_back({u, v});
        }
    }

    timer++;
    finishTime[u] = timer;
}

void DFS(list<int> graph[], int v) {
    // Initialize arrays
    discovered.resize(v, false);
    discoveryTime.resize(v, 0);
    finishTime.resize(v, 0);
    parent.resize(v, -1);
    timer = 0;

    // Clear the edge vectors
    treeEdges.clear();
    forwardEdges.clear();
    backEdges.clear();
    crossEdges.clear();

    for (int i = 1; i < v; i++) {
        if (!discovered[i]) {
            DFS_Visit(graph, i);
        }
    }
}

void printEdgeClassification() {
    cout << "Tree Edges" << endl;
    for (auto edge : treeEdges) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    cout << "Forward Edges" << endl;
    for (auto edge : forwardEdges) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    cout << "Back Edges" << endl;
    for (auto edge : backEdges) {
        cout << edge.first << " " << edge.second << endl;
    }
    
    cout << "Cross Edges" << endl;
    for (auto edge : crossEdges) {
        cout << edge.first << " " << edge.second << endl;
    }
}

int main(int argc, char *argv[]) {
    int v = 10; // Number of vertices (+1 for 1-based indexing)

    // Create an adjacency list representation of the graph
    list<int> graph[v];

    // Insert edges
    insert_edge(graph, 1, 5);
    insert_edge(graph, 1, 9);
    insert_edge(graph, 1, 2);
    insert_edge(graph, 1, 3);

    insert_edge(graph, 2, 1);
    insert_edge(graph, 2, 6);
    insert_edge(graph, 2, 4);

    insert_edge(graph, 3, 7);
    insert_edge(graph, 3, 5);
    insert_edge(graph, 3, 2);
    insert_edge(graph, 3, 8);

    insert_edge(graph, 4, 9);
    insert_edge(graph, 4, 3);
    insert_edge(graph, 4, 1);

    insert_edge(graph, 5, 2);
    insert_edge(graph, 5, 6);
    insert_edge(graph, 5, 4);
    insert_edge(graph, 5, 8);

    insert_edge(graph, 6, 3);
    insert_edge(graph, 6, 5);

    insert_edge(graph, 7, 1);
    insert_edge(graph, 7, 9);
    insert_edge(graph, 7, 8);
    insert_edge(graph, 7, 6);

    insert_edge(graph, 8, 5);
    insert_edge(graph, 8, 4);
    insert_edge(graph, 8, 7);

    insert_edge(graph, 9, 2);
    insert_edge(graph, 9, 8);
    insert_edge(graph, 9, 6);
    insert_edge(graph, 9, 7);

    // Sort all adjacency lists in ascending order
    sortGraph(graph, v);

    // Perform DFS and classify edges
    DFS(graph, v);

    // Print the edge classification in the exact format you specified
    printEdgeClassification();

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////
//
// ΑΠΟΤΕΛΕΣΜΑ ΕΚΤΕΛΕΣΗΣ
/*  
Tree Edges
1 2
2 4
4 3
3 5
5 6
5 8
8 7
7 9
Forward Edges
3 7
3 8
4 9
2 6
1 3
1 5
1 9
Back Edges
2 1
4 1
3 2
5 2
5 4
6 3
6 5
8 4
8 5
7 1
7 8
9 2
9 7
9 8
Cross Edges
7 6
9 6
*/