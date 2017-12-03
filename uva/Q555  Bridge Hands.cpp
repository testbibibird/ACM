#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

map<string,int> card;

bool cmp(string a,string b)
{
	return card[a]<card[b];
}

int main()
{
	string a,q;
	char start;
	//char n[26],s[26],e[26],w[26];
	vector<string> n,s,e,w;
	char tmp[3]={"aa"};

	card["C2"]=1;
	card["C3"]=2;
	card["C4"]=3;
	card["C5"]=4;
	card["C6"]=5;
	card["C7"]=6;
	card["C8"]=7;
	card["C9"]=8;
	card["CT"]=9;
	card["CJ"]=10;
	card["CQ"]=11;
	card["CK"]=12;
	card["CA"]=13;

	card["D2"]=14;
	card["D3"]=15;
	card["D4"]=16;
	card["D5"]=17;
	card["D6"]=18;
	card["D7"]=19;
	card["D8"]=20;
	card["D9"]=21;
	card["DT"]=22;
	card["DJ"]=23;
	card["DQ"]=24;
	card["DK"]=25;
	card["DA"]=26;

	card["S2"]=27;
	card["S3"]=28;
	card["S4"]=29;
	card["S5"]=30;
	card["S6"]=31;
	card["S7"]=32;
	card["S8"]=33;
	card["S9"]=34;
	card["ST"]=35;
	card["SJ"]=36;
	card["SQ"]=37;
	card["SK"]=38;
	card["SA"]=39;

	card["H2"]=40;
	card["H3"]=41;
	card["H4"]=42;
	card["H5"]=43;
	card["H6"]=44;
	card["H7"]=45;
	card["H8"]=46;
	card["H9"]=47;
	card["HT"]=48;
	card["HJ"]=49;
	card["HQ"]=50;
	card["HK"]=51;
	card["HA"]=52;

	while(getline(cin,a))
	{
		if(a[0] == '#')	break;

		start = a[0];

		getline(cin,a);
		getline(cin,q);

		a.append(q);
		
		switch(start)
		{
			case 'N':
			for(int i = 0 ; i < 13 ; ++i )
			{
				tmp[0] = a[i*8];
				tmp[1] = a[i*8+1];
				e.push_back(tmp);
				tmp[0] = a[i*8+2];
				tmp[1] = a[i*8+3];
				s.push_back(tmp);
				tmp[0] = a[i*8+4];
				tmp[1] = a[i*8+5];
				w.push_back(tmp);
				tmp[0] = a[i*8+6];
				tmp[1] = a[i*8+7];
				n.push_back(tmp);		
			}
			break;
		case 'E':
			for(int i = 0 ; i < 13 ; ++i )
			{
				tmp[0] = a[i*8];
				tmp[1] = a[i*8+1];
				s.push_back(tmp);
				tmp[0] = a[i*8+2];
				tmp[1] = a[i*8+3];
				w.push_back(tmp);
				tmp[0] = a[i*8+4];
				tmp[1] = a[i*8+5];
				n.push_back(tmp);
				tmp[0] = a[i*8+6];
				tmp[1] = a[i*8+7];
				e.push_back(tmp);		
			}
			break;
		case 'W':
			for(int i = 0 ; i < 13 ; ++i )
			{
				tmp[0] = a[i*8];
				tmp[1] = a[i*8+1];
				n.push_back(tmp);
				tmp[0] = a[i*8+2];
				tmp[1] = a[i*8+3];
				e.push_back(tmp);
				tmp[0] = a[i*8+4];
				tmp[1] = a[i*8+5];
				s.push_back(tmp);
				tmp[0] = a[i*8+6];
				tmp[1] = a[i*8+7];
				w.push_back(tmp);		
			}
			break;
		case 'S':
			for(int i = 0 ; i < 13 ; ++i )
			{
				tmp[0] = a[i*8];
				tmp[1] = a[i*8+1];
				w.push_back(tmp);
				tmp[0] = a[i*8+2];
				tmp[1] = a[i*8+3];
				n.push_back(tmp);
				tmp[0] = a[i*8+4];
				tmp[1] = a[i*8+5];
				e.push_back(tmp);
				tmp[0] = a[i*8+6];
				tmp[1] = a[i*8+7];
				s.push_back(tmp);		
			}
			break;
		}

		sort(n.begin() , n.end() , cmp ) ;
		sort(s.begin() , s.end() , cmp ) ;
		sort(e.begin() , e.end() , cmp ) ;
		sort(w.begin() , w.end() , cmp ) ;


		cout<<"S:";
		for(int i = 0 ; i < 13 ; ++i )
			cout<<' '<<s[i];
		cout<<endl;

		cout<<"W:";
		for(int i = 0 ; i < 13 ; ++i )
			cout<<' '<<w[i];
		cout<<endl;

		cout<<"N:";
		for(int i = 0 ; i < 13 ; ++i )
			cout<<' '<<n[i];
		cout<<endl;

		cout<<"E:";
		for(int i = 0 ; i < 13 ; ++i )
			cout<<' '<<e[i];
		cout<<endl;
		
		n.clear();
		s.clear();
		e.clear();
		w.clear();
	}
}