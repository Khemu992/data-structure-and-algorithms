/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<iostream>
using namespace std;
/*
struct Array 
{
  int *A;
  int size;
  int length;
};

void Display(struct Array a)
{
    cout<<"Elements are "<<endl;
    for(int i=0; i<a.length; i++)
    {
        cout<<a.A[i]<<" ";
    }
}
void Add(struct Array *a , int x)
{
    a->A[a->length]=x;
} 

int main()
{ 
    struct Array a;
 
    cout<<"Enter thr size of arra"<<endl;
    cin>>a.size;
    a.A=new int[a.size];
    a.length=0;
    cout<<"Enter lengh of array"<<endl;
    int n;
    cin>>n;
    a.length=n;
    cout<<"Enter all elements "<<endl;
    for(int i=0; i<a.length; i++)
    {
        cin>>a.A[i];
    }
    Display(a);
    */
struct Array
{
  int A[10];
  int size;
  int length;
};

void
Display (struct Array a)
{
  cout << "Elements are " << endl;
  for (int i = 0; i < a.length; i++)
    {
      cout << a.A[i] << " ";
    }
  cout << endl;
}

void
Add (struct Array *a, int x)
{
  a->A[a->length] = x;
  a->length++;
}

void
Insert (struct Array *a, int index, int x)
{
  for (int i = a->length; i > index; i--)
    {
      a->A[i] = a->A[i - 1];
    }
  a->A[index] = x;
  a->length++;
}

void
Delete (struct Array *a, int index)
{
  int x;
  x = a->A[index];
  for (int i = index; i < (a->length - 1); i++)
    {
      a->A[i] = a->A[i + 1];

    }
  a->length -= 1;

}

int
Search (struct Array a, int x)
{
  for (int i = 0; i < a.length; i++)
    {
      if (a.A[i] == x)
	{
	  return i;
	}
    }
  return -1;
}

void
Swap (int *a, int *b)
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int
ImproveLinearSearch1 (struct Array *a, int key)
{
  for (int i = 0; i < a->length; i++)
    {
      if (a->A[i] == key)
	{
	  Swap (&a->A[i], &a->A[i - 1]);
	  return i - 1;
	}
    }
  return -1;
}

int
ImproveLinearSearch2 (struct Array *a, int key)
{
  for (int i = 0; i < a->length; i++)
    {
      if (a->A[i] == key)
	{
	  Swap (&a->A[i], &a->A[0]);
	  return 0;
	}
    }
  return -1;
}

int
BinarySearch (struct Array a, int key)
{
  int l = 0;
  int h = a.length - 1;
  int mid;
  while (l <= h)
    {
      mid = (l + h) / 2;
      if (key == a.A[mid])
	{
	  return mid;
	}
      else if (key < a.A[mid])
	{
	  h = mid - 1;
	}
      else
	{
	  l = mid + 1;
	}
    }
  return -1;
}

int
RBinarySearch (struct Array a, int key, int l, int h)
{
  int mid = (l + h) / 2;
  if (l <= h)
    {
      if (key == a.A[mid])
	{
	  return mid;
	}
      else if (key < a.A[mid])
	{
	  RBinarySearch (a, key, l, mid - 1);
	}
      else
	{
	  RBinarySearch (a, key, mid + 1, h);
	}
    }
  return -1;
}

int
Get (struct Array a, int index)
{
  if (index >= 0 && index < a.length)
    {
      return a.A[index];
    }
  return -1;
}

void
Set (struct Array *a, int index, int x)
{
  if (index >= 0 && index < a->length)
    {
      a->A[index] = x;
    }
}

int
Sum (struct Array a)
{
  int sum = a.A[0];
  for (int i = 1; i < a.length; i++)
    {
      sum = sum + a.A[i];
    }
  return sum;
}

int
Max (struct Array a)
{
  int max;
  max = a.A[0];
  for (int i = 1; i < a.length; i++)
    {
      if (a.A[i] > max)
	{
	  max = a.A[i];
	}
    }
  return max;
}

int
Min (struct Array a)
{
  int min;
  min = a.A[0];
  for (int i = 1; i < a.length; i++)
    {
      if (a.A[i] < min)
	{
	  min = a.A[i];
	}
    }
  return min;
}

int
RecursiveSum (struct Array a, int n)
{
  if (n < 0)
    {
      return 0;
    }
  return RecursiveSum (a, n - 1) + a.A[n];
}

int
Avg (struct Array a)
{
  int total = a.A[0];
  for (int i = 1; i < a.length; i++)
    {
      total = total + a.A[i];
    }
  return total / (a.length - 1);
}

void
Reverse (struct Array *a)
{
  int B[a->size];
  int i, j;
  for (i = 0, j = a->length - 1; i < a->length; i++, j--)
    {
      B[j] = a->A[i];
    }
  for (i = 0; i < a->length; i++)
    {
      a->A[i] = B[i];
    }
}

void
Reverse2 (struct Array *a)
{
  int i, j;
  for (i = 0, j = a->length - 1; i <= j; i++, j--)
    {
      int temp;
      temp = a->A[i];
      a->A[i] = a->A[j];
      a->A[j] = temp;
    }
}

int
IsSorted (struct Array a, int n)
{
  for (int i = 0; i < n - 1; i++)
    {
      if (a.A[i] > a.A[i + 1])
	{
	  return 0;
	}
    }
  return 1;
}

void
Insert2 (struct Array *a, int x)	//Insert x such that it insterted at sorted position********
{
  int i = a->length - 1;
  while (x < a->A[i])
    {
      a->A[i + 1] = a->A[i];
      i--;
    }
  a->A[i + 1] = x;
  a->length++;
}

void
NegOnLeft (struct Array *a)
{
  int i = 0;
  int j = a->length - 1;
  while (i < j)
    {
      while (a->A[i] < 0)
	{
	  i++;
	}
      while (a->A[j] >= 0)
	{
	  j--;
	}
      if (i < j)
	{
	  Swap (&a->A[i], &a->A[j]);
	}
    }
}

struct Array *
Merging (struct Array *a1, struct Array *a2)
{
  struct Array *c = (struct Array *) malloc (sizeof (struct Array));;


  int i, j, k;
  while (i < a1->length && j < a2->length)
    {
      if (a1->A[i] < a2->A[j])
	{
	  c->A[k++] = a1->A[i++];
	}

      else
	{
	  c->A[k++] = a2->A[j++];

	}
    }
  for (; i < a1->length; i++)
    {
      c->A[k++] = a1->A[i++];
    }
  for (; j < a2->length; j++)
    {
      c->A[k++] = a2->A[j++];
    }
  c->length = a1->length + a2->length;
  return c;
}

struct Array *
Union (struct Array *a1, struct Array *a2)
{
  int i, j, k;
  i = j = k = 0;
  struct Array *a3;
  a3 = (struct Array *) malloc (sizeof (struct Array));
  //struct Array *a3=new Array;
  while (i < a1->length && j < a2->length)
    {
      if (a1->A[i] < a2->A[j])
	{
	  a3->A[k++] = a1->A[i++];
	}
      else if (a1->A[i] > a2->A[j])
	{
	  a3->A[k++] = a2->A[j++];
	}
      else
	{
	  a3->A[k++] = a1->A[i++];
	  j++;
	}

    }
  for (i; i < a1->length; i++)
    {
      a3->A[k++] = a1->A[i];
    }
  for (j; j < a2->length; j++)
    {
      a3->A[k++] = a2->A[j];
    }
  a3->length = k;
  return a3;
}

struct Array *
Intersection (struct Array *a1, struct Array *a2)
{
  // struct Array *a3=(struct Array*)malloc(sizeof(struct Array));
  struct Array *a3 = new Array;
  int i, j, k;
  i = k = j = 0;
  while (i < a1->length && j < a2->length)
    {
      if (a1->A[i] < a2->A[j])
	{
	  i++;
	  j++;
	}
      else if (a1->A[i] > a2->A[j])
	{
	  i++;
	  j++;
	}
      else
	{
	  a3->A[k++] = a1->A[i++];
	  j++;
	}
    }
  a3->length = k;
  return a3;
}

int
Missing1 (struct Array a)	//If Array is like this 1,2,3,4,5.......
{
  int n = a.A[a.length - 1];
  int s = n * (n + 1) / 2;

  return s - Sum (a);
}

void
Missing2 (struct Array a)	// Array is like this 6,7,8,9,11,12,13......
{
  int l = a.A[0];
  int d = l - 0;
  for (int i = 0; i < a.length; i++)
    {
      if (a.A[i] - i != d)
	{
	  cout << "Missing Ele is " << i + d;
	  break;
	}

    }

}

void
Missing3 (struct Array a)
{
  int l = a.A[0];
  int diff = l - 0;
  for (int i = 0; i < a.length; i++)
    {
      if (a.A[i] - i != diff)
	{
	  while (diff < a.A[i] - i)
	    {
	      cout << diff + i << " ";
	      diff += 1;
	    }
	}
    }
}

void
Missing4 (struct Array a)	// in UnSorted Array********
{
  int *H;
  H = new int[Max (a)];

  for (int i = 0; i < Max (a); i++)
    {
      H[i] = 0;
    }

  for (int i = 0; i < a.length; i++)
    {
      H[a.A[i]] += 1;
    }

  for (int i = 1; i <= Max (a); i++)
    {
      if (H[i] == 0)
	{
	  cout << i << " ";
	}
    }
}

void
Dublicate (struct Array a)
{
  int lastDublicate = 0;
  for (int i = 0; i < a.length - 1; i++)
    {
      if (a.A[i] == a.A[i + 1] && a.A[i] != lastDublicate)
	{
	  cout << "Dublicate is " << a.A[i] << endl;
	  lastDublicate = a.A[i];
	}
    }
}

void
CountDublicate (struct Array a)
{
  int j = 0;
  int lastDblicate = 0;
  for (int i = 0; i < a.length - 1; i++)
    {
      if (a.A[i] == a.A[i + 1] && a.A[i] != lastDblicate)
	{
	  j = i + 1;
	  while (a.A[i] == a.A[j])
	    {
	      j++;
	    }
	  cout << "Dublicate is " << a.A[i] << " Repeted " << j -
	    i << " times" << endl;
	  i = j - 1;
	}
    }
}

void
Dublicate2 (struct Array a)
{
  int H[Max (a) + 1] = { 0 };
  for (int i = 0; i < a.length; i++)
    {
      H[a.A[i]]++;
    }

  for (int i = 0; i < Max (a) + 1; i++)
    {
      if (H[i] > 1)
	{
	  cout << "Dublicated Element is " << i;
	  cout << " Repeted " << H[i] << " times" << endl;
	}
    }
}

void
Dublicate3 (struct Array a)
{
  for (int i = 0; i < a.length - 1; i++)
    {
      int count = 1;
      if (a.A[i] != -1)
	{
	  for (int j = i + 1; j < a.length; j++)
	    {
	      if (a.A[i] == a.A[j])
		{
		  count++;
		  a.A[j] = -1;
		}

	    }
	  if (count > 1)
	    {
	      cout << a.A[i] << " Repeted " << count << " times" << endl;
	    }
	}

    }
}

void
Dublicate4 (struct Array a)	//Using HasTable
{
  int H[Max (a) + 1] = { 0 };
  for (int i = 0; i < a.length; i++)
    {
      H[a.A[i]]++;
    }
  for (int i = 0; i < Max (a) + 1; i++)
    {
      if (H[i] > 1)
	{
	  cout << i << " is Repeted " << H[i] << " times " << endl;
	}
    }
}

void PairOfEelement(struct Array a,int k)
{
    for(int i=0; i<a.length-1; i++)
    {
        for(int j=i+1; j<a.length; j++)
        {
            if(a.A[i]+a.A[j]==k)
            {
                cout<<a.A[i]<<"+"<<a.A[j]<<"="<<k<<endl;
            }
        }
    }
}

void PairOfEelement2(struct Array a, int k)//Using Hashing******
{
    int H[Max(a)+1]={0};
    for(int i=0; i<a.length; i++)
    {
        if(H[k-a.A[i]]==1)
        {
            cout<<a.A[i]<<"+"<<k-a.A[i]<<"="<<k<<endl;
        }
        H[a.A[i]]++;
    }
    
}

void PairOfEelement3(struct Array a, int k) //IN Sorted Array******
{
    int i=0,j=a.length-1;
    while(i<j)
    {
        if(a.A[i]+a.A[j]==k)
        {
             cout<<a.A[i]<<"+"<<a.A[j]<<"="<<k<<endl;
             i++;
             j--;
        }
        else if(a.A[i]+a.A[j]<k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
}
int
main ()
{
  struct Array a1 = { {1,3,4,5,6,8,9,10,12,14}, 10, 10 };
  Display (a1);
  //struct Array a2={{2,4,5,7,12},10,5};
  //Display(a2);
  //struct Array *a3;
  //Display (a);
  //Add (&a, 6);
  //Display (a);
  //Insert(&a,2,12);
  //Delete(&a,1);
  //cout<<Search(a,8);
  //cout << "Index is " << ImproveLinearSearch1 (&a, 1) << endl;  //Transposition***
  //Display (a);
  //cout << "Index is " << ImproveLinearSearch2 (&a, 4) << endl;  //Move to Head***
  //Display (a);
  //cout << "Index is " << BinarySearch (a, 41) << endl;
  // cout<<"Element at index 7 is "<<Get(a,7)<<endl;
  //Set(&a,3,14);
  //Display(a);
  //cout<<"sum is "<<sum(a)<<endl;
  //cout<<"Max element is "<<Max(a)<<endl;
  //cout<<"sum By Recursion is "<<RecursiveSum(a,a.length-1)<<endl;
  //cout<<"Avg is "<<Avg(a)<<endl;
  //Reverse(&a);
  //Display(a);
  //Reverse2(&a);
  //Display(a);
  //cout<<IsSorted(a,5)<<endl;
  //Insert2(&a,18);
  //Display(a);
  //NegOnLeft(&a);
  //Display(a);
  //a3=Merging(&a1,&a2);
  //Display(*a3);
  //a3=Union(&a1,&a2);
  //Display(*a3);
  //a3=Intersection(&a1,&a2);
  //Display(*a3);
  //cout<<"size of a3 array "<<sizeof(a3)<<endl;
  //cout<<"size of a1 array "<<sizeof(a1)<<endl;
  //cout<<"Missing Elemets are "<<endl;
  //Missing3(a1);

  //cout<<"Missing Elemets are "<<endl;  //For UnSorted Array **
  //Missing4(a1);

  //Dublicate(a1);
  //CountDublicate(a1);
  //Dublicate2(a1);
  //Dublicate4(a1);
  //PairOfEelement(a1,10);
  //PairOfEelement2(a1,10);
  //PairOfEelement3(a1,10);

}


