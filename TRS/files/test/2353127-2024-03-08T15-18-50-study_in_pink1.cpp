#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & exp1,
        int & exp2,
        int & M1,
        int & M2,
        int & e1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> exp1 >> exp2
            >> M1 >> M2
            >> e1 >> E2 >> E3;
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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
int A;
A = EXP2;
if (E1 >= 0 && E1 <= 3) 
    {

    switch (E1) 
        {
            case 0: EXP2 += 29;  break;
            case 1: EXP2 += 45;  break;
            case 2: EXP2 += 75;  break;
            case 3: EXP2 += 149; break;
        }

    int D = E1 * 3 + EXP1 * 7; 
    if (D % 2 == 0) {EXP1 += D / 200;} 
    else {EXP1 -= D / 100;}

    } 

    else if (E1 >= 4 && E1 <= 19) 
    {
        EXP2 = round(V + (E1 / 4.0 + 19));
        EXP1 -= E1;
    } 

    else if (E1 >= 20 && E1 <= 49) 
    {
        EXP2 = round(V + (E1 / 9.0 + 21));
        EXP1 -= E1;
    } 

    else if (E1 >= 50 && E1 <= 65) 
    {
        EXP2 =  round(V + (E1 / 16.0+ 17));
        EXP1 -= E1;
    } 

    else if (E1 >= 66 && E1 <= 79) 
    {
        EXP2 = round(V + (E1 / 4.0 + 19));
        if (EXP2 > 200) {
            EXP2 = round(V + (E1 / 9.0 + 21));
        }
        EXP1 -= E1;
    }

    else if (E1 >= 80 && E1 <= 99) 
    {
        EXP2 = round(2*V + (E1 / 4.0 + 19) + (E1 / 9.0 + 21));
        if (EXP2 > 400) {
            EXP2 +=round(E1 / 16.0 )+ 17;
            EXP2 = round(EXP2 * 1.15);
        }
        EXP1 -= E1;
    }
    
    if (EXP1 > 600) {EXP1 = 600;}
    if (EXP1 < 0) {EXP1 = 0;}
    if (EXP2 > 600) {EXP2 = 600;}
    if (EXP2 < 0) {EXP2 = 0;}
    if (E1 > 99) {return -99;}
    if (E1 < 0) {return -99;}
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
float P1, P2, P3, Ptb;
    int m = M1 * 0.5;
    int A = 0;
    int S = static_cast<int>(sqrt(EXP1) + 0.5); 

    if (EXP1 >= S) // DUONG 1
    {
        P1 = 1;
    } 

    else 
    {
        P1 = (EXP1 / static_cast<float>(S) + 80) / 123; 
    }

    if (E2 % 2 != 0) { // NEU LE 
        while (m > A) 
        {
            if (HP1 < 200) // ACTION 1
            { 
                HP1 = round(HP1 * 1.3);
                M1 = M1 - 150;
                A += 150;
            } 

            else 
            {
                HP1 = round(HP1 * 1.1);
                M1 = M1 - 70;
                A += 70;
            }

            if (m < A) // ACTION 2
                break;
            else
            { 
                if (EXP1 < 400) {
                    M1 = M1 - 200;
                    A += 200;
                } else 
                {
                    M1 = M1 - 120;
                    A += 120;
                }

                EXP1 = round(EXP1 * 1.13);

                if (m < A)
                    break;
                else // ACTION 3
                { 
                    if (EXP1 < 300) {
                        M1 = M1 - 100;
                        A += 100;
                    } else {
                        M1 = M1 - 120;
                        A += 120;
                    }
                    EXP1 = round(EXP1 * 0.9);
                }
            }
        }
    } 
    else // NEU CHAN
    { 
        while (m >= 0) 
        {
            // ACTION 1
            if (HP1 < 200) 
            {
                HP1 = round(HP1 * 1.3);
                M1 = M1 - 150;
                A += 150;
            } 

            else 
            {
                HP1 = round(HP1 * 1.1);
                M1 = M1 - 70;
                A += 70;
            }

            if (M1 <= 0)
                break;
            if (EXP1 < 400) //action 2
            { 
                M1 = M1 - 200;
                A += 200;
            } 
            else
            {
                M1 = M1 - 120;
                A += 120;
            }

            EXP1 = round(EXP1 * 1.13);
            if (m <= 0)
                break;
            else 
            { 
                if (EXP1 < 300) // ACTION 3
                {
                    M1 = M1 - 100;
                    A += 100;
                } 

                else
                {
                    M1 = M1 - 120;
                    A += 120;
                }

                EXP1 = round(EXP1 * 0.9);
                break;
            }
        }
    }

    HP1 = round(HP1 * 0.83);
    EXP1 = round(EXP1 * 1.17);

    if (EXP1 >= S) 
    {
        P2 = 1;
    } 

    else 
    {
        P2 = (EXP1 / static_cast<float>(S) + 80) / 123; 
    }
    //round 2
    float P[] = {0.32, 0.47, 0.28, 0.79, 1, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i;
    if (E2 < 10 && E2 > 0 ) 
    {
        i = E2;
    } 
    else if(E2 > 10 && E2 < 99) 
    {
        i = ((E2 - floor(E2 / 10) * 10) + floor(E2 / 10));
        if (i < 10 ) {i = i;} 
        else if (i >= 10) {i = i - 9 ;}
    }
    P3 = P[i];
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 *= 0.75;
    } 

    else 
    {
        Ptb = (P1 + P2 + P3) / 3;
        if (Ptb < 0.5 && Ptb > 0) {
            HP1 = round(HP1 * 0.85);
            EXP1 = round(EXP1 * 1.15);
        } 
        else 
        {
            HP1 = round(HP1 * 0.9);
            EXP1 = round(EXP1 * 1.2);
        }
    }
    // round 3 
    
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
    if (E2 > 99 || E2 < 0) return -99;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & exp1, int & HP2, int & exp2, int E3) {
    int taxi[10][10];
    int Duong=0, Am=0;
    for(int i=0; i<10;i++)
    {
        for(int j=0; j<10;j++)
        {
            taxi[i][j]=((E3*j)+(i*2))*(i-j);
            if(taxi[i][j]> E3*2) {Duong++;}
            else if(taxi[i][j]< -E3 ) {Am++;}
        }
    }

    while(Duong>9)
    {
        int a, b;
        b=Duong%10;
        a=Duong/10;
        Duong=a+b;        
    }

    while(Am>9)
    {
        int a, b;
        b=Am%10;
        a=Am/10;
        Am=a+b;        
    }

    int Mtaxi=taxi[Duong][Am], MS=taxi[Duong][Am];
    for( int i=Duong,j=Am; i<10 && j>0; i++,j-- )
    {
        if(taxi[i][j] > MS ){MS=taxi[i][j];}
    }

    for( int i=Duong,j=Am; j<10 && i>0; i--,j++ )
    {
        if(taxi[i][j] > MS ){MS=taxi[i][j];}
    }

    for( int i=Duong,j=Am; i<10 && j<10 ; i++,j++ )
    {
        if(taxi[i][j] > MS ){MS=taxi[i][j];}
    }

    for( int i=Duong,j=Am; i>0 && j>0 ; i--,j-- )
    {
        if(taxi[i][j] > MS ){MS=taxi[i][j];}
    }

    if(abs(Mtaxi)> abs(MS))
    {
        exp1*=0.88;
        HP1*=0.9;
        exp2*=0.88;
        HP2*=0.9;
        return Mtaxi;
    }
    else
    {
        exp1*=1.12;
        HP1*=1.1;
        exp2*=1.12;
        HP2*=1.1;
        return MS;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;

    string mail(email), pass(s);

    int pos = mail.find('@');
    string se = mail.substr(0, pos);
    if (pass.find(se) != string::npos) return -(300 + pass.find(se));

    int len = pass.length();

    char c = pass[0];
    int COUNTC = 1, inC = 0;
    for (int i = 1; i < len; i++) 
    {
        if (pass[i] == c) 
        {
            COUNTC++;
            if (COUNTC > 2) return -(400 + inC);
        }
        else 
        {
            c = pass[i];
            COUNTC = 1;
            inC = i;
        }
    }

    //@ # % $ !
    bool hasSpecial = false;
    for (int i = 0; i < len; i++) 
    {
        if (pass[i] == '@' || pass[i] == '#' || pass[i] == '%' || pass[i] == '$' || pass[i] == '!') 
        {
            hasSpecial = true;
            break;
        }
    }

    if (!hasSpecial) return -5;

    for (int i = 0; i < len; i++) 
    {
        if ((pass[i] < 'A' || pass[i] > 'Z') &&
            (pass[i] < 'a' || pass[i] > 'z') &&
            (pass[i] < '0' || pass[i] > '9')) 
        {
            if (pass[i] != '@' && pass[i] != '#' && pass[i] != '%' && pass[i] != '$' && pass[i] != '!') return i;
        }
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
struct PasswordInfo 
{
    int COUNT;
    int LENGTH;
};
 PasswordInfo MAX_PASS = {0, 0};
    int max_index = -1;

    for (int i = 0; i < num_pwds; ++i) 
    {
        const char *password = arr_pwds[i];
        int PASS_LENGTH = strlen(password);
        int COUNT = 1;

        // Đếm số lần xuất hiện của mật khẩu
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(password, arr_pwds[j]) == 0) 
            {
                ++COUNT;
            }
        }

        // Kiểm tra nếu mật khẩu hiện tại có số lần xuất hiện lớn hơn mật khẩu có số lần xuất hiện nhiều nhất hiện tại
        if (COUNT > MAX_PASS.COUNT || (COUNT == MAX_PASS.COUNT && PASS_LENGTH > MAX_PASS.LENGTH)) {
            MAX_PASS.COUNT = COUNT;
            MAX_PASS.LENGTH = PASS_LENGTH;
            max_index = i;
        }
    }
    return max_index;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////