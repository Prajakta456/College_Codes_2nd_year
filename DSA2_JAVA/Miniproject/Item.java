package FoodOrderSystem;
public class Item
{
	String itemName;
	int price;
	int qtBought;
	int id;
	Item left;  
	Item right;
	int height;
		    
		    Item(int id,String itemName,int price,int qtBought)
		    {  
		    //Assign data to the new node, set left and right children to null  
		    	this.id=id;
		        this.itemName = itemName;
		        this.price=price;
		        this.qtBought=qtBought;
		        left = right = null;
		        height=1;
		        
		    }
		    Item()
		    {
		    	this.id=-1;
		        this.itemName = null;
		        this.price=0;
		        this.qtBought=0;
		         left=right=null;
		         height=1;    
		    }
}
	