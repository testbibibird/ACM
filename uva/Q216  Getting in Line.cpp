#include<iostream>
#include<cmath>

using namespace std;

int n;

class node
{
public:
	double x,y;
};

node arr[10]={};
node tmp[10]={};
node seq[10]={};
bool used[10]={},key;
double mini;

double dis(node a,node b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void DFS(int count)
{
	if(count==n)
	{
		double sum=0;

		for(int i = 0 ; i < n-1 ; ++i )
		{
			sum += dis(tmp[i],tmp[i+1]);
		}

		if(sum<mini)
		{
			mini = sum;

			for(int i = 0 ; i < n ; ++i )
			{
				seq[i] = tmp[i];
			}
		}

		return;
	}

	for(int i = 0 ; i < n ; ++i )
	{
		if(!used[i])
		{
			used[i] = true;
			tmp[count] = arr[i];
			DFS(count+1);
			used[i] = false;
		}
	}
}



int main()
{
	int num=1;

	while(cin>>n && n!=0)
	{
		for(int i = 0 ; i < n ; ++i )
		{
			cin>>arr[i].x>>arr[i].y;
		}

		mini = 100000;
		key = false;
		
		DFS(0);

		cout<<"**********************************************************"<<endl;
		cout<<"Network #"<<num++<<endl;

		cout.setf(ios::fixed);
		cout.precision(2);
		//cout.setf(ios::fixed);
		//cout.precision(0);
		for(int i = 0 ; i < n-1 ; ++i )
		{
			cout<<"Cable requirement to connect ("<<(int)seq[i].x<<","<<(int)seq[i].y<<") to ("<<(int)seq[i+1].x<<","<<(int)seq[i+1].y<<") is "<<dis(seq[i],seq[i+1])+16.0<<" feet."<<endl;
		}
		
		
		cout<<"Number of feet of cable required is "<<mini+(n-1)*16<<'.'<<endl;
	}
}