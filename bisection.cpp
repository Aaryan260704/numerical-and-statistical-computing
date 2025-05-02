#include <iostream>
#include <cmath>
using namespace std;


double f(double x) {
    return x * x * x - x - 2;  
}

void bisection(double a, double b, double tolerance = 1e-6, int max_iter = 1000) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval. f(a) and f(b) should have opposite signs." << endl;
        return;
    }

    double c;
    int iter = 0;
    while ((b - a) >= tolerance && iter < max_iter) {
        c = (a + b) / 2;
        cout << "Iteration " << iter + 1 << ": c = " << c << ", f(c) = " << f(c) << endl;

        if (fabs(f(c)) < tolerance) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
        iter++;
    }

    cout << "The root is approximately: " << c << endl;
}

int main() {
    double a = 1, b = 2;  
    bisection(a, b);
    return 0;
}