#ifndef CLACULATOR_H
#define CLACULATOR_H
#include "Stack.h"

class Calculator {
    private:
      Stack<double> s; // 操作数栈
      void enter (double num); //将操作数压入栈
      // 连续将两个操作数弹出栈，放在opnd1，opnd2
      bool getTwoOperands(double &opnd1, double &opnd2);
      void compute(char op); //执行由操作符op指定的运算
    public:
      void run();
      void clear();
};
#endif