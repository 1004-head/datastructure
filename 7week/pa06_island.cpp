#include <iostream>
#include <queue>
#define MAX 801

using namespace std;

int N, M, sum=0;                       // 미로 크기
int map[MAX][MAX];             // 미로 표현용 2차원 배열
int visited[MAX][MAX];          // 방문 기록용 2차원 배열
int dist[MAX][MAX];             // 이동칸 기록용 2차원 배열

int x_dir[4] = {-1, 1, 0, 0};   // 상화좌우 x축 방향
int y_dir[4] = {0, 0, -1, 1};   // 상화좌우 y축 방향

queue<pair<int,int> > q;        // 탐색 좌표 저장용 queue

// 미로 경로 탐색
void bfs(int start_x, int start_y){         

    visited[start_y][start_x] = 1;          // 입력 받은 시작 좌표를 방문
    q.push(make_pair(start_x,start_y));     // queue 에 삽입
    dist[start_y][start_x]++;               // 시작 좌표까지 이동한 칸을 1로 지정

    // 모든 좌표를 탐색할 때까지 반복
    while (!q.empty()){

        // queue 의 front 좌표를, 현재 좌표로 지정
        int x = q.front().first;
        int y = q.front().second;

        // qeueu 의 front 좌표 제거
        q.pop();

        // 현재 좌표와 상하좌우로 인접한 좌표 확인
        for (int i=0; i<4; ++i){

            // 현재 좌표와 상하좌우로 인접한 좌표
            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            // 인접한 좌표가, 미로 내에 존재하는지, 방문한 적이 없는지, 이동이 가능한지 확인
            if ( (0 <= x_new && x_new < M) && (0 <= y_new && y_new < N) 
            && !visited[y_new][x_new] && map[y_new][x_new] == 0 ){

                visited[y_new][x_new] = 1;              // 인접 좌표는 방문한 것으로 저장
                q.push(make_pair(x_new, y_new));        // 인접 좌표를 queue 에 삽입
                dist[y_new][x_new] = dist[y][x] + 1;    // 인접 좌표까지 이동한 거리 저장
            }
        }
        sum++;
    }
}

int main(){

    cin >> M >> N;                      

    vector<string> arr;
    string str;
    do
    {
        cin >> str;
        arr.push_back(str);
        /* code */
    } while (str != "-1");

    int *l = new int[M*N];
    int k = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == "-1") break;
        for(int j=0; j<arr[i].length(); j++){
            l[k] = arr[i][j]-0x30;
            k++;
        }
    }

    k=0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j< M; j++){
            map[i][j] = l[k];
            k++;
        }

    }

    bfs(0, 0);                          // 미로 탐색 시작

    cout << M*N-sum << "\n";             // 도착 좌표까지의 거리 출력
}