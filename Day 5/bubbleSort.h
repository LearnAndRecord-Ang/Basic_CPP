#ifndef BUBBLESORT_H
#define BUBBLESORT_H

template <class T>
void swapTest(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

template <class T>
void bubbleSort(T a[], int n) {
    int i = n - 1;
    while (i > 0) {
        int lastExchangeIndex = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                swapTest(a[j], a[j+1]);
                lastExchangeIndex = j; 
            }
        }
        i = lastExchangeIndex; // 控制内层比较到哪个位置停止
    }
}

#endif