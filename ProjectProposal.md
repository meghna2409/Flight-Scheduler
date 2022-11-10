## Leading Question 

By utilizing the OpenFlights dataset, which has access to flight routes and airports dated from 2014, we hope to analyze common flight routes and the evolution of these routes in the past eight years. More specifically, our main objective is to use the information from the dataset to compute the distance and find the shortest path between two cities. To accomplish this, we will produce a general search tool using depth-first search and Dijkstra's algorithm, where one can input their departure and arrival location. The program will then return a highlighted route with the best possible path between the two nodes (airports) along with the total distance (weighted edge). 

## Dataset Acquisition

### Data Format

The OpenFlights dataset (https://openflights.org/data.html) has specific routes from one airport to the other (nodes) with weighted edges representing the distance connecting them. In this project, we plan to use two subsets of data: routes.dat and airports.dat. By employing the routes database, we can access these numerous routes, more precisely 67663 routes between 3321 airports on 548 airlines. Likewise, the database with airports will provide information on 14110 different airports, such as each airport name/ID and its location via latitude and longitude. We will extract this information from the two datasets and store them in new CSV files to implement in our program. 

### Data Correction

To validate that the input data remains error-free, we will treat invalid or unreadable data (such as  IDs that don't exist) as faulty and ignore it. To check the input, we need to ensure that the departure and arrival airports are valid and that each airport ID is unique so that no conflicts arise. We also need to check the range for the latitude (-90 to 90) and longitude (-180 to 180) and round the numbers accordingly. 

### Data Storage

We will use an Edge struct to store each route with a variable holding the distance between two airports. We will also use a Node struct to store each airport, with variables for the city the airport is in, the name of the airport, the airport ID, and the latitude/longitude. Using a directed graph, we will store the set of airports (V) and set of edges (E) as an adjacency matrix and adjacency list. Hence, our estimated space complexity for the directed graph would be V + E = O(V^2), and the total space complexity would equal O(V^2 + (V + E)) = O(V^2).

## Algorithm 

We will implement a depth-first search traversal algorithm, Dijkstra's algorithm, and PageRank algorithm in our program. 

First, we will build a directed graph that stores airports and the various routes connecting them. To visit the nodes (airports), we will utilize a DFS traversal, with the input being the directed graph in an adjacency list function object. There is no return value for this algorithm. The complexity for time would be O(V+E), and for memory, it would be O(d), where d represents the maximum number of nodes on a path. 

We will then use Dijkstra's algorithm to determine the distance between relative nodes by selecting a starting and ending point and using the latitude and longitude coordinates to calculate the distance between them. The inputs would be our starting node and the directed graph represented by an adjacency matrix or list. The algorithm returns a vector of vertices representing the shortest path between any two airports. The complexity for time would be O((|V| + |E|) log V), and for space, it would be O(|V| + |E|).

We also want to locate the most significant airports and map them using the PageRank method. The input is an adjacency list representing the directed graph, and the algorithm returns a vector where each value denotes the importance of each airport. The complexity for time would be O(k(V+E)), and for space, it would be O(V).

## Timeline

November 4th - Submit team contract, project proposal, and GitHub repository link. 

November 11th - Read and process necessary data, storing them in new CSV files. 

November 15th - Complete depth-first traversal algorithm. 

November 18th -  Complete Dijkstra's algorithm.

November 29th - Complete PageRank algorithm. 

December 2nd - Finish up test cases and final project report.

December 6th - Record and submit the final presentation.
