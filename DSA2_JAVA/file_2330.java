/******************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:7

Use sequential file to maintain student information. Write
algorithm to add, delete and search student information
from the file.

*******************************************************************************/
package FileHandling;
import java.io.Serializable;
public class Student implements Serializable
{
	int roll_no;
	double mark;
	String name;
	
	//parameterized constructor
	
	Student(int roll_no,String name,double mark)
	{
		//initialize variables
          this.roll_no=roll_no;
          this.name=name;
          this.mark=mark; 
	}
	
	public String toString()
	{
		String s= "Student{ "+" id= "+roll_no+" name= "+name+" marks= "+mark+" }"; 
		return s;
	}
}
package FileHandling;
import java.io.Serializable;
import java.io.*;
import java.util.*;
import java.util.Scanner;
public class file1 
{
	Vector<Student> st=new Vector<Student>();
	Scanner sc=new Scanner(System.in);
	Student obj;

	void writeinFile()
	{
		int id = 0, choice = 1;
		double mk = 0;
		String nm = "";
		System.out.println("\n<<< Enter data for file info.txt >>>" );
		do 
		{
			System.out.println("\nStudent entry :");
			System.out.print("Enter roll no. :");
			id = sc.nextInt();
			System.out.print("Enter name :");
			nm = sc.next();
			System.out.print("Enter marks :");
			mk = sc.nextInt();
			obj = new Student(id,nm,mk);
			st.add(obj);
			System.out.println("[ Student entry complete. ]\n");
			System.out.print("Do you want to continue entering (1 = Yes, 0 = No)?: ");
			choice = sc.nextInt();
		}while (choice == 1);
		
		try{
			FileOutputStream f = new FileOutputStream("info.txt");
			ObjectOutputStream obs = new ObjectOutputStream(f);
			obs.writeObject(st);
			obs.close();
			f.close();
			System.out.println("Entries written " + " : " + st.size());
		}
		catch (Exception e){
			System.out.println(e);
		}
	  

	}
	void readFile()
	{
		System.out.println("\nReading file ");
		try 
		{
			FileInputStream f = new FileInputStream("info.txt");
			ObjectInputStream obs = new ObjectInputStream(f);
			st = (Vector<Student>)obs.readObject();
			obs.close();
			f.close();
		}
		catch (Exception e)
		{
			System.out.println(e.getMessage());
			return;
		}
		Iterator<Student> itr = st.iterator();
		while (itr.hasNext())
		{
			Student s = itr.next();
			System.out.println(s);
		}
	}
	
	void Search()
	{
		System.out.println("\nEnter roll number to be searched:");
		int r=sc.nextInt();
		try 
		{
			FileInputStream f = new FileInputStream("info.txt");
			ObjectInputStream obs = new ObjectInputStream(f);
			st = (Vector<Student>) obs.readObject();
			obs.close();
			f.close();
		}
		catch (Exception e)
		{
			System.out.println(e.getMessage());
			return;
		}
		Iterator<Student> itr = st.iterator();
		while (itr.hasNext())
		{
			Student s = itr.next();
			if (s.roll_no == r)
			{
				System.out.println("Entry found:  ");
				System.out.println(s);
				return;
			}
		}
		System.out.println("Entry not found.");
		
	}

	void delete()
	{
		int roll;
		System.out.println("Enter roll no. to be deleted: ");
		roll=sc.nextInt();

      	try 
      	{
				FileInputStream f = new FileInputStream("info.txt");
				ObjectInputStream obs = new ObjectInputStream(f);
				st = (Vector<Student>) obs.readObject();
				obs.close();
				f.close();
			}
			catch (Exception e)
      	    {
				System.out.println(e);
				return;
			}
			int i = 0;
			for (; i < st.size(); i++) 
			{
				if (st.get(i).roll_no == roll)
					break;
			}
			if (i == st.size())
			{
				System.out.println("not found.");
				return;
			}
			else
			{
				st.remove(i);
				try 
				{
					FileOutputStream f = new FileOutputStream("info.txt");
					ObjectOutputStream obs = new ObjectOutputStream(f);
					obs.writeObject(st);
					obs.close();
					f.close();
					System.out.println("deleted");
								
				}
				catch (Exception e)
				{
					System.out.println(e);
					return;
				}
				
			}
		}
						

	}
package FileHandling;
import java.util.Scanner;
public class Main 
{
  public static void main(String[] args)
  {
	int ch;
	Scanner sc=new Scanner (System.in);
	file1 f=new file1();
	
	do 
	{
		System.out.println("\nMenu\n1.Write File\n2.Read file\n3.Search record\n4.Delete record\nEnter your choice");
		ch=sc.nextInt();

		switch(ch) 
		{
		case 1:f.writeinFile();
	           break;
		
		case 2:f.readFile();
		       break;
		
		case 3:f.Search();
		       break;
		
		case 4:f.delete();
		       f.readFile();
		       break;
		
		default:System.out.println("Invalid choice");
		break;
		}
	}while(ch!=0);
}

}
	


/*
Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
1

<<< Enter data for file info.txt >>>

Student entry :
Enter roll no. :30
Enter name :Prajakta
Enter marks :98
[ Student entry complete. ]

Do you want to continue entering (1 = Yes, 0 = No)?: 1

Student entry :
Enter roll no. :77
Enter name :Sneha
Enter marks :90
[ Student entry complete. ]

Do you want to continue entering (1 = Yes, 0 = No)?: 1

Student entry :
Enter roll no. :10
Enter name :Pallavi
Enter marks :85
[ Student entry complete. ]

Do you want to continue entering (1 = Yes, 0 = No)?: 0
Entries written  : 3

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
2

Reading file 
Student{  id= 30 name= Prajakta marks= 98.0 }
Student{  id= 77 name= Sneha marks= 90.0 }
Student{  id= 10 name= Pallavi marks= 85.0 }

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
3

Enter roll number to be searched:
30
Entry found:  
Student{  id= 30 name= Prajakta marks= 98.0 }

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
4
Enter roll no. to be deleted: 
10
deleted

Reading file 
Student{  id= 30 name= Prajakta marks= 98.0 }
Student{  id= 77 name= Sneha marks= 90.0 }

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
4
Enter roll no. to be deleted: 
79
not found.

Reading file 
Student{  id= 30 name= Prajakta marks= 98.0 }
Student{  id= 77 name= Sneha marks= 90.0 }

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
3

Enter roll number to be searched:
47
Entry not found.

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
1

<<< Enter data for file info.txt >>>

Student entry :
Enter roll no. :13
Enter name :Mahi
Enter marks :34
[ Student entry complete. ]

Do you want to continue entering (1 = Yes, 0 = No)?: 0
Entries written  : 3

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
4
Enter roll no. to be deleted: 
34
not found.

Reading file 
Student{  id= 30 name= Prajakta marks= 98.0 }
Student{  id= 77 name= Sneha marks= 90.0 }
Student{  id= 13 name= Mahi marks= 34.0 }

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
4
Enter roll no. to be deleted: 
13
deleted

Reading file 
Student{  id= 30 name= Prajakta marks= 98.0 }
Student{  id= 77 name= Sneha marks= 90.0 }

Menu
1.Write File
2.Read file
3.Search record
4.Delete record
Enter your choice
0
Invalid choice
*/
