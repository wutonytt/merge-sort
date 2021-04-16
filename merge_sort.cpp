#include <iostream>
#include <vector>

using namespace std;

const int Max = 1000;

void Merge(vector<int> &array, int front, int mid, int end) {
    vector<int> leftSub(array.begin()+front, array.begin()+mid+1);
    vector<int> rightSub(array.begin()+mid+1, array.begin()+end+1);

    leftSub.push_back(Max);
    rightSub.push_back(Max);

    int leftIdx = 0, rightIdx = 0;
    
    for (int i = front; i <= end; i++) {
        if (leftSub[leftIdx] <= rightSub[rightIdx]) {
            array[i] = leftSub[leftIdx];
            leftIdx++;
        }
        else {
            array[i] = rightSub[rightIdx];
            rightIdx++;
        }
    }
}

void MergeSort(vector<int> &array, int front, int end) {
    if (front < end) {
        int mid = (front + end) / 2;
        MergeSort(array, front, mid);
        MergeSort(array, mid+1, end);
        Merge(array, front, mid, end);
    }
}

int main() {
    int arr[] = {5,3,8,6,2,7,1,4};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(arr[0]));
    MergeSort(array, 0, array.size()-1);

    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
}