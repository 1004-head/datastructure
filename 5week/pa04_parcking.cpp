#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int k, n;
    cin >> k >> n;

    vector<int> park;
    vector<int>::iterator it;
    vector< vector<int>::iterator > its;
    vector<int> nums;
    int num = 0;
    for(int i = 0; i < n; i++){
        int car;
        cin >> car;
        if(car > 0){
            sort(its.begin(), its.end());
            if(its.size() == 0){
                park.push_back(car);
            }else{
                it = its.front();
                its.erase(its.begin());
                nums.erase(remove(nums.begin(), nums.end(), it-park.begin()), nums.end());
                park.insert(it, car);
            }
        }else{
            car *= -1;
            it = find(park.begin(),park.end(),car);
            if(it != park.end()){
                its.push_back(it);
                nums.push_back(it-park.begin());
                park.erase(it);
            }
        }
    }

    int size = park.size() + nums.size();
    int idx = 0;
    for(int i = 0; i<size; i++){
        if(find(nums.begin(), nums.end(), i) == nums.end()){
            cout << i+1 << " " << park[idx] << "\n";
            idx++;
        }
    }
    return 0;
}