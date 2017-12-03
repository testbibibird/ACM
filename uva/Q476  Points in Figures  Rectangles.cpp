#include<iostream>

using namespace std;

bool judge(int*,int ,int );

int main()
{
	char n;
	int i=0;
	double x, y;
	int count=1;
	int tok=0;

	pair<double,double> arr[20];

	while(cin>>n)
	{
		if(n=='*')	break;

		cin>>arr[i].first>>arr[i].second>>arr[i+1].first>>arr[i+1].second;

		i+=2;
	}

	while(cin>>x>>y)
	{
		tok=0;

		if(x==9999.9&&y==9999.9)	break;
	
		for(int j=0 ; j<i ; j+=2)
		{
			if(x > arr[j].first && x< arr[j+1].first && y>arr[j+1].second && y<arr[j].second)
			{
				cout<<"Point "<<count<<" is contained in figure "<<j/2+1<<endl;
				++tok;
			}
			else
			{
				//cout<<"Point "<<count<<" is not contained in figure "<<j/2+1<<endl;
			}
		}
		
		if(tok==0)
		{
			cout<<"Point "<<count<<" is not contained in any figure"<<endl;
		}

		++count;		
	}
}
