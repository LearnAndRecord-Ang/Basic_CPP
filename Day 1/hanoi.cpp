#include <iostream>
using namespace std;

void hanoi(int m, char src, char med, char dest);
void move(char src, char dest);

int main()
{
    int m = 3;
    hanoi(m,'A','B','C');
    return 0;
}

void hanoi(int m, char src, char med, char dest)
{
    if (m == 1)
    {
        move(src,dest);
    }
    else
    {
        /* code */
        hanoi(m-1,src,dest,med);
        move(src,dest);
        hanoi(m-1, med, src, dest);
    }
    
}

void move(char src, char dest)
{
    cout<<"From "<<src<<" TO "<<dest<<endl;
}