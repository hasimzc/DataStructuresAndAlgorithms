#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int vertex_count= 0;
    int edge_count=0;
    cin >> vertex_count >> edge_count;
    vector<pair<int,double>> adjList[100001]; // ilki gidilen vertex ikinci weight
    bool visited[100001];
    for(int i =0;i<edge_count;i++){
        int startVertex;
        int endVertex;
        double weight;
        cin >> startVertex >> endVertex >> weight;
        adjList[startVertex].emplace_back(endVertex,weight);
        adjList[endVertex].emplace_back(startVertex,weight);// adjaceny list tutuyorum
    }
    priority_queue<pair<int,double>> priorityQueue; // bütün yolları priority queue ya ekliyorum.
    for (pair<int,double> p:adjList[1]) {
        int endVertex = p.first;
        double weight = p.second;
        priorityQueue.push({endVertex,weight*-1}); // min pq olduğu için weightlerı -1 ile çarparak yolluyoruz böylece aslında max pq gibi çalışıyor.
    }
    visited[1] = true; // ilk vertex den başlayacağımız için şimdiden visited olarak işaretliyorum.
    double sum = 0;
    while (priorityQueue.empty()){
        pair<int,double> minEdge = priorityQueue.top();
        int endVertex = minEdge.first;
        double weight = minEdge.second*-1; // pq ya weight ları -1 le çarparak attığımız için tekrar alırken asıl değeri elde etmek için tekrar -1 ile çarpıyoruz
        priorityQueue.pop(); // minimum ağırlıklı yolun bilgilerini aldık artık onu pq dan atabiliriz.
        if (visited[endVertex]){
            continue; // eğer gideceğimiz vertex'e daha önceden gittiysek tekrar gitmeye gerek kalmıyor.
        }
        sum+=weight; // eğer gideceğimiz vertex'e daha önce gitmediysek şimdi gitmemiz gerekecek bu yüzden ağırlığımızı toplama ekliyorum.
        visited[endVertex] = true; // gittiğimiz vertex'i visited olarak işaretliyorum.
        for (pair<int,double> p: adjList[endVertex]) {
            if (!visited[p.first]){
                priorityQueue.push({p.first,p.second*-1}); // şu an bulunduğumuz vertexten daha önce ziyaret edilmemiş vertex'lere olan yolları pq ma ekliyorum.
            }
        }

    }
    cout << sum << endl;
    return 0;
}
