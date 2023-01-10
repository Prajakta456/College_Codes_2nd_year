/*
FOOD ORDERING SYSTEM
Roll nos included: 2330,2333,2335,2338

Data Structures used:AVL Tree,Array,Graph

AVL TREE- for storing all the food items

Graph: For delivery of food items(Dijkstra's algorithm for shortest path and time)

Array:For Storing Purchased items bought by customer

(ArrayList is used for review system)

*/

package FoodOrderSystem;
import java.util.*;
public class Main 
{
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		int avgRating=0;
		ArrayList<Integer> review=new ArrayList<Integer>(15);
		review.add(5);
		review.add(4);
		review.add(5);
		review.add(5);
		Iterator<Integer> iter1 = review.iterator();
		int sum1=0;
	    Item deletedIt=null,updated=null;
		int p,cnt=0,ID,qt;
        int revenuechange=0;
		 while(iter1.hasNext())
		  {
		    int n=iter1.next();
		    sum1=sum1+n;
		  }    
		   
		    avgRating=sum1/review.size();
		    int revenue=0;
		   Scanner sc=new Scanner(System.in);
		   Scanner sc1=new Scanner(System.in);
		   String password="hello123";
		   String itemN,passentered;
		   int q,ch,f,r,flag=0,t,comps,itch,custch;
		   char choice,deliverych,temps;
		    int val;
		       
		    Item temp=new Item();
		    Item temp1=new Item();
		    Item temp2=new Item();

		    int idTosearch;

		    int adjmat[][] = new int[][] { {0,0,0,10,7,8,5,0,0,0},
		                                    {0,0,0,0,0,0,0,3,0,2},
		                                    {0,0,0,4,0,6,0,0,0,7},
		                                    {10,0,4,0,0,0,1,0,2,0},
		                                    {7,0,0,0,0,0,0,6,0,0},
		                                    {8,0,6,0,0,0,0,0,0,0},
		                                    {5,0,0,1,0,0,0,0,0,0},
		                                    {0,3,0,0,0,0,0,3,0,2},
		                                    {0,0,0,2,0,0,0,3,0,0},
		                                    {0,2,7,0,0,0,0,5,0,0},};
		   
		          String places[]={"FC road","Shivaginagar","Aundh","Baner","Vidhyapeeth Chowk","Katraj","Karvenagar","Sinhagad Road","Sangavi","MG road"};
		     

		 StoreFoodItems a1=new StoreFoodItems();
		 StoreFoodItems a2=new StoreFoodItems();
		 StoreFoodItems a3=new StoreFoodItems();
		 
		//id,String itemName,int price,int qtBought
		     
		      a3.create("Coffee icecream",4,45,5);
		      a3.create("Butterscotch icecream",6,40,10);
		      a3.create("Vanilla icecream",5,35,6);
		      a3.create("Strawberry icecream",3,30,3);
		      a3.create("Chocalate chip cookie icecream",2,50,4);
		      a3.create("Pistachio icecream",7,30,8);
		      a3.create("Mango icecream",9,40,7);
		      a3.create("Chocolate icecream",8,60,6);
		      a3.create("Cotton candy icecream",1,25,4);
		      a3.create("Cornetto icecream",10,55,5);
		 
		      a2.create("Spring Roll",26,75,12);
		      a2.create("Masala papad",27,60,0);
		      a2.create("Roasted Veggies with Pesto Sauce Tartine",30,65,4);
		      a2.create("Corn Cheese on Toast",18,250,9);
		      a2.create("Tomato soup",17,80,2);
		      a2.create("Mixed vegetable salad",28,60,4);
		      a2.create("Crispy spinach and corn",15,75,5);
		      a2.create("Sabudana Tikki",20,65,7);
		      a2.create("Veg Manchow Soup",16,100,8);
		      a2.create("French Fries",19,80,3);
		      a2.create("Lasagna Roll",23,435,4);
		      a2.create("Masala Dosa",21,320,5);
		      a2.create("Masala Dosa",22,320,5);
		      a2.create("Grill Mayo Sandwich", 24, 100, 7);
		     
		      a1.create("Bundi Raita",42,85,3);
		      a1.create("Panner Butter Masala",41,210,7);
		      a1.create("Veg Biryani",44,300,9);
		      a1.create("Palak Paneer",43,310,2);
		      a1.create("Rajasthani Thali",45,325,4);
		      a1.create("Bengali Vegeterian Thali",36,390,6);
		      a1.create("Veg Hakka Noodles",46,200,7);
		      a1.create("Maharashtrian Thali",47,450,6);
		      a1.create("Veg Khadai",35,225,3);
		      a1.create("Dal Makhani",48,185,5);
		      a1.create("Butter Tawa Pulao",49,155,8);
		      a1.create("Bhindi Masala",38,170,3);
		      a1.create("Veg Manchurian Dry",37,180,9);
		      a1.create("Burnt Garlic Fried Rice",50,250,9);
		      a1.create("Chana Masala",40,190,5);
		      a1.create("Jeera Rice",39,160,8);
		     
		  do
		      {
		      System.out.println("\n***************************************************************************************");
		      System.out.println("\nWelcome to Online Food Ordering System!!");
		      System.out.println("\nAverage rating of our food ordering system is "+avgRating+ " STAR");
		      System.out.println("****************************************************************************************");
		      System.out.println("Login as:");
		      System.out.println("****************************************************************************************");
		      System.out.println("A.Admin");
		      System.out.println("B.Customer");
		      System.out.println("C.Exit");
		      System.out.println("****************************************************************************************");
		      System.out.println("Enter your choice:");
		      choice=sc.next().charAt(0);
		      if(choice=='a'||choice=='b'||choice=='c')
		      {
		      choice=Character.toUpperCase(choice);
		      }
		      switch(choice)
		      {
		      case 'A':System.out.println("Enter password to login:");
		               passentered=sc1.next();
		               comps=passentered.compareTo(password);
		               if(comps==0)
		               {
		             do
		                     {
		                     System.out.println("\nAdmin Activities:");
		                     System.out.print("\n1.Add a food item to the food items list");
		                     System.out.print("\n2.Display the food items list");
		                     System.out.print("\n3.Display the Revenue for the day");
		                     System.out.print("\n4.Display the number of quantities for a particular item sold");
		                     System.out.println("\n0.Exit");
		                 System.out.println("Enter your choice:");
		                     ch=sc.nextInt();
		                   
		                     switch(ch)//Switch case
		                     {
		                      case 0:System.out.println("\nExiting admin options");
		                             break;
		                    case 1:do
		                             {
		                        System.out.println("Do you want to add item to \n(1)lunch items\n(2)soups,salads and breakfast items\n(3)icecreams:");      
		                                   itch=sc.nextInt();
		                                    if(itch==1)
		                                    {
		                                    a1.createByAdmin();
		                                   
		                                    }
		                           
		                                    else if(itch==2)
		                                    a2.createByAdmin();
		                           
		                                    else if(itch==3)
		                                    a3.createByAdmin();
		                                   
		                                    else
		                                    System.out.println("Wrong choice ,try again");
		                           
		                                    System.out.println("Enter 1 to continue adding items to the food items list:");
		                                    t=sc.nextInt();
		                                  }while(t==1);
		                                 break;
		                 case 2:System.out.println("********************************************************************************************************");
		                            System.out.println("The food item list is as follows:");
		                            System.out.println("=========================================================================================================");
		                               System.out.println("ICECREAMS:");
		                               System.out.println("==========================================================================================================");
		                               a3.Inorderdisplay(a3.root);
		                               System.out.println("==========================================================================================================");
		                               System.out.println("SOUPS,SALADS AND BREAKFAST ITEMS:");
		                               System.out.println("==========================================================================================================");
		                               a2.Inorderdisplay(a2.root);
		                               System.out.println("==========================================================================================================");                              
		                               System.out.println("LUNCH FOOD ITEMS:");
		                               System.out.println("=========================================================================================================");
		                               a1.Inorderdisplay(a1.root);
		                               System.out.println("=========================================================================================================");
		                               
		                               
		                               break;
		                       
		                 case 3:System.out.println("Revenue genereated today:"+revenue);
		                        break;
		                 case 4:System.out.println("Do you want to search item in \n(1)lunch items\n(2)soups,salads and breakfast items\n(3)icecreams:");
		                               itch=sc.nextInt();
		                          System.out.println("Enter food item id to search it number of quantities sold:");
		                               idTosearch=sc.nextInt();
		                               
		                               
		                               if(itch==1)
		                               {
		                              if(idTosearch>=35 && idTosearch<=50)  
		                              {
		                            temp2=a1.search(a1.root,idTosearch);
		                               }  
		                              else
		                                    System.out.println("Item not found, Try again!");
		                               }
		                               else if(itch==2)
		                               {
		                              if(idTosearch>=16 && idTosearch<=30)  
		                                       temp2=a1.search(a2.root,idTosearch);
		                              else
		                                    System.out.println("Item not found, Try again!");
		                                 
		                               }
		                               else if(itch==3)
		                               {
		                               if(idTosearch>=1 && idTosearch<=10)  
		                                    temp2=a1.search(a3.root,idTosearch);
		                                   
		                                    else
		                                    System.out.println("Item not found, Try again!");
		                               }
		                            if(temp2!=null)
		                            {
		                            System.out.println("Food item name:"+temp2.itemName);
		                             System.out.println("Food item price:"+temp2.price);
		                             System.out.println("Number of quantities sold:"+temp2.qtBought);
		                             r=temp2.price*temp2.qtBought;
		                             System.out.println("Revenue earned from selling"+temp2.itemName+"till today from starting:"+" is "+r);
		                            }
		                           break;
		                
		        
         default:System.out.println("\nWrong choice try again");
                 break;        
		                       
		                }//close admin switch
		               }while(ch!=0);
		              }//close if
		           else
		           {
		            System.out.println("Incorrect  password entered!");
		            System.out.println("Cannot login as Admin,try again");
		           }
		           break;
		  case 'B':Customer1 c1=new Customer1();
		           do
		          {
		         System.out.println("*****************************************************************************");
		         System.out.println("\nWelcome to Online Food Ordering System!!");
		         System.out.println("******************************************************************************");
		         System.out.println("\n1.Display Food Items Menu");
		         System.out.println("\n2.Purchase Food Items");
		         System.out.println("\n3.Delete a food Item after purchasing");
		         System.out.println("-----------------------------------------------------------------------------");
		         System.out.println("\n***Home Delivery of purchased items can be done after exiting this section***");
		         System.out.println("\n***Review Online Food ordering system***");
		         System.out.println("\n0.Exit");
		               
		         System.out.println("\nEnter your choice:");
		         custch=sc.nextInt();
		         switch(custch)
		         {
		         case 0:System.out.println("\nExiting Customer options");
		                break;
		         case 1:System.out.println("********************************************************************************************************");
		                         System.out.println("The food item list is as follows:");
		                         System.out.println("=========================================================================================================");
		                         System.out.println("ICECREAMS:");
		                         System.out.println("==========================================================================================================");
		                         a3.Inorderdisplay(a3.root);
		                         System.out.println("==========================================================================================================");
		                         System.out.println("SOUPS,SALADS AND BREAKFAST ITEMS:");
		                         System.out.println("==========================================================================================================");
		                         a2.Inorderdisplay(a2.root);
		                         System.out.println("==========================================================================================================");                              
		                         System.out.println("LUNCH FOOD ITEMS:");
		                         System.out.println("=========================================================================================================");
		                         a1.Inorderdisplay(a1.root);
		                         System.out.println("=========================================================================================================");
		                         break;
		         case 2:do
		                {
		                  System.out.println("*************PURCHASE SECTION****************");  
		                  System.out.println("Do you want to purchase item from \n(1)lunch items\n(2)soups,salads and breakfast items\n(3)icecreams:");      
		                  itch=sc.nextInt();
		                  System.out.println("Enter the food item id you want to buy:");
		                  f=sc1.nextInt();
		                  System.out.println("Enter the quantity you want to buy:");
		                  q=sc1.nextInt();
		                  if(itch==1)
		                  {
		                     temp1=a1.search(a1.root,f);
		                           
		                  }
		                   else if(itch==2)
		                  {
		                    temp1=a2.search(a2.root,f);
		                           
		                   }
		                   else if(itch==3)
		                   {
		                       temp1=a3.search(a3.root,f);
		                           
		                    }
		                   if(temp1!=null)
		                    {
		                      System.out.println("Item bought: "+temp1.itemName);
		                      val=c1.purchase(temp1,q,f);
		                      if(val<=4)
		                      temp1.qtBought=temp1.qtBought+q;
		                       revenue=revenue+temp1.price*q;
		                      //System.out.println("Revenue is"+revenue);
		                    }
		                    else
		                    {
		                        System.out.println("\nFood Item not found in the menu!");
		                        System.out.println("\nIncorrect entry!");
		                     }
		                    System.out.println("Do you wish to continue purchasing food items?(1 for yes)");
		                    flag=sc.nextInt();
		                   }while(flag==1);
		                   break;
		         case 3:System.out.println("Enter productId that you wish to delete:");      
	                    ID=sc.nextInt();
	                    System.out.println("Enter the number of qt you want to delete");
	                    qt=sc.nextInt();
	                    int confirm=c1.delete(ID);
	                    if(confirm!=-1)
	                    {
	                    	if(confirm>=1 && confirm<=10)
	                    	{
	                    		updated=a1.update(a1.root,confirm,qt);
	                    	}
	                    	else if(confirm>=15 && confirm<=30)
	                    	{
	                    		updated=a1.update(a2.root,confirm,qt);
	                    		
	                    	}
	                    	else if(confirm>=35 && confirm<=50)
	                    	{
	                    		updated=a1.update(a3.root,confirm,qt);
	                    	}
	                    	
	                    		System.out.println("\nFOOD ITEMS LIST UPDATED SUCCESSFULLY!");
	                    		revenuechange=c1.revenueDeduct(ID);
	                    		revenue-=revenuechange;
	                    	
	                    }
	                    
	                    break;          
		         default:System.out.println("\nInvalid choice!");
		                 break;
		                  }//close switch()
		            }while(custch!=0);
		           System.out.println("-----------------------------------------------------------------------------");
		           System.out.println("Enter your details :\n");
		           c1.accept();
		           System.out.println("-----------------------------------------------------------------------------");
		           c1.display();
		           System.out.println("BILL FOR FOOD ITEMS BOUGHT:"+c1.bilc);
		          
		           System.out.println("-----------------------------------------------------------------------------");
		           System.out.println("GIVE REVIEW FOR ONLINE FOOD ORDERING SYSTEM");
		           System.out.println("Rate out of 5");
		           int star=sc.nextInt();
		           if(star<=5)
		           review.add(star);
		          
		         
		           Iterator<Integer> iter = review.iterator();
		                     
		            int sum=0;
		           while(iter.hasNext())
		           {
		            int n=iter.next();
		            sum=sum+n;
		            }
		           
		           avgRating=sum/review.size();
		           
		        
		      
		       System.out.println("\nHome delivery is compulsory!!");
		          //3 is the restaurant address
		                   System.out.println("Restaurant Address:"+places[3]);
		                   System.out.println("We have delivery service to the following addresses:");
		                   for(int i=0;i<10;i++)
		                   {
		                    System.out.println((i)+"->"+places[i]);
		                   }
		                   
		          		Delivery.dijkstra(adjmat,3);
		                  System.out.println("Delivery charge is 20 for all distances");
		                     c1.bilc=c1.bilc+20;
		                     System.out.println("FINAL BILL WITH THE DELIVERY CHARGES IS"+c1.bilc);      
        		
        		     break;
		     
		  case 'C':System.out.println("Thank you for visiting!");
		           break;
		  default:System.out.println("Incorrect choice,Try again!");
		              break;        
		  }

		}while(choice!='C');
		
		 
	}
}
//close Main



