#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recursive fib(). Since fibonacci #1 is 0, adjust the other values
// to fit the constraints
unsigned long long int rfib(unsigned long long int n) {
   if (n <= 1) {
      return 0;
   } else if (n == 2) {
      return 1;
   }

   // Using recursion, find fib(n)
   return rfib(n - 1) + rfib(n - 2);
}                                   

// Iterative fib(). Same as above, make sure fib(1) is 0. Then adjust
// the other values
unsigned long long int ifib(unsigned long long int n) { 
   if (n == 1) {
      return 0;
   } else if (n == 2) {
      return 1;                       
   }

   // Set the initial values for the iterative sequence
   unsigned long long int a = 0;
   unsigned long long int b = 1;
   unsigned long long int result = 0;                    

   // Update the result and variables for the next iteration
   for (int i = 3; i <= n; ++i) {
      result = a + b;
      a = b;
      b = result;
   }                                  

   // Return the result.
   return result;
}                                     

int main(int argc, char* argv[]) {
   // Create and store the cmd line integer into a variable
   unsigned long long int n;
   sscanf(argv[1], "%llu", &n);

   // Store the type of method
   char type = argv[2][0];            

   // If the type of method is iterative, call ifib(),
   // otherwise call rfib(). If the type is invalid,
   // set the result to 0.
   unsigned long long int number = 0;
   if (type == 'i') {
      number = ifib(n);
   } else if (type == 'r') {
      number = rfib(n);
   } else {
      number = 0;
   }

   // Print the result
   printf("%llu", number);

   return 0;
}