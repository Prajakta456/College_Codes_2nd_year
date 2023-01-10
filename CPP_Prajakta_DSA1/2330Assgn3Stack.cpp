/***************************************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:3 (Stack)
Implement Stack as ADT using linked list or array. Use the same ADT to evaluate a given
postfix expression
****************************************************************************************************/
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class Stack
{
    int top,size;
    int value[50];

    public:
    Stack(int maxNoOfElements)
    {
        //constructor
        top=-1;
        size=maxNoOfElements;
    }

//push function
void push(int data)
{
    top++;
    value[top]=data;
}

//pop function
int pop()
{
    int elementPopped=value[top];
    top--;
    return(elementPopped);

}

//isEmpty() function to check if stack is empty
int isEmpty()
{
    if(top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//isFull() function to check if stack is full
int isFull()
{
    if(top==size-1)
    {
         return 1;
    }
    else
    {
        return 0;
    }
}

//findTop() function to get the top element of the stack
int findTop()
{
    return(value[top]);
}

//display function to display the stack elements
void display()
{
    if(top==-1)
    cout<<"\nStack is empty";
    else
    {
      cout<<"\n Stack elements:";
      int i=top;
      while(i>=0)
      {
        cout<<value[i]<<" ";
        i--;
       }
    }
}
};

/*here conditions to check if "a postfix expression is valid":
1) The first two elements are operands(values)
2) The last element is an operator*/
int main()
{
	    int s,choice,numToPush,PoppedNum,checkFull,checkEmpty,topElement;
	    int lengthExpression,count,result=0;
	    string postexpr;
	    while(true)
	    {
	        cout<<"\nEnter size of stack:(Max size allowed is 25)";
	        cin>>s;
	        if(s<=25)
	        {
	            break;
	        }
	        else
	        {
	            cout<<"Stack size exceeded try again";
	            continue;
	        }
	    }
	    Stack obj(s);
	    Stack expression(25);
	    do
	    {
		  cout<<"\n**************MENU*************";
		  cout<<"\n 1.Push element into stack";
		  cout<<"\n 2.Pop element from stack";
		  cout<<"\n 3.Display stack";
		  cout<<"\n 4.Print top of stack";
		  cout<<"\n 5.Evaluate a postfix expression";
		  cout<<"\n 6.Exit";
		  cout<<"\n Enter your choice:";
		  cin>>choice;
		  switch(choice)
		  {
		      case 1:cout<<"\n Enter element to push into stack:";
		             checkFull=obj.isFull();
		             if(checkFull==1)
		             {
		               cout<<"Stack full condition!Cannot insert element in stack";
		             }
		             else
		             {
		               cin>>numToPush;
		               obj.push(numToPush);
		             }
		             break;
		      case 2:checkEmpty=obj.isEmpty();
		             if(checkEmpty==1)
		             {
		                 cout<<"Stack is empty!Cannot pop element";
		             }
		             else
		             {
		               PoppedNum=obj.pop();
		               cout<<"\nPopped element: "<<PoppedNum;
		             }
		             break;
		      case 3:obj.display();
		             break;
		      case 4:checkEmpty=obj.isEmpty();
		             if(checkEmpty==1)
		             {
		               cout<<"\nStack is empty,top does not contain any element";
		             }
		             else
		             {
		               topElement=obj.findTop();
		               cout<<"Top of stack contains:"<<topElement;
		             }
		             break;
		      case 5:do
		             {
		               cout<<"\nEnter postfix expression to evaluate it(max size is 25 characters)";
		               cout<<"\nEnter only single digit numbers as operands";
		               cout<<"\nEnter only +,-,*,/,^ as operands\n";
		               cin>>postexpr;
		               char ch1=postexpr.at(0);
		               char ch2=postexpr.at(1);
		               lengthExpression=postexpr.length();
		               char chl=postexpr.at(lengthExpression-1);
		               int i1=(int)ch1;
		               int i2=(int)ch2;
		               count=0;
		               if(lengthExpression<=25)
		               {
		                   count++;
		               }
		               if((i1>=48&&i1<=57)&&(i2>=48&&i2<=57))
		               {
		                   count++;
		               }
		               if((chl=='+')||(chl=='-')||(chl=='*')||(chl=='/')||(ch1=='^'))
		               {
		                  count++;
		               }
		             }while(count!=3);
		             for(int j=0;j<postexpr.length();j++)
		             {
		                 //open for loop
		                 char ch=postexpr.at(j);
		                 int asciiCh=(int)postexpr.at(j);
		                 if(asciiCh>=48&&asciiCh<=57)
		                 {
		                     int num=asciiCh-48;
		                     expression.push(num);
		                 }
		                 else if((ch=='+')||(ch=='-')||(ch=='*')||(ch=='/')||(ch=='^'))
		                 {
		                     int i2=expression.pop();
		                     int i1=expression.pop();
		                     int ans=0;
		                     switch(ch)
		                     {  //open switch case
		                         case'+':ans=i1+i2;
		                                 expression.push(ans);
		                                 break;
		                         case'-':ans=i1-i2;
		                                 expression.push(ans);
		                                 break;
		                         case'*':ans=i1*i2;
		                                 expression.push(ans);
		                                 break;
		                         case'/':ans=i1/i2;
		                                 expression.push(ans);
		                                 break;
		                         case'^':ans=pow(i1,i2);
		                                 expression.push(ans);
		                                 break;
		                      }    //close switch case
		                 }
		              }//close for loop
		              result=expression.pop();
		              cout<<"\nThe value of the evaluated postfix expression is"<<result;
		              break;
		      case 6:cout<<"\nExit";
		             break;
		      default:cout<<"\nInvalid choice";
		              break;
		       }

	    }while(choice!=6);
		return 0;
}
/*
//***********OUTPUT************


Enter size of stack:(Max size allowed is 25)29
Stack size exceeded try again
Enter size of stack:(Max size allowed is 25)10

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:2
Stack is empty!Cannot pop element
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:3

Stack is empty
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:4

Stack is empty,top does not contain any element
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:8

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:9

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:3

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:7

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:56

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:4

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:2

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:6

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:5

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1
0
 Enter element to push into stack:0

**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:1

 Enter element to push into stack:Stack full condition!Cannot insert element in stack
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:4
Top of stack contains:0
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:2

Popped element: 0
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:3

 Stack elements:5 6 2 4 56 7 3 9 8
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:4
Top of stack contains:5
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:2

Popped element: 5
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:5

Enter postfix expression to evaluate it(max size is 25 characters)
Enter only single digit numbers as operands
Enter only +,-,*,/,^ as operands
23+9-1

Enter postfix expression to evaluate it(max size is 25 characters)
Enter only single digit numbers as operands
Enter only +,-,*,/,^ as operands
24+1^8-2+

The value of the evaluated postfix expression is0
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:5

Enter postfix expression to evaluate it(max size is 25 characters)
Enter only single digit numbers as operands
Enter only +,-,*,/,^ as operands
+5-8+4*5

Enter postfix expression to evaluate it(max size is 25 characters)
Enter only single digit numbers as operands
Enter only +,-,*,/,^ as operands
7-80+9

Enter postfix expression to evaluate it(max size is 25 characters)
Enter only single digit numbers as operands
Enter only +,-,*,/,^ as operands
7+1

Enter postfix expression to evaluate it(max size is 25 characters)
Enter only single digit numbers as operands
Enter only +,-,*,/,^ as operands
29+3-

The value of the evaluated postfix expression is8
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:7

Invalid choice
**************MENU*************
 1.Push element into stack
 2.Pop element from stack
 3.Display stack
 4.Print top of stack
 5.Evaluate a postfix expression
 6.Exit
 Enter your choice:6

Exit

*****TIME COMPLEXITY*******

void push(int data)=O(1)
int pop()=O(1)
int isEmpty()=O(1)
int isFull()=O(1)
int findTop()=O(1)
void display()=O(n)

*/




