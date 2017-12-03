#include<iostream>
#include<map>
#include<algorithm>
#include<string>

class node
{
public:
	char c;
	int num;
};

using namespace std;

bool cmp(node a,node b)
{
	if(a.num==b.num)
	{
		return a.c < b.c;
	}
	return a.num > b.num;
}

int main()
{
	map<const char,int> alpha;
	alpha['a'] = 0 ;
	alpha['b'] = 1 ;
	alpha['c'] = 2 ;
	alpha['d'] = 3 ;
	alpha['e'] = 4 ;
	alpha['f'] = 5 ;
	alpha['g'] = 6 ;
	alpha['h'] = 7 ;
	alpha['i'] = 8 ;
	alpha['j'] = 9 ;
	alpha['k'] = 10 ;
	alpha['l'] = 11 ;
	alpha['m'] = 12 ;
	alpha['n'] = 13 ;
	alpha['o'] = 14 ;
	alpha['p'] = 15 ;
	alpha['q'] = 16 ;
	alpha['r'] = 17 ;
	alpha['s'] = 18 ;
	alpha['t'] = 19 ;
	alpha['u'] = 20 ;
	alpha['v'] = 21 ;
	alpha['w'] = 22 ;
	alpha['x'] = 23 ;
	alpha['y'] = 24 ;
	alpha['z'] = 25 ;
	alpha['A'] = 0 ;
	alpha['B'] = 1 ;
	alpha['C'] = 2 ;
	alpha['D'] = 3 ;
	alpha['E'] = 4 ;
	alpha['F'] = 5 ;
	alpha['G'] = 6 ;
	alpha['H'] = 7 ;
	alpha['I'] = 8 ;
	alpha['J'] = 9 ;
	alpha['K'] = 10 ;
	alpha['L'] = 11 ;
	alpha['M'] = 12 ;
	alpha['N'] = 13 ;
	alpha['O'] = 14 ;
	alpha['P'] = 15 ;
	alpha['Q'] = 16 ;
	alpha['R'] = 17 ;
	alpha['S'] = 18 ;
	alpha['T'] = 19 ;
	alpha['U'] = 20 ;
	alpha['V'] = 21 ;
	alpha['W'] = 22 ;
	alpha['X'] = 23 ;
	alpha['Y'] = 24 ;
	alpha['Z'] = 25 ;


	int n;

	node arr[26];

	for(int i = 0 ; i < 26 ; ++i )
	{
		arr[i].num = 0 ;
		arr[i].c = 65+i;
	}

	string a,tmp;

	cin>>n;
	getline(cin,a);
	getline(cin,a);

	for( int i = 1 ; i < n ; ++i )
	{
		getline(cin,tmp);
		a.append(tmp);
	}

	for( int i = 0 ; i < a.size() ; ++i  )
	{
		if( isalpha(a[i]) )
		{
			arr[alpha[a[i]]].num++;
		}
	}

	sort(arr,arr+26,cmp);

	for(int i = 0 ; i < 26 && arr[i].num != 0 ; ++i )
	{
		cout<<arr[i].c<<' '<<arr[i].num<<endl;
	}
}