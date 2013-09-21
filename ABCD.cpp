#include<iostream>
using namespace std;
char result[1000001];
char b[1000001];
int values[4] = {0};
void fill_color(char a[],int i,int j)
{
        int mid;
        if((j-i+1) <= 2)
        {
                
               	int values [4] = {0}; 
		//cout << a[i] << ":" << a[j] << "\n";
                values[a[i]-'A']  = values[a[j]-'A'] = 1;
  		int p = 0;              
  		for(int b=i; b<=j; ++b)
  		{
           		while(values[p]==1) ++p; 
            		result[b] = p+'A'; p++;  
         	}
		if (result[i - 1] == result[i])
		{
			char temp = result[i];
			result[i] = result[i + 1];
			result[i + 1] = temp;

		}
  	}
                
        else
        {
             	for ( int k = i; k <= j; k+=2)
		{
			//cout << k << "\n";
			fill_color(a,k,k+1);
		}
        }
}
int main()
{
        int n;
        cin>>n;
 
        cin>>b;
	for (int i = 0; i < n; i++)
		values[b[i] - 'A']+= 1;
        fill_color(b,0,2*n-1); result[2*n] = '\0';
        cout<<result;
        return 0;
}
