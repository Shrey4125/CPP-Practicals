/*Question: A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.

To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.

EMI=
P ∗ R ∗ (1 + R)^T
((1+R)^T) −1

As part of the implementation, the developers planned to initialize loans either with default values for
testing purposes or with actual customer data provided at the time of application. The system needed
to include a feature to display comprehensive loan details, including the calculated EMI, in a customer-
friendly format. This functionality was intended to aid both customers and bank staff in managing
loan-related queries effectively.*/ 

#include<iostream>
#include<cmath>
using namespace std;

class Loan{
    int LoanId;
    string Name;
    double Principal;
    float RateOfInterest;
    int Tenure;
    float EMI;
    public:
        Loan(int id,string n,double p,float r,int t)
        {
            LoanId=id;
            Name=n;
            Principal=p;
            RateOfInterest=r;
            Tenure=t;
        }
        void CalculateEMI()
        {
            float a=pow(1+RateOfInterest,Tenure);
            float x=((Principal*RateOfInterest)*a);
            float y=(a-1);
            EMI=x/y;
            cout<<a<<endl;
        }
        void DisplayDetails()
        {
            cout<<"Loan ID: "<<LoanId<<endl;
            cout<<"Name: "<<Name<<endl;
            cout<<"Principal Amount: "<<Principal<<endl;
            cout<<"Rate Of Interest: "<<RateOfInterest<<endl;
            cout<<"Tenure: "<<Tenure<<endl;
            CalculateEMI();
            cout<<"EMI: "<<EMI<<endl<<endl;
        }
};

int main()
{
    Loan l1(12574129,"Shrey",200000,12,1);
    l1.DisplayDetails();
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}