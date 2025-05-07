/*Question: A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's
management sought to build a system that could keep track of individual items, including details like
a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.
To address this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of item details, either with default values or
specific attributes like ID, name, price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when items were sold,
ensuring sufficient inventory was available for each transaction. Additionally, the system would
provide clear, detailed summaries of each item's status, aiding in decision-making and reporting.
The developers faced real-world scenarios where they had to manage multiple inventory items
simultaneously. They planned to design an array of inventory items and simulate common tasks such
as adding stock, processing sales transactions, and displaying the current inventory details. Handling
edge cases, such as attempting to sell more items than available in stock, became a critical part of the
implementation to ensure reliability.*/
#include<iostream>
using namespace std;

class item
{
    int itemid;
    string itemname;
    float price;
    int quantity;
public:
    item()
    {
        itemid=0;
        price=0;
        quantity=0;
    }
    item(int id,string name,float p,int quantity)
    {
        itemid=id;
        itemname=name;
        price=p;
        this->quantity=quantity;
    }
    void AddStock(int quantity)
    {
        cout<<"Stock added"<<endl;
        this->quantity+=quantity;
    }
    void DisplayDetails()
    {
        cout<<"Item Id: "<<itemid<<endl; 
        cout<<"Item name: "<<itemname<<endl;
        cout<<"Price: "<<price<<endl;
        cout<<"Quantity: "<<quantity<<endl<<endl;
    }
    void SellProduct(int quantity)
    {
        this->quantity-=quantity;
        cout<<"Sold:"<<endl;
        cout<<"Name: "<<itemname<<endl;
        cout<<"Quantity: "<<quantity<<endl<<endl;
    }
};

int main()
{
    int i;
    item s[3];
    s[0]=item(1,"Milk",35,5);
    s[1]=item(2,"Curd",20,5);
    s[2]=item(3,"cheese",50,5);
    for(i=0;i<3;i++)
    {
        s[i].DisplayDetails();
    }
    s[0].AddStock(5);
    s[0].DisplayDetails();
    s[1].SellProduct(3);
    s[1].DisplayDetails();
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}