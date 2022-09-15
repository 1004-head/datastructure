#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

vector< vector<int> > getSkyline(vector< vector<int> >& buildings){

    vector< vector<int> > edges;
    for(auto building : buildings){
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(building[0]);
        edges[x].push_back(-building[2]);
        edges[x].push_back(building[1]);
    }

    for(auto building : buildings){
        int x = edges.size();
        edges.push_back(vector<int>());
        edges[x].push_back(building[1]);
        edges[x].push_back(0);
        edges[x].push_back(1024);
    }

    sort(edges.begin(), edges.end());

    priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > preHigher;

    preHigher.push(make_pair(0, 1024));

    vector< vector<int> > skyline;

    for(auto edge : edges){
        
        int pos = edge[0];
        int curHeight = -1*edge[1];
        int isValid = edge[2];

        while(preHigher.top().second <= pos){
            preHigher.pop();
        }
        
        if(curHeight > 0){
            preHigher.push(make_pair(-curHeight, isValid));
        }
        
        if(skyline.size() == 0){
            skyline.push_back(vector<int>());
            skyline[0].push_back(pos);
            skyline[0].push_back(-preHigher.top().first);
        }
        else if(skyline.back()[1] != -preHigher.top().first){
            int x = skyline.size();
            skyline.push_back(vector<int>());
            skyline[x].push_back(pos);
            skyline[x].push_back(-preHigher.top().first);   
        }
    }

    return skyline;
}

int main(){

    int nBuilding=0, nStar=0;
    vector< vector<int> > buildings, stars;

    cin >> nBuilding;

    for(int i=0; i<nBuilding; i++){
        int xPos=0, yPos=0, hPos=0;
        cin >> xPos >> hPos >> yPos;
        vector<int> pos;
        pos.push_back(xPos);
        pos.push_back(xPos+yPos);
        pos.push_back(hPos);
        
        buildings.push_back(pos);
    }

    cin >> nStar;

    for(int i=0; i<nStar; i++){
        int xPos=0, yPos=0;
        cin >> xPos >> yPos;
        vector<int> star;
        star.push_back(xPos);
        star.push_back(yPos);

        stars.push_back(star);
    }

    vector< vector<int> > skyline = getSkyline(buildings);

    for(auto star: stars){
        int starX = star[0], starY=star[1], i;
        int cmpX1 = 0, cmpY1 = 0, cmpX2 = 0, cmpY2 = 0;

        for(i=0; skyline[i][0] < starX && i < skyline.size(); i++){
            cmpX1 = skyline[i][0];
            cmpY1 = skyline[i][1];
        }
        cmpX2 = skyline[i][0];
        cmpY2 = skyline[i][1];

        if(starX == cmpX2 && cmpY1 < cmpY2){
            if(starY > cmpY2){ cout << "over" << endl;}
            else if(starY <= cmpY2 && starY >= cmpY1){ cout << "on" << endl;}
            else{ cout << "under" << endl;}
        }else if(starX == cmpX2 && cmpY1 > cmpY2){
            if(starY > cmpY1){ cout << "over" << endl;}
            else if(starY <= cmpY1 && starY >= cmpY2){ cout << "on" << endl;}
            else{ cout << "under" << endl;}
        }else{
            if(starY > cmpY1){ cout << "over" << endl;}
            else if(starY < cmpY1){ cout << "under" << endl;}
            else{ cout << "on" << endl;}
        }
    }

    return 0;
}