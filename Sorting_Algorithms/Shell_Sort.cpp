#include<iostream>
using namespace std;

/* function to implement shellSort */
int shell(int a[],int n){
   int i, j, gap;
   /* Rearrange the array elements at n/2, n/4, ..., 1 gap or intervals */

   // Code from Jenny:
   for (gap = n/2; gap > 0; gap/=2){
      for(j=gap; j<n; j+= 1){
         for (i = j - gap; i >= 0; i = i - gap){
               if(a[i + gap] > a[i]){
                 //We don't need to swap
                 break;
              }
                 
              else{
                  //swap the a[i] with a[i+gap]
                  int temp = a[i];
                  a[i] = a[i + gap];
                  a[i + gap] = temp;
              }
         }
      }
   }

/*
   //Code from JavaTpoint:
   for (gap = n/2; gap > 0; gap/=2){
      for(j=gap; j<n; j+= 1){
         // store a[i] to the variable temp and make the ith position empty
         int temp = a[j];
         int i;

         for(i = j; i >= gap && a[i -gap] > temp; i -= gap)
            a[i] = a[i - gap];

         a[i] = temp;  // put temp (the original a[i]) in its correct position  
      }
   }
*/

   return 0;
}


void printArr(int a[],int n) /* function to print the array elements */{
   for (int i = 0;i < n; i++)
      cout<<a[i]<<" ";
}

int main()
{
   int a[] ={33, 31, 40, 8, 12, 17,25,42};
   int n=sizeof(a) / sizeof(a[0]);

   printf("Before sorting array elements are - \n");
   printArr(a,n);

   shell(a,n); 
   printf("\nAfter applying shell sort, the array elements are - \n");
   printArr(a,n);

   return 0;

}