#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 10;

void gaussSeidel(double a[MAX][MAX], double b[MAX], int n, double x[MAX], int max_iter = 100, double tol = 1e-6) {
    for (int i = 0; i < n; i++) x[i] = 0;

    for (int iter = 0; iter < max_iter; iter++) {
        double max_err = 0;
        for (int i = 0; i < n; i++) {
            double old = x[i];
            double sum = b[i];
            for (int j = 0; j < n; j++) {
                if (j != i) sum -= a[i][j] * x[j];
            }
            x[i] = sum / a[i][i];
            max_err = max(max_err, fabs(x[i] - old));
        }
        if (max_err < tol) break;
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }
}

int main() {
    int n;
    double a[MAX][MAX], b[MAX], x[MAX];

    cout << "Enter the number of equations: ";
    cin >> n;

    cout << "Enter the coefficients matrix (row-wise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    cout << "Enter the constant terms:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    gaussSeidel(a, b, n, x);
    return 0;
}