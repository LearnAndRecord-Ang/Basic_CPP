#include <iostream>
#include<string>

using namespace std;

class ExamInfo
{
    private:
        string name;
        // enum Mode 枚举表达方式一
        // {
        //     GRADE,
        //     PASS,
        //     PERCENTAGE
        // };
        // Mode mode;
        enum //枚举表达方式2
        {
            GRADE,
            PASS,
            PERCENTAGE
        }mode;
        // 此处为无名联合体，可以使用有名的，之后声明
        union
        {
            char grade;
            bool pass;
            int percentage;
        };
    public :
        ExamInfo(string name, char grade):name(name),mode(GRADE),grade(grade){}
        ExamInfo(string name, bool pass):name(name),mode(PASS),pass(pass){}
        ExamInfo(string name, int percentage):name(name),mode(PERCENTAGE),percentage(percentage){}
        void show();
};

void ExamInfo::show()
{
    cout<<name<<" ";
    switch (mode)
    {
    case /* constant-expression */GRADE:
        /* code */cout<<grade;
        break;
    case PASS:
        cout<<pass;
        break;
    case PERCENTAGE:
        cout<<percentage;
        break;
    }
    cout<<endl;
}

int main()
{
    ExamInfo course("C++",100);
    course.show();
    return 0;
}