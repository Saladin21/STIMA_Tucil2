#ifndef NODE_HPP
#define NODE_HPP

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
        
        Node(); //Konstruktor
        Node(string name); //konstruktor
        void deleteTrail(); //Menghapus trail milik node
        int getId(); //mengembalikan id node
        int getInDegree(); //mengembalikan derajat masuk node
        int getOutDegree(); //mengembalikan derajat keluar node
        string getName(); //mengembalikan nama node
        void addInDegree(int n); //menambah derajat masuk node
        void minInDegree(int n); //mengurangi derajat masuk node
        void connect(Node& N); //membuat hubungan (Node, N)
        void disconnect(Node& N); //menghapus hubungan (Node, N)
        bool isConnected(Node& N); //Mengecek apakah Node dan N terhubung
        bool operator==(Node& N); //mengecek apakah id Node dan N sama
        bool operator!=(Node& N); //mengecek apakah id Node dan N berbeda
        void printTrail(); //Menampilkan trail ke layar
        
};


#endif