#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main()
{
	char s1[3];
	char s2[2010];
	char ii[3];
	char jj[2010];
	int t , n , m , i, j;
	bool b = false;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s%s",&s1,&s2,&ii,&jj);
		n = (s1[strlen(s1)-1] - '0'); 
		m = (s2[strlen(s2)-1] - '0');
		i = (ii[strlen(ii)-1] - '0');
		j = (jj[strlen(jj)-1] - '0');
		if((n * m) % 2 == 0)
		{
			printf("Impossible.\n");
			continue ;
		}
		else
		{
			if(((i * j)%2 == 1) or ((i%2 == 0) and (j%2 == 0)))
				printf("Possible.\n");
			else
				printf("Impossible.\n");
		}
	}
	return 0;
}
			



		
