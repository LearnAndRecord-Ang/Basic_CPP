#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

template <class T>
void swapTest(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

// 选择排序，一个个排序比较
template <class T>
void selectionSort(T a[], int n) { //从小到大排序
    for (int i = 0; i < n - 1; i++) {
        int leastIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[leastIndex]) {
                leastIndex = j
            }
        }
        swapTest(a[i], a[leastIndex]);
    }
}

#endif