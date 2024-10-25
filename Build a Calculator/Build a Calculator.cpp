#include <iostream>
#include <cmath>

using namespace std;

// Helper function for factorial
int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    cout << "Welcome to the Enhanced SJA Calculator!\n";
    cout << "Here are the available operations:\n";
    cout << "Basic Arithmetic:\n";
    cout << "  + : Addition\n";
    cout << "  - : Subtraction\n";
    cout << "  * : Multiplication\n";
    cout << "  / : Division\n";
    cout << "  % : Modulus (Remainder)\n";
    cout << "  ^ : Power (firstNum^secondNum)\n";
    cout << "\nUnary Operations (only use firstNum):\n";
    cout << "  r : Square root\n";
    cout << "  a : Absolute value\n";
    cout << "  e : Exponential (e^firstNum)\n";
    cout << "  l : Natural logarithm (ln(firstNum))\n";
    cout << "  g : Logarithm base 10 (log10(firstNum))\n";
    cout << "\nTrigonometric Functions (in radians):\n";
    cout << "  s : Sine\n";
    cout << "  c : Cosine\n";
    cout << "  t : Tangent\n";
    cout << "\nInverse Trigonometric Functions (in radians):\n";
    cout << "  S : Arcsine\n";
    cout << "  C : Arccosine\n";
    cout << "  T : Arctangent\n";
    cout << "\nHyperbolic Functions:\n";
    cout << "  h : Hyperbolic Sine (sinh)\n";
    cout << "  H : Hyperbolic Cosine (cosh)\n";
    cout << "  y : Hyperbolic Tangent (tanh)\n";
    cout << "\nAdditional Functions:\n";
    cout << "  ! : Factorial (for non-negative integers)\n";
    cout << "  m : Maximum of two numbers\n";
    cout << "  n : Minimum of two numbers\n";
    cout << "\nBitwise Operations:\n";
    cout << "  & : Bitwise AND\n";
    cout << "  | : Bitwise OR\n";
    cout << "\n";

    double firstNum, secondNum, result;
    char op;

    cout << "Enter First Number: ";
    cin >> firstNum;
    cout << "Enter the operator (+ - * / % ^ r a e l g m n s c t S C T h H y ! & |): ";
    cin >> op;

    if (op == 'r' || op == 'a' || op == 'e' || op == 'l' || op == 'g' || op == 's' || op == 'c' ||
        op == 't' || op == 'S' || op == 'C' || op == 'T' || op == 'h' || op == 'H' || op == 'y' || op == '!') {

        // Unary operations
        if (op == 'r') {
            if (firstNum >= 0) {
                result = sqrt(firstNum);
            } else {
                cout << "Error: Square root of negative number is not real." << endl;
                return 1;
            }
        } else if (op == 'a') {
            result = abs(firstNum);
        } else if (op == 'e') {
            result = exp(firstNum);
        } else if (op == 'l') {
            if (firstNum > 0) {
                result = log(firstNum); // Natural logarithm
            } else {
                cout << "Error: Logarithm of non-positive number." << endl;
                return 1;
            }
        } else if (op == 'g') {
            if (firstNum > 0) {
                result = log10(firstNum); // Logarithm base 10
            } else {
                cout << "Error: Logarithm of non-positive number." << endl;
                return 1;
            }
        } else if (op == 's') {
            result = sin(firstNum);
        } else if (op == 'c') {
            result = cos(firstNum);
        } else if (op == 't') {
            result = tan(firstNum);
        } else if (op == 'S') {
            result = asin(firstNum);
        } else if (op == 'C') {
            result = acos(firstNum);
        } else if (op == 'T') {
            result = atan(firstNum);
        } else if (op == 'h') {
            result = sinh(firstNum);
        } else if (op == 'H') {
            result = cosh(firstNum);
        } else if (op == 'y') {
            result = tanh(firstNum);
        } else if (op == '!') {
            if (firstNum >= 0 && int(firstNum) == firstNum) {
                result = factorial(static_cast<int>(firstNum));
            } else {
                cout << "Error: Factorial only defined for non-negative integers." << endl;
                return 1;
            }
        } else {
            cout << "Invalid Operator" << endl;
            return 1;
        }
        cout << "Result = " << result << endl;
    } else {
        // Binary operations
        cout << "Enter Second Number: ";
        cin >> secondNum;

        if (op == '+') {
            result = firstNum + secondNum;
        } else if (op == '-') {
            result = firstNum - secondNum;
        } else if (op == '*') {
            result = firstNum * secondNum;
        } else if (op == '/') {
            if (secondNum != 0) {
                result = firstNum / secondNum;
            } else {
                cout << "Error: Division by zero." << endl;
                return 1;
            }
        } else if (op == '%') {
            if (secondNum != 0) {
                result = fmod(firstNum, secondNum);
            } else {
                cout << "Error: Modulo by zero." << endl;
                return 1;
            }
        } else if (op == '^') {
            result = pow(firstNum, secondNum);
        } else if (op == 'm') {
            result = max(firstNum, secondNum);
        } else if (op == 'n') {
            result = min(firstNum, secondNum);
        } else if (op == '&') {
            result = static_cast<int>(firstNum) & static_cast<int>(secondNum);
        } else if (op == '|') {
            result = static_cast<int>(firstNum) | static_cast<int>(secondNum);
        } else {
            cout << "Invalid Operator" << endl;
            return 1;
        }
        cout << "Result = " << result << endl;
    }

    return 0;
}
