/******************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:5
Sorting Operations on first year student CGPA data using array
*******************************************************************************/
#include<iostream>
#include<string>
using namespace std;
class Student
{
    public:
    string name;
    int rollNo;
    float marks;
    string emailId;
    Student()
    {
        name="";
        emailId="";
        rollNo=0;
        marks=0.0;
    }
    void acceptDetails()
    {
        cout<<"\nEnter Student details:";
        cout<<"\nEnter your name:";
        cin>>name;
        cout<<"\nEnter your Roll Number:";
        cin>>rollNo;
        int cnt=0;
        do
        {
          cout<<"\nEnter your CGPA:";
          cin>>marks;
          if(marks>=0 && marks<=10)
          {
              cnt++;
              break;
          }
          else
          {
           cout<<"\nInvalid CGPA";
           cout<<"\nCGPA should be less than or equal to 10";
          }
        }while(cnt==0);
    }
    void displayDetails()
    {
        cout<<"\nStudent details:";
        cout<<"\nName:"<<name;
        cout<<"\nRoll Number:"<<rollNo;
        cout<<"\nCGPA:"<<marks;
        cout<<"\n";
    }
}; 
/* Function to sort an array using bubble sort*/
   void bubble_sort(float a[],int n)
   {
       int i,j;
       float temp;
       for(i=0;i<n-1;i++)
       {
           for(j=0;j<n-i-1;j++)
           {
               if(a[j]>a[j+1])
               {
                  temp=a[j];
                  a[j]=a[j+1];
                  a[j+1]=temp;
               }
               
           }
       }
    }
   /*Function to sort an aaray using selection sort*/
   void selectionSort(float arr[],int n)
   {
       int i,j,minpos;
       float tempp;
       
       for(i=0;i<n;i++)
       {
           minpos=i;
           for(j=i+1;j<n;j++)
           {
               if(arr[j]<arr[minpos])
               {
                   minpos=j;
               }
               
           }
           //swap the minimum element with the first element
           tempp=arr[i];
           arr[i]=arr[minpos];
           arr[minpos]=tempp;
       }
       
       
   }
   
   
/* Function to sort an array using insertion sort*/
void insertionSort(float arr[], int n)  
{  
    int i,  j;
    float key;
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
         }  
        arr[j + 1] = key;  
    }  
}  
// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(float a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
    // Create temp arrays
    float L[n1], R[n2];
 
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of 
    //second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];
            i++;
        }
        else 
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[]
    while (i < n1) 
    {
        a[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[]
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
 
// l and r are left and right indices of the sub-array of arr to be sorted 
void mergeSort(float a[],int l,int r)
{
    if(l>=r)
    {
        return;
        //returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(a,l,m);
    mergeSort(a,m+1,r);
    merge(a,l,m,r);
}
/* This function takes last element as pivot, places  
the pivot element at its correct position in sorted  
array, and places all smaller (smaller than pivot)  
to left of pivot and all greater elements to right  
of pivot */
int partition (float arr[], int low, int high)  
{  
    float pivot = arr[high]; 
    // pivot  
    int i = (low - 1);
    // Index of smaller element  
  
    float t;
    for (int j = low; j <= high - 1; j++)  
    {  
        // If current element is smaller than the pivot  
        if (arr[j] < pivot)  
        {  
            i++; // increment index of smaller element 
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }  
    }  
    
    float temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;  
    return (i + 1);  
}  
  
/*here low=starting index and high=ending index */
void quickSort(float arr[], int low, int high)  
{  
    if (low < high)  
    {  
      
        /* p is partitioning index arr[p] is now at right place */
        int p = partition(arr, low, high);  
         
        // Separately sort elements before  
        // partition and after partition  
        quickSort(arr, low, p - 1);  
        quickSort(arr, p + 1, high); 
        }  
}  
int main()
{
    int n,i,choiceOrder,choiceSort;
    cout<<"\nEnter the number of students who first year CGPA is to be stored:";
    cin>>n;
    Student obj[n];
    float arr[n];
    float arr1[n];
    float arr2[n];
    float arr3[n];
    float atemp[n];
    
    
    for(int i=0;i<n;i++)
    {
      obj[i].acceptDetails();
      
    }
     for(int i=0;i<n;i++)
    {
      obj[i].displayDetails();
      arr[i]=obj[i].marks;
      arr1[i]=obj[i].marks;
      arr2[i]=obj[i].marks;
      arr3[i]=obj[i].marks;
      
    }
    char ch=n;
     do
     {
        cout<<"\n *******MENU********";
        cout<<"\n Sort the floating point numbers in Ascending/descending order using:";
        cout<<"\n 1.Bubble Sort";
        cout<<"\n 2.Insertion Sort";
        cout<<"\n 3.Merge Sort";
        cout<<"\n 4.Quick Sort";
        cout<<"\nEnter your choice:";
        cin>>choiceSort;
        switch(choiceSort)
        {
        case 1:bubble_sort(arr,n);
               for(int i=0;i<n;i++)
               {
                atemp[i]=arr[i];
               }
               break;
               
        case 2:insertionSort(arr1, n);
                for(int i=0;i<n;i++)
               {
                atemp[i]=arr1[i];
               }
               break;
               
        case 3:mergeSort(arr2, 0, n-1);
               for(int i=0;i<n;i++)
               {
                atemp[i]=arr2[i];
               }
               break;
               
        case 4:quickSort(arr3, 0, n - 1);
               for(int i=0;i<n;i++)
               {
                atemp[i]=arr3[i];
               }
               break;
        default:cout<<"\nIncorrect choice,try again!";
               break;
        }
        cout<<"\nSort the array of floating point numbers in\n1.ascending order \n2.descending order:";
        cout<<"\nEnter your choice:";
        cin>>choiceOrder;
        if(choiceOrder==1)
        {
          cout<<"\nGiven list of numbers after sorting:";
          for(int j=0;j<n;j++)
          {
          cout<<atemp[j]<<"  ";
          }
        }
      else if(choiceOrder==2)
      {
         cout<<"\nGiven list of numbers after sorting in descending order:";
         for(int j=n-1;j>=0;j--)
         {
           cout<<atemp[j]<<"  ";
         }
      }
      else
      {
        cout<<"\nInvalid entry";
        cout<<"\nTry again";
      }
     
      cout<<"\nDo you wish to continue?";
      cout<<"\nPress y for yes:";
      cin>>ch;
    }while(ch=='y'||ch=='Y');
    
    
    return 0;
}
/*OUTPUT

Enter the number of students who first year CGPA is to be stored:5

Enter Student details:
Enter your name:Riya

Enter your Roll Number:23

Enter your CGPA:8.9

Enter Student details:
Enter your name:Tanaya

Enter your Roll Number:45

Enter your CGPA:5.8

Enter Student details:
Enter your name:Prachi

Enter your Roll Number:67

Enter your CGPA:9.7

Enter Student details:
Enter your name:Urvi

Enter your Roll Number:21

Enter your CGPA:6.3

Enter Student details:
Enter your name:Rasika

Enter your Roll Number:20

Enter your CGPA:8.3

Student details:
Name:Riya
Roll Number:23
CGPA:8.9

Student details:
Name:Tanaya
Roll Number:45
CGPA:5.8

Student details:
Name:Prachi
Roll Number:67
CGPA:9.7

Student details:
Name:Urvi
Roll Number:21
CGPA:6.3

Student details:
Name:Rasika
Roll Number:20
CGPA:8.3
 *******MENU********
 Sort the floating point numbers in Ascending/descending order using:
 1.Bubble Sort
 2.Insertion Sort
 3.Merge Sort
 4.Quick Sort
Enter your choice:1

Sort the array of floating point numbers in
1.ascending order 
2.descending order:
Enter your choice:1

Given list of numbers after sorting:5.8  6.3  8.3  8.9  9.7  
Do you wish to continue?
Press y for yes:y

 *******MENU********
 Sort the floating point numbers in Ascending/descending order using:
 1.Bubble Sort
 2.Insertion Sort
 3.Merge Sort
 4.Quick Sort
Enter your choice:2

Sort the array of floating point numbers in
1.ascending order 
2.descending order:
Enter your choice:2

Given list of numbers after sorting in descending order:9.7  8.9  8.3  6.3  5.8  
Do you wish to continue?
Press y for yes:y

 *******MENU********
 Sort the floating point numbers in Ascending/descending order using:
 1.Bubble Sort
 2.Insertion Sort
 3.Merge Sort
 4.Quick Sort
Enter your choice:3

Sort the array of floating point numbers in
1.ascending order 
2.descending order:
Enter your choice:1

Given list of numbers after sorting:5.8  6.3  8.3  8.9  9.7  
Do you wish to continue?
Press y for yes:y

 *******MENU********
 Sort the floating point numbers in Ascending/descending order using:
 1.Bubble Sort
 2.Insertion Sort
 3.Merge Sort
 4.Quick Sort
Enter your choice:4

Sort the array of floating point numbers in
1.ascending order 
2.descending order:
Enter your choice:2

Given list of numbers after sorting in descending order:9.7  8.9  8.3  6.3  5.8  
Do you wish to continue?
Press y for yes:n
*/

/*TIME COMPLEXITY(Worst case time complexity)
void acceptDetails()=O(1)
void displayDetails()=O(1)

void bubble_sort()=O(n^2)
void selectionSort()=O(n^2)
void insertionSort()=O(n^2)
void mergeSort()=O(nlogn)
void quickSort()=O(n^2)
*/

