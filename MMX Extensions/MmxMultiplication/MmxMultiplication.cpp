#include "pch.h"
#include <iostream>
#include "MmxVal.h"

extern "C" void MmxMultiply(MmxVal a, MmxVal b, MmxVal * prod_lo, MmxVal * prod_hi);
int main()
{
    MmxVal a, b;
    MmxVal prod_lo, prod_hi;
    char buff[256];

    a.i16[0] = 10;      b.i16[0] = 2000;
    a.i16[1] = 30;      b.i16[0] = -4000;
    a.i16[0] = -50;     b.i16[0] = 6000;
    a.i16[1] = -70;     b.i16[0] = -8000;

    MmxMultiply(a, b, &prod_lo, &prod_hi);

    printf("\nResult of MmxMulSignedWord\n");
    printf("a:%s\n", a.ToString_i16(buff, sizeof(buff)));
    printf("b:%s\n", a.ToString_i16(buff, sizeof(buff)));

    printf("prod_lo:%s\n", prod_lo.ToString_i32(buff, sizeof(buff)));
    printf("prod_hi:%s\n", prod_hi.ToString_i32(buff, sizeof(buff)));

    return 0;
}