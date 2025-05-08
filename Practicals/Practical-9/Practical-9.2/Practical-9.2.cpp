/*Question: Imagine you are tasked with developing a simple banking system for a local financial institution. The
bank has observed an increase in customer complaints regarding unclear transaction records and
unhandled errors during operations. They want a robust software module to manage bank accounts
efficiently while maintaining a log of transactions.
As a software developer, your job is to create a banking system with the following features:
1. A way to represent individual bank accounts, including the ability to manage their balances.
2. Secure methods to deposit and withdraw funds.
3. An error-handling mechanism to address invalid operations, such as attempting to withdraw more
than the account's current balance.

4. A feature that logs every function call when an error occurs to provide insights into the issue.
The bank also insists on maintaining a history of transactions using basic data structures without
relying on advanced libraries or containers. Design and implement a banking system that fulfills the
above requirements.*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class BankAccount {
private:
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(double initialBalance = 0.0) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            recordTransaction("Deposited: " + to_string(amount));
        } else {
            logError("Invalid deposit amount: " + to_string(amount));
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            logError("Invalid withdrawal amount: " + to_string(amount));
            return;
        }
        if (amount > balance) {
            logError("Insufficient funds for withdrawal of: " + to_string(amount));
        } else {
            balance -= amount;
            recordTransaction("Withdrew: " + to_string(amount));
        }
    }

    void printTransactionHistory() const {
        if (transactionHistory.empty()) {
            cout << "No transactions available.\n";
        } else {
            for (const auto& transaction : transactionHistory) {
                cout << transaction << endl;
            }
        }
    }

private:
    void recordTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

    void logError(const string& error) const {
        cout << "Error: " << error << endl;
        ofstream logFile("error_log.txt", ios::app);
        if (logFile.is_open()) {
            logFile << error << endl;
        }
        logFile.close();
    }
};

int main() {
    BankAccount account(500.0); // Starting balance of 500.0

    cout << "Initial Balance: " << account.getBalance() << endl;

    account.deposit(100); // Depositing 100
    account.withdraw(200); // Withdrawing 200
    account.withdraw(600); // Trying to withdraw more than available
    account.deposit(-50); // Invalid deposit

    cout << "\nTransaction History:\n";
    account.printTransactionHistory();

    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
