/*Question: A local construction company frequently deals with rectangular plots and structures of varying
dimensions. To streamline their planning and estimation processes, the company requires a simple
system to manage and analyze rectangular shapes efficiently.
The system must be able to handle multiple rectangles, each with distinct dimensions. For each
rectangle, the length and width need to be defined and stored securely. Additionally, the company
needs the ability to calculate two key metrics for any given rectangle:
The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths
or material requirements for edges. To make this system functional, there should be a way to define
or update the dimensions of any rectangle as required. The system should be capable of creating and
managing multiple rectangle records, performing calculations for each, and displaying the results
clearly for analysis and planning purposes.Do it with an array of object.Take the number of rectangles input from user*/

#include<iostream>
using namespace std;

class Rectangle{
    float length,width;
    public:
        void SetDimensions(float l, float b)
        {
            length=l;
            width=b;
        }
        void CalculateArea()
        {
            cout<<"Area: "<<length*width<<endl;
        }
        void CalculatePerimeter()
        {
            cout<<"Perimeter: "<<2*(length+width)<<endl;
        }
        void DisplayDetails()
        {
            cout<<"Dimensions are:"<<endl<<"Length: "<<length<<endl<<"Width: "<<width<<endl;
            CalculateArea();
            CalculatePerimeter();
        }
};

int main()
{
    int n;
    cout<<"Enter Number Of Rectangles: ";
    cin>>n;
    Rectangle R[n];
    int length[n],width[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Enter Length and Width of Rectangle "<<i+1<<": ";
        cin>>length[i]>>width[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"Rectangle "<<i+1<<endl;
        R[i].SetDimensions(length[i],width[i]);
        R[i].DisplayDetails();
    }
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}