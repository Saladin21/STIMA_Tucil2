#include "13519187_Graph.hpp"
#include <fstream>
#include <vector>


void readGraph(string file, Graph& G); //Membaca graph dari file
void topologicalSort(Graph& G); //Melakukan topological sort

int main(){
    Graph G;
    string file;
    cout << "Masukkan nama file: ";
    cin >> file;
    readGraph("../test/"+file, G); //Membaca graph
    topologicalSort(G); //melakukan topological sort
    system("pause");
    
    return 0;
}

void topologicalSort(Graph& G){
    list<int> temp;
    for (int i =1; i<=8 ; i ++){
        //id semua node dengan derajat masuk 0 disimpan dalam list temp
        temp = G.getZeroNodes();

        if(temp.size() > 0){
            //Menampilkan nama node dengan derajat masuk 0
            cout << "Semester " << i << ": ";
            for (int j : temp){
                cout << G.getNode(j).getName() << " ";
                //menghapus node yang sudah ditampilkan
                G.deleteNode(G.getNode(j)); 
            }
            cout << endl;
        }
        //Tidak terdapat node dengan derajat masuk 0
        else if(G.countNodes() > 0){
            cout << "gagal, tidak ada lagi mata kuliah yang bisa diambil"<< endl;
            break;
        }
    }
    //Graph belum kosong setelah 8 semester
    if (G.countNodes() > 0){
        cout << "Masih terdapat mata kuliah yang belum diambil, ";
        cout << "Tidak dapat diselesaikan dalam 8 semester" <<endl;
    }
    
}

void readGraph(string file, Graph& G){
    ifstream scanner(file);
    string text, temp, head;
    vector<string> nodes;
    int i;

    while(getline(scanner, text)){
        
        i = 0;
        
        nodes.clear();
        while(text[i] != '.'){
            temp = "";
            while(text[i] != ',' && text[i] != '.'){
                if (text[i] != ' '){
                    temp = temp + text[i];
                }
                i++;
            }
            nodes.push_back(temp);
            if (text[i] != '.'){
                i++;
            }
        }

        head = nodes[0];
        if (!G.nodeExist(head)){
                G.addNode(head);
            }
        
        nodes.erase(nodes.begin());
        for (string n : nodes){
            if (!G.nodeExist(n)){
                G.addNode(n);
            }
            G.addEdge(G.getNode(n), G.getNode(head));
        }
    }
}