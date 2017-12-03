#include<iostream>

using namespace std;

struct node
{
	int area;
	int number;
	int grade;
};

int main()
{

	int num,c,total;
	node farm[20];
	
	cin>>c;

	while(c>0)
	{
		cin>>num;

		total=0;

		for(int i=0;i<num;++i)
		{
			cin>>farm[i].area>>farm[i].number>>farm[i].grade;
		
			total+=farm[i].area*farm[i].grade;
		}
		
		cout<<total<<endl;

		--c;
	}
}
