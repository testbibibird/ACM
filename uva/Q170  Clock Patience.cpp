#include<iostream>
#include<stack>
#include<string>
#include<map>

using namespace std;

int main()
{
	stack<string> stk[13];
	string arr[52];
	char a,tmp,tmp2,rs;

	map<const char , int > maps;
	maps['A'] = 0;
	maps['2'] = 1;
	maps['3'] = 2;
	maps['4'] = 3;
	maps['5'] = 4;
	maps['6'] = 5;
	maps['7'] = 6;
	maps['8'] = 7;
	maps['9'] = 8;
	maps['T'] = 9;
	maps['J'] = 10;
	maps['Q'] = 11;
	maps['K'] = 12;

	while(cin>>arr[0])
	{
		if(arr[0]=="#")	break;

		int count=0;

		for(int i = 1 ; i < 52 ; ++i )	cin>>arr[i];

		for(int i = 51 ,j = 0 ; i >= 0 ; --i , ++j )	stk[j%13].push( arr[i] );

		tmp='K';

		while(1)
		{
			if( stk[ maps[tmp] ].empty() )	break;
			
			tmp2 = stk[ maps[tmp] ].top()[0];
			rs  = stk[ maps[tmp] ].top()[1];
			
			stk[ maps[tmp] ].pop();

			tmp=tmp2;
		
			++count;
			
		}

		if(count<10)	cout<<0;

		cout<<count<<","<<tmp<<rs<<endl;
	}

}