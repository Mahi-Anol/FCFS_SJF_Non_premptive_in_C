//Mahi Sarwar Anol
//ID:201-15-13664

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

    // return 0;
    sort(arr,0,n-1);

    int wt[n];
    memset(wt,0,sizeof(wt));
    for(int i=1;i<n;i++)
    {
       wt[i]=wt[i-1]+arr[i-1][2];
    }
    int tat[n];
    for(int i=0;i<n;i++)
    {
        tat[i]=wt[i]+arr[i][2];
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
        printf("|%-17d|%-17d|%-17d|%-17d|%-16d|",arr[i][0],arr[i][1],arr[i][2],wt[i],tat[i]);
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
        for(int j=0;j<arr[i][2];j++)
        {
             printf("--");
        }
    }
    printf("\n|");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i][2]-1;j++)
        {
            printf(" ");
        }
        printf("p%d",arr[i][0]);
        for(int j=0;j<arr[i][2]-1;j++)
        {
            printf(" ");
        }
        printf("|");
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf(" ");
        for(int j=0;j<arr[i][2];j++)
        {
             printf("--");
        }
    }
    printf("\n0");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<arr[i][2];j++)
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