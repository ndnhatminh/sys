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

//! Task 1
void checkinputtask1(int &a, int &b)
{
    if (a > 600) {a = 600;}
    if (a < 0) {a = 0;}
    if (b > 600) {b = 600;}
    if (b < 0) {b = 0;}
    return;
}

int firstMeet(int &EXP1, int &EXP2, int E1)
{
    if (E1 < 0 || E1 > 99) return -99;
    if (E1 >= 0 && E1 <= 3) {
        if (E1 == 0) {EXP2 += 29;}
        checkinputtask1(EXP1, EXP2);
        if (E1 == 1) {EXP2 += 45;}
        checkinputtask1(EXP1, EXP2);
        if (E1 == 2) {EXP2 += 75;}
        checkinputtask1(EXP1, EXP2);
        if (E1 == 3) {EXP2 += (29+45+75);}
        checkinputtask1(EXP1, EXP2);
        int D = E1*3 + EXP1*7;
        if (D%2 == 0) {
            EXP1 = ceil(EXP1 + (double(D)/200));
            checkinputtask1(EXP1, EXP2);
        }
        if (D%2 == 1) {
            EXP1 = ceil(EXP1 - (double(D)/100));
            checkinputtask1(EXP1, EXP2);
        }
    }

    if (E1 >= 4 && E1 <= 99) {
        if (E1 <= 19) {EXP2 += ceil(double(E1)/4 + 19); checkinputtask1(EXP1, EXP2);}
        if (E1 <= 49 && E1 > 19) {EXP2 += ceil(double(E1)/9 + 21); checkinputtask1(EXP1, EXP2);}
        if (E1 <= 65 && E1 > 49) {EXP2 += ceil(double(E1)/16 + 17); checkinputtask1(EXP1, EXP2);}
        if (E1 <= 79 && E1 > 65) {
            EXP2 += ceil(double(E1)/4 + 19);
            checkinputtask1(EXP1, EXP2);
            if (EXP2 > 200) {
                EXP2 += ceil(double(E1)/9 + 21);
                checkinputtask1(EXP1, EXP2);
            }
        }
        if (E1 <= 99 && E1 > 79) {
            EXP2 += ceil(double(E1)/4 + 19);
            checkinputtask1(EXP1, EXP2);
            EXP2 += ceil(double(E1)/9 + 21);
            checkinputtask1(EXP1, EXP2);
            if (EXP2 > 400) {
                EXP2 = ceil(EXP2 + double(E1)/16 + 17);
                checkinputtask1(EXP1, EXP2);
                EXP2 = ceil(EXP2 + double(EXP2)*0.15);
                checkinputtask1(EXP1, EXP2);
            }
        }

        EXP1 -= E1;
        checkinputtask1(EXP1, EXP2);
    }

    checkinputtask1(EXP1, EXP2);

    return EXP1 + EXP2;
}


//! Task 2
void checkinputtask2(int &a, int &b, int &c)
{
    if (a > 666) {a = 666;}
    if (a < 0) {a = 0;}
    if (b > 600) {b = 600;}
    if (b < 0) {b = 0;}
    if (c > 3000) {c = 3000;}
    if (c < 0) {c = 0;}
}

int calculate_Nearest_Perfect_quare(int &d) {
    int S = sqrt(d);
    int lowerSquare = S * S;  
    int upperSquare = (S + 1) * (S + 1);  
    
    if (d - lowerSquare <= upperSquare - d) {
        return lowerSquare;
    } 
    else {
        return upperSquare;
    }
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 < 0 || E2 > 99) return -99;
    checkinputtask2(HP1, EXP1, M1);
    double P, P1, P2, P3;

    //first.road
    int S1 = calculate_Nearest_Perfect_quare(EXP1);
    if (EXP1 >= S1) {P1 = 100;}
    else {P1 = (((double(EXP1)/double(S1)) + 80)/123)*100;}

    //second.road
    double SUM = 0;
    double M0 = (double(M1)/2);

    while ((E2 % 2) != 0) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 + double(HP1)*0.3);
            M1 -= 150;
            SUM += 150;
            checkinputtask2(HP1, EXP1, M1);
        }
        else {
            HP1 = ceil(HP1 + double(HP1)*0.1);
            M1 -= 70;
            SUM += 70;
            checkinputtask2(HP1, EXP1, M1);
        }
        if (SUM > M0) {break;}

        if (EXP1 < 400) {
            M1 -= 200;
            SUM += 200;
            EXP1 = ceil(EXP1 + double(EXP1)*0.13);
            checkinputtask2(HP1, EXP1, M1);
        }
        else {
            M1 -= 120;
            SUM += 120;
            EXP1 = ceil(EXP1 + double(EXP1)*0.13);
            checkinputtask2(HP1, EXP1, M1);
        }
        if (SUM > M0) {break;}

        if (EXP1 < 300) {
            M1 -= 100;
            SUM += 100;
            EXP1 = ceil(EXP1 - double(EXP1)*0.1);
            checkinputtask2(HP1, EXP1, M1);
        }
        else {
            M1 -= 120;
            SUM += 120;
            EXP1 = ceil(EXP1 - double(EXP1)*0.1);
            checkinputtask2(HP1, EXP1, M1);
        }
        if (SUM > M0) {break;}

    }


    while ((E2 % 2) == 0) {

        if (M1 == 0) {break;}

        if (HP1 < 200) {
            HP1 = ceil(HP1 + double(HP1)*0.3);
            M1 -= 150;
            SUM += 150;
            checkinputtask2(HP1, EXP1, M1);
        }
        else {
            HP1 = ceil(HP1 + double(HP1)*0.1);
            M1 -= 70;
            SUM += 70;
            checkinputtask2(HP1, EXP1, M1);
        }
        if (M1 == 0) {break;}

        if (EXP1 < 400) {
            M1 -= 200;
            SUM += 200;
            EXP1 = ceil(EXP1 + double(EXP1)*0.13);
            checkinputtask2(HP1, EXP1, M1);
        }
        else {
            M1 -= 120;
            SUM += 120;
            EXP1 = ceil(EXP1 + double(EXP1)*0.13);
            checkinputtask2(HP1, EXP1, M1);
        }
        if (M1 == 0) {break;}

        if (EXP1 < 300) {
            M1 -= 100;
            SUM += 100;
            EXP1 = ceil(EXP1 - double(EXP1)*0.1);
            checkinputtask2(HP1, EXP1, M1);
        }
        else {
            M1 -= 120;
            SUM += 120;
            EXP1 = ceil(EXP1 - double(EXP1)*0.1);
            checkinputtask2(HP1, EXP1, M1);
        }
        break;
    }

    HP1 = ceil(HP1 - double(HP1)*0.17);
    EXP1 = ceil(EXP1 + double(EXP1)*0.17);
    checkinputtask2(HP1, EXP1, M1);

    int S2 = calculate_Nearest_Perfect_quare(EXP1);
    if (EXP1 >= S2) {P2 = 100;}
    else {P2 = (((double(EXP1)/double(S2)) + 80)/123)*100;}

    //third.road
    int arrP3[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 < 10) {i = E2;}
    else {i = (E2/10 + E2%10)%10;}
    P3 = arrP3[i];

    if (P1 == 100 && P2 == 100 && P3 == 100 ) {
        EXP1 = ceil(EXP1 - double(EXP1)*0.25);
        checkinputtask2(HP1, EXP1, M1);
    }
    else {
        P = (P1 + P2 + P3)/3;
        if (P < 50) {
            HP1 = ceil(HP1 - double(HP1)*0.15);
            EXP1 = ceil(EXP1 + double(EXP1)*0.15);
            checkinputtask2(HP1, EXP1, M1);
        }
        else {
            HP1 = ceil(HP1 - double(HP1)*0.1);
            EXP1 = ceil(EXP1 + double(EXP1)*0.2);
            checkinputtask2(HP1, EXP1, M1);
        }
        }
    checkinputtask2(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}


//! Task 3
void checkinputtask3(int &a, int &b, int &c, int &d)
{
    if (a > 666) {a = 666;}
    if (a < 0) {a = 0;}
    if (b > 600) {b = 600;}
    if (b < 0) {b = 0;}
    if (c > 666) {c = 666;}
    if (c < 0) {c = 0;}
    if (d > 600) {d = 600;}
    if (d < 0) {d = 0;}
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) return -99;
    checkinputtask3(HP1, EXP1, HP2, EXP2);
    int ROW = 10;
    int COL = 10;

    //ma trận của taxi
    int arr_taxi[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            arr_taxi[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }

    //ma trận của S và W
    int arr_main[ROW][COL];
    for (int b = 0; b < COL; b++) {
        for (int a = 0; a < ROW; a++) {
            int max_cheotrai = 0;
            int max_cheophai = 0;

            //tìm max chéo trái
            for (int i = 0; (a-i) >= 0 && (b-i) >= 0; i++) {
                if (arr_taxi[a-i][b-i] > max_cheotrai) {
                    max_cheotrai = arr_taxi[a-i][b-i]; //max chéo trái trên
                }
            }
            for (int i = 0; (a+i) < 10 && (b+i) < 10; i++) {
                if (arr_taxi[a+i][b+i] > max_cheotrai) {
                    max_cheotrai = arr_taxi[a+i][b+i]; //max chéo trái dưới
                }
            }

            //tìm max chéo phải
            for (int i = 0; (a-i) >= 0 && (b+i) < 10; i++) {
                if (arr_taxi[a-i][b+i] > max_cheophai) {
                    max_cheophai = arr_taxi[a-i][b+i]; //max chéo phải trên
                }
            }
            for (int i = 0; (a+i) < 10 && (b-i) >= 0; i++) {
                if (arr_taxi[a+i][b-i] > max_cheophai) {
                    max_cheophai = arr_taxi[a+i][b-i]; //max chéo phải dưới
                }
            }

            //so sánh chéo trái & phải
            if (max_cheotrai > max_cheophai) {
                arr_main[a][b] = max_cheotrai;
            }
            if (max_cheotrai <= max_cheophai) {arr_main[a][b] = max_cheophai;}
        }    
    }
    
    int counti = 0;
    int countj = 0;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (arr_taxi[i][j] > E3*2) {counti ++;}
            if (arr_taxi[i][j] < (-(E3))) {countj ++;}
        }
    }

    if (counti >= 10) {counti = counti/10 + counti%10;} 
    if (counti >= 10) {counti = counti/10 + counti%10;} 
    if (countj >= 10) {countj = countj/10 + countj%10;}
    if (countj >= 10) {countj = countj/10 + countj%10;}



    if (abs(arr_taxi[counti][countj]) > arr_main[counti][countj]) {
        HP1 = ceil(HP1 - double(HP1)*0.1);
        EXP1 = ceil(EXP1 - double(EXP1)*0.12);
        HP2 = ceil(HP2 - double(HP2)*0.1);
        EXP2 = ceil(EXP2 - double(EXP2)*0.12);
        checkinputtask3(HP1, EXP1, HP2, EXP2);
        return arr_taxi[counti][countj];
    }

    else {
        HP1 = ceil(HP1 + double(HP1)*0.1);
        EXP1 = ceil(EXP1 + double(EXP1)*0.12);
        HP2 = ceil(HP2 + double(HP2)*0.1);
        EXP2 = ceil(EXP2 + double(EXP2)*0.12);
        checkinputtask3(HP1, EXP1, HP2, EXP2);
        return arr_main[counti][countj];
    }
}


//! Task 4
int checkPassword(const char *s, const char *email)
{
    //Vị trí của '@' trong mail
    int char_mail = -1;
    for (int i = 0; email[i] != '\0'; i++) {
        if (email[i] == '@') {
            char_mail = i;
            break;
        }
    }

    //Lấy substring se từ mail
    char se[101];
    strncpy(se, email, char_mail);
    se[char_mail] = '\0';

    //Độ dài mật khẩu
    int passLength = strlen(s);
    if (passLength < 8) 
        return -1;
    if (passLength > 20) 
        return -2;

    //Kiểm tra string se
    const char *found = strstr(s, se);
    if (found != NULL) 
        return -(300 + (found - s));

    //Hơn 2 ký tự liên tiếp giống nhau
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2])
            return -(400 + i);
    }

    //Ký tự đặc biệt
    bool special_char = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
            special_char = true;
    }
    if (!special_char)
        return -5;

    //Điều kiện khác
    for (int i = 0; s[i] != '\0'; i++) {
        if (!(isdigit(s[i]) || islower(s[i]) || isupper(s[i]) || 
            s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))
            return i;
    }

    return -10;
}


//! Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_appear = 0;
    int max_length = 0;
    int value = 0;
    int count = -1;
    int strlength = -1;

    //Vòng lặp lồng
    for (int i = 0; i < num_pwds; i++) {
        const char *string = arr_pwds[i];
        strlength = strlen(string);
        count = 1;

        for (int j = i; j < num_pwds; j++) {

            //xác định số lần xuất hiện
            if (strcmp (string, arr_pwds[j]) == 0) {
                count++;
            }

            //xuất hiện nhiều nhất
            if (count > max_appear) {
                max_appear = count;
                max_length = strlength;
                value = i;
            }

            //so sánh độ dài nếu xuất hiện = nhau
            if (count == max_appear && strlength > max_length) {
                max_appear = count;
                max_length = strlength;
                value = i;
            }
        }
    }

    return value;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////