package FoodOrderSystem;
import java.util.*;
public class StoreFoodItems 
{
	Item root;
	
    int revenue;
    StoreFoodItems()
    {
        root=null;
    }
    StoreFoodItems(Item root)
    {
        this.root=root;
    }
              
    public Item search(Item root, int key)
    {
        // root is null or key is present at root
        if (root==null || root.id==key)
            return root;
     
        if (root.id < key)
           return search(root.right, key);
     
        return search(root.left, key);
    }
    public Item update(Item root, int key,int qt)
    {
        // root is null or key is present at root
        if (root==null || root.id==key)
        {
        	root.qtBought=root.id-qt;
            return root;
        }
        if (root.id < key)
           return search(root.right, key);
     
        return search(root.left, key);
    }
	Item insert(Item root,String name,int idFood,int priceF,int QtBt)
    {
        // Perform the normal BST insertion 
        if(root==null)
        {
            root=new Item(idFood,name,priceF,QtBt);
        }
        else
        {
        	   
            if(idFood>root.id)
            {
                root.right=insert(root.right,name,idFood,priceF,QtBt);
                
                //checking balance factor
                if(balanceFactor(root)==-2)
                {
                    if(root.right.id<idFood)
                    {
                       root=RR(root); 
                    }
                    else
                    {
                        root=RL(root);
                    }
                    
                }
                
            }
            else if(idFood<root.id)
            {
                root.left=insert(root.left,name,idFood,priceF,QtBt);
                
                //checking balance factor
                if(balanceFactor(root)==2)
                {
                    if(root.left.id>idFood)
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
            System.out.println("\nA Food item with the same ID is there in the list!\nDuplicates are not allowed!"); 
        
           
        }
        root.height=height(root);
        return root;
    }
	void create(String name,int idf,int price,int NofqtBt)
    {
        
        root=insert(root,name,idf,price,NofqtBt);
        
    }
	
     
    //create function is used to accept the food item details to be added
    void createByAdmin()
    {
        Scanner sc=new Scanner(System.in);
        Scanner sc2=new Scanner(System.in);
        String nmF;
        int priceI,idF;
        System.out.println("\nEnter the ID of the food item to add:");
        idF=sc2.nextInt();
        System.out.println("\nEnter the name of the food item to add:");
        nmF=sc2.next();
        System.out.println("\nEnter the price of the food item to add:");
        priceI=sc.nextInt();
      //call create();
        create(nmF,idF,priceI,0);
       
    }
    
    
  //calculate balance factor of tree=ht of left subtree - ht of right subtree
    int balanceFactor(Item r)	
	{
		if(r==null)
			return -1;
		else
			return (height(r.left)-height(r.right)); 
	}
 
    //finding height 
    int height(Item n)
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
    Item rotateright(Item r)
    {
    	Item temp=new Item();
       temp=r.left;
       r.left=temp.right;
       temp.right=r;
    
       r.height=height(r);
       temp.height=height(temp);
       return temp;
    }
    //function to rotate left
    Item rotateleft(Item r)
    {
       
    	Item temp=new Item();
       temp=r.right;
       r.right=temp.left;
       temp.left=r;
        
        r.height=height(r);    
        temp.height=height(temp);
        return temp;
        
    }
    /*functions for the 4 cases LL,RR,LR and RL*/
    Item LL(Item r)
    {
        r=rotateright(r);
        return r;
    
    }
    
    Item RR(Item r)
    {
        r=rotateleft(r);
        // Return new root
        return r;
    }
    
    Item LR(Item r)
    {
        r.left=rotateleft(r.left);
        r=rotateright(r);
        return r;
        
    }
    
    Item RL(Item r)
    {
        r.right=rotateright(r.right);
        r=rotateleft(r);
        return r;
    }
    void Inorderdisplay(Item i) 
    {
       if(i==null)
        return;
        else
        {
            
            Inorderdisplay(i.left);
            System.out.println("---------------------------------------------------------------------------------------------------------");
            System.out.print("FOOD  ITEM  ID :");
            System.out.println(i.id);
            
            System.out.print("FOOD   ITEM    :");
            System.out.println(i.itemName);
            
            System.out.print("PRICE OF 1  QT :");
            System.out.println(i.price);          
            System.out.println("----------------------------------------------------------------------------------------------------------");
            Inorderdisplay(i.right);
            
        }
       
    }
    

}
