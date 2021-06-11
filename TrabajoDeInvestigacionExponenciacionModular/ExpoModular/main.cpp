#include <iostream>
#include <NTL/ZZ.h>
using namespace NTL;
using namespace std;


ZZ modExp(ZZ A, ZZ B, ZZ C)
{
    if (A == ZZ(0)) {
        return ZZ(0);
    }
    if (B == ZZ(0)) {
        return ZZ(1);
    }
    ZZ y;
    if (B % 2 == ZZ(0)) {
        y = modExp(A, B / 2, C);
        y = (y * y) % C;
    }
    else {
        y = A % C;
        y = (y * modExp(A, B - 1, C) % C) % C;
    }
    return (ZZ)((y + C) % C);
}

int main()
{
    ZZ A = ZZ(7), B = ZZ(256), C = ZZ(13);
    cout << A << "^"<< B << " mod" << C
         << " = "<< modExp(A, B, C);
    return 0;
}

