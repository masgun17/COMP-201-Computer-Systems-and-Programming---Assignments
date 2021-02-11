/* This is a code for COMP 201 assignment 3.
 * In this code, Floyd-Warshall algorithm is implemented
 * to find the shortest paths between any two cities
 * in a given graph of cities.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lookup_string(char str[30]);

const int INF = 1e7;  

/* Array of vertices. 
 * Each element of the str array contains a city name and 
 * its index in str becomes the city's numeric id.
 */
typedef struct vertices 
{
	// This attribute shows the size of dynamically allocated memory
	int size;
	// This attribute shows the number of cities in the array
	int city_count;
	// This attribute is the array of city names
	char (* str)[30];
} 
vertices;

/* Array of edges. 
 * Each element of the edge array contains the ids of two cities 
 * connected directy by a road and the length of the road.
 */
typedef struct edges 
{
	// This attribute shows the size of dynamically allocated memory
	int size;
	// This attribute shows the number of roads in the array
	int edge_count;
	// This attribute is the array of road information
	int (* edge)[3];
} 
edges;

vertices cities;

edges roads;

/* A two-dimensional array that shows 
 * the length of the shortest path connecting 
 * any two cities.
 */
int **city_graph;

/* A two-dimensional array that shows the direction 
 * to the shortest path between any two cities.
 */
int **shortest_paths;

/* A function that implements Floyd-Warshall algorithm. 
 * This algorithm finds the shortest path between 
 * any two vertices in a given graph.
 */
void floydWarshall()  
{  
	for (int k = 0; k < cities.city_count; k++) 
	{  
		for (int i = 0; i < cities.city_count; i++) 
		{  
			for (int j = 0; j < cities.city_count; j++) 
			{  

				// We cannot cross a road that doesn't exist  
				if ((city_graph[i][k] == INF) || (city_graph[k][j] == INF))  
				{
					continue;
				}  

				if (city_graph[i][j] > (city_graph[i][k] + city_graph[k][j])) 
				{  
					city_graph[i][j] = city_graph[i][k] + city_graph[k][j];  
					shortest_paths[i][j] = shortest_paths[i][k];  
				}  
			}  
		}  
	}  
} 

/* A function that initializes the values in 
 * city_graph and shortest_paths arrays.
 */
void initialise()  
{  
	for (int i = 0; i < cities.city_count; i++) 
	{  
		for (int j = 0; j < cities.city_count; j++) 
		{    

			// No edge between node i and j  
			if (city_graph[i][j] == INF)  
			{
				shortest_paths[i][j] = -1;
			}  
			else
			{
				shortest_paths[i][j] = j;
			}  
		}  
	}  
}

/* A function that inserts the name of a new city 
 * to the cities array.
 */
int insert_to_cities(char str[30]) 
{
	// Write your code here
	// Check if the city name already exists in the array 
	// If it does, return the array index of the city 
	
	if(lookup_string(str) != -1){
	    return lookup_string(str);
	}

	// If the city name doesn't exist, it is inserted to the cities array, and
	// return the array index of the city
	

	// If the dynamically allocated size of cities array is not large enough, 
	// the size of cities array is enlarged and the city name is inserted 
	// to the newly added region
	
	// If we passed the if statement above, then we will add the city to cities.
	// That is why we increase the city_count.
	// Then reallocating memory for the city name and copying the new city name.
	cities.city_count++;
	//cities.str= realloc(cities.str, cities.city_count * sizeof(char[30]));
	cities.str= realloc(cities.str, cities.city_count * sizeof(char)*30);
    strcpy(cities.str[cities.city_count-1], str);

	// Return the array index of the city.
	return cities.city_count-1;
}

/* A function that looks up if a city name
 * is already in the cities array. 
 */
int lookup_string(char str[30]) 
{
	for(int i = 0; i < cities.city_count; i++) {
		if(strncmp(str, cities.str[i], 30) == 0)
			return i;
	}
	printf("city %s is not found\n", str);
	return -1;
}

void printPath(int u, int v)  
{  
	// Write your code here  
	// Index1, Index2
    int a=u;   // Yaxchilan - 2
    int b=v;   // Castrovalva - 7  Path: 2 4 3 7
    int counter=1;
    while( a!=b){  // Loop for getting the size of the corresponding array
        int k = shortest_paths[a][b];
        a = k;
        counter++;
    }
    int *patharr = malloc(counter * sizeof(int));
    //int patharr[counter];
    int index = 0;
    a=u;
    b=v;
    patharr[index] = a;
    while( a!=b){  // Creating the path by indexes
        int k = shortest_paths[a][b];
        a = k;
        index++;
        patharr[index] = a;         
    }
    char *path = malloc(counter*sizeof(char)*30);
    strcpy(path, "");
    int totalCost=0;
    for(int i=0; i<counter; i++){   // Converting path to strings and calculate the length
        strcat(path, cities.str[patharr[i]]);
        strcat(path, " ");
        if( i + 1 != counter){
            totalCost += city_graph[patharr[i]][patharr[i+1]];
        }
    }
    
    if( !strcmp(path, "")){
        printf("*** NO PATH ***\n");
    } else {
    printf("Path: %s\n", path); 
    printf("Length: %d\n", totalCost);
    }
    
    free(patharr);	// Allocated memories are freed
    free(path);
} 

int main(int argc, char *argv[])
{
	// Write your code here

	// Allocate memory regions dynamically to cities array 
	// and roads array.

    vertices *p= malloc(sizeof(vertices));
    p->size=sizeof(vertices);
    p->city_count=0;
    //p->str= calloc(p->city_count , sizeof(char[30]));  // No need for calloc actually, so switched to malloc
    p->str= malloc(p->city_count * 30*sizeof(char));
    cities = *p;
    
    edges *e = malloc(sizeof(edges));
    e->size=sizeof(vertices);
    e->edge_count=0;
    //e->edge= calloc(e->edge_count, sizeof(int[3]));   // No need for calloc actually, so switched to malloc
    e->edge= malloc(e->edge_count * 3* sizeof(int));
    roads = *e;

	// Read and parse the input file. Insert the city names to cities array.
	// The index of the city name in the cities array becomes the city id. 
	// Insert city ids and road lengths to roads array.
	
	char *inputFile = argv[1];
	FILE *fp;
	fp = fopen(inputFile,"r");
	char **string = malloc(3*sizeof(char*));
	//char *string[3]; 
	int i=0;         
	while(1){  // Read the lines from the txt file       
	    int MAX = 1000;
	    char *str = malloc(MAX * sizeof(char));
	    //char str[MAX];  
	    if(fgets(str,MAX,fp) != NULL){
	        if(str[0] == '\n'){ // To skip last line
	            free(str);
	            break;
	        }
	        char *delimit = malloc(10 * sizeof(char));
	        strcpy(delimit, " \t\r\n\v\f\0");
	        //char delimit[]=" \t\r\n\v\f\0";		
            char *word = str;
            word = strtok(word,delimit);    // Tokenize the str with given delimiters.
            i = 0;
	        while(word != NULL){
	            string[i]=word;     // Add tokenized words to string array.
	            i++;
	            word = strtok(NULL,delimit);	            
            }         
            // Insert to cities  
	        int index1= insert_to_cities(string[0]);    // Insert to cities and record the indexes
	        int index2= insert_to_cities(string[1]);
	        // Insert to roads
	        roads.edge_count++;
	        roads.edge= realloc(roads.edge, roads.edge_count * sizeof(int[3]));
            roads.edge[roads.edge_count-1][0] = index1;
            roads.edge[roads.edge_count-1][1] = index2;
            roads.edge[roads.edge_count-1][2] = atoi(string[2]);
            free(delimit);
	       	   
	    } else {
	        free(str);
	        break;
	    }	    
	    free(str);	    	
	}	
	fclose(fp);
	free(string);

	// Allocate memory regions dynamically to city_graph, 
	// distance, and shortest_paths arrays.
	
	city_graph = (int **)malloc(cities.city_count * sizeof(int *)); 
    for (int i=0; i<cities.city_count; i++){
         city_graph[i] = (int *)malloc(cities.city_count * sizeof(int)); 
	}
	
	shortest_paths = (int **)malloc(cities.city_count * sizeof(int *));
	for (int i=0; i<cities.city_count; i++){
        shortest_paths[i] = (int *)malloc(cities.city_count * sizeof(int));
    }
	// Initialize the values in city_graph array with road lengths, 
	// such that the value in city_graph[i][j] is the road length 
	// between cities i and j if these cities are directly connected 
	// by a road 
	
	// First initialized all entries to INF
	for(int i=0; i<cities.city_count; i++){
	    for(int j=0; j<cities.city_count; j++){
	        city_graph[i][j] = INF;
	    }
	} // Then updated each i,j pair		
	for(int i=0; i<cities.city_count; i++){
	    for(int j=0; j<cities.city_count; j++){
	        if(i == j){ // Location A to A, clearly cost is 0
	            city_graph[i][j] = 0;
	        }else{
	            for(int k=0; k<roads.edge_count; k++){
	                if( (roads.edge[k][0] == i & roads.edge[k][1] == j)  |  (roads.edge[k][0] == j & roads.edge[k][1]  == i) ){
	                    city_graph[i][j] = roads.edge[k][2]; // Cost from A to B is equal to cost from B to A
	                }
	            }
	        }    
	    }
	}
		
	// For cities m and n that are not connected directly by a road, 
	// the value in city_graph[m][n] will be INF, 
    // which is a large value like 10M, 
	// that is assumed to be infinite. 
	
	 initialise();
	 floydWarshall();
	 while(1) {
		// prompt user to enter two city names
		// print the shortest path between the two cities
		// print the length of the path
		
		char *userinput = malloc(150 * sizeof(char));
		//char userinput[50];
        printf("Enter two city names, seperated by a whitespace (press -1 to exit): ");
        //scanf("%s",userinput);  // Looks like scanf only takes one string value, cannot record strings with whitespace
        fgets(userinput, 150, stdin);
        
        userinput[strcspn( userinput, "\n" )] = '\0'; // Getting rid of \n at the end of string
        
        if( !strcmp("-1", userinput)){  // Exit condition
            free(userinput);
            break;
        }
        char *delimit = malloc(sizeof(char));
        strcpy(delimit, " ");
        //char delimit[]=" ";		
        char *word = userinput;
        word = strtok(word,delimit);    // Tokenize the str with given delimiters.
        char **string2 = malloc(10 * sizeof(char*));
        //char *string2[10];            
        int i = 0;
        while(word != NULL){
            string2[i]=word;     // Add tokenized words to string array.
            i++;
            word = strtok(NULL,delimit);	            
        }
        free(delimit);
        if(i != 2) {
            printf("Please enter valid input.\n"); // If entered more than two words, prompt again.
            free(userinput);
            free(string2);
            continue;
        }     
        
        int cityIndex1=-1;  // Initial values, check later for wrong inputs
        int cityIndex2=-1;
        for(int i=0; i<cities.city_count; i++){ // Get corresponding indexes for given words
            if( !strcmp(cities.str[i], string2[0]) ){
                cityIndex1=i;
            }
            if( !strcmp(cities.str[i], string2[1]) ){
                cityIndex2=i;
            }       
        }
        free(string2);
        if( cityIndex1 == -1 | cityIndex2== -1){
            printf("City names you entered are not in the input file. Try again.\n");
            free(userinput);
            continue;
        }
        printPath(cityIndex1, cityIndex2);  // Print function, prints the path and calculates the total length.
		
		free(userinput);
	 }
	 	 
	 // Free the allocated memory
	 for(int i=0;i<cities.city_count;i++){
	    free(city_graph[i]);
	    free(shortest_paths[i]);
	 }
	 free(city_graph);
   	 free(shortest_paths);
   	 free(cities.str);
   	 free(roads.edge);
   	 free(p);
   	 free(e);
	 
	return 0;	
}
