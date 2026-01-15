#include<iostream>
using namespace std;

// Abstract Class
class ATMInterface {
public:
	virtual void checkBalance() = 0;
	virtual void deposit(double amount) = 0;
	virtual void withdraw(double amount) = 0;
	virtual ~ATMInterface() {}  // virtual destructor for cleanup
}; 

class BankAccount : public ATMInterface{
private:
	double balance; // Hidden data 
	
public:
	BankAccount(double initialBalance = 0) {
		balance = initialBalance;
	}
	void checkBalance() override {
	    cout<<"Current Balance: rs"<<balance <<endl;
	}
	
	void deposit(double amount) override {
	    if(amount > 0) {
	    	balance += amount;
	    	cout<<"rs "<<amount <<"deposited successfully."<<endl;
		} else {
			cout<<" Invalid deposite amount."<<endl;
		}
	}
	void withdraw(double amount) override {
	    if (amount <= 0) {
	    	cout<<"Invalid withdrawl amount."<<endl;
		}else if(amount > balance) {
			cout<<"Insufficent funds."<<endl;
		}else {
			balance  -= amount;
			cout<<"rs"<<amount <<"withdrawn successfully."<<endl;
		}
	}
};

int main() {
	BankAccount userAccount(2000);  //intial balance
	int choice;
	double amount;
	
	do {
		cout<<"\n==========ATM MENU ===========\n";
		cout<<"1. Check Balance\n";
		cout<<"2. Deposite Balance\n";
		cout<<"3. Withdraw Money\n";
		cout<<"4. Exit\n";
		
		cout<<"Enter your choice:";
		cin>>choice;
		
		switch(choice) {
			case 1:
				userAccount.checkBalance();
				break;
			case 2:
				cout<<"Enter amount to deposit: rs";
				cin>>amount;
				userAccount.deposit(amount);
				break;
			case 3:
				cout<<"Enter amount towithdraw: rs";
				cin>>amount;
				userAccount.withdraw(amount);
				break;
			case 4:
				cout<<"Thank you for using the ATM!"<<endl;
				break;
			default:
				cout<<"Invalid choice. Pleasetry again."<<endl;
		}
	} while(choice != 4);
	return 0;
}
