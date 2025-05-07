#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

template <typename T>

inline void Max(vector<T>&a)
{
    T Max=*max_element(a.begin(),a.end());
    cout<<"Maximum Value: "<<Max<<endl;
}

template <typename T>
void Reverse(vector<T>&a)
{
    reverse(a.begin(),a.end());
    cout<<"Reversed array: ";
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl<<endl;
}

template <typename T>
void Basic(vector<T>&a)
{
    int size;
    cout<<"Enter Size: ";
    cin>>size;
    a.resize(size);
    for(int i=0;i<size;i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        cin>>a[i];
    }
    cout<<"Original Array: ";
    for(int i=0;i<size;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    Max(a);
    Reverse(a);
}
int main()
{
    cout<<"INTEGER COLLECTION:"<<endl;
    vector<int>I;
    Basic(I);

    cout<<"FLOAT COLLECTION:"<<endl;
    vector<float>F;
    Basic(F);

    cout<<"CHARACTER COLLECTION:"<<endl;
    vector<char>C;
    Basic(C);
    cout<<endl<<endl<<"24CE106-Shrey Rathod"<<endl;
    return 0;
}
