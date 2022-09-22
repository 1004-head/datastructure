#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int inNum = 0;
    vector<int> leftBlocks, rightBlocks;

//왼쪽부터 보는 블록
    do{
        cin >> inNum;
        leftBlocks.push_back(inNum);
    }while(inNum != -9);
//오른쪽부터 보는 블록
    inNum = 0;
    do{
        cin >> inNum;
        rightBlocks.push_back(inNum);
    }while(inNum != -9);

//전체 보도블록 사이즈 계산
    int colSize = leftBlocks.size()-1, rowSize = 0;

    int index = 0;
    for(int block : rightBlocks){
        if(block == -1){
            rowSize = leftBlocks[index];
            break;
        }
        index++;
    }

    if(rowSize == 0){
        rowSize += *max_element(leftBlocks.begin(), leftBlocks.end())+1;
    }

    char blocks[colSize][rowSize] = {0,};
// 왼쪽부터 블록 깔기
    int x = 0;
    for(int blockN : leftBlocks){
        for(int i=0; i<blockN; i++){
            blocks[x][i] = 1;
        }
        x++;
    }

// 오른쪽부터 블록 깔기 -- 여기서 문제 발생 도대체 왜 블록이 안 깔림????
    x = 0;
    for(int blockM : rightBlocks){
        if(blockM == -1) continue;
        else{
            for(int i=blockM; i>0; i--){
                blocks[x][rowSize-blockM] = 1;
            }
        }
        x++;
    }

//보도블록 출력
    for(int i = 0; i<colSize; i++){
        for(int j = 0; j<rowSize; j++){
            printf("%d ", blocks[i][j]);
        }
        printf("\n");
    }
    return 0;   
}