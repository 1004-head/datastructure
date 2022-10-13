#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;

    stack<int> tmp;
    vector<int> train; //front가 큰 값
    for(int i = 0; i < n; i++){
        int weight;
        cin >> weight;

        cout << "=============train start===============" << endl;
        for(int i : train){
            cout << i << " ";
        }
        cout << endl;
        cout << "==============train end==============" << endl;

        if(train.size() == 0 && tmp.size() == 0){
            if(weight != 1 || weight != n){
                train.push_back(weight);
            }else{
                tmp.push(weight);
            }
        }else if(train.size() == 0 && tmp.size() != 0){
            if(weight != 1 || weight != n){
                train.push_back(weight);
            }else{
                train.push_back(tmp.top());
                tmp.pop();
                tmp.push(weight);
            }
        }else{
            if(tmp.size() == 0){
                if(train.back() - weight == 1){
                    train.push_back(weight);
                }else if(weight - train.front() == 1){
                    train.insert(train.begin(), weight);
                }else{
                    tmp.push(weight);
                }
            }else{
                int cmp = tmp.top();
                if(cmp > train.front() && weight > train.front()){
                    if(cmp < weight){
                        train.push_back(weight);
                    }else{
                        train.push_back(cmp);
                        tmp.pop();
                        tmp.push(weight);
                    }
                }else if(cmp > train.front() && weight < train.front()){
                    if(cmp - train.front() < train.back() - weight){
                        train.insert(train.begin(), cmp);
                        tmp.pop();
                        tmp.push(weight);
                    }else{
                        train.push_back(weight);
                    }
                }else if(cmp < train.front() < 0 && weight > train.front()){
                    if(cmp - train.back() < train.front() - weight){
                        train.push_back(cmp);
                        tmp.pop();
                        tmp.push(weight);
                    }else{
                        train.insert(train.begin(), weight);
                    }
                }else{
                    if(cmp > weight){
                        train.push_back(cmp);
                        tmp.pop();
                        tmp.push(weight);
                    }else{
                        train.push_back(weight);
                    }
                }
            }
        }
    }

    for(int i : train){
        cout << i << " ";
    }
    
    //cout << train.size() << endl;

    return 0;
    
}