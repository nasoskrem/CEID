///////////////////////////////////////////////////////////////////////////////////
//
// ONOMA:   ΑΘΑΝΑΣΙΟΣ
// ΕΠΩΝΥΜΟ: ΚΡΕΜΑΝΤΑΛΑΣ
// ΑΜ:      
// ΕΤΟΣ:    2ο ΕΤΟΣ
// ΑΣΚΗΣΗ ΕΡΓΑΣΤΗΡΙΟΥ |5|
//
///////////////////////////////////////////////////////////////////////////////////

// ΚΩΔΙΚΑΣ ΛΥΣΗΣ //

#include <iostream>
#include <list>
#include <queue>
#include <vector>
using namespace std;

void displayGraph(list<int> graph[], int v)  // display the Graph
{
   for(int i = 1; i<v; i++) {
      cout << i << "--->";
      list<int> :: iterator it;
      for(it = graph[i].begin(); it != graph[i].end(); ++it) {
         cout << *it << " ";
      }
      cout << endl;
   }
}

void insert_edge(list<int> graph[], int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// BFS με vector<bool> και vector<int>
int bfs(list<int> graph[], int v, int start, int target) {
    vector<bool> visited(v, false);
    vector<int> level(v, -1);

    queue<int> q;

    visited[start] = true;
    level[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int nxt : graph[curr]) {
            if(!visited[nxt]) {
                visited[nxt] = true;
                level[nxt] = level[curr] + 1;
                q.push(nxt);

                if(nxt == target)
                    return level[nxt];
            }
        }
    }

    return -1;
}

int main() {
    int v = 10;    //number of vertices in graph +1
   //create an array of lists whose size is v
    list<int> graph[v];

    insert_edge(graph, 1, 2);
    insert_edge(graph, 1, 3);

    insert_edge(graph, 2, 4);
    insert_edge(graph, 2, 5);

    insert_edge(graph, 3, 6);

    insert_edge(graph, 4, 7);

    insert_edge(graph, 5, 8);

    insert_edge(graph, 6, 9);

    displayGraph(graph, v);

    int start, target;
    cout << "Δωσε αρχικη κορυφη" << " και κορυφή στόχο: "; 
    cin >> start >> target;

    int result = bfs(graph, v, start, target);

    if (result == -1)
        cout << "Not Discovered" << endl;
    else
        cout << "Level " << result << endl;

    return 0;
}


/* answer
Level 3 */

///////////////////////////////////////////////////////////////////////////////////
//
// ΑΠΟΤΕΛΕΣΜΑ ΕΚΤΕΛΕΣΗΣ
/*  
1--->2 3 
2--->1 4 5 
3--->1 6 
4--->2 7 
5--->2 8 
6--->3 9  
7--->4 
8--->5 
9--->6 
Δωσε αρχικη κορυφη και κορυφή στόχο: 1 8
Level 3
*/