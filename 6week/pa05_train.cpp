#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<int> weight;

int line(int index, list<int> li, int B, int add){
    int cnt = 0, tmp;
    if(add != -1){
        if(add < li.front()) li.push_front(add);
        else if(li.back() < add) li.push_back(add);
        else return li.size();
    }

    for(int i=index; i<weight.size(); i++){
        if(li.front() < weight[i] && weight[i] < li.back() &&
            li.front() < B && B < li.back()) return li.size();

        if(weight[i] < B && B < li.front()){
            li.push_front(B);
            B = weight[i];
        } else if(B < weight[i] && weight[i] < li.front()){
            li.push_front(weight[i]);
        } else if(li.back() < B && B < weight[i]){
            li.push_back(B);
            B = weight[i];
        } else if(li.back() < weight[i] && weight[i] < B){
            li.push_back(weight[i]);
        } else {
            tmp = line(i+1, li, weight[i], B);
            cnt = max(tmp, cnt);
            tmp = line(i+1, li, B, weight[i]);
            cnt = max(tmp, cnt);
            return cnt;
        }
    }

    if(li.front() < B && B < li.back()) return li.size();
    else return li.size() + 1;
}

int main(){
    int N; cin >> N;
    int tmp;
    while(N--){
        cin >> tmp;
        weight.push_back(tmp);
    }
    if(weight.size() < 2){
        cout << weight.size();
        return 0;
    }
    list<int> li;
    li.push_back(weight[0]);
    int result = 0;
    result = max(line(2, li, weight[1], -1), result);
    li.clear();
    li.push_back(weight[1]);
    result = max(line(2, li, weight[0], -1), result);

    cout << result;
    return 0;
}