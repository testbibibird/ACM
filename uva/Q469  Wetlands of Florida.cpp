#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

vector<string> v;
int c;

void W(int x,int y)
{
	if( x>=0 && y>=0 && x<v.size() && y<v[0].size() )
	{
		if(v[x][y]=='W')
		{
			++c;
			v[x][y] = 'L';	
			W(x-1,y);
			W(x-1,y-1);
			W(x,y-1);
			W(x+1,y-1);
			W(x+1,y);
			W(x+1,y+1);
			W(x,y+1);
			W(x-1,y+1);
			//v[x][y] = 'W';
		}
	}
}

int main()
{
	int casenum,x,y,blank=0;
	string a;
	

	cin>>casenum;

	getline(cin,a);
	getline(cin,a);
	
	while(casenum--)
	{
		if(!v.empty())v.clear();

		if(blank!=0)	cout<<endl;
		blank++;
		
		while(getline(cin,a))
		{
			if( !isalpha(a[0]) )	break;

			v.push_back(a);
		}

		vector<string>	tmp(v);
		//copy(v.begin(),v.end(),tmp.begin());

		istringstream in(a);
		c=0;
		in>>x>>y;
		
		W(x-1,y-1);
		
		cout<<c<<endl;

		while( getline(cin,a) )
		{
			if(a=="")	break;

			copy(tmp.begin(),tmp.end(),v.begin());

			istringstream in(a);

			in>>x>>y;

			//cout<<x<<y;
			
			c=0;
			
			W(x-1,y-1);
		
			cout<<c<<endl;
		}
		



		//for(int i = 0 ; i < v.size() ; ++i )	cout<<v[i]<<endl;
	}
}