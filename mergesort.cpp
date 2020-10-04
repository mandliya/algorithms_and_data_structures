#include<iostream>
using namespace std;
void merge(int[],int,int,int);
void mergesort(int a[],int l,int h)
{
	if(l<h)
	{
		int mid;
	mid=(l+h)/2;
	//cout<<"Inside merge";
	mergesort(a,l,mid);
	mergesort(a,mid+1,h);
	merge(a,l,mid,h);
	}
}
void merge(int a[],int l,int mid,int h)
{
	int i,j,k;
	int n1,n2;
	n1=mid-l+1;
	n2=h-mid;
	int left[n1],r[n2];
	for(i=0;i<n1;i++)
	left[i]=a[l+i];
	for(j=0;j<n2;j++)
	r[j]=a[mid+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(left[i]<r[j])
		{
			a[k]=left[i];
			k++;
			i++;
		}
		else
		{
			a[k]=r[j];
			j++;
			k++;
		}
	}
	while(i<n1)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k]=r[j];
		k++;
		j++;
	}
//	cout<<"merge sucessfully";
}

int main()
{
	int a[5]={12,32,10,5,3};
	mergesort(a,0,4);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}


