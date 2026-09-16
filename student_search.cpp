#include<iostream>
using namespace std;
int main()
{
    int array[5];
    int roll;

    for (int i=0;i<5;i++)
        {
            cout<<"Enter roll number of student"<<i+1<<":";
            cin>>array[i];
        }
    cout<<"\n Enter the roll number of the student you want to search:";
    cin>>roll;

    for(int i=0;i<5;i++)
        {
            if(array[i]==roll)
            {
                cout<<"student found";
                return 0;
            }
        }
    cout<<"student not found";
    return 0;
}
