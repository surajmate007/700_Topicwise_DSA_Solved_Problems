// Approach : Keep subtracting the divisor from the dividend until the dividend becomes less than the divisor. The dividend becomes the remainder,
// and the number of times subtraction is done becomes the quotient. Below is the implementation of the above approach : 

// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and
// return floor value of the result
int divide(int dividend, int divisor){

	// Calculate sign of divisor i.e.,
	// sign will be negative only if
	// either one of them is negative
	// otherwise it will be positive
	int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

	// Update both divisor and
	// dividend positive
	dividend = abs(dividend);
	divisor = abs(divisor);

	// Initialize the quotient
	int quotient = 0;
	while (dividend >= divisor) {
		dividend -= divisor;
		++quotient;
	}

	// Return the value of quotient with the appropriate
	// sign.
	return quotient * sign;
}

// Driver code
int main(){
	int a = 10, b = 3;
	cout << divide(a, b) << "\n";

	a = 43, b = -8;
	cout << divide(a, b);

	return 0;
}



// As every number can be represented in base 2(0 or 1), represent the quotient in binary form by using the shift operator as given below : 

// Determine the most significant bit in the divisor. This can easily be calculated by iterating on the bit position i from 31 to 1.
// Find the first bit for which divisor << i is less than dividend and keep updating the ith bit position for which it is true.
// Add the result in the temp variable for checking the next position such that (temp + (divisor << i) ) is less than the dividend.
// Return the final answer of the quotient after updating with a corresponding sign.


// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and
// return floor value it
int divide(long long dividend, long long divisor) {

    // Calculate sign of divisor i.e.,
    // sign will be negative only if
    // either one of them is negative
    // otherwise it will be positive
    int sign = ((dividend < 0) ^
                (divisor < 0)) ? -1 : 1;

    // remove sign of operands
    dividend = abs(dividend);
    divisor = abs(divisor);

    // Initialize the quotient
    long long quotient = 0, temp = 0;

    // test down from the highest bit and
    // accumulate the tentative value for
    // valid bit
    for (int i = 31; i >= 0; --i){

        if (temp + (divisor << i) <= dividend){
        temp += divisor << i;
        quotient |= 1LL << i;
        }
    }
    
    //if the sign value computed earlier is -1 then negate the value of quotient
    if(sign==-1) quotient=-quotient;

    return quotient;
}


// Driver code
int main() {
int a = 10, b = 3;
cout << divide(a, b) << "\n";

a = 43, b = -8;
cout << divide(a, b);

return 0;
}
