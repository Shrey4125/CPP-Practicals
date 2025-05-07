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

class Product{
    int Id, Quantity;
    string Name;
    float Price;
    public:
        void AddNewProduct(int id, string name, int quantity, float price){
            Id = id;
            Name = name;
            Quantity = quantity;
            Price = price;
            cout<<"New Product Added!!"<<endl;
        }
        void Display()
        {
            cout<<"Product "<<Id<<" Details:"<<endl;
            cout<<"ID: "<<Id<<endl;
            cout<<"Name: "<<Name<<endl;
            cout<<"Price: "<<Price<<endl;
            cout<<"Quantity: "<<Quantity<<endl;
            cout<<"Total Price: "<<CalculateTotalPrice()<<endl<<endl;
        }
        void ChangeQuantity(int quantity){
            Quantity = quantity;
            cout<<"Changed Quantity of product "<<Id<<" to "<<Quantity<<endl<<endl;
            cout<<"After Changing quantity:"<<endl;
            Display();
        }
        float CalculateTotalPrice(){
            float Total;
            Total=Quantity*Price;
            return Total;
            //cout << "Total Price: " << Quantity * Price << endl;
        }
};

int main(){
    Product p1,p2;
    p1.AddNewProduct(1,"Milk",10,100);
    p1.Display();
    p2.AddNewProduct(2,"Sugar",12,240);
    p2.Display();
    p1.ChangeQuantity(20);
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
}
