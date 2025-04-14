/*Question: A bank wants to create a simple system to manage customer bank accounts. The system should
allow customers to perform basic banking operations such as depositing money, withdrawing
money, and checking their account balance.
Each bank account will need to have an account holder's name, a unique account number, and
a balance. Deposits should increase the account balance, while withdrawals should only be
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more
money than is available, an error message should be displayed. Customers should also have the
ability to view their account balance whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on
creating a simple and efficient solution to manage the accounts effectively. The system should
ensure that all account details are secure and accessible only through authorized methods.*/
#include<iostream>
#include<iomanip>
using namespace std;

//Making class for bankaccounts
class BankAccount{
    double Balance;
    string Name;
    int AccountNo;

    public:
        //default constructor
        BankAccount()
        {
            Balance = 0;
            Name = "N/A";
            AccountNo = 000;
        }

        //parameterized constructor
        BankAccount(int acc_no , string name , double balance)
        {
            Balance=balance;
            Name=name;
            AccountNo=acc_no;
        }

        //function to deposit money
        void Deposit(double amount)
        {
            Balance += amount;
            cout<< "Deposited"<<setw(8)<<": " << amount << endl<<endl;
            DisplayDetails();
        }

        //function to withdraw money
        void Withdraw(double amount)
        {
            if(Balance >= amount)
            {
                Balance -= amount;
                cout << "Withdrawn" << setw(8) << ": " << amount << endl << endl;
                DisplayDetails();
            }
            else
            {
                cout << "Not enough balance" << endl;
            }
        }

        //function to display all details
        void DisplayDetails()
        {
            cout << "Holder Name" << setw(6) << ": " << Name << endl;
            cout << "Account Number : " << AccountNo << endl;
            cout << "Balance" << setw(10) << ": " << Balance << endl << endl;
        }
};

int main()
{
    cout<<setw(6)<<"SBI BANK ACCOUNT DISPLAY"<<endl<<endl;
    //making a object to create a bank account
    //using parameterized constructor
    BankAccount A1 (4125 , "Shrey" , 20000);
    //calling functions
    A1.DisplayDetails();
    A1.Deposit(5000);
    A1.Withdraw(2500);
    BankAccount A2 (0412 , "Dhyey" , 30000);
    A2.DisplayDetails();
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
