#include "node.hpp"

int Node::currentId = 0;

Node::Node(){
    this->id = currentId;
    this->name = "No name";
    this->inDegree = 0;
    currentId++;
}

Node::Node(int id){
    this->name = "No name";
    this->id = id;
    this->inDegree = 0;
}

Node::Node(string name){
    this->id = currentId;
    this->name = name;
    this->inDegree = 0;
    currentId++;
}

void Node::deleteTrail(){
    list<Node*>::iterator p;
    for (p = this->trail.begin();p!=this->trail.end();++p){
        (*p)->inDegree--;
    }
}

int Node::getId(){
    return this->id;
}

string Node::getName(){
    return this->name;
}

int Node::getInDegree(){
    return this->inDegree;
}

int Node::getOutDegree(){
    int count =0;
    for (Node* N : this->trail){
        count++;
    }
    return count;
}

void Node::addInDegree(int n){
    this->inDegree += n;
}
        

void Node::minInDegree(int n){
    this->inDegree -= n;
}

void Node::connect(Node& N){
    this->trail.push_back(&N);
}

void Node::disconnect(Node& N){
    list<Node*>::iterator p;
    p = this->trail.begin();
    while((*p)->getId() != N.getId()){
        advance(p,1);
    }
    this->trail.erase(p);
}

bool Node::isConnected(Node& N){
    list<Node*>::iterator p;
    for (p = this->trail.begin();p!=this->trail.end();++p){
        if ((*p)->getId() == N.getId()){
            return true;
        }
    }
    return false;
}

bool Node::operator==(Node& N){
    return this->getId() == N.getId();
}

bool Node::operator!=(Node& N){
    return this->getId() != N.getId();
}

void Node::printTrail(){
    list<Node*>::iterator p;
    for(p=this->trail.begin();p!=this->trail.end();++p){
        cout << (*p)->getName() << " ";
    }
}
