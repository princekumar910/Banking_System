#include <bits/stdc++.h>
using namespace std;
class Bank_Account
{
private:
  
    char name[20];
    double Acc_no;
    string type_of_account;
    int Amount;

public:
  static int count;
    void New_Registration();
    void deposit(int deposit);
    void withdraw(int amount);
    void Info();
    int find(int Account_No, Bank_Account Obj[]);
};
int Bank_Account :: count = 0 ;
void Bank_Account ::New_Registration()
{   cin.ignore(); // clear the input buffer 
    cout << "Enter Your Name : ";
    cin.getline(this->name , 20);
    cout << "Enter Account Number : ";
    cin >> this->Acc_no;
    cout << "Enter Your type of account  : ";
    cin >> this->type_of_account;
    cout << "Enter Your amount : ";
    cin >> this->Amount;
    count++ ;
}
void Bank_Account ::deposit(int deposit)
{
    cout << "your previous balance : " << this->Amount<<endl;
    this->Amount = this->Amount + deposit;
    cout << "your New balance : " << this->Amount<<endl;
}
void Bank_Account ::withdraw(int amount)
{   if(amount > this->Amount){
    cout<<"insuffient balance"<<endl;
    return;
}
    cout << "Your current balance is : " << this->Amount;
    this->Amount = this->Amount - amount;
    cout << "Your balance after withdrawal : " << this->Amount;
}
void Bank_Account ::Info()
{
    cout << "Name         : " << this->name << endl;
    cout << "Account No.  : " << this->Acc_no << endl;
    cout << "Amount       : " << this->Amount << endl;
    cout << "Account type : " << this->type_of_account << endl;
}
int Bank_Account ::find(int Account_No, Bank_Account Obj[])
{
    int i;
    for (i = 0; i < count; i++)
    {
        if (Account_No == Obj[i].Acc_no)
        {
            return i ;
        }
    }
    return -1;
}

int main()
{
    Bank_Account Customer[50];
    // Bank_Account b1;
    // Customer[0].New_Registration();
    int choice = 0;
    int account_number;
    while(choice != 5){
        cout << "Enter your choice : \n"
         << "1. To Know the status. \n"
         << "2. To deposit.\n"
         << "3. To withdraw.\n"
         << "4. New Registration.\n"
         << "5. Exit.\n"
         << endl;
    cin >> choice;
    switch (choice)
    {
         int index ;
    case 1:
        cout << "Enter Your account Nummber : ";
        cin >> account_number;
        index = Customer[0].find(account_number, Customer);
          if (index != -1) {
                Customer[index].Info();
            } else {
                cout << "Account not found!" << endl;
            }
        break;
    case 2:
        cout << "Enter Your account Nummber : ";
        cin >> account_number;
        index = Customer[0].find(account_number, Customer);
       if (index != -1) {
                int deposit;
                cout << "Enter Amount to Deposit: ";
                cin >> deposit;
                Customer[index].deposit(deposit);
            } else {
                cout << "Account not found!" << endl;
            }
        break;
    case 3:
        int amount;
        cout << "Enter Your account Nummber : ";
        cin >> account_number;
        index = Customer[0].find(account_number, Customer);
        if (index != -1) {
                int amount;
                cout << "Enter Amount to Withdraw: ";
                cin >> amount;
                Customer[index].withdraw(amount);
            } else {
                cout << "Account not found!" << endl;
            }
        break ;
    case 4:
       Customer[Bank_Account::count].New_Registration() ;
       break ;
       case 5:
       cout<<"Exiting..."<<endl;
       default :
       cout<<"Invalid Choice !"<<endl;
    }
    }
    return 0;
}