/* Roll no:2330
  Name:Prajakta Deokule
  CNumber: C22019221332
  Assignment nnumber:2*/
  
 /* Problem statement:
 Department of Computer Engineering has 'CSI student branch'.
Students of second, third and final year can subscribe to membership.
Design a system to maintain CSI student branch membership information.
Choose appropriate data structure. Write a program using C++ for following operations:
Add new members.
Compute total number of members at branch.Display member information.
Remove member details*/

#include<iostream>
using namespace std;
class node
{
    //store data
    public:
    string Name;
    int Roll,Year;
    //pointer
    node *link;
    public:
    node(string name,int rn,int year)
    {   //initialize all variables
        Name=name;
        Roll=rn;
        Year=year;
        link=NULL;
    }
    friend class list;
};
class list
{
    node *head;
    public:
    list()
    {
        head=NULL;
    }
    //function declaration
    public:
    void createMember();
    void insertMember(int); 
    void deleteMember();
    void displayMembers();
    int CountNofMembers();
};

//function to add members in the CSI branch
void list::createMember()
{
    node *ptr;
    char option;
    ptr=head;
    do
    {
        int sroll,syear;
        string sname;
        cout<<"\nEnter roll number to enter into the list:\n";
        cin>>sroll;
        while(true)
        {
          cout<<"Enter year of student to enter into the list(2 or 3 or 4):\n";
          cin>>syear;
           if(syear==2||syear==3||syear==4)
           {
            break;
           }
            else
            {
               cout<<"Incorrect information entered try again\n";
            }
        }
        cout<<"Enter name of student to enter into the list:\n";
        cin>>sname;
        
        node *temp=new node(sname,sroll,syear);
        
        if(head==NULL)
        {
            head=temp;
            cout<<"Information added successfully\n";
        }
        else 
        {
            //traverse to last node and add node after that
            ptr=head;
            while(ptr->link!=NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=temp;
            cout<<" Information added successfully\n";
        }
    cout<<"\n*****************************************************\n";
    cout<<"Do you want to continue adding nodes? if yes enter y:";    
    cin>>option; 
    cout<<"\n******************************************************";
    }while(option=='y'||option=='Y');
}
//display the data
void list::displayMembers()
{
    node *ptr=head;
   
    if(ptr==NULL)
    cout<<"\nThe membership list is empty";
    else
    {
         cout<<"\n*********************************";
         cout<<"\nDisplay of membership details:";
         cout<<"\n*********************************";
         while(ptr!=NULL)
         {
           cout<<"\nRoll number of member is:"<<ptr->Roll;
           cout<<"\nName of member is:"<<ptr->Name;
           cout<<"\nThe member is in year:"<<ptr->Year<<"\n";
           ptr=ptr->link;
         }
         cout<<"*********************************";
    }
}

//insert new member information at particular position
void list::insertMember(int position)
{
    int sr,sy;
    string sn;
    //accept data to insert
    while(true)
    {
       cout<<"\nEnter year of student to enter into the list(2 or 3 or 4):";
       cin>>sy;
       if(sy==2||sy==3||sy==4)
       {
            break;
       }
       else
       {
         cout<<"Incorrect information entered try again\n";
       }
    }
    cout<<"Enter roll number to enter into the list:";
    cin>>sr;
    cout<<"Enter name of student to enter into the list:";
    cin>>sn;
    
    node *cur,*prev;
    cur = head;  
    prev=NULL;
   // create a new node
    node *temp=new node(sn,sr,sy);
        
    //inserting node at head position    
    if (head==NULL) 
    {
        head = temp;
    }
    else
    {  //open outer else
        
         //inserting node at head position    
        if(position==1)
        {
            temp->link=head;
            head=temp;
        }
        
        else  
        {
            
            //inserting node at the position 
            //here node is not head 
            cur=head;
            int i=1;
            while(i<position) 
            {
               prev=cur;
               if(cur->link==NULL)
               {
                cur=NULL;  
                 i++;
                break;
               }
               cur=cur->link;
                i++;
            }
             prev->link=temp;
             temp->link=cur;
             cout<<"Inserted the details at position \n"<<i;
        }
        
    }//close outer else
}//close insert function

//function to count the number of members in the CSI branch
int list::CountNofMembers()
{
    int count=0;
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    return count;
}
//delete the node of given Roll no

void list::deleteMember()
{
    node *ptr,*prev;
    int rollNoToDelete;
    prev=NULL;
    ptr=head;
    cout<<"\nEnter roll number to delete:";
    cin>>rollNoToDelete;
    int j=1;
    while(ptr!=NULL && ptr->Roll!=rollNoToDelete)
    {
        prev=ptr;
        ptr=ptr->link;
        j++;
    }
    if(ptr==NULL)
    cout<<"\n No such element found";
    else
    {
        //ptr is the head and we have to delete ptr to delete
        if(prev==NULL)
        {
            head=ptr->link;
            ptr->link=NULL;
            delete(ptr);
            cout<<"Deleted member at position "<<j;
        }
        else
        {
           prev->link=ptr->link;
           ptr->link=NULL;
           delete(ptr);
           cout<<"Deleted member at position "<<j;
        }
    }
}

int main()
{
    list obj; //object of list class
    int choice,noM,cM;
    char ans;
    cout<<"\n----------------------------------------------------------------";
    cout<<"\n**********************Create members account*********************";
    cout<<"\n----------------------------------------------------------------";
        //Call create function
        obj.createMember();
    //menu driven program
    do
    {
       
        
        cout<<"\n*****************************MENU******************************";
        cout<<"\n 1.Insert a new member account\n 2.Display the accounts of the members";
        cout<<"\n 3.Delete a member account";
        cout<<"\n 4.Display the number of members in the CSI branch";
        cout<<"\n----------------------------------------------------------------";
        cout<<"\nEnter your choice:";
        cin>>choice;
        cout<<"\n----------------------------------------------------------------";
        switch(choice)
        {
        case 1://Call insert function
               int pos;
               cout<<"\nPosition starts from 1";
               cout<<"\nEnter position to insert the member details:";
               cin>>pos;
               noM=obj.CountNofMembers();
               if(pos<=0||(pos>noM+1))
               {
                   cout<<"\nInvalid position!";
               }
               else
               {
                   obj.insertMember(pos);
               }   
               break;
               break;
        case 2://Call display function
               obj.displayMembers();
               break;
        case 3://Call delete function
                obj.deleteMember();
               break;
        case 4:cM=obj.CountNofMembers();
                cout<<"\nThe number of members in the CSI branch are "<<cM;
                break;
        default:cout<<"\nEnter Valid option!!";
                break;
        }
        cout<<"\n----------------------------------------------------------------";
        cout<<"\nDo you want to continue?if yes,enter Y:";
        cin>>ans;
        cout<<"\n----------------------------------------------------------------";
    }while(ans=='Y'||ans=='y');
    cout<<"\nExit";
}
/*

----------------------------------------------------------------
**********************Create members account*********************
----------------------------------------------------------------
Enter roll number to enter into the list:
1
Enter year of student to enter into the list(2 or 3 or 4):
4
Enter name of student to enter into the list:
Shravani
Information added successfully

*****************************************************
Do you want to continue adding nodes? if yes enter y:y

******************************************************
Enter roll number to enter into the list:
3
Enter year of student to enter into the list(2 or 3 or 4):
2
Enter name of student to enter into the list:
Yashika
 Information added successfully

*****************************************************
Do you want to continue adding nodes? if yes enter y:y

******************************************************
Enter roll number to enter into the list:
5
Enter year of student to enter into the list(2 or 3 or 4):
5
Incorrect information entered try again
Enter year of student to enter into the list(2 or 3 or 4):
3
Enter name of student to enter into the list:
Isha
 Information added successfully

*****************************************************
Do you want to continue adding nodes? if yes enter y:y

******************************************************
Enter roll number to enter into the list:
7
Enter year of student to enter into the list(2 or 3 or 4):
3
Enter name of student to enter into the list:
Ovi
 Information added successfully

*****************************************************
Do you want to continue adding nodes? if yes enter y:n

******************************************************
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:4

----------------------------------------------------------------
The number of members in the CSI branch are 4
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:1
Name of member is:Shravani
The member is in year:4

Roll number of member is:3
Name of member is:Yashika
The member is in year:2

Roll number of member is:5
Name of member is:Isha
The member is in year:3

Roll number of member is:7
Name of member is:Ovi
The member is in year:3
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:1

----------------------------------------------------------------
Position starts from 1
Enter position to insert the member details:0

Invalid position!
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:1

----------------------------------------------------------------
Position starts from 1
Enter position to insert the member details:6

Invalid position!
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:1

----------------------------------------------------------------
Position starts from 1
Enter position to insert the member details:1

Enter year of student to enter into the list(2 or 3 or 4):2
Enter roll number to enter into the list:9
Enter name of student to enter into the list:Prajakta

----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:4

----------------------------------------------------------------
The number of members in the CSI branch are 5
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:9
Name of member is:Prajakta
The member is in year:2

Roll number of member is:1
Name of member is:Shravani
The member is in year:4

Roll number of member is:3
Name of member is:Yashika
The member is in year:2

Roll number of member is:5
Name of member is:Isha
The member is in year:3

Roll number of member is:7
Name of member is:Ovi
The member is in year:3
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:3

----------------------------------------------------------------
Enter roll number to delete 5
Deleted member at position 4
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:9
Name of member is:Prajakta
The member is in year:2

Roll number of member is:1
Name of member is:Shravani
The member is in year:4

Roll number of member is:3
Name of member is:Yashika
The member is in year:2

Roll number of member is:7
Name of member is:Ovi
The member is in year:3
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:3

----------------------------------------------------------------
Enter roll number to delete 7
Deleted member at position 4
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:4

----------------------------------------------------------------
The number of members in the CSI branch are 3
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:9
Name of member is:Prajakta
The member is in year:2

Roll number of member is:1
Name of member is:Shravani
The member is in year:4

Roll number of member is:3
Name of member is:Yashika
The member is in year:2
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:3

----------------------------------------------------------------
Enter roll number to delete 1
Deleted member at position 2
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:9
Name of member is:Prajakta
The member is in year:2

Roll number of member is:3
Name of member is:Yashika
The member is in year:2
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:1

----------------------------------------------------------------
Position starts from 1
Enter position to insert the member details:3

Enter year of student to enter into the list(2 or 3 or 4):4
Enter roll number to enter into the list:2
Enter name of student to enter into the list:Rasika
Inserted the details at position 
3
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:9
Name of member is:Prajakta
The member is in year:2

Roll number of member is:3
Name of member is:Yashika
The member is in year:2

Roll number of member is:2
Name of member is:Rasika
The member is in year:4
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:1

----------------------------------------------------------------
Position starts from 1
Enter position to insert the member details:1

Enter year of student to enter into the list(2 or 3 or 4):4
Enter roll number to enter into the list:6
Enter name of student to enter into the list:Tanaya

----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:6
Name of member is:Tanaya
The member is in year:4

Roll number of member is:9
Name of member is:Prajakta
The member is in year:2

Roll number of member is:3
Name of member is:Yashika
The member is in year:2

Roll number of member is:2
Name of member is:Rasika
The member is in year:4
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:3

----------------------------------------------------------------
Enter roll number to delete 6
Deleted member at position 1
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:2

----------------------------------------------------------------
*********************************
Display of membership details:
*********************************
Roll number of member is:9
Name of member is:Prajakta
The member is in year:2

Roll number of member is:3
Name of member is:Yashika
The member is in year:2

Roll number of member is:2
Name of member is:Rasika
The member is in year:4
*********************************
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:4

----------------------------------------------------------------
The number of members in the CSI branch are 3
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:y

----------------------------------------------------------------
*****************************MENU******************************
1.Insert a new member account
2.Display the accounts of the members
3.Delete a member account
4.Display the number of members in the CSI branch
----------------------------------------------------------------
Enter your choice:5

----------------------------------------------------------------
Enter Valid option!!
----------------------------------------------------------------
Do you want to continue?if yes,enter Y:n

----------------------------------------------------------------
Exit
*******TIME COMPLEXITY***********
void createMember()=O(n)
void insertMember(int)=O(n); 
void deleteMember()=O(n);
void displayMembers()=O(n);
int CountNofMembers()=O(n);
*/






