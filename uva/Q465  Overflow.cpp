#include<iostream>
#include<string>

using namespace std;

bool compare(string);

string plus1(string,string);

string mul(string,string);

int main()
{
	//string e,f;
	char a[200],delims[]=" ", *result =NULL,c,*r[2];
	int i = 0;

	while(cin.getline(a,200))
	{
		cout<<a<<endl;
//		cout<<e<<" "<<c<<" "<<f<<endl;
		result = strtok( a, delims );
		string e(result);
		
		i=0;

		while( result != NULL ) 
		{
			//printf( "result is \"%s\"\n", result );
			result = strtok( NULL, delims );
			r[i++] = result;
		}
		c = r[0][0] ;
		//f = arr[1] ;
		string f(r[1]);

		e.erase(0,e.find_first_not_of('0'));
		f.erase(0,f.find_first_not_of('0'));
		
		//cout<<r[0]<<' '<<r[1]<<endl;

		if(compare(e))
		{
			cout<<"first number too big"<<endl;
		}
		if(compare(f))
		{
			cout<<"second number too big"<<endl;
		}
		
		if(c=='+')	e=plus1(e,f);

		if(c=='*')	e=mul(e,f);
	
		//cout<<e<<endl;
		if(compare(e))
		{
			cout<<"result too big"<<endl;
		}
		
	}
}

string plus1(string a,string b)
{
	char carry=0,tmp;
	int i,j;

	if(a.size()<b.size())	a.swap(b);

	for(i=a.size()-1,j=b.size()-1;j>=0;--i,--j)
	{
		tmp=a[i]-'0'+b[j]-'0'+carry;
		a[i]=tmp%10+'0';
		carry=tmp/10;
	}

	for(;carry!=0&&i>=0;--i)
	{
		tmp=a[i]-'0'+carry;
		a[i]=tmp%10+'0';
		carry=tmp/10;
	}

	if(carry==1)	a.insert(0,1,'1');

	return a;
}

string mul(string a,string b)
{
	int i,j;
	char temp,carry=0;
	//string c;

	if((a[0]=='0'&&a[1]=='\0')||(b[0]=='0'&&b[1]=='\0'))	
	{
		string c(1,'0');		
		return c;
	}

	string c(500,'0');

	//cout<<c;

	int k=0,m;

	for(int i=a.size()-1,m=499;i>=0;--i,m--)
	{
		carry=0;

		k=m;

		for(int j=b.size()-1;j>=0;--j)
		{
			temp=c[k]-'0';

			c[k]=((a[i]-'0')*(b[j]-'0')+carry+c[k]-'0')%10+'0';

			carry=((a[i]-'0')*(b[j]-'0')+carry+temp)/10;

			--k;
	
			//	cout<<static_cast<int>(carry)<<endl;

			if(j==0)
			{
				c[k]+=carry;	
			}
		}
	}

	c.erase(0,k);
		
	for(;c[0]=='0';)	c.erase(0,1);
		
	//cout<<c<<endl;

	return c; 
}

bool compare(string a)
{
	if(a.size()>10)	return true;

	if(a.size()<10)	return	false;

	string tmp("2147483647",10);

	for(int i=0;i<10;++i)
	{
		if(a[i]>tmp[i])	return true;

		else	if(a[i]<tmp[i])	return false;
	}

	return false;
}
