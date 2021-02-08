#ifndef STACK_H
#define STACK_H
#include <cassert>

template <class T, int SIZE = 50>
class Stack {
    private:
      T list[SIZE];
      int top;
    public:
      Stack(); //构造函数
      void push(const T &item); //压入栈
      T pop(); //弹出栈
      void clear(); //清空栈
      const T &peek() const; //读取栈顶元素
      bool isEmpty() const;
      bool isFull() const;
};

template <class T, int SIZE>
Stack<T, SIZE>::Stack():top(-1) {}

template <class T, int SIZE>
void Stack<T, SIZE>::push(const T &item) {
    assert(!isFull());
    list[++top] = item;
}

template <class T, int SIZE>
T Stack<T,SIZE>::pop() {
    assert(!isEmpty());
    return list[top--];
}

template <class T, int SIZE>
void Stack<T, SIZE>::clear() {
    top = -1;
}

template <class T, int SIZE>
const T &Stack<T, SIZE>::peek() const {
    assert(!isEmpty());
    return list[top];
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const {
    retrun top == -1
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull() const {
    return top == SIZE - 1;
}

#endif