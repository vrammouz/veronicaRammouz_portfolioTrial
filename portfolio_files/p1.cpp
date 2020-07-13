//Program 1

#ifndef classMatrix22_h
#define classMatrix22_h			//defining class on separate page

class Matrix22
{
private:
	int a;
	int b;
	int c;
	int d;					//data members	

public:

Matrix22(int A, int B, int C, int D)	//A constructor which takes the four defining entries of the matrix as arguments
		{
		a=A;
		b=B;
		c=C;
		d=D;
		}
	
	Matrix22()		//A constructor with no arguments which sets all the    	                four entries of the matrix to zeros
	{
		a=0;
		b=0;
		c=0;
		d=0;
	}
	
	void print();
	int determinant();
	Matrix22 add(Matrix22);
	Matrix22 multiply(Matrix22);	//member functions
};
#endif


#include<iostream>
#include "classMatrix22.h"
using namespace std;

void Matrix22::print()		//print matrix	
	{
	cout<<a<<"\t"<<b<<"\n"<<c<<"\t"<<d<<endl;		
	}

int Matrix22::determinant()		//member function which calculates and returns 						the determinant of the matrix
	{
	int det;
	det=(a*d)-(b*c);
	return det;
	}

Matrix22 Matrix22::add(Matrix22 N)		//member function that adds two Matrices							 M and N and store the result in a third 							matrix P
	{	
		Matrix22 P;

		P.a=a+(N.a); 
		P.b=b+(N.b);
		P.c=c+(N.c);
		P.d=d+(N.d);

		return P;
	}
	
Matrix22 Matrix22::multiply(Matrix22 N) 	//member function that multiplies two 							Matrices M and N and store the result in 							a third matrix P
	{
		Matrix22 P;

		P.a= (N.a)*a + (N.c)*b;
		P.b= (N.b)*a + (N.d)*b;
		P.c= (N.a)*c + (N.c)*d;
		P.d= (N.b)*c + (N.d)*d;

		return P;
	}			







#include<iostream>
#include "classMatrix22.h"
using namespace std;

int main()
{
	Matrix22 M(1,2,3,4), N (5,6,7,8) , P;		//defining matrices

		cout<< "M:"<<endl;
			M.print();
				cout<<endl<<endl;

		cout<< "N:"<<endl;
			N.print();
				cout<<endl<<endl;
	
		cout<<"det(M) ="<<M.determinant();		//det(M)
			cout<<endl<<endl;
	
			P = M.add(N);			//P=M+N
				cout<<"P (sum):"<<endl;
					P.print();
						cout<<endl<<endl;

		P = M.multiply(N);			//P=M*N
			cout<<"P (product):"<<endl;
				P.print();
					cout<<endl<<endl;

	system ("pause");
	return 0;
}
