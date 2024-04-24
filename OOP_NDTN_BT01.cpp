#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
//C++14
class BankAccount{
protected:
	string id;
	string CusName;
	string idCard;
	double balance;
public:
	BankAccount(string _id="000000",string _name="No name",string _idCard="xxx",double _balance=0){
		id=_id;
		CusName=_name;
		idCard=_idCard;
		balance=_balance;
	}
	BankAccount(BankAccount & a){
		id=a.id;
		CusName=a.CusName;
		idCard=a.idCard;
		balance=a.balance;
	}
	virtual bool Withdraw(double WithdrawMoney){};
	virtual double Deposit(double dmoney){}
	string toString(){
		string a="";
		a=a+"{";a=a+id;a=a+"}:{";a=a+CusName;a=a+"}:{";
		a=a+to_string(int(balance));a=a+"}";
		return a;
	}
	virtual double WLimit(){}
	virtual void get(string in4){}
	void get_balance(double dmoney){
		balance=Deposit(dmoney);
	}
};

class CheckingAccount:public BankAccount{
	double OverDraftLimit;
public:
	CheckingAccount(string _id="000000", string _name="No name", string _idCard="xxx", double _balance=0, double _overDraftLimit=50000):BankAccount(_id,_name,_idCard,_balance){
		OverDraftLimit=_overDraftLimit;
	}
	CheckingAccount(CheckingAccount & a):BankAccount(a){
		OverDraftLimit=a.OverDraftLimit;
	}
	double WLimit(){
		return balance+OverDraftLimit;
	}
	bool Withdraw(double WithdrawMoney){
		return WithdrawMoney<=WLimit();
	}
	void get(string in4){
		int n=0;
		int v[n];
		for(int i=0; i<in4.size(); i++) if(in4[i]=='/') v[n++]=i;
		id=in4.substr(0,v[0]-0);
		CusName=in4.substr(v[0]+1,v[1]-v[0]-1);
		idCard=in4.substr(v[1]+1,v[2]-v[1]-1);
		balance=stod(in4.substr(v[2]+1,v[3]-v[2]-1));
		OverDraftLimit=stod(in4.substr(v[3]+1,v[4]-v[3]-1));
	}
	double Deposit(double dmoney){
		balance-=dmoney;
	}
};

class SavingAccount: public BankAccount{
	double InterestRate;
	double InterestMoney;
public:
	SavingAccount(string _id="000000", string _name="No name", string _idCard="xxx", double _balance=0, double _interestRate=0, double _interestMoney=0):BankAccount(_id,_name,_idCard,_balance){
		InterestRate=_interestRate;
		InterestMoney=_interestMoney;
	}
	SavingAccount(SavingAccount&a):BankAccount(a){
		InterestRate=a.InterestRate;
		InterestMoney=a.InterestMoney;
	}
	double Deposit(double dmoney){
		balance+=dmoney;
	};
	double WLimit(){
		return balance;
	}
	bool Withdraw(double WithdrawMoney){
		return WithdrawMoney<=WLimit();
	}
	void get(string in4){
		int n=0;
		int v[n];
		for(int i=0; i<in4.size(); i++) if(in4[i]=='/') v[n++]=i;
		id=in4.substr(0,v[0]-0);
		CusName=in4.substr(v[0]+1,v[1]-v[0]-1);
		idCard=in4.substr(v[1]+1,v[2]-v[1]-1);
		balance=stod(in4.substr(v[2]+1,v[3]-v[2]-1));
	}
	double laisuat(){
		if(balance<1000000) balance*=1.1;
		else if(balance>=1000000&&balance<50000000) balance*=1.3;
		else if(balance>=50000000&&balance<200000000) balance*=1.5;
		else if(balance>=200000000&&balance<1000000000) balance*=2;
		else balance*=2.94;
	}
};
int main(){
	CheckingAccount a;
	SavingAccount b;
	char c;
	string in4;
	double amount;	

	cin>>c>>in4>>amount;
	if(c=='C'){
		a.get(in4);
		cout<<a.toString()<<endl;
		if(a.Withdraw(amount)){
			cout<<"Yes ";
			a.get_balance(amount);
			cout<<a.toString()<<endl;
		}else{
			cout<<"No\n";
		}
		cout<<"Checking Account";		
	}else if(c=='S'){
		b.get(in4);
		cout<<b.toString()<<endl;
		if(b.Withdraw(amount)){
			cout<<"Yes ";
			b.get_balance(amount*-1);
			cout<<b.toString()<<endl;
		}else{
			cout<<"No\n";
		}
		b.laisuat();
		cout<<b.toString();
	}
	return 0;
}
