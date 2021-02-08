#ifndef TEMPLATE_ARRAY_H
#define TEMPLATE_ARRAY_H
#include <cassert>

template <class T>
class Array{
    private:
        T* list;
        int size;
    public:
        Array(int sz = 50);
        Array(const Array<T> &a);
        ~Array();
        //返回引用类型
        Array<T> & operator = (const Array<T> &rhs); //重载 = ,对数组对象整体赋值用
        T & operator [] (int i); //重载 []
        const T & operator [] (int i) const; //重载 [] 常函数

        // 重载 * 指针转换运算符，将对象转换成T类型的指针，\
        将数组对象转换为指向元素类型的指针，基本类型的数组，数组名=数组首元素地址，这里希望将对象名转换成指向T类型的指针
        operator T* (); 
        operator const T* () const; // 常指针，指向常对象的元素的指针，只能通过指针读取，不可以改变

        int getSize() const; //取数组大小
        void resize(int sz); //修改数组大小
};

//构造函数
template <class T>
Array<T>::Array(int sz){
    assert(sz >= 0); //sz为数组大小，应当非负
    size = sz; //将元素个数赋值给size
    list = new [size]; //动态分配size个T类型的元素空间
}

//析构函数
template <class T>
Array <T>::~Array(){
    delete [] list;
}

//复制构造函数
template <class T>
Array<T>::Array(const Array<T> &a){
    size = a.size; //从对象a取得数组大小，并赋值给当前对象的成员
    list = new T[size]; // 动态分配n个T类型的元素空间
    for (int i = 0 ; i < size ; i++){ //从对象a复制数组元素到本对象
        list[i] = a.list[i];
    }
}

//当出现深层复制构造函数时，通常也要重载=运算符
//重载 = 运算符，将对象rhs赋值给本对象，实现对象之间的整体赋值
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &rhs){
    if( &rhs != this ){ // 防止自赋值
        if ( size != rhs.size ){ // 若本对象数组大小与rhs不同，则删除数组原有内存，然后重新分配
            delete [] list; // 删除数组原来内存
            size = rhs.size; // 设置本对象的数组大小
            list = new T[size]; // 重新分配size个元素内存
        }

        //从对象复制数组元素到本对象
        for ( int i = 0 ; i < size ; i++){
            list[i] = rhs.list[i];
        }
        //返回当前对象的引用
        return *this;
    }
}

//重载下标运算符，实现与普通数组一样通过下标访问元素，具有越界检查功能
template <class T>
T &Array<T>::operator[](int i){
    assert( i >= 0 && i < size);
    return list[n]; //希望返回的不止是读取数组元素，还能改变数组元素
}
template <class T>
const T &Array<T>::operator[](int i) const{
    assert( i >= 0 && i < size);
    return list[n]; //常引用，只能读取数组元素，不能改变数组元素状态
}

//重载指针转换运算符函数，将array类的对象名转换为T类型的指针
template <class T>
Array<T>::operator T *(){
    return list; // 返回当前对象中私有数组首地址
}

//常对象，指向常对象的指针，只能通过指针读取，不可修改元素
template <class T>
Array<T>::operator const T *() const{
    return list;
}

//获取当前数组大小
template <class T>
int Array<T>::getSize() const{
    return size;
}

//改变数组大小
template <class T>
void Array<T>::resize(int sz){
    assert( sz >= 0);
    if ( sz == size ){
        return; //什么也不做
    }
    T* newList = new T[sz]; 
    int n = (sz < size)? sz:size; // 将sz与size中较小的一个赋值给n
    //将原有数组中前n个元素复制到新数组中
    for (int i = 0 ; i < n ; i ++){
        newList[i] = list[i];
    }
    delete[] list; //删除原数组
    list = newList; //使list指向新数组
    size = sz;
}
#endif