#include<stdio.h>

struct server{
int storage;
int clock;
int instr_cap;
int ram;
int cache;
int jobs[100];
};




void MinMin(int n,double et[n],int m,double r[m])
{
    int i,j;
    //Phase 1:
    double ct[n][m]; //Matrix to store completion time of tasks corresponding to each resources;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            ct[i][j]=et[i]+r[j];
    }
   //Phase 2
    int min=ct[0][0],index_i,min_res,index_j;
    do
    {
        printf("completion time :\n");
        for (i = 0; i < n; i++)
        {

            for (j = 0; j < m; j++)
            {
                ct[i][j]=et[i]+r[j];
                if (min > ct[i][j])
                {
                    min = ct[i][j];
                    index_i=i;
                    index_j=min_res=j;

                }

            }
            printf("\n");

        }
        r[min_res]=min;
        for ( i = index_i- 1; i < n - 1; i++)
            et[i] = et[i+1];
        for(int i=0;i<n;i++)
        {
            printf("Remaing resources is:%f\n",et[i]);
   
        }
	printf("\n");
	printf("Completion time is:\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%f ",ct[i][j]);
            printf("\n");
        }
        n--;

    }while(n>0);
}

void Minmin()
{
int n;
int m=3; // As we have 3 servers to allocate our tasks.
printf("Enter the number of tasks:\n");
scanf("%d",&n);
int ins[n];
printf("Enter the task instructions(in mips)\n");
for(int i=0;i<n;i++)
{
    scanf("%d",&ins[i]);
}
//Execution time of tasks.
double r[3];// ready time of resource.
r[0]=0;
r[1]=0;
r[2]=0;
double et1[n],et2[n],et3[n];
for(int i=0;i<n;i++)
    et1[i]=ins[i]/5;
for(int i=0;i<n;i++)
    et2[i]=ins[i]/3;
for(int i=0;i<n;i++)
    et3[i]=ins[i]/2;
printf("\n1st Completion time and remaining resources are:\n ");
MinMin(n,et1,m,r);
printf("\n2nd Completion time and remaining resources are:\n ");
MinMin(n,et2,m,r);
printf("\n3rd Completion time and remaining resources are:\n ");
MinMin(n,et3,m,r);
}




void MaxMin(int n,double et[n],int m,double r[m])
{
    double ct[n][m];
    //Phase 1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            ct[i][j]=et[i]+r[j];
    }
    // Phase 2:
   do
   {
       int maximum=-100;
       int index_i;
       int index_j;
       int minimum=100;
       int min_res;
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               ct[i][j]=et[i]+r[j];
               if(ct[i][j]>maximum)
               {
                   maximum=ct[i][j];
                   index_i=i;
                   index_j=j;
               }
           }
       }
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(ct[index_i][j]<minimum)
               {
                   minimum=ct[index_i][j];
                   min_res=j;
               }
           }
       }
        r[min_res]=minimum;
       int position=index_i;
       for(int i=position;i<n-1;i++)
            et[i]=et[i+1];
        for(int i=0;i<n;i++)
        {
            printf("Remaing resources is:%f\n",et[i]);
   
        }
	printf("\n");
	printf("Completion time is:\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%f ",ct[i][j]);
            printf("\n");
        }
        n--;
   }while(n>0);
}

void Maxmin()
{
int n;
int m=3; // As we have 3 servers to allocate our tasks.
printf("Enter the number of tasks:\n");
scanf("%d",&n);
int ins[n];
printf("Enter the task instructions(in mips)\n");
for(int i=0;i<n;i++)
{
    scanf("%d",&ins[i]);
}
//Execution time of tasks.
double r[3];// ready time of resource.
r[0]=0;
r[1]=0;
r[2]=0;
double et1[n],et2[n],et3[n];
for(int i=0;i<n;i++)
    et1[i]=ins[i]/5;
for(int i=0;i<n;i++)
    et2[i]=ins[i]/3;
for(int i=0;i<n;i++)
    et3[i]=ins[i]/2;
printf("\n1st Completion time and remaining resources are:\n ");
MaxMin(n,et1,m,r);
printf("\n2nd Completion time and remaining resources are:\n ");
MaxMin(n,et2,m,r);
printf("\n3rd Completion time and remaining resources are:\n ");
MaxMin(n,et3,m,r);
}




void EnMaxMin(int n,double et[n],int m,double r[m])
{
    double ct[n][m];
    //Phase 1
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            ct[i][j]=et[i]+r[j];
    }
	// Phase 2:
  
 	int maximum=-100;
       int index_i;
       int index_j;
       int minimum=100;
       int min_res;

	for(int i=0;i<n;i++)
	{
		if(et[i]>maximum)
		{
		maximum=et[i];
		index_i=i;
		}
	}
       
       
            
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(ct[index_i][j]<minimum)
               {
                   minimum=ct[index_i][j];
                   min_res=j;
               }
           }
       }
        r[min_res]=minimum;
       int position=index_i;
       for(int i=position;i<n-1;i++)
            et[i]=et[i+1];
        for(int i=0;i<n;i++)
        {
            printf("Remaing resources is:%f\n",et[i]);
           
        }
       printf("\n");
	printf("Completion time is:\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%f ",ct[i][j]);
            printf("\n");
        }
        
   do{
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               ct[i][j]=et[i]+r[j];
               if(ct[i][j]>maximum)
               {
                   maximum=ct[i][j];
                   index_i=i;
                   index_j=j;
               }
           }
       }
        for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(ct[index_i][j]<minimum)
               {
                   minimum=ct[index_i][j];
                   min_res=j;
               }
           }
       }
        r[min_res]=minimum;
       int position=index_i;
       for(int i=position;i<n-1;i++)
            et[i]=et[i+1];
        for(int i=0;i<n;i++)
        {
            printf("Remaing resources is:%f\n",et[i]);
   
        }
	printf("\n");
	printf("Completion time is:\n");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%f ",ct[i][j]);
            printf("\n");
        }
        n--;
   }while(n>0);
   
}

void Enhancedmaxmin()
{
int n;
int m=3; // As we have 3 servers to allocate our tasks.
printf("Enter the number of tasks:\n");
scanf("%d",&n);
int ins[n];
printf("Enter the task instructions(in mips)\n");
for(int i=0;i<n;i++)
{
    scanf("%d",&ins[i]);
}
//Execution time of tasks.
double r[3];// ready time of resource.
r[0]=0;
r[1]=0;
r[2]=0;
double et1[n],et2[n],et3[n];
for(int i=0;i<n;i++)
    et1[i]=ins[i]/5;
for(int i=0;i<n;i++)
    et2[i]=ins[i]/3;
for(int i=0;i<n;i++)
    et3[i]=ins[i]/2;
printf("\n1st Completion time and remaining resources are:\n ");
EnMaxMin(n,et1,m,r);
printf("\n2nd Completion time and remaining resources are:\n ");
EnMaxMin(n,et2,m,r);
printf("\n3rd Completion time and remaining resources are:\n ");
EnMaxMin(n,et3,m,r);
}




void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {

    int pi = partition(array, low, high);

    quickSort(array, low, pi - 1);

    quickSort(array, pi + 1, high);
  }
}

void Greedy()
{
struct server s1;
struct server s2;
struct server s3;

s1.storage = 1000;
s1.clock = 5;
s1.instr_cap = 500;
s1.ram = 8;
s1.cache=3;

s2.storage = 1500;
s2.clock = 3;
s2.instr_cap = 350;
s2.ram = 10;
s2.cache = 4;

s3.storage = 1000;
s3.clock = 2;
s3.instr_cap = 600;
s3.ram = 6;
s3.cache = 2;
int n;

printf("Enter the number of tasks\n");
scanf("%d",&n);

int a[n], ar[n];

for(int i=0;i<n;i++)
{printf("Enter the task id\n");
scanf("%d",&a[i]);
printf("Enter the task instructions(in million instructions)\n");
scanf("%d",&ar[i]);
}
quickSort(ar, 0, n - 1);
int s1_instr = 0, s2_instr = 0, s3_instr = 0;
float s1_load , s2_load , s3_load;
int z=0;
int p=0, q=0, r=0;
for(int j=0; j<n; j++)
{
s1_load = (s1_instr/s1.instr_cap)*100;
s2_load = (s2_instr/s2.instr_cap)*100;
s3_load = (s3_instr/s3.instr_cap)*100;
if(s1_load<=s2_load && s1_load<=s3_load)
z = 1;
else if(s2_load<=s1_load && s2_load<=s3_load)
z = 2;
else
z = 3;

if (z==1)
{ if(s1_load<100)
    {s1.jobs[p++] = a[j];
    s1_instr = s1_instr + ar[j];}
  else
    z=2;
}

else if (z==2)
{ if(s2_load<100)
    {s2.jobs[q++] = a[j];
    s2_instr = s2_instr + ar[j];}
  else
    z=3;
}

else if (z==3)
{ if(s3_load<100)
    {s3.jobs[r++] = a[j];
    s3_instr = s3_instr + ar[j];}
  else
    printf("Server capacity full \n");
}

else
  printf("Server Capacity full \n");
}

float s1_time, s2_time, s3_time;
s1_time = s1_instr/s1.clock;
s2_time = s2_instr/s2.clock;
s3_time = s3_instr/s3.clock;

printf("\nTotal Time taken by Server 1 is %f",s1_time);
printf("\nTotal Time taken by Server 2 is %f",s2_time);
printf("\nTotal Time taken by Server 3 is %f",s3_time);

}




int main()
{
struct server s1;
struct server s2;
struct server s3;

s1.storage = 1000;
s1.clock = 5;
s1.instr_cap = 500;
s1.ram = 8;
s1.cache=3;

s2.storage = 1500;
s2.clock = 3;
s2.instr_cap = 350;
s2.ram = 10;
s2.cache = 4;

s3.storage = 1000;
s3.clock = 2;
s3.instr_cap = 600;
s3.ram = 6;
s3.cache = 2;

int choice;
printf("Enter which algorithm you want to run (1 for min-min,2 for max-min, 3 for Enhanced max-min,4 for greedy)\n");
scanf("%d",&choice);

switch(choice)
{

case 1:
Minmin();
break;

case 2:
Maxmin();
break;

case 3:
Enhancedmaxmin();
break;

case 4:
Greedy();
break;

default:
printf("Enter a suitable choice(1 For min-min, 2 For max-min, 3 For Enhanced Max-Min, 4 for Greedy Algorithm)\n");
break;
}


return 0;
}