#include "mylibrary.h"
int sum_of_1_to_n(int n)
{
	int sum = 0;

	//TODO: sum all numbers from 1 to n
    for(int i=1;i<=n;i++){
    sum=sum+i;
}

	return sum;
}

int sum_of_even_numbers(int *array, int count)
{
	int sum = 0;
	for (int i=0;i<count;++i){
		//TODO: only add even numbers, e.g., 4. Skip odd numbers, e.g., 3
    if(array[i]%2==0){
      	sum += array[i];
    }
	
	}
	return sum;
}

int max_of_numbers(int *array, int count)
{
	//TODO: return the maximum number from the array
    int max=array[0];
    for(int i=1;i<count;i++){
        if(max<array[i]){
            max=array[i];        
        }
    }        
	return max;
}

int reversed_number(int number){
        
	    int reversed = 0;
        
        int temp=number;
        int digit=0;
        for( ; temp>0; digit++ ){
            temp = temp/10;
        }
        
        int reverseArray[digit];
        
        for(int i=0; i<digit; i++){
            reverseArray[i]=number%10;
            number= number/10;
        }
	    //TODO: if input is 12345, return 54321
    
        for(int i=0; i<digit; i++){
            reversed= reversed*10 + reverseArray[i];
        }

	    return reversed;
    }

int is_prime(int number){
        
	    //TODO: return 1 if the input number is prime, otherwise 0
        if(number==1){
            return 0;
        }else if (number==2){
            return 1;
        }else{
            for(int i=2; i<= number/2;i++){
                if(number%i ==0){
                    return 0;
                }
            }
            return 1;
        }
	    return 0;
    }

int count_primes(int start, int end){
        
	    //TODO: return the count of prime numbers in range [start, end] inclusive.
        int count=0;
        for (int i=start;i<=end;i++){
            if(is_prime(i)){
                count++;
            }
        }
	    return count;
}


char alphabet_index(int index)
{
	//TODO: for index 0, return A. index 1, B, etc. until 25 for Z.
	//if index is out of range, return space ' '.

    if(index<=25 && index>=0){
        return ('A'+index);
    } else return ' ';
}

