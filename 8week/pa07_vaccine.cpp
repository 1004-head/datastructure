#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp1(const pair<int, pair<int, char> > &a, const pair<int, pair<int, char> > &b) {
    if(&a.second.second > &b.second.second) return true;
    else return false;
}

bool comp2(const pair<int, pair<int, char> > &a, const pair<int, pair<int, char> > &b) {
    if(&a.second.second > &b.second.second) return false;
    else return true;
}


int main(){
    int N;
    cin >> N;

    vector< int > v1;
    vector< int > v2M;
    vector< int > v2F;
    vector< int > v3M;
    vector< int > v3F;
    
    for(int i=0; i<N; i++){
        int num, age;
        char sex;
        cin >> num >> age >> sex;

        if(age <= 15) v1.push_back(num);
        else if(16 <= age && age <= 60){
            if(sex == 'M') v2M.push_back(num);
            else v2F.push_back(num);
        } 
        else {
            if(sex == 'M') v3M.push_back(num);
            else v3F.push_back(num);
        }
    }

    for(int i = 0; i < v3M.size(); i++){
        cout << v3M[i] << "\n";
    }
    for(int i = 0; i < v3F.size(); i++){
        cout << v3F[i] << "\n";
    }
    for(int i = 0; i < v1.size(); i++){
        cout << v1[i] << "\n";
    }
    for(int i = 0; i < v2F.size(); i++){
        cout << v2F[i] << "\n";
    }
    for(int i = 0; i < v2M.size(); i++){
        cout << v2M[i] << "\n";
    }

    return 0;
}