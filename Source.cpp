#include <iostream>
#include <string>

using namespace std;                                                                    //here is my programming from 5.4, i think it still works

// Function to double a digit and sum its individual digits
int doubleAndSum(int digit) {
    int doubled = digit * 2;
    return doubled % 10 + doubled / 10;
}

// Function to verify the credit card number
bool verifyCreditCard(const string& cardNumber) {
    int sum1 = 0;
    int sum2 = 0;

    // Iterate through the card number digits from right to left
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int digit = cardNumber[i] - '0';

        if ((cardNumber.length() - i) % 2 == 0) {
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
    string cardNumber;
    cout << "Enter the credit card number: ";
    cin >> cardNumber;

    if (verifyCreditCard(cardNumber)) {
        cout << "The credit card number is valid." << endl;
    }
    else {
        cout << "The credit card number is invalid." << endl;
    }

    return 0;
}
