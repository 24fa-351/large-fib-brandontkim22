#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive fib(). Since fibonacci #1 is 0, adjust the other values
// to fit the constraints
unsigned long long rfib(unsigned long long num) {
   if (num <= 1) {
      return 0;
   } else if (num == 2) {
      return 1;
   }

   return rfib(num - 1) + rfib(num - 2);
}                                   

// Iterative fib(). Same as above, make sure fib(1) is 0. Then adjust
// the other values
unsigned long long ifib(unsigned long long num) { 
   if (num <= 1) {
      return 0;
   } else if (num == 2) {
      return 1;                       
   }

   unsigned long long previous = 0;
   unsigned long long current = 1;
   unsigned long long result = 0;                    

   for (int ix = 3; ix <= num; ++ix) {
      result = previous + current;
      previous = current;
      current = result;
   }                                  

   return result;
}                                     

int main(int argc, char* argv[]) {
   unsigned long long n_input;
   sscanf(argv[1], "%llu", &n_input);

   char method_type = argv[2][0];

   unsigned long long result = 0;
   if (method_type == 'i') {
      result = ifib(n_input);
   } else if (method_type == 'r') {
      result = rfib(n_input);
   } else {
      result = 0;
   }

   printf("%llu", result);

   return 0;
}