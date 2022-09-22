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
    for(int i=0; i<rowSize; i++){
        blocks[0][i] = 0;
    }

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
        if(blockM == -1){
            x++;
        }else{
            for(int i=blockM; i>0; i--){
                blocks[x][rowSize-i] = 1;
            }
            x++;
        }
    }

    vector<int> topBlocks, bottomBlocks;
    
    //위에서 블록 세기
    for(int i = 0; i < rowSize; i++){
        int flag = 0;
        for(int j = 0; j < colSize; j++){
            if(blocks[j][i] == 0){
                flag = 1;
                topBlocks.push_back(j+1-1);
                break;
            }
        }
        if(flag == 0){ topBlocks.push_back(colSize); }
    }

    //아래에서 블록 세기
    for(int i = 0; i < rowSize; i++){
        int flag = 0;
        for(int j = colSize-1; j >= 0; j--){
            if(blocks[j][i] == 0){
                flag = 1;
                bottomBlocks.push_back(colSize-j-1);
                break;
            }
        }
        if(flag == 0){ bottomBlocks.push_back(-1); }
    }

    //위아래 블록 출력
    for(int k : topBlocks){
        printf("%d ", k);
    }
    printf("-9\n");
    for(int k : bottomBlocks){
        printf("%d ", k);
    }
    printf("-9\n");

    return 0;   
}