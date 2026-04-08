#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// ── ANSI colour helpers ──────────────────────────────────────────────────────
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define CYAN    "\033[96m"
#define YELLOW  "\033[93m"
#define GREEN   "\033[92m"
#define RED     "\033[91m"
#define MAGENTA "\033[95m"

// ── Utilities ────────────────────────────────────────────────────────────────
void clearInvalidInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

double getNumber(const string& prompt) {
    double val;
    while (true) {
        cout << YELLOW << prompt << RESET;
        if (cin >> val) return val;
        cout << RED << "  ✗ Invalid input. Please enter a number.\n" << RESET;
        clearInvalidInput();
    }
}

int getChoice() {
    int val;
    while (true) {
        cout << CYAN << BOLD << "  Enter your choice: " << RESET;
        if (cin >> val) return val;
        cout << RED << "  ✗ Invalid input. Enter a number from the menu.\n" << RESET;
        clearInvalidInput();
    }
}

void printDivider(char c = '─', int width = 45) {
    cout << CYAN;
    for (int i = 0; i < width; i++) cout << c;
    cout << RESET << "\n";
}

// ── History ──────────────────────────────────────────────────────────────────
struct Record {
    string expression;
    double result;
};

vector<Record> history;

void addHistory(const string& expr, double result) {
    history.push_back({expr, result});
}

void showHistory() {
    cout << "\n";
    printDivider();
    cout << BOLD << MAGENTA << "  📋  Calculation History\n" << RESET;
    printDivider();
    if (history.empty()) {
        cout << "  No calculations yet.\n";
    } else {
        for (size_t i = 0; i < history.size(); i++) {
            cout << "  " << setw(2) << i + 1 << ".  "
                 << history[i].expression << " = "
                 << GREEN << history[i].result << RESET << "\n";
        }
    }
    printDivider();
}

// ── Menu ─────────────────────────────────────────────────────────────────────
void showMenu() {
    cout << "\n";
    printDivider('═');
    cout << BOLD << CYAN
         << "       ◈  C++ ENHANCED CALCULATOR  ◈\n"
         << RESET;
    printDivider('═');

    const char* opts[] = {
        "Addition          (a + b)",
        "Subtraction       (a - b)",
        "Multiplication    (a × b)",
        "Division          (a ÷ b)",
        "Floor Division    (⌊a ÷ b⌋)",
        "Modulus           (a mod b)",
        "Power             (aⁿ)",
        "Square            (a²)",
        "Square Root       (√a)",
        "Cube Root         (∛a)",
        "Logarithm Base-10 (log a)",
        "Natural Log       (ln a)",
        "Absolute Value    (|a|)",
        "Show History",
        "Clear History",
        "Exit"
    };

    for (int i = 0; i < 16; i++) {
        cout << "  " << BOLD << setw(2) << i + 1 << RESET
             << ".  " << opts[i] << "\n";
    }
    printDivider('═');
}
// ── Main ─────────────────────────────────────────────────────────────────────
int main() {
    cout << fixed << setprecision(6);

    while (true) {
        showMenu();
        int choice = getChoice();
        cout << "\n";

        double a, b, result;
        string expr;

        switch (choice) {

            // ── Binary operations ───────────────────────────────────────────
            case 1: case 2: case 3: case 4: case 5: case 6: case 7: {
                a = getNumber("  Enter first  number (a): ");
                b = getNumber("  Enter second number (b): ");

                if ((choice == 4 || choice == 5 || choice == 6) && b == 0) {
                    cout << RED << "  ✗ Error: Division by zero!\n" << RESET;
                    break;
                }

                switch (choice) {
                    case 1: result = a + b;            expr = to_string(a) + " + " + to_string(b); break;
                    case 2: result = a - b;            expr = to_string(a) + " - " + to_string(b); break;
                    case 3: result = a * b;            expr = to_string(a) + " × " + to_string(b); break;
                    case 4: result = a / b;            expr = to_string(a) + " ÷ " + to_string(b); break;
                    case 5: result = floor(a / b);     expr = "⌊" + to_string(a) + " ÷ " + to_string(b) + "⌋"; break;
                    case 6: result = fmod(a, b);       expr = to_string(a) + " mod " + to_string(b); break;
                    case 7: result = pow(a, b);        expr = to_string(a) + " ^ " + to_string(b); break;
                }
                cout << GREEN << "  ✔ Result = " << result << RESET << "\n";
                addHistory(expr, result);
                break;
            }

            // ── Unary operations ────────────────────────────────────────────
            case 8: case 9: case 10: case 11: case 12: case 13: {
                a = getNumber("  Enter a number (a): ");

                if (choice == 9 && a < 0) {
                    cout << RED << "  ✗ Error: Square root of a negative number is undefined in ℝ.\n" << RESET;
                    break;
                }
                if ((choice == 11 || choice == 12) && a <= 0) {
                    cout << RED << "  ✗ Error: Logarithm undefined for non-positive numbers.\n" << RESET;
                    break;
                }

                
