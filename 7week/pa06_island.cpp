#include <iostream>
#include <queue>
#include <vector>

#define MAX 801

using namespace std;

int n, m, sum=0;                      
int map[MAX][MAX];             
int visited[MAX][MAX];          
int dist[MAX][MAX];             

int xDir[4] = {-1, 1, 0, 0};   
int yDir[4] = {0, 0, -1, 1};   

queue<pair<int,int> > q;       


void bfs(int startX, int startY){         

    visited[startY][startX] = 1;          
    q.push(make_pair(startX,startY));    
    dist[startY][startX]++;              

    while (!q.empty()){

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i=0; i<4; ++i){

            int xNew = x + xDir[i];
            int yNew = y + yDir[i];

            if ( (0 <= xNew && xNew < m) && (0 <= yNew && yNew < n) 
            && !visited[yNew][xNew] && map[yNew][xNew] == 0 ){

                visited[yNew][xNew] = 1;             
                q.push(make_pair(xNew, yNew));        
                dist[yNew][xNew] = dist[y][x] + 1;    
            }
        }
        sum++;
    }
}

int main(){

    cin >> m >> n;                      

    vector<string> arr;
    string str;
    do
    {
        cin >> str;
        arr.push_back(str);
        /* code */
    } while (str != "-1");

    int *l = new int[m*n];
    int k = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == "-1") break;
        for(int j=0; j<arr[i].length(); j++){
            l[k] = arr[i][j]-0x30;
            k++;
        }
    }

    k=0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            map[i][j] = l[k];
            k++;
        }

    }

    bfs(0, 0);                          

    cout << m*n-sum << "\n";             
}