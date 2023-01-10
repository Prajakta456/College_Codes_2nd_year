/***********************************************************************************************************
	Roll no:2330
	Name:Prajakta Deokule
	CNumber: C22019221332
	Assignment number:4

	A news paper delivery boy every day drops news paper in
	a society having many lanes and houses. Represent this
	as a graph using adjacency matrix or adjacency list.

	Perform Depth First traversal and Breadth First traversal.

	***USING ADJACENCY MATRIX AND ADJACENCY LIST*.

**************************************************************************************************************/
import java.util.*;
class SocietyMat
{
     int houses;       //number of vertices
     int lanes;        //number of edges
     int[][] adjMat;   //adjacency matrix of the graph
     
     SocietyMat()
     {
    	 houses = 0;
    	 lanes = 0;
     }
     
     //function to accept adjacency matrix
     void accept()
     {
    	 Scanner sc = new Scanner(System.in);
    	 int start=0;
    	 int end=0;
    	 
    	 System.out.println("Enter the number of houses in the society(vertices): ");
    	 houses = sc.nextInt();
    	 System.out.println("Enter the number of lanes in the society(edges): ");
    	 lanes = sc.nextInt();
    	 
    	 adjMat = new int[houses][houses];
    	 for(int i=0 ; i<houses ; i++)
    	 {
    		 for(int j=0 ; j<houses ; j++)
    			 adjMat[i][j]=0;
    	 }
    	 
    	 System.out.println("Enter the house numbers that a given lane connects: ");
    	 //the endpoints of the edges in the graph 
    	 for(int i=0 ; i<lanes ; i++)
    	 {
    		 System.out.println("Enter the endpoints of the lanes "+(i+1)+" : ");
    		 start = sc.nextInt();
    		 end = sc.nextInt();
    		 
    		 adjMat[start][end]=1;
    		 adjMat[end][start]=1;
    	 }
     }
     
     
     void display()
     {
    	 System.out.println("Displaying graph in the form of adjacency matrix : ");
    	 for(int i=0 ; i<houses ; i++)
    	 {
    		 for(int j=0 ; j<houses ; j++)
    		 {
    			 System.out.print("  "+adjMat[i][j]+"  ");
    		 }
    		 System.out.println();
    	 }
     }
     
     
     
     void bfs()    //breadth first traversal
     {
    	 Scanner sc=new Scanner(System.in);
    	 boolean[] visited = new boolean[houses];   //array to keep track of visited vertices
    	 
    	 for(int i = 0; i<houses ; i++)
    		 visited[i]=false;
    	 
    	 int[] traversal = new int[houses];     //to store order in which vertices are visited
    	 int t=0;
    	 
    	 Queue<Integer> q= new LinkedList<Integer>();	//declare queue data structure
    	 
    	 System.out.println("Enter the starting vertex for breadth first traversal : ");
    	 int startVertex = sc.nextInt();
    	 
    	 q.add(startVertex);                //enter starting vertex to queue before starting with looping
    	 visited[startVertex] = true;       
    	                                    //else vertices which are already in queue are yet seen as unvisited 
    	                                    // get added into the queue again by other vertices
    	 while(!q.isEmpty())
    	 {
    		 traversal[t] = q.remove();             //add dequeued element to array of visited vertices
  	 
    		 for(int i = 0; i<houses ; i++)
    		 {
    			 if((adjMat[traversal[t]][i]==1)&&(visited[i]==false))         //if vertex adjacent and unvisited
    			 {
    				 q.add(i);
    			     visited[i] = true;                                         //mark vertex visited immediately
    			 }
    		 }
    		 
    		 t = (t+1) ;                                    //to keep variable t within array limits
    	 }
    	 
    	 System.out.println("Breadth first traversal for house numbers is : ");
    	 for(int j=0 ; j<houses ; j++)
		 {
			 System.out.print("  "+traversal[j]+"  ");           //display traversal array
		 }
    	 System.out.println();
     }
   
     //depth first traversal
     void dfs()     
     {
    	 Scanner sc = new Scanner(System.in);
         boolean[] visited = new boolean[houses];               //array to keep track of visited vertices
    	 
    	 for(int i = 0; i<houses ; i++)
    		 visited[i]=false;
    	 
    	 int traversal[] = new int[houses];                      //to store order in which vertices are visited
    	 int t=0;
    	 
    	 System.out.println("Enter the starting vertex for breadth first traversal : ");
    	 int startVertex = sc.nextInt();
    	 
    	 Stack<Integer> s = new Stack<Integer>();           //stack for vertices
    	 
    	 s.push(startVertex);
    	 traversal[t]=startVertex;
    	 visited[startVertex] = true;                      //push starting vertex into stack and mark visited before starting looping
    	 t = (t+1) ;
    	 
    	 while(!s.isEmpty())
    	 {
    		 int top = s.peek();                 //to compare against stack top
    		 int next = -1 ;
    		 
    		 for(int i = 0; i<houses ; i++)
    		 {
    			 if((adjMat[top][i]==1)&&(visited[i]==false))         //if adjacent vertex unvisited found break out of for loop
    			 {
    				 next = i;
    				 break;
    			 }
    		 }
    		 
    		 if(next == -1)                                      //if no deeper vertex exists
    		 {
    			s.pop();
    		 }
    		 else
    		 {
    			 visited[next] = true;                               //add found vertex to stack and mark visited
    			 traversal[t] = next;
    			 t = (t+1) ;
    			 s.push(next);
    		 }
    	 }
    	 System.out.println("Depth first traversal for house numbers is : ");
    	 for(int j=0 ; j<houses ; j++)
		 {
			 System.out.print("  "+traversal[j]+"  ");
		 }
    	 System.out.println();
     }
}

class Vertex
{
	int vertex;
	Vertex link;
	
	Vertex(int n)
	{
		vertex = n;
		link = null;
	}
}

class AdjList
{
	int vertex ;
	Vertex head;
	
	AdjList(int n)
	{
		vertex = n;
		head = null;
	}
	
	void addEdge(int n)
	{
		Vertex v = new Vertex(n);
		if(head == null)
			head = v;
		else
	    {
			v.link = head;
		    head = v;
	    }
	}
}

class SocietyList
{
	 int v; //number of vertices
     int e; //number of edges
     AdjList[] list; //array of adjacency lists of the graph
     
     SocietyList()
     {
    	 v = 0;
    	 e = 0;
     }
     
     //function to accept adjacency list
     void accept()
     {
         Scanner sc=new Scanner(System.in);
    	 
    	 int start=0;
    	 int end=0;
    	 
    	 System.out.println("Enter number of houses in the society: ");
    	 v = sc.nextInt();
    	 System.out.println("Enter the number of lanes in the society: ");
    	 e = sc.nextInt();
    	 
    	 list = new AdjList[v];
    	 for(int j=0 ; j<v ; j++)
    		 list[j] = new AdjList(j);
    	 
    	 System.out.println("Enter the house numbers that a given lane connects: ");
    	 //the endpoints of the edges in the graph 
    	 for(int i=0 ; i<e ; i++)
    	 {
    		 System.out.println("Enter the endpoints of the edge "+(i+1)+" : ");
    		 start = sc.nextInt();
    		 end = sc.nextInt();
    		 
    		 list[start].addEdge(end);
    		 list[end].addEdge(start);
    	 }
     }
     
     //display adjacency list
     void display()
     {
    	 System.out.println("Displaying graph in the form of adjacency list : ");
    	 for(int i=0 ; i<v ; i++)
    	 {
    		 System.out.print( i );
    		 for( Vertex ptr = list[i].head ; ptr != null ; ptr = ptr.link)
    		 {
    			 System.out.print(" --> "+ ptr.vertex );
    		 }
    		 System.out.println();
    	 }
     }
  
  //breadth first traversal
     void bfsl()    
     {
    	 Scanner sc=new Scanner(System.in);
    	 boolean visited[] = new boolean[v];  
    	 
    	 for(int i = 0; i<v ; i++)
    		 visited[i]=false;
    	 
    	 int traversal[] = new int[v];     //to store order in which vertices are visited
    	 int t=0;
    	 
    	 Queue<Integer> q= new LinkedList<Integer>();	
    	 System.out.println("Enter the starting vertex for breadth first traversal : ");
    	 int startVertex = sc.nextInt();
    	 
    	 q.add(startVertex);                
    	 //enter starting vertex head node to queue before starting with looping
    	 visited[startVertex] = true;
    	 while(!q.isEmpty())
    	 {
    		 traversal[t] =  q.remove();         
    		 //add vertex number of dequeued node to array of visited vertices
    		 
    		 for( Vertex ptr = list[traversal[t]].head ; ptr != null ; ptr = ptr.link)
    		 {
    			 if((visited[ptr.vertex] == false))         
    			 {
    			     //if vertex adjacent and unvisited
    				 q.add(ptr.vertex);
    			     visited[ptr.vertex] = true;
    			 }
    		 }
    		 
    		 t = (t+1) ;                                    
    	 }
    	 
    	 System.out.println("Breadth first traversal for house numbers is : ");
    	 for(int j=0 ; j<v ; j++)
		 {
			 System.out.print("  "+traversal[j]+"  ");           
		 }
    	 System.out.println();
     }

}

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int choice;    
		SocietyMat smat = new SocietyMat();
		SocietyList slist = new SocietyList();
		
		do
		{
		System.out.println("****************************************************");
		System.out.println("MENU: ");
		System.out.println("1: Accept graph and store using adjacency matrix");
		System.out.println("2: Display graph in the form of adjacency matrix  ");
		System.out.println("3: Display breadth first traversal of graph in adjacency matrix  ");
		System.out.println("4: Display depth first traversal of graph in adjacency matrix ");
		System.out.println("5: Accept graph and store using adjacency list");
		System.out.println("6: Display graph in the form of adjacency list  ");
		System.out.println("7: Display breadth first traversal of graph in adjacency list  ");
		System.out.println("0: EXIT ");
		System.out.println("*****************************************************");
		
	    choice=sc.nextInt();
	    
	    
		switch(choice)  
		{
		case 1: smat.accept();    
		        break;
		
		case 2:smat.display();     
		        break;
		
		case 3:smat.bfs();       
        		break;
		
		case 4:smat.dfs();         
		        break;
		
		case 5:slist.accept();    
	        	break;
		
		case 6:slist.display();      
		        break;
		
		case 7:slist.bfsl();        
		        break;
		case 0:System.out.println("\nExited");
		
		}
		
		}while (choice==0); 
		
	}

}
/*TIME complexity
 adjacency matrix
 accept()   = O(E)
 display()  = O(V^2)
 dfs()      = O(V^2)
 bfs()      = O(V^2)



adjacency list
 void bfsl()       = O(V^2)
 void display()    = O(V^2)
 void accept()     = O(E)
*/
/*OUTPUT
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
1
Enter the number of houses in the society: 
6
Enter the number of lanes in the society: 
6
Enter the house numbers that a given lane connects: 
Enter the endpoints of the edge 1 : 
0
1
Enter the endpoints of the edge 2 : 
1
2
Enter the endpoints of the edge 3 : 
1
5
Enter the endpoints of the edge 4 : 
3
2
Enter the endpoints of the edge 5 : 
3
4
Enter the endpoints of the edge 6 : 
3
5


****************************************************
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
4
Enter the starting vertex for breadth first traversal : 
3
Depth first traversal for house numbers is : 
  3    2    1    0    5    4  


****************************************************
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
2
Displaying graph in the form of adjacency matrix : 
  0    1    0    0    0    0  
  1    0    1    0    0    1  
  0    1    0    1    0    0  
  0    0    1    0    1    1  
  0    0    0    1    0    0  
  0    1    0    1    0    0  



****************************************************
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
3
Enter the starting vertex for breadth first traversal : 
1
Breadth first traversal for house numbers is : 
  1    0    2    5    3    4  

****************************************************
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
5
Enter the number of houses in the society: 
6
Enter the number of lanes in the society: 
6
Enter the house numbers that a given lane connects: 
Enter the endpoints of the edge 1 : 
0
1
Enter the endpoints of the edge 2 : 
1
5
Enter the endpoints of the edge 3 : 
1
2
Enter the endpoints of the edge 4 : 
3
2
Enter the endpoints of the edge 5 : 
3
4
Enter the endpoints of the edge 6 : 
3
5

****************************************************
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
6
Displaying graph in the form of adjacency list : 
0 --> 1
1 --> 2 --> 5 --> 0
2 --> 3 --> 1
3 --> 5 --> 4 --> 2
4 --> 3
5 --> 3 --> 1


****************************************************
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
7
Enter the starting vertex for breadth first traversal : 
3
Breadth first traversal for house numbers is : 
  3    5    4    2    1    0  
  
  
******************************************************
MENU: 
1: Accept graph and store using adjacency matrix
2: Display graph in the form of adjacency matrix  
3: Display breadth first traversal of graph in adjacency matrix  
4: Display depth first traversal of graph in adjacency matrix 
5: Accept graph and store using adjacency list
6: Display graph in the form of adjacency list  
7: Display breadth first traversal of graph in adjacency list  
0: EXIT 
*****************************************************
0
Exited
 */










