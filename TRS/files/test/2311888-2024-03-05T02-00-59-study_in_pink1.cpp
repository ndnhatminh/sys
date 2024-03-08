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
// Check Info
void checkInfo (int & info, int num1, int num2){
    if      (info > num2) {info = num2;}
    else if (info < num1) {info = num1;}
}

//This for probability
double xacSuat (int exp) {
    int num = 0, i = 1; double ans1;
    do {
        num+= i;
        i += 2;
    }while (num < exp);
    int num1 = num - exp, num2 = exp - (num - (i - 2));
    if ((num1 > num2)|(num1 == 0))    {ans1 = 1;}
    else {
        ans1 = num;
        ans1 = (((exp*1.0)/num) + 80.0)/123.0;
    }
    return ans1;
}

//Path2
double path2 (int & hp1, int & exp1, int & m1, int e2) {
    int m1max = ceil(m1*0.5);
    if (m1 > 0) {
        if (e2 % 2 != 0) {
            do {
                if (hp1 < 200) {
                    hp1 = ceil(hp1 + hp1*0.3);  m1 -= 150;
                }else {
                    hp1 = ceil(hp1 + hp1*0.1);  m1 -= 70;}
                checkInfo(hp1, 0, 666);
                if (m1 < m1max) {break;}

                if (exp1 < 400) {m1 -= 200;}
                else            {m1 -= 120;}
                exp1 = ceil(exp1 + exp1*0.13);
                checkInfo(exp1, 0, 600);
                if (m1 < m1max) {break;}


                if (exp1 < 300) {m1 -= 100;}
                else            {m1 -= 120;}
                exp1 = ceil(exp1 - exp1*0.1);
                checkInfo(exp1, 0, 600);
            }while (m1 >= m1max);
        }else {
            while (true) {
            //P1
            if (hp1 < 200) {
                hp1 = ceil(hp1 + hp1*0.3);  m1 -= 150;
            }else {
                hp1 = ceil(hp1 + hp1*0.1);  m1 -= 70;
            }
            checkInfo(hp1, 0, 666); checkInfo(m1, 0, 3000);
            if (m1 == 0) {break;}

            //P2
            if (exp1 < 400) {m1 -= 200;}
            else            {m1 -= 120;;}
            exp1 = ceil(exp1 + exp1*0.13);
            checkInfo(exp1, 0, 600); checkInfo(m1, 0, 3000);
            if (m1 == 0) {break;}

            //P3
            if (exp1 < 300) {m1 -= 100;}
            else            {m1 -= 120;}
            exp1 = ceil(exp1 - exp1*0.1);
            checkInfo(exp1, 0, 600);  checkInfo(m1, 0, 3000);
            break;
            }
        }
    }else {;}
    hp1 = ceil(hp1 - hp1*0.17);
    exp1 = ceil(exp1 + exp1*0.17);
    checkInfo (hp1, 0, 666);
    checkInfo (exp1, 0, 600);
    checkInfo (m1, 0, 3000);
    double ans2 = xacSuat(exp1);
    return ans2;
}

//Path3
double path3 (int e2) {
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}, i;
    if (e2 - 10 < 0)    {i = e2;}
    else {
        i = e2/10 + (e2 - (e2/10)*10);
        if ((i == 20)|(i==10)) {i = 0;}
        if (i - 10 > 0) {i -= 10;}
    }
    double ans3 = P[i]/100.0;
    return ans3;
}

void findMax (int num, int & result) {
    if (num > result) {result = num;}
}

int findNum (int num) {
    num = num/10 + (num-(num/10)*10);
    while (num >= 10) {num -= 9;}
    return num;
}

int matrix (int e3, int & point) {
    int taxiM[10][10] = { {0} }, pos = 0, neg = 0;
    bool winner;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxiM[i][j] = ((e3*j)+(i*2))*(i-j);
            if (taxiM[i][j] > (e3 * 2)) {pos++;}
            else if (taxiM[i][j] < (-e3)) {neg++;}
        }
    }
    int a = findNum(pos), b = findNum(neg);
    if (a <= b) {
        for (int i = a, j = b; ((j >= 0)&(i < 10)); i++, j--) {
            findMax (taxiM[i][j], point);
        }
    }else {
        for (int i = a, j = b; ((j < 10)&(i < 10)); i++, j++) {
            findMax (taxiM[i][j], point);
        }
        for (int i = a, j = b; ((j >= 0)&(i >= 0)); i--, j--) {
            findMax (taxiM[i][j], point);
        }
        for (int i = a, j = b; ((j >= 0)&(i < 10)); i++, j--) {
            findMax (taxiM[i][j], point);
        }
        for (int i = a, j = b; ((i >= 0)&(j < 10)); i--, j++) {
            findMax (taxiM[i][j], point);
        }
    }

    if (point >= abs(taxiM[a][b])) {winner = true;}
    else {
        winner = false;
        point = taxiM[a][b];
    }

    return winner;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1 < 0)|(e1 > 99)) {return -99;}
    checkInfo(exp1, 0, 600);
    checkInfo(exp2, 0, 600);
    if ((e1 >= 0)&(e1 < 4)){
        if      (e1 == 0)   {exp2+= 29;}
        else if (e1 == 1)   {exp2+= 45;}
        else if (e1 == 2)   {exp2+= 75;}
        else                {exp2+= 149;}

        int d = e1*3 + exp1*7;

        if      (d%2==0)    {exp1 = ceil(exp1 + float(d)/200.0);}
        else                {exp1 = ceil(exp1 - float(d)/100.0);}
    }else if ((e1 > 3)&(e1 < 100)){
        if      (e1 < 20)   {exp2+= ceil(e1/4.0 + 19.0);}
        else if (e1 < 50)   {exp2+= ceil(e1/9.0 + 21.0);}
        else if (e1 < 66)   {exp2+= ceil(e1/16.0 + 17.0);}
        else if (e1 < 80)   {
                exp2+= ceil((e1/4.0)+ 19.0);
                if (exp2 > 200){exp2+= ceil(e1/9.0 + 21.0);}
        }else{
                exp2+= ceil(e1/4.0 + 19.0);
                exp2+= ceil(e1/9.0 + 21.0);
                if (exp2 > 400){
                    exp2+= ceil(e1/16.0 + 17.0);
                    exp2 = ceil(exp2*1.15);
                }
        }
        exp1 -= e1;
    }

    checkInfo(exp1, 0, 600);
    checkInfo(exp2, 0, 600);

    return exp1 + exp2;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2 < 0)|(E2 > 99)) {return -99;}
    checkInfo (M1, 0, 3000);
    checkInfo (EXP1, 0, 600);
    checkInfo (HP1, 0, 666);
    double P1 = xacSuat(EXP1), P2 = path2(HP1, EXP1, M1, E2), P3 = path3(E2);
    if ((P1 == P2)&(P1 == P3)) {
        EXP1 = ceil(EXP1 - EXP1*0.25);
    }else {
        double P = (P1 + P2 + P3)/3;
        if (P < 0.5) {
            HP1 = ceil(HP1 - HP1*0.15);
            EXP1 = ceil(EXP1 + EXP1*0.15);
        }else {
            HP1 = ceil(HP1 - HP1*0.1);
            EXP1 = ceil(EXP1 + EXP1*0.2);
        }
    }
    checkInfo(HP1, 0, 666);
    checkInfo(EXP1, 0, 600);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int point = 0;
    if ((E3 < 0)|(E3 > 99)) {return -99;}
    checkInfo(HP1, 0, 666);
    checkInfo(EXP1, 0, 600);
    checkInfo(HP2, 0, 666);
    checkInfo(EXP2, 0, 600);
    if (matrix (E3, point)) {
        EXP1 = ceil(EXP1 + EXP1*0.12);
        HP1 = ceil(HP1 + HP1*0.1);
        EXP2 = ceil(EXP2 + EXP2*0.12);
        HP2 = ceil(HP2 + HP2*0.1);
    }else {
        EXP1 = ceil(EXP1 - EXP1*0.12);
        HP1 = ceil(HP1 - HP1*0.1);
        EXP2 = ceil(EXP2 - EXP2*0.12);
        HP2 = ceil(HP2 - HP2*0.1);
    }
    checkInfo(HP1, 0, 666);
    checkInfo(EXP1, 0, 600);
    checkInfo(HP2, 0, 666);
    checkInfo(EXP2, 0, 600);
    return point;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pass = s, s_e = email;
    s_e = s_e.substr(0, s_e.find("@"));
    string spec1 = "@#%$!",
           spec2 = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM@#%$!";
    bool SpecFind = false;
    int len = pass.length();
    if      (len < 8)     {return -1;}
    else if (len > 20)    {return -2;}
    if      (pass.find(s_e) != string::npos)   {return -(300 + pass.find(s_e));}
    for     (int i = 0; i < len; i++) {
        if ((pass[i] == pass[i + 1])&(pass[i]==pass[i+2])) {return -(400 + i);}
    }
    for     (int i = 0; i < spec1.length(); i++) {
        if (pass.find(spec1[i]) != -1)   {SpecFind = true;}
    }
    if (!SpecFind) {return -5;}
    for     (int i = 0; i < pass.length(); i++) {
        if (spec2.find(pass[i]) == -1)   {return i;}
    }
    return -10;
}


// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string pwds; int result1 = 0, result2 = 0, pwds_len = 0, dup;
    string pass[num_pwds], result;
    int theCORRECTpassword;

    //Khoi tao danh sach cac mat ma rieng biet
    for (int i = 0; i < num_pwds; i++) {
        dup = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (arr_pwds[i] == pass[j]) {
                dup += 1;
            }
        }
        if (dup == 0) {pass[i] = arr_pwds[i];}
    }

    for (int i = 0; i < num_pwds; i++) {
        pwds = pass[i];

        for (int j = 0; j < num_pwds; j++) {
            if (pwds == arr_pwds[j]) {result2 += 1;}
        }
        if (result2 > result1) {
            result1 = result2;
            pwds_len = pwds.length();
            result = pwds;
        }else if (result2 == result1) {
            if (pwds.length() > pwds_len) {
                result1 = result2;
                result = pwds;
                pwds_len = pwds.length();
            }
        }
        result2 = 0;
    }

    for (int i = 0; i < num_pwds; i++) {
        if (result == pass[i])  {theCORRECTpassword = i;}
    }
    return theCORRECTpassword;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
