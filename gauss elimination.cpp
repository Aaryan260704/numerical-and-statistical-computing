#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 10;

void gaussElimination(double mat[MAX][MAX + 1], int n) {
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            if (abs(mat[i][i]) < abs(mat[k][i])) {
                for (int j = 0; j <= n; j++) {
                    swap(mat[i][j], mat[k][j]);
                }
            }
        }
        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    double x[MAX];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            x[i] -= mat[i][j] * x[j];
        }
        x[i] /= mat[i][i];
    }

    cout << "\nSolution:\n";
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(6) << x[i] << endl;
    }
}

int main() {
    int n;
    double mat[MAX][MAX + 1];

    cout << "Enter the number of equations: ";
    cin >> n;

    cout << "Enter the augmented matrix coefficients (row-wise):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            cin >> mat[i][j];
        }
    }

    gaussElimination(mat, n);

    return 0;
}