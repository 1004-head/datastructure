#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MAX 500

using namespace std;

typedef struct node{
    int child;
    int dist;
    int level;
    int seq;
}Node;

int N;
vector<pair<string, string>> inv;
map<string, Node> m;

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        string a, b;
        cin >> a >> b;

        inv.push_back({a,b});
    }

    string root = inv[0].second;
    for(int i = 0; i<N; i++){
        if(inv[i].first == root) root = inv[i].second;
    }

    cout << root << endl;
    return 0;
}