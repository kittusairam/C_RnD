/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>


int isValidEmail(char *email)
{
	// variable email is in form of "name something@domain.server"
	int i = 0,flag=0;
	if (email[i] == '\0'){
		return 0;
	}
	if (email[i] != '\0'){
		int n;
		while (email[i] != ' '){
			i++;
			if (email[i] == '\0'){
				return 0;
			}
		}
		n = i;
		i++;
		int e = 0;
		if (email[i] == '_'){
			return 0;
		}
		while (email[i] == ' ')
			i++;
		while (email[i] != '@'){
			if (email[i] == ' ' || e>234 || email[i] == '>'){
				return 0;
			}
			int cek = 0;
			while ((email[i] == email[cek] || email[i] == (email[cek] - 32) || email[i] == email[cek] + 32) &&( email[i] != '@')){
				cek++;
				i++;
			}
			if ((cek == n)){
				if ((e == 0 || email[i] == '@')){
					flag = 1;
				}
			}
			if (email[i] != '@'&&cek==0)
			i++;
			if (email[i] == '\0'){
				return 0;
			}
			e++;
		}
		i++;
		while (email[i] != '.'){
			if ( email[i] == '_' || email[i] == '@'){
				return 0;
			}
			i++;
		}
		while (email[i] != '\0')
			i++;
		if (flag == 1){
			return 2;
		}
		else{
			return 1;
		}
	}
}