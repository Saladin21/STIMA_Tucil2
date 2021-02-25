#ifndef NODE_HPP
#define NODE_HPP

#include <forward_list>
#include <iostream>
#include <string>
#include <list>
using namespace std;

class Node{
    private:
        int id;
        int inDegree;
        string name;
        static int currentId;
        list<Node*> trail;
        


    public:
        
        Node();
        Node(int id);
        Node(string name);
        void deleteTrail();
        int getId();
        int getInDegree();
        int getOutDegree();
        string getName();
        void addInDegree(int n);
        void minInDegree(int n);
        void connect(Node& N);
        void disconnect(Node& N);
        bool isConnected(Node& N);
        bool operator==(Node& N);
        bool operator!=(Node& N);
        void printTrail();
        
};


#endif