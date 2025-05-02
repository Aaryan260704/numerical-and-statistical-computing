#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 2;
}

void regulaFalsi(double a, double b, double tol = 1e-6, int max_iter = 1000) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) must have opposite signs.\n";
        return;
    }

    double c;
    int iter = 0;

    while (iter < max_iter) {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        cout << "Iteration " << iter + 1 << ": c = " << c << ", f(c) = " << f(c) << endl;

        if (fabs(f(c)) < tol) break;

        if (f(c) * f(a) < 0) b = c;
        else a = c;

        iter++;
    }

    cout << "Root is approximately: " << c << endl;
}

int main() {
    double a = 1, b = 2;
    regulaFalsi(a, b);
    return 0;
}