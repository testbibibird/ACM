#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
	map<char , int> sound;
	sound['B']=1;
	sound['F']=1;
	sound['P']=1;
	sound['V']=1;
	sound['C']=2;
	sound['G']=2;
	sound['J']=2;
	sound['K']=2;
	sound['Q']=2;
	sound['S']=2;
	sound['X']=2;
	sound['Z']=2;
	sound['D']=3;
	sound['T']=3;
	sound['L']=4;
	sound['M']=5;
	sound['N']=5;
	sound['R']=6;
	
	string a;
	bool key;

	while(cin>>a)
	{
		key = true;

		if(a.size()==1&& sound[a[0]])	
		{
			cout<<sound[a[0]]<<endl;
			continue;
		}
		if( a.size()==1)	{cout<<endl;continue;}
		if( sound[a[0]] != 0 && sound[a[0]] != sound[a[1]])	{cout<<sound[a[0]];key=false;}

		if(key&&sound[a[0]])	cout<<sound[a[0]];

		for(int i = 1 ; i < a.size()  ; ++i )
		{
			if( sound[a[i]] != 0 && sound[a[i]] != sound[a[i-1]] )
			{
				cout<<sound[a[i]];
			}
		}

		//if( sound[a[ a.size()-1 ]] != sound[a[a.size()-2]] && sound[a[a.size()-1]] != 0 )	cout<<sound[a[a.size()-1]];

		cout<<endl;
	}

		
}