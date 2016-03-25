#include "bits/stdc++.h"

using namespace std;

#define N 20
#define inf 1000000
#define mp make_pair
#define sz size()
#define pb push_back

double x[N],y[N];
double px0,py0;
stack <pair<double,double> >S;
vector < pair<double, pair<double,double> > > myAngles;

double dist(double x, double y){
	return (abs(x-px0)*abs(x-px0))+(abs(y-py0)*abs(y-py0));
}

bool myfunction (pair<double,pair<double,double> >i,pair<double, pair<double,double> > j) {

    if(i.first==j.first){
        return dist(i.second.first,i.second.second)>dist(j.second.first,j.second.second);
    }
    return (i.first<j.first);
}

bool orientation(pair<double,double> p,pair<double,double> q,pair<double,double> r)
{
	int val = (q.second - p.second) * (r.first - q.first)-(q.first - p.first) * (r.second - q.second);
	if(val<0){
		return 1;
	}
	return 0;
}

bool check(int pos)
{
	pair<double,double> x1=S.top();
	S.pop();
	pair<double,double> x2=S.top();
	S.push(x1);
	if(orientation(x2,x1,myAngles[pos].second)){
		return 1;
	}
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int i,j;
	int inpoints[20][20];
	memset(inpoints,0,sizeof(inpoints));
	for(i=0;i<n;i++)
	{
		cin >> x[i] >> y[i];
		inpoints[int(x[i])][int(y[i])]=1;
	}
	cout << "-Initial points\n";
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(inpoints[i][j]==1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	cout << "-Final points\n";
	double leasty=inf ,leastx=inf;
	int leastindex = -1;
	for(i=0;i<n;i++)
	{
		if(y[i]<leasty)
		{
			leasty = y[i];
			leastx = x[i];
			leastindex = i;
		}
		else if(y[i]==leasty)
		{
			if(x[i]>leastx)
			{
				leastx = x[i];
				leastindex = i;
			}
		}
	}
	px0=leastx;
	py0=leasty;
	pair<double, pair<double,double> > angle[N];
	for(i=0;i<n;i++)
	{
		angle[i]=mp(atan(y[i]/x[i]), mp(x[i],y[i]));
	}
	swap(angle[leastindex],angle[0]);
	sort(angle+1,angle+n,myfunction);
	for(i=0;i<n;i++)
	{
		if(i>0 && angle[i].first!=angle[i-1].first)
		{
			myAngles.pb(angle[i]);
		}
		else
		{
			myAngles.pb(angle[i]);
		}
	}
	if(myAngles.sz<3)
	{
		cout << "Impossible! \n";
		return 0;
	}
	S.push(myAngles[0].second);
	S.push(myAngles[1].second);
	S.push(myAngles[2].second);
	for(i=3;i<myAngles.sz;i++)
	{
		while(!check(i))
		{
			S.pop();
		}
		S.push(myAngles[i].second);
	}
	int plot[20][20];
	memset(plot,0,sizeof(plot));
	while(!S.empty())
	{
		int u=S.top().first;
		int v=S.top().second;
		S.pop();
		plot[u][v]=1;
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(plot[i][j]==1)
			{
				cout << "*";
			}
			else if(inpoints[i][j]==1)
			{
				cout << ".";
			}
			else
			{
				cout << " ";
			}
		}
		cout << "\n";
	}
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(plot[i][j]==1)
			{
				cout << i << " " << j << "\n";
			}
		}
	}
	return 0;
}