//Mahi Sarwar Anol
//ID:201-15-13664

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

void combine(int **arr,int st,int end)
{
      int mid=st+(end-st)/2;
      int temp1[end+1];
      int temp2[end+1];
      int temp3[end+1];
      int i=st,j=mid+1,k=0;
      while(i<=mid && j<=end)
      {
      	   if(arr[i][1]>arr[j][1])
      	   {
      	   	  temp1[k]=arr[j][1];
              temp2[k]=arr[j][2];
              temp3[k]=arr[j][0];
              k++;
      	   	  j++;
      	   }
      	   else
      	   {
             if(arr[j][1]==arr[i][1] && arr[j][0]<arr[i][0])
             {
                temp1[k]=arr[j][1];
                temp2[k]=arr[j][2];
                temp3[k]=arr[j][0];
                k++;
                j++;
             }
     	   	 else
             {
                temp1[k]=arr[i][1];
                temp2[k]=arr[i][2];
                temp3[k]=arr[i][0];
                k++;
                i++;
             }
      	   }
      }
      while(i<=mid)
      {
      	temp1[k]=arr[i][1];
        temp2[k]=arr[i][2];
        temp3[k]=arr[i][0];
        k++;
        i++;
      }

      while(j<=end)
      {
      	temp1[k]=arr[j][1];
        temp2[k]=arr[j][2];
        temp3[k]=arr[j][0];
        k++;
        j++;
      }
      int x=0;

      for(int i=st;i<=end;i++)
      {
      	arr[i][1]=temp1[x];
        arr[i][2]=temp2[x];
        arr[i][0]=temp3[x];
        x++;
      }
}

void sort(int **arr,int st,int end)
{
   int mid=st+(end-st)/2;
   if(st<end)
   {
       sort(arr,st,mid);
       sort(arr,mid+1,end);
       combine(arr,st,end);
   }
}
void swp(int x,int y,int **arr)
{
    int t1,t2,t3;
    t1=arr[x][0];
    t2=arr[x][1];
    t3=arr[x][2];
    arr[x][0]=arr[y][0];
    arr[x][1]=arr[y][1];
    arr[x][2]=arr[y][2];
    arr[y][0]=t1;
    arr[y][1]=t2;
    arr[y][2]=t3;
}
int main()
{
    printf("Enter number of processes: ");
    int n;scanf("%d",&n);

    int **arr;
    arr=(int**)malloc(n*sizeof(int *));

    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(3*sizeof(int));
    }
    printf("\"Now kindly enter process id,arrival time,Burst time separed by a space\"\n");
    for(int i=0;i<n;i++)
    {
        printf("Enter for process %d : ",i+1);
        for(int j=0;j<3;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    sort(arr,0,n-1);
 for(int j=0;j<n;j++)
    for(int i=0;i<n-1;i++)
    {
        
        if(arr[i][1]==arr[i+1][1] && arr[i][2]>arr[i+1][2])
        {
            swp(i,i+1,arr);
        }
        
    }
    int seq[n];
    int h[1000]={0};
    seq[0]=arr[0][0];
    h[arr[0][0]]=1;
    int val=arr[0][1]+arr[0][2];

    for(int i=1;i<n;i++)
    {
        int cmp=val;
        int cbt=INT_MAX;
        int id=90;
        for(int j=1;j<n;j++)
        {   
            if(arr[j][1]<=cmp && h[arr[j][0]]==0 && arr[j][2]<cbt)
            {
                 cbt=arr[j][2];
                 id=arr[j][0];
            }
        }
        seq[i]=id;
        h[id]=1;
        val+=cbt;
    }
    int arr2[n][3];
    int rows[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(seq[i]==arr[j][0])rows[i]=j;
        }
    }
     
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            arr2[i][j]=arr[rows[i]][j];
        }
    }
    printf("\n");
    int wt[n];
    memset(wt,0,sizeof(wt));
    for(int i=1;i<n;i++)
    {
       wt[i]=wt[i-1]+arr2[i-1][2];
    }
    int tat[n];
    for(int i=0;i<n;i++)
    {
        tat[i]=wt[i]+arr2[i][2];
    }
    for(int i=0;i<90;i++)
    {
        printf("-");
    }
    printf("\n");
    printf("%-18s%-18s%-18s%-18s%-18s","|PID","|Arrival Time","|Burst Time","|Waiting Time","|Turn Around Time|\n");
    for(int i=0;i<90;i++)
    {
        printf("-");
    }
    printf("\n");

    for(int i=0;i<n;i++)
    {
        printf("|%-17d|%-17d|%-17d|%-17d|%-16d|",arr2[i][0],arr2[i][1],arr2[i][2],wt[i],tat[i]);
        printf("\n");
    }
    for(int i=0;i<90;i++)
    {
        printf("-");
    }
    printf("\n\n\n");

    printf("x-x-x-x-x-x-x-Grant chart-x-x-x-x-x-x-x-x-x\n");

    for(int i=0;i<n;i++)
    {
        printf(" ");
        for(int j=0;j<arr2[i][2];j++)
        {
             printf("--");
        }
    }
    printf("\n|");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr2[i][2]-1;j++)
        {
            printf(" ");
        }
        printf("p%d",arr2[i][0]);
        for(int j=0;j<arr2[i][2]-1;j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf(" ");
        for(int j=0;j<arr2[i][2];j++)
        {
             printf("--");
        }
    }
    printf("\n0");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr2[i][2];j++)
        {
            printf("  ");
        }
        if(tat[i]>9)printf("\b");
        printf("%d",tat[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        free(arr[i]);
    }
    free(arr);
}
