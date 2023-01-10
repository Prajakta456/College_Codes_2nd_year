package FoodOrderSystem;
import java.util.*;
import java.lang.*;
import java.io.*;
public class Delivery 
{  
	static final int NO_PARENT = -1;
     static void dijkstra(int[][]adjacencyMatrix,int startVertex)
     {
       int nVertices = adjacencyMatrix[0].length;

       int[] shortestDistances = new int[nVertices];

    // added[i] will true if vertex i is included in shortest path tree or shortest distance from src to i is finalized
    boolean[] added = new boolean[nVertices];

    for (int vertexIndex = 0;vertexIndex < nVertices;vertexIndex++)
    {
        shortestDistances[vertexIndex] = Integer.MAX_VALUE;
        added[vertexIndex] = false;
    }
      
    shortestDistances[startVertex] = 0;

     int[] parents = new int[nVertices];

     parents[startVertex] = NO_PARENT;

    // Find shortest path for all  vertices
    for (int i = 1; i < nVertices; i++)
    {

        // Pick the minimum distance vertex from the set of vertices not yet processed. nearestVertex is always equal to startNode in first iteration.
        int nearestVertex = -1;
        int shortestDistance = Integer.MAX_VALUE;
        for (int vertexIndex = 0;
                 vertexIndex < nVertices; 
                 vertexIndex++)
        {
            if (!added[vertexIndex] &&
                shortestDistances[vertexIndex] < 
                shortestDistance) 
            {
                nearestVertex = vertexIndex;
                shortestDistance = shortestDistances[vertexIndex];
            }
        }

          added[nearestVertex] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int vertexIndex = 0;vertexIndex < nVertices;vertexIndex++) 
        {
            int edgeDistance = adjacencyMatrix[nearestVertex][vertexIndex];
              
            if (edgeDistance > 0
                && ((shortestDistance + edgeDistance) < 
                    shortestDistances[vertexIndex])) 
            {
                parents[vertexIndex] = nearestVertex;
                shortestDistances[vertexIndex] = shortestDistance + 
                                                   edgeDistance;
            }
        }
    }

    printSolution(startVertex, shortestDistances, parents);
}

// function to print the constructed distances array and shortest paths
 static void printSolution(int startVertex,int[] distances,int[] parents)
{
	Scanner sc=new Scanner(System.in);
    int nVertices = distances.length;
    
    int price;
    System.out.println("Enter the area you want to receive your delivery:(Enter index from above table)");
    int k= sc.nextInt();
    int vertexIndex=k;
    System.out.print("Vertex\t Distance\tPath");
        if (vertexIndex != startVertex) 
        {
            System.out.print("\n" + startVertex + " -> ");
            System.out.print(vertexIndex + " \t\t ");
            System.out.print(distances[vertexIndex] + "\t\t");
            printPath(vertexIndex, parents);
            
            price=distances[vertexIndex]*10;
            
            int time= 5*distances[vertexIndex];//5 mins per km
        	System.out.println("\nYour food items will be delivered in "+time+" minutes");
        	
        	
        }
    
}

// Function to print shortest path from source to currentVertex using parents array
static void printPath(int currentVertex,int[] parents)
{      
    // Base case : Source node has been processed
    if (currentVertex == NO_PARENT)
    {
        return;
    }
    printPath(parents[currentVertex], parents);
    System.out.print(currentVertex + " ");
}
}
	


