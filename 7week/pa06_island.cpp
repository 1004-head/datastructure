#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int m, n;
    cin >> m >> n;


    int **map = new int*[m];
    for(int i = 0; i < m; i++){
        map[i] = new int[n];
    }

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
    for(string s : arr){
        if(s == "-1") break;
        for(char c : s){
            l[k] = c-0x30;
            k++;
        }
    }

    k=0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j< n; j++){
            map[i][j] = l[k];
            k++;
        }
    }

    vector<pair<int, int>> idx;
    int start = -1, end = -1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j< n; j++){
            cout << map[i][j];
            if(map[i][j] == 1){
                idx.push_back({i,j});
            }
        }
        cout << endl;
    }

    int sum = 0;
    for(pair<int, int> p : idx){
        

    }

    return 0;    
}