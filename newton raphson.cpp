#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x * x * x - x - 2;
}

double df(double x) {
    return 3 * x * x - 1;
}

void newtonRaphson(double x0, double tol = 1e-6, int max_iter = 1000) {
    double x1;
    int iter = 0;

    while (iter < max_iter) {
        if (df(x0) == 0) {
            cout << "Derivative zero. Method fails.\n";
            return;
        }

        x1 = x0 - f(x0) / df(x0);
        cout << "Iteration " << iter + 1 << ": x = " << x1 << ", f(x) = " << f(x1) << endl;

        if (fabs(x1 - x0) < tol) break;

        x0 = x1;
        iter++;
    }

    cout << "Root is approximately: " << x1 << endl;
}

int main() {
    double x0 = 1.5;
    newtonRaphson(x0);
    return 0;
}