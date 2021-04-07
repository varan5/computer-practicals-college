#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
  char name[40];
  int age;
  int salary;
} emp;
void write (emp empdetails[], int n)
{
  printf ("\n\tSorted text is written in the new file\n\n");
  int i;
  FILE *fptr;
  if ((fptr = fopen ("sortedemployee.txt", "w")) != NULL)
    {
      for (i = 0; i < n; i++)
	{
	  fprintf (fptr, "%s\t%d\t%d\n", empdetails[i].name,
		   empdetails[i].age, empdetails[i].salary);
	}
    }
}

void counting (emp empdetails[], int k, int n)
{
  int i, c[100] = { 0 }, s[100], s1[100], b[100], p[100];
  char ch[40][40], ch1[40][40];
  for (i = 0; i < n; i++)
    {
      c[empdetails[i].age] = c[empdetails[i].age] + 1;
    }
  for (i = 1; i <= k; i++)
    {
      c[i] = c[i] + c[i - 1];
    }
  for (i = n - 1; i >= 0; i--)
    {
      b[c[empdetails[i].age] - 1] = empdetails[i].age;
      s[c[empdetails[i].age] - 1] = empdetails[i].salary;
      strcpy (ch[c[empdetails[i].age] - 1], empdetails[i].name);

      c[empdetails[i].age] = c[empdetails[i].age] - 1;
    }

  for (i = 0; i < n; i++)
    {
      p[i] = empdetails[i].age;
      s1[i] = empdetails[i].salary;
      strcpy (ch1[i], empdetails[i].name);

      empdetails[i].age = b[i];
      empdetails[i].salary = s[i];
      strcpy (empdetails[i].name, ch[i]);
    }
}

int readFile (emp empdetails[])
{
  int i = 0;
  FILE *fp;
  if ((fp = fopen ("emp.txt", "r")) != NULL)
    {
      while (!feof (fp))
	{
	  fscanf (fp, "%s%d%d", empdetails[i].name, &empdetails[i].age,
		  &empdetails[i].salary);
	  i++;
	}
    }
  return i;			// number of records read
}

void merge (emp empdetails[], int low, int mid, int high)
{
  int i, j, k, b[40], s[40];
  char ch[40][40];
  i = low;
  j = mid + 1;
  k = 0;

  while ((i <= mid) && (j <= high))
    {
      if (empdetails[i].age <= empdetails[j].age)
	{
	  b[k] = empdetails[i].age;
	  s[k] = empdetails[i].salary;
	  strcpy (ch[k], empdetails[i].name);
	  k++, i++;
	}
      else
	{
	  b[k] = empdetails[j].age;
	  s[k] = empdetails[j].salary;
	  strcpy (ch[k], empdetails[j].name);
	  k++, j++;
	}
    }

  while (i <= mid)
    {
      b[k] = empdetails[i].age;
      s[k] = empdetails[i].salary;
      strcpy (ch[k], empdetails[i].name);
      k++, i++;
    }
  while (j <= high)
    {
      b[k] = empdetails[j].age;
      s[k] = empdetails[j].salary;
      strcpy (ch[k], empdetails[j].name);
      k++, j++;
    }

  for (i = low, k = 0; i <= high; i++, k++)
    {
      empdetails[i].age = b[k];
      empdetails[i].salary = s[k];
      strcpy (empdetails[i].name, ch[k]);
    }
}

void merge_sort (emp empdetails[], int low, int high)
{
  int mid;
  if (low < high)
    {
      mid = (low + high) / 2;
      merge_sort (empdetails, low, mid);
      merge_sort (empdetails, mid + 1, high);
      merge (empdetails, low, mid, high);
    }
}


int part (emp empdetails[], int lb, int ub)
{
  int up, down, temp, pivot;
  up = ub;
  down = lb + 1;
  char npivot[30];

  pivot = empdetails[lb].age;
  int spivot = empdetails[lb].salary;
  strcpy (npivot, empdetails[lb].name);

  int s;
  char ch[30];
  do
    {
      while ((empdetails[down].age < pivot) && (down <= ub))
	down++;
      while ((empdetails[up].age > pivot) && (up > lb))
	up--;

      if (down < up)
	{
	  temp = empdetails[down].age;
	  strcpy (ch, empdetails[down].name);
	  s = empdetails[down].salary;

	  empdetails[down].age = empdetails[up].age;
	  strcpy (empdetails[down].name, empdetails[up].name);
	  empdetails[down].salary = empdetails[up].salary;

	  empdetails[up].age = temp;
	  strcpy (empdetails[up].name, ch);
	  empdetails[up].salary = s;
	}
    }
  while (down < up);

  empdetails[lb].age = empdetails[up].age;
  empdetails[lb].salary = empdetails[up].salary;
  strcpy (empdetails[lb].name, empdetails[up].name);

  empdetails[up].age = pivot;
  empdetails[up].salary = spivot;
  strcpy (empdetails[up].name, npivot);
  return up;
}

void sort (emp empdetails[], int lb, int ub)
{
  int j;
  if (lb < ub)
    {
      j = part (empdetails, lb, ub);
      sort (empdetails, lb, j - 1);
      sort (empdetails, j + 1, ub);
    }
}
void display(emp empdetails[],int n)
{
    printf("the sorted list is:\n");
    for(int i=0;i<n;i++)
    {
    printf("\n%s with age %d and salary %d\n",empdetails[i].name,empdetails[i].age,empdetails[i].salary);
    }
}
int main ()
{
  emp empdetails[100];
  char name[40];
  int n;
  n = readFile (empdetails);
  int ch, k = 50;


  printf ("\n\n\t1: Counting Sort\n\t2: Merge Sort\n\t3: Quick Sort\n");
  printf ("\tEnter your choice: ");
  scanf ("%d", &ch);
  int low = 0, high = n - 1, lb = 0, ub = n - 1;

  switch (ch)
    {
    case 1:
      counting (empdetails, k, n);
      display(empdetails,n);
      write (empdetails, n);
      break;

    case 2:
      merge_sort (empdetails, low, high);
      display(empdetails,n);
      write (empdetails, n);
      break;

    case 3:
      sort (empdetails, lb, ub);
      display(empdetails,n);
      write (empdetails, n);
      break;
    }

}
