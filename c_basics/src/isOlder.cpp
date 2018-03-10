/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	int d1, d2, m1, m2, y1, y2;
	if (dob1[2] != '-'||dob2[2] != '-'||dob1[5] != '-'||dob2[5] != '-'){
		return -1;
	}
	d1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	d2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	y1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
	y2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');
	if ((m1 < 0 || m1 > 12) ||( m2 < 0 || m2 > 12)){
		return -1;
	}
	if ((d1 > 0 && d1 <= 31) || (d2 > 0 && d2 <= 31)){
		if (m1 == 2 || m2 == 2){
			if ((y1 % 400 == 0) || ((y1 % 4 == 0) && (y1 % 100 != 0))){
				if (d1 <= 29){
					
				}
				else{
					return -1;
				}
			}
			else{
				if (d1 < 29){
					
				}
				else{
					return -1;
				}
			}
			if ((y1 % 400 == 0) || ((y1 % 4 == 0) && (y1 % 100 != 0))){
				if (d2 <= 29){
					
				}
				else{
					return -1;
				}
			}
			else{
				if (d2 < 29){
					
				}
				else{
					return -1;
				}
			}
		}
	}
	else{
		return -1;
	}
	if (y1 < y2){
		return 1;
	}
	else if (y1 > y2){
		return 2;
	}
	else{
		if (m1 < m2){
			return 1;
		}
		else if (m1 > m2){
			return 2;
		}
		else{
			if (d1 < d2){
				return 1;
			}
			else if (d1 > d2){
				return 2;
			}
			else{
				return 0;
			}
		}
	}
}