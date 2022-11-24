#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define MAX 500

using namespace std;

int N;
vector< pair<string, string> > inv;
map<string, vector<string> > m2;
vector<string> mafia;

string findRoot(vector< pair<string, string> > &v){
    string root = v[0].second;
    for(int i = 0; i<N; i++){
        if(inv[i].first == root) root = inv[i].second;
    }
    return root;
}

int childCtr(string k){
    if(m2.find(k) == m2.end()) return 1;
    int n = m2[k].size();

    int j=0;
    for(int i = 0; i < n; i++){
        j = j+childCtr(m2[k][i]);
        cout << j << endl;
    }
    return j;
}

int main(){
    cin >> N;

    for(int i=0; i<N-1; i++){
        string a, b;
        cin >> a >> b;

        inv.push_back(make_pair(a,b));
        if(m2.count(b) == 0){
            vector<string> tmp;
            tmp.push_back(a);
            m2.insert(make_pair(b, tmp));
        }else{
            vector<string> tmp;
            m2.find(b)->second.push_back(a);
        }
    }
    
    for(map<string, vector<string> >::iterator it = m2.begin(); it != m2.end(); it++){
        cout << "===========================" << endl;
        cout << it->first << endl;
        for(vector<string>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++){
            cout << *it2 << " ";
        }
        cout << endl;
    }

    string root = findRoot(inv);
    mafia.push_back(root);
    
    int n = childCtr(root);
    cout << n << endl;

    cout << root << endl;
    return 0;
}