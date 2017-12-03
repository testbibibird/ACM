#include<iostream>
#include<string>

using namespace std;

int main()
{
	string l1,l2;
	int n;
	bool key;
	char dot[4]="...";

	cin>>n;

	getline(cin,l1);
	
	while(n--)
	{
		string s2,s3,s4,s5;
		int i;
		
		getline(cin,l1);
		getline(cin,l2);
		
		key = false;

		for( i = 0 ; l1[i] != '<' ; ++i )
		{
			cout<<l1[i];
		}
		++i;
		for( ; l1[i] != '>' ; ++i )
		{
			cout<<l1[i];
			s2.push_back(l1[i]);
		}
		++i;
		
		for( ; l1[i] != '<' ; ++i )	
		{
			cout<<l1[i];
			s3.push_back(l1[i]);
		}
		++i;
		
		for( ; l1[i] != '>' ; ++i )	
		{
			cout<<l1[i];
			s4.push_back(l1[i]); 
		}
		++i;
		for( ; i < l1.size() ; ++i)
		{
			cout<<l1[i];
			s5.push_back(l1[i]);
		}

		cout<<endl;
		l2.erase( l2.begin()+l2.find(dot) , l2.end() );
		cout<<l2<<s4<<s3<<s2<<s5<<endl;
	}
	
}