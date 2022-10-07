#include <iostream>

#define MAX_SIZE 5000

using namespace std;

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int* shuffleDeck(int* deck, int size) {
    int deck1[size/2], deck2[size-size/2], i;
    int* shuffledDeck = new int[size];

    if(size%2 == 0){
        for(i = 0; i<size/2; i++){
            shuffledDeck[2*i] = deck1[i];
            shuffledDeck[2*i+1] = deck2[i];
        }
    }else{
        for(i = 0; i<size/2; i++){
            shuffledDeck[2*i] = deck1[i];
            shuffledDeck[2*i+1] = deck2[i];
        }
        shuffledDeck[2*i] = deck2[i];
    }

    return shuffledDeck;
}

int main(){
    int list1[MAX_SIZE], list2[MAX_SIZE], i=0, n, listSize=0;

    do{
        cin >> n;
        list1[i] = n;
        i++;
    }while(n != -9);
    listSize = i;
    n=0;
    i=0;
    /* do{
        cin >> n;
        list2[i] = n;
        i++;
    }while(n != -9); */

    int *sortedList = new int[listSize];

    quickSort(sortedList, 0, listSize-2);

    for(int i = 0; i<listSize-1; i++){
        cout << sortedList[i] << " ";
    }

    int *shuffledList = new int[listSize-1];
    
    shuffledList = shuffleDeck(sortedList, listSize-1);
    for(i=0; i < listSize-1; i++){
        cout << shuffledList[i] << " ";
    }
    
    delete[] sortedList;
    delete[] shuffledList;

    return 0;
}