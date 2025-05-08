/*Qustion: Imagine you're developing a financial calculator for a bank's system that allows users to calculate the

ratio of two monetary values they input. This tool must be reliable, as it's part of a crucial decision-
making process for loan eligibility.

A bank customer is required to enter two values directly into the system:
1. The first value represents the total loan amount they wish to apply for.
2. The second value represents their annual income.
The system will compute and display the ratio of the loan amount to the income, which helps the bank
assess the customer's loan-to-income ratio.
Major challenges that developer will face while developing the system would be, if the customer
mistakenly enters non-numerical characters (e.g., "abc"), the system should handle the situation
gracefully and prompt the user to correct their input. If the customer enters 0 as their annual income,
the system must identify this issue and avoid performing a division that would lead to an invalid result.*/

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

bool isValidInput(double& value) {
    string input;
    getline(cin, input);
    stringstream ss(input);

    if (ss >> value) {
        return true;
    }
    return false;
}

int main() {
    double loanAmount, annualIncome;

    cout << "Enter the loan amount: ";
    while (true) {
        if (isValidInput(loanAmount)) {
            break;
        }
        cout << "Invalid input. Please enter a valid numerical loan amount: ";
    }

    cout << "Enter your annual income: ";
    while (true) {
        if (isValidInput(annualIncome) && annualIncome != 0) {
            break;
        } else if (annualIncome == 0) {
            cout << "Income cannot be zero. Please enter a valid income: ";
        } else {
            cout << "Invalid input. Please enter a valid numerical income: ";
        }
    }

    double ratio = loanAmount / annualIncome;

    cout << "\nLoan-to-Income Ratio: " << ratio << endl;

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
