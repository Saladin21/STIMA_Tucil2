#ifndef GRAPH_HPP
#define GRAPH_HPP
#include "13519187_node.hpp"
#include "list"

class Graph{
    private:
        list<Node> Nodes;

    public:
        Graph(); //konstruktor
        ~Graph(); //destruktor
        void addNode(string name); //membuat node dengan nama name
        void deleteNode(Node& N); //menghapus node N dari graph
        void addEdge(Node& N1, Node& N2); //menambah hubungan (N1, N2)
        void deleteEdge(Node& N1, Node& N2); //menghapus hubungan (N1, N2)
        Node& getNode(int id); //mengembalikan node dengan id id
        Node& getNode(string name); //mengembalikan node dengan nama name
        void printGraph(); //menampilkan graph ke layar
        void printInDegree(); //menampilkan derajat masuk semua node
        //mengembalikan list yang berisi semua id node dengan derajat masuk 0
        list<int> getZeroNodes(); 
        int countNodes(); //menghitung jumlah semua node
        bool nodeExist(string name); //mengecek apakah terdapat node dengan nama name

};

#endif