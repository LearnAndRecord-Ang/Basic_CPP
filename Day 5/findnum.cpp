#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
	const int N = sizeof(intArr) / sizeof(int);
	vector<int> a(intArr, intArr + N);
    //find_if算法在stl的原型声明为：
    //template <class InputIterator, class UnaryPredicate>
    //InputIterator find_if(InputIterator first, InputIterator last, UnaryPredicate pred);
    //功能是查找数组[first, last)区间中第一个 pred(x)为真的元素，
    //find_if算法最后是一元位词，则用bind2nd绑定
	vector<int>::iterator p = find_if(a.begin(), a.end(), bind2nd(greater<int>(), 40));
	if (p == a.end())
		cout << "no element greater than 40" << endl;
	else
		cout << "first element greater than 40 is: " << *p << endl;
	return 0;
}
