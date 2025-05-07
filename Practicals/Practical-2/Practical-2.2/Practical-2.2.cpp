/*Question: A university managing academic data for its students. The administration seeks to digitize the records
of student performance, including personal and academic details. The system must store each
student's roll number, name, and marks in three subjects. Additionally, it should provide
functionalities to calculate and display the average marks for performance analysis.
The institution's IT team proposed a solution where student records could be initialized in two ways:
either with default values for testing purposes or by accepting specific input details for each student.
Once initialized, the system would allow for viewing comprehensive student details, including their
roll number, name, marks, and calculated average. This functionality was designed to help faculty and
administrators track individual student performance efficiently.
To simulate real-world usage, the team decided to create multiple student records. They planned to
populate the system with a mix of students initialized using both default and specific values. The
system's ability to accurately calculate averages and display detailed student information was to be
tested with this data.*/


#include<iostream>
using namespace std;

class Student
{
    int rollNumber;
    string name;
    int marks[3];
public:
    Student()
    {
        rollNumber=0;
        name="N/A";
        for(int i=0; i<3; i++)
        {
            marks[i]=0;
        }
    }

    Student(int roll, string n, int m[])
    {
        rollNumber=roll;
        name=n;
        for(int i=0;i<3;i++)
        {
            marks[i] = m[i];
        }

    }

    void displayDetails()
    {
        cout<<"Roll Number: "<<rollNumber<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: ";
        for(int i=0; i<3; i++)
        {
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }

    void calculateAverage()
    {
        float avg=0;
        for(int i=0; i<3; i++)
        {
            avg+=marks[i];
        }
        avg/=3;
        cout<<"Average Marks: "<<avg<<endl<<endl;
    }
};

int main()
{
    int roll;
    string name1;
    int marks1[3]={20,30,40};
    int marks2[3]={35,65,34};
    Student s[2]={Student(1,"A",marks1),Student(2,"B",marks2)};
    for(int i=0;i<2;i++)
    {
        s[i].displayDetails();
        s[i].calculateAverage();
    }
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
