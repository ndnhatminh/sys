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

bool oddEven(int d) //kiem tra tinh chan le
{
    return (d % 2 == 0);
}

float nearestSquare(float ind) //tim perfect square
{
    float s;
    s = round(sqrt(ind));
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

int mScaleF(int & M1)
{
    if(M1 > 3000)
        M1 = 3000;
    if(M1 < 0)
        M1 = 0;
    
    return M1;
}

void roads(float & HP1, float & EXP1, int & M1, bool sochan, int money) //di qua 3 duong
{
    while(true)
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
        if (sochan == false && M1 < money)
            return;

        if(EXP1 < 400) //di chuyen
            M1 -= 200;
        else
            M1 -= 120;

        EXP1 *= 1.13;
        expScaleF(EXP1);

        if (sochan == true && M1 <= 0) 
            return;
        if (sochan == false && M1 < money)
            return;

        if(EXP1 < 300) //vo gia cu
            M1 -= 100;
        else
            M1 -= 120;

        EXP1 *= 0.9;
        expScaleF(EXP1);

        if (sochan == true )
            break;
            
        if (sochan == false && M1 < money)
            break;  
    }
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
    int biggest = j1;
    while (true)
    {
        if (matrix_taxi[i1][j1] > biggest)
        {
            biggest = matrix_taxi[i1][j1];
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
        if (matrix_taxi[i2][j2] > biggest)
        {
            biggest = matrix_taxi[i2][j2];
        }
        i2++;
        j2++;
        if (i2 > 9 or j2 < 0)
        {
            break;
        }
    }

    return biggest;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function

    float exp2_float = exp2; //goi bien tam luu tru dau phay
    float exp1_float = exp1;

    if(e1 < 0 || e1 > 99)
        return -99;

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
    expScaleF(exp2_float);
    //ket luan
    int d = e1 * 3 + exp1 * 7;
    if(oddEven(d)) 
        exp1_float += d / 200.0f;
    else
        exp1_float -= d / 100.0f;
    expScaleF(exp1_float);
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
                exp2_float += e1 / 9.0f + 21;
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
        exp1_float -= e1;
        expScaleF(exp1_float);
    }
    //tra ve gia tri
    expScaleF(exp2_float);
    exp2 = exp2_float;
    exp1 = exp1_float;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99)
        return -99;
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
        roads(hp1_float, exp1_float, M1, true, money); //chan
    else
    {
        while(M1 > money)
            roads(hp1_float, exp1_float, M1, false, money);
    }
    M1 = mScaleF(M1);
    hp1_float *= 0.83;
    hpScaleF(hp1_float);
    exp1_float *= 1.17;
    expScaleF(exp1_float);
    if(exp1_float >= nearestSquare(exp1_float))
        p2 = 1;
    else
        p2 = (exp1_float / nearestSquare(exp1_float) + 80) / 123;

    //road 3
    float pi[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float p3 = pi[findi(E2)]/100.f;

    //ket luan
    if( p1 == p2 && p2 == p3 && p3 == 1)
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

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    float e3 = E3;
    float hp1 = HP1;
    float exp1 = EXP1;
    float hp2 = HP2;
    float exp2 = EXP2;

    int matrix_taxi[10][10];
    int matrix_sherlock[10][10];

    int meet_i = 0, meet_j = 0;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            matrix_taxi[i][j] = ((e3 * j) + (i * 2)) * (i - j);
            if (matrix_taxi[i][j] > 0 and matrix_taxi[i][j] > e3 * 2)
            {
                meet_i++;
            }
            else if (matrix_taxi[i][j] < 0 and matrix_taxi[i][j] < -e3)
            {
                meet_j++;
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
    while (meet_i > 9)
    {
        meet_i = meet_i / 10 + meet_i % 10;
    }
    while (meet_j > 9)
    {
        meet_j = meet_j / 10 + meet_j % 10;
    }

    if (abs(matrix_taxi[meet_i][meet_j]) > matrix_sherlock[meet_i][meet_j])
    {
        exp1 = exp1 * 0.88;
        hp1 = hp1 * 0.9;
        exp2 = exp2 * 0.88;
        hp2 = hp2 * 0.9;
        hpScaleF(hp1);
        hpScaleF(hp2);
        expScaleF(exp1);
        expScaleF(exp2);
        HP1 = hp1;
        EXP1 = exp1;
        HP2 = hp2;
        EXP2 = exp2;
        cout << "EXP1 : " << EXP1 << endl;
        cout << "EXP2 : " << EXP2 << endl;
        cout << "HP1 : " << HP1 << endl;
        cout << "HP2 : " << HP2 << endl;
        return matrix_taxi[meet_i][meet_j];
    }
    else
    {
        exp1 = exp1 * 1.12;
        hp1 = hp1 * 1.1;
        exp2 = exp2 * 1.12;
        hp2 = hp2 * 1.1;
        hpScaleF(hp1);
        hpScaleF(hp2);
        expScaleF(exp1);
        expScaleF(exp2);
        HP1 = hp1;
        EXP1 = exp1;
        HP2 = hp2;
        EXP2 = exp2;
        cout << "EXP1 : " << EXP1 << endl;
        cout << "EXP2 : " << EXP2 << endl;
        cout << "HP1 : " << HP1 << endl;
        cout << "HP2 : " << HP2 << endl;
        return matrix_sherlock[meet_i][meet_j];
    }
    return -1;
}            

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    const char *pos = strchr(email, '@');
    int size = pos - email;
    char *se = new char[size+1];
    strncpy(se, email, size);
    se[size] = '\0';
    int strLength = strlen(s);

    if(strLength < 8)
        return -1;
    if(strLength > 20)
        return -2;

    if(strstr(s, se) != NULL)
        return -(300 + (strstr(s, se) - s)); // s chua se

    for(int i = 0; i < strLength - 2; ++i) 
    {
        if(s[i] == s[i+1] && s[i+1] == s[i+2])
            return -(400 + i); // >2 ki tu lien tiep giong nhau
    }

    if(strpbrk(s, "!@#$%^") == nullptr)
        return -5; // Khong chua ki tu db

    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int mRepeat = 0;
    int mLength = 0;
    int correct = -1;

    for(int i = 0; i < num_pwds; i++) 
    {
        int k = 0; //goi bien dem
        int cLength = strlen(arr_pwds[i]); //do dai hien tai

        for(int j = 0; j < num_pwds; j++) 
        {
            if(i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0) 
                k++;
        }

        if(k > mRepeat || (k == mRepeat && cLength > mLength)) 
        {
            mRepeat = k;
            mLength = cLength;
            correct = i;
        }
    }

    return correct;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////