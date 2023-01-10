/*
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:4
Implement Queue as ADT using array/linked list
Use Queue ADT to simulate waiting list' operations of railway reservation system
*/

/*Here 2 queues are maintained
one is for confirm bookings where bookings are made at the start
after the confirm booking tickets are over and still more passengers register then
the bookings are placed in the waiting queue*/

/*If a passenger from confirm bookings list cancels his booking then a passenger from
waiting list gets the booking of the canceled passenger
If waiting list is empty at the time when passenger cancels his booking then
whenever the next passenger is going to enter the waiting list he gets the booking
of the canceled passenger
*/

#include <iostream>
using namespace std;
class PassengerBooking
{
    public:
    int bookingId;
    string name;
    int age;
    string contactNo;
    char gender;
    string emailId;

    //constructor
    PassengerBooking()
   {
     bookingId=0;
     name="";
     age=0;
     contactNo="";
     gender='\u0000';
     emailId="";
   }

    //function to accept passenger details
  void acceptDetails()
  {
    cout<<"\nPassenger Details:";
    cout<<"\nEnter your name:";
    cin>>name;
    cout<<"\nEnter your age:";
    cin>>age;
    cout<<"\nEnter your contact number:";
    cin>>contactNo;
    cout<<"\nEnter your gender:";
    cout<<"\nEnter F for female and M for male:";
    cin>>gender;
    cout<<"\nEnter your email id:";
    cin>>emailId;
    cout<<"\nEnter your booking Id:";
    cin>>bookingId;
  }

   //function to display passenger details
   void displayDetails()
  {
    cout<<"\nPassenger Details:";
    cout<<"\nName:"<<name;
    cout<<"\nAge:"<<age;
    cout<<"\nContact number:"<<contactNo;
    cout<<"\nGender:"<<gender;
    cout<<"\nEmail id:"<<emailId;
    cout<<"\nBooking Id:"<<bookingId;
   }
};
class RailwayQueue
{
    public:
    int front,rear;
    int maxSize;
    PassengerBooking tNo[10];

     RailwayQueue(int sizeofQueue)
    {
        front=-1;
        rear=-1;
        maxSize=sizeofQueue;
    }

    //check if queue is empty
    int isEmpty()
    {
        if(front==-1 && rear==-1)
        {
            return 1;
        }
        else
        return 0;
    }

    //check if queue is full
    int isFull()
    {
        if(rear==maxSize-1)
        return 1;
        else
        return 0;
    }

    //Enqueue new passenger to queue
    void enqueue(PassengerBooking Newpassenger)
    {
        if(isEmpty())
        {
            front=rear=0;
            tNo[front]=Newpassenger;
        }
        else
        {
        rear=rear+1;
        tNo[rear]=Newpassenger;
        }
    }

     //cancel passenger reservation based on ticket number
    int searchAndDelete(int TicketToDelete)
    {
        int indexDeleted=0;
        int i=front;
        while(i<=rear)
        {
            if(tNo[i].bookingId==TicketToDelete)
            {
                cout<<"\nThe canceled booking is\n";
                tNo[i].displayDetails();
                tNo[i].name="";
                tNo[i].age=0;
                tNo[i].contactNo="";
                tNo[i].emailId="";
                tNo[i].bookingId=0;
                tNo[i].gender='\u0000';
                indexDeleted=i;

               }
            i++;
        }
     return indexDeleted;
    }

    //search if ticket is found in confirm list to cancel passenger reservation based on ticket number
    int foundTicketTodelete(int TicketToDelete)
    {
        int found=0;
        int i=front;
        while(i<=rear)
        {
            if(tNo[i].bookingId==TicketToDelete)
            {
                found++;
                break;
            }
            i++;
        }
        return found;
    }

    //deque Passenger booking
    PassengerBooking deque()
    {
         PassengerBooking ptr;

        if(front<rear)
        {
            ptr=tNo[front];
            front++;
            //cout<<"\nPassenger dequed is";
            //ptr.displayDetails();
        }
        else if(front==rear)
        {
          ptr=tNo[front];
          //cout<<"\nPassenger dequed is";
          //ptr.displayDetails();
          front=-1;
          rear=-1;
        }
        return ptr;
    }

     //display Passenger bookings in queue
    void displayBookings()
    {
        PassengerBooking objtemp;
        if(isEmpty())
        {
            cout<<"\nThere are no passengers in the queue"<<endl;
        }
        else
        {
            for(int i=0;i<=rear;i++)
           {
            objtemp=tNo[i];
            objtemp.displayDetails();
            cout<<"\n";
           }
        }
    }


};
int main()
{
    int s,choice,tndelete,found,indexDeleted1,flag=0;
    while(true)
    {   //open while
       cout<<"\nEnter the maximum number of bookings in confirm queue:(MAX 10)";
       cin>>s;
       if(s<=10)
       {
        break;
       }
       else
       continue;
    }//close while

    PassengerBooking ptr2;
    PassengerBooking obj;
    RailwayQueue waitinglist(s);
    RailwayQueue confirmlist(s);

   do
   {
   cout<<"\n*********MENU*********";
   cout<<"\n 1.Book a railway ticket";
   cout<<"\n 2.Cancel a railway ticket form confirm list";
   cout<<"\n 3.Display all the tickets in waiting list";
   cout<<"\n 4.Display all the tickets in confirm list";
   cout<<"\n 5.Exit";
   cout<<"\nEnter your choice:";
   cin>>choice;

   //open switch
   switch(choice)
   {
       case 1:obj.acceptDetails();

              if(!(confirmlist.isFull()))
              {
                confirmlist.enqueue(obj);
              }
              else if(confirmlist.isFull())
              {
                  if(!(waitinglist.isFull()))
                  {
                        waitinglist.enqueue(obj);
                  }

                  else if(waitinglist.isFull())
                  {
                      cout<<"\nSorry all tickets in waiting list and confirm list are full";
                      cout<<"\nCannot book ticket";
                  }

              }


              break;
       case 2:cout<<"\nEnter the ticket number to cancel reservation:";
              cin>>tndelete;
              if(confirmlist.isEmpty())
              {
                  cout<<"\nConfirm booking list is empty";
                  cout<<"\nNo ticket booked to cancel";
              }
               else
               {
                 found=confirmlist.foundTicketTodelete(tndelete);
                  if(found==1)
                   {
                       indexDeleted1=confirmlist.searchAndDelete(tndelete);
                       flag++;

                       if(waitinglist.isEmpty())
                       {
                       cout<<"\nTicket deleted from confirm list and Waiting list is empty ";
                       cout<<"\nSo could not transfer a ticket from waiting to confirm list";
                       }
                       else
                       {
                       ptr2=waitinglist.deque();
                       confirmlist.tNo[indexDeleted1]=ptr2;
                       cout<<"Transfered the following ticket from waiting to confirm list";
                       ptr2.displayDetails();
                       }
                    }
                  else
                  {
                    cout<<"Ticket number does not exist in Confirm booking list";
                    cout<<"\nCould not cancel reservation";
                  }
                }
              break;
       case 3:if(waitinglist.isEmpty())
              {
               cout<<"\nWaiting list is empty!";
              }
              else
              {
              cout<<"\nWaiting list:\n";
              waitinglist.displayBookings();
              }
              break;
       case 4:if(confirmlist.isEmpty())
              {
               cout<<"\nConfirm bookings list is empty!";
              }
              else
              {
              cout<<"\nConfirm booking list:\n";
              confirmlist.displayBookings();
              }
              break;
       case 5:cout<<"Thank you for visiting!";
              break;
       default:cout<<"\nInvalid choice!";
              break;
              }  //close switch
              if(flag>0)
              {
                  if(!(waitinglist.isEmpty()))
                  {
                    PassengerBooking ptr;
                    ptr=waitinglist.deque();
                    confirmlist.tNo[indexDeleted1]=ptr;
                    flag=0;
                  }
              }


   }while(choice!=5);
   return 0;

}


//*****OUTPUT******

/*Enter the maximum number of bookings in confirm queue:(MAX 10)3

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Rohit

Enter your age:34

Enter your contact number:8765789868

Enter your gender:
Enter F for female and M for male:m

Enter your email id:rojit@yahoo.com

Enter your booking Id:3

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Purva

Enter your age:20

Enter your contact number:7378858479

Enter your gender:
Enter F for female and M for male:f

Enter your email id:purva@yahoo.com

Enter your booking Id:4

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Yashika

Enter your age:35

Enter your contact number:9923200909

Enter your gender:
Enter F for female and M for male:f

Enter your email id:yashika77@gmail.com

Enter your booking Id:6

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:3

Waiting list is empty!
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:4

Confirm booking list:

Passenger Details:
Name:Rohit
Age:34
Contact number:8765789868
Gender:m
Email id:rojit@yahoo.com
Booking Id:3

Passenger Details:
Name:Purva
Age:20
Contact number:7378858479
Gender:f
Email id:purva@yahoo.com
Booking Id:4

Passenger Details:
Name:Yashika
Age:35
Contact number:9923200909
Gender:f
Email id:yashika77@gmail.com
Booking Id:6
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:2

Enter the ticket number to cancel reservation:6

The canceled booking is

Passenger Details:
Name:Yashika
Age:35
Contact number:9923200909
Gender:f
Email id:yashika77@gmail.com
Booking Id:6
Ticket deleted from confirm list and Waiting list is empty
So could not transfer a ticket from waiting to confirm list
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Urvi

Enter your age:31

Enter your contact number:6789897890

Enter your gender:
Enter F for female and M for male:f

Enter your email id:urvi@yahoo.com

Enter your booking Id:9

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:4

Confirm booking list:

Passenger Details:
Name:Rohit
Age:34
Contact number:8765789868
Gender:m
Email id:rojit@yahoo.com
Booking Id:3

Passenger Details:
Name:Purva
Age:20
Contact number:7378858479
Gender:f
Email id:purva@yahoo.com
Booking Id:4

Passenger Details:
Name:Urvi
Age:31
Contact number:6789897890
Gender:f
Email id:urvi@yahoo.com
Booking Id:9
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:3

Waiting list is empty!
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Harsh

Enter your age:24

Enter your contact number:7689234323

Enter your gender:
Enter F for female and M for male:m

Enter your email id:harsh34@gmail.com

Enter your booking Id:12

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:3

Waiting list:

Passenger Details:
Name:Harsh
Age:24
Contact number:7689234323
Gender:m
Email id:harsh34@gmail.com
Booking Id:12
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:4

Confirm booking list:

Passenger Details:
Name:Rohit
Age:34
Contact number:8765789868
Gender:m
Email id:rojit@yahoo.com
Booking Id:3

Passenger Details:
Name:Purva
Age:20
Contact number:7378858479
Gender:f
Email id:purva@yahoo.com
Booking Id:4

Passenger Details:
Name:Urvi
Age:31
Contact number:6789897890
Gender:f
Email id:urvi@yahoo.com
Booking Id:9
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Parth

Enter your age:50

Enter your contact number:9970069859

Enter your gender:
Enter F for female and M for male:m

Enter your email id:parth@gmail.com

Enter your booking Id:14

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:3

Waiting list:

Passenger Details:
Name:Harsh
Age:24
Contact number:7689234323
Gender:m
Email id:harsh34@gmail.com
Booking Id:12
Passenger Details:
Name:Parth
Age:50
Contact number:9970069859
Gender:m
Email id:parth@gmail.com
Booking Id:14
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Ishika

Enter your age:40

Enter your contact number:7658986789

Enter your gender:
Enter F for female and M for male:f

Enter your email id:ishika@gmail.com

Enter your booking Id:15

*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:4

Confirm booking list:

Passenger Details:
Name:Rohit
Age:34
Contact number:8765789868
Gender:m
Email id:rojit@yahoo.com
Booking Id:3

Passenger Details:
Name:Purva
Age:20
Contact number:7378858479
Gender:f
Email id:purva@yahoo.com
Booking Id:4

Passenger Details:
Name:Urvi
Age:31
Contact number:6789897890
Gender:f
Email id:urvi@yahoo.com
Booking Id:9
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:3

Waiting list:

Passenger Details:
Name:Harsh
Age:24
Contact number:7689234323
Gender:m
Email id:harsh34@gmail.com
Booking Id:12

Passenger Details:
Name:Parth
Age:50
Contact number:9970069859
Gender:m
Email id:parth@gmail.com
Booking Id:14

Passenger Details:
Name:Ishika
Age:40
Contact number:7658986789
Gender:f
Email id:ishika@gmail.com
Booking Id:15
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:1

Passenger Details:
Enter your name:Om

Enter your age:21

Enter your contact number:9890989098

Enter your gender:
Enter F for female and M for male:m

Enter your email id:om@yahoo.com

Enter your booking Id:16

Sorry all tickets in waiting list and confirm list are full
Cannot book ticket
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:7
Invalid choice!
*********MENU*********
1.Book a railway ticket
2.Cancel a railway ticket form confirm list
3.Display all the tickets in waiting list
4.Display all the tickets in confirm list
5.Exit
Enter your choice:5
Thank you for visiting!
*/
/*
*****TIME COMPLEXITY*****
acceptDetails()=O(1)
displayDetails()=O(1)
IsEmpty()=O(1)
IsFull()=O(1)
searchAndDelete()=O(n)
foundTicketTodelete()=O(n)
enqueue()=O(1)
deque()=O(1)
displayBookings()=O(n)
*/
