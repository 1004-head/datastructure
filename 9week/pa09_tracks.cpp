#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct work{
    work(int s, int e):
    start{s}, end{e}{};
    int start;
    int end;
};

vector<work> data;
vector<int> track;

bool comp(work a, work b){
    return a.start < b.start;
}

int main(){
    int N; cin >> N;
    int i, j;
    int tmps, tmpe;
    for(i=0; i<N; i++){
        cin >> tmps >> tmpe;
        data.push_back(work(tmps, tmpe + tmps));
    }
    sort(data.begin(), data.end(), comp);
    
    int it;
    track.push_back(data[0].end);
    for(i=1; i<data.size(); i++){
        it = min_element(track.begin(), track.end()) - track.begin();
        if(track[it] <= data[i].start)
            track[it] = data[i].end;
        else
            track.push_back(data[i].end);
    }
    cout << track.size();
}
