#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Students
{
    /* data */
    int num;
    string name;
    char sex;
    int age;
};

int main()
{
    Students stu = { 2331 , "Lin", 'M', 18};
    return 0;
}

