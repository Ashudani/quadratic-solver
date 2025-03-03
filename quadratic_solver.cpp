#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

void printSeparator() {
    cout << "\n===========================================================\n";
}

void printColorText(string text, string colorCode) {
    cout << "\033[" << colorCode << "m" << text << "\033[0m";
}

int main() {
    double a, b, c, disc;
    complex<double> root1, root2;

    printColorText("\n\u2728 Welcome to the Quadratic Equation Solver! \u2728\n", "1;34");
    printSeparator();

    cout << "Enter the coefficient 'a': ";
    cin >> a;
    cout << "Enter the coefficient 'b': ";
    cin >> b;
    cout << "Enter the coefficient 'c': ";
    cin >> c;

    printSeparator();
    cout << "\U0001F4CC Solving the quadratic equation: " << a << "x² + " << b << "x + " << c << " = 0\n";

    disc = b * b - 4 * a * c;

    if (disc > 0) {
        root1 = (-b + sqrt(disc)) / (2 * a);
        root2 = (-b - sqrt(disc)) / (2 * a);
        printColorText("\n\u2705 Two Real Roots Found!\n", "1;32");
        cout << "\U0001F539 Root 1: " << root1.real() << endl;
        cout << "\U0001F539 Root 2: " << root2.real() << endl;
    } 
    else if (disc == 0) {
        root1 = root2 = -b / (2 * a);
        printColorText("\n\U0001F539 One Repeated Real Root: ", "1;33");
        cout << root1.real() << endl;
    } 
    else {
        complex<double> sqrt_disc(0, sqrt(-disc));
        root1 = (-b + sqrt_disc) / (2.0 * a);
        root2 = (-b - sqrt_disc) / (2.0 * a);
        printColorText("\n\u26A0 The roots are imaginary! \u26A0\n", "1;31");
        cout << "\U0001F539 Root 1: " << root1 << endl;
        cout << "\U0001F539 Root 2: " << root2 << endl;
    }

    printSeparator();
    printColorText("\u2728 Thank you for using the Quadratic Equation Solver! \u2728\n", "1;34");
    return 0;
}

