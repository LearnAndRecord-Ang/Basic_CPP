#ifndef BINSEARCH_H
#define BINSEARCH_H

template <class T>
int binSearch(const T a[], int n, const T &key) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (key == a[mid]) {
            return mid;
        }
        else if (key < a[mid]) {
            high = mid -1;
        }
        else if (key > a[mid]) {
            low = mid + 1;
        }
    }
    return -1;
}
#endif