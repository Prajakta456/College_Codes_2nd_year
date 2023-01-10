package FoodOrderSystem;
import java.util.Scanner;
public class Customer1 
{
	 int bilc=0;
	   String name;
	   String phoneNumber;
	   int cnt=0;
       int tempprice=0;
       int tempid=-1;
	   String purchasedItems[]=new String[5];
	   int pricei[]=new int[5];
	   int productid[]=new int[5];
       
	   Customer1()
	   {
	     name=null;
	     phoneNumber=null;
         cnt=0;
	     for(int i=0;i<5;i++)
	     {
	    	 productid[i]=-1;
	       purchasedItems[i]=null;
	     }
	    }

	    int purchase(Item bought,int qt,int iDD)
	   {
	    	if(cnt<=4)
	    	{
	         productid[cnt]=iDD;   
	         purchasedItems[cnt]=bought.itemName;
	         pricei[cnt]=bought.price*qt;
	         cnt++;
	         return cnt;
	    	}
	     else 
	    {
	    System.out.println("Cannot purchase more than 5 items!");
	    return -1;
	   }
	  }
	 
	  void display()
	  {
	   System.out.println("*************************************BILL*******************************************");
	   for(int i=0;i<5;i++)
	   {
	    if(purchasedItems[i]!=null)
	   {
	    bilc+=pricei[i];
	    System.out.println("-----------------------------------------------------------------------------");
	    System.out.println("Item purchased:"+purchasedItems[i]);
	    System.out.println("-----------------------------------------------------------------------------");
	    System.out.println("Price of purchased item:"+pricei[i]);
	    System.out.println("-----------------------------------------------------------------------------");
	    }
	   } 
	  }
	   void accept()          
	   {        
	        Scanner sc=new Scanner(System.in);
	        Scanner sc3=new Scanner(System.in);
	        System.out.println("Enter your name:");
	        name=sc.next();
	        do
	        {
	           System.out.println("\nEnter telephone number of the customer:");
	           phoneNumber=sc3.nextLine();
	           int count=0;
	            for(int j=0;j<phoneNumber.length();j++)
	            {
	              if(Character.isDigit(phoneNumber.charAt(j)))
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
	                     
	     }    
	     int delete(int idd)
	     {
	    	for(int i=0;i<=cnt;i++)
	    	 {
	    	 if(productid[i]==idd)
		     {
	    	  System.out.println("\nDELETED"+purchasedItems[i]);
	    	  tempprice=pricei[i];
	    	  tempid=idd;
		      productid[i]=-1;   
		      purchasedItems[i]=null;
		      pricei[i]=0;
		       return idd;
		     }
	    	 }
	    	 
	    		System.out.println("\nCannot delete food item!");
                  return -1;
	    	 
	     }
	     int revenueDeduct(int idd)
	     {
	    	 if(tempid==idd)
	    	  {
	    		 System.out.println("\nRevenue to be deducted from admin accounts"+tempprice);
	    		 return tempprice;
		     }
	    	 	    	 
	    		System.out.println("\nCannot update revenue!");
                  return -1;
	    	 
	    	 
	     }
	       
	        
}
