
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<typename T>
class Shrey
{
protected:
    vector<T>arr;
    int size;
public:
    Shrey()
    {
        cout<<"enter size :";
        cin >> size;
        cout<<"enter elements of array: "<<endl;
        arr.resize(size);

        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        cout<<endl<<endl;
    }
    void FindMax()
    {
        T Max = *max_element(arr.begin(),arr.end());
        cout<<"Maximum Value: "<<Max<<endl<<endl;
        cout<<"original array: "<<endl;
        Display();
    }
    void Reverse()
    {
        reverse(arr.begin(),arr.end());
        cout<<"Reversed Array: "<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl<<endl<<endl;
    }
    void Display()
    {
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl<<endl;
    }
};

int main()
{
    cout<<"----- For INTEGER -----"<<endl;
    Shrey<int>I;
    I.FindMax();
    I.Reverse();

    cout<<"----- For FLOAT -----"<<endl;
    Shrey<float>F;
    F.FindMax();
    F.Reverse();

    cout<<"----- For CHARACTER -----"<<endl;
    Shrey<char>C;
    C.FindMax();
    C.Reverse();
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
