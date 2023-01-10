/****************************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:1
Title:Implement Binary Tree and perform recursive and non-recursive traversals on item

Create a binary tree and perform inorder,preorder and postorder traversals.
******************************************************************************************/

import java.util.*;
class Node
{
	int data;
	Node left, right;

	Node(int item)
	{
		data=item;
		left=right=null;
	}
	Node()
	{
	    data=0;
	    left=right=null;
	}
}
class BinaryTree
{
    Scanner sc=new Scanner(System.in);
	// Root of Binary Tree
	Node root;

	BinaryTree()
	{
	    root = null;
	}
    void create()
    {
        int num,dir;
        Node ptr=root;

             System.out.println("Enter data to add new node to the binary tree:");
             num=sc.nextInt();
             Node nnode=new Node(num);
             if(root==null)
             {
                root=nnode;
                System.out.print("\nRoot inserted successfully");
             }
             else
             {
                Node temp=root;
                while(temp!=null)
                 {

                     System.out.println("The current Node is :"+temp.data);
                     //node currently pointed Displayed
                    while(true)
                    {
                    System.out.println("Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)");
                    dir=sc.nextInt();
                     if(dir==1||dir==2)
                      break;
                    else
                    {
                     System.out.println("Wrong choice,try again!");
                     continue;
                    }
                   }

                    if(dir==1)
                    {
                      if(temp.left==null)
                      {
                          temp.left=nnode;
                          break;
                      }
                      else
                      temp=temp.left;
                    }

                    else if(dir==2)
                    {
                      if(temp.right==null)
                      {
                        temp.right=nnode;
                        break;
                      }
                      else
                      temp=temp.right;

                    }
                }//close while
             }//close outer else

    }//close create()

	//Recursive postorder traversal (Left Right Node)
	void RPostorder(Node t)
	{
		if(t==null)
			return;

        RPostorder(t.left);             // first recur on left subtree
		RPostorder(t.right);            // then recur on right subtree
        System.out.print(t.data+"  ");
	}

	//Recursive Inorder traversal (Left Node Right)
	void RInorder(Node t1)
	{
		if(t1==null)
		   return;

		RInorder(t1.left);   // first recur on left subtree
        System.out.print(t1.data+"  ");
		RInorder(t1.right);  //then recur on right subtree

	}

	//Recursive Preorder traversal (Node Left Right)
	void RPreorder(Node t2)
	{
		if(t2==null)
		  return;

		System.out.print(t2.data+"  ");
        RPreorder(t2.left);             //recur on left sutree
        RPreorder(t2.right);            //now recur on right subtree

	}
	//Non recursive inorder traversal using stack
	void Ninorder()
	{
	    if(root==null)
	    return;
	    else
	    {
	        Stack<Node> s = new Stack<Node>();
	        Node cur=root;

	        //traverse the Tree
	        while(cur!=null || s.size()>0)
	        {
	            //reach the left most node of the cur node
	            while(cur!=null)
	            {
	                s.push(cur);
	                cur=cur.left;
	            }
	            //cur is null at this pt
	            cur=s.pop();
	            System.out.print(cur.data+"  ");
	            //now the left subtree and node are visited and we have to visit the right subtree
	            cur=cur.right;
	        }
	    }

	}//close Non recursive inorder traversal using stack

	//function to print non recursive Preorder traversal of tree using stack
	void Npreorder(Node tem)
	{
	    if(tem==null)
	    return;
	    else
        {
	       //create an empty stack and push root to it

	      Stack<Node> nstack=new Stack<Node>();
	      nstack.push(root);

	      //Pop all the elements one by one
	      //for each popped element do this
	      //print it
	      //push its right child
	      //push its left child
	      //right child is pushed first so that the left child is processed first
	      while(!nstack.isEmpty())
	      {
	         Node tn=nstack.peek();
	         System.out.print(tn.data+" ");
	         nstack.pop();
	         //push the left and the right childs of the popped item
	         if(tn.right!=null)
	         {
	          nstack.push(tn.right);
	         }
	         if(tn.left!=null)
	         {
	           nstack.push(tn.left);
	         }
	      }//close while
        }//close else
    }//close function to print non recursive Preorder traversal of tree using stack

	//Non recursive postorder traversal of binary tree using 2 stacks
    void Npostorder(Node root)
    {
        Stack<Node> s1=new Stack<Node>();
        Stack<Node> s2=new Stack<Node>();

        if(root==null)
        return;

        //push root to 1st stack
        s1.push(root);

        //run while 1st stack is not empty
        while(!s1.isEmpty())
        {
            //pop an element from s1 and push it in s2
            Node temp=s1.pop();
            s2.push(temp);
            //push left and right child of node removed to s1
            if(temp.left!=null)
            s1.push(temp.left);
            if(temp.right!=null)
            s1.push(temp.right);
        }
         //print all the elements off the 2nd stack
            while(!s2.isEmpty())
            {
                Node t=s2.pop();
                System.out.print(t.data+" ");
            }

        }//close Non recursive postorder traversal of binary tree using 2 stacks

}
public class Main
{
   public static void main(String[] args)
	{
	     int choice,no=0;
	     char ch;
	     Scanner sc=new Scanner(System.in);
	     BinaryTree bt=new BinaryTree();
	    do
	    {
	      System.out.println("*****MENU*****");
	      System.out.print("\n1.Create a Binary Tree ");
	      System.out.print("\n2.Display the recursive Preorder traversal");
	      System.out.print("\n3.Display the recursive Inorder traversal");
	      System.out.print("\n4.Display the recursive Postorder traversal");
          System.out.print("\n5.Display the non recursive Preorder traversal");
	      System.out.print("\n6.Display the non recursive Inorder traversal");
	      System.out.print("\n7.Display the non recursive Postorder traversal");
	      System.out.print("\n0.Exit");

           System.out.println("\nEnter your choice: ");
           choice=sc.nextInt();
           switch(choice)
           {
             case 1: do
                     {
                       bt.create();
                       System.out.println("\nDo you wish to add more nodes?(y/n)");
                       ch=sc.next().charAt(0);
                      }while(ch=='y'||ch=='Y');
                     break;
             case 2: if(bt.root==null)
                     System.out.println("\nBinary tree is empty cannot perform traversal");
                     else
                     {
                        System.out.print("\n(Recursive)Preorder traversal of Binary tree is ");
                        bt.RPreorder(bt.root);
                     }
                     break;
             case 3:if(bt.root==null)
                     System.out.println("\nBinary tree is empty cannot perform traversal");
                     else
                     {
                        System.out.print("\n(Recursive)Inorder traversal of Binary tree is ");
                        bt.RInorder(bt.root);
                     }
                     break;
             case 4:if(bt.root==null)
                     System.out.println("\nBinary tree is empty cannot perform traversal");
                     else
                      {
                       System.out.print("\n(Recursive) Postorder traversal of Binary tree is:");
                       bt.RPostorder(bt.root);
                      }
                     break;

              case 5: if(bt.root==null)
                      System.out.println("\nBinary tree is empty cannot perform traversal");
                      else
                      {
	                  System.out.println("\nThe non recursive Preorder traversal:");
	                  bt.Npreorder(bt.root);
                      }
	                  break;
	          case 6: if(bt.root==null)
                      System.out.println("\nBinary tree is empty cannot perform traversal");
                      else
                      {
                        System.out.println("\nThe non recursive Inorder traversal:");
                        bt.Ninorder();
                      }
                      break;
	          case 7: if(bt.root==null)
                      System.out.println("\nBinary tree is empty cannot perform traversal");
                      else
                      {
	                    System.out.println("\nThe non recursive Postorder traversal");
	                    bt.Npostorder(bt.root);
                      }
                      break;
              case 0:System.out.println("\nExit");
                     break;
             default:System.out.println("\nInvalid choice,try again");

            }

          System.out.println("\nDo you want to continue??1 to continue,0 to exit");
          no=sc.nextInt();
         }while (no==1);

	}

}
//OUTPUT
/*
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
2

Binary tree is empty cannot perform traversal

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
3

Binary tree is empty cannot perform traversal

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
4

Binary tree is empty cannot perform traversal

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
5

Binary tree is empty cannot perform traversal

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
6

Binary tree is empty cannot perform traversal

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
7

Binary tree is empty cannot perform traversal

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
1
Enter data to add new node to the binary tree:
10

Root inserted successfully
Do you wish to add more nodes?(y/n)
y
Enter data to add new node to the binary tree:
12
The current Node is :10
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
2

Do you wish to add more nodes?(y/n)
y
Enter data to add new node to the binary tree:
8
The current Node is :10
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
1

Do you wish to add more nodes?(y/n)
y
Enter data to add new node to the binary tree:
9
The current Node is :10
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
1
The current Node is :8
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
2

Do you wish to add more nodes?(y/n)
y
Enter data to add new node to the binary tree:
7
The current Node is :10
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
1
The current Node is :8
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
1

Do you wish to add more nodes?(y/n)
y
Enter data to add new node to the binary tree:
12
The current Node is :10
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
2
The current Node is :12
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
1

Do you wish to add more nodes?(y/n)
y
Enter data to add new node to the binary tree:
13
The current Node is :10
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
2
The current Node is :12
Enter the direction to insert new node of cur node(l/r)(1 is left and 2 is right)
2

Do you wish to add more nodes?(y/n)
n

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
2

(Recursive)Preorder traversal of Binary tree is 10  8  7  9  12  11  13
Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
3

(Recursive)Inorder traversal of Binary tree is 7  8  9  10  11  12  13
Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
4

(Recursive) Postorder traversal of Binary tree is:7  9  8  11  13  12  10
Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
5

The non recursive Preorder traversal:
10 8 7 9 12 11 13
Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
6

The non recursive Inorder traversal:
7  8  9  10  11  12  13
Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
7

The non recursive Postorder traversal
7 9 8 11 13 12 10
Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
8

Invalid choice,try again

Do you want to continue??1 to continue,0 to exit
1
*****MENU*****

1.Create a Binary Tree
2.Display the recursive Preorder traversal
3.Display the recursive Inorder traversal
4.Display the recursive Postorder traversal
5.Display the non recursive Preorder traversal
6.Display the non recursive Inorder traversal
7.Display the non recursive Postorder traversal
0.Exit
Enter your choice:
0

Exit

Do you want to continue??1 to continue,0 to exit
0
*/
/*TIME COMPLEXITY

void create()=O(n)
void RPostorder(Node t)=O(n)
void RInorder(Node t1)=O(n)
void RPreorder(Node t2)=O(n)
void Ninorder()=O(n)
void Npreorder(Node tem)=O(n)
void Npostorder(Node root)=O(n)

 */
