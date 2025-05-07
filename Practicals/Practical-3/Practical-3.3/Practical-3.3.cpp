/*Question: A community bank sought to enhance its account management system with a digital solution to
improve efficiency and provide better customer service. The system was required to manage the
essential details of each account, including the account number, account holder’s name, and balance.
Additionally, the bank wanted to provide a secure mechanism for transferring money between
accounts, allowing customers to easily manage their funds.
The bank also needed a way to track the total number of accounts created, which would be important
for generating reports and understanding the growth of their customer base. This feature was aimed
at helping the bank maintain an overview of their account portfolio and analyze trends over time.
To ensure smooth and reliable operations, the system was designed to store account information in a
way that would allow easy access and updates. When new accounts were created, they would be
added to the system dynamically. The management team planned for future scalability and
performance improvements by considering more efficient storage and retrieval methods after the
initial system was built, ensuring that the bank could easily accommodate more accounts and
transactions as the customer base grew.*/
#include<iostream>
#include<vector>
using namespace std;

class Account{
    int AccountNumber;
    string Name;
    double Balance;

    public:
    static int NumberOfAccounts;
        Account()
        {
            AccountNumber=0;
            Name="N/A";
            Balance=0;
            NumberOfAccounts++;
        }
        Account(int no,string n,double bal)
        {
            AccountNumber=no;
            Name=n;
            Balance=bal;
            NumberOfAccounts++;
        }
        void DisplayDetails()
        {
            cout<<"Account Number: "<<AccountNumber<<endl;
            cout<<"Holder's Name: "<<Name<<endl;
            cout<<"Balance: "<<Balance<<endl;
        }
        int getAccountNumber()
        {
            return AccountNumber;
        }
        friend void Transfer(Account& from,double amt,Account& to)
        {
            if(amt<=from.Balance)
            {
                from.Balance-=amt;
                to.Balance+=amt;
                cout<<amt<<" Transfer Successful"<<endl<<endl;
            }
            else
            {
                cout<<"Invalid Amount!!!"<<endl<<endl;
            }
        }
};

int Account::NumberOfAccounts = 0;

int main()
{
    vector<Account> acc;
    acc.emplace_back(Account(1,"Shrey",80000));
    acc.emplace_back(Account(2,"Dhyey",50000));
    acc.emplace_back(Account());

    for(auto& i:acc)
    {
        i.DisplayDetails();
        cout<<endl;
    }

    int a;
    cout<<"If you want to transfer money then enter 1 else 0 : ";
    cin>>a;

    if(a==1)
    {
        int fromAcc, toAcc, amt;
        cout<<"Enter sender account number: ";
        cin>>fromAcc;
        cout<<"Enter receiver account number: ";
        cin>>toAcc;
        cout<<"Enter amount to transfer: ";
        cin>>amt;

        Account *from = nullptr, *to = nullptr;

        for(auto& i : acc)
        {
            if(i.getAccountNumber() == fromAcc)
                from = &i;
            if(i.getAccountNumber() == toAcc)
                to = &i;
        }

        if(from && to)
        {
            Transfer(*from, amt, *to);
        }
        else
        {
            cout<<"Invalid account number(s)!"<<endl<<endl;
        }
    }

    for(auto& i:acc)
    {
        i.DisplayDetails();
        cout<<endl;
    }

    cout<<Account::NumberOfAccounts;
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
