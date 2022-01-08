#include "pch.h"
#include <iostream>
#include "XmmVal.h"

extern "C" void SsePackedInt16_Add(const XmmVal * a, const XmmVal * b, XmmVal c[2]);
extern "C" void SsePackedInt32_Sub(const XmmVal * a, const XmmVal * b, XmmVal * c);
extern "C" void SsePackedInt32_Mul(const XmmVal * a, const XmmVal * b, XmmVal c[2]);

void SsePackedInt16_Add(void);
void SsePackedInt32_Sub(void);
void SsePackedInt32_Mul(void);
int main()
{
    SsePackedInt16_Add();
    SsePackedInt32_Sub();
    SsePackedInt32_Mul();
}

void SsePackedInt16_Add(void) {

    _declspec(align(16)) XmmVal a;
    _declspec(align(16)) XmmVal b;
    _declspec(align(16)) XmmVal c[2];
    char buff[256];

    a.i16[0] = 10;      b.i16[0] = 90;
    a.i16[1] = 210;      b.i16[1] = 78;
    a.i16[2] = -890;      b.i16[2] = 90;
    a.i16[3] = 234;      b.i16[3] = 76;
    a.i16[4] = 46;      b.i16[4] = 4;
    a.i16[5] = 67;      b.i16[5] = -89;
    a.i16[6] = 0;      b.i16[6] = 1;
    a.i16[7] = 254;      b.i16[7] = 18;

    SsePackedInt16_Add(&a, &b, c);

    printf("\nResult for SsePackedInt16_Add\n ");
    printf("a: %s\n", a.ToString_i16(buff, sizeof(buff)));
    printf("b: %s\n", b.ToString_i16(buff, sizeof(buff)));
    printf("c: %s\n", c[0].ToString_i16(buff, sizeof(buff)));
    printf("\n");
    printf("a: %s\n", a.ToString_i16(buff, sizeof(buff)));
    printf("b: %s\n", b.ToString_i16(buff, sizeof(buff)));
    printf("c: %s\n", c[1].ToString_i16(buff, sizeof(buff)));
}

void SsePackedInt32_Sub(void) {

    _declspec(align(16)) XmmVal a;
    _declspec(align(16)) XmmVal b;      //needs to be aligned on a 16 byte memory address
    _declspec(align(8)) XmmVal c;
    char buff[256];

    a.i32[0] = 200;      b.i32[0] = 90;
    a.i32[1] = 2901;      b.i32[1] = -307;
    a.i32[2] = -890;      b.i32[2] = 150;
    a.i32[3] = 234;      b.i32[3] = 76;

    SsePackedInt32_Sub(&a, &b, &c);

    printf("\nResult for SsePackedInt16_Sub\n ");
    printf("a: %s\n", a.ToString_i32(buff, sizeof(buff)));
    printf("b: %s\n", b.ToString_i32(buff, sizeof(buff)));
    printf("c: %s\n", c.ToString_i32(buff, sizeof(buff)));
}

void SsePackedInt32_Mul(void) {

    _declspec(align(16)) XmmVal a;
    _declspec(align(16)) XmmVal b;
    _declspec(align(16)) XmmVal c[2];
    char buff[256];

    a.i32[0] = 10;      b.i32[0] = 1000;
    a.i32[1] = 210;      b.i32[1] = 78;
    a.i32[2] = -890;      b.i32[2] = 90;
    a.i32[3] = 234;      b.i32[3] = 76;

    SsePackedInt32_Mul(&a, &b, c);

    printf("\nResult for SsePackedInt32_Mul\n ");
    printf("a: %s\n", a.ToString_i32(buff, sizeof(buff)));
    printf("b: %s\n", b.ToString_i32(buff, sizeof(buff)));
    printf("c: %s\n", c[1].ToString_i64(buff, sizeof(buff)));
    printf("\n");
}