#include<iostream>
using namespace std;
int main()
{
   int n,a[50],temp;
   cout<<"enter no of elements:";
   cin>>n;
   cout<<"enter elements:\n";
   for(int i=0;i<n;i++)
      cin>>a[i];
   for(int i=0;i<n-1;i++)
   {
      int flag=1;
      for(int j=0;j<n-i-1;j++)
      {
         if(a[j]>a[j+1])
         {
            temp =a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
            flag =0;
         }
      }
      if(flag!=0)
         break;
   }
   cout<<"sorted array:\n";
   for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
   return 0;
}

[24bcs170@mepcolinux ex1]cat bubble.cpp
[24bcs170@mepcolinux ex1]$./a.out
enter no of elements:6
enter elements:
5
3
2
9
8
1
sorted array:
1 2 3 5 8 9 [24bcs170@mepcolinux ex1]$2
bash: 2: command not found
[24bcs170@mepcolinux ex1]$./a.out
enter no of elements:8
enter elements:
66
55
22
11
0
66
45
12
sorted array:
0 11 12 22 45 55 66 68
