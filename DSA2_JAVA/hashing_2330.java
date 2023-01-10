/**************************************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:6

Implement hash table for storing bank account
information. 
Write a program for inserting customer details for a bank and solve 
collision using linear hashing.Also search the record, delete it and display all records.
****************************************************************************************************/
import java.util.Scanner;
public class Customer 
{
    long id;
	String name;
	double balance;
    
    //parameterized constructor
	public Customer(long id, String name, double balance) 
	{
		this.id = id;
		this.name = name;
		this.balance = balance;
	}
	
	//default constructor
	public Customer()
	{
	    id=-1;
	    name=null;
	    balance=0.0;
	}
}
public class Bank 
{
	Customer bankAccount[];
    int size;
	int maxsize;
    
    // parameterized constructor
    Bank(int maxsize)
	{
	    this.maxsize=maxsize;
	    this.size=0;
	    bankAccount= new Customer[maxsize];
	}
	
	//function to calculate hash address
	
	int hash(long id)
	{
	   return (int)(id % maxsize);
	}
	
	//function to create a hashtable
	void create()
	{
		Scanner sc=new Scanner(System.in);
	   //accepting the details to insert the account in the bank
		if(size==maxsize)	
		{
			System.out.println("Bank Accounts are full!Cannot insert account");
			return;
		}
			System.out.println("Enter the Customer Account Number:");
			long accID=sc.nextLong();	
			System.out.println("Enter the Customer name:");
			String accNm=sc.next();		
			System.out.println("Enter the Customer Account Balance :");
			double accBal=sc.nextDouble();	
		
		 //checking if account is already present
		
		 if(search(accID)!=null)
		 {
		     System.out.println("Account with this id already exists");
		 }
		 else
		 {
			 Customer nCustomer = new Customer(accID,accNm,accBal);

			 int hashindex=hash(accID);
			//finding empty slot in hash table  
			// To store original index
				int temp = hashindex;

				do 
				{
					// If required hashkey is null
					if (bankAccount[hashindex] == null) 
					{
						bankAccount[hashindex] = nCustomer;
						size++;
						return;
					}

					// Incrementing index
					hashindex++;
					hashindex%=maxsize;

				} while (hashindex != temp);	
				
			
		   
		    
		 }//close else
		
				
	}//close create function
	
	//display function opens
	void display()
	{
	   if(size==0)
	   {
	       System.out.println("\nHash Table for Bank account is empty");
	   }
	   else
	   {
	     for(int i=0;i<maxsize;i++)
	     {
	       if(bankAccount[i]!=null && bankAccount[i].id!=-1)
	       {
	           System.out.println("Name:"+bankAccount[i].name);
	           System.out.println("Account Id:"+bankAccount[i].id);
	           System.out.println("Balance:"+bankAccount[i].balance);
	       }
	       else
	       {
	           System.out.println("Account is not allocated");
	       }
	     }
	   }
	}	//close display function 
	
	//search function opens
	String search(long ID)
	{
		if(size==0)
		return null;
	   int hashindex=hash(ID);
	   int count=0;
	   
	   while(bankAccount[hashindex]!=null)	//looping through the hash map from the hashIndex till any empty block is found 
		{
			if(count++>maxsize)	            //checking if we have already traversed the entire hash table
				return null;	            //if we have already traversed the table and element is not found then return null
			if(bankAccount[hashindex].id==ID)       
				return bankAccount[hashindex].name;	//Returning the name 
			
			//if none of the above conditions satisfy then upgrade the index
			hashindex++;	
			hashindex %=maxsize;
		}
		return null;//returning null if element is not found	
		
	}//close search function 
	
	//delete function 
	String delete(long AccId)
	{
		String delstr=null;
	    int hashidx=hash(AccId);
	    //getting hash value of account id 
	   
	    while(bankAccount[hashidx]!=null && bankAccount[hashidx].id!=-1)
	    {
	        if(bankAccount[hashidx].id==AccId)
	        {
	        	delstr=bankAccount[hashidx].name;	
	            System.out.println("Account for ID "+AccId+" deleted");
	            bankAccount[hashidx].id=-1;
	            bankAccount[hashidx].name=null;
	            bankAccount[hashidx].balance=0.0;
	            size--;
	            
	        }
	        hashidx++;
	        hashidx=hashidx%maxsize;
	    }
	    return delstr;
	}//close delete function
}
public class HashTable {

	public static void main(String[] args) {
		
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the maximum number of bank accounts that the bank can have :");
		int maxS=sc.nextInt();
		long acNum;
        String fndstr,found,deletedstr;
		Bank bA = new Bank(maxS);
		
		int choice;
		do
		{
		System.out.println("***************************MENU****************************************");    
		System.out.print("\n1.Insert a new bank account \n2.Display all the bank accounts");
		System.out.println("\n3.Search a bank account\n4.Delete a bank account\n0.EXIT");
		System.out.println("************************************************************************"); 
		System.out.println("\nEnter the option:");
		choice=sc.nextInt();
		switch(choice)
		{
		case 0:System.out.println("\nExited!");
		       break;
		case 1:bA.create();
				break;
		case 2:bA.display();
				break;
		case 3:if(bA.size==0)	
			   System.out.println("Hash Table for Bank account is empty");
			   else	
			   {
				System.out.println("Enter the Account Id of the Customer to be searched :");
				acNum=sc.nextLong();	
				//checking if account is found after calling search function
				fndstr=bA.search(acNum);	
				if(fndstr==null)		
				System.out.println("Account not found in bank");
				else
				System.out.println("Account name:"+fndstr+" found");
				}
				break;
		case 4:if(bA.size==0)	//checking if the hash table is empty
			   {
				System.out.println("Hash Table for Bank account is empty");
			   }
			   else
			   {
			    System.out.println("Enter the Account Id of the Customer to be deleted :");
			    long idtodel=sc.nextLong(); 
			    found=bA.search(idtodel);	
			    if(found==null)	
				System.out.println("Account not found in Bank,could not delete");
			    else
			    {
				  deletedstr=bA.delete(idtodel);
				  System.out.println("Account name:"+deletedstr+" deleted");
			    }
			    }
		       break;
		default:System.out.println("\nInvalid choice!");
		        break;
		}
		}while(choice!=0);	

	}

}
/*TIME COMPLEXITY
 * String search(long ID)     = O(n)
 * int hash(long id)          = O(1)
 * void create()              = O(n)
 * void delete(long AccId)    = O(n)
 * void display()             = O(n)
 */
/*OUTPUT
Enter the maximum number of bank accounts that the bank can have :
5
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
2

Hash Table for Bank account is empty
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
3
Hash Table for Bank account is empty
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
4
Hash Table for Bank account is empty
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
5

Invalid choice!
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
1
Enter the Customer Account Number:
8905632456
Enter the Customer name:
Yash
Enter the Customer Account Balance :
9000
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
2
Account is not allocated
Name:Yash
Account Id:8905632456
Balance:9000.0
Account is not allocated
Account is not allocated
Account is not allocated
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
1
Enter the Customer Account Number:
8906789090
Enter the Customer name:
Parth
Enter the Customer Account Balance :
5600
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
2
Name:Parth
Account Id:8906789090
Balance:5600.0
Name:Yash
Account Id:8905632456
Balance:9000.0
Account is not allocated
Account is not allocated
Account is not allocated
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
1
Enter the Customer Account Number:
9056478999
Enter the Customer name:
Urvi
Enter the Customer Account Balance :
89000
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
2
Name:Parth
Account Id:8906789090
Balance:5600.0
Name:Yash
Account Id:8905632456
Balance:9000.0
Account is not allocated
Account is not allocated
Name:Urvi
Account Id:9056478999
Balance:89000.0
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
1
Enter the Customer Account Number:
8976231111
Enter the Customer name:
Sanika
Enter the Customer Account Balance :
7800
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
2
Name:Parth
Account Id:8906789090
Balance:5600.0
Name:Yash
Account Id:8905632456
Balance:9000.0
Name:Sanika
Account Id:8976231111
Balance:7800.0
Account is not allocated
Name:Urvi
Account Id:9056478999
Balance:89000.0
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
1
Enter the Customer Account Number:
8900078953
Enter the Customer name:
Vaishali
Enter the Customer Account Balance :
39900
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
2
Name:Parth
Account Id:8906789090
Balance:5600.0
Name:Yash
Account Id:8905632456
Balance:9000.0
Name:Sanika
Account Id:8976231111
Balance:7800.0
Name:Vaishali
Account Id:8900078953
Balance:39900.0
Name:Urvi
Account Id:9056478999
Balance:89000.0
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
3
Enter the Account Id of the Customer to be searched :
9056478999
Account name:Urvi found
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
3
Enter the Account Id of the Customer to be searched :
1234567890
Account not found in bank
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
4
Enter the Account Id of the Customer to be deleted :
1234567656
Account not found in Bank,could not delete
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
4
Enter the Account Id of the Customer to be deleted :
8906789090
Account for ID 8906789090 deleted
Account name:Parth deleted
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
2
Account is not allocated
Name:Yash
Account Id:8905632456
Balance:9000.0
Name:Sanika
Account Id:8976231111
Balance:7800.0
Name:Vaishali
Account Id:8900078953
Balance:39900.0
Name:Urvi
Account Id:9056478999
Balance:89000.0
***************************MENU****************************************

1.Insert a new bank account 
2.Display all the bank accounts
3.Search a bank account
4.Delete a bank account
0.EXIT
************************************************************************

Enter the option:
0

Exited!
*/


