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
int firstMeet(int &EXP1, int &EXP2, int E1) {
    if (E1 < 0 || E1 > 99) return -99;
    
    EXP1 = max(0, min(EXP1, 600)); // Sherlock exp
    EXP1 = ceil(EXP1);
    
    EXP2 = max(0, min(EXP2, 600)); // Watson exp
    EXP2 = ceil(EXP2);
    
    // Begin case 1 
if (E1 >= 0 && E1 <= 3) {
    if (E1 == 0) {
        EXP2 += 29;
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
    } else if (E1 == 1) {
        EXP2 += 45;
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
    } else if (E1 == 2) {
        EXP2 += 75;
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
    } else if (E1 == 3) {
        EXP2 += 149;
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
    }

int D = (E1 * 3 + EXP1 * 7);
if (D % 2 == 0) {
    EXP1 += float(D) / 200.0;
    EXP1 = max(0, min(EXP1, 600)); // Sherlock exp
    EXP1 = ceil(EXP1);
} else {
    EXP1 -= D / 100.0;
    EXP1 = max(0, min(EXP1, 600)); // Sherlock exp
    EXP1 = ceil(EXP1 + 1e-9);
}

}
    // End case 1

    // Begin case 2
if (E1 >= 4 && E1 <= 99) {
    bool condition1 = false;
    bool condition2 = false;
    bool condition3 = false;

    if (E1 >= 4 && E1 <= 19) {
        EXP2 += ceil(float(E1)/4.0 + 19.0);
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);

    } else if (E1 >= 20 && E1 <= 49) {
        EXP2 += ceil(float(E1)/9.0 + 21.0);
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);

    } else if (E1 >= 50 && E1 <= 65) {
        EXP2 += ceil(float(E1)/16.0 + 17.0);
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
        condition3 = true; // info3

    } else if (E1 >= 66 && E1 <= 79) {
        EXP2 += ceil(float(E1)/4.0 + 19.0); // info1
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2); 
        if (EXP2 > 200) {
            EXP2 += ceil(E1/9.0 + 21.0);
            EXP2 = max(0, min(EXP2, 600)); // Watson exp
            EXP2 = ceil(EXP2);
            condition2 = true; // info4 -> info2
        }
    } else if (E1 >= 80 && E1 <= 99) {
        EXP2 += ceil(float(E1)/4 + 19);
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
        condition1 = true;
        EXP2 += ceil(float(E1)/9 + 21);
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
        condition2 = true;
        if (EXP2 > 400) {
            EXP2 += ceil(float(E1)/16 + 17);
            EXP2 = max(0, min(EXP2, 600)); // Watson exp
            EXP2 = ceil(EXP2);
            condition3 = true; // info5 -> info3
        }
    }

    if (condition1  && condition2  && condition3 ) {
        EXP2 = ceil(EXP2 * 1.15);
        EXP2 = max(0, min(EXP2, 600)); // Watson exp
        EXP2 = ceil(EXP2);
    }

    EXP1 -= ceil(E1);
    EXP1 = max(0, min(EXP1, 600)); // Sherlock exp
    EXP1 = ceil(EXP1);
    EXP2 = max(0, min(EXP2, 600)); // Watson exp
    EXP2 = ceil(EXP2);

}
return EXP1 + EXP2;
}

// Task 2
double calculateProbability(int EXP1) {
    int S = pow(round(sqrt(EXP1)), 2); // nearest perfect square to EXP1
    double P;
    if (EXP1 >= S) {
        P = 1.0; // 100% probability
    } else {
        P = (EXP1 / static_cast<double>(S) + 80) / 123;
    }
    return P;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    HP1 = max(0, min(HP1, 666)); //Sherlock hp
    HP1 = ceil(HP1);

    EXP1 = max(0, min(EXP1, 600)); //Sherlock exp
    EXP1 = ceil(EXP1);

    M1 = max(0, min(M1, 3000)); //Sherlock money
    M1 = ceil(M1);

    //START ROAD 1
    double P1 = calculateProbability(EXP1);
    //END ROAD 1

    //START ROAD 2
    int initialM1 = M1; // store the initial money for checking 50% condition
    do {
    int nextM1;

    if (HP1 < 200.0) {
        HP1 = ceil(HP1 * 1.3f);
        nextM1 = M1 - 150;
        M1 = nextM1;
        if (nextM1 < initialM1 / 2) break; 
    } else {
        HP1 = ceil(HP1 * 1.1f);
        nextM1 = M1 - 70;
        M1 = nextM1;
        if (nextM1 < initialM1 / 2) break; 
    }

    if (EXP1 < 400.0) {
        EXP1 = ceil(EXP1 * 1.13f);
        nextM1 = M1 - 200; 
        M1 = nextM1;
        if (nextM1 < initialM1 / 2) break;
    } else {
        EXP1 = ceil(EXP1 * 1.13f);
        nextM1 = M1 - 120; 
        M1 = nextM1;
        if (nextM1 < initialM1 / 2) break;
    }

    if (EXP1 < 300.0) {
        EXP1 = ceil(EXP1 * 0.9);
        nextM1 = M1 - 100;
        M1 = nextM1;
        if (nextM1 < initialM1 / 2) break;
    } else {
        EXP1 = ceil(EXP1 * 0.9);
        nextM1 = M1 - 120;
        M1 = nextM1;
        if (nextM1 < initialM1 / 2) break;
    }

    // if E2 is even, break the loop
    if (E2 % 2 == 0) {
        break;
    }
} while (M1 > 0); // repeat until money is exhausted

    // After walking to the end of the road
    HP1 = ceil(HP1 * 0.83);
    HP1 = max(0, min(HP1, 666));
    EXP1 = ceil(EXP1 * 1.17); 
    EXP1 = max(0, min(EXP1, 600));

    double P2 = calculateProbability(EXP1);
    
    //START ROAD 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // probability values
    int i; // index value of the probability
    if (E2 < 10) { // if E2 is a one-digit number
        i = E2;
    } else { // if E2 is a two-digit number
        i = (E2 / 10 + E2 % 10) % 10; // sum of the two digits and take the unit place
    }
    double P3 = P[i] / 100.0; 
    //END ROAD 3

    if (P1 == 1.0 && P2 == 1.0 && P3 == 1.0) {
        EXP1 = ceil(EXP1 * 0.75); 
    } else {
        double P_final = (P1 + P2 + P3) / 3.0;
        if (P_final < 0.5) {
            HP1 = ceil(HP1 * 0.85f); 
            EXP1 = ceil(EXP1 * 1.15f);
            EXP1 = max(0, min(EXP1, 600));
        } else {
            HP1 = ceil(HP1 * 0.9f); 
            EXP1 = ceil(EXP1 * 1.2f); 
            EXP1 = max(0, min(EXP1, 600));
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
void TaxiValue(int Arr1[10][10], int E3) { 
        for (int j = 0; j < 10; ++j) {
            for (int i = 0; i < 10; ++i ) {
                Arr1[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }
    }

//Tìm gtri lớn nhất cho Sherlock
int SherlockMax(int Arr1[10][10], int i, int j) {  
        int MaxValue = Arr1[i][j];
        
        int x = i, y = j;
        
        //ktra gtri đường chéo trái
        while (x >= 0 && y >= 0) {
            MaxValue = max(MaxValue, Arr1[x][y]);
            --x; --y;
        }

        x = i + 1, y = j + 1;
        while (x < 10 && y < 10) {
            MaxValue = max(MaxValue, Arr1[x][y]);
            ++x; ++y;
        }
        
        //ktra gtri đường chéo phải
        x = i, y = j;
        while (x < 10 && y >= 0) {
            MaxValue = max(MaxValue, Arr1[x][y]);
            ++x; --y;
        }

        x = i - 1, y = j;
        while (x >= 0 && y < 10) {
            MaxValue = max(MaxValue, Arr1[x][y]);
            --x; ++y;
        }

        return MaxValue;
    }


int SumDigit(int num) { //cộng giá trị các phần tử
        int sum = 0; 
        while (num >= 10) {
            sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum; 
        }
        return num;
    }



int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) return -99;

    HP1 = max(0, min(HP1, 666)); //Sherlock hp
    HP1 = ceil(HP1);

    HP2 = max(0, min(HP2, 666)); //Watson hp
    HP2 = ceil(HP2);

    EXP1 = max(0, max(EXP1, 600)); //Sherlock exp
    EXP1 = ceil(EXP1);

    EXP2 = max(0, min(EXP2, 600)); //Watson exp
    EXP2 = ceil(EXP2);

    int Arr1[10][10] = {0}; //tạo array 10x10 cho taxi
    TaxiValue(Arr1, E3);
    
    int GreaterValue = 0;
    int LowerValue = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            
            if (Arr1[i][j] > E3 * 2) { //tìm số lượng ô > E3 * 2
            ++GreaterValue;
            }
            
            if (Arr1[i][j] < -E3) { //tìm số lượng ô < -E3
            ++LowerValue;
            }
        }
    }

    
    GreaterValue = SumDigit(GreaterValue);
    LowerValue = SumDigit(LowerValue);

    int TaxiValue = Arr1[GreaterValue][LowerValue];
    int absTaxiValue = abs(Arr1[GreaterValue][LowerValue]);
    int SherlockMaxValue = SherlockMax(Arr1, GreaterValue, LowerValue);

    if (SherlockMaxValue < absTaxiValue) {
        EXP1 = ceil(EXP1 * 0.88);
        HP1 = ceil(HP1 * 0.9);
        EXP2 = ceil(EXP2 * 0.88);
        HP2 = ceil(HP2 * 0.9);
        return TaxiValue;
    } else {
        EXP1 = ceil(EXP1 * 1.12);
        HP1 = ceil(HP1 * 1.1);
        EXP2 = ceil(EXP2 * 1.12);
        HP2 = ceil(HP2 * 1.1);
        return SherlockMaxValue;
    }


    return -1;
}



// Task 4
int checkPassword(const char* s, const char* email) {
    //xuất se từ mail
    char* email_copy = new char[strlen(email) + 1];
    strcpy(email_copy, email);
    char* se = strtok(email_copy, "@");

    //số lượng ký tự của string
    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;

    //check nếu se có xuất hiện trong pass
    if (strstr(s, se) != nullptr) return -(300 + (strstr(s, se) - s));

    //check ký tự trùng trong pass
    for (int i = 0; i < len - 2; i++) {
        if (s[i] == s[i + 1] && s[i + 1] == s[i + 2]) return -(400 + i);
    }

    //check ký tự đặc biệt và ký tự ko hợp lệ
    bool hasSpecialChar = false;
    for (int i = 0; i < len; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
        } else if (!isalnum(s[i])) {
            return i;
        }
    }
    if (!hasSpecialChar) return -5;

    //thông qua các điều kiện để pass hợp lệ
    delete[] email_copy; //dọn bộ nhớ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int MostFreq = 0;
    int Longest = 0;

    const char * CorrectPwd = NULL; //hàm để chứa dòng pass dài nhất
    
    for(int i = 0; i < num_pwds; i++) { //xét các dãy string và tìm kiếm
        int Freq = 0;
        for(int j = 0; j < num_pwds; j++) { //so sánh string hiện tại so với các string khác
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                Freq++;
            }
        }
        int len = strlen(arr_pwds[i]); //số lượng ký tự của string
        
        if(Freq > MostFreq || (Freq == MostFreq && len > Longest)) { 
            MostFreq = Freq;
            Longest = len;
            CorrectPwd = arr_pwds[i];
        }
    }

    if(CorrectPwd == NULL) { //trả về -1 nếu không có pass hợp lệ
        return -1;  
    }

    for(int i = 0; i < num_pwds; i++) { //tìm index
        if(strcmp(arr_pwds[i], CorrectPwd) == 0) {
            return i;
        }
    }

    return -1; 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////