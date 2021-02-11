#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int loopPart1(char *search,int *count, int *cumulativeSum,FILE *fp);
int averageReview(FILE *fp);

// Method for first part
int averageReview(FILE *fp){

    // Read input from user. Assuming a word would not be longer than 30 characters.
    char word[30];
    printf("Enter a word: ");
    scanf("%s",word);
    
    // Adding whitespaces before and after the word, so that strstr() will return exact matches.
    char search[30];
    strcpy(search, " ");
    strcat(search, word);
    strcat(search, " ");

    int count=0;
    int cumulativeSum=0;

    loopPart1(search,&count,&cumulativeSum,fp);    
    
    // Just for aesthetics purposes, left trim the word to get rid of the whitespace we added.
    char *ltrim(char *s){
        while(isspace(*s)) s++;
        return s;
    }
    
    // Print commands
    printf("%sappears %d times.\n",ltrim(search),count);
    float average = (float)cumulativeSum / count;
    printf("The average score for reviews containing the word %sis %.4f\n",ltrim(search),average);
}

int loopPart1(char *search,int *count, int *cumulativeSum,FILE *fp){
    // Loop in text file.     
    while(1){
        int MAX = 9999;  // To be able to read every line, set character size to a high value.
        char str[MAX];
        if(fgets(str,MAX,fp) != NULL){
            
            // Turn strings into lowercase to become case insensitive.
            int i=0;
            while(str[i]!= '\0'){
               str[i] = tolower(str[i]);
               i++;           
            }
            
            // Search for the given word in string. If found increase the count and sum.
            if(strstr(str,search) != NULL){
              *count=*count+1;
              *cumulativeSum=*cumulativeSum + str[0]-'0';  // Convert char into int.
            }
        } else {
            break;  // Breaks from the while loop, when there isnt any line left.
        }
    }  
}

int main(){
    // Reading the file
    FILE *fp;
    fp = fopen("movieReviews.txt","r");
        
    averageReview(fp);  // Function for part 1
    
    // Below are for part 2
    FILE *fp2;
    fp2 = fopen("wordList.txt", "r");
           
    char *string[256];  // String array to store words.
    int i=0;    
    while(1){
        int MAX=9999;
        char str[MAX];               
        if(fgets(str,MAX,fp2) != NULL){
            char delimit[]=" \t\r\n\v\f\0";		
            char* word = str;
            word = strtok(word,delimit);    // Tokenize the str with given delimiters.
	        while(word != NULL){
	            string[i]=word;     // Add tokenized words to string array.
	            i++;
	            word = strtok(NULL,delimit);	            
            }       
        } else {
            break;
        }
    }
    
    int posRev[i];      // Array for positive reviews.
    int negRev[i];      // Array for negative reviews.
    
    // For each index(word), loop through all moviesReviews.txt. Count the number of reviews.
    int j=0;
    for(j; j<i;j++){
        char search[30];
        strcpy(search, " ");
        strcat(search, string[j]);
        strcat(search, " ");
        int posIns=0;
        int negIns=0;
        
        // Re-opening for each for loop.    
        fclose(fp); 
        FILE *fp;
        fp = fopen("movieReviews.txt","r");
        while(1){
            int MAX = 9999;  // To be able to read every line, set character size to a high value.
            char str[MAX];
            if(fgets(str,MAX,fp) != NULL){
                
                // Turn strings into lowercase to become case insensitive.
                int k=0;
                while(str[k]!= '\0'){
                   str[k] = tolower(str[k]);
                   k++;           
                }
                
                // Search for the given word in string. If found depending on its review score, increase the instance value of positive or negative reviews.
                if(strstr(str,search) != NULL){
                    // printf("%s\n",str);
                    if( (str[0]-'0') > 2){
                        posIns++;
                    } else {
                        negIns++;
                    }
                }
            } else {
                break;  // Breaks from the while loop, when there isnt any line left.
            }
        }
        
        // Updating the arrays.
        posRev[j]=posIns;  
        negRev[j]=negIns;
    }
    int maxPos=0;
    char *maxPosWord;
    int maxNeg=0;
    char *maxNegWord;
    
    // Find maxs
    int k=0;
    for(k;k<i;k++){
        if(posRev[k]>maxPos){
            maxPos=posRev[k];
            maxPosWord=string[k];
        }
        if(negRev[k]>maxNeg){
            maxNeg=negRev[k];
            maxNegWord=string[k];
        }
    }
    printf("The word %s with %d appearances has appeared in most number of positive reviews.\n", maxPosWord, maxPos);
    printf("The word %s with %d appearances has appeared in most number of negative reviews.\n", maxNegWord, maxNeg);
    
    fclose(fp);
    fclose(fp2);   
    return(0);
}
