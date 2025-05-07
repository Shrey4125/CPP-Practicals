/*Question : A small retail store is facing challenges in managing its inventory effectively. The store sells a
variety of products, each identified by a unique product ID, a name, the available quantity in
stock, and the price per unit. To streamline their operations, the store needs a basic system to
manage this inventory efficiently.
The system must provide the ability to add new products to the inventory, ensuring that each
product has its ID, name, quantity, and price properly recorded. Additionally, the system should
allow the store staff to update the quantity of any existing product, such as when new stock
arrives or when items are sold.
Another essential feature of the system is the calculation of the total value of all products in
the inventory, which is determined by multiplying the quantity of each product by its price and
summing these values for all products.

The store management is exploring two approaches for this system: a procedural approach and
an object-oriented approach. The goal is to evaluate these approaches by comparing their ease
of implementation, code reusability, and overall complexity.
The system's design and implementation should consider these requirements and provide an
effective solution (either procedural approach or an object-oriented approach) to the store's
inventory management problems.*/
#include<iostream>
using namespace std;

struct Product{
    int id, quantity;
    string name;
    float price;
    float total;
};

void AddNewProduct(Product *p, int n){
    for(int i=0; i<n; i++){
        cout<<"For Product "<<i+1<<":"<<endl;
        cout<<"Enter Product ID: ";
        cin>>p[i].id;
        cout<<"Enter Product Name: ";
        cin>>p[i].name;
        cout<<"Enter Product Quantity: ";
        cin>>p[i].quantity;
        cout<<"Enter Product Price: ";
        cin>>p[i].price;
    }
}

void CalculateTotalPrice(Product *p, int n){
    float Total=0;
    for(int i=0; i<n; i++){
        Total+=p[i].price*p[i].quantity;
    }
    cout<<"Total value of inventory: "<<Total<<endl;
}

void Display(Product *p,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Product "<<i+1<<" Detials :"<<endl;
        cout<<"ID : "<<p[i].id<<endl;
        cout<<"Name: "<<p[i].name<<endl;
        cout<<"Price: "<<p[i].price<<endl;
        cout<<"Quantity: "<<p[i].quantity<<endl<<endl;
    }
}
void UpdateQuantity(Product *p, int n){
    int Id, quantity;
    cout<<"Enter Product ID: ";
    cin>>Id;
    cout<<"Enter New Quantity: ";
    cin>>quantity;
    for(int i=0; i<n; i++){
        if(Id==p[i].id){
            p[i].quantity=quantity;
         //   cout<<"Updated quantity of Product "<<p[i].id<<" to "<<p[i].quantity<<endl;
        }
    }
}

int main(){
    int n,op;
    cout<<"Enter Number of Products: ";
    cin>>n;
    Product *p=new Product[n];
    AddNewProduct(p,n);
    Display(p,n);
    CalculateTotalPrice(p,n);
    cout<<"To Update Quantity Enter 1, else 0:";
    cin>>op;
    switch(op)
    {
    case 0:
        cout<<"No quantity updated"<<endl;
        break;
    case 1:
        cout<<"Update Quantity: "<<endl;
        UpdateQuantity(p,n);
        CalculateTotalPrice(p, n);
        break;
    }
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
