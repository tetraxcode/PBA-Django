#include <bits/stdc++.h>

using namespace std;

//main function

int main() {

// variables to store input and calculate price change and mortgage

int current_price,last_price,change;

float mortgage=0;

cout<<"Please enter the current month price:";

//reading current month price

cin>>current_price;

cout<<"Please enter the last month price:";

//reading last month price

cin>>last_price;

// calculating difference

change=current_price-last_price;

 // calculating mortgage

mortgage=(current_price*0.045)/12;

//printing output

cout<<"The change is $"<<change<<" since last month."<<endl;

cout<<"The estimated monthly mortgage is $"<<mortgage<<endl;

return 0;