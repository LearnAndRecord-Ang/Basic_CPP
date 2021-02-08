#include <iostream>
using namespace std;

enum class Side{Right,Left};
enum class Thing{Right, Wrong}; // 不冲突

int main()
{
    Side s = Side::Right;
    Thing t = Thing::Right;
    // cout<<( s == t )<<endl; //编译报错
    return 0;
}