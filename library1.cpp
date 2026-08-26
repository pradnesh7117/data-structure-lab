include<iostream>
#include<string>
using namespace std;
int main()
{
int id1,id2,id3;
string title1,title2,title3;

//book 1
cout<<"enter book 1 ID:";
cin>>id1;

cin.ignore();
cout<<"enter book 1 title:";
getline(cin,title1);

//book2
cout<<"enter book 2 ID:";
cin>>id2;

cin.ignore();
cout<<"enter book 2 title:";
getline(cin,title2);

//book3
cout<<"enter book 3 ID:";
cin>>id3;

cin.ignore();
cout<<"enter book 3 title:";
getline(cin,title3);

//Display
cout<<"\n\n ==============library";
cout<<"\n\n Book ID1="<<id1;
cout<<"\t Book Title1 ="<<title1;
cout<<"\n Book ID2="<<id2;
cout<<"\t Book Title2 ="<<title2;
cout<<"\n\n Book ID3="<<id3;
cout<<"\t Book Title3="<<title3;
cout<<"\n\n===============";
return 0;
}
