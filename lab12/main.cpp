#include <iostream>

using namespace std;


int main()
{
    int num, sim, sim1;
    bool flag = 1;
    cin >> num;
    if (num < 0){
        num = num * (-1);
    }
    while (num>0)
    {
        sim = num%10;
        if (sim == sim1){
            flag = 0;
            cout << "Neverno";
            break;
        }
        sim1 = sim;
        num = num/10;
        if (num == 0){
            num = -1;
        }
    }

    if (flag){
        cout << "Verno";
    }
}