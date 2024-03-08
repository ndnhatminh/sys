#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
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
    //TODO: implement task
    return -1;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    //TODO: implement task
    return -1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    //TODO: implement task
    return -1;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int Numstring[num_pwds];
    for (int m = 0; m < num_pwds; m++){Numstring[m]=0;}

    for(int i = 0; i < num_pwds; i++) {
        for (int j = 0; j < num_pwds; j++) {
            if(i != j) {
                if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) { Numstring[i] = Numstring[i] + 1; }
            }
        }
    }

    int max = Numstring[0];
    int n=0;
    while (n < num_pwds) {
        if(max < Numstring[n]){max = Numstring[n];}
        n++;
    }

    int k;
    for (k = 0; k < num_pwds; k++) {
        if(Numstring[k] == max){break;}
    }
    return k;
}
//int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
//    // TODO: Complete this function
//    int max = 0;
//    int max_index = -1;
//    int max_string_length = 0;
//    string string_max_freq;
//    string string_max_length;
//    for (int i = 0; i < num_pwds; i++) {
//        int hz = 1;
//        for (int j = i + 1; j < num_pwds; j++) {
//            if (i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
//                hz++;
//            }
//        }
//        if ( hz > max || (hz == max && max_string_length < strlen(arr_pwds[i])))
//        {
//            max = hz;
//            max_string_length = strlen(arr_pwds[i]);
//            max_index = i;
//        }
//    }
//    return max_index;
//}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////