#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
using namespace std;

template <class T, class InputIterator, class OutputIterator>
void mySort(InputIterator first, InputIterator last, OutputIterator result) {
    vector<T> s;
    for (; first != last; ++first) {
        s.push_back(*first);
    }
    sort(s.begin(), s.end());
    copy(s.begin(), s.end(), result);
}

int main() {
    double a[5] = {2.2,2.1,4.2,4.6,5};
    mySort<double>(a, a + 5, ostream_iterator<double>(cout," "));
    cout<<endl;
}