#include <iostream>
#include <cmath>
#include <complex>
#include <limits>

using namespace std;

void printSeparator() {
    cout << "\n===========================================================\n";
}

void printColorText(string text, string colorCode) {
    cout << "\033[" << colorCode << "m" << text << "\033[0m";
}

void solveQuadratic() {
    double a, b, c, disc;
    complex<double> root1, root2;

    cout << "Enter the coefficient 'a': ";
    while (!(cin >> a) || a == 0) {
        cout << "\033[1;31mInvalid input! 'a' cannot be zero or non-numeric. Try again: \033[0m";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the coefficient 'b': ";
    while (!(cin >> b)) {
        cout << "\033[1;31mInvalid input! Try again: \033[0m";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the coefficient 'c': ";
    while (!(cin >> c)) {
        cout << "\033[1;31mInvalid input! Try again: \033[0m";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    printSeparator();
    cout << "\U0001F4CC Solving the quadratic equation: " << a << "x² + " << b << "x + " << c << " = 0\n";

    disc = b * b - 4 * a * c;

    // Display the nature of roots
    if (disc > 0) {
        printColorText("\n\U0001F4A1 The equation has two distinct real roots.\n", "1;36");
    } else if (disc == 0) {
        printColorText("\n\U0001F4A1 The equation has one repeated real root.\n", "1;33");
    } else {
        printColorText("\n\U0001F4A1 The equation has complex (imaginary) roots.\n", "1;31");
    }

    // Solve and display the roots
    if (disc > 0) {
        root1 = (-b + sqrt(disc)) / (2 * a);
        root2 = (-b - sqrt(disc)) / (2 * a);
        printColorText("\n\U0001F389 Two Real Roots Found!\n", "1;32");
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
        printColorText("\n\U0001F525 The roots are imaginary! \n", "1;31");
        cout << "\U0001F539 Root 1: " << root1 << endl;
        cout << "\U0001F539 Root 2: " << root2 << endl;
    }

    printSeparator();
}

int main() {
    printColorText("\n\U0001F680 Welcome to the Quadratic Equation Solver! \U0001F680\n", "1;34");

    char choice;
    do {
        printSeparator();
        solveQuadratic();

        cout << "\n\U0001F3AF Would you like to solve another equation? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    printColorText("\n\U0001F44B Thank you for using the Quadratic Equation Solver! \U0001F44B\n", "1;34");
    return 0;
}
