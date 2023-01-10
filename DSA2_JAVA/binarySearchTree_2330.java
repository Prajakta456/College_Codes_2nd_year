/******************************************************************************
Roll no:2330
Name:Prajakta Deokule
CNumber: C22019221332
Assignment number:2
Title: To implement Binary Search Tree and perform operations on it.

Write a program to create a BST and perform following operations
1. Find minimum or maximum node in a tree
2. Display tree level wise
3. Display tree in descending order
4. Count no.of leaf nodes recursive
(Extra functions- Find parent of a given node, Find height of a tree )
*******************************************************************************/
import java.util.*;
class Node
{  
        int data;  
        Node left;  
        Node right;  
  
        Node(int data)
        {  
        //Assign data to the new node, set left and right children to null  
            this.data = data;  
            left = right = null;  
        }
        Node()
        {
        data=0;        
        left=right=null;
        }
  }
class BinarySearchTree
{
    Node root = null;
	BinarySearchTree()
	{
		root = null;
	}
	BinarySearchTree(Node rt)
	{
		root = rt;
	}
	//function to search a node in the BST
	Node search(int t)
	{
	    Node temp=null;
	    if(root==null)
	    return temp;
	    else if(root.data==t)
	    return root;
	    else
	    {
	        Node ptr=root;
	        while(ptr!=null && ptr.data!=t)
	        {
	            if(t<ptr.data)
	             ptr=ptr.left;
	            
	            else
	            ptr=ptr.right;
	        }
	        
	        temp=ptr;
	    }
	    return temp;
	}
	//function to create BST
	void create(int val)
	{
	    Node nnode=new Node(val);
	    if(search(val)!=null)      //checking if node is already inserted and not allowing insertion again
        {
            System.out.println("\nDuplicate elements are not allowed in binary search tree");
            return;
        }
        if(root==null)
        {
            root=nnode;
            System.out.println("\nRoot created successfully");
        }
        else
        {
            Node temp=root;
           while(temp!=null)
          {
            if(nnode.data<temp.data && temp.left==null)
            {
                temp.left=nnode;
                break;
            }
            else if(nnode.data<temp.data && temp.left!=null)
            {
                temp=temp.left;
            }
            else if(nnode.data>temp.data && temp.right==null)
            {
                temp.right=nnode;
                break;
            }
            else if(nnode.data>temp.data && temp.right!=null)
            {
               temp=temp.right; 
            }
          }
          System.out.println("\nNode inserted successfully");
        }
	   
	}
	//function to find maximum node in BST
    int maximum()
    {
        if(root==null)
        return -1;
        else
        {
            Node cur=root;
            while(cur.right!=null)
            {
                cur=cur.right;
            }
            return cur.data;
        }
    }
    //function to find minimum node in BST
    int minimum()
    {
        if(root==null)
        return -1;
        else
        {
            Node cur=root;
            while(cur.left!=null)
            {
                cur=cur.left;
            }
            return cur.data;
        }
    }
    //function to display level order traversal of BST
    void levelwise()
    {
        if(root==null)
        {
            System.out.println("\nTree is empty,cannot traverse");
        }
        else
        {
           System.out.println("The Level Order Traversal of Binary Search Tree is as follows :");
           
           Queue <Node> q=new LinkedList<>();
           //creating queue to store and display the node at each level
           
           //pushing root into Queue
           q.add(root);
           
           // Pushing delimiter into the queue
           q.add(null);
           
           //executing loop till queue becomes empty
           while(!q.isEmpty())
           {
               Node cur=q.poll();
               
                // condition to check the
                // occurence of next level
                
                if(cur==null)
                {
                    if(!q.isEmpty())
                    {
                        q.add(null);
                        System.out.println();
                    }
                }
                else
                {
                    if(cur.left!=null)
                    {
                        q.add(cur.left);
                    }
                    if(cur.right!=null)
                    {
                        q.add(cur.right);
                    }
                    System.out.print(cur.data+"  ");
                }
           }
                
        }    
                  
    }
    //function to traverse BST in descending order
    void ReverseInorder(Node n)
    {
        if(n==null)
        return;
        else
        {
            ReverseInorder(n.right);
            System.out.print(n.data+" ");
            ReverseInorder(n.left);
        }
    }
    //functions to count the number of leaf nodes in the BST
    int count_leaf_nodes()
    {
        return(getLeafNode(root));
    }
    int getLeafNode(Node node)
    {
        if(node==null)
        return 0;
        else if(node.left==null && node.right==null)
        return 1;
        else
        return(getLeafNode(node.left)+getLeafNode(node.right));
        
    }
    Node findParent(int nd)
	{
		Node temp=root;
		Node prev=root;      //prev to maintain the parent node of present element
		Node result=null;   
		if(nd==root.data)   
			result =null;
		else                      //if root is not the node whose parent is to be searched
		{
			while(temp!=null)
			{
				if(temp.data==nd)       
				{
					 result=prev;
					 break;
				}
				else if(nd<temp.data)   
				{
					prev=temp;
					temp=temp.left;
				}
				else if(nd>temp.data)   
				{
					prev=temp;
					temp=temp.right;
				}
			}
		}
		return result;          //returning the result i.e the parent of the node to be searched
    }

   //function to find the height of the BST
	int height(Node t)
	{
	    if(t==null)
	     return 0;
	    
	    else
	    {
	         /* compute the depth of each subtree */
	        int lht=height(t.left);
	        int rht=height(t.right);
	        
	        //take the larger subtree
	        if(lht>rht)
	         return(lht+1);
	       
	        else
	          return(rht+1);
	        
	    }
	}
}
public class Main
{
	public static void main(String[] args)
	{
	   int ch,t,v,htbst,fp,flag=0,minN=0,maxN=0,cl;
	   Node temp1=null;
       Node temp=null;
       BinarySearchTree bst=new BinarySearchTree();
       Scanner sc=new Scanner(System.in);
       do
       {
        System.out.println("\n****MENU****");
        System.out.print("\n1.Create a Binary Tree \n2.Display tree Levelwise ");
        System.out.print("\n3.Find Minimum  node \n4.Find Maximum node\n5.Display in Descending order ");
        System.out.print("\n6.Count no of leaf nodes\n7.Find parent of given node");
        System.out.print("\n8.Find the height of the tree \n0.Exit");
        
        System.out.println("\nEnter your choice:");
        ch=sc.nextInt();
        switch(ch)//Switch case
        {
         case 1:do
                {
                  System.out.println("Enter value the binary search tree:");
                  v=sc.nextInt();
                   //call create();
                  bst.create(v);    
                  System.out.println("Enter 1 to continue adding nodes to the binary search tree:");
                  t=sc.nextInt();
                }while(t==1); 
                break;
         case 2:bst.levelwise();
                //call Levelwise();
                break;
         case 3:minN=bst.minimum();
                if(minN==-1)
                System.out.println("Tree is empty cannot find minimum node");
                else
                System.out.println("The minimum node in the binary search tree:"+minN);
                break;
         case 4:maxN=bst.maximum();
                if(maxN==-1)
                System.out.println("Tree is empty cannot find maximum node");
                else
                System.out.println("The maximum node in the binary search tree:"+maxN);
                break;
         case 5:if(bst.root==null)
                System.out.println("The binary search tree in empty,cannot display in descending order");
                else
                {
                   System.out.println("The binary search tree in descending order:");
                   bst.ReverseInorder(bst.root);
                }
                break; 
         case 6:cl=bst.count_leaf_nodes();
                //Call count_leaf_nodes function
                System.out.println("There are "+cl+" leaf nodes in the binary search tree");
                
                break;
         case 7:System.out.println("Enter value to find its parent in the binary search tree is:");
                fp=sc.nextInt();
                if (bst.root == null)
		        {
		            System.out.println("Tree is empty,cannot find parent");
			    }
			    else
			    {
                   temp1=bst.search(fp);
                   if(temp1==null)
                    System.out.println("node not found in tree so cannot find parent");
                    else
                    {
                      temp=bst.findParent(fp);
                      if(temp==null)
                      System.out.println(fp+" is root node,Parent is not there");  
                      
                      else
                      System.out.println("Parent of "+fp+" is"+temp.data);
                    }
                }
                break;
                
         case 8:htbst=bst.height(bst.root);
                //Call height function
                System.out.println("The height of the binary search tree is"+htbst);
                break;
         default:System.out.println("\nWrong choice try again");
        }
       System.out.println("\nDo you want to continue (1 to continue,0 to exit)");
       ch=sc.nextInt();
      }while (ch==1);
   }
}
//OUTPUT
/*

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
2

Tree is empty,cannot traverse

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
3
Tree is empty cannot find minimum node

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
9

Wrong choice try again

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
4
Tree is empty cannot find maximum node

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
5
The binary search tree in empty,cannot display in descending order

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
6
There are 0 leaf nodes in the binary search tree

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
7
Enter value to find its parent in the binary search tree is:
2
Tree is empty,cannot find parent

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
8
The height of the binary search tree is0

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:

1
Enter value the binary search tree:
10

Root created successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
6

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
20

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
8

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
15

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
9

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
22

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
24

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
23

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
1
Enter value the binary search tree:
21

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
0

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
2
The Level Order Traversal of Binary Search Tree is as follows :
10  
6  20  
8  15  22  
9  21  24  
23  
Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
3
The minimum node in the binary search tree:6

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
4
The maximum node in the binary search tree:24

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
5
The binary search tree in descending order:
24 23 22 21 20 15 10 9 8 6 
Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
6
There are 4 leaf nodes in the binary search tree

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
8
The height of the binary search tree is5

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
7
Enter value to find its parent in the binary search tree is:
15
Parent of 15 is20

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
7
Enter value to find its parent in the binary search tree is:
6
Parent of 6 is10

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
7
Enter value to find its parent in the binary search tree is:
23
Parent of 23 is24

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
7
Enter value to find its parent in the binary search tree is:
10
10 is root node,Parent is not there

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
7
Enter value to find its parent in the binary search tree is:
18
node not found in tree so cannot find parent

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
1
Enter value the binary search tree:
27

Node inserted successfully
Enter 1 to continue adding nodes to the binary search tree:
0

Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
2
The Level Order Traversal of Binary Search Tree is as follows :
10  
6  20  
8  15  22  
9  21  24  
23  27  
Do you want to continue (1 to continue,0 to exit)
1

****MENU****

1.Create a Binary Tree 
2.Display tree Levelwise 
3.Find Minimum  node 
4.Find Maximum node
5.Display in Descending order 
6.Count no of leaf nodes
7.Find parent of given node
8.Find the height of the tree 
0.Exit
Enter your choice:
4
The maximum node in the binary search tree:27

Do you want to continue (1 to continue,0 to exit)
0
*/
/********TIME COMPLEXITY***********
Node search(int t)=O(n)
void create(int val)=O(n)
int maximum()=O(n)
int minimum()=O(n)
void levelwise()=O(n)  n is number of levels
int count_leaf_nodes()=O(n)
void ReverseInorder(Node n)=O(n)
int height(Node t)=O(n)
Node findParent(int nd)=O(n)*/

