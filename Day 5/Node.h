#ifndef NODE_H
#define NODE_H

template <class T>
class Node{
    private:
        Node<T> *next; //（对象）下一个结点指针
        T data; //数据域
    public:
        Node(const T &item, Node<T> *next = nullptr); //构造函数
        Node();
        void insertAfter(Node<T> *p); //当前结点后插入结点p
        Node<T> *deleteAfter(); //删除当前结点的后继结点，并返回其地址函数
        const Node<T> *&nextNode() const; //获取后继结点地址
        Node<T> *&nextNode(); //获取后继结点地址
        T &getData();
        // friend LinkedList<T>; //设为友元，则可以直接访问私有函数
};

//构造函数，初始化数据和指针
template <class T>
Node<T>::Node(const T &item, Node<T> *next):data(item), next(next){}

template <class T>
Node<T>::Node():data(0),next(nullptr){}

//返回后继结点指针
template <class T>
Node<T> *&Node<T>::nextNode(){ //返回next指针的引用，作为左值
    return next;
}

//返回后继结点常指针
template <class T>
const Node<T> *&Node<T>::nextNode() const{
    return next;
}

//在当前结点插入一个结点p
template <class T>
void Node<T>::insertAfter(Node<T> *p){
    //注意两个顺序不要弄错，一定要先把后面的接上，再连接前面的
    //p结点指针指向当前结点的后继结点
    p->next = next;
    //当前结点的指针指向p
    next = p;
}

//删除当前结点的后继结点，并返回其地址，不在此函数释放被删除的结点的空间
template <class T>
Node<T> *Node<T>::deleteAfter(){
    Node<T> *tempPtr = next; //将要删除的结点地址储存在tempptr中
    if (next == 0){ //若当前结点没有后继结点，则返回空指针
        return 0;
    }
    next = tempPtr->next; //使当前结点的指针指向tempptr的后继结点
    return tempPtr; //返回被删除的结点地址
}

template <class T>
T& Node<T>::getData() {
	return data;
}

#endif