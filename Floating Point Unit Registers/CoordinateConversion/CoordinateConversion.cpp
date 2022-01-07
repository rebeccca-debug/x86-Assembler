// CoordinateConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

extern "C" void RectToPolar(double x, double y, double* r, double* a);
extern "C" void PolarToRect(double r, double a, double* x, double* y);

int main()
{
    double x[] = { 0,3,-3,-5,6 };
    double y[] = { 0,3,5,-7,8 };
    const int nx = sizeof(x) / sizeof(double);
    const int ny = sizeof(y) / sizeof(double);

    for (int i = 0; i < ny; i++) {
        for (int j = 0; j < nx; j++) {
            double r, a, _x, _y;
            RectToPolar(x[i], y[i], &r, &a);
            PolarToRect(r, a, &_x, &_y);

            printf("[%d, %d]:", i, j);
            printf("%8.4lf, %8.4lf", x[i], y[i]);
            printf("(%8.4lf, %10.4lf)", r, a);
            printf(" (%8.4lf, %8.4lf)\n", _x, _y);
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
