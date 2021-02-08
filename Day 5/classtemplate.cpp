#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

struct Student
{
    /* data */
    int id;
    float gpa;
};

template <class T>
class Store{ //类模板，实现对任意类型数据对存取
    private:
        T item; //item用于存放任意类型的数据
        bool haveValue;
    public:
        Store();
        T &getElem();
        void putElem(const T &i);
};

template <class T>
Store<T>::Store():haveValue(false){}

template <class T>
T &Store<T>::getElem(){
    if (!haveValue){
        cout << "No item present" <<endl;
        exit(1);
    }
    return item;
}

template <class T>
void Store<T>::putElem(const T &i){
    haveValue = true;
    item = i;
}

int main(){
    // Store<double> d;
    // cout<<d.getElem()<<endl; //d未初始化，执行getelem()时终止
    // return 0;

    Store<Student> s;
    Student p = {1000,91};
    s.putElem(p);
    cout << s.getElem().id <<endl;
}