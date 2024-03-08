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
int up(double a) 
if (abs(a-int (a)) <=10E-7)
return int (a);
else 
return int (a)+1;
}
void checkUp (int & EXP)
{
    if(EXP > 600)
    {
        EXP=600;
    }if(EXP<0)
    {
        EXP=0;
    }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (E1<0 || E1>99) return -99;
    if (E1>=0 && E1<=3)
    {
        switch (E1)
        {
            case 0:
            EXP2+=29;
            break;
            case 1:
            EXP2+=45;
            break;
            case 2:
            EXP2+=75;
            break;
            case 3:
            EXP2+=29+45+75;
            break;
        }
        int D=E1*3+EXP1*7;
        if(D%2==0) {
            EXP1+=up(D/200.0);
        } else if(D%2==1) {
            EXP1-=up(D/100.0);
        }
    }
    else if(E1>=4 && E1<=99) {
        if(E1>=4 && E1<=19) {
            EXP2+=up((E1/4.0)+19);
        }else if (E1>=20 && E1<=49){
            EXP2+=up((E1/9.0)+21);
        }else if (E1>=50 && E1<=65){
            EXP2+=up((E1/16)+17);
        }else if (E1>=66 && E1<=79){
            EXP2+=up((E1/4.0)+19);
            if(EXP2>200){
                EXP2+=up((E1/9.0)+21);
            } else {}
        }else if (E1>=80 && E1<=99){
            EXP2+=up((E1/4.0)+19);
            EXP2+=up((E1/9.0)+21);
            if(EXP2>400){
              EXP2+=up((E1/16)+17);
              EXP2+=up(EXP2*1.15);  
            }else {  

            }
        }
        EXP1-=E1;
    }
    checkUp(EXP1);
    checkUp(EXP2);
    
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////