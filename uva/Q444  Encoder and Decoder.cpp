#include<iostream>
#include<string>

using namespace std;

string      arr[128]={"0","1","2","3","4","5","6","7","8","9",
					   "01","11","21","31","41","51","61","71","81","91",
					   "02","12","22","32","42","52","62","72","82","92",
					   "03","13","23","33","43","53","63","73","83","93",
					   "04","14","24","34","44","54","64","74","84","94",
					   "05","15","25","35","45","55","65","75","85","95",
					   "06","16","26","36","46","56","66","76","86","96",
					   "07","17","27","37","47","57","67","77","87","97",
					   "08","18","28","38","48","58","68","78","88","98",
					   "09","19","29","39","49","59","69","79","89","99",
					   "001","101","201","301","401","501","601","701","801","901",
					   "011","111","211","311","411","511","611","711","811","911",
					   "021","121","221"};
int main()
{
	string a;
	char c;

	while(getline(cin,a))
	{
		if( a[0] >= 48 && a[0] < 58)
		{	
			for(int i = a.size()-1 ; i >= 0  ;  )
			{
				if(a[i] == '1' )
				{
					--i;
					c = ( a[i--] - 48 )*10 ;
					c += a[i--] - 48  ;
					c += 100;
				}
				else
				{
					c = ( a[i--] - 48 )*10 ;
					c += a[i--] - 48  ;
				}
				cout<<c;
			}
		}
		else
		{
			for(int i = a.size()-1 ; i >= 0 ; --i )
			{
				cout<<arr[a[i]];
			}
		}
		cout<<endl;
	}
}