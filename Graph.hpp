#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "node.hpp"
#include "vector"

class Graph{
    private:
        vector<Node> Nodes;

    public:
        Graph();
        ~Graph();
        void addNode(string name);
        void deleteNode(Node& N);
        void addEdge(Node& N1, Node& N2);
        void deleteEdge(Node& N1, Node& N2);
        Node& getNode(int id);
        Node& getNode(string name);
        Node& getNodeZeroInDegree();
        bool zeroInDegreeExist();
        void printGraph();
        void printInDegree();
        list<int> getZeroNodes();
        int countNodes();
};

#endif