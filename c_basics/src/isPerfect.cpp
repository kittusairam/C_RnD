/*Problem - To find if given number is perfect or not

Description - A perfect number is a number which has the sum of its factors equal to the number itself.For each test case, you will be given two arrays, an input array consisting of numbers and output array of - 1's of the same length. For every index, if the number in the input array is perfect then set the corresponding number in output array to 1. If not, then set the corresponding number to 0.

Test Case 1:

	Input = [6, 4];
	Output = [-1, -1];
	length = 2;

	The factors of 6 are 1, 2, 3 whose sum equals 1 + 2 + 3 = 6. Hence 6 is perfect.
		The factors of 4 are 1, 2 whose sum equals 1 + 2 = 3. Hence 4 is not perfect.

		Hence output array must be[1, 0];

		DONT CHANGE THE FUNCTION HEADERS.
*/

#include<stdio.h>
bool IsPerfect(long long int n)
{
	// To store sum of divisors
	long long int sum = 1;

	// Find all divisors and add them
	for (long long int i = 2; i*i <= n; i++)
		if (n%i == 0)
			sum = sum + i + n / i;

	// If sum of divisors is equal to
	// n, then n is a perfect number
	if (sum == n && n != 1)
		return true;

	return false;
}
void isPerfect(long input[], int output[], int length)
{
	long rem, sum = 0, i,f;
	for (f = 0; f < length; f++){
		if (IsPerfect(input[f]))
			output[f] = 1;
		else
			output[f] = 0;
	}
}