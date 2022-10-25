#include <iostream>
using namespace std;

int main() {
   int currentPrice;
   int lastMonthsPrice;
   
   cin >> currentPrice;
   cin >> lastMonthsPrice;

//importing Scanner class from util package
import java.util.Scanner;

//the class is named as LabProgram...so the file name
//should also be LabProgram.java
public class LabProgram {
public static void main(String[] args) {
Scanner scnr = new Scanner(System.in);
int currentPrice;
int lastMonthsPrice;

//taking currentPrice and lastMonthprice inputs
currentPrice = scnr.nextInt();
lastMonthsPrice = scnr.nextInt();

//concatenating the strings with variables using + operator
System.out.println("This house is $"+currentPrice+". The change is $"+(currentPrice - lastMonthsPrice)+" since last month.");
System.out.println("The estimated monthly mortgage is $"+((currentPrice * 0.051) / 12));
}
}

   return 0;
}
