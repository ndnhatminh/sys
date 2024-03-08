#include "study_in_pink1.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
        cout << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1.1

bool oddEven(int c) //kiem tra tinh chan le
{
    return (c % 2 == 0);
}

int nearestSquare(int d) //tim perfect square
{
    float s;
    s = round(sqrt(d));
    return s*s;
}

void hpScaleF(float & HP1)
{
    if(HP1 > 666)
        HP1 = 666;
    if(HP1 < 0)
        HP1 = 0;

    HP1 = ceil(HP1); 
}

void expScaleF(float & EXP1)
{
    if(EXP1 > 600)
        EXP1 = 600;
    if(EXP1 < 0)
        EXP1 = 0;

    EXP1 = ceil(EXP1);
}

void mScaleF(float & M1)
{
    if(M1 > 3000)
        M1 = 3000;
    if(M1 < 0)
        M1 = 0;

    M1 = ceil(M1);
}

void roads(float & HP1, float & EXP1, int & M1, bool sochan, int money) //di qua 3 duong
{
    if(HP1 < 200) //mua do
    {
        HP1 *= 1.3;
        M1 -= 150;
    }
    else
    {
        HP1 *= 1.1;
        M1 -= 70;
    }
    hpScaleF(HP1);

    if (sochan == true && M1 <= 0) 
        return;
    if (sochan == false && M1 <= money)
        return;

    if(EXP1 < 400) //di chuyen
        M1 -= 200;
    else
        M1 -= 120;

    EXP1 *= 1.13;
    expScaleF(EXP1);

    if (sochan == true && M1 <= 0) 
        return;
    if (sochan == false && M1 <= money)
        return;

    if(EXP1 < 300) //vo gia cu
        M1 -= 100;
    else
        M1 -= 120;

    EXP1 *= 0.9;
    expScaleF(EXP1);
}

int findi(int E2)
{
    if(E2 >= 0 && E2 <= 9)
        return E2;
    if(E2 >= 10)
    {
        int sum;
        sum = E2%10 + E2/10;
        if(sum >=0 && sum <= 9)
            return sum;
        else
            return sum%10;
    }
    return 0;
}

int clamp(int value, int min, int max)
{
    if (value > max)
        value = max;
    if (value < min)
        value = min;
    return value;
}

void printMatrix(int matrix[10][10])
{
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout << setw(6) << matrix[i][j];
        }
        cout << endl;
    }
}

int getSherlockPoint(int diem_gap_i, int diem_gap_j, int matrix_taxi[10][10])
{
    int i1 = clamp(diem_gap_i - 9 + diem_gap_j, 0, 9), j1 = clamp(diem_gap_i + diem_gap_j, 0, 9);
    int maxl = j1;
    while (true)
    {
        if (matrix_taxi[i1][j1] > maxl)
        {
            maxl = matrix_taxi[i1][j1];
        }
        i1++;
        j1--;
        if (i1 > 9 or j1 < 0)
        {
            break;
        }
    }

    int i2 = clamp(diem_gap_i + 9 - diem_gap_j, 0, 9);
    int j2 = clamp(diem_gap_i + 9 - diem_gap_j, 0, 9);
    while (true)
    {
        if (matrix_taxi[i2][j2] > maxl)
        {
            maxl = matrix_taxi[i2][j2];
        }
        i2++;
        j2++;
        if (i2 > 9 or j2 < 0)
        {
            break;
        }
    }

    return maxl;
}

// Task 1.2
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    float exp2_float = exp2; //goi bien tam luu tru dau phay

    if(e1 >= 0 && e1 <= 3) //lua chon su kien 1
    {
        switch(e1)
        {
            case 0:
                exp2_float += 29;
                break;
            case 1:
                exp2_float += 45;
                break;
            case 2:
                exp2_float += 75;
                break;
            case 3:
                exp2_float += 149;
                break;
        }
    //ket luan
    int d = e1 * 3 + exp1 * 7;
    int ch= d/200;
    int le= d/100;
    if(oddEven(d)) 
        exp1 += ch;
    else
        exp1 -= le;
    expScaleF(exp2_float);
    }

    if(e1 >= 4 && e1 <= 99) //lua chon su kien 2
    {
        if(e1 >= 4 && e1 <= 19)
            exp2_float += e1 / 4.0f + 19;

        if(e1 >= 20 && e1 <= 49)
            exp2_float += e1 / 9.0f + 21;

        if(e1 >= 50 && e1 <= 65)
            exp2_float += e1 / 16.0f + 17;

        if(e1 >= 66 && e1 <= 79)
        {
            exp2_float += e1 / 4.0f + 19;
            expScaleF(exp2_float);
            if(exp2_float > 200)
            {
                exp2_float += e1 / 9.0f + 21;
                expScaleF(exp2_float);
            }   
        }

        if(e1 >= 80 && e1 <= 99)
        {
            exp2_float += e1 / 4.0f + 19;
            expScaleF(exp2_float);
            exp2_float += e1 / 9.0f + 21;
            expScaleF(exp2_float);
            if(exp2_float > 400)
            {
                exp2_float += e1 / 16.0f + 17;
                expScaleF(exp2_float);
                exp2_float *= 1.15;
            }
        }
        //ket luan
        exp1 -= e1;
    }
    //tra ve gia tri
    expScaleF(exp2_float);
    exp2 = exp2_float;
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    //road 1 
    float p1;
    float exp1_float = EXP1; //goi bien tam luu tru dau phay
    if(exp1_float >= nearestSquare(exp1_float))
        p1 = 1;
    else
        p1 = (exp1_float / nearestSquare(exp1_float) + 80) / 123;

    //road 2
    int money = M1/2; //co dinh tien
    float hp1_float = HP1; //goi bien tam luu tru dau phay
    float p2;
    if(oddEven(E2)) 
    {
        roads(hp1_float, exp1_float, M1, true, money); //chan
    }
    else
    {
        while(M1 > money) 
        {
            roads(hp1_float, exp1_float, M1, false, money); 
        }
    }
    hp1_float *= 0.83;
    hpScaleF(hp1_float);
    exp1_float *= 1.17;
    expScaleF(exp1_float);
    if(exp1_float >= nearestSquare(exp1_float))
        p2 = 1;
    else
        p2 = (exp1_float / nearestSquare(exp1_float) + 80) / 123;

    //road 3
    int pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p3 = pi[findi(E2)]/100.f;

    //ket luan
    if( p1 == p2 && p2 == p3 && p3 == 100)
        exp1_float *= 0.75;
    else
    {
        float avg;
        avg = (p1 + p2 + p3)/3;
        if(avg < 0.5)
        {
            hp1_float *= 0.85;
            exp1_float *= 1.15;
        }
        else
        {
            hp1_float *= 0.9;
            exp1_float *= 1.2;
        }
    }
    hpScaleF(hp1_float);
    expScaleF(exp1_float);
    HP1 = hp1_float;
    EXP1 = exp1_float;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    int matrix_taxi[10][10];
    int matrix_sherlock[10][10];

    int diem_gap_i = 0, diem_gap_j = 0;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix_taxi[i][j] > 0 and matrix_taxi[i][j] > E3 * 2)
            {
                diem_gap_i++;
            }
            else if (matrix_taxi[i][j] < 0 and matrix_taxi[i][j] < -E3)
            {
                diem_gap_j++;
            }
        }
    }
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix_sherlock[i][j] = abs(getSherlockPoint(i, j, matrix_taxi));
        }
    }
    while (diem_gap_i > 9)
    {
        diem_gap_i = diem_gap_i / 10 + diem_gap_i % 10;
    }
    while (diem_gap_j > 9)
    {
        diem_gap_j = diem_gap_j / 10 + diem_gap_j % 10;
    }

    if (abs(matrix_taxi[diem_gap_i][diem_gap_j]) > matrix_sherlock[diem_gap_i][diem_gap_j])
    {
        EXP1 = EXP1 * 0.88;
        HP1 = HP1 * 0.9;
        EXP2 = EXP2 * 0.88;
        HP2 = HP2 * 0.9;
        return matrix_taxi[diem_gap_i][diem_gap_j];
    }
    else
    {

        EXP1 = EXP1 * 1.12;
        HP1 = HP1 * 1.1;
        EXP2 = EXP2 * 1.12;
        HP2 = HP2 * 1.1;

        return matrix_sherlock[diem_gap_i][diem_gap_j];
    }
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    const char *pos = strchr(email, '@');
    int size = pos - email;
    char *se = new char[size + 1];
    strncpy(se, email, size);
    se[size] = '\0';
    
    int length = strlen(s);

    if(length < 8)
        return -1;
    if(length > 20)
        return -2;

    if (strpbrk(s, "@!#%$^") == nullptr)
        return -5; // Khong chua ki tu db

    if (strstr(s, se) != NULL)
        return -(300 + (strstr(s, se) - s)); // s chua se

    for (int i = 0; i < length - 2; ++i) 
    {
        if (s[i] == s[i+1] && s[i+1] == s[i+2])
            return -(400 + i); // >2 ki tu lien tiep giong nhau
    }

    delete[] se;

    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int repeat = 0; 
    int lengmax = 0;
    int correct = 0;
    for(int i=0; i < num_pwds-1; i++) 
    {
        int count = 0;
        for (int j=i+1; j < num_pwds; j++) 
        {
            if (arr_pwds[i] == arr_pwds[j]) 
                count++;
        }

        int length = strlen(arr_pwds[i]);
        if (count > repeat || (count == repeat && length > lengmax)) 
        {
            repeat = count;
            lengmax = length;
            correct = i;
        }
    }

    return correct;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////
