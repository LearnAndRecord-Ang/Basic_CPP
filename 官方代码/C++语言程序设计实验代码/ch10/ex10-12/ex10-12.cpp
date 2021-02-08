#include <iostream>
#include <iterator>
#include <cstdio>
#include <ctime>
#include <list>
#include <algorithm>
using namespace std;

int random() {
	return rand()%10;
}

int main() {
	srand((int)time(0));
	list<int> l(20);
	generate(l.begin(), l.end(), random);
	cout << "listµÄÔªËØ£º" << endl;
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	return 0;
}
