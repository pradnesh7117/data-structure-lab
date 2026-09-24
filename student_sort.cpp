#include<iostream>
using namespace std;
int main()
{
int marks[5];
cout<<"enter marks of 5 students:\n";
//in descending order
for(int i=0;i<5;i++)
{
    cin>>marks[i];
}
for(int i=0;i<4;i++)
    {
        for(int j=0;j<4-i;j++)
            {
                if(marks[j]<marks[j+1])
                {   int temp=marks[j];
                marks[j]=marks[j+1];
                marks[j+1]=temp;
                }
            }
    }
cout<<"students from higher marks to lower marks:\n";
for(int i=0;i<5;i++)
    {
        cout<<"student"<<i+1<<":"<<marks[i]<<endl;        
    }
return 0;
}
