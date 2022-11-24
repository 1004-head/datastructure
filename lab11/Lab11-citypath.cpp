#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 99999999999

using namespace std;

int N;
map<int, vector<int>> m;

vector<int> dijkstra(int start, int V, vector<pair<int, int> > adj[]){
    vector<int> dist(V, INF);
    priority_queue<pair<int, int> > pq;

    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(int i = 0; i < adj[cur].size(); i++){
            int next = adj[cur][i].first;
            int nCost = cost + adj[cur][i].second;

            if(nCost , dist[next]){
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
    return dist;
}

int main(){
    cin >> N;

    for(int i = 0; i < N; i++){
        int k, v=-1;
        cin >> k;

        while(v != 0){
            cin >> v;
            m[k].push_back(v);
        }
    }

    vector<pair<int, int> > e;
    for(map<int, vector<int> >::iterator it = m.begin(); it != m.end(); it++){
        cout << "===========================" << endl;
        cout << it->first << endl;
        for(vector<int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << *it2 << " ";
            if(*it2 != 0){
                if(it->first < *it2) e.push_back({it->first, *it2});
                else e.push_back({*it2, it->first});
            }
        }
        cout << endl;
    }

    sort(e.begin(), e.end());
    e.erase(unique(e.begin(), e.end()), e.end());
    int E = e.size();
    cout << "===========================" << endl;
    for(int i = 0; i < E; i++){
        cout << e[i].first << " " << e[i].second << endl;
    }
    cout << "===========================" << endl;
    cout << e[5].first << endl;
/*
    vector<pair<int, int> > adj[N];
    for(int i = 0; i<E; i++){
        int from, to, cost;
        from = e[i].first;
        to = e[i].second;
        cost = m[e[i].first].size()-2;
        cout << from << " " << to << " " << cost << endl;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }

    vector<int> dist = dijkstra(1, N, adj);
    cout << "\n===다익스트라 결과===\n";
    for(int i=0; i<N; i++){
        cout << "0번 정점에서 " << i << "번 정점까지 최단거리 : " << dist[i] << endl;
    }
*/
    return 0;
}