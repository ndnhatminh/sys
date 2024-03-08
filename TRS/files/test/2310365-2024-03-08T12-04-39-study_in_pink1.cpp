#include "study_in_pink1.h"

bool readFile(
    const string& filename,
    int& HP1,
    int& HP2,
    int& EXP1,
    int& EXP2,
    int& M1,
    int& M2,
    int& E1,
    int& E2,
    int& E3
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

//Ham lam tron len
void lam_tron(int& a, double b) {
    a = a * b + 0.999999;
}
int firstMeet(int& exp1, int& exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1>99) return -99;
    if (e1 >= 0 && e1 <= 3) {
        if (e1 == 0) exp2 += 29;
        else if (e1 == 1) exp2 += 45;
        else if (e1 == 2) exp2 += 75;
        else if (e1 == 3) exp2 += 29 + 45 + 75;
        if ((e1 * 3 + exp1 * 7) % 2 == 0) { 

            exp1 = ceil(exp1 + ((e1 * 3 + exp1 * 7) * 1.0) / 200);
            
        }
        else { 
            exp1 = ceil(exp1 - ((e1 * 3 + exp1 * 7) * 1.0) / 100);
            
        }
        
    }
    if (e1 >= 4 && e1 <= 99) {
        if (e1 >= 4 && e1 <= 19) exp2 = ceil(exp2 + (e1 *1.0)/ 4 + 19);
        else if (e1 <= 49) exp2 = ceil(exp2 + (e1*1.0) / 9 + 21);
        else if (e1 <= 65) exp2 = ceil(exp2 + (e1*1.0) / 16 + 17);
        else if (e1 <= 79) {
            exp2 = ceil(exp2 + (e1*1.0) / 4 + 19);
            
            if (exp2 > 200) exp2 = ceil(exp2 + (e1*1.0) / 9 + 21);
        }
        else if (e1 <= 99) {
            exp2 = ceil(exp2 + (e1*1.0) / 4 + 19 + (e1*1.0) / 9 + 21);
            
            if (exp2 > 400) {
                exp2 = ceil(exp2 + (e1 * 1.0) / 16 + 17);
                
                //exp2 = ceil(exp2 * 1.15 );
                lam_tron(exp2, 1.15);
                
            }

        }
        exp1 -= e1;
        
    }
    if (exp2 > 600) exp2 = 600;
    if (exp2 < 0) exp2 = 0;
    if (exp1 > 600) exp1 = 600;
    if (exp1 < 0) exp1 = 0;
    return exp1 + exp2;
}

// Task 2
// Tim So chinh phuong gan nhat
int S_lon(int S) {
    while (1) {
        for (int i = 1; i <= S; i++)
            if (S * 1.0 / i == i) return S;
        S++;
    }

}
int S_nho(int S) {
    while (1) {
        for (int i = 1; i <= S; i++)
            if (S * 1.0 / i == i) return S;
        S--;
    }
}
int S_gan(int S) {
    if ((S_lon(S) - S) < (S - S_nho(S)))
        return S_lon(S);
    else return S_nho(S);

}
//Viec 1
void V1(int& HP1, int& M1) {
    if (HP1 < 200) {
        //HP1 = ceil(HP1 * 1.3); 
        lam_tron(HP1, 1.3);
        M1 -= 150;
    }
    else {
        //HP1 = ceil(HP1 * 1.1);
        lam_tron(HP1, 1.1);
        M1 -= 70;
    }
    if (M1 < 0) M1 = 0;
    if (HP1 > 666) HP1 = 666;
}
//Viec 2
    void V2(int& EXP1, int& M1) {
        if (EXP1 < 400) M1 -= 200;
        else M1-=120;

        //EXP1 = ceil(EXP1 * 1.13);
        lam_tron(EXP1, 1.13);

        if (M1 < 0) M1 = 0;
        if (EXP1 > 600) EXP1 = 600;
    }
//Viec 3
    void V3(int& EXP1, int& M1) {
        if (EXP1 < 300) M1 -= 100;
        else M1 -= 120;

        //EXP1 = ceil(EXP1 * 0.9);  
        lam_tron(EXP1, 0.9);

        if (M1 < 0) M1 = 0;
        if (EXP1 > 600) EXP1 = 600;
    }

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // TODO: Complete this function
if (E2 < 0 || E2>99) return -99;
if (EXP1 > 600) EXP1 = 600;
if (EXP1 < 0) EXP1 = 0;
if (HP1 > 666) HP1 = 666;
if (HP1 < 0) HP1 = 0;
    // D1
    double P1, P2, P3;
    int T = (M1*1.0)/2;
    if (EXP1 == 0|| EXP1 >= S_gan(EXP1)) P1 = 100;
    else P1 = ((EXP1*1.0)/S_gan(EXP1)+80)/1.23;
    //D2
    if (M1 > 3000) M1 = 3000;
    if (E2 % 2 == 0) {
        V1(HP1, M1);
        if (M1 > 0) {
            V2(EXP1, M1);
            if (M1 > 0) V3(EXP1, M1);
        };
        
    }
    else {

        for (M1; M1 > T;) {
            V1(HP1, M1);
            if (M1 < T) break;
            V2(EXP1, M1);
            if (M1 < T) break;
            V3(EXP1, M1);
            if (M1 < T) break;
        }

    }
    
    //HP1 = ceil(HP1 * 0.83);
    lam_tron(HP1, 0.83);
    //EXP1 = ceil(EXP1 * 1.17);   
    lam_tron(EXP1, 1.17);

    if (EXP1 > 600) EXP1 = 600;

    if (EXP1 == 0 || EXP1 >= S_gan(EXP1)) P2 = 100;
    else P2 = ((EXP1 * 1.0) / S_gan(EXP1) + 80) / 1.23;

//D3
    int P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11 };
    if (E2 < 10 && E2 >= 0) P3 = P[E2];
    else P3 = P[(E2/10+E2%10)%10];

//Xac suat
    if (P1 == 100 && P2 == 100 && P3 == 100) 
        
        //EXP1 = ceil(EXP1 * 0.75);
        lam_tron(EXP1, 0.75);

    else if (((P1 + P2 + P3) / 3) < 50) {

        //HP1 = ceil(HP1 * 0.85);
        lam_tron(HP1, 0.85);

        //EXP1 = ceil(EXP1 * 1.15);
        lam_tron(EXP1, 1.15);
    }
    else {

        //HP1 = ceil(HP1 * 0.9);
        lam_tron(HP1, 0.9);

        //EXP1 = ceil(EXP1 * 1.2);   
        lam_tron(EXP1, 1.2);
    }

    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
    return HP1 + EXP1 + M1;
}

// Task 3
// ham max
int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3>99) return -99;
    int m = 0, n = 0;
    int arr[10][10];
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > E3 * 2) m++;
            if (arr[i][j] < -E3) n++;
        }
    while (m > 9) m = (m / 10 + m % 10);
    while (n > 9) n = (n / 10 + n % 10);
    int max1, max2, Diemso;
    max1 = arr[m][n];
    max2 = arr[m][n];
    //duong cheo trai
    if (m == n)
        for (int i = 0, j = 0; i <= 9 && j <= 9; i++, j++)
            max1 = max(max1, arr[i][j]);

    else if (m < n)
        for (int i = 0, j = n - m; i <= 9 && j <= 9; i++, j++)
            max1 = max(max1, arr[i][j]);

    else
        for (int i = m - n, j = 0; i <= 9 && j <= 9; i++, j++)
            max1 = max(max1, arr[i][j]);



    //duong cheo phai
    if (m + n <= 9)
        for (int i = 0, j = m + n; i <= 9 && j >= 0; i++, j--)
            max2 = max(arr[i][j], max2);

    else for (int i = m + n - 9, j = 9; i <= 9 && j >= 0; i++, j--)
        max2 = max(arr[i][j], max2);

    Diemso = abs(max(max1, max2));
    if (abs(arr[m][n]) > Diemso) {

        //EXP1 = ceil(EXP1 * 0.88);  
        lam_tron(EXP1, 0.88);

        //HP1 = ceil(HP1 * 0.9);   
        lam_tron(HP1, 0.9);

        //EXP2 = ceil(EXP2 * 0.88);   
        lam_tron(EXP2, 0.88);


        //HP2 = ceil(HP2 * 0.9);
        lam_tron(HP2, 0.9);
    }
    else {

        //EXP1 = ceil(EXP1 * 1.12);
        lam_tron(EXP1, 1.12);

        //HP1 = ceil(HP1 * 1.1);
        lam_tron(HP1, 1.1);

        //EXP2 = ceil(EXP2 * 1.12);
        lam_tron(EXP2, 1.12);

        //HP2 = ceil(HP2 * 1.1);
        lam_tron(HP2, 1.1);
        
    }
    if (EXP1 > 600) EXP1 = 600;
    if (HP1 > 666) HP1 = 666;
    if (EXP2 > 600) EXP2 = 600;
    if (HP2 > 666) HP2 = 666;

    if (abs(arr[m][n]) > Diemso) return arr[m][n];
    else return Diemso;
}

// Task 4
int checkPassword(const char* s, const char* email) {
    // TODO: Complete this function
    char  se[100] = {};

    for (int i = 0; i < strlen(email); i++)
        if (email[i] == '@') {
            for (int n = 0; n < i; n++) se[n] = email[n];
            break;
        }
    //DK1:chieu dai
    if (strlen(s) < 8) return -1;
    else if (strlen(s) > 20) return -2;

    //DK2: s chua se
    const char* p = strstr(s, se);
    if (p != nullptr)
        return -(300 + (p - s));

    //DK3: ky tu giong nhau
    for (int i = 0; i < strlen(s) - 2; i++)
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
        
            return -(400 + (i));
        
    //DK4: chuoi co chua ky tu dac biet
    const char* kyTuDacBiet = "!@#$%";
    int KTDB = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (strchr(kyTuDacBiet, s[i]) != nullptr)
            KTDB++;
    }
    if (KTDB == 0) return -5;
    //DK5: ky tu vi pham
    int index = 0;
    while (*s != '\0') {
        if (!isdigit(*s) && !isalpha(*s) && *s != '!' && *s != '@' && *s != '#' && *s != '$' && *s != '%') {
            return index;
        }
        s++;
        index++;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int m = 0;
    const char** b = new const char* [num_pwds];
    int c[30];
    b[m] = arr_pwds[0];
    m++;
    for (int i = 1; i < num_pwds; i++) {
        bool KT = true;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr_pwds[i] == arr_pwds[j]) {
                KT = false;
                break;

            }

        }
        if (KT) {
            b[m] = arr_pwds[i];
            m++;

        }
    }


    for (int i = 0; i < m; i++) {
        int n = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (b[i] == arr_pwds[j]) n++;

        }
        c[i] = n;
    }

    int max = c[0];
    const char* lon = {};
    lon = b[0];
    for (int i = 0; i < m; i++)
    {
        if (c[i] > max) {
            lon = b[i];
            max = c[i];
        }
        else if (c[i] == max)
            if (strlen(lon) < strlen(b[i])) {
                lon = b[i];
                max = c[i];
            }


    }
    for (int i = 0; i < num_pwds; i++)
        if (lon == arr_pwds[i])
        {
            return i;
        }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////