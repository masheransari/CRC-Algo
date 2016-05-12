#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
void divide(int n,int d,char div[], char code[])
{
	int b=0;
	while((n+d-1-b)>=d)
	{
		for(int i=b,j=0;i<d+b;i++,j++)
		{
			if(code[i]==div[j])
			code[i]='0';
			else
			code[i]='1';
		}
		for(int x=b;x<d+b;x++)
		{
			if(code[x]=='0')
			{
				b++;
			}
			else
			break;
		}
	}
	//cout<<"remainder=";
	//for(int i=b;i<n+d-1;i++)
	//cout<<code[i];
}
int main()
{
	// server side encryption
	int n,d;
	cout<<"enter the number of bits you want to send:";
	cin>>n;
	char data[n];
	cout<<"\n enter the bits:";
	for(int i=0;i<n;i++)
	cin>>data[i];
	if(data[0]=='0')
	{
		cout<<"\n invalid data!! retry";
		exit(0);
	}
	cout<<"\n enter the number of bits in divisor:";
	cin>>d;
	char div[d];
	char code[n+d-1];
	cout<<"\n enter the divisor:";
	for(int i=0;i<d;i++)
	cin>>div[i];
	if(div[0]=='0')
	{
		cout<<"\n invalid data!! retry";
		exit(0);
	}


	for(int i=0;i<sizeof(code);i++)
	{
		if(i<n)
		code[i]=data[i];
		else
		code[i]='0';
	}

	///complete

	divide(n, d,div,code);
	char cs[n+d-1];
	cout<<"\n send code=";
	for(int i=0;i<(n+d-1);i++)
	{
		if(i<n)
		cs[i]=data[i];
		else
		cs[i]=code[i];
		cout<<cs[i];
	}


	//end of sender side encryption of data

	//receiver side  manipulation


	char cr[n+d-1],datar[n];
	cout<<"\n\n\n enter the received code=";







	for(int i=0;i<n+d-1;i++)
	cin>>cr[i];
	for(int i=0;i<n;i++)
	datar[i]=cr[i];
	divide(n,d,div,cr);
	bool flag=true;
	for(int i=n;i<n+d-1;i++)
	{
		if(cr[i]!='0')
		{
			flag=false;
		}
	}
	if(flag==true)
	{
		cout<<"\n transmission succesful\n received data=";
		for(int i=0;i<(n);i++)
		{
			cout<<datar[i];
		}
	}
	else cout<<"resend data!! error occured";
}
