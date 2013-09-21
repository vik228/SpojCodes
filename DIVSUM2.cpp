#include<iostream>
#include<map>
#include<cstdlib>
#include<cmath>
#include<ctime>
#define MAX 10000000000000000
typedef unsigned long long int int64;
using namespace std;
map<long long,int> m1;
void save_factors(long long);
long long power(long long x,int i)
{
	if(i==0)
		return 1;
	else
		return (x*power(x,i-1));
}
int64 mulmod(int64,int64,int64);
int64 modulo(int64 a ,int64 pow,int64 n)
{
	int64 y,u;
	y=1;
	u=a;
	//cout<<"y"<<" "<<"u"<<" "<<"pow"<<"\n";
	while(pow>0)
	{
		//cout<<y<<" "<<u<<" "<<pow<<"\n";
		if(pow%2==1)
			y=mulmod(y,u,n);
		u = mulmod(u,u,n);
		pow/=2;
	}
	return y%n;

}
int64 mulmod(int64 a,int64 b,int64 c)
{
	int64 x=0,y=a%c;
	while(b>0)
	{
		if(b%2==1)
		{
			x = (x+y)%c;
		}
		y = (y*2)%c;
		b/=2;
	}
	return x%c;
}

bool miller(int64 n,int it)
{
	if(n<2)
		return false;
	if(n!=2 and n%2==0)
		return false;
	int64 s =n-1;
	while(s%2==0)
		s/=2;
	for(int i=0;i<it;i++)
	{
		int64 a = rand()%(n-1)+1,temp=s;
		int64 mod = modulo(a,temp,n);
		while(temp!=n-1 && mod!=1 && mod!=n-1)
		{
			mod = mulmod(mod,mod,n);
			temp*=2;
		}
		if(mod!=n-1 and temp%2==0)
		{
			return false;
		}
	}
	return true;
}

long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
long long pollard_rho(long long n)
{
	//cout<<"pollard called\n";
	long long x=rand()%(n-1)+1;
	long long y=x;
	long long c=rand()%(n-1)+1;
	long long g=1;
	if(n%2==0)
		return 2;
	while(g==1)
	{
		//cout<<"In an infinite loop now:\n";
		x=(mulmod(x,x,n)+c)%n;
		y=(mulmod(y,y,n)+c)%n;
		y=(mulmod(y,y,n)+c)%n;
		g=gcd(abs(x-y),n);

	}
	return g;
}
void factor(long long n)
{
	if(n==1)
		return;
	if(miller(n,20))
	{
		//cout<<"called\n";
		save_factors(n);
		return;
		
	}
	long long d=pollard_rho(n);
	factor(d);
	factor(n/d);
}
void save_factors(long long n)
{
	m1[n]+=1;
}
int main()
{
	int t;
	clock_t t1,t2;
	long long n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		map<long long,int>::iterator it1;
		//map<long long,int>::iterator it2;
		factor(n);
		long long p=1;
		long long x=0;
	
		for(it1=m1.begin();it1!=m1.end();it1++)
		{
			 long long a = 0, pp = 1;
                        
                        for(int cnt = 0; cnt <= it1->second; cnt++) 
			{
                            	//cout << "a = " << a << " \t pp = " << pp << endl;
                                a += pp;
                                pp *= it1->first;
				//cout << "a = " << a << "\t pp = " << pp <<endl;
                        }
                        
                        p*=a;
			

			/*
			long long  a=power((it1->first),it1->second+1)-1;
			//cout<<a<<"\n";
             		a = a /(it1->first-1);
             		p*=a;
			*/
			
			//cout<<it1->first<<"->"<<it1->second<<"\n";
		}
		cout<<p-n<<"\n";
		m1.clear();
		
	}
	return 0;
}
