#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) 
{
    // TODO: Complete this function
    int d;
if (exp1 > 600) { exp1 = 600; }
if (exp1 < 0) { exp1 = 0; }
if (exp2 > 600) { exp2 = 600; }
if (exp2 < 0) { exp2 = 0; }
if (e1 == 0)
{
    exp2 = exp2 + 29;
    if (exp2 > 600) { exp2 = 600; }
    if (exp2 < 0) { exp2 = 0; }
    d = e1 * 3 + exp1 * 7;
    if (d % 2 == 0)
    {
        exp1 = ceil(exp1 + d / 200);
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
    else
    {
        exp1 = ceil(exp1 - d / 100);
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
}
else if (e1 == 1)
{
    exp2 = exp2 + 45;
    if (exp2 > 600) { exp2 = 600; }
    if (exp2 < 0) { exp2 = 0; }
    d = e1 * 3 + exp1 * 7;
    if (d % 2 == 0)
    {
        exp1 = ceil(exp1 + d / 200);
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
    else
    {
        exp1 = ceil(exp1 - d / 100);
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
}
else if (e1 == 2)
{
    exp2 = exp2 + 75;
    if (exp2 > 600) { exp2 = 600; }
    if (exp2 < 0) { exp2 = 0; }
    d = e1 * 3 + exp1 * 7;
    if (d % 2 == 0)
    {
        exp1 = ceil(exp1 + d / 200);
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
    else
    {
         exp1 = ceil(exp1 - d / 100);
         if (exp1 > 600) { exp1 = 600; }
         if (exp1 < 0) { exp1 = 0; }
    }
}
else if (e1 == 3)
{
    exp2 = exp2 + 29 + 45 + 75;
    if (exp2 > 600) { exp2 = 600; }
    if (exp2 < 0) { exp2 = 0; }
    d = e1 * 3 + exp1 * 7;
    if (d % 2 == 0)
    {
        exp1 = ceil(exp1 + d / 200);
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
    else
    {
        exp1 = ceil(exp1 - d / 100);
        if (exp1 > 600) { exp1 = 600; }
        if (exp1 < 0) { exp1 = 0; }
    }
}
else if (e1 <= 19)
{
    exp2 = exp2 + ceil(e1 / 4.0 + 19);
    exp1 = exp1 - e1;
}
else if (e1 <= 49)
{
    exp2 = exp2 + ceil(e1 / 9.0 + 21);
    exp1 = exp1 - e1;
}
else if (e1 <= 65)
{
    exp2 = exp2 + ceil(e1 / 16.0 + 17);
    exp1 = exp1 - e1;
}
else if (e1 <= 79)
{
    exp2 = exp2 + ceil(e1 / 4.0 + 19);
    if (exp2 > 600) { exp2 = 600; }
    if (exp2 < 0) { exp2 = 0; }
    if (exp2 > 200){exp2 = exp2 + ceil(e1 / 9.0 + 21);}
    exp1 = exp1 - e1;
}
else
{
    exp2 = exp2 + ceil(e1 / 4.0 + 19 + e1 / 9.0 + 21);
    if (exp2 > 600) { exp2 = 600; }
    if (exp2 < 0) { exp2 = 0; }
    if (exp2 > 400)
    {
        exp2 = exp2 + ceil(e1 / 16.0 + 17);
        exp2 = exp2 * 1.15;
    }
    exp1 = exp1 - e1;
}
if (exp2 > 600) { exp2 = 600; }
if (exp2 < 0) { exp2 = 0; }
if (exp1 > 600) { exp1 = 600; }
if (exp1 < 0) { exp1 = 0; }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
        if (HP1 > 666) { HP1 = 666; }
    if (HP1 < 0) { HP1 = 0; }
    if (EXP1 > 600) { EXP1 = 600; }
    if (EXP1 < 0) { EXP1 = 0; }
    if (M1 > 3000) { M1 = 3000; }
    if (M1 < 0) { M1 = 0; }

    int A = M1 / 2.0;
    float p1, p2, p3;                                                              
    int s1, s2;
    s1 = round(sqrt(EXP1)) * round(sqrt(EXP1));
    if (EXP1 >= s1) { p1 = 100; }
    else { p1 = 100 * (static_cast<float>(EXP1) / static_cast<float>(s1) + 80) / 123.0; }

    int i;
    if (E2 % 2 == 0) { i = 1; }                                              
    else { i = 50; }
    for (int j = 1; j <= i; j++)
    {
        if (HP1 < 200)                                                     
        {
            HP1 = ceil(HP1 * 1.3);
            if (HP1 > 666) { HP1 = 666; }
            if (HP1 < 0) { HP1 = 0; }
            M1 = M1 - 150;
        }
        else
        {
            HP1 = ceil(HP1 * 1.1);
            if (HP1 > 666) { HP1 = 666; }
            if (HP1 < 0) { HP1 = 0; }
            M1 = M1 - 70;
        }
        if (E2 % 2 == 1)
        {
            if (M1 < A)
            {
                if (M1 > 3000) { M1 = 3000; }
                if (M1 < 0) { M1 = 0; }
                goto capnhat;
            }
        }
        else if (M1 <= 0)
        {
            if (M1 > 3000) { M1 = 3000; }
            if (M1 < 0) { M1 = 0; }
            goto capnhat;
        }
        if (EXP1 < 400)                                                 
        {
            M1 = M1 - 200;
        }
        else
        {
            M1 = M1 - 120;
        }
        EXP1 = ceil(EXP1 * 1.13);
        if (EXP1 > 600) { EXP1 = 600; }
        if (EXP1 < 0) { EXP1 = 0; }
        if (E2 % 2 == 1)
        {
            if (M1 < A)
            {
                if (M1 > 3000) { M1 = 3000; }
                if (M1 < 0) { M1 = 0; }
                goto capnhat;
            }
        }
        else if (M1 <= 0)
        {
            if (M1 > 3000) { M1 = 3000; }
            if (M1 < 0) { M1 = 0; }
            goto capnhat;
        }

        if (EXP1 < 300)             
        {
            M1 = M1 - 100;
        }
        else
        {
            M1 = M1 - 120;
        }
        EXP1 = ceil(EXP1 * 0.9);
        if (EXP1 > 600) { EXP1 = 600; }
        if (EXP1 < 0) { EXP1 = 0; }
        if (E2 % 2 == 1)
        {
            if (M1 < A)
            {
                if (M1 > 3000) { M1 = 3000; }
                if (M1 < 0) { M1 = 0; }
                goto capnhat;
            }
            else if (M1 <= 0)
            {
                goto capnhat;
                if (M1 > 3000) { M1 = 3000; }
                if (M1 < 0) { M1 = 0; }
            }
        }
    }
capnhat:                                                 
    HP1 = ceil(HP1 * 0.83);
    EXP1 = ceil(EXP1 * 1.17);
    if (HP1 > 666) { HP1 = 666; }
    if (HP1 < 0) { HP1 = 0; }
    if (EXP1 > 600) { EXP1 = 600; }
    if (EXP1 < 0) { EXP1 = 0; }
    s2 = round(sqrt(EXP1)) * round(sqrt(EXP1));
    if (EXP1 >= s2) { p2 = 100; }
    else { p2 = 100 * ((static_cast<float>(EXP1) / static_cast<float>(s2)) + 80) / 123.0; }

    int dv;                                                       
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 % 10 == 0) { p3 = P[E2]; }
    else
    {
        dv = ((E2 % 10) + (E2 / 10)) % 10;
        p3 = P[dv];
    }
    float p;
    if ((p1 == 100) && (p2 == 100) && (p3 == 100))
    {
        EXP1 = ceil(EXP1 * 0.75);
        if (EXP1 > 600) { EXP1 = 600; }
        if (EXP1 < 0) { EXP1 = 0; }
    }
    else
    {
        p = (p1 + p2 + p3) / 3.0;
        if (p < 50)
        {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
            if (HP1 > 666) { HP1 = 666; }
            if (HP1 < 0) { HP1 = 0; }
            if (EXP1 > 600) { EXP1 = 600; }
            if (EXP1 < 0) { EXP1 = 0; }
            if (M1 > 3000) { M1 = 3000; }
            if (M1 < 0) { M1 = 0; }
        }
        else
        {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
            if (HP1 > 666) { HP1 = 666; }
            if (HP1 < 0) { HP1 = 0; }
            if (EXP1 > 600) { EXP1 = 600; }
            if (EXP1 < 0) { EXP1 = 0; }
            if (M1 > 3000) { M1 = 3000; }
            if (M1 < 0) { M1 = 0; }
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function;
	if (EXP1 > 600) { EXP1 = 600; }
	if (EXP2 > 600) { EXP2 = 600; }
	if (HP1 > 666) { HP1 = 666; }
	if (HP2 > 666) { HP2 = 666; }
	if (EXP1 < 0) { EXP1 = 0; }
	if (EXP2 < 0) { EXP2 = 0; }
	if (HP1 < 0) { HP1 = 0; }
	if (HP2 < 0) { HP2 = 0; }
	int count1 = 0, count2 = 0, pt = 0;
	int B[10][10];
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			B[i][j] = ((E3 * j) + (i * 2)) * (i - j);
			if (B[i][j] > (E3 * 2)) { count1 = count1 + 1; }
			if (B[i][j] < (E3 * (-1))) { count2 = count2 + 1; }
		}
	}
	while (count1 >= 10)
	{
		count1 = count1 % 10 + count1 / 10;
	}
	while (count2 >= 10)
	{
		count2 = count2 % 10 + count2 / 10;
	}
	int taxi = B[count1][count2];
	int max=B[count1][count2];
	int S=count1+count2, M=abs(count1-count2);
	for (int i=count1;((i>=0)&&(i<=9));i++)
	{
		if (max < B[i][S - i]) { max = B[i][S - i]; }
	}
	for (int i = count1; ((i >= 0) && (i <= 9) && (S - i >= 0) && (S - i <= 9)); i--)
	{
		if (max < B[i][S - i]) { max = B[i][S - i]; } 
	}
	for (int i = count1; ((i >= 0) && (i <= 9) && (M + i >= 0) && (M + i <= 9)); i++)
	{
		if (max < B[i][M + i]) { max = B[i][M + i]; }
	}
	for (int i = count1; ((i >= 0) && (i <= 9) && (M + i >= 0) && (M + i <= 9)); i--)
	{
		if (max < B[i][M + i]) { max = B[i][M + i]; } 
	}
	if (abs(taxi) > max)
	{
		EXP1 = round(EXP1 * 0.88);
		HP1 = round(HP1 * 0.9);
		EXP2 = round(EXP2 * 0.88);
		HP2 = round(HP2 * 0.9);
		return taxi;
	}
	else
	{
		EXP1 = round(EXP1 * 1.12);
		HP1 = round(HP1 * 1.1);
		EXP2 = round(EXP2 * 1.12);
		HP2 = round(HP2 * 1.1);
		if (EXP1 > 600) { EXP1 = 600; }
		if (EXP2 > 600) { EXP2 = 600; }
		if (HP1 > 666) { HP1 = 666; }
		if (HP2 > 666) { HP2 = 666; }
		if (EXP1 < 0) { EXP1 = 0; }
		if (EXP2 < 0) { EXP2 = 0; }
		if (HP1 < 0) { HP1 = 0; }
		if (HP2 < 0) { HP2 = 0; }
		return max;
	}
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
int lenEmail = strlen(email);
    int lenSe = lenEmail - 10;
    char se[lenSe];
    se[lenSe]='\0';
    for(int i = 0; i < lenSe; i++){
        se[i] = email[i];
    }
    int lenS = strlen(s);
    if(lenS < 8) return -1;

    if(lenS > 20) return -2;
    
    for(int i = 0; i < lenS; i++){
        if(!isalpha(s[i])&&(s[i]!='0'&&s[i] !='1'&& s[i] !='2' && s[i] != '3'&&s[i]!='4'&&s[i] != '5'&&s[i] !='6' &&s[i] !='7' && s[i]!='8' &&s[i] != '9' ) &&(s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')) {
            return i;
        }
    }
    
const char* found = strstr(s, se);
    if (found != nullptr) {
        return -(300 + (found - s));
    }

    int len2 = 1;
    char c = s[0];
    int check = 0;
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] == c) {
            len2++;
            if(len2 > 2) {
                return -(400 + check);   
            }
        }
        else {
            c = s[i];
            check = i;
            len2 = 1;
        }
    }

    int cnt = 0;
    for(int i = 0; i < lenS; i++) {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            cnt++;
        }
    }
    if(cnt == 0) return -5;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

int vt[num_pwds];
for (int i = 0; i <= num_pwds - 1; i++)
{
	vt[i] = 0;
}
for (int i = 0; i <= num_pwds; i++)
{
	if (vt[i] == 1)
	{
		continue;
	}
	for (int j = i; j <= num_pwds; j++)
	{
		if (arr_pwds[i] == arr_pwds[j])
		{
			vt[i]++;
			vt[j] = 1;
		}
	}
}
int max = vt[0];
int maxsize = 0;
int ans;
for (int i = 0; i <= num_pwds; i++)
{
	if (max <= vt[i]) { max = vt[i]; }
}
for (int i = 0; i <= num_pwds; i++)
{
	if (max == vt[i])
	{
		if (strlen(arr_pwds[i]) > maxsize)
		{
			maxsize = strlen(arr_pwds[i]);
			ans = i;
		}
	}
}
return ans;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////