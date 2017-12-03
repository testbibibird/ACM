#include<iostream>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

map<char,int> alpha;


bool cmp(char a,char b)
{	
	return alpha[a]<alpha[b];
}


int main()
{
	
	alpha['A']=0;
	alpha['a']=1;
	alpha['B']=2;
	alpha['b']=3;
	alpha['C']=4;
	alpha['c']=5;
	alpha['D']=6;
	alpha['d']=7;
	alpha['E']=8;
	alpha['e']=9;
	alpha['F']=10;
	alpha['f']=11;
	alpha['G']=12;
	alpha['g']=13;
	alpha['H']=14;
	alpha['h']=15;
	alpha['I']=16;
	alpha['i']=17;
	alpha['J']=18;
	alpha['j']=19;
	alpha['K']=20;
	alpha['k']=21;
	alpha['L']=22;
	alpha['l']=23;
	alpha['M']=24;
	alpha['m']=25;
	alpha['N']=26;
	alpha['n']=27;
	alpha['O']=28;
	alpha['o']=29;
	alpha['P']=30;
	alpha['p']=31;
	alpha['Q']=32;
	alpha['q']=33;
	alpha['R']=34;
	alpha['r']=35;
	alpha['S']=36;
	alpha['s']=37;
	alpha['T']=38;
	alpha['t']=39;
	alpha['U']=40;
	alpha['u']=41;
	alpha['V']=42;
	alpha['v']=43;
	alpha['W']=44;
	alpha['w']=45;
	alpha['X']=46;
	alpha['x']=47;
	alpha['Y']=48;
	alpha['y']=49;
	alpha['Z']=50;
	alpha['z']=51;

	string a;
	int n;

	cin>>n;

	while(n--)
	{
		cin>>a;

		sort(a.begin(),a.end(),cmp);

		cout<<a<<endl;

		while( next_permutation(a.begin(),a.end(),cmp) )
		{
			cout<<a<<endl;
		}
	}

}