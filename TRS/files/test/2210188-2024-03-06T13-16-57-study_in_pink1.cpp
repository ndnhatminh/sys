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
 int check(int &n, int firstpoint, int lastpoint) {
     if (n > lastpoint)
         n = lastpoint;
    else if (n < firstpoint)
        n = firstpoint;
     return n;
    
 }
 
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    // kiem tra dau vao
    if (e1 < 0 || e1 > 99) return -99;
    int firstpoint = 0, lastpoint = 600;
    exp1 = check(exp1, firstpoint, lastpoint);
    exp2 = check(exp2, firstpoint, lastpoint);
    //==========cac bien===========================
    float inform2_1, inform2_2, inform2_3;
    inform2_1 = e1 * 1.0000 / 4 + 19;
    inform2_2 = e1 * 1.0000 / 9 + 21;
    inform2_3 = e1 * 1.0000 / 16 + 17;
    float EXP1_test = exp1; // use float var to caculate
    float EXP2_test = exp2;
    // Du doan cua selock
    bool case1;
    if (e1 <= 3) {
        case1 = 1;
    }
    else {
        case1 = 0;
    }



        if (case1) {
                switch (e1)
                {
                case 0:  exp2 = exp2 + 29; break;
                case 1:  exp2 = exp2 + 45; break;
                case 2:  exp2 = exp2 + 75; break;
                case 3:  exp2 = exp2 + 29 + 45 + 75; break;


                }
                exp2 = check(exp2, firstpoint, lastpoint);

                //caculate EXP1  (need to round up)
                int D = e1 * 3 + exp1 * 7;
                if (D % 2) EXP1_test =  EXP1_test = ceil(EXP1_test - D * 1.0000 / 100);
                else ceil(EXP1_test + D * 1.0000 / 200);
                exp1 = EXP1_test;

            }
        else {
            if (e1 >= 4 && e1 <= 19) // thông tin 1
            {
                EXP2_test += inform2_1;

            }
            else if (e1 >= 20 && e1 <= 49) //2
            {
                EXP2_test += inform2_2;

            }
            else if (e1 >= 50 && e1 <= 65) //3
            {
                EXP2_test += inform2_3;
            }
            else if (e1 >= 66 && e1 <= 79) //4
            {
                EXP2_test = ceil(EXP2_test + inform2_1); // add inform2_1 and roundup value and check value
                exp2 = EXP2_test;                         // convert to int to check value
                exp2 = check(exp2, firstpoint, lastpoint);
                EXP2_test = exp2; //return EXP2 to EXP2_test to continue caculate
                if (EXP2_test > 200) EXP2_test += inform2_2;
            }
            else if (e1 >= 80 && e1 <= 99) //5
            {
                exp2 = exp2 + ceil(inform2_1);
                exp2 = check(exp2, firstpoint, lastpoint);
                exp2 = exp2 + ceil(inform2_2);
                exp2 = check(exp2, firstpoint, lastpoint);
                EXP2_test = exp2;
                if (EXP2_test > 400) {
                    EXP2_test = ceil(EXP2_test + inform2_3);
                    exp2 = EXP2_test;                         // convert to int to check value
                    exp2 = check(exp2, firstpoint, lastpoint);
                    EXP2_test = exp2; //return EXP2 to EXP2_test to continue caculate
                    EXP2_test = EXP2_test * 1.1500;
                }
             }
            // round up EXP2
            EXP2_test = ceil(EXP2_test);
            exp2 = EXP2_test;
            //caculate EXP1 (need round up)
            EXP1_test = ceil(EXP1_test - e1);
            exp1 = EXP1_test;
        }
        //check the result
        exp1 = check(exp1, firstpoint, lastpoint);
        exp2 = check(exp2, firstpoint, lastpoint);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // kiem tra dau vao
    if (E2 < 0 || E2 > 99) return -99;
    check(EXP1, 0, 600);
    check(HP1, 0, 666);
    check(M1, 0, 3000);
    // con duong 1
    int S, S1, S2; 
    S1 = EXP1;
    S2 = EXP1;
    while (!(sqrt(S1) == trunc(sqrt(S1)))) { S1++; };
    while (!(sqrt(S2) == trunc(sqrt(S2)))) { S2--; };
    if (S1 - EXP1 < EXP1 - S2)
    {
        S = S1;
    }
    else
    {
        S = S2;
    }
    float  P1;
    if (EXP1 >= S)
            P1 = 1;
    else    P1 = (EXP1 * 1.0000 / S + 80) / 123;
    // Con đường 2
    double initial_M1 = M1; // Lưu số tiền ban đầu
    float HP1_test = HP1; // use float var to caculate
    float EXP1_test = EXP1; 
    while (true) {
        // Sự kiện 1: Mua thức ăn và nước uống
        if (HP1 < 200) {
            HP1 += ceil(0.3 * HP1);
            M1 -= 150;
        }
        else  {
            HP1 += ceil(0.1 * HP1);
            M1 -= 70;
        }
        check(HP1, 0, 666);
        check(M1, 0, 3000);
        if (M1 < 0.5 * initial_M1 || M1 <= 0) {
            break;
        }
        // Sự kiện 2: Thuê taxi hoặc xe ngựa
        if (EXP1 < 400) {
            EXP1 += ceil(0.13 * EXP1);
            M1 -= 200;
        }
        else  {
            EXP1 += ceil(0.13 * EXP1);
            M1 -= 120;
        }
        check(EXP1, 0, 600);
        check(M1, 0, 3000);
        if (M1 < 0.5 * initial_M1 || M1 <= 0) {
            break;
        }
        // Sự kiện 3: Giúp đỡ người vô gia cư
        if (EXP1 < 300) {
            EXP1 -= ceil(0.1 * EXP1);
            M1 -= 100;
        }
        else {
            EXP1 -= ceil(0.1 * EXP1);
            M1 -= 120;
        }
        check(EXP1, 0, 600);
        check(M1, 0, 3000);
        // Kiểm tra xem có thể tiếp tục các sự kiện hay không
        if (M1 < 0.5 * initial_M1 || E2 % 2 == 0) {
            break;
        }
    }

    // Đi bộ đến cuối con đường
    HP1  = ceil(HP1 - 0.17 * HP1);
    EXP1 = ceil(EXP1 + EXP1 * 0.17);
    S1 = EXP1;
    S2 = EXP1;
    while (!(sqrt(S1) == trunc(sqrt(S1)))) { S1++; };
    while (!(sqrt(S2) == trunc(sqrt(S2)))) { S2--; };
    if (S1 - EXP1 < EXP1 - S2)
    {
        S = S1;
    }
    else
    {
        S = S2;
    }
    float  P2;
    if (EXP1 >= S)
        P2 = 1;
    else    P2 = (EXP1 / S + 80) / 123;
    // Con đường 3
    float P[10] = { 3.2, 4.7, 2.8, 7.9, 1, 5.0, 2.2, 8.3, 6.4, 1.1 };
    float P3;
    if (E2 < 10)
         P3 = P[E2];
    else {
        int a = E2 / 10; // Chữ số thứ 1
        int b = E2 % 10; // Chữ số thứ 2
        int x = a + b; // Tổng hai chữ số
        if (x < 10)
            P3 = P[x];
        else P3 = P[x - 10];
    }
    // tong ket ca 3 tuyen duong
    if (P1 == 1 && P2 == 1 && P3 == 1)
        EXP1 -= ceil(EXP1 * 0.25);
    else if ((P1 + P2 + P3) / 3 < 0.5) {
        HP1 -= ceil(0.15 * HP1);
        EXP1 += ceil(0.15 * HP1);
    }
    else {
        HP1 -= ceil(0.1 * HP1);
        EXP1 += ceil(0.2 * HP1);
    }
    // kiem tra dau ra
    check(EXP1, 0, 600);
    check(HP1, 0, 666);
    check(M1, 0, 3000);





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
        string s_str(s);
        string email_str(email);
        string se = email_str.substr(0, email_str.find('@'));

        if (s_str.length() < 8) {
            return -1;
            }
            if (s_str.length() > 20) {
                return -2;
            }

        size_t found = s_str.find(se);
            if (found != string::npos) {
                return -(300 + static_cast<int>(found));
            }

        for (int i = 0; i < s_str.length() - 2; i++) {
            if (s_str[i] == s_str[i + 1] && s_str[i + 1] == s_str[i + 2]) {
                return -(400 + i);
            }
        }

        string special_chars = "@#%$!";
        found = string::npos;
        for (char c : special_chars) {
            found = s_str.find(c);
            if (found != string::npos) {
                break;
            }
        }
        if (found == string::npos) {
            return -5;
        }

        return -10;
    

    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
        int maxCount = 0;
        int maxLength = 0;
        const char* correctPassword = nullptr;

        for (int i = 0; i < num_pwds; ++i) {
            int count = 0;
            for (int j = 0; j < num_pwds; ++j) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    ++count;
                }
            }

            int length = 0;
            while (arr_pwds[i][length] != '\0') {
                ++length;
            }

            if (count > maxCount || (count == maxCount && length > maxLength)) {
                maxCount = count;
                maxLength = length;
                correctPassword = arr_pwds[i];
            }
        }

        for (int i = 0; i < num_pwds; ++i) {
            if (strcmp(arr_pwds[i], correctPassword) == 0) {
                return i;
            }
        }

        return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////