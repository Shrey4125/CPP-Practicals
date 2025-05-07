/*Question : In a growing city, a newly established bank sought to streamline its operations by implementing a
digital system to manage customer accounts. The management envisioned a system where each
account would store details about the account holder, their unique account number, and the current
balance. To ensure flexibility and accuracy, they required functionalities for creating accounts with
varying initial balances, depositing money, withdrawing funds (with checks for sufficient balance), and
generating detailed account summaries.
The bank's IT team faced the challenge of developing a robust solution. They began by sketching out
the essential features of the system. The team highlighted that new accounts could be created in two
ways: one with no initial balance, and another with specified account details and a starting amount.
Additionally, they recognized the need for reliable mechanisms to handle deposits and withdrawals,
ensuring proper validation to prevent overdrafts. Displaying account details in a clear format was also
prioritized for customer communication.
To ensure scalability, the team decided to simulate the system by creating multiple accounts using the
proposed methods. They tested various scenarios, such as depositing and withdrawing different
amounts, handling edge cases like insufficient funds, and verifying that the account summaries were
accurate. This iterative approach helped them refine the system and ensure its readiness for
deployment.*/
 
#include<iostream>
using namespace std;

class BankAccount{
    string name;
    int AccountNumber;
    float balance;
    public:
    BankAccount(){
        name="N/A";
        balance=0;
        
    }
    BankAccount(string n, int acc, float bal){
        name=n;
        AccountNumber=acc;
        balance=bal;
    }
    void Deposit(float amount);
    void Withdraw(float amount);
    void DisplayAccountDetails();
};

void BankAccount::Deposit(float amount){
    balance+=amount;
}

void BankAccount::Withdraw(float amount){
    if(balance>=amount){
        balance-=amount;
    }
    else{
        cout<<"Not enough balance"<<endl<<endl;
    }
}

void BankAccount::DisplayAccountDetails(){
    cout<<"Name: "<<name<<endl;
    cout<<"Account Number: "<<AccountNumber<<endl;
    cout<<"Balance: "<<balance<<endl<<endl;
}

int main(){
    BankAccount b1;
    BankAccount b2("Shrey Rathod",12574129,2000);
    b1.Deposit(1000);
    b1.DisplayAccountDetails();
    b1.Withdraw(500);
    b1.DisplayAccountDetails();
    b2.DisplayAccountDetails();
    b2.Withdraw(3000);
    b2.DisplayAccountDetails();
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}