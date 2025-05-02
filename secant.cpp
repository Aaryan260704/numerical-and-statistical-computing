#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 2;
}

void secant(double x0, double x1, double tol = 1e-6, int max_iter = 1000) {
    double x2;
    int iter = 0;

    while (fabs(f(x1)) > tol && iter < max_iter) {
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        x0 = x1;
        x1 = x2;
        iter++;
        cout << "Iteration " << iter << ": x = " << x2 << ", f(x) = " << f(x2) << endl;
    }

    cout << "Root is approximately: " << x2 << endl;
}

int main() {
    double x0 = 1, x1 = 2;
    secant(x0, x1);
    return 0;
}