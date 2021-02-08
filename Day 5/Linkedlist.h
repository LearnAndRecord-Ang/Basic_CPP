#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using std::cout;
using std::endl;

/*
* 在LinkedList的设计中，采用了附加指针front和rear，即链表的结构为front->a1->a2->...->rear
* 只有在析构函数中才删除这两个指针，其余的时间这两个指针都是存在的，其中的数据始终为0，不存储用户数据
*/
template <class T>
class LinkedList{
    private:
        Node<T> *front, *rear; //表头表尾（对象）指针，始终指向表头和表尾结点
        Node<T> *prevPtr, *currPtr; //记录表当前遍历位置的指针，由插入和删除操作更新，curr为当前指针，prev是前驱指针
        int size; //表中的元素个数
        int position; //当前元素在表中的位置序号，由函数reset使用
        
        //生成新的结点，数据域为item，指针域为ptrnext
        Node<T> *newNode(const T &item, Node<T> *ptrNext = nullptr);
        void freeNode(Node<T> *p); //释放结点
        //将链表l复制到当前表（若当前表为空），被复制构造函数，operator=调用，复制算法则统一
        void copy(const LinkedList<T> &L);
    public:
        // void print(); //打印链表类里对数据及其数目
        LinkedList(); //构造函数
        LinkedList(const LinkedList<T> &L); //复制构造函数
        ~LinkedList(); //析构函数
        LinkedList<T> & operator = (const LinkedList<T> & L); //重载=运算符

        int getSize() const; //返回链表中元素个数
        bool isEmpty() const; //链表是否为空

        void reset(int pos = 0); //初始化游标的位置，默认起始位置为0
        void next(); //使游标移动到下一个结点
        bool endOfList() const; //游标是否返回到了链表尾
        int currentPosition() const; //返回游标当前位置

        void insertFront(const T &item); //在表头插入结点
        void insertRear(const T &item); //在表尾插入结点
        void insertAt(const T &item); //在当前结点前插入结点
        void insertAfter(const T &item); //在当前结点后插入结点

        T deleteFront(); //删除头结点
        void deleteCurrent(); //删除当前结点

        T& data(); //返回对当前结点成员数据对引用
        const T& data() const; //返回对当前结点成员数据对常引用
        //清空链表：释放所有结点的内存空间，被析构函数，operator = 调用
        void clear();
};

//生成新结点
template <class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext) {
    Node<T> *n = new Node<T>(item , ptrNext);
    return n;
}

//释放结点
//判断p结点与currPtr的位置关系，分别是p在curr前，p = currPtr，p在curr后
template <class T>
void LinkedList<T>::freeNode(Node<T> *p) {
    Node<T> *temp = front;
    while (temp->nextNode() != p) {
        temp = temp->nextNode();
        if (temp == currPtr) { //当p在curr前和p=curr时候均不会执行，只有在p在curr后才会为true
            position++; //为了保证position数值不变，函数体后有position--，与此++抵消
        }
    }
    temp->nextNode() = p->nextNode();
    if (currPtr == p) {
        currPtr = currPtr->nextNode();
    }
    if (prevPtr == p) {
        prevPtr = prevPtr->nextNode();
        currPtr = currPtr->nextNode();
    }
    delete p;
    p = nullptr;
    size--;
    position--;
}

//将链表L复制到当前表（假设当前表为空），被复制构造函数和operator=调用
template <class T>
void LinkedList<T>::copy(const LinkedList<T> &L) {
    Node<T> *temp = L.front, *ptr = front;
    while (temp != L.rear) {
        /* code */
        ptr->nextNode() = new Node<T>(temp->getData(),nullptr);
        ptr = ptr->nextNode();
        temp = temp->nextNode();
    }
    ptr->nextNode() = rear;
    size = L.getSize();
    position = L.currentPosition();
}

//构造函数
template <class T>
LinkedList<T>::LinkedList() {
    front = new Node<T>();
    rear = new Node<T>();
    front->nextNode() = rear;
    currPtr = rear;
    prevPtr = front;
    size = 0; //不计算front和rear
    position = 0; //front下一个位置为0
}

//复制构造函数
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &L) {
    clear();
    copy(L);
}

//析构函数
template <class T>
LinkedList<T>::~LinkedList() {
    LinkedList<T>::clear();
    delete front;
    delete rear;
    front = nullptr;
    rear = nullptr;
}

//重载 = 运算符
template <class T>
LinkedList<T> &LinkedList<T>::operator = (const LinkedList<T> & L) {
    clear();
    copy(L);
}

//返回链表元素个数
template <class T>
int LinkedList<T>::getSize() const {
    return size;
}

//判断链表是否为空
template <class T>
bool LinkedList<T>::isEmpty() const {
    return (size == 0);
}

//初始化游标位置
template <class T>
void LinkedList<T>::reset(int pos) {
    if (pos > size) { //若初始化位置大于链表大小
        cout << "reset越界" <<endl;
        return;
    }
    int i = 0;
    prevPtr = front;
    // cout << "prev next = " << prevPtr->nextNode()->getData() << endl;
    currPtr = front->nextNode();
    // cout << "currPtr = " << currPtr->getData() << endl;
    while (i < pos) {
        if (currPtr == rear) { //若当前结点已经是尾部结点，则链表除了头位结点为空
            cout << "reset越界" << endl;
            return;
        }
        i++;
        currPtr = currPtr->nextNode();
        prevPtr = prevPtr->nextNode();
    }
    position = pos;
}

//移动到下一个结点
template <class T>
void LinkedList<T>::next() {
    if (currPtr == rear) {
        cout << "已到链表尾部" <<endl;
        return;
    }
    currPtr = currPtr->nextNode();
    prevPtr = prevPtr->nextNode();
}

//链表是否返回表尾部
template <class T>
bool LinkedList<T>::endOfList() const {
    return (currPtr == rear);
}

//返回游标当前位置
template <class T>
int LinkedList<T>::currentPosition() const {
    return position;
}

//表头插入结点
template <class T>
void LinkedList<T>::insertFront(const T &item) {
    Node<T> *temp = new Node<T>(item,front->nextNode());
    front->nextNode() = temp;
    size++;
    position++;
}

//表尾插入结点
template <class T>
void LinkedList<T>::insertRear(const T &item) {
    Node<T> *temp = front;
    while (temp->nextNode() != rear) {
        /* code */
        temp = temp->nextNode();
    }
    Node<T> *n = new Node<T>(item,rear);
    temp->nextNode() = n;
    size++;
}

//当前结点前插入结点
template <class T>
void LinkedList<T>::insertAt(const T &item) {
    Node<T> *temp = new Node<T>(item,currPtr);
    prevPtr->nextNode() = temp;
    prevPtr =temp;
    size++;
    position++;
}

//当前结点后插入结点
template <class T>
void LinkedList<T>::insertAfter(const T&item){
    Node<T> *temp = new Node<T>(item,nullptr);
    temp->nextNode() = currPtr->nextNode();
    currPtr->nextNode() = temp;
    size++;
}

//删除头结点，实质是删除front->next
template <class T>
T LinkedList<T>::deleteFront() {
    if (front->nextNode() == rear) {
        cout << "无可删除结点" << endl;
    }
    if (prevPtr == front->nextNode()) {
        prevPtr = prevPtr->nextNode();
        currPtr = currPtr->nextNode();
    }
    Node<T> *temp = front->nextNode();
    T d = temp->getData();
    front->nextNode() = temp->nextNode();
    delete temp;
    temp = nullptr;
    size--;
    if (front->nextNode() != rear) {
        position--;
    }
    return d;
}

// 删除当前结点
template <class T>
void LinkedList<T>::deleteCurrent() {
    Node<T> *temp = currPtr;
    currPtr = currPtr->nextNode();
    // prevPtr->nextNode() = currPtr;
    // delete temp;
    // temp = nullptr;
    freeNode(temp);
    cout<<"prev = " << prevPtr->getData() << " curr = " << currPtr->getData() <<endl;
    size--;
    // cout << size <<endl;
}

template <class T>
T &LinkedList<T>::data() {
    return currPtr->getData();
}

template <class T>
const T &LinkedList<T>::data() const {
    return currPtr->getData();
}

template <class T>
void LinkedList<T>::clear() {
    Node<T> *temp;
    while(front->nextNode() != rear) {
        temp = front->nextNode();
        front->nextNode() = temp->nextNode();
        // cout << "??????"<<endl;
        delete temp;
        temp = nullptr;
    }
    size = 0;
    position = 0;
}

#endif