#include <iostream>
using namespace std;

int search(int arr[], int len, int key) {
    for(int i = 0; i < len; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

void insert(int arr[], int& len, int pos, int key) {
    for(int i = len; i > pos; i--){
        arr[i] = arr[i-1];
    }

    arr[pos] = key;
    len += 1;
}

int remove(int arr[], int len, int key) {
    int pos = search(arr, len, key);

    if(pos == -1) {
        return -1;
    }

    for(int i = pos; i < len; i++) {
        arr[i] = arr[i+1];
    }

    return pos;
}

int main() {
    int myArray[10] = {1, 2, 3, 4, 5};
    int arrayLength = 5;

    insert(myArray, arrayLength, 2, 100);

    for(auto item : myArray) {
        cout << item << " ";
    }
    cout << endl;
    cout << search(myArray, arrayLength, 100) << endl;
    cout << remove(myArray, arrayLength, 4) << endl;
    for(auto item : myArray) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
