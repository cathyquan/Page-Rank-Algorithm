#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <map>
#include <vector>
using namespace std;

struct AdjacencyList {
    map<string, vector<string>> inDegUrls;
    map<string, float> outDegNum;
    map<string, float> ranks;
    void initializeRank();
    void powerIterations(int p);
    void pageRank();

//    void printAdjList();
};

void AdjacencyList::initializeRank() {
    int numUrls = inDegUrls.size();
    for (auto member: inDegUrls) {
        ranks[member.first] = (float)1/numUrls; // setting r(0)
    }
}

void AdjacencyList::powerIterations(int p) {
    if (p == 1)
        return;
    else {
        map<string, float> ranksStorage = ranks;
        for (auto member: inDegUrls) {
            float pageRank = 0.0;
            for (auto link: member.second) {
                pageRank += (float)1/outDegNum[link] * ranks[link];
//                cout << "1 / " << outDegNum[link] << " * " << ranks[link] << " = " << pageRank << endl;
            }
            ranksStorage[member.first] = pageRank;
        }
        ranks = ranksStorage;
        powerIterations(p - 1);
    }
}

void AdjacencyList::pageRank() {
    for (auto member: ranks) {
        cout << member.first << " ";
        cout << fixed << showpoint;
        cout << setprecision(2);
        cout << member.second << endl;
    }
}

//void AdjacencyList::printAdjList() {
//    for (auto member: inDegUrls) {
//        cout << member.first << ": ";
//        for (int i = 0; i < member.second.size(); i++) {
//            cout << member.second[i] << " ";
//        }
//        cout << endl;
//    }
//}

int main() {
    AdjacencyList graph;
    int numLines, p;
    string from, to;
    cin >> numLines;
    cin >> p;

    for (int i = 0; i < numLines; i++) {
        string line;
        cin >> from >> to;
        graph.inDegUrls[to].push_back(from);
        graph.outDegNum[from]++;
        if (graph.inDegUrls.find(from) == graph.inDegUrls.end())
            graph.inDegUrls[from] = {};
        if (graph.outDegNum.find(to) == graph.outDegNum.end())
            graph.outDegNum[to] = 0;
    }
    graph.initializeRank();
    graph.powerIterations(p);
    graph.pageRank();

    return 0;
}
