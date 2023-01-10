/******************************************************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:5

Problem Statement:
Perform following operation on Min heap or Max Heap
1. Insert an element
2. Delete an element from heap
3. Build Heap
4. Delete Heap
Extra- Heap sort
*****************************************************************************************************************/
import java.util.Scanner;
class MinHeap
{
	int maxSize;       //maximum possible size of min heap
	int heap[];        //array of elements of heap
	int csize;	       //current number of elements in min heap

    //Parameterized constructor
	MinHeap(int maxSize)
	{
		this.maxSize=maxSize;
		csize=0;
		heap=new int[maxSize];

	}
	Scanner sc = new Scanner(System.in);

	// method to create MinHeap using upadjustment
	void create()
	{
	    System.out.println("Creating Heap:");
		int i,n;
		System.out.print("\nEnter number of elements(less than 15):");
		csize=sc.nextInt();
		heap[0]=csize;
		int inp;
		for (i = 1; i <= csize; i++)
		{
			System.out.print("Enter element:");
			inp=sc.nextInt();
			heap[i]=inp;
			upAdjustment(i);
		}
	}

	// method to display heap
	void display()
	{
	    if(csize==0)	//if no elements are inserted in the heap
		{
			System.out.println("Min Heap is empty");
			return;
		}

		System.out.println("Heap size : " +csize);
		for (int i=1;i<=csize;i++)
			System.out.print(heap[i]+"\t");
		System.out.println("");
	}

	void upAdjustment(int i)
	{
		int parent;
		for (int j=i; j>1; j/= 2)
		{
			parent = j / 2;
			if (heap[j] < heap[parent])
			{
				int temp = heap[j];
				heap[j] = heap[parent];
				heap[parent] = temp;
			}
		}
	}

	//Recursively heapify using downadjustment
	void heapify(int i)
	{
		int left = 2 * i;       // index of left child
		int right = 2 * i + 1;  // index of right child
		int smallest = i;

		if(left<=csize && heap[left]<heap[i])
			smallest=left;

		if(right<=csize && heap[right]<heap[smallest])
			smallest = right;

		if(smallest!=i)
		{
			int temp=heap[i];// swapping
			heap[i]=heap[smallest];
			heap[smallest]=temp;
			heapify(smallest); // recursively heapify(downadjustment)
		}
	}

	// method to delete minimum element
	int deleteH()
	{
		if (csize<=0) // checking if heap is empty
		{
			System.out.println("Heap is empty,cannot delete");
			return -1;
		}

		int deleter=heap[1];

		int temp=heap[1];// swapping
		heap[1]=heap[csize];
		heap[csize]=temp;

		csize--;          // decrement heap size
		heap[0]=csize;    // store updated count
		heapify(1);
		return deleter;
	}

	//method to insert in a MinHeap using upadjustment
	void insert()
	{
		if ((csize+1)==maxSize)// largest capacity
		{
			System.out.println("Can't insert as heap is full.");
			return;
		}
		csize++;
		heap[0]=csize;

		System.out.print("Enter element to insert : ");

		int inse=sc.nextInt();
		heap[csize]=inse;
		upAdjustment(csize);
	}


	//method to find heap sort(heap sorted in descending order)
	void heapSort()
	{
		int cnt=heap[0];
		for (int i=heap[0]; i>0; i--)
			deleteH();

		heap[0]=cnt;
		csize=cnt;
	}
}

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc=new Scanner(System.in);
		MinHeap h=new MinHeap(15);

        //here maxsize is taken as 15
		int choice,mine;
		h.create();

		System.out.println("\nMin Heap created");
		h.display();

		do
		{
			System.out.println("\n****************************MENU********************************");
			System.out.println("\n1.Insert\n2.Delete minimum\n3.Display\n4.HeapSort\n0 EXIT");
			System.out.println("****************************************************************");
			System.out.print("Enter your choice : ");
			choice=sc.nextInt();
			switch (choice)
			{
				case 0:System.out.println("Exited");
					   break;

				case 1:h.insert();
					   break;

				case 2:mine=h.deleteH();
					   if(mine!=-1)
						System.out.println("\nMin element "+mine+" deleted");
					    break;

				case 3:h.display();
					   break;

				case 4:System.out.println("\nDescending Order:");
					   h.heapSort();
					   h.display();
					   break;
				default:System.out.print("\nInvalid choice!!");
					break;
			}
		} while (choice!= 0);
	}
}



/*TIME COMPLEXITY
create()         = O(n)
upAdjustment()   = O(log n)
heapify()        = O(log n)
(down adjustment)
display()        = O(n)
heapSort()       = O(nlog n)
deleteH()        = O(log n)
*/
/*OUTPUT

Creating Heap:



Enter number of elements(less than 15):8

Enter element:13

Enter element:45

Enter element:56

Enter element:34

Enter element:23

Enter element:56

Enter element:37

Enter element:87



Min Heap created

Heap size : 8

13	23	37	45	34	56	56	87



****************************MENU********************************



1.Insert

2.Delete minimum

3.Display

4.HeapSort

0 EXIT

****************************************************************

Enter your choice : 1

Enter element to insert : 35



****************************MENU********************************



1.Insert

2.Delete minimum

3.Display

4.HeapSort

0 EXIT

****************************************************************

Enter your choice : 3

Heap size : 9

13	23	37	35	34	56	56	87	45



****************************MENU********************************



1.Insert

2.Delete minimum

3.Display

4.HeapSort

0 EXIT

****************************************************************

Enter your choice : 5



Invalid choice!!

****************************MENU********************************



1.Insert

2.Delete minimum

3.Display

4.HeapSort

0 EXIT

****************************************************************

Enter your choice : 2



Min element 13 deleted



****************************MENU********************************



1.Insert

2.Delete minimum

3.Display

4.HeapSort

0 EXIT

****************************************************************

Enter your choice : 3

Heap size : 8

23	34	37	35	45	56	56	87



****************************MENU********************************



1.Insert

2.Delete minimum

3.Display

4.HeapSort

0 EXIT

****************************************************************

Enter your choice : 4



Descending Order:

Heap size : 8

87	56	56	45	37	35	34	23



****************************MENU********************************



1.Insert

2.Delete minimum

3.Display

4.HeapSort

0 EXIT

****************************************************************

Enter your choice : 0

Exited
*/




