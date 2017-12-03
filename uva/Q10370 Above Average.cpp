#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int c;
	double n;
	int grade[1000];
	

	cin>>c;

	while(c>0)
	{
		double total=0;
		double average;
		double result;
		double count=0;
		
		cin>>n;

		for(int i=0;i<n;i++)
		{
			cin>>grade[i];
			total+=grade[i];
		}

		average=total/n;

		for(int i=0;i<n;i++)
		{
			if(grade[i]>average)
			{
				count++;
			}
		}

		result=(count/n)*100;

		cout.setf(ios::fixed);
		cout.precision(3);

		cout<<result<<"%"<<endl;

		--c;
	}

}