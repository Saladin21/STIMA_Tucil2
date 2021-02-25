#include "Graph.hpp"



Graph::Graph(){

}

Graph::~Graph(){
    
}

void Graph::addNode(string name){
    Node N(name);
    Nodes.push_back(N);
}

void Graph::deleteNode(Node& N){
    //hapus semua hubungan ke N
    list<Node>::iterator p1;
    for(auto p1 = begin(this->Nodes);p1!=end(this->Nodes);++p1){        
        if ((*p1).isConnected(N)){
            this->deleteEdge((*p1), N);
        }
    }
    
    //hapus node
    list<Node>::iterator p;
    p = Nodes.begin();
    while((*p) != N){
        advance(p,1);
    }
    (*p).deleteTrail();
    Nodes.erase(p);
}

void Graph::addEdge(Node& N1, Node& N2){
    
    N2.addInDegree(1);
    N1.connect(N2);
}

void Graph::deleteEdge(Node& N1, Node& N2){
    N2.minInDegree(1);
    N1.disconnect(N2);
}

Node& Graph::getNode(int id){
    list<Node>::iterator p;
    p = Nodes.begin();
    while((*p).getId() != id){
        advance(p,1);
    }
    return (*p); 
}

Node& Graph::getNode(string name){
    list<Node>::iterator p;
    p = Nodes.begin();
    while((*p).getName() != name){
        advance(p,1);
    }
    return (*p); 
}

void Graph::printGraph(){
    list<Node>::iterator p;
    
    for (p=this->Nodes.begin();p!=this->Nodes.end();++p){
        cout << (*p).getName() << ": ";
        (*p).printTrail();
        cout << endl;
    }
}



void Graph::printInDegree(){
    list<Node>::iterator p;
    
    for (p=this->Nodes.begin();p!=this->Nodes.end();++p){
        cout << (*p).getName() << ": " << (*p).getInDegree()<<endl;
    }
}

int Graph::countNodes(){
    int count = 0;
    for (Node N : Nodes){
        count++;
    }
    return count;
}

list<int> Graph::getZeroNodes(){
    list<int> temp;
    list<Node>::iterator p;
    for (p = this->Nodes.begin();p!=this->Nodes.end();++p){
        if((*p).getInDegree() == 0){
            temp.push_back((*p).getId());
        }
    }
    return temp;
}