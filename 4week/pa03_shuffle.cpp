#include <iostream>

#define MAX_SIZE 5000

using namespace std;

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
  
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
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
    
    for(i=0; i < listSize-1; i++){
        sortedList[i] = list1[i];
        cout << sortedList[i] << endl;
    }

    quickSort(sortedList, 0, listSize-2);

    int *shuffledList = new int[listSize-1];
    
    shuffledList = shuffleDeck(sortedList, listSize-1);
    for(i=0; i < listSize-1; i++){
        cout << shuffledList[i] << " ";
    }
    
    delete[] sortedList;
    delete[] shuffledList;

    return 0;
}