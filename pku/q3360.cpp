#include<iostream>
#include<map>
#include<string>

using namespace std;

bool r[55][55]={},used[55],v[55];
int roadnum,degree[55]={},roadtmp;

int main()
{
	map<char,int>	z;
	z['a']=1;
	z['b']=2;
	z['c']=3;
	z['d']=4;
	z['e']=5;	
	z['f']=6;
	z['g']=7;
	z['h']=8;
	z['i']=9;
	z['j']=10;
	z['k']=11;
	z['l']=12;
	z['m']=13;
	z['n']=14;
	z['o']=15;
	z['p']=16;
	z['q']=17;
	z['r']=18;
	z['s']=19;
	z['t']=20;
	z['u']=21;
	z['v']=22;
	z['w']=23;
	z['x']=24;
	z['y']=25;
	z['z']=26;
	z['A']=1+26;
	z['B']=2+26;
	z['C']=3+26;
	z['D']=4+26;
	z['E']=5+26;	
	z['F']=6+26;
	z['G']=7+26;
	z['H']=8+26;
	z['I']=9+26;
	z['J']=10+26;
	z['K']=11+26;
	z['L']=12+26;
	z['M']=13+26;
	z['N']=14+26;
	z['O']=15+26;
	z['P']=16+26;
	z['Q']=17+26;
	z['R']=18+26;
	z['S']=19+26;
	z['T']=20+26;
	z['U']=21+26;
	z['V']=22+26;
	z['W']=23+26;
	z['X']=24+26;
	z['Y']=25+26;
	z['Z']=26+26;


	string a;
	int l,s,t;

	while(getline(cin,a))
	{
		
		memset(degree,0,55*4);
		roadtmp=roadnum=0;

		l = a.find_first_of('{');

		for( ; a[l] != '}' ; ++l)
		{
			if( isalph(a[l]) )
			{
				v[z[a[l]]] = true;
			}
		}
		++i;

		for( ; a[l] != '}' ; ++l )
		{
			if(a[l]=='(')
			{
				for(int nn = 1 ; a[l]!=')' ; ++l )
				{
					if(isalpha(a[l]) && nn==1)
					{
						s = z[a[l]];++nn;
					}
					else if(isalpha(a[l]) && nn==2)
					{
						t = z[a[l]];
					}
				}

				r[s][t] = true;
				r[t][s] = true;
				++roadnum;
			}
		}
			
		if(euler())
		{
			cout<<"Yes ";
		}
		else
		{
			cout<<"No ";
		}


	}

}

bool euler()
{

	for(int i = 0 ; i < 55 ; ++i )
	{
		for(int j = 0 ; j < 55 ; ++j )
		{
			if( r[i][j] )	degree[i]++;
		}
	}

	for(int i = 0 ; i < 55 ; ++i )
	{
		if( degree[i]%2 != 0 )	return false;
	}

	for(int i = 0 ; i < 55 ; ++i )
	{
		if( degree[i] > 0 )
		{
			DFS(i);
			break;
		}
	}

	if(roadnum!=roadtmp)	return false;
	
	return true;
}