/*
Group No. 04
MINI-PROJECT:

Title: Implementing Interactive On-line Shopping System.

Members:

1) Prajakta R. Deokule (2330)
2) Shriharsha S. Dhobe (2334)
3) Aditi A. Dhumal (2335)
4) Kshitija S. Gadade (2338)

*/

#include<iostream>
#include<string.h>
#include <ctime>
using namespace std;

class CustomerDetails
{
public:
    CustomerDetails *next;

    string cname;
    string password1;
    string password2;
    string emailId;
    string address;


    CustomerDetails (string n,string p,string p1,string e,string ad)
    {
        cname = n;
        password1 = p;
        password2 = p1;
        emailId = e;
        address = ad;
        next = NULL;
    }
    friend class cList;
};

class cList
{
    CustomerDetails *head;
public:
    cList ()
    {
        head = NULL;
    }
    void signUp();
    void displaydetails();
    void login();
    int validate(CustomerDetails *p);
};

int cList::validate(CustomerDetails *p)
{
    int flag=1;
    string str;

    if(flag==1)
    {
        str=p->emailId;
        int cnt=0;
        for(int i=0; str[i]!='\0'; i++)
        {
            if((str[i]=='@') || (str[i]=='.'))
            {
                cnt++;
            }
        }
        if(cnt<2)
        {
            cout << "Please Enter Valid Email-Id! Try Signing in Again!" << endl;
            flag=0;
            return 0;
        }
    }
    if(flag==1)
    {
        if(p->password1!=p->password2)
        {
            cout << "Passwords do not match. Try Signing in Again!" << endl;
            flag=0;
            return 0;
        }
    }
    return flag;
}

void cList::displaydetails()
{
    CustomerDetails *ptr=head;
    if(head==NULL)
    {
        cout << "No Customer Signed Up." << endl;
    }
    else
    {
        while(ptr!=NULL)
        {
            cout << "\nDetails of Customer are: " << endl;
            cout << "\nName: " << ptr->cname << endl;
            cout << "Email-Id: " << ptr->emailId << endl;
            cout << "Address: " << ptr->address << endl;
            ptr=ptr->next;
        }
    }
}

void cList::signUp()
{
    string n,p,p1,e,addr;
    int x;
    CustomerDetails *temp;
    do
    {
        cout << "Please SignUp:" << endl;
        cout << "\nEnter your name: " ;
        cin >> n;
        cout << "\nEnter your email id: ";
        cin >> e;
        cout << "\nEnter your password: ";
        cin >> p;
        cout << "\nConfirm your password: ";
        cin >> p1;
        cout << "\nEnter your address: ";
        cin >> addr;
        temp = new CustomerDetails(n,p,p1,e,addr);
        x=validate(temp);

    }
    while(x!=1);
    if(x==1)
    {
        CustomerDetails *ptr =head;

        if(head==NULL)
        {
            head=temp;
        }
        else
        {
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }

        cout << "Account Created Successfully!" << endl;
        cout << "Hello! " << temp->cname << endl;
    }
};

void cList::login()
{
    string mail,pass;
    cout << "\nEnter e-mail Id: ";
    cin >> mail;
    cout << "\nEnter password: ";
    cin >> pass;
    if(head==NULL)
    {
        cout<< "Account does not exist\nPlease sign up!";
        signUp();
    }
    else
    {
        CustomerDetails *ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->emailId==mail)
            {
                if(ptr->password1==pass)
                {
                    cout << "\nWelcome! Successfully logged in\n";
                    cout << ptr->cname << endl;
                    return;
                }
                else
                {
                    cout << "Invalid Password! Try Logging in again." << endl;
                    return;
                }
            }
            else
            {
                cout<< "Account does not exist.\nPlease sign up!";
                signUp();
                return;
            }
            ptr=ptr->next;
        }
    }

};

class Node
{
public:
    int cnt,price,productId;
    string prdtname;
    Node *next;

    Node()
    {
        cnt=0;
        price=0;
        productId=0;
        prdtname="";
        next=NULL;
    }

    friend class llist;
};

class llist
{

    Node* head;

public:
    llist()
    {
        head=NULL;
    }

    void push(int pId,int Availablenum,string name,int cost);
    void display(int s,int e);


    Node decrementQt(int d,int quantity);
    void incrementQt(int productid,int quantityc);

    void AddItems();

    void AdminAdds();

};


void llist::AddItems()
{
    push(1,25,"Crocin Tablet            ",20);
    push(2,25,"Paracetamol Tablet       ",40);
    push(3,25,"Azithral 500 Tablet      ",50);
    push(4,25,"Dolo Tablet              ",30);
    push(5,25,"Aspirin Tablet           ",15);
    push(6,25,"Alex Syrup(100ml bottle) ",100);
    push(7,25,"Azee(500mg) Tablet       ",25);
    push(8,25,"ALlegra-M Tablet         ",20);
    push(9,25,"Ascoril D Plus Syrup     ",100);
    push(10,25,"Azax 500 Tablet          ",23);
    push(11,20,"Rice (1 Kg)              ",38);
    push(12,20,"Wheat flour(1 Kg)        ",50);
    push(13,20,"Moong Dal(1 Kg)          ",70);
    push(14,20,"Sugar(1 Kg)              ",30);
    push(15,30,"Coffee                   ",20);
    push(16,10,"Peanut Oil(1 litre)      ",100);
    push(17,10,"Tomato Ketchup(1)        ",40);
    push(18,15,"Detergent (1 Kg)         ",50);
    push(19,25,"Room Freshener           ",70);
    push(20,25,"floor Cleaner(1)         ",60);
    push(21,25,"Onions(1 Kg)             ",30);
    push(22,10,"Tomatoes(1 Kg)           ",12);
    push(23,10,"Garlic(1 Kg)             ",80);
    push(24,10,"Ginger(1 Kg)             ",110);
    push(25,15,"Spinach (1 Bunch)        ",20);
    push(26,15,"Potato(1 Kg)             ",35);
    push(27,5,"Double Beans(1 Kg)        ",55);
    push(28,15,"Coriander(1 Bunch)       ",20);
    push(29,10,"Sweet Lime(i Kg)         ",40);
    push(30,10,"Apple (1 Kg)             ",90);
    push(31,10,"Banana (1 Kg)            ",100);
    push(32,20,"Mango-Alphonso(1 Kg)     ",100);
    push(33,30,"Milk (1 Ltr)             ",50);
    push(34,50,"Cheese (1 Packet)        ",70);
    push(35,50,"Yogurt (1)               ",50);
    push(36,10,"Paneer(1 Pack)           ",350);
    push(37,15,"Polo T-shirt             ",500);
    push(38,10,"Denim Jeans              ",2000);
    push(39,10,"Anklets (1pair)          ",300);
    push(40,10,"Sunglasses               ",3000);
    push(41,5,"Watch                     ",2500);
    push(42,10,"Wallet                    ",600);
    push(43,15,"Earrings(1pair)           ",200);
    push(44,10,"Shoes(1pair)              ",3500);
    push(45,12,"Umbrella                  ",200);
    push(46,12,"Headphones                ",500);
    push(47,15,"Telivision                ",20000);
    push(48,10,"Lenovo Laptop(Inspiron 14)",53000);
    push(49,15,"One plus Nord Blue Marble ",29900);
    push(50,7,"Samsung Galaxy A51         ",19800);
    push(51,5,"Apple iPhone 11 Pro        ",78000);
    push(52,9,"HP laptop core i3          ",42000);
    push(53,15,"HP laptop core i5         ",54000);
    push(54,15,"Inspiron 14 Laptop Dell   ",58000);
    push(55,15,"One plus Nord Blue Marble ",29900);
    push(56,15,"Ceiling fan               ",5000);

};

void llist::push(int pId,int Availablenum,string name,int cost)
{
    Node* temp=new Node();
    temp->productId=pId;
    temp->cnt=Availablenum;
    temp->prdtname=name;
    temp->price=cost;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        Node* ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
};

void llist::AdminAdds()
{
    string productName;
    int quantityPr,priceOf1qt;
    cout<<"\nEnter product Name to add to the list:";
    cin>>productName;
    cout<<"\nEnter quantity of product to add to the list:";
    cin>>quantityPr;
    cout<<"\nEnter price of 1 quantity of product to add to the list:";
    cin>>priceOf1qt;
    Node *nptr=new Node();

    nptr->cnt=quantityPr;
    nptr->prdtname=productName;
    nptr->price=priceOf1qt;

    Node* ptr1=head;
    int cntOfNodes=1;
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
        cntOfNodes++;
    }
    cntOfNodes++;
    nptr->productId=cntOfNodes;
    ptr1->next=nptr;

    cout<<nptr->prdtname<<"  ";
    cout<<nptr->productId<<"  ";
    cout<<nptr->cnt<<"  ";
    cout<<nptr->price<<"\n";
    cout<<"Node added Successfully";
};
Node llist::decrementQt(int Id,int quantity)
{
    Node obj;
    //initialiase cur
    Node *cur;
    cur=head;

    //traverse up to desired location
    while(cur->next!=NULL && cur->productId<Id)
    {
        cur=cur->next;

    }
    if((cur==NULL)||(cur->productId!=Id))
    {
        cout<<"No such element found" << endl;
        obj.productId=1000;
        obj.prdtname="";
        obj.price=cur->price;
        return(obj);
    }
    else
    {
        //cur is the node that was to be searched
        cur->cnt=cur->cnt-quantity;
        if(cur->cnt<=0)
        {
            cout<<"Item currently not available!" << endl;
            obj.productId=500;
            obj.prdtname="";
            obj.price=cur->price;
            return(obj);
        }
        else
        {
            obj.productId=cur->productId;
            obj.prdtname=cur->prdtname;
            obj.price=cur->price;
            return(obj);
        }

    }
};

void llist::display(int start,int end)
{
    if(head==NULL)
    {
        cout << "Menu is Empty." << endl;
    }
    else
    {

        Node *ptr=head;
        cout << "Items in List are: " << endl;
        int i=1;
        while(i<start)
        {
            ptr=ptr->next;

            i++;
        }
        while((ptr->next!=NULL)&&(i<end))
        {
            cout<<"|___________________|____________________________________________|________________________|"<<endl;
            cout<<"|Product Id:"<<ptr->productId<<"\t";
            cout<<"    |Product Name:" << ptr->prdtname << "\t" <<" |Product Price:" << ptr->price <<"\t  |"<< endl;
            i++;
            ptr=ptr->next;
        }
        cout<<"|___________________|____________________________________________|________________________|"<<endl;
        cout<<"|Product Id:"<<ptr->productId<<"\t";
        cout<<"    |Product Name:" << ptr->prdtname << "\t" <<" |Product Price:" << ptr->price <<"\t  |"<< endl;
        cout<<"|___________________|____________________________________________|________________________|"<<endl;
    }
};
void llist::incrementQt(int productid,int q)
{
    Node *cur;
    cur=head;

    //traverse upto desired location
    while(cur->next!=NULL && cur->productId<productid)
    {
        cur=cur->next;
    }
    if((cur==NULL)||(cur!=NULL && cur->productId!=productid))
        cout<<"\n Item not found";
    else if(cur!=NULL && cur->productId==productid)
    {
        cur->cnt=cur->cnt+q;
        cout<<"\nItem qt incremented in menu list";
    }

};
class NodeOfCart
{
public:
    int q,priceP,prId;
    string pname;
    NodeOfCart* next;

    NodeOfCart(int noOfqt,int priceP1,int IdP,string prNm)
    {
        q=noOfqt;
        priceP=priceP1;
        prId=IdP;
        pname=prNm;
        next=NULL;
    }
    friend class Customercart;
};
class Customercart
{
    NodeOfCart* start;

public:
    Customercart()
    {
        start=NULL;
    }

    void AddToCart(int noOfqt,int price,int productId,string prdtname);
    void CalculateTotalPrice();
    int  DeleteItem(int productId);
    void displayCart();

};

void Customercart::AddToCart(int noOfqt,int price,int productId,string prdtname)
{
    NodeOfCart *temp=new NodeOfCart(noOfqt,price,productId,prdtname);

    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        NodeOfCart* ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->next=NULL;
    }
    cout << "Item added to cart!" << endl;

};


void Customercart::displayCart()
{
    if(start==NULL)
    {
        cout << "Shopping cart is Empty!" << endl;
    }
    else
    {

        NodeOfCart *ptr=start;
        cout << "Items in Cart are: " << endl;
        if(start==NULL)
        {
            cout << "Cart is Empty" << endl;
        }
        else
        {
            int i=0;
            while(ptr!=NULL)
            {
                cout<<"-------------------------------------------|--------------------|-------------------|-------------------|"<<endl;
                cout << i+1 <<". Product Name: " << ptr->pname<<" |"<<"Product ID: "<<ptr->prId<<"\t| Product Price: " << ptr->priceP<<"";
                cout<<" |Product quantity:"<<ptr->q<<"\t|"<<endl;
                ++i;
                ptr=ptr->next;
            }
            cout<<"-------------------------------------------|--------------------|-------------------|-------------------|"<<endl;
        }

    }
};
int Customercart::DeleteItem(int pidtodelete)
{
    int quantity;
    NodeOfCart *prev,*cur;
    prev=NULL;
    cur=start;
    //traverse up to desired location
    while(cur!=NULL && cur->prId<pidtodelete)
    {
        prev=cur;
        cur=cur->next;
    }
    if((cur==NULL)||(cur!=NULL && cur->prId!=pidtodelete))
    {
        cout<<"\n Product Id not found in cart";
        return(-1);
    }
    else
    {
        //cur is the node to delete
        quantity=cur->q;

        if(prev==NULL)
        {
            //cur is the start and we have to delete start
            start=cur->next;
            cur->next=NULL;
            delete(cur);
        }
        else
        {
            prev->next=cur->next;
            cur->next=NULL;
            delete(cur);
        }

        return(quantity);

    }

};

void Customercart::CalculateTotalPrice()
{
    if(start==NULL)
    {
        cout << "Shopping cart is Empty!" << endl;
    }
    else
    {
        int i=0,bill=0;

        NodeOfCart *ptr=start;
        cout << "\n ***BILLING***:" << endl;
        cout << "Items in Cart are: " << endl;
        while(ptr!=NULL)
        {
            bill+=(ptr->priceP*ptr->q);


            cout<<"|-------------------------------------------|--------------------|-------------------|-------------------|----------------|"<<endl;
            cout <<"|"<< i+1 <<". Product Name: " << ptr->pname<<" |"<<"Product ID: "<<ptr->prId<<"\t | Product Price: " << ptr->priceP<<"";
            cout<<" |Product quantity:"<<ptr->q<<" |"<<"Total cost:"<<(ptr->priceP*ptr->q)<<endl;

            i++;
            ptr=ptr->next;

        }
        cout<<"|-------------------------------------------|--------------------|-------------------|-------------------|----------------|"<<endl;
        cout<<"|---------------------------------|"<<endl;
        cout<<"|  Total Amount: "<<bill<<"              |"<<endl;
        cout<<"|---------------------------------|"<<endl;

        cout << "Mode of Payment: Pay on Delivery." << endl;

        time_t now = time(0);
        tm *ltm=localtime(&now);

        cout << "Your Order Will be Delivered to you by: " << ltm->tm_mday+7 << "/" << ltm->tm_mon+1 << endl;
    }


};
int main()
{
    int chf,loginas;
    Node obj;

    string pAdmin,correctPA;
    correctPA="123helloproject";
    llist s;
    Customercart cart;

    cList c;

    int choice,continueSameSection,chfinal;
    int indexOfItem,q,loginAgain;
    char ch,chA;
    int chDelete,quantityc,pIdtodelete;
    //admin adds the items available
    s.AddItems();
    //open outermost do
    do
    {
        cout<<"\n*********Welcome to Online Shopping System!**********";
        cout<<"\n 1.Login as an Admin";
        cout<<"\n 2.Login as a Customer";
        cout<<"\n 3.Exit";
        cout<<"\nEnter choice:";
        cin>>loginas;
        switch(loginas)
        {
        case 1:
            do
            {
                cout<<"\nEnter password to login as admin:";
                cin>>pAdmin;
                if(pAdmin==correctPA)
                {
                    cout<<"\nYou have logged in as Admin";
                    cout<<"***********Welcome to Online Shopping As Admin!***********\n";
                    cout<<"\nYou can add items to the list as Admin:";
                    s.AdminAdds();
                }
                else
                {
                    cout<<"\nDo you want to try again?(y/n)";
                    cin>>chA;
                }
            }
            while(chA);
            break;
        case 2:
            do
            {
                c.login();
                do
                    {

                        do
                        {

                            cout<<"***********Welcome to Online Shopping As a Customer!***********\n";
                            cout<<"\nSelect the category of goods that you want to purchase:";
                            cout<<"\n 1.Medicines";
                            cout<<"\n 2.Daily need items";
                            cout<<"\n 3.Grocery Items";
                            cout<<"\n 4.Clothing Items";
                            cout<<"\n 5.Electronic items";
                            cout<<"\n 6.Newly added items";
                            cout <<"\n\n***Enter your choice:****"<<endl;
                            cin>>choice;

                            switch(choice)
                            {
                            case 1:
                                s.display(1,10);
                                do
                                {
                                    cout<<"\nEnter the product Id of the item to buy it:";
                                    cin>>indexOfItem;
                                    if(indexOfItem>=1 && indexOfItem<=10)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout<<"\nInvalid choice try again!";
                                    }
                                    cout<<"\nDo you want to continue in the same section of goods? press 1 for yes:" << endl;
                                    cin>>continueSameSection;
                                }
                                while(continueSameSection==1);
                                break;
                            case 2:
                                s.display(11,20);
                                do
                                {
                                    cout<<"\nEnter the product Id of the item to buy it:";
                                    cin>>indexOfItem;
                                    if(indexOfItem>=11 && indexOfItem<=20)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout<<"\nInvalid choice try again!";
                                    }
                                    cout<<"\nDo you want to continue in the same section of goods? press 1 for yes:" << endl;
                                    cin>>continueSameSection;
                                }
                                while(continueSameSection==1);
                                break;

                            case 3:
                                s.display(21,36);
                                do
                                {
                                    cout<<"\nEnter the product Id of the item to buy it:";
                                    cin>>indexOfItem;
                                    if(indexOfItem>=21 && indexOfItem<=36)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout<<"\nInvalid choice try again!";
                                    }
                                    cout<<"\nDo you want to continue in the same section of goods? press 1 for yes:" << endl;
                                    cin>>continueSameSection;
                                }
                                while(continueSameSection==1);
                                break;

                            case 4:
                                s.display(37,45);
                                do
                                {
                                    cout<<"\nEnter the product Id of the item to buy it:";
                                    cin>>indexOfItem;
                                    if(indexOfItem>=37 && indexOfItem<=45)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout<<"\nInvalid choice try again!";
                                    }
                                    cout<<"\nDo you want to continue in the same section of goods? press 1 for yes:" << endl;
                                    cin>>continueSameSection;
                                }
                                while(continueSameSection==1);
                                break;

                            case 5:
                                s.display(46,56);
                                do
                                {
                                    cout<<"\nEnter the product Id of the item to buy it:";
                                    cin>>indexOfItem;
                                    if(indexOfItem>=46 && indexOfItem<=56)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout<<"\nInvalid choice try again!";
                                    }
                                    cout<<"\nDo you want to continue in the same section of goods? press 1 for yes:" << endl;
                                    cin>>continueSameSection;
                                }
                                while(continueSameSection==1);
                                break;

                            case 6:
                                s.display(57,60);
                                do
                                {
                                    cout<<"\nEnter the product Id of the item to buy it:";
                                    cin>>indexOfItem;
                                    if(indexOfItem>=57 && indexOfItem<=60)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                        cout<<"\nInvalid choice try again!";
                                    }
                                    cout<<"\nDo you want to continue in the same section of goods? press 1 for yes:" << endl;
                                    cin>>continueSameSection;
                                }
                                while(continueSameSection==1);
                                break;

                            default:
                                cout<<"\nInvalid choice";
                            }


                            cout<<"\nEnter Quantity: "<<endl;
                            cin>>q;
                            obj=s.decrementQt(indexOfItem,q);
                            if(obj.productId==1000)
                            {
                                cout<<"\nItem not found in list of goods for sale\n";
                            }
                            else if(obj.productId==500)
                            {
                                cout<<"\nSorry for the invconvenience!";
                            }
                            else
                            {
                                //int noOfqt,int price,int productId,string prdtname
                                cart.AddToCart(q,obj.price,obj.productId,obj.prdtname);
                                cart.displayCart();
                            }
                            cout<<"\nDo you want to continue adding items to cart? press y for yes:" << endl;
                            cin>>ch;
                        }
                        while(ch=='y'||ch=='Y');
                        //close second do inside if


                        cout<<"\nDo you want to delete any item from the cart?";
                        cout<<"\nPress 0 to delete any item from cart:"<<endl;
                        cin>>chDelete;
                        if(chDelete==0)
                        {
                            cout<<"\nEnter product Id to delete product: ";
                            cin>>pIdtodelete;
                            quantityc=cart.DeleteItem(pIdtodelete);
                            if(quantityc==-1)
                            {
                                cout<<"\nItem not found in cart!Cannot delete!";
                            }
                            else
                            {
                                cout<<"\nItem successfully deleted";
                                s.incrementQt(pIdtodelete,quantityc);
                            }
                        }

                        cout<<"\nDo you want to continue shopping?";
                        cout<<"\nPress 1 for yes:";
                        cin>>chf;
                    }
                    while(chf==1);   //close 1st do while inside if

                    c.displaydetails();
                    cart.CalculateTotalPrice();
                    cout<<"\nThank you for visiting!!";
                    break;
                cout<<"\nEnter 0 to exit and 1 to continue:";
                cin>>chfinal;
            }
            while(chfinal==1); //close do while of customer case 2 ie login as customer or admin
        case 3:
            cout<<"\nExit";
            break;
        default:
            cout<<"\nInvalid choice:";
            break;
        }//close switch
        cout<<"\nLogin again??:1 for yes";
        cin>>loginAgain;
    }
    while(loginAgain==1);
    //open outermost do
    return 0;
}


/*
******OUTPUT******:
*********Welcome to Online Shopping System!**********
1.Login as an Admin
2.Login as a Customer
3.Exit
Enter choice:1

Enter password to login as admin:123helloproject

You have logged in as admin
***********Welcome to Online Shopping As Admin!***********

You can add items to the list as Admin:
Enter product Name to add to the list:Nachos

Enter quantity of product to add to the list:20

Enter price of 1 quantity of product to add to the list:30
Nachos  57  20  30
Node added Successfully
Login again??:1 for yes1

*********Welcome to Online Shopping System!**********
1.Login as an Admin
2.Login as a Customer
3.Exit
Enter choice:2

Enter e-mail Id: abc@gmail.com

Enter password: abc123
Account doesn't exist
Please sign up!Please SignUp:

Enter your name: Riya

Enter your email id: riyagmailcom

Enter your password: riya123

Confirm your password: riya123

Enter your address: Pune
Please Enter Valid Email-Id! Try Signing in Again!
Please SignUp:

Enter your name: Riya

Enter your email id: riya@gmailcom

Enter your password: riya123

Confirm your password: riya123

Enter your address: Pune
Please Enter Valid Email-Id! Try Signing in Again!
Please SignUp:

Enter your name: Riya

Enter your email id: riyagmail.com

Enter your password: riya123

Confirm your password: riya123

Enter your address: Pune
Please Enter Valid Email-Id! Try Signing in Again!
Please SignUp:

Enter your name: Riya

Enter your email id: riya@gmail.com

Enter your password: riya123

Confirm your password: riya12

Enter your address: Pune
Passwords do not match. Try Signing in Again!
Please SignUp:

Enter your name: Riya

Enter your email id: riya.05@gmail.com

Enter your password: riya123

Confirm your password: riya123

Enter your address: Kothrud,Pune
Account Created Successfully!
Hello! Riya
***********Welcome to Online Shopping As a Customer!***********

Select the category of goods that you want to purchase:
1.Medicines
2.Daily need items
3.Grocery Items
4.Clothing Items
5.Electronic items

***Enter your choice:****
1
Items in List are:
|___________________|____________________________________________|________________________|
|Product Id:1       |Product Name:Crocin Tablet                  |Product Price:20        |
|___________________|____________________________________________|________________________|
|Product Id:2       |Product Name:Paracetamol Tablet             |Product Price:40        |
|___________________|____________________________________________|________________________|
|Product Id:3       |Product Name:Azithral 500 Tablet            |Product Price:50        |
|___________________|____________________________________________|________________________|
|Product Id:4       |Product Name:Dolo Tablet                    |Product Price:30        |
|___________________|____________________________________________|________________________|
|Product Id:5       |Product Name:Aspirin Tablet                 |Product Price:15        |
|___________________|____________________________________________|________________________|
|Product Id:6       |Product Name:Alex Syrup(100ml bottle)       |Product Price:100       |
|___________________|____________________________________________|________________________|
|Product Id:7       |Product Name:Azee(500mg) Tablet             |Product Price:25        |
|___________________|____________________________________________|________________________|
|Product Id:8       |Product Name:ALlegra-M Tablet               |Product Price:20        |
|___________________|____________________________________________|________________________|
|Product Id:9       |Product Name:Ascoril D Plus Syrup           |Product Price:100       |
|___________________|____________________________________________|________________________|
|Product Id:10      |Product Name:Azax 500 Tablet                |Product Price:23        |
|___________________|____________________________________________|________________________|

Enter the product Id of the item to buy it:11

Invalid choice try again!
Do you want to continue in the same section of goods? press 1 for yes:
1

Enter the product Id of the item to buy it:6

Enter Quantity:
1
Item added to cart!
Items in Cart are:
-------------------------------------------|--------------------|-------------------|-------------------|
1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1        |
-------------------------------------------|--------------------|-------------------|-------------------|

Do you want to continue adding items to cart? press y for yes:
y
***********Welcome to Online Shopping As a Customer!***********

Select the category of goods that you want to purchase:
1.Medicines
2.Daily need items
3.Grocery Items
4.Clothing Items
5.Electronic items

***Enter your choice:****
2
Items in List are:
|___________________|____________________________________________|________________________|
|Product Id:11      |Product Name:Rice (1 Kg)                    |Product Price:38        |
|___________________|____________________________________________|________________________|
|Product Id:12      |Product Name:Wheat flour(1 Kg)              |Product Price:50        |
|___________________|____________________________________________|________________________|
|Product Id:13      |Product Name:Moong Dal(1 Kg)                |Product Price:70        |
|___________________|____________________________________________|________________________|
|Product Id:14      |Product Name:Sugar(1 Kg)                    |Product Price:30        |
|___________________|____________________________________________|________________________|
|Product Id:15      |Product Name:Coffee                         |Product Price:20        |
|___________________|____________________________________________|________________________|
|Product Id:16      |Product Name:Peanut Oil(1 litre)            |Product Price:100       |
|___________________|____________________________________________|________________________|
|Product Id:17      |Product Name:Tomato Ketchup(1)              |Product Price:40        |
|___________________|____________________________________________|________________________|
|Product Id:18      |Product Name:Detergent (1 Kg)               |Product Price:50        |
|___________________|____________________________________________|________________________|
|Product Id:19      |Product Name:Room Freshener                 |Product Price:70        |
|___________________|____________________________________________|________________________|
|Product Id:20      |Product Name:floor Cleaner(1)               |Product Price:60        |
|___________________|____________________________________________|________________________|

Enter the product Id of the item to buy it:19

Enter Quantity:
2
Item added to cart!
Items in Cart are:
-------------------------------------------|--------------------|-------------------|-------------------|
1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1        |
-------------------------------------------|--------------------|-------------------|-------------------|
2. Product Name: Room Freshener            |Product ID: 19      | Product Price: 70 |Product quantity:2 |
-------------------------------------------|--------------------|-------------------|-------------------|

Do you want to continue adding items to cart? press y for yes:
y
***********Welcome to Online Shopping As a Customer!***********

Select the category of goods that you want to purchase:
1.Medicines
2.Daily need items
3.Grocery Items
4.Clothing Items
5.Electronic items

***Enter your choice:****
3
Items in List are:
|___________________|____________________________________________|________________________|
|Product Id:21      |Product Name:Onions(1 Kg)                   |Product Price:30        |
|___________________|____________________________________________|________________________|
|Product Id:22      |Product Name:Tomatoes(1 Kg)                 |Product Price:12        |
|___________________|____________________________________________|________________________|
|Product Id:23      |Product Name:Garlic(1 Kg)                   |Product Price:80        |
|___________________|____________________________________________|________________________|
|Product Id:24      |Product Name:Ginger(1 Kg)                   |Product Price:110       |
|___________________|____________________________________________|________________________|
|Product Id:25      |Product Name:Spinach (1 Bunch)              |Product Price:20        |
|___________________|____________________________________________|________________________|
|Product Id:26      |Product Name:Potato(1 Kg)                   |Product Price:35        |
|___________________|____________________________________________|________________________|
|Product Id:27      |Product Name:Double Beans(1 Kg)             |Product Price:55        |
|___________________|____________________________________________|________________________|
|Product Id:28      |Product Name:Coriander(1 Bunch)             |Product Price:20        |
|___________________|____________________________________________|________________________|
|Product Id:29      |Product Name:Sweet Lime(i Kg)               |Product Price:40        |
|___________________|____________________________________________|________________________|
|Product Id:30      |Product Name:Apple (1 Kg)                   |Product Price:90        |
|___________________|____________________________________________|________________________|
|Product Id:31      |Product Name:Banana (1 Kg)                  |Product Price:100       |
|___________________|____________________________________________|________________________|
|Product Id:32      |Product Name:Mango-Alphonso(1 Kg)           |Product Price:100       |
|___________________|____________________________________________|________________________|
|Product Id:33      |Product Name:Milk (1 Ltr)                   |Product Price:50        |
|___________________|____________________________________________|________________________|
|Product Id:34      |Product Name:Cheese (1 Packet)              |Product Price:70        |
|___________________|____________________________________________|________________________|
|Product Id:35      |Product Name:Yogurt (1)                     |Product Price:50        |
|___________________|____________________________________________|________________________|
|Product Id:36      |Product Name:Paneer(1 Pack)                 |Product Price:350       |
|___________________|____________________________________________|________________________|

Enter the product Id of the item to buy it:
34

Enter Quantity:
3
Item added to cart!
Items in Cart are:
-------------------------------------------|--------------------|-------------------|-------------------|
1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1        |
-------------------------------------------|--------------------|-------------------|-------------------|
2. Product Name: Room Freshener            |Product ID: 19      | Product Price: 70 |Product quantity:2 |
-------------------------------------------|--------------------|-------------------|-------------------|
3. Product Name: Cheese (1 Packet)         |Product ID: 34      | Product Price: 70 |Product quantity:3 |
-------------------------------------------|--------------------|-------------------|-------------------|

Do you want to continue adding items to cart? press y for yes:
y
***********Welcome to Online Shopping As a Customer!***********

Select the category of goods that you want to purchase:
1.Medicines
2.Daily need items
3.Grocery Items
4.Clothing Items
5.Electronic items

***Enter your choice:****
4
Items in List are:
|___________________|____________________________________________|________________________|
|Product Id:37      |Product Name:Polo T-shirt                   |Product Price:500       |
|___________________|____________________________________________|________________________|
|Product Id:38      |Product Name:Denim Jeans                    |Product Price:2000      |
|___________________|____________________________________________|________________________|
|Product Id:39      |Product Name:Anklets (1pair)                |Product Price:300       |
|___________________|____________________________________________|________________________|
|Product Id:40      |Product Name:Sunglasses                     |Product Price:3000      |
|___________________|____________________________________________|________________________|
|Product Id:41      |Product Name:Watch                          |Product Price:2500      |
|___________________|____________________________________________|________________________|
|Product Id:42      |Product Name:Wallet                         |Product Price:600       |
|___________________|____________________________________________|________________________|
|Product Id:43      |Product Name:Earrings(1pair)                |Product Price:200       |
|___________________|____________________________________________|________________________|
|Product Id:44      |Product Name:Shoes(1pair)                   |Product Price:3500      |
|___________________|____________________________________________|________________________|
|Product Id:45      |Product Name:Umbrella                       |Product Price:200       |
|___________________|____________________________________________|________________________|

Enter the product Id of the item to buy it:41

Enter Quantity:
1
Item added to cart!
Items in Cart are:
-------------------------------------------|--------------------|-------------------|-------------------|
1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1        |
-------------------------------------------|--------------------|-------------------|-------------------|
2. Product Name: Room Freshener            |Product ID: 19      | Product Price: 70 |Product quantity:2 |
-------------------------------------------|--------------------|-------------------|-------------------|
3. Product Name: Cheese (1 Packet)         |Product ID: 34      | Product Price: 70 |Product quantity:3 |
-------------------------------------------|--------------------|-------------------|-------------------|
4. Product Name: Watch                      |Product ID: 41     | Product Price: 2500 |Product quantity:1       |
-------------------------------------------|--------------------|-------------------|-------------------|

Do you want to continue adding items to cart? press y for yes:
y
***********Welcome to Online Shopping As a Customer!***********

Select the category of goods that you want to purchase:
1.Medicines
2.Daily need items
3.Grocery Items
4.Clothing Items
5.Electronic items

***Enter your choice:****
5
Items in List are:
|___________________|____________________________________________|________________________|
|Product Id:46      |Product Name:Headphones                     |Product Price:500       |
|___________________|____________________________________________|________________________|
|Product Id:47      |Product Name:Telivision                     |Product Price:20000     |
|___________________|____________________________________________|________________________|
|Product Id:48      |Product Name:Lenovo Laptop(Inspiron 14)     |Product Price:53000     |
|___________________|____________________________________________|________________________|
|Product Id:49      |Product Name:One plus Nord Blue Marble      |Product Price:29900     |
|___________________|____________________________________________|________________________|
|Product Id:50      |Product Name:Samsung Galaxy A51             |Product Price:19800     |
|___________________|____________________________________________|________________________|
|Product Id:51      |Product Name:Apple iPhone 11 Pro            |Product Price:78000     |
|___________________|____________________________________________|________________________|
|Product Id:52      |Product Name:HP laptop core i3              |Product Price:42000     |
|___________________|____________________________________________|________________________|
|Product Id:53      |Product Name:HP laptop core i5              |Product Price:54000     |
|___________________|____________________________________________|________________________|
|Product Id:54      |Product Name:Inspiron 14 Laptop Dell        |Product Price:58000     |
|___________________|____________________________________________|________________________|
|Product Id:55      |Product Name:One plus Nord Blue Marble      |Product Price:29900     |
|___________________|____________________________________________|________________________|
|Product Id:56      |Product Name:Ceiling fan                    |Product Price:5000      |
|___________________|____________________________________________|________________________|

Enter the product Id of the item to buy it:46

Enter Quantity:
2
Item added to cart!
Items in Cart are:
-------------------------------------------|--------------------|-------------------|-------------------|
1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1        |
-------------------------------------------|--------------------|-------------------|-------------------|
2. Product Name: Room Freshener            |Product ID: 19      | Product Price: 70 |Product quantity:2 |
-------------------------------------------|--------------------|-------------------|-------------------|
3. Product Name: Cheese (1 Packet)         |Product ID: 34      | Product Price: 70 |Product quantity:3 |
-------------------------------------------|--------------------|-------------------|-------------------|
4. Product Name: Watch                      |Product ID: 41     | Product Price: 2500 |Product quantity:1       |
-------------------------------------------|--------------------|-------------------|-------------------|
5. Product Name: Headphones                 |Product ID: 46     | Product Price: 500 |Product quantity:2        |
-------------------------------------------|--------------------|-------------------|-------------------|

Do you want to continue adding items to cart? press y for yes:
n

Do you want to delete any item from the cart?
Press 0 to delete any item from cart:
0

Enter product Id to delete product: 41

Item successfully deleted
Item qt incremented in menu list
Do you want to continue shopping?
Press 1 for yes:2

Details of Customer are:

Name: Riya
Email-Id: riya.05@gmail.com
Address: Kothrud,Pune

 ***BILLING***:
Items in Cart are:
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1 |Total cost:100
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|2. Product Name: Room Freshener            |Product ID: 19      | Product Price: 70 |Product quantity:2 |Total cost:140
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|3. Product Name: Cheese (1 Packet)         |Product ID: 34      | Product Price: 70 |Product quantity:3 |Total cost:210
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|4. Product Name: Headphones                 |Product ID: 46     | Product Price: 500 |Product quantity:2 |Total cost:1000
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|---------------------------------|
|  Total Amount: 1450              |
|---------------------------------|
Mode of Payment: Pay on Delivery.
Your Order Will be Delivered to you by: 20/5

Thank you for visiting!!
Exit
Login again??:1 for yes1

*********Welcome to Online Shopping System!**********
1.Login as an Admin
2.Login as a Customer
3.Exit
Enter choice:2

Enter e-mail Id: riya.05@gmail.com

Enter password: riya123

Welcome! Successfully logged in
Riya
***********Welcome to Online Shopping As a Customer!***********

Select the category of goods that you want to purchase:
1.Medicines
2.Daily need items
3.Grocery Items
4.Clothing Items
5.Electronic items

***Enter your choice:****
1
Items in List are:
|___________________|____________________________________________|________________________|
|Product Id:1       |Product Name:Crocin Tablet                  |Product Price:20        |
|___________________|____________________________________________|________________________|
|Product Id:2       |Product Name:Paracetamol Tablet             |Product Price:40        |
|___________________|____________________________________________|________________________|
|Product Id:3       |Product Name:Azithral 500 Tablet            |Product Price:50        |
|___________________|____________________________________________|________________________|
|Product Id:4       |Product Name:Dolo Tablet                    |Product Price:30        |
|___________________|____________________________________________|________________________|
|Product Id:5       |Product Name:Aspirin Tablet                 |Product Price:15        |
|___________________|____________________________________________|________________________|
|Product Id:6       |Product Name:Alex Syrup(100ml bottle)       |Product Price:100       |
|___________________|____________________________________________|________________________|
|Product Id:7       |Product Name:Azee(500mg) Tablet             |Product Price:25        |
|___________________|____________________________________________|________________________|
|Product Id:8       |Product Name:ALlegra-M Tablet               |Product Price:20        |
|___________________|____________________________________________|________________________|
|Product Id:9       |Product Name:Ascoril D Plus Syrup           |Product Price:100       |
|___________________|____________________________________________|________________________|
|Product Id:10      |Product Name:Azax 500 Tablet                |Product Price:23        |
|___________________|____________________________________________|________________________|

Enter the product Id of the item to buy it:4

Enter Quantity:
3
Item added to cart!
Items in Cart are:
-------------------------------------------|--------------------|-------------------|-------------------|
1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1        |
-------------------------------------------|--------------------|-------------------|-------------------|
2. Product Name: Room Freshener            |Product ID: 19      | Product Price: 70 |Product quantity:2 |
-------------------------------------------|--------------------|-------------------|-------------------|
3. Product Name: Cheese (1 Packet)         |Product ID: 34      | Product Price: 70 |Product quantity:3 |
-------------------------------------------|--------------------|-------------------|-------------------|
4. Product Name: Headphones                 |Product ID: 46     | Product Price: 500 |Product quantity:2        |
-------------------------------------------|--------------------|-------------------|-------------------|
5. Product Name: Dolo Tablet               |Product ID: 4       | Product Price: 30 |Product quantity:3 |
-------------------------------------------|--------------------|-------------------|-------------------|

Do you want to continue adding items to cart? press y for yes:
n

Do you want to delete any item from the cart?
Press 0 to delete any item from cart:
1

Do you want to continue shopping?
Press 1 for yes:2

Details of Customer are:

Name: Riya
Email-Id: riya.05@gmail.com
Address: Kothrud,Pune

 ***BILLING***:
Items in Cart are:
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|1. Product Name: Alex Syrup(100ml bottle)  |Product ID: 6       | Product Price: 100 |Product quantity:1 |Total cost:100
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|2. Product Name: Room Freshener            |Product ID: 19      | Product Price: 70 |Product quantity:2 |Total cost:140
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|3. Product Name: Cheese (1 Packet)         |Product ID: 34      | Product Price: 70 |Product quantity:3 |Total cost:210
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|4. Product Name: Headphones                 |Product ID: 46     | Product Price: 500 |Product quantity:2 |Total cost:1000
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|5. Product Name: Dolo Tablet               |Product ID: 4       | Product Price: 30 |Product quantity:3 |Total cost:90
|-------------------------------------------|--------------------|-------------------|-------------------|----------------|
|---------------------------------|
|  Total Amount: 1540              |
|---------------------------------|
Mode of Payment: Pay on Delivery.
Your Order Will be Delivered to you by: 20/5

Thank you for visiting!!
Exit
Login again??:1 for yes0

Process returned 0 (0x0)   execution time : 441.684 s
Press any key to continue.
*/
