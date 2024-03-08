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

//Ham dieu chinh gia tri HP
void checkHP (int &HP)
{
    HP = (HP > 666 ? 666 : (HP < 0 ? 0 : HP));
}
//Ham dieu chinh gia tri EXP
void checkEXP(int &exp)
{
    exp = (exp > 600 ? 600 : (exp < 0 ? 0 : exp));
}
//Ham dieu chinh M
void checkM(int &M)
{
    M = (M > 3000 ? 3000 : (M < 0 ? 0 : M));
}
//Ham tim so chinh phuong gan nhat
int square_near(int a)
{
    static int S, c, d;
	c = a;
	d = a;
	while (sqrt(c) != (float) sqrt(c))
	{
		c--;
	}
	while (sqrt(d) != (float) sqrt(d))
	{
		d++;
	}
	S = ((d - a) >= (a - c) ? c : d);
    return S;
}
//Ham tim gia tri lon nhat tren duong cheo trai
int max_trai(int map[10][10], int i, int j)
{
    int a = map[i][j];
    for (int m = i, n = j; (m < 10) && (n < 10); m++, n++)
    {
        if(a < map[m][n])
        {
            a = map[m][n];
        }
    }
    for (int m = i, n = j; (m >= 0) && (n >= 0); m--, n--)
    {
        if(a < map[m][n])
        {
            a = map[m][n];
        }
    }
    return a;
}
//Ham tim gia tri lon nhat tren duong cheo phai
int max_phai(int map[10][10], int i, int j)
{
    int a = map[i][j];
    for (int m = i, n = j; (m < 10) && (n >= 0); m++, n--)
    {
        if(a < map[m][n])
        {
            a = map[m][n];
        }
    }
    for (int m = i, n = j; (n < 10) && (m >= 0); m--, n++)
    {
        if(a < map[m][n])
        {
            a = map[m][n];
        }
    }
    return a;
}
//Ham chuyen so 2 chu so thanh 1 chu so
int mot_chu_so(int a)
{
    int i = (a < 10 ? a :(a/10 + a % 10));
    if(i < 10)
    {
        return i;
    } else
    {
        return mot_chu_so(i);
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 < 0 || e1 > 99) return -99;
    checkEXP(exp1);
    checkEXP(exp2);
    if ((e1 >= 0) && (e1 <= 3))
    {
        switch(e1)
        {
            case 0:
            exp2 += 29;
            break;
            case 1:
            exp2 += 45;
            break;
            case 2:
            exp2 += 75;
            break;
            case 3:
            exp2 += 149;
            break;
        }
        checkEXP(exp2);
        int D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
        {
            exp1 += ceilf((float) D/200);
        } else
        {
            exp1 = ceilf((float) exp1 - D/100);
        }
        checkEXP(exp1);
    }
    if ((e1 >= 4) && (e1 <= 99))
    {
        if ((e1 >= 4) && (e1 <= 19))
        {
            exp2 += ceilf((float) e1/4 + 19);
        }
        else if ((e1 >= 20) && (e1 <= 49))
        {
            exp2 += ceilf((float) e1/9 + 21);
        }
        else if ((e1 >= 50) && (e1 <= 65))
        {
            exp2 += ceilf((float) e1/16 + 17);
        }
        else if ((e1 >= 66) && (e1 <= 79))
        {
            exp2 += ceilf((float) e1/4 + 19);
            if (exp2 > 200)
            {
                exp2 += ceilf((float) e1/9 + 21); 
            }
        }
        else 
        {
            exp2 += ceilf((float) e1/4 + 19);
            exp2 += ceilf((float) e1/9 + 21);
            if (exp2 > 400)
            {
                exp2 += ceilf((float) e1/16) + 17;
                exp2 += ceilf((float) exp2 * 0.15);
            }
        }
        checkEXP(exp2);
        exp1 -= e1;
        checkEXP(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    //con duong 1:
    checkEXP(EXP1);
    checkHP(HP1);
    checkM(M1);
    int S1 = square_near(EXP1);
    float P1;
    if (EXP1 >= S1) 
    {
        P1 = 1;
    }
    else 
    {
        P1 = (float) ((float) EXP1/S1 + 80)/123;
    }
    //con duong 2:
    float M = (float) M1/2;
    int Mk = 0;
    while (E2 % 2 == 0)
    {
        if (M1 <= 0) break;
        if(HP1 < 200)
        {
            HP1 += ceilf((float) HP1*0.3);
            M1 -= 150;
        } else
        {
            HP1 += ceilf((float) HP1*0.1);
            M1 -= 70;
        }
        checkHP(HP1);
        if(M1 <= 0) break;
        if(EXP1 < 400)
        {
            M1 -= 200;
        } else
        {
            M1 -= 120;
        }
        EXP1 += ceilf((float) EXP1*0.13);
        checkEXP(EXP1);
        if(M1 <= 0) break;

        if(EXP1 < 300)
        {
            M1 -= 100;
        }else
        {
            M1 -= 120;
        }
        EXP1 = ceilf((float) EXP1 - EXP1*0.1);
        break;
    }

    while (E2 % 2 == 1)
    {
        if(M1 == 0) break;
        if(HP1 < 200)
        {
            HP1 += ceilf((float) HP1*0.3);
            M1 -= 150;
            Mk += 150;
        }else
        {
            HP1 += ceilf((float) HP1*0.1);
            M1 -= 70;
            Mk += 70;
        }
        checkHP(HP1);
        if(Mk > M) break;

        if(EXP1 < 400)
        {
            M1 -= 200;
            Mk += 200;
        }else
        {
            M1 -= 120;
            Mk += 120;
        }
        EXP1 += ceilf((float) EXP1*0.13);
        checkEXP(EXP1);
        if(Mk > M) break;

        if(EXP1 < 300)
        {
            M1 -= 100;
            Mk += 100;
        }else
        {
            M1 -= 120;
            Mk += 120;
        }
        EXP1 = ceilf((float) EXP1 - EXP1*0.1);
        if(Mk > M) break;
    }
    HP1 = ceilf((float) HP1 - HP1*0.17);
    EXP1 += ceilf((float) EXP1*0.17);
    checkEXP(EXP1);
    checkM(M1);
    int S2 = square_near(EXP1);
    float P2;
    if (EXP1 >= S2) 
    {
        P2 = 1;
    }
    else 
    {
        P2 = (float) ((float) EXP1/S2 + 80)/123;
    }

    //con duong 3:
    float P[10] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i = (E2 < 10) ? E2 : ((E2 / 10 + E2 % 10) % 10);
    float P3 = P[i];
    if((P1 == 1.0)&&(P2 == 1.0)&&(P3 == 1.0))
    {
        EXP1 = ceilf((float) EXP1 - EXP1*0.25);
    }
    else if((P1 + P2 + P3)/3 < 0.5)
    {
        HP1 = ceilf((float) HP1 - HP1*0.15);
        EXP1 += ceilf((float) EXP1*0.15);
    }
    else
    {
        HP1 = ceilf((float) HP1 - HP1*0.1);
        EXP1 += ceilf((float) EXP1*0.2);
    }
    checkHP(HP1);
    checkEXP(EXP1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return - 99;
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    int taxi[10][10];
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
    int SW[10][10];
    for(int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            SW[i][j] = (max_trai(taxi, i, j) > max_phai(taxi, i, j)) ? max_trai(taxi, i, j): max_phai(taxi, i, j);
        }  
    }
    int i = 0, j = 0;
    for(int m = 0; m < 10; m++)
    {
        for(int n = 0; n < 10; n++)
        {
            if(taxi[m][n] > E3 * 2)
            {
                i++;
            }
            if(taxi[m][n] < - E3)
            {
                j++;
            }
        }
    }
    i = mot_chu_so(i);
    j = mot_chu_so(j);
    if(abs(taxi[i][j]) > SW[i][j])
    {
        EXP1 = ceilf((float) EXP1 - EXP1 * 0.12);
        EXP2 = ceilf((float) EXP2 - EXP2 * 0.12);
        HP1 = ceilf((float) HP1 - HP1 * 0.1);
        HP2 = ceilf((float) HP2 - HP2 * 0.1);
        return taxi[i][j];
    } else
    {
        EXP1 = ceilf((float) EXP1 + EXP1 * 0.12);
        checkEXP(EXP1);
        EXP2 = ceilf((float) EXP2 + EXP2 * 0.12);
        checkEXP(EXP2);
        HP1 = ceilf((float) HP1 + HP1 * 0.1);
        checkHP(HP1);
        HP2 = ceilf((float) HP2 + HP2 * 0.1);
        checkHP(HP2);
        return SW[i][j];
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char se[99] = "";
    for (int i = 0; i < strlen(email); i++)
    {
        if (email[i] == '@')
        {
            break;
        }
        se[i] = email[i];
    }
    if (strlen(s) < 8)
    {
        return -1;
    }
    if (strlen(s) > 20)
    {
        return -2;
    }
    if(strstr(s, se))
    {
        return -(300 + strstr(s, se) - s);
    }
    for (int i = 0; i <= (strlen(s) - 2); i++)
    {
        if ((s[i] == s[i + 1]) && (s[i + 1] == s[i + 2]))
        {
            return - (400 + i);
        }
    }
    bool a = true;
    for (int i = 0; i < strlen(s); i++)
    {
        if ((s[i] == '@')||(s[i] == '#')||(s[i] == '%')||(s[i] == '$')||(s[i] == '!'))
        {
            a = false;
        }
    }
    if (a)
    {
        return -5;
    }
    for (int i = 0; i <strlen(s); i++)
    {
        if((((int) s[i] < 48)||((int) s[i] > 57))&&(((int) s[i] < 64)||((int) s[i] > 90))&&(((int) s[i] < 97)||((int) s[i] > 122))&&(s[i] != '!')&&(s[i] != '#')&&(s[i] != '$')&&(s[i] != '%'))
        {
            return i;
        }
    }
    return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int num;
    int a = 0, b;
    string c = arr_pwds[0];
    for(int i = 0; i < num_pwds; i++)
    {
        b = 0;
        string d = arr_pwds[i];
        for(int j = i; j < num_pwds; j++)
        {
            if(d.compare(arr_pwds[j]) == 0)
            {
                b++;
            } 
        }
        if (b >= a)
        {
            if(b > a)
            {
                a = b;
                c = d;
                num = i;
            }
            else if(d.size() > c.size())
            {
                c = d;
                num = i;
            }
        }
    }
    return num;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////