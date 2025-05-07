/*Question: A growing organization sought to enhance its payroll process to improve accuracy and efficiency in
calculating employee salaries. The goal was to manage details such as the employee's name, basic
salary, and bonus amount. While most employees would receive a default bonus, there was a need
for flexibility to provide customized bonuses for exceptional performers or those in specialized roles.
To ensure real-time computation of each employee's total salary, the system would dynamically
calculate the total salary by adding the basic salary and the bonus. An inline function was chosen for
this task, allowing the system to compute the total salary instantly during processing. The system was
designed to initialize employee records using a constructor, where the bonus could either be set to a
default value or adjusted according to specific employee criteria.
As the organization expanded, managing employee records efficiently became a key consideration.
The solution involved storing employee details dynamically, ensuring the system could handle a
growing number of records while maintaining scalability and flexibility. Each employee record would
include their personal details, basic salary, and bonus information, with the system displaying a
breakdown of each employee’s details along with their total salary.*/
#include<iostream>
#include<vector>
using namespace std;

class Employee{
    string Name;
    double BasicSalary;
    double Bonus;
    double TotalSalary;
    public:
        Employee()
        {
            Name="N/A";
            BasicSalary=30000;
            Bonus=0;
        }
        Employee(string n,double basic,double bonus)
        {
            Name=n;
            Bonus=bonus;
            BasicSalary=basic;
        }
        inline void CalculateTotalSalary()
        {
            TotalSalary=(BasicSalary+Bonus);
        }
        void DisplayDetails()
        {
            cout<<"Employee Name: "<<Name<<endl;
            cout<<"Basic Salary: "<<BasicSalary<<endl;
            cout<<"Bonus: "<<Bonus<<endl;
            CalculateTotalSalary();
            cout<<"Total Salary: "<<TotalSalary<<endl<<endl;
        }
};

int main()
{
    vector<Employee> emp;

    emp.emplace_back(Employee("Shrey",50000,50000));
    emp.emplace_back(Employee("Dhyey",10000,500));

    for(auto& i:emp)
    {
        i.DisplayDetails();
    }
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
