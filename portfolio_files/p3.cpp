//The following program serves a bank institution 
//with keeping track of its customers' accounts
#include <iostream>
#include <cstring>
using namespace std;

class Account
{
	friend ostream &operator << (ostream &,Account &);
	
protected:
	int acc_nbr;
	char *name;
	float acc_balance;

public:
	Account(int ac_nb, char n[], float ac_b)
	{
		acc_nbr = ac_nb;
		name = new char [strlen(n) + 1];
		strcpy(name, n);
		acc_balance = ac_b;
	}

	Account (Account &a1)
	{
		acc_nbr = a1.acc_nbr;
		name = new char [strlen(a1.name) + 1];
		strcpy(name, a1.name);
		acc_balance = a1.acc_balance;
	}

	void operator = (Account &a1)
	{
		if (this != &a1)
		{
			acc_nbr = a1.acc_nbr;
			if( name != a1.name)
			{
				delete []name;
				name = new char [strlen(a1.name) + 1];
			}
			strcpy(name, a1.name);
			acc_balance = a1.acc_balance;
		}
	}

	virtual float getBankCharge(){return 0;}
	virtual float operator -= (float d){if( d <= acc_balance)
			acc_balance -= d;
		return acc_balance;}

	~Account(){delete []name;}
};

ostream &operator << (ostream &out, Account &a1)
{
	out << "Account Number: " << a1.acc_nbr << endl
		<< "Name: " << a1.name << endl
		<< "Account Balance: $" << a1.acc_balance;
	return out;
}

class Checking: public Account
{
private:
	float fixed_fees;

public:
	Checking(int ac_nb, char n[], float ac_b, float fix_f): Account(ac_nb, n, ac_b)
	{
		fixed_fees = fix_f;
	}

	float getBankCharge(){return fixed_fees;}
};

class Saving: public Account
{
private:
	float interest_earned;
	float taxRate;

public:
	Saving(int ac_nb, char n[], float ac_b, float earned, float tax): Account(ac_nb, n, ac_b)
	{
		interest_earned = earned;
		taxRate = tax;
	}

	float getBankCharge(){ return acc_balance*interest_earned/100*taxRate/100;}
};

class Credit: public Account
{
private:
	float max_limit;
	float interest_credB;

public:
	Credit(int ac_nb, char n[], float ac_b, float max_lim, float interestRate): Account(ac_nb, n, ac_b)
	{
		max_limit = max_lim;
		interest_credB = interestRate;
	}

	float getBanckCharge(){return acc_balance*(interest_credB/100);}

	float operator -= (float d)
	{
		if(d <= acc_balance && d <= max_limit)
		acc_balance -= d;

		else
			cout << "Account balance contains no such money."<<endl;
		return acc_balance;
	}

	bool operator == (Credit &a2)
	{
		if(max_limit == a2.max_limit)
			return true;
		else
			return false;
	}

	void print()
	{ 
		cout << static_cast<Account>(*this) << endl;
		cout << "Maximum limit to be withdrawn: $" << max_limit << endl
			<<"Yearly interest rate to be paid on credit balance: $" << interest_credB << endl;
	}
};

int main()
{
	Checking a1(52565, "Travis", 76.66, 25.2);
	Saving a2(52566, "Alexander", 82.2, 77.7, 50.3);
	Credit a3(52567, "Katheryn", 79.2, 60.1, 66.7);

	cout << a1 << endl;
	Account *checkPtr;
	checkPtr = &a1;
	cout << "Amount to be paid: $" << checkPtr -> getBankCharge() << endl << endl;
	checkPtr -> operator-= (6.2);
	cout << "Travis withdrew $6.2..." << endl << endl
		<< "Updated account details: " << a1 << endl << endl;

	cout << a2 << endl;
	Account *savPtr;
	savPtr = &a2;
	cout << "Amount to be paid: $" << savPtr -> getBankCharge() << endl << endl;
	savPtr -> operator-=(10.5);
	cout << "Alexander withdrew $10.5..." << endl << endl
		<<"Updated account details: " << a2 << endl << endl;

	a3.print();
	Account &crRef = a3;
	cout << "Amount to be paid: $" << crRef.getBankCharge() << endl << endl;
	crRef.operator-=(25.2);
	cout << "Katheryn withdrew $25.2..." << endl << endl;
	cout << "Updated account details: " << endl;
	cout << static_cast<Account>(a3) << endl << endl;

	return 0;
}

