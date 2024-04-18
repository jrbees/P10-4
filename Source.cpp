#include <iostream>

using namespace std;

// Function to double a digit and sum its individual digits
int doubleAndSum(int digit) {
    int doubled = digit * 2;
    return doubled % 10 + doubled / 10;
}

// Function to verify the credit card number
bool isCardValid(int digits[], int size) {
    int sum1 = 0;
    int sum2 = 0;

    // Iterate through the card number digits from right to left
    for (int i = size - 1; i >= 0; i--) {
        int digit = digits[i];

        if ((size - i) % 2 == 0) {
            // Step 1: Double each of the digits and sum their individual digits
            sum2 += doubleAndSum(digit);
        }
        else {
            // Step 2: Form the sum of every other digit
            sum1 += digit;
        }
    }

    // Step 3: Add the sums
    int totalSum = sum1 + sum2;

    // Step 4: Check if the last digit of the result is 0
    return (totalSum % 10 == 0);
}

int main() {
    int cardNumber;
    while (true) {
        cout << "Enter 8-digit credit card # or Q to quit: ";
        if (!(cin >> cardNumber)) {
            // Input is not an integer, quit the program
            break;
        }

        int digits[8];
        // Extract each digit from the card number and store it in an array
        for (int i = 7; i >= 0; i--) {
            digits[i] = cardNumber % 10;
            cardNumber /= 10;
        }

        // Check if the card number is valid
        if (isCardValid(digits, 8)) {
            cout << "Card is valid." << endl;
        }
        else {
            cout << "Card is not valid." << endl;
        }
    }

    return 0;
}
