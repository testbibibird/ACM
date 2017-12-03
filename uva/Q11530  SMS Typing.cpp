#include<iostream>
#include<string>

using namespace std;

int arr[26]={1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};

int main()
{
	string a;
	int n,count,num=1;

	cin>>n;getline(cin,a);

	while(n--)
	{
		getline(cin,a);

		count=0;

		for(int i = 0 ; i < a.size() ; ++i )
		{
			if(a[i]==' ')	++count;
			
			else count+=arr[a[i]-'a'];
		}

		cout<<"Case #"<<num++<<": "<<count<<endl;
	}
}