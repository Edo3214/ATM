#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<conio.h>
using namespace std;
class ATM {
   string name;
   int account_number,current_amount;
public:
   ATM(string a, int b) : name(a), account_number(b) {
      cout << "Account created successfully \n";
    }
    int get_account_number(){return account_number;}
    int get_current_amount(){return current_amount;}
    void add_amount(int amount){current_amount=current_amount+amount;}
};
vector<ATM*> accounts; 
void create_account(string name , int account_number){accounts.push_back(new ATM(name, account_number));}
int find_account(int );
void account_balance(int state){cout<<"You have "<<accounts[state]->get_current_amount()<<" Euros \n";}
void add(int state);
void withdraw(int state);
int main(){ 
  int option=1,account_number,state,login_option=1;
  string name;
  while(option != 0)
  {
  	cout<<"Input 0 if you want to stop the program\n1 for creating an account\n2 to sign in\n";
  	cin>>option;
  	if(option==1){
  		cout<<"Input your name and surname,then account number of your choice\n";
  		cin.ignore();
  		cout<<"Name and surname: ";
  		getline(cin,name);
  		cin.clear();
  		cout<<"account number: ";
  		cin>>account_number;
  		create_account(name,account_number);
  		cout<<"press any key to continue\n";
  		_getch();
  		system("CLS");
	  }
  	if(option == 2){
  		cout<<"Input your account number\n";
  		cin>>account_number;
  		state=find_account(account_number);
  		if(state>=0){
  			login_option=1;
  			cout<<"You are signed in\n"<<"press any key to continue\n";
  			_getch();
  			while(login_option!=0)
  			{
			    if(option==2)
				{
					system("CLS");
					option++;  // since variable option is not used and it will be restarted,I will increment it
							  }			  
  				cout<<"Input 0 if you want to log out, if you want to check balance input 1\n";
  				cout<<"if you want to deposit money input 2\nif you want to withdraw money input 3\n";
  				cin>>login_option;
  				if(login_option==1)
  				account_balance(state);
  				else if(login_option==2)
  				add(state);
  				else if(login_option==3)
  				withdraw(state);
			  }
		  }
		  else
		  cout<<"Account with that account number does not exist!\n";
	  }
  }
   return 0;
}
int find_account(int account_number){
	for(int i=0;i<accounts.size();i++)
	{
		int gett;
	    gett=accounts[i]->get_account_number();
		if(account_number==gett)
		{
			return i;
			break;
		}
	}
  return -1;
}
void add(int state){
	cout<<"input the amount of money you want to deposit\n";
	int amount;
	cin>>amount;
	if(amount<0)
	amount=-1*amount;
    accounts[state]->add_amount(amount);                        //state=variable it represents index of vector
	cout<<"You deposited money successfully \n";
}
void withdraw(int state){
	cout<<"input the amount you want to withdraw\n";
	int amount,account_amount;
	cin>>amount;
	account_amount=accounts[state] -> get_current_amount();
	if(account_amount < amount){
		cout<<"You don't have enough funds in your account \n";
		return;
	}
	if(amount>0)
	amount=-1*amount;
	accounts[state]->add_amount(amount);
	cout<<"You have successfully withdrawn money \n";
}