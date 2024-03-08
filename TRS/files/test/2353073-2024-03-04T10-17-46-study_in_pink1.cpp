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

//check the condition of HP
int checkhp(float hp) {
    if (hp > 666) {hp = 666;}
    if (hp < 0) {hp = 0;}
    return ceil(hp);
}

//check the condition of EXP
int checkexp(float exp) {
    if (exp > 600) {exp = 600;}
    if (exp < 0) {exp = 0;}
    return ceil(exp);
}

//check the condition of M
int checkm(float m) {
    if (m > 3000) {m = 3000;}
    if (m < 0) {m = 0;}
    return ceil(m);
}

//Calculate the probability in task 2 for road 1, road 2.
float Probability(int EXP) {
    float S = 0.00;
    S = (round(sqrt(EXP))) * (round(sqrt(EXP)));
    if (EXP >= S) {return 1;} else {return (((EXP / S) + 80)/123);}
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 > 99) || (e1 < 0)) {
        return -99;
    } else {
        checkexp(exp1);
        checkexp(exp2);
    }


    // Case 1:
    if (e1 < 4) {
        switch (e1) {
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
            exp2 += 29 + 45 + 75;
            break;
        }
        exp2 = checkexp(exp2);

        
        int D;
        D = e1 * 3 + exp1 * 7;

        switch (D % 2)
        {
        case 0:
            exp1 = checkexp( exp1 + (D / 200.00) );
            break;
        
        case 1:
            exp1 = checkexp( exp1 - (D/100.00));
            break;
        }
    }


    // Case 2:
    else {
        if (e1 < 20) {
            exp2 = checkexp( exp2 + (e1 / 4.00) + 19 );
        } else if (e1 < 50) {
            exp2 = checkexp( exp2 + (e1 / 9.00) + 21 );
        } else if (e1 < 66) {
            exp2 = checkexp( exp2 + (e1 / 16.00) + 17 );
        } else if (e1 < 80) {
            exp2 = checkexp( exp2 + (e1 / 4.00) + 19 );
            if (exp2 > 200) {exp2 = checkexp( exp2 + (e1 / 9.00) + 21 );}
        } else {
            exp2 = checkexp( exp2 + (e1 / 4.00) + 19 );
            exp2 = checkexp( exp2 + (e1 / 9.00) + 21 );
            if (exp2 > 400) {
                exp2 = checkexp( exp2 + (e1 / 16.00) + 17);
                exp2 = checkexp( exp2 * 1.15 );
            }
        }
        exp1 = checkexp(exp1 - e1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 > 99) || (E2 < 0)) {
        return -99;
    } else {
        checkhp(HP1);
        checkexp(EXP1);
        checkm(M1);
    }


    int M_initial = M1;
    float P_average, P1 = 0, P2 = 0, P3 = 0;

    // Road 01:
    P1 = Probability(EXP1);

    // Road 02:
    if (E2 % 2) {
        while (1) {
            if (HP1 < 200) {
                HP1 = checkhp(HP1 * 1.3);
                M1 = checkm(M1 - 150);
            } else {
                HP1 = checkhp(HP1 * 1.1);
                M1 = checkm(M1 - 70);
            }
            if ((M1 * 2) < M_initial) {break;}

            if (EXP1 < 400) {M1 = checkm(M1 - 200);} else {M1 = checkm(M1 - 120);}
            EXP1 = checkexp(EXP1 * 1.13);
            if ((M1 * 2) < M_initial) {break;}

            if (EXP1 < 300) {M1 = checkm(M1 - 100);} else {M1 = checkm(M1 - 120);}
            EXP1 = checkexp(EXP1 * 0.9);
            if ((M1 * 2) < M_initial) {break;}
        }

        HP1 = checkhp(HP1 * 0.83);
        EXP1 = checkexp(EXP1 * 1.17);
    } else {
        while (1) {
            if (HP1 < 200) {
                HP1 = checkhp(HP1 * 1.3);
                M1 = checkm(M1 - 150);
            } else {
                HP1 = checkhp(HP1 * 1.1);
                M1 = checkm(M1 - 70);
            }
            if (M1 == 0) {break;}

            if (EXP1 < 400) {M1 = checkm(M1 - 200);} else {M1 = checkm(M1 - 120);}
            EXP1 = checkexp(EXP1 * 1.13);
            if (M1 == 0) {break;}

            if (EXP1 < 300) {M1 = checkm(M1 - 100);} else {M1 = checkm(M1 - 120);}
            EXP1 = checkexp(EXP1 * 0.9);
            break;
        
        }
        
        HP1 = checkhp(HP1 * 0.83);
        EXP1 = checkexp(EXP1 * 1.17);
    }
    P2 = Probability(EXP1);

    // Road 03:
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = (E2 % 10 + E2 / 10) % 10;
    P3 = (P[i] / 100.00);

    // After going through all 3 routes
    if ((P1 == P2) && (P2 == P3) && (i == 4)) {EXP1 = checkexp(EXP1 * 0.75);} else {
        P_average = (P1 + P2 + P3) / 3;
        if (P_average < 0.5) {
            HP1 = checkhp(HP1 * 0.85);
            EXP1 = checkexp(EXP1 * 1.15);
        } else {
            HP1 = checkhp(HP1 * 0.9);
            EXP1 = checkexp(EXP1 * 1.2);
        }
    }


    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3 > 99) || (E3 < 0)) {
        return -99;
    } else {
        checkhp(HP1);
        checkhp(HP2);
        checkexp(EXP1);
        checkexp(EXP2);
    }

    // Create the grade matrix of taxi and count the number of positive values in the matrix greater than (E3 ∗ 2) and the number of negative values in the matrix smaller than (−E3) 
    float Score[10][10];
    int x = 0, y = 0;
    int i = 0, j = 0;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            Score[i][j] = ((E3*j)+(i*2))*(i-j);
            if (Score[i][j] > (E3*2)) {x++;}
            if (Score[i][j] < (-E3)) {y++;}
        }
    }

    //Calculate the meeting location
    while (x > 9) {
        x = (x % 10 + x / 10);
    }
    while (y > 9) {
        y = (y % 10 + y / 10);
    }

    //Find the grade of Sherlock and Waston
    float SherlockWastonScore = 0;
    if (x < y) {i = 0; j = y - x;} else {i = x - y; j = 0;};
    while ((i < 10) && (j < 10)) {
        if (Score[i][j] > SherlockWastonScore) {SherlockWastonScore = Score[i][j];}
        i++; j++;
    }
    i = ( (x + y) > 9 ) ? (x + y - 9) : 0;
    for (i; i < 10; i++) {
        j = x + y - i;
        if (Score[i][j] > SherlockWastonScore) {SherlockWastonScore = Score[i][j];}
    }

    // Updated the value of EXP!, EXP2, HP1, HP2
    if ( abs(Score[x][y]) > SherlockWastonScore ) {
        EXP1 = checkexp( EXP1 * 0.88 );
        HP1 = checkhp( HP1 * 0.9 );
        EXP2 = checkexp( EXP2 * 0.88 );
        HP2 = checkhp( HP2 * 0.9 );
        return Score[x][y];
    } else {
        EXP1 = checkexp( EXP1 * 1.12 );
        HP1 = checkhp( HP1 * 1.1 );
        EXP2 = checkexp( EXP2 * 1.12 );
        HP2 = checkhp( HP2 * 1.1 );
        return SherlockWastonScore;
    }
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    char Checker;
    bool checkCharType = true, sciCheck = false;
    int s_length = 0, i = 0, sei = -1, sci = 1, FirstPosViolate = 100, checkSpecialChar = 0;
    while (*email != 64) {se += *email; email ++;}

    while ((*s != '\0') && (s_length < 21)) {
        Checker = *s;
        
        // Check the password have the special character or not and the character type of all character in password
        if ( (*s == '@') || (*s == '#') || (*s == '$') || (*s == '!') || (*s == '%') ) {
            checkSpecialChar++;
        } else if ( ( (*s < '0') || (*s > '9') ) && ( (*s < 'a') || (*s > 'z') ) && ( (*s < 'A') || (*s > 'Z') ) && (FirstPosViolate == 100) ) {
            FirstPosViolate = s_length;
        }

        // Check the password contains se or not and calculate sei
        if (sei < 0) {
            if (se[0] == '\0') {
                sei = 0;
            } else {
                while (se[i] != '\0') {
                    if (*(s + i) != se[i]) {
                        break;
                    }
                    if (se[i + 1] == '\0') {
                        sei = s_length;
                    }
                    i++;
                }
                i = 0;
            }
        }

        //Calculate the length of password
        s_length++; 
        s++;
        
        //Check the password is consecutive and identical or not and calculate sci
        if ((Checker == *s) && (!sciCheck)) {
            sci++;
        } else if ((sci > 2) && (!sciCheck)) {
            sci = s_length - sci ; sciCheck = true;
        } else if (!sciCheck) {
            sci = 1;
        }
    }

    if (s_length < 8) {
        return -1;
    } else if (s_length > 20) {
        return -2;
    } else if (sei >= 0) {
        return -(300 + sei);
    } else if (sciCheck) {
        return -(400 + sci);
    } else if (checkSpecialChar == 0) {
        return -5;
    } else if (FirstPosViolate != 100) {
        return FirstPosViolate;
    } else {
        return -10;
    }
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int position = 0, i = 0, length = 0, OrdinalNumber = 0, MaxLength = 0, MaxAppearence = 0, FirstPosition = 0;;
    string Pass[30] = {};
    int Properties[30][3] = {};

    // Check all passowrds
    while (position < num_pwds)
    {   
        // Check the appearence of an password
        while (i <= OrdinalNumber) {
            if (arr_pwds[position] == Pass[i]) {
                Properties[i][1]++;
                break;
            } else if (i == OrdinalNumber) {
                Pass[OrdinalNumber] = arr_pwds[position];
                Properties[OrdinalNumber][1]++;
                Properties[OrdinalNumber][3] = position;
            
                // Calculate the length of an password
                i = 0;
                while (arr_pwds[position][i] != '\0')
                {
                    length++;
                    i++;
                }
                Properties[OrdinalNumber][2] = length;
            
                
                length = 0;
                OrdinalNumber++;
                i = 0;
                break;
            }
            i++;
        } 
        position++;
        i = 0;
    }

    // Compare the appearence and the length of all passwords
    while (i < OrdinalNumber) {
        if (Properties[i][1] > MaxAppearence) {
            MaxAppearence = Properties[i][1];
            MaxLength = Properties[i][2];
            FirstPosition = Properties[i][3];
        } else if (Properties[i][1] == MaxAppearence) {
            if (Properties[i][2] > MaxLength) {
                MaxLength = Properties[i][2];
                FirstPosition = Properties[i][3];
            }
        }
        i++;
    }
    return FirstPosition;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////