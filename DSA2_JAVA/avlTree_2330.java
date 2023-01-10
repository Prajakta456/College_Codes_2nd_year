/******************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:3
To implement AVL tree and perform operations on it
Create a reasonably balanced tree to maintain names and telephone numbers of all the
customers of a shopkeeper and perform operations on it. Test your program for at least 10
names.
*******************************************************************************/
import java.util.*;
class Node
{
    String name;
    String telephone;
    Node left;
    Node right;
    int height;
    
    //parameterized constructor 
     Node(String name,String telephone)
     {  
            this.name = name;
            this.telephone=telephone;
            left = right = null;  
            height=1;
     }
     //default constructor
     Node()
     {
        name=null;
        telephone=null;
        left=right=null;
        height=1;
     }
    
}
//class Node ends here
class AVL
{
    Node root;
    AVL()
    {
        root=null;
    }
    AVL(Node rt)
    {
        root=rt;
    }
    
    /*for inserting node in AVL tree
     1.Perform the normal BST insertion 
     2.Update height of this ancestor node 
     3.Get the balance factor of this ancestor
       node to check whether this node became unbalanced
     4.If this node becomes unbalanced, then there
        are 4 cases: 
        (a) Left Left Case  
        (b)Right Right Case
        (c)Left Right Case
        (d)Right Left Case
    */
       
    Node insert(Node root,String nC,String tC)
    {
        // Perform the normal BST insertion 
        if(root==null)
        {
            root=new Node(nC,tC);
        }
        else
        {
            int comStr=root.name.compareTo(nC);
            if(comStr<0)
            {
                root.right=insert(root.right,nC,tC);
                //checking balance factor
                if(balanceFactor(root)==-2)
                {
                    if(root.right.name.compareTo(nC)<0)
                    {
                       root=RR(root); 
                    }
                    else
                    {
                        root=RL(root);
                    }
                    
                }
                
            }
            else if(comStr>0)
            {
                root.left=insert(root.left,nC,tC);
                //checking balance factor
                if(balanceFactor(root)==2)
                {
                    if(root.left.name.compareTo(nC)>0)
                    {
                        root=LL(root);
                    }
                    else
                    {
                        root=LR(root);
                    }
                }
            }
            else
            {
                System.out.println("\nA customer with the same name is there in the list!\nDuplicates are not allowed!");
            }
        }
        root.height=height(root);
        return root;
    }
    
    //create function is used to accept the customer details
    void create()
    {
        Scanner sc=new Scanner(System.in);
        String n,t;
        System.out.println("\nEnter name of the customer:");
        n=sc.nextLine();
        
    //do while loop is used for checking if the phone number entered by the customer is a 10 digit number
        do
        {
          System.out.println("\nEnter telephone number of the customer:");
          t=sc.nextLine();
          int count=0;
           for(int j=0;j<t.length();j++)
           {
             if(Character.isDigit(t.charAt(j)))
             {
              count++;
             }
           }
         if(count==10)
           break;
          else
          {
            System.out.println("Wrong telephone number try again");
            System.out.println("Telephone number should be 10 digits");
             continue;
          }
       }while(true);
        
         root=insert(root,n,t);
    }
    
    //calculate balance factor of tree=ht of left subtree - ht of right subtree
    int balanceFactor(Node r)	
	{
		if(r==null)
			return -1;
		else
			return (height(r.left)-height(r.right)); 
	}
 
    //finding height 
    int height(Node n)
    {
        int lh,rh;
        if(n==null)
        return 0;
        
        else
        {
            //calculate height of each subtree
            lh=height(n.left);
            rh=height(n.right);
            
            //use the larger one
            if(lh>rh)
            return(lh+1);
            else
            return(rh+1);
        }
        
    }
    //function to rotate right
    Node rotateright(Node r)
    {
       Node temp=new Node();
       temp=r.left;
       r.left=temp.right;
       temp.right=r;
    
       r.height=height(r);
       temp.height=height(temp);
       return temp;
    }
    //function to rotate left
    Node rotateleft(Node r)
    {
       
       Node temp=new Node();
       temp=r.right;
       r.right=temp.left;
       temp.left=r;
        
        r.height=height(r);    
        temp.height=height(temp);
        return temp;
        
    }
    /*functions for the 4 cases LL,RR,LR and RL*/
    Node LL(Node r)
    {
        r=rotateright(r);
        return r;
    
    }
    
    Node RR(Node r)
    {
        r=rotateleft(r);
        // Return new root
        return r;
    }
    
    Node LR(Node r)
    {
        r.left=rotateleft(r.left);
        r=rotateright(r);
        return r;
        
    }
    
    Node RL(Node r)
    {
        r.right=rotateright(r.right);
        r=rotateleft(r);
        return r;
    }
    
    // Recursive Inorder traversal
    void Inorderdisplay(Node t) 
    {
       if(t==null)
        return;
        else
        {
            
            Inorderdisplay(t.left);
            System.out.println(t.name+" \t "+t.telephone);
            Inorderdisplay(t.right);
            
        }
       
    }
 
}
//class AVL ends here
public class Main
{
	public static void main(String[] args) 
	{
	   AVL avl=new AVL();
	   int ht;
       Scanner sc=new Scanner(System.in);
       int ch;
       char cont;
        do
        {
          System.out.println("******************************************************************************");
          System.out.println("---------------------------------MENU-----------------------------------------");
          System.out.println("\n1.Accept the names and telephone numbers of all customers in the shop");
          System.out.println("\n2.Display the AVL Tree using inorder traversal");
          System.out.println("\n3.Find the height of the AVL tree");
          System.out.println("\n0.Exit");
          System.out.println("--------------------------------------------------------------------------");
          System.out.println("\nEnter your choice:");
          ch=sc.nextInt();
          switch(ch)
          {
            case 1:do
                   {
                   avl.create();
                   System.out.println("\nDo you want to add more customer details?(y/n)");
                   cont=sc.next().charAt(0);
                   }while(cont=='y'||cont=='Y');
                   break;

            case 2:if(avl.root==null)
                   System.out.println("\nAVL tree is empty cannot display inorder traversal");
                   else
                   {
                    System.out.println("\nThe inorder traversal of the AVL tree is as follows\n");
                    System.out.println("\nName "+"\tContact Number\n");
                    avl.Inorderdisplay(avl.root);
                   }
                   break;
                   
            case 3:ht=avl.height(avl.root);
                   System.out.println("\nThe height of the AVL tree is "+ht);
                   break;
                   
            case 0:System.out.println("\nExit");
                   break;       
                   
            default:System.out.println("\nInvalid choice!");
                    break;
           }
         }while(ch!=0);
         }
}

/*
OUTPUT
******************************************************************************
---------------------------------MENU-----------------------------------------

1.Accept the names and telephone numbers of all customers in the shop

2.Display the AVL Tree using inorder traversal

3.Find the height of the AVL tree

0.Exit
--------------------------------------------------------------------------

Enter your choice:
2

AVL tree is empty cannot display inorder traversal
******************************************************************************
---------------------------------MENU-----------------------------------------

1.Accept the names and telephone numbers of all customers in the shop

2.Display the AVL Tree using inorder traversal

3.Find the height of the AVL tree

0.Exit
--------------------------------------------------------------------------

Enter your choice:
3

The height of the AVL tree is 0
******************************************************************************
---------------------------------MENU-----------------------------------------

1.Accept the names and telephone numbers of all customers in the shop

2.Display the AVL Tree using inorder traversal

3.Find the height of the AVL tree

0.Exit
--------------------------------------------------------------------------

Enter your choice:
8

Invalid choice!
******************************************************************************
---------------------------------MENU-----------------------------------------

1.Accept the names and telephone numbers of all customers in the shop

2.Display the AVL Tree using inorder traversal

3.Find the height of the AVL tree

0.Exit
--------------------------------------------------------------------------

Enter your choice:
1

Enter name of the customer:
Pravin Aralkar

Enter telephone number of the customer:
8989890909

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Pravin

Enter telephone number of the customer:
8745645345

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Parth

Enter telephone number of the customer:
7867898787

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Tanaya

Enter telephone number of the customer:
786
Wrong telephone number try again
Telephone number should be 10 digits

Enter telephone number of the customer:
7890989hgf
Wrong telephone number try again
Telephone number should be 10 digits

Enter telephone number of the customer:
7890890789

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Ahana

Enter telephone number of the customer:
7890789078

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Sneha

Enter telephone number of the customer:
678909890
Wrong telephone number try again
Telephone number should be 10 digits

Enter telephone number of the customer:
8978989098

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Sanika

Enter telephone number of the customer:
7890890989

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Purva

Enter telephone number of the customer:
6789098909

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Purva

Enter telephone number of the customer:
8978906789

A customer with the same name is there in the list!
Duplicates are not allowed!

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Harshawardhan

Enter telephone number of the customer:
7890897898

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Sagar

Enter telephone number of the customer:
7890897856

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Tanmay

Enter telephone number of the customer:
7856765678

Do you want to add more customer details?(y/n)
y

Enter name of the customer:
Pooja

Enter telephone number of the customer:
7896712121

Do you want to add more customer details?(y/n)
n
******************************************************************************
---------------------------------MENU-----------------------------------------

1.Accept the names and telephone numbers of all customers in the shop

2.Display the AVL Tree using inorder traversal

3.Find the height of the AVL tree

0.Exit
--------------------------------------------------------------------------

Enter your choice:
3

The height of the AVL tree is 4
******************************************************************************
---------------------------------MENU-----------------------------------------

1.Accept the names and telephone numbers of all customers in the shop

2.Display the AVL Tree using inorder traversal

3.Find the height of the AVL tree

0.Exit
--------------------------------------------------------------------------

Enter your choice:
2

The inorder traversal of the AVL tree is as follows


Name 	Contact Number

Ahana 	 7890789078
Harshawardhan 	 7890897898
Parth 	 7867898787
Pooja 	 7896712121
Pravin 	 8745645345
Pravin Aralkar 	 8989890909
Purva 	 6789098909
Sagar 	 7890897856
Sanika 	 7890890989
Sneha 	 8978989098
Tanaya 	 7890890789
Tanmay 	 7856765678
******************************************************************************
---------------------------------MENU-----------------------------------------

1.Accept the names and telephone numbers of all customers in the shop

2.Display the AVL Tree using inorder traversal

3.Find the height of the AVL tree

0.Exit
--------------------------------------------------------------------------

Enter your choice:
0

Exit

*/
/***TIME COMPLEXITY***

create()                   = O(1)
insert()                   = O(log n)
LL(),RR(),RL(),LR()        = O(1)
rotateright(),rotateleft() = O(1)
balanceFactor()            = O(log n)(Worst case tiime complexity=O(n))
height()                   = O(log n)
Inorderdisplay()           = O(n)
*/
