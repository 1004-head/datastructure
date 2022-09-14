#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> getSkyline(vector<vector<int>>& buildings){
    
    /*
        [start, -height, validUntil]
        height > 0: start edge
        height == 0: end edge
    */

    vector<vector<int>> edges;
    for(int i = 0; i < buildings.size(); i++){
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][0]);
        edges[x].push_back(-buildings[i][2]);
        edges[x].push_back(buildings[i][1]);
    }

    for(int i = 0; i < buildings.size(); i++){
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(buildings[i][1]);
        edges[x].push_back(0);
        edges[x].push_back(1e9);
    }

    sort(edges.begin(), edges.end());

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> prevHighest;

    prevHighest.push({0, 1e9});

    vector<vector<int>> skyline;

    for(int i = 0; i < edges.size(); i++){
        
        int position = edges[i][0];
        int curHeight = -1*edges[i][1];
        int validUntil = edges[i][2];

        while(prevHighest.top().second <= position){
            /*
                The equal term guarantees that, for end edges, popping 
                from height to low still works.
            */
            prevHighest.pop();
        }
        
        if(curHeight > 0){
            // Start edge.
            prevHighest.push({-curHeight, validUntil});
        }
        
        // prevHighest is now the current highest.

        if(skyline.size() == 0){
            skyline.push_back(vector<int>());
            skyline[0].push_back(position);
            skyline[0].push_back(-prevHighest.top().first);
        }
        else if(skyline.back()[1] != -prevHighest.top().first){
            int x = skyline.size();
            skyline.push_back(vector<int>());
            skyline[x].push_back(position);
            skyline[x].push_back(-prevHighest.top().first);   
        }
    }

    return skyline;
}

int main(){

    int nBuilding=0, nStar=0;
    vector<vector<int>> bPositions;
    vector<int> sPositions;

    for(int i=0; i<nBuilding; i++){
        int xPos=0, yPos=0, hPos=0;
        cin >> xPos >> yPos >> hPos;
        vector<int> pos;
        pos.push_back(xPos);
        pos.push_back(yPos);
        pos.push_back(hPos);
        bPositions.push_back(pos);
    }

    for(int i=0; i<nStar; i++){
        int xPos=0, yPos=0;
        cin >> xPos >> yPos;
        sPositions.push_back(xPos);
        sPositions.push_back(yPos);
    }

    vector<vector<int>> skyline = getSkyline(bPositions);

    return 0;
}