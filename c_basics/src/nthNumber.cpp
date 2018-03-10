/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n <= 0){
		return -1;
	}
	n--;
	/* Declare an array to store Fibonacci numbers. */
	int *f=new int[n+1];
	int i;

	/* 0th and 1st number of the series are 0 and 1*/
	f[0] = 0;
	f[1] = 1;

	for (i = 2; i <= n; i++)
	{
		/* Add the previous 2 numbers in the series
		and store it */
		f[i] = f[i - 1] + f[i - 2];
	}

	return f[n];
}

int nthPrime(int num)
{
	if (num <= 0){
		return -1;
	}
	num + 1;
	int pk, qd, am, c = 0;
	for (pk = 2; pk <= 10000; pk++)
	{
		am = 0;
		for (qd = 2; qd <= pk / 2; qd++)
		{
			if (pk%qd == 0)
			{
				am = 1;
				break;
			}
		}
		if (am == 0)
			c++;
		if (c == num)
		{
			return pk;
		}
	}
	return -1;
}