#include <iostream>
using std::cout;
using std::endl;

class Base1{
    public:
    virtual ~Base1();
};

Base1:: ~Base1(){
    cout<< "Base1 destructor called"<<endl;
}

class Derived: public Base1{
    public:
    Derived();
    virtual ~Derived();
    private:
    int* p;
};

// Derived::Derived(){
//     p = new int(0);
// }
Derived::Derived(): p(new int(0)){} //和上方功能相同

Derived::~Derived(){
    cout<< "Derived destructor"<<endl;
    delete p;
}

void fun(Base1 *p){
    delete p;
}

int main(){
    Base1 *b = new Derived();
    fun(b);
    return 0;
}