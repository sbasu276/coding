/* Count INVERSIONS in an Array 

Algorithm:
---------

Using Merge-Sort.
While merging, count the number of inversions.
How?
Suppose A[] & B[] are merged in a single sorted array.
Whenever B[j] is selected over A[i], inv_count += number of element remaining in A

while A,B != empty
    append min(a_i,b_j) to C
    if b_j < a_i
       count += number of element remaining in A
       j++
    else
       i++
  ; now one list is empty
  append the remainder of the list to C
  return count, C

sort-and-count(L)
  if L has one element return 0
  else
     divide L into A, B
     (rA, A) = sort-and-count(A)
     (rB, B) = sort-and-count(B)
     (r, L) = merge-and-count(A,B)
  return r = rA+rB+r, L

*/


#include<cstdio>
#include<stdlib.h>

int merge(int a[],int temp[],int l,int m,int r)
{
	int i,j,k;
	i=l; // index for A[]
	j=m+1; // index for B[]
	k=l; // index for C = merged(A,B)
	int count=0;
	while(i<=m && j<=r)
	{
		if(a[i] <= a[j])
			temp[k++]=a[i++];
		else
		{
			temp[k++]=a[j++];
			count = count + ((m-i)+1);
			// show the inversions too
			for(int itr=i; itr<=m; itr++)
				printf("%d,%d\n",a[itr],a[j-1]);
//m-i elements left between i and m(endpoint of A) + 1 for i-th element itself
		}
	}

	// copy remaining elements from A or B
	while(i<=m)
		temp[k++] = a[i++];
	while(j<=r)
		temp[k++] = a[j++];
	
	//copy back merged elements to original array
	for(i=l;i<=r;i++)
		a[i]=temp[i];

return count;
}

int sort(int a[],int temp[],int l,int r)
{
	int m,inv_count=0;
	if(l<r) 
	{
		m=(l+r)/2;
		inv_count = sort(a,temp,l,m);
		inv_count += sort(a,temp,m+1,r);
		inv_count += merge(a,temp,l,m,r);
	}
return inv_count;
}

int mergesort(int a[], int size)
{
	int *temp = (int *)malloc(size*sizeof(int));
	return sort(a,temp,0,size-1);
}


int main()
{
	int a[] = {2,4,1,3,5};
	int size = sizeof(a)/sizeof(a[0]);
	printf("%d\n",mergesort(a,size));
	return 0;
}
