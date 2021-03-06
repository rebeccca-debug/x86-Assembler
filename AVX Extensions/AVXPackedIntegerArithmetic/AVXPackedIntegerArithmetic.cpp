// AVXPackedIntegerArithmetic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "YmmVal.h"

extern "C" void AVXPackedInt_16(YmmVal * a, YmmVal * b, YmmVal c[6]);
extern "C" void AVXPackedInt_32(YmmVal * a, YmmVal * b, YmmVal c[5]);
void AVXPackedInt_16_Test(void);
void AVXPackedInt_32_Test(void);

int main()
{
    AVXPackedInt_16_Test();
    AVXPackedInt_32_Test();

    return 0;
}

void AVXPackedInt_16_Test(void) {
    __declspec(align(32)) YmmVal a;
    __declspec(align(32)) YmmVal b;
    __declspec(align(32)) YmmVal c[6];

    a.i16[0] = 30;          b.i16[0] = 3000;
    a.i16[1] = 56;          b.i16[1] = 7809;
    a.i16[2] = 785;         b.i16[2] = 10;
    a.i16[3] = 90828;       b.i16[3] = 5;
    a.i16[4] = -908;        b.i16[4] = 100;
    a.i16[5] = 234;         b.i16[5] = 87;
    a.i16[6] = -785;        b.i16[6] = 900;
    a.i16[7] = 1111;        b.i16[7] = 2222;
    a.i16[8] = 30;          b.i16[8] = 3000;
    a.i16[9] = 56;          b.i16[9] = 7809;
    a.i16[10] = 785;        b.i16[10] = 10;
    a.i16[11] = 90828;      b.i16[11] = 5;
    a.i16[12] = -908;       b.i16[12] = 100;
    a.i16[13] = 234;        b.i16[13] = 87;
    a.i16[14] = -785;       b.i16[14] = 900;
    a.i16[15] = 1111;       b.i16[15] = 2222;

    AVXPackedInt_16(&a, &b, c);
    printf("\nResult for Int 16\n");
    printf(" a  b   vpaddw  vpaddsw     vpubw     vpsubsw      vpminsw      vpmaxsw\n");
    printf("****************************************************************************");

    for (int i = 0; i < 16; i++) {

        const char* fs = "%7d";

        printf(fs, a.i16[i]);
        printf(fs, b.i16[i]);

        printf(fs, c[0].i16[i]);
        printf(fs, c[1].i16[i]);
        printf(fs, c[2].i16[i]);
        printf(fs, c[3].i16[i]);
        printf(fs, c[4].i16[i]);
        printf(fs, c[5].i16[i]);
        printf("\n");
    }

}

void AVXPackedInt_32_Test(void) {
    __declspec(align(32)) YmmVal a;
    __declspec(align(32)) YmmVal b;
    __declspec(align(32)) YmmVal c[5];

    a.i32[0] = 223020;          b.i32[0] = 3000;
    a.i32[1] = 132323;          b.i32[1] = 7809;
    a.i32[2] = 1;               b.i32[2] = 10;
    a.i32[3] = 4452;            b.i32[3] = 5;
    a.i32[4] = -91208;          b.i32[4] = 100;
    a.i32[5] = -9088;           b.i32[5] = 87;
    a.i32[6] = 233;             b.i32[6] = 900;
    a.i32[7] = 4552;            b.i32[7] = 2222;

    AVXPackedInt_32(&a, &b, c);

    printf("\nResult for Int 32\n");
    printf("        a        b   vpaddd  vpsubd  vpmulld  vpsllvd  vpsravd\n");
    printf("*********************************************************************");

    for (int i = 0; i < 8; i++) {

        const char* fs = "%7d";

        printf(fs, a.i32[i]);
        printf(fs, b.i32[i]);

        printf(fs, c[0].i32[i]);
        printf(fs, c[1].i32[i]);
        printf(fs, c[2].i32[i]);
        printf(fs, c[3].i32[i]);
        printf(fs, c[4].i32[i]);
        printf("\n");
    }

}