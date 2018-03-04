#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
struct s1{
	int map = 0;
	char *rollno = NULL;
	char *name=NULL;
	int m1=0;
	int m2=0;
	int m3=0;
	int m4=0;
	float avg = 0;
	float cgpa = 0;
};
struct s2{
	int map = 0;
	char *rollno = NULL;
	char *phoneno = NULL;
	char *adress = NULL;
	char *city = NULL;
	char *pincode = NULL;
};
struct s3{
	char *name = NULL;
	int m1 = 0;
	int m2 = 0;
	int m3 = 0;
	int m4 = 0;
	float avg = 0;
	float cgpa = 0;
	char *rollno = NULL;
	char *phoneno = NULL;
	char *adress = NULL;
	char *city = NULL;
	char *pincode = NULL;
};
int is_in_string(char *s, char *d){
	int s_l = strlen(s);
	int d_l = strlen(d);
	if (s_l >= d_l){
		int i = 0,c=0;
		while (d[i] != '\0'){
			if (s[i] != d[i]){
				break;
			}
			i++;
		}
		if (i == d_l){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}
int find_list_length(char *filename){
	FILE *fptr;
	fptr = fopen(filename, "r");
	char ch = fgetc(fptr);
	if (ch == NULL){
		printf("file not found");
		exit(0);
	}
	int i = 0;
	while (ch != EOF)
	{
		if (ch == '\n'){
			i++;
		}
		ch = fgetc(fptr);
	}
	fclose(fptr);
	return i;
}
int charToint(char *ch){
	if (ch == NULL){
		return -1;
	}
	int res = 0;
	int i = 0, l = strlen(ch)-1;
	while (ch[i] != '\0'){
		res = res + ((ch[i] - 48)*(int)pow(10.0,l));
		i++;
		l--;
	}
	return res;
}
float getgrade(int marks){
	if (marks >= 90){
		return 4.0;
	}
	else if (marks >= 85){
		return 3.76;
	}
	else if (marks >= 80){
		return 3.5;
	}
	else if (marks >= 75){
		return 3.33;
	}
	else if (marks >= 70){
		return 3.0;
	}
	else if (marks >= 65){
		return 2.76;
	}
	else if (marks >= 60){
		return 2.5;
	}
	else{
		return 2.0;
	}
}

void find_avg_cgpa(struct s1 *list){
	int sum = 0;
	sum = list->m1 + list->m2 + list->m3 + list->m4;
	list->avg = sum / 4.0;
	float sum_g = getgrade(list->m1) * list->m1 + getgrade(list->m2) * list->m2 + getgrade(list->m3) * list->m3 + getgrade(list->m4) * list->m4;
	list->cgpa = sum_g / 400.0;
}

struct s1** read_s1(struct s1 **list1, char *filename,int *l){
	int list_length = find_list_length(filename);
	struct s1 **list = (struct s1 **)realloc(list1, sizeof(struct s1 *)*(list_length + (*l)));
	for (int i = (*l); i < (list_length + (*l)); i++){
		list[i] = new struct s1;
	}
	FILE *fptr;
	fptr = fopen(filename, "r");
	char ch = fgetc(fptr);
	if (ch == NULL){
		printf("file not found");
		exit(0);
	}
	int c = 0,r=0,l_p=(*l);
	while (ch != EOF){
		c = 0;
		while (ch != EOF&&ch != '\n'){
			char *d = new char[30];
			int d_p = 0;
			while (ch != EOF&&ch != ','){
				if (ch == '\n')
					break;
				d[d_p++] = ch;
				ch = fgetc(fptr);
			}
			d[d_p] = '\0';
			if (r != 0&&c == 0){
				list[l_p]->rollno = d;
				int t = charToint(d);
				list[t-1]->map = l_p;
			}
			else if (r != 0 && c == 1){
				list[l_p]->name = d;
			}
			else if (r != 0 && c == 2){
				list[l_p]->m1 =charToint(d);
			}
			else if (r != 0 && c == 3){
				list[l_p]->m2 = charToint(d);
			}
			else if (r != 0 && c == 4){
				list[l_p]->m3 = charToint(d);
			}
			else if (r != 0 && c == 5){
				list[l_p]->m4 = charToint(d);
			}
			c++;
			if (ch != '\n')
			ch = fgetc(fptr);
		}
		ch = fgetc(fptr);
		if (r != 0){
			find_avg_cgpa(list[l_p]);
			l_p++;
		}
		r++;
	}
	(*l) = l_p;
	fclose(fptr);
	return list;
}
struct s2** read_s2(struct s2 **list1, char *filename, int *l){
	int list_length = find_list_length(filename);
	struct s2 **list = (struct s2 **)realloc(list1, sizeof(struct s2 *)*(list_length + (*l)));
	for (int i = (*l); i < (list_length + (*l)); i++){
		list[i] = new struct s2;
	}
	FILE *fptr;
	fptr = fopen(filename, "r");
	char ch = fgetc(fptr);
	if (ch == NULL){
		printf("file not found");
		exit(0);
	}
	int c = 0, r = 0, l_p = (*l);
	while (ch != EOF){
		c = 0;
		while (ch != EOF&&ch != '\n'){
			char *d = new char[30];
			int d_p = 0;
			while (ch != EOF&&ch != ','){
				if (ch == '\n')
					break;
				d[d_p++] = ch;
				ch = fgetc(fptr);
			}
			d[d_p] = '\0';
			if (r != 0 && c == 0){
				list[l_p]->rollno = d;
			}
			else if (r != 0 && c == 1){
				list[l_p]->phoneno = d;
			}
			else if (r != 0 && c == 2){
				list[l_p]->adress = d;
			}
			else if (r != 0 && c == 3){
				list[l_p]->city = d;
			}
			else if (r != 0 && c == 4){
				list[l_p]->pincode = d;
			}
			c++;
			if (ch != '\n')
				ch = fgetc(fptr);
		}
		ch = fgetc(fptr);
		if (r != 0){
			l_p++;
		}
		r++;
	}
	(*l) = l_p;
	fclose(fptr);
	return list;
}
int get_pos(struct s1 **list,char *roll, int *l_l){
	//int rol = charToint(roll);
	int i,k=0;
	for (i = 0; i < (*l_l); i++){
		k = 0;
		while (roll[k]!='\0')
		{
			if (roll[k] != list[i]->rollno[k]){
				break;
			}
			k++;
		}
		if (k == strlen(roll)){
			return i;
		}
	}
	return -1;
}
struct s3 ** join(struct s1 **list1, struct s2 **list2, struct s3 **list3, int *s1_l, int *s2_l, int *s3_l){
	struct s3 **list = (struct s3 **)realloc(list3, sizeof(struct s3 *)*((*s1_l) + (*s3_l)));
	for (int i = (*s3_l); i < ((*s3_l) + (*s1_l)); i++){
		list[i] = new struct s3;
	}
	int k = (*s3_l);
	(*s3_l) = (*s3_l) + (*s1_l);
	int k_d = k;
	for (int i = 0; i < (*s1_l); i++){
		int rol = charToint(list2[i]->rollno);
		if (rol == -1){
			list[k]->rollno = list1[i]->rollno;
			list[k]->name = list1[i]->name;
			list[k]->m1 = list1[i]->m1;
			list[k]->m2 = list1[i]->m2;
			list[k]->m3 = list1[i]->m3;
			list[k]->m4 = list1[i]->m4;
			list[k]->avg = list1[i]->avg;
			list[k]->cgpa = list1[i]->cgpa;
			i++;
			continue;
		}
		int pos = list1[rol-1]->map;
		list[k]->rollno=list1[i]->rollno;
		list[k]->name = list1[pos]->name;
		list[k]->m1 = list1[pos]->m1;
		list[k]->m2 = list1[pos]->m2;
		list[k]->m3 = list1[pos]->m3;
		list[k]->m4 = list1[pos]->m4;
		list[k]->avg = list1[pos]->avg;
		list[k]->cgpa = list1[pos]->cgpa;
		list[k]->phoneno = list2[i]->phoneno;
		list[k]->adress = list2[i]->adress;
		list[k]->city = list2[i]->city;
		list[k]->pincode = list2[i]->pincode;
		k++;
	}
	return list;
}
void display_s1(struct s1 **list,int l_l){
	for (int i = 0; i < l_l; i++){
		printf("%s\t", list[i]->rollno);
		printf("%s\t", list[i]->name);
		printf("%d\t", list[i]->m1);
		printf("%d\t", list[i]->m2);
		printf("%d\t", list[i]->m3);
		printf("%d\t", list[i]->m4);
		printf("%f\t", list[i]->avg);
		printf("%f\n", list[i]->cgpa);
		
	}
}
void display_s2(struct s2 **list, int l_l){
	for (int i = 0; i < l_l; i++){
		printf("%s\t", list[i]->rollno);
		printf("%s\t", list[i]->phoneno);
		printf("%s\t", list[i]->adress);
		printf("%s\t", list[i]->city);
		printf("%s\n", list[i]->pincode);
	}
}
void display_s3(struct s3 **list, int l_l){
	for (int i = 0; i < l_l; i++){
		printf("%s\t", list[i]->rollno);
		printf("%s\t", list[i]->name);
		printf("%d\t", list[i]->m1);
		printf("%d\t", list[i]->m2);
		printf("%d\t", list[i]->m3);
		printf("%d\t", list[i]->m4);
		printf("%f\t", list[i]->avg);
		printf("%f\t", list[i]->cgpa);
		printf("%s\t", list[i]->phoneno);
		printf("%s\t", list[i]->adress);
		printf("%s\t", list[i]->city);
		printf("%s\n", list[i]->pincode);
	}
}
void create_file_s2(struct s2 **list, char *filename, int s2_l){
	FILE *fptr;
	fptr = fopen(filename, "w");
	char ch = fgetc(fptr);
	if (ch == NULL){
		printf("file not found");
		exit(0);
	}
	fprintf(fptr, "RollNo,PhoneNo,Address,City,PinCode\n");
	char *buf = new char[30];
	for (int i = 0; i < s2_l; i++){
		fprintf(fptr, list[i]->rollno);
		fprintf(fptr, ",");
		if (list[i]->phoneno == NULL)
			fprintf(fptr, "NULL");
		else
			fprintf(fptr, list[i]->phoneno);
		fprintf(fptr, ",");
		if (list[i]->adress == NULL)
			fprintf(fptr, "NULL");
		else
			fprintf(fptr, list[i]->adress);
		fprintf(fptr, ",");
		if (list[i]->city == NULL)
			fprintf(fptr, "NULL");
		else
			fprintf(fptr, list[i]->city);
		fprintf(fptr, ",");
		if (list[i]->pincode == NULL)
			fprintf(fptr, "NULL");
		else
			fprintf(fptr, list[i]->pincode);
		fprintf(fptr, "\n");
	}
	fclose(fptr);
}
void create_file_s1(struct s1 **list, char *filename, int s1_l){
	FILE *fptr;
	fptr = fopen(filename, "w");
	char ch = fgetc(fptr);
	if (ch == NULL){
		printf("file not found");
		exit(0);
	}
	fprintf(fptr, "RollNo,Name,M1,M2,M3,M4,Avg,CGPA\n");
	char *buf = new char[30];
	for (int i = 0; i < s1_l; i++){
		fprintf(fptr, list[i]->rollno);
		fprintf(fptr, ",");
		fprintf(fptr, list[i]->name);
		fprintf(fptr, ",");
		gcvt(list[i]->m1, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->m2, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->m3, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->m4, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->avg, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->cgpa, 6, buf);
		fprintf(fptr, buf);
		fprintf(fptr, "\n");
	}
	fclose(fptr);
}
void create_file_s3(struct s3 **list,char *filename,int s3_l){
	FILE *fptr;
	fptr = fopen(filename, "w");
	char ch = fgetc(fptr);
	if (ch == NULL){
		printf("file not found");
		exit(0);
	}
	fprintf(fptr,"RollNo,Name,M1,M2,M3,M4,Avg,CGPA,PhoneNo,Address,City,PinCode\n");
	char *buf = new char[30];
	for (int i = 0; i < s3_l; i++){
		fprintf(fptr, list[i]->rollno);
		fprintf(fptr, ",");
		fprintf(fptr, list[i]->name);
		fprintf(fptr, ",");
		gcvt(list[i]->m1, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf)+1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->m2, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->m3, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->m4, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->avg, 6, buf);
		buf[strlen(buf)] = ',';
		buf[strlen(buf) + 1] = '\0';
		fprintf(fptr, buf);
		gcvt(list[i]->cgpa, 6, buf);
		fprintf(fptr, buf);
		fprintf(fptr, ",");
		if (list[i]->phoneno == NULL)
			fprintf(fptr,"NULL");
		else
			fprintf(fptr, list[i]->phoneno);
		fprintf(fptr, ",");
		if (list[i]->adress == NULL)
			fprintf(fptr,"NULL");
		else
			fprintf(fptr, list[i]->adress);
		fprintf(fptr, ",");
		if (list[i]->city == NULL)
			fprintf(fptr,"NULL");
		else
			fprintf(fptr, list[i]->city);
		fprintf(fptr, ",");
		if (list[i]->pincode == NULL)
			fprintf(fptr,"NULL");
		else
			fprintf(fptr, list[i]->pincode);
		fprintf(fptr, "\n");
	}
	fclose(fptr);
}
void print_row(struct s3 *list,char *token){
	char display[10][30];
	int i, j, k;
	i = j = k = 0;
	while (token[k] != '\0'){
		j = 0;
		while (token[k] != '\0'&&token[k] != ',')
		{
			display[i][j++] = token[k++];
		}
		display[i][j] = '\0';
		i++;
		if (token[k] != '\0')
			k++;
	}
	display[i][0] = '\0';
	int r = 0;
	while (strcmp(display[r],"\0")!=0){
		if (strcmp(display[r], "rollno") == 0){
			printf("%s\t", list->rollno);
		}
		else if (strcmp(display[r], "name") == 0){
			printf("%s\t", list->name);
		}
		else if (strcmp(display[r], "m1") == 0){
			printf("%d\t", list->m1);
		}
		else if (strcmp(display[r], "m2") == 0){
			printf("%d\t", list->m2);
		}
		else if (strcmp(display[r], "m3") == 0){
			printf("%d\t", list->m3);
		}
		else if (strcmp(display[r], "m4") == 0){
			printf("%d\t", list->m4);
		}
		else if (strcmp(display[r], "avg") == 0){
			printf("%f\t", list->avg);
		}
		else if (strcmp(display[r], "cgpa") == 0){
			printf("%f\t", list->cgpa);
		}
		else if (strcmp(display[r], "phoneno") == 0){
			printf("%s\t", list->phoneno);
		}
		else if (strcmp(display[r], "address") == 0){
			printf("%s\t", list->adress);
		}
		else if (strcmp(display[r], "city") == 0){
			printf("%s\t", list->city);
		}
		else if (strcmp(display[r], "pincode") == 0){
			printf("%s\t", list->pincode);
		}
		else{
			printf("query error");
		}
		r++;
	}
	printf("\n");
}
void get_query(struct s3 **list,int s3_l,char *query){
	char token[15][60];
	int k = 0, i = 0, j = 0;

	while (query[k] != '\0'){
		j = 0;
		while (query[k] != '\0'&&query[k] != ' ')
		{
			token[i][j++] = query[k++];
		}
		token[i][j] = '\0';
		i++;
		if (query[k] != '\0')
		k++;
	}
	token[i][0] = '\0';
	//
	//
	if (strcmp(token[4], "\0") == 0){
		if ((strcmp(token[0], "select") == 0) && (strcmp(token[1], "*") == 0)){
			display_s3(list, s3_l);
		}
		else{
			for (int i = 0; i < s3_l; i++){
				print_row(list[i], token[1]);
			}
		}
	}
	
	//
	char op_list[][6] = { "m1", "m2", "m3", "m4", "avg", "cgpa" };
	char operater[][5] = { "GT", "LT", "GE", "LE","EQ"};
	char all[][10] = { "rollno", "name", "m1", "m2", "m3", "m4", "avg", "cgpa", "phoneno", "address", "city", "pincode" };
	int flag_1 = 0, flag_2 = 0,flag_3=0;
	for (int l = 0; l < 6; l++){
		if (strcmp(token[5], op_list[l]) == 0){
			flag_1 = 1;
		}
	}
	for (int l = 0; l < 4; l++){
		if (strcmp(token[6], operater[l]) == 0){
			flag_2 = 1;
		}
	}
	for (int l = 0; l < 12; l++){
		if (strcmp(token[5], all[l]) == 0){
			flag_3 = 1;
		}
	}
	//
	//
	if (flag_1 == 1 && flag_2 == 1){
		float val = atof(token[7]);
		if (strcmp(token[6], "GT") == 0){
			for (int l_p = 0; l_p < s3_l; l_p++){
				if (strcmp(token[5], "m1") == 0){
					if (list[l_p]->m1 > val){
						print_row(list[l_p],token[1]);
					}
				}
				else if (strcmp(token[5], "m2") == 0){
					if (list[l_p]->m2 > val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m3") == 0){
					if (list[l_p]->m3 > val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m4") == 0){
					if (list[l_p]->m4 > val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "avg") == 0){
					if (list[l_p]->avg > val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "cgpa") == 0){
					if (list[l_p]->cgpa > val){
						print_row(list[l_p], token[1]);
					}
				}
			}
		}
		else if (strcmp(token[6], "LT") == 0){
			for (int l_p = 0; l_p < s3_l; l_p++){
				if (strcmp(token[5], "m1") == 0){
					if (list[l_p]->m1 < val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m2") == 0){
					if (list[l_p]->m2 < val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m3") == 0){
					if (list[l_p]->m3 < val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m4") == 0){
					if (list[l_p]->m4 < val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "avg") == 0){
					if (list[l_p]->avg < val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "cgpa") == 0){
					if (list[l_p]->cgpa < val){
						print_row(list[l_p], token[1]);
					}
				}
			}
		}
		else if (strcmp(token[6], "GE") == 0){
			for (int l_p = 0; l_p < s3_l; l_p++){
				if (strcmp(token[5], "m1") == 0){
					if (list[l_p]->m1 >= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m2") == 0){
					if (list[l_p]->m2 >= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m3") == 0){
					if (list[l_p]->m3 >= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m4") == 0){
					if (list[l_p]->m4 >= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "avg") == 0){
					if (list[l_p]->avg >= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "cgpa") == 0){
					if (list[l_p]->cgpa >= val){
						print_row(list[l_p], token[1]);
					}
				}
			}
		}
		else if (strcmp(token[6], "LE") == 0){
			for (int l_p = 0; l_p < s3_l; l_p++){
				if (strcmp(token[5], "m1") == 0){
					if (list[l_p]->m1 <= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m2") == 0){
					if (list[l_p]->m2 <= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m3") == 0){
					if (list[l_p]->m3 <= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m4") == 0){
					if (list[l_p]->m4 <= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "avg") == 0){
					if (list[l_p]->avg <= val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "cgpa") == 0){
					if (list[l_p]->cgpa <= val){
						print_row(list[l_p], token[1]);
					}
				}
			}
		}
		else if (strcmp(token[6], "EQ") == 0){
			for (int l_p = 0; l_p < s3_l; l_p++){
				if (strcmp(token[5], "m1") == 0){
					if (list[l_p]->m1 == val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m2") == 0){
					if (list[l_p]->m2 == val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m3") == 0){
					if (list[l_p]->m3 == val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "m4") == 0){
					if (list[l_p]->m4 == val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "avg") == 0){
					if (list[l_p]->avg == val){
						print_row(list[l_p], token[1]);
					}
				}
				else if (strcmp(token[5], "cgpa") == 0){
					if (list[l_p]->cgpa == val){
						print_row(list[l_p], token[1]);
					}
				}
			}
		}
		else{
			printf("query error");
		}
	}
	if ((flag_3 == 1) && ((strcmp(token[6], "CONTAINS") == 0) || (strcmp(token[6], "MATCHES") == 0))){
		for (int l_p = 0; l_p < s3_l; l_p++){
			if (strcmp("name", token[5]) == 0){
				if (strcmp(list[l_p]->name, token[7])==0)
				print_row(list[l_p], token[1]);
				else if (is_in_string(list[l_p]->name, token[7]) == 1){
					print_row(list[l_p], token[1]);
				}
			}
			else if (strcmp("rollno", token[5]) == 0){
				if (strcmp(list[l_p]->rollno, token[7]) == 0)
					print_row(list[l_p], token[1]);
				else if (is_in_string(list[l_p]->rollno, token[7]) == 1){
					print_row(list[l_p], token[1]);
				}
			}
			else if (strcmp("address", token[5]) == 0){
				if (strcmp(list[l_p]->adress, token[7]) == 0)
					print_row(list[l_p], token[1]);
				else if (is_in_string(list[l_p]->adress, token[7]) == 1){
					print_row(list[l_p], token[1]);
				}
			}
			else if (strcmp("phoneno", token[5]) == 0){
				if (strcmp(list[l_p]->phoneno, token[7]) == 0)
					print_row(list[l_p], token[1]);
				else if (is_in_string(list[l_p]->phoneno, token[7]) == 1){
					print_row(list[l_p], token[1]);
				}
			}
			else if (strcmp("city", token[5]) == 0){
				if (strcmp(list[l_p]->city, token[7]) == 0)
					print_row(list[l_p], token[1]);
				else if (is_in_string(list[l_p]->city, token[7]) == 1){
					print_row(list[l_p], token[1]);
				}
			}
			else if (strcmp("pincode", token[5]) == 0){
				if (strcmp(list[l_p]->pincode, token[7]) == 0)
					print_row(list[l_p], token[1]);
				else if (is_in_string(list[l_p]->pincode, token[7]) == 1){
					print_row(list[l_p], token[1]);
				}
			}
		}
	}
}
//struct s3 * compute(struct s3 **list,char *lhs,char *op,char *rhs){
//	char op_list[][6] = { "m1", "m2", "m3", "m4", "avg", "cgpa" };
//	char operater[][5] = { "GT", "LT", "GE", "LE", "EQ" };
//	int flag_1 = 0, flag_2 = 0;
//	for (int l = 0; l < 6; l++){
//		if (strcmp(lhs, op) == 0){
//			flag_1 = 1;
//		}
//	}
//	for (int l = 0; l < 5; l++){
//		if (strcmp(op, operater[l]) == 0){
//			flag_1 = 1;
//		}
//	}
//	if (flag_1 == 1 && flag_2 == 1){
//
//	}
//}
int main(){
	int s1_l = 0,s2_l=0,s3_l=0;
	struct s1 **l1 = NULL;
	struct s2 **l2 = NULL;
	struct s3 **l3 = NULL;
	/*l1=read_s1((l1), "D:\\studentmarkslist.csv", &s1_l);
	l2 = read_s2((l2), "D:\\studentinfolist.csv", &s2_l);
	l3 = join(l1, l2, l3, &s1_l, &s2_l, &s3_l);
	display_s3(l3, s3_l);
	create_file(l3, "D:\\result.csv", s3_l);*/
	char *s = new char[100];
	char tokents[3][50];
	do{
		scanf("%[^\n]", s);
		int k = 0,i=0,j=0;
		
		while (s[k] != '\0'){
			j = 0;
			while (s[k] != '\0'&&s[k] != ' ')
			{
				tokents[i][j++] = s[k++];
			}
			tokents[i][j] = '\0';
			i++;
			if (s[k] != '\0')
			k++;
		}
		if (strcmp(tokents[0], "import") == 0){
			if (strcmp(tokents[2], "s1") == 0){
				l1 = read_s1(l1, tokents[1], &s1_l);
			}
			else if (strcmp(tokents[2], "s2") == 0){
				l2 = read_s2(l2, tokents[1], &s2_l);
			}
			else{
				printf("syntax error\n");
			}
		}
		else if (strcmp(tokents[0], "join") == 0){
			if (((strcmp(tokents[1], "s2") == 0) && (strcmp(tokents[2], "s1") == 0)) || ((strcmp(tokents[1], "s1") == 0) && (strcmp(tokents[2], "s2")==0))){
				l3 = join(l1,l2,l3,&s1_l,&s2_l,&s3_l);
			}
		}
		else if (strcmp(tokents[0], "flush")==0){
			if (strcmp(tokents[2], "s1")==0){
				create_file_s1(l1, tokents[1], s1_l);
			}
			else if (strcmp(tokents[2], "s2") == 0){
				create_file_s2(l2, tokents[1], s2_l);
			}
			else if (strcmp(tokents[2], "s3") == 0){
				create_file_s3(l3, tokents[1], s3_l);
			}
			
		}
		else if (strcmp(tokents[0], "select") == 0){
			get_query(l3,s3_l,s);
		}
		fflush(stdin);
		//compute(s);
	} while (strcmp(s, "exit")!=0);
	getchar();
	getchar();
	return(1);
}