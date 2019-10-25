#include<iostream>
using namespace std;

int partition(int *ap, int lb, int ub)
{
	int pivot,i,j,temp;
	pivot = ap[ub];
	i = lb;
	j = ub;
	while(i<j)
	{
		while((ap[j]>=pivot)&&(i<j))
		j--;
		while((ap[i]<pivot))
		i++;
		if(i<j)
		{
			temp = ap[i];
			ap[i] = ap[j];
			ap[j] = temp;
		}
	}
	ap[ub] = ap[i];
	ap[i] = pivot;
	return i;
}
void quick(int *a, int lb, int ub)
{
	int i,j;
	if(lb<ub)
	{
		j = partition(a,lb,ub);
		quick(a,lb,j-1);
		quick(a,j+1,ub);
	}
	/*for(i=0;i<=ub;i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;*/
	
}
int main()
{
	int arr[10];
	int i,j;
	int n;
	cin>>n;
	cout<<"Enter elements\n";
	for(i=0;i<n;i++)
	{
			cin>>arr[i];
		
	}
	quick(arr,0,n-1);
	for(i=0;i<n;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
	return 0;
}

