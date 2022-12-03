#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    int c;
    while (1){
        c = getchar();
        if (c == ' ' || c == '\n' || c == EOF){
            cout << sum << ' ';
            sum = 0;
        } else {
            sum += c%2147483647;
        }

        if (c == '\n' || c == EOF){
            break;
        }
               
    }
    
}