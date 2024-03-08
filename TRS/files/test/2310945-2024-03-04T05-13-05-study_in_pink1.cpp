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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    if(E1>=0&&E1<=3)
    {
    if(E1==0)
    {
        EXP2+=29;
    }
    else if(E1==1)
    {
        EXP2+=45;
    }
    else if(E1==2)
    {
        EXP2+=75;
    }
    else 
    {
        EXP2=EXP2+(29+45+75);
    }
    int D=E1*3+EXP1*7;
    int I=D%2;
    if(I==0)
    {
         EXP1=ceil(EXP1+(D/200.0));
    }
    else
    {
        EXP1=ceil(EXP1-(D/100.0));
    }
    }
    else if(E1>=4&&E1<=99)
    {
        if(E1>=4&&E1<=19)
        {
            EXP2+=ceil(E1/4.0+19);
        }
        else if(E1>=20&&E1<=49)
        {
            EXP2+=ceil(E1/9.0+21);
        }
        else if(E1>=50&&E1<=65)
        {
            EXP2+=ceil(E1/16.0+17);
        }
        else if(E1>=66&&E1<=79)
        {
            EXP2=ceil(EXP2+(E1/4.0+19));
            if(EXP2<=200)
            {
                EXP2=0+EXP2;
            }
            else
            {
                EXP2=ceil(EXP2+(E1/9.0+21));
            }
        }
        else
        {
        
            EXP2=ceil(EXP2+(E1/4.0)+19);
            EXP2=ceil(EXP2+(E1/9.0)+21);
            if(EXP2<=400)
            {
                EXP2=0+EXP2;
            }
            else
            {
                EXP2=ceil(EXP2+(E1/16.0+17));
                EXP2=ceil(EXP2*1.15);
            }
        }
        EXP1-=E1;
    }
    else return -99;
    if(EXP1>600)
    {
        EXP1=600;
    }
    else if(EXP1>=0&&EXP1<=600)
    {
        EXP1=0+EXP1;
    }
    else
    {
        EXP1=0;
    }
    if(EXP2>600)
    {
        EXP2=600;
    }
    else if(EXP2>=0&&EXP2<=600)
    {
        EXP2=0+EXP2;
    }
    else
    {
        EXP2=0;
    }
    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
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