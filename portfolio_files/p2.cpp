#include <cstring>
#ifndef classPatient_h
#define classPatient_h

class Patient
{
private:
	char name[41];
	char gender;
	char email[81];
	double weight;
	double height;

public:
//A constructor with default arguments
	Patient(char n[40]="\0", char g='F', char e[81]="\0", double w=50.0, double h=1.65)		
	{	setName(n);
		setGender(g);
		setEmail(e);
		setWeight(w);
		setHeight(h);		//All set functions with the integrity checks
	}

	void setName(char n[])
	{	int len; 
		len=strlen(n); 
			
		strncpy(name, n, len);		
		name[len]='\0';				
				 
		if (len>41) 
strcpy(name, " ");			//if different from [0,40] characters, display blank
	}
	void setGender(char g)
{	gender = (g=='M' || g=='F' ? g : 'F');		//default gender: 											female			}
	void setWeight(double w)
	{	weight = (w>=3.5 && w<=150 ? w : 50.0);		//weight between 3.5 										kg and 150 kg
	}
	void setHeight(double h)
	{	height= (h>=0.50 && h<=2.20 ? h : 1.65);
	}
	void setEmail(char e[])
	{	int a=0;
		int d=0;

		for (int i=0;e[i]!='\0';i++)
			{	if (e[i]=='@')
				a++;
				if (e[i]=='.')
				d++;
			}

		if (a>1 || d<1)
			strcpy(email, " ");
		else
		{	int len;
			len=strlen(e);

			strncpy(email,e,len); 
			email[len]='\0';
		}
	}	
	
	char* getName(){return name;}
	char getGender(){return gender;}
	char* getEmail(){return email;}
	double getWeight(){return weight;}
	double getHeight(){return height;}
	double calculateBMI();
	void printPatientInfo();
};
#endif
















#include "classPatient.h"
#include<iostream>

using namespace std;

double Patient::calculateBMI()
{
	double BMI;
		BMI=weight/(height*height);		//calculation of BMI

	return BMI;
}

void Patient::printPatientInfo()		//member function to print patients' 							information
{
	cout<<"Name: "<<name<<endl;
	cout<<"Gender: "<<gender<<endl;
	cout<<"Email: "<<email<<endl;
	cout<<"Weight = "<<weight<<" kg"<<endl;
	cout<<"Height = "<<height<<" m"<<endl;
	cout<<"Body Mass Index = "<<calculateBMI()<<" kg/m^2"<<endl;

	if (calculateBMI()<18.5)
		cout<<name<<" is underweight"<<endl<<endl;
	else
		if(calculateBMI()>=18.5 && calculateBMI()<=24.9)
			cout<<name<<" is healthy"<<endl<<endl;
		else
			if(calculateBMI()>=25 && calculateBMI()<=29)
				cout<<name<<" is overweight"<<endl<<endl;
			else 
				if(calculateBMI()>=30)
					cout<<name<<" is obese"<<endl<<endl;
}	


