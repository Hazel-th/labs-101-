#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    const int i0 = 7, j0 = -4, l0 = -10;
    bool f = false;
    int r = 10;
    int i01 = -10, j01 = -10, i02 = -20, j02 = -20;
    
    int i = i0;
    int j = j0;
    int l = l0;
    for (int k = 0; k <= 50; ++k) {
        int ik = i;
        int jk = j;
        int lk = l;
        
        i = max((47 * ik) % 25, min((47 * jk) % 30, (47 * lk) % 30)) - k % 15;
        i = max((47 * ik) % 25, min((47 * jk) % 30, (47 * lk) % 30)) - k % 15;
        j = min(max((47 * ik) % 25, (47 * jk) % 25), 47 * lk % 30) + k % 5;
        l = 47 * ik * jk * lk % 25 + k % 5;

        if (((ik - i01) * (ik - i01) + (jk - j01) * (jk - j01)) <= r * r && ((ik - i02) * (ik - i02) + (jk - j02) * (jk - j02)) <= r * r) {
            cout << "point is in rang" << '\n';
            cout << "k: " << k << '\n';
            cout << "coordinates: " << ik << ' ' << jk << '\n';
            f = true;
        }
    }
    if (f == false){
        cout << "point is not in range";
    }
}
