/* Roll no:2330
  Name:Prajakta Deokule
  CNumber: C22019221332
  Assignment number:1 Matrices*/

/*Problem statement:
Write C++ program to perform following operations on matrices:
1.Check matrix is square matrix
2.Check matrix is upper triangular matrix
3.Compute transpose of matrix
4.Add  two matrices
5.Multiply two matrices*/

#include<iostream>
using namespace std;
class matrix
{
    public:
    int a[20][20];
    int r,c;
    //default constructor
    matrix()
    {
        r=0;
        c=0;
    }
    //parameterized constructor
    matrix(int rn,int cn)
    {
        r=rn;
        c=cn;
    }
    //functions
    void accept();
    void display();
    void add(matrix,matrix);
    void multiplication(matrix,matrix);
    void transpose();
    bool square();
    bool uppertriangular();
};
//time complexity for accept function = O(n^2)
void matrix::accept()
{
    cout<<"\nEnter the order of the matrix\n";
    cout<<"Enter the number of rows:";
    cin>>r;
    cout<<"Enter the number of columns:";
    cin>>c;
    cout<<"\nEnter the elements of the matrix";
    cout<<"\nYou have to enter "<<(r*c)<<" values\n";

    for(int i=0;i<r;i++)
    {
           for(int j=0;j<c;j++)
          {
              cout<<"Enter a value:";
              cin>>a[i][j];
          }
    }
}

//time complexity for display function = O(n^2)
 void matrix::display()
{
    cout<<"\nMatrix :\n";
    for(int i=0;i<r;i++)
    {
           for(int j=0;j<c;j++)
          {
              cout<<a[i][j]<<"\t";
          }
          cout<<"\n";
    }
}

//time complexity for transpose function = O(n^2)
void matrix::transpose()
{
    int transpose[20][20];
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
           transpose[i][j]=a[j][i];
        }
    }
    cout<<"\nThe transpose of the matrix is:\n";
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
         cout<<transpose[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
//time complexity for add function = O(n^2)
void matrix::add(matrix m1,matrix m2)
{
    if((m1.r==m2.r)&&(m1.c==m2.c))
    {
       cout<<"\nAddition is possible";
       for(int i=0;i<m1.r;i++)
       {
        for(int j=0;j<m1.c;j++)
        {
            a[i][j]=m1.a[i][j]+m2.a[i][j];
        }
        }
         cout<<"\nSum is\n";
        for(int i=0;i<m1.r;i++)
        {
           for(int j=0;j<m1.c;j++)
          {
              cout<<a[i][j]<<"\t";
          }
          cout<<"\n";
        }
    }
    else
    {
     cout<<"Addition not possible";
    }
}

//time complexity for multiplication function = O(n^3)
void matrix::multiplication(matrix m3,matrix m4)
{
    if(m3.c==m4.r)
    {
       cout<<"Matrix multiplication is possible";
       int i,j,k;
        for(i=0;i<m3.r;i++)
        {
          for(j=0;j<m4.c;j++)
         {
           a[i][j]=0;
           for(k=0;k<m3.c;k++)
           {
             a[i][j]+=m3.a[i][k]*m4.a[k][j];
            }
          }
        }
         cout<<"\nProduct is as follows:\n";
        for(int i=0;i<m3.r;i++)
        {
           for(int j=0;j<m4.c;j++)
          {
              cout<<a[i][j]<<"\t";
           }
          cout<<"\n";
         }
      }
       else
       {
         cout<<"\nMatrix multiplication is not possible";
         cout<<"\nNumber of rows of 2nd matrix and number of columns of first matrix are not equal";
        }
}
//time complexity for upper triangular function = O(n^2)
bool matrix::uppertriangular()
{
    int flag=0;
    for(int i=1;i<r;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i][j]!=0)
            {
               flag++;
               break;
            }
        }
    }
    if(flag==0)
    return true;
    else
    return false;

}
//time complexity for square function = O(1)
bool matrix::square()
{
    if(r==c)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    bool checksquare;
    bool result;
    matrix obj,obj1,obj2;
    matrix sumobj(20,20);
    matrix pobj(20,20);

    int ch;
    do
    {
    cout<<"\n**********MENU*********";
    cout<<"\nFollowing operations can be operated on matrices:";
    cout<<"\n 1. Check matrix is square matrix";
    cout<<"\n 2. Check matrix is upper triangular";
    cout<<"\n 3. Compute transpose of matrix";
    cout<<"\n 4. Add two matrices";
    cout<<"\n 5. Multiply two matrices";
    cout<<"\n 6. Exit";
    cout<<"\nEnter your choice:";
    cin>>ch;
    switch(ch)
    {
    case 1: obj.accept();
            obj.display();
            checksquare=obj.square();
            if(checksquare)
            {
              cout<<"The matrix is square matrix";
            }
            else
            {
              cout<<"The matrix is not square matrix";
            }
            break;
    case 2: obj.accept();
            obj.display();
            result=obj.uppertriangular();
            if(result)
            {
              cout<<"The matrix is upper triangular matrix";
            }
            else
            {
              cout<<"The matrix is not upper triangular matrix\n";
            }
            break;
    case 3:obj.accept();
           obj.display();
           obj.transpose();
           break;
    case 4:obj1.accept();
           obj1.display();
           obj2.accept();
           obj2.display();
           sumobj.add(obj1,obj2);
           break;
    case 5:obj1.accept();
           obj1.display();
           obj2.accept();
           obj2.display();
           pobj.multiplication(obj1,obj2);
           break;
    case 6:cout<<"\nExit";
           break;
    default:cout<<"\nInvalid choice";
           break;
    }    //close switch
    }while(ch!=6);     //close do while
    return 0;
}//close main()

/*OUTPUT


**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:1

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:3

Enter the elements of the matrix
You have to enter 6 values
Enter a value:2
Enter a value:3
Enter a value:4
Enter a value:1
Enter a value:34
Enter a value:2

Matrix :
2	3	4
1	34	2
The matrix is not square matrix
**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:1

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:2

Enter the elements of the matrix
You have to enter 4 values
Enter a value:2
Enter a value:89
Enter a value:35
Enter a value:67

Matrix :
2	89
35	67
The matrix is square matrix
**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:2

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:2

Enter the elements of the matrix
You have to enter 4 values
Enter a value:0
Enter a value:86
Enter a value:0
Enter a value:0

Matrix :
0	86
0	0
The matrix is upper triangular matrix
**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:2

Enter the order of the matrix
Enter the number of rows:3
Enter the number of columns:3

Enter the elements of the matrix
You have to enter 9 values
Enter a value:0
Enter a value:9
Enter a value:8
Enter a value:0
Enter a value:0
Enter a value:78
Enter a value:0
Enter a value:0
Enter a value:0

Matrix :
0	9	8
0	0	78
0	0	0
The matrix is upper triangular matrix

**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:3

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:3

Enter the elements of the matrix
You have to enter 6 values
Enter a value:3
Enter a value:6
Enter a value:8
Enter a value:9
Enter a value:79
Enter a value:65

Matrix :
3	6	8
9	79	65

The transpose of the matrix is:
3	9
6	79
8	65

**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:4

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:3

Enter the elements of the matrix
You have to enter 6 values
Enter a value:2
Enter a value:1
Enter a value:3
Enter a value:1
Enter a value:0
Enter a value:1

Matrix :
2	1	3
1	0	1

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:3

Enter the elements of the matrix
You have to enter 6 values
Enter a value:1
Enter a value:0
Enter a value:0
Enter a value:2
Enter a value:6
Enter a value:8

Matrix :
1	0	0
2	6	8

Addition is possible
Sum is
3	1	3
3	6	9

**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:4

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:1

Enter the elements of the matrix
You have to enter 2 values
Enter a value:2
Enter a value:5

Matrix :
2
5

Enter the order of the matrix
Enter the number of rows:1
Enter the number of columns:2

Enter the elements of the matrix
You have to enter 2 values
Enter a value:2
Enter a value:3

Matrix :
2	3
Addition not possible
**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:5

Enter the order of the matrix
Enter the number of rows:3
Enter the number of columns:2

Enter the elements of the matrix
You have to enter 6 values
Enter a value:2
Enter a value:1
Enter a value:0
Enter a value:2
Enter a value:9
Enter a value:1

Matrix :
2	1
0	2
9	1

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:3

Enter the elements of the matrix
You have to enter 6 values
Enter a value:1
Enter a value:0
Enter a value:6
Enter a value:2
Enter a value:3
Enter a value:1

Matrix :
1	0	6
2	3	1

Matrix multiplication is possible
Product is as follows:
4	3	13
4	6	2
11	3	55

**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:15

Invalid choice
**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:5

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:1

Enter the elements of the matrix
You have to enter 2 values
Enter a value:2
Enter a value:1

Matrix :
2
1

Enter the order of the matrix
Enter the number of rows:2
Enter the number of columns:1

Enter the elements of the matrix
You have to enter 2 values
Enter a value:9
Enter a value:0

Matrix :
9
0

Matrix multiplication is not possible
Number of rows of 2nd matrix and number of columns of first matrix are not equal
**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:7

Invalid choice
**********MENU*********
Following operations can be operated on matrices:
1. Check matrix is square matrix
2. Check matrix is upper triangular
3. Compute transpose of matrix
4. Add two matrices
5. Multiply two matrices
6. Exit
Enter your choice:6

Exit*/
