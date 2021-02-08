#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
using namespace std;

int main()
{
    const int N = 5;
    vector<int> s(N); //s是容器
    for (int i = 0 ; i < N ; i++)
    {
        cin >> s[i];
    }
    // transform是算法，s.begin(),s.end(),ostream_iterator是迭代器，negate是函数对象
    transform(s.begin(),s.end(),ostream_iterator<int>(cout," "),negate<int>());
    cout<<endl;
    return 0; 
}

