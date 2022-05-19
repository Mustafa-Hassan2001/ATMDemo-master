/*
Program: ATM Demo
Description: Program that assumes end user has already entered an ATM card.  After entering PIN number the end user can select the type of account either
Checking or Savings account and make a deposit or withdraw. Then it prints the results with the new balance after each transaction.
*/
// Libraries
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <iomanip> //allows math round to decimal places

using namespace std;
// Declare class BankAccount
class BankAccount {
   // Declare variables
 private:
   string pinNum;
   char accType;
   double balance;
   double amount;

public:
   // Constructor of BankAccount
   BankAccount(){
      // Initialize balance and amount variables
      balance = 0.0;
      amount = 0.0;
   }

   // Declare functions prototypes
   void pinNumber();
   void accountType();
   void balanceChecking();
   void balanceSavings();
   void deposit();
   void withdraw();
   void display();
}; // End class BankAccount

// Function to retrieve pinNumber from end user
void BankAccount::pinNumber()
{
   cout << "________________________________________________________________________________";
   cout << "\n\t\t\t        ATM DEMO PROJECT" << endl;
   cout << "________________________________________________________________________________";
   //prompts end user for the pin number to access bank account
   cout << "\n\t\t\t        ENTER PIN NUMBER: \n" <<endl;
   cout << "\t\t\t\t      ";

   // For loop to allow user to re-enter pin 4 times if it is invalid
   for(int i = 0; i <= 3; i++) {
     // Mask pinNum with asterisks
     char ch;
     cout << setw(1); // Output formatting space
     ch = _getch();
     while(ch != 13){
        pinNum.push_back(ch); //push pinNum and replace with asterisk
        cout << '*';
        ch = _getch();
     }

      // Set pinNum to 1234
      if(pinNum == "1234") {
         cout << "\n\n\t\t\t   Welcome to your account!" << endl;
         // Display options menu if pinNumber is correct
         display();

         // Verify if pinNum contains only intergers
         while(!(cin >> pinNum)) {
            // Reset the input
            cin.clear();
	      // Get string input
	       while (cin.get() != '\n')
              continue;
           // Ask user to try again:
           cout << "\n\t\t\t   Please enter a numeric Pin:  ";
         } // End while cin

      // Allow user to re-enter pinNum 4 times before locking account
    } else if (i >= 4) {
         cout << "\n\t\t\t   You account is Locked!\n";
      	 cout << "\t\t\t   You have reached the limit of tries." << endl;
         // If user enters any numeric invalid pin, allow to re-enter pin
      } else {
         cout << "\n\t\t\t   Invalid Pin Number \n";
         cout << "\t\t\t   Enter Pin Number Again: \n";
         cout << "\t\t\t\t   ";
         cin >> pinNum;
      }// End else
   }// End for loop pinNum
}// End pinNumber function

// Function to retrieve account type from end user
void BankAccount::accountType(){
  cout << "\n\t\t\t Select Account Type:\n";
  cout << "\t\t\t Checking 'C' or Savings 'S': ";
  cin >> accType;

  // If C or c is entered display Checking Account
  if(accType == 'C' || accType == 'c') {
     cout << "\t\t\t================================" << endl << endl;
     cout << "\t\t\t\tChecking Account" << endl << endl;
     cout << "\t\t\t================================" << endl << endl;
  // Else if S or s is entered display Savings Account
  } else if (accType == 'S' || accType == 's') {
     cout << "\t\t\t================================" << endl << endl;
     cout << "\t\t\t\tSavings Account" <<endl << endl;
     cout << "\t\t\t================================" << endl << endl;
  } else {
    cout << "\t\t\tInvalid Account Type.\n";
    cout << "\t\t\tSelect Account Type: 'C' or 'S': ";
    cin >> accType;
  }
}// End getAccountType function

// Deposit function
void BankAccount::deposit(){
   cout << "\n\t\t\t\t    DEPOSIT\n";
   cout << "\t\t\t   Enter Deposit Amount $";
   cin >> amount;
   cout << "\n\t\t\t========Deposit Receipt========" << endl << endl;
   cout << setprecision(2) << fixed; //round decimal 2 places
   cout << "\t\t\t Amount Deposited = $" << amount << endl << endl;
   balance += amount;
   cout << "\t\t\t New balance $" << balance << endl << endl;
   cout << "\t\t\t===============================" << endl;
}// End deposit function

// Withdraw function
void BankAccount::withdraw(){
  cout << "\n\t\t\t\t    WITHDRAW\n";
  cout << "\t\t\t   Enter Withdraw Amount $";
  cin >> amount;
  cout << "\n\t\t\t=======Withdraw Receipt==========" << endl << endl;
  cout << "\t\t\t Amount withdrawn = $" << amount << endl << endl;
  balance -= amount;
  cout << "\t\t\t New balance $" << balance << endl <<endl;
  cout << "\t\t\t=================================" << endl;
}// End withdraw function

// Function to display Checking account balance
void BankAccount::balanceChecking() {
   cout <<"\n\t\t\t=====Checking Account Balance=====";
   cout << "\n\t\t\t Checking Account # xxxxxxxx4567\n";
   //balance = 10000;
   cout << "\n\t\t\t Balance = $" << balance << endl;
   cout <<"\n\t\t\t==================================" << endl;
}// End getBalanceChecking function

// Function to display Savings account balance
void BankAccount::balanceSavings() {
  cout << "\n\t\t\t=====Savings Account Balance=====";
  cout << "\n\t\t\t Savings Account # xxxxxxxx8901\n";
  //balance = 25000;
  cout << "\n\t\t\t Balance = $" << balance << endl;
  cout << "\n\t\t\t=================================" << endl;
}// End balanceSavings function

// Display options menu after entering pin number
void BankAccount::display(){
  int options = 1;
     // While options is not zero allow enduser to select an option to access bankaccount
      while( options != 0 ) {
        cout << "\n\t\t\t  1. Select Account Type\n";
        cout << "\t\t\t  2. Deposit\n";
        cout << "\t\t\t  3. Withdraw\n";
        cout << "\t\t\t  4. Checking Account Balance\n";
        cout << "\t\t\t  5. Savings Account Balance\n";
        cout << "\t\t\t  0. End Transactions\n";
        cout <<"\n\t\t\t\t\t";
        cin >> options;

       // Switch statement to call functions based on end user selected option
        switch (options) {
          case 0: pinNumber();
          break;
          case 1: accountType();
          break;
          case 2: deposit();
          break;
          case 3: withdraw();
          break;
          case 4: balanceChecking();
          break;
          case 5: balanceSavings();
          break;
          default: cout << "\n\t\t\t   Invalid Option" << endl;
        }
      }
}

int main()
{
  // Change screen text color
  system("color 0b");
   // Declare BankAccount Object
   BankAccount bank;
   // Call functions
   bank.pinNumber();
   bank.accountType();
   bank.balanceChecking();
   bank.balanceSavings();
   bank.deposit();
   bank.withdraw();

   return 0;
}
