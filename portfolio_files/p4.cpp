#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	//Open read and write files
    fstream inf;
    inf.open("num.txt", ios::in);
	fstream outf;
	outf.open("below.txt", ios::out|ios:: binary);
		
	//Check if files can be opened
    if (!inf || !outf)
		{
			cout << "File(s) could not be opened." << endl;
            return 1;
        }

	int num;
	int count = 0;
	float sum = 0;
	float avg = 0;
	int countNum[100] = {0};
	int max = 1;

	while (inf >> num)
		{
			/*Calculate and display count of odd and even numbers
			+ display their average*/
			++count;	
			sum = sum + num;
			avg = sum / count;
			
			/*Write numbers below average
			in a new file below*/
			if (num < avg)
				outf.write(reinterpret_cast<char*>(&num), sizeof(num));
	
			/*Find the number with the highest frequency and
			find how many times it showed up*/
			for  (int i=0; i<100; i++)	
			{
				if (num == i)
					countNum[i]++;
						
				if (countNum[i] > countNum[max])
					max = i;
			}	
		}	

		cout << "Count of odd and even numbers: " << count << endl
			<< "Average of all numbers: " << setprecision(3) << avg << endl
			<< "Most frequent number: " << max << " (repeated " << countNum[max] << " times)" << endl;

        return 0;
}
