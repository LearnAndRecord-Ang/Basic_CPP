#include <iostream>
#include <cstdlib>

using namespace std;
enum GameStatus{
    WIN,
    LOSE,
    PLAYING
};

int rollDice();

int main()
{
    GameStatus status;
    unsigned seed;
    int sum , points;
    cout<<"seed = ";
    cin >> seed;
    srand(seed);
    sum = rollDice();
    switch(sum)
    {
        case 7:
        case 11:
            status = WIN;
            break;
        case 2:
        case 3:
        case 12:
            status = LOSE;
            break;
        default:
            status = PLAYING;
            points = sum;
            cout<<"points are "<<points;
            break;
    }
    while (status == PLAYING)
    {
        sum = rollDice();
        if (sum == points)
        {
            status = WIN;
        }
        else if (sum == 7)
        {
            status = LOSE;
        }
        if(status == WIN)
        {
            cout<<"WIN";
        }
        else
        {
            /* code */
            cout<<"LOSE";
        }
        
    }
}

int rollDice()
{
    int first = 1 + rand()%6; //rand()%6范围是[0,5]
    int second = 1 + rand()%6;
    int sum = first + second;
    return sum;
}