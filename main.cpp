#include "Graph.hpp"


void topologicalSort(Graph& G);

int main(){
    Graph G;
    G.addNode("N1");
    G.addNode("N2");
    G.addNode("N3");
    G.addNode("N4");
    G.addNode("N5");
    G.addEdge(G.getNode("N3"), G.getNode("N1"));
    G.addEdge(G.getNode("N1"), G.getNode("N2"));
    G.addEdge(G.getNode("N4"), G.getNode("N2"));
    G.addEdge(G.getNode("N1"), G.getNode("N4"));
    G.addEdge(G.getNode("N3"), G.getNode("N4"));
    G.addEdge(G.getNode("N2"), G.getNode("N5"));
    G.addEdge(G.getNode("N4"), G.getNode("N5"));
    G.printGraph();
    cout << endl;
    G.printInDegree();
    cout << endl;
    //topologicalSort(G);
    G.getNode("N1").printTrail();
    G.deleteNode(G.getNode("N3"));
    G.printInDegree();
    cout << endl;
    G.getNode("N1").printTrail();
    G.deleteNode(G.getNode("N1"));
    G.printInDegree();

    
    return 0;
}

void topologicalSort(Graph& G){
    list<int> temp;
    for (int i =1; i<=8 ; i ++){
        temp = G.getZeroNodes();
        for (int k : temp){
            cout << k << endl;
        }
        if(temp.size() > 0){
            cout << "Semester " << i << ": ";
            for (int j : temp){
                cout << G.getNode(j).getName();
                G.deleteNode(G.getNode(j));
            }
            cout << endl;
            G.printInDegree();
        }
        else if(G.countNodes() > 0){
            cout << "gagal, tidak ada lagi mata kuliah yang bisa diambil"<< endl;
            break;
        }
    }
    
}