/******************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:6

Title: Library Book data maintenance

College Library maintains records of books. 
Write a program using C++  for following operations:
Add a new book details.
Search a book in library.Sort books based on ISBN numbers.
List all books of specific author.
Use  appropriate data structure.
*******************************************************************************/
#include <iostream>
#include<string>
using namespace std;
class Node           //or class Book
{
    //Name
    //ISBN number
    //Author Name
    //Publication
    long IsbnNo;
    string bookName,publication,author;
    int price;
    Node *next;
    Node(long IsbnNo1,int price1,string bookName1,string author1,string publication1)
    {
        IsbnNo=IsbnNo1;
        price=price1;
        bookName=bookName1;
        author=author1;
        publication=publication1;
        next=NULL;
    }
    
     friend class list;
};
class list          //or class Library
{
    Node *head;
    public:
     list()
    {
        head=NULL;
    }
    
     void Addbook();
     void Searchbook(string author);
     void SortByISBN(); 
     
     void displayBook();
     void SearchbookByISBN(long ISBNb);
    
};
void list::Addbook()
{
    int cnt=0;
    int price1;
    long Isbn1;
    string bookName1,publication1,author1;
    cout<<"\nEnter the name of the book that you want to add:";
    cin>>bookName1;
    cout<<"\nEnter the name of author of the book:";
    cin>>author1;
    cout<<"\nEnter the publication of the book:";
    cin>>publication1;
    cout<<"\nEnter the price of the book:";
    cin>>price1;
    
    cout<<"\nEnter the ISBN of the book:";
    cin>>Isbn1;
   
    Node *temp=new Node(Isbn1,price1,bookName1,author1,publication1);
    
    Node *ptr;
    ptr=head;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        while(ptr->next!=NULL)
        {
           ptr=ptr->next; 
        }
        ptr->next=temp;
    }
        cout<<"\nBook added successfully!";
        displayBook();
        cout<<"\n";
    
    
};
void list::SearchbookByISBN(long Is)
{
   Node *ptr;
   int countB;
   ptr=head;
  
   if(head==NULL)
   {
       cout<<"\nBook not found";
   }
   else
   {
       while(ptr!=NULL)
       {
          
           if(Is==ptr->IsbnNo)
           {
               cout<<"\nBook Details:";
               cout<<"\nBook Name: "<<ptr->bookName;
               cout<<"\nAuthor: "<<ptr->author;
               cout<<"\nPrice: "<<ptr->price;
               cout<<"\nPublication"<<ptr->publication;
               cout<<"\nISBN"<<ptr->IsbnNo;
               break;
           
           }
           ptr=ptr->next;
       }
   }
 };
//function to list all books of a specific author
void list::Searchbook(string Author)
{
    Node *cur;
    int count=0;
    cur=head;
    
    
    //using linear/sequential search
    while(cur!=NULL)
    {
        if(cur->author==Author)
        {
          cout<<"\nBook Details:\n";
          cout<<"\nBook name: "<<cur->bookName<<" ";
          cout<<"\nISBN number: "<<cur->IsbnNo<<" ";
          cout<<"\nPublication: "<<cur->publication<<" ";
          cout<<"\nAuthor: "<<cur->author<<" ";
          cout<<"\nPrice: "<<cur->price;
          count++;
         }
        cur=cur->next;
    }
    if(count==0)
    {
        cout<<"\nBook not found!";
    }
   
    else
    {
        cout<<"Number of books found with same author name are:"<<count;
    }
    
};

/* Function to sort  using bubble sort*/
void list::SortByISBN()          
 {
    Node *ptr1=head;
    Node *ptr2;
   
    Node *t;
    //long IsbnNo;
    //string bookName,publication,author;
    //int price;
    
    while(ptr1 != NULL) 
    {  
       
        ptr2 = ptr1->next; 
                  
        while(ptr2 != NULL) 
        {   
            if(ptr1->IsbnNo > ptr2->IsbnNo) 
            {  
                t->IsbnNo= ptr1->IsbnNo;
                ptr1->IsbnNo = ptr2->IsbnNo; 
                ptr2->IsbnNo = t->IsbnNo;
                
                t->bookName= ptr1->bookName;
                ptr1->bookName = ptr2->bookName; 
                ptr2->bookName = t->bookName;
                
                t->publication= ptr1->publication;
                ptr1->publication = ptr2->publication;  
                ptr2->publication = t->publication;
                
                t->author= ptr1->author;
                ptr1->author = ptr2->author; 
                ptr2->author = t->author;
                
                t->price= ptr1->price;
                ptr1->price = ptr2->price; 
                ptr2->price = t->price;
            }  
            ptr2 = ptr2->next;  
        }  
        ptr1 = ptr1->next;  
    }
    cout<<"Sorted list of books is: ";
    displayBook();
}

void list::displayBook()
{
    Node *ptr;
    ptr=head;
    if(head==NULL)
    {
        cout<<"\nBook list is empty";
    }
    else
    {
        // string IsbnNo,bookName,publication,author;int price;
    
        while(ptr!=NULL)
        {
            cout<<"\n";
            cout<<"\nName of the book: "<<ptr->bookName;
            cout<<"\nAuthor of the book: "<<ptr->author;
            cout<<"\nPublication of the book: "<<ptr->publication;
            cout<<"\nPrice of the book: "<<ptr->price;
            cout<<"\nISBN of the book: "<<ptr->IsbnNo;
            cout<<"\n";
            
            ptr=ptr->next;
        }
    }
    
};
int main()
{
    string authorFromUser;
    long isbn;
    
   
    list obj;
    int choice,data;
    char cont;
    do
    {
    
    cout<<"\n Welcome to College Library :";
    cout<<"\n*******MENU*******";
    cout<<"\n1. Add a new book details";
    cout<<"\n2. Search a book in library by ISBN";
    cout<<"\n3. Sort books based on ISBN numbers";
    cout<<"\n4. List all books of specific author";
    cout<<"\nEnter your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:obj.Addbook();
           break;
           
    case 2: cout<<"\nEnter ISBN to search book in library by ISBN:";
            cin>>isbn;
             obj.SearchbookByISBN(isbn);
            break;
           
    case 3:cout<<"\nSort books based on ISBN numbers";
           obj.SortByISBN();
           break;
           
    case 4:cout<<"\nEnter author name  to search a book in the library:";
           cin>>authorFromUser;
           obj.Searchbook(authorFromUser);
           break;
           
    default:cout<<"\nIncorrect choice try again";
           break;
    }
    cout<<"\nDo you want to continue?:(y/n)";
    cin>>cont;
    }while(cont=='y');
    return 0;
}
/*OUTPUT



 Welcome to College Library :
*******MENU*******
1. Add a new book details
2. Search a book in library by ISBN
3. Sort books based on ISBN numbers
4. List all books of specific author
Enter your choice:1

Enter the name of the book that you want to add:HarryPotter

Enter the name of author of the book:JKRowling

Enter the publication of the book:Bloomsbury

Enter the price of the book:299

Enter the ISBN of the book:8798678

Book added successfully!

Name of the book: HarryPotter
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 299
ISBN of the book: 8798678


Do you want to continue?:(y/n)y

 Welcome to College Library :
*******MENU*******
1. Add a new book details
2. Search a book in library by ISBN
3. Sort books based on ISBN numbers
4. List all books of specific author
Enter your choice:1

Enter the name of the book that you want to add:Ickabog

Enter the name of author of the book:JKRowling

Enter the publication of the book:Bloomsbury

Enter the price of the book:150

Enter the ISBN of the book:8456345

Book added successfully!

Name of the book: HarryPotter
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 299
ISBN of the book: 8798678


Name of the book: Ickabog
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 150
ISBN of the book: 8456345


Do you want to continue?:(y/n)y

 Welcome to College Library :
*******MENU*******
1. Add a new book details
2. Search a book in library by ISBN
3. Sort books based on ISBN numbers
4. List all books of specific author
Enter your choice:1

Enter the name of the book that you want to add:TheKiteRunner

Enter the name of author of the book:KhaledHosseini

Enter the publication of the book:RiverheadBooks

Enter the price of the book:289

Enter the ISBN of the book:7845231

Book added successfully!

Name of the book: HarryPotter
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 299
ISBN of the book: 8798678


Name of the book: Ickabog
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 150
ISBN of the book: 8456345


Name of the book: TheKiteRunner
Author of the book: KhaledHosseini
Publication of the book: RiverheadBooks
Price of the book: 289
ISBN of the book: 7845231


Do you want to continue?:(y/n)y

 Welcome to College Library :
*******MENU*******
1. Add a new book details
2. Search a book in library by ISBN
3. Sort books based on ISBN numbers
4. List all books of specific author
Enter your choice:1

Enter the name of the book that you want to add:PathwaysToLight

Enter the name of author of the book:PrakashAmte

Enter the publication of the book:Pigeons

Enter the price of the book:120

Enter the ISBN of the book:9123567

Book added successfully!

Name of the book: HarryPotter
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 299
ISBN of the book: 8798678


Name of the book: Ickabog
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 150
ISBN of the book: 8456345


Name of the book: TheKiteRunner
Author of the book: KhaledHosseini
Publication of the book: RiverheadBooks
Price of the book: 289
ISBN of the book: 7845231


Name of the book: PathwaysToLight
Author of the book: PrakashAmte
Publication of the book: Pigeons
Price of the book: 120
ISBN of the book: 9123567


Do you want to continue?:(y/n)y

 Welcome to College Library :

*******MENU*******
1. Add a new book details
2. Search a book in library by ISBN
3. Sort books based on ISBN numbers
4. List all books of specific author
Enter your choice:2

Enter ISBN to search book in library by ISBN:9123567

Book Details:
Book Name: PathwaysToLight
Author: PrakashAmte
Price: 120
PublicationPigeons
ISBN9123567
Do you want to continue?:(y/n)y

 Welcome to College Library :
*******MENU*******
1. Add a new book details
2. Search a book in library by ISBN
3. Sort books based on ISBN numbers
4. List all books of specific author
Enter your choice:4

Enter author name  to search a book in the library:JKRowling

Book Details:

Book name: HarryPotter 
ISBN number: 8798678 
Publication: Bloomsbury 
Author: JKRowling 
Price: 299
Book Details:

Book name: Ickabog 
ISBN number: 8456345 
Publication: Bloomsbury 
Author: JKRowling 
Price: 150Number of books found with same author name are:2
Do you want to continue?:(y/n)y

 Welcome to College Library :
*******MENU*******
1. Add a new book details
2. Search a book in library by ISBN
3. Sort books based on ISBN numbers
4. List all books of specific author
Enter your choice:3

Sort books based on ISBN numbers

Name of the book: TheKiteRunner
Author of the book: KhaledHosseini
Publication of the book: RiverheadBooks
Price of the book: 289
ISBN of the book: 7845231

Name of the book: Ickabog
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 150
ISBN of the book: 8456345

Name of the book: HarryPotter
Author of the book: JKRowling
Publication of the book: Bloomsbury
Price of the book: 299
ISBN of the book: 8798678

Name of the book: PathwaysToLight
Author of the book: PrakashAmte
Publication of the book: Pigeons
Price of the book: 120
ISBN of the book: 9123567

Do you want to continue?:(y/n)
n*/

/*TIME COMPLEXITY
Addbook()=O(n)
SearchbookByISBN()=O(n)
SortByISBN()=O(n) for best case and O(n^2) for worst case
displayBook()=O(n)
SearchbookByISBN()=O(n)*/ 