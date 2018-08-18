#include "stdafx.h"
#include "gauss.h"
#include <iostream>
using namespace std;
int n, i, j, k;
double d, s;
void gauss(int n)
{
	double **a=new double *[n];
	for (i=0; i<=n; i++)
		a[i]=new double [n];
	double *b=new double [n];
	double *x=new double [n];
	//cout << "Vvedite koefficienty i svobodnye chleny " << endl;
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			/*if (i==j)
				a[i][j]=5;
			else
				a[i][j]=0;*/
			cout<<"a["<<i<<","<<j<< "]= ";
			cin>>a[i][j];
		}
		cout<<"b["<<i<< "]= ";
		cin>>b[i];
		//b[i]=5;
	}
	for (k=1; k<=n; k++) 
	{
		for (j=k+1; j<=n; j++)
		{
			if (a[k][k]==0)
			{
				i=k+1;
				while (a[i][k]==0)
				{
					i++;
					int c;
					for (j=k;j<n;j++)						
						swap(a[k],a[i]);	
					swap(b[k],b[i]);
				}
			}	
			d=a[j][k]/a[k][k]; 
			for (i=k; i<=n; i++)
			{
				a[j][i]=a[j][i]-d*a[k][i];
			}
			b[j]=b[j]-d*b[k];
		}
	}
	for (k=n; k>=1; k--)
	{
		d=0;
		for (j=k+1; j<=n; j++)
		{
			s=a[k][j]*x[j]; 
			d=d+s;
		}
		x[k]=(b[k]-d)/a[k][k];
	}
	cout<<"Korni sistemy: "<<endl;
	for (i=1; i<=n; i++)
		cout<<"x["<<i<<"]="<<x[i]<<" "<<endl;
}
