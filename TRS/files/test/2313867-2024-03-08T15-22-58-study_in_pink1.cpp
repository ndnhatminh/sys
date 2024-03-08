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

int roundUp(float number) {
    int d = (int)number;
    float t = number - d;
    if (t > 0.0)
    {
        return d + 1;
    }
    return d;
}

int validateExp(int exp) {
    if (exp > 600) {
        return 600;
    }

    if (exp < 0) {
        return 0;
    }

    return exp;
}

int validateE(int e) {
    if (e < 0 || e > 99)
    {
        return -99;
    }
    return e;
}

int validateHP(int hp) {
    if (hp > 666) {
        return 666;
    }

    if (hp < 0) {
        return 0;
    }
    return hp;
}

int validateM(int m) {
    if (m > 3000) {
        return 3000;
    }
    
    if (m < 0) {
        return 0;
    }

    return m;
}

// Task 1
int firstMeet(int &exp1, int &exp2, int e1) {
    float fexp1 = validateExp(exp1);
    float fexp2 = validateExp(exp2);
    float fe1 = validateE(e1);

    if (e1 < 0 || e1 > 99) {
        return -99;
    }

    int d;
    if (e1 == 0) {
        fexp2 += 29;
    }

    if (e1 == 1) {
        fexp2 += 45;
    }

    if (e1 == 2) {
        fexp2 += 75;
    }

    if (e1 == 3) {
        fexp2 += 29 + 45 + 75;
    }

    if (e1 >= 4 && e1 <= 19) {
        fexp2 += fe1 / 4 + 19;
    }

    if (e1 >= 20 && e1 <= 49) {
        fexp2 += fe1 / 9 + 21;
    }

    if (e1 >= 50 && e1 <= 65) {
        fexp2 += fe1 / 16 + 17;
    }

    if (e1 >= 66 && e1 <= 79) {
        fexp2 += fe1 / 4 + 19;
        fexp2 = (fexp2 <= 200) ? fexp2 : (fexp2 + fe1 / 9 + 21);
    }

    if (e1 >= 80 && e1 <= 99) {
        fexp2 += (fe1 / 4 + 19) + (fe1 / 9 + 21);
        if (fexp2 > 400) {
            fexp2 += fe1 / 16 + 17; // 5,06 + 17
            fexp2 *= 1.15; // 564,65 -> 565
        }
    }

    if (e1 < 4) {
        d = fe1 * 3 + fexp1 * 7;
        fexp1 = (d % 2 == 0) ? (fexp1 + d / 200) : (fexp1 - d / 100);
    }
    else {
        fexp1 -= fe1;
    }

    exp1 = roundUp(fexp1); 
    exp1 = validateExp(exp1); 

    exp2 = roundUp(fexp2); 
    exp2 = validateExp(exp2); 

    return exp1 + exp2;
}

// Task 2
int mission02_Way01(int &HP1, int &EXP1, int &M1, int E2) {
    float S;
    float p1_1, p1_2;
    int P1;
    float S1 = sqrt(EXP1);
    int S2 = round(S1);
    S = S2 * S2;
    p1_1 = (EXP1 >= S) ? 1 : ((EXP1 / S) + 80)/123;
    p1_1 = round(p1_1 * 100.0)/100.0;
    p1_2 = p1_1 * 100;
    P1 = round(p1_2);
    return P1;
}

void subWay02_01(int &HP1, int &M1) {
    float fHp1 = HP1;
    if (HP1 < 200) {
        fHp1 *= 1.13;
        M1 -= 150;
    } else {
        fHp1 *= 1.1;
        M1 -= 70;
    }
    HP1 = roundUp(fHp1); 
    HP1 = validateHP(HP1); 

    M1 = roundUp(M1); 
    M1 = validateM(M1);
}

void subWay02_02(int &EXP1, int &M1) {
    float fExp1 = EXP1;
    if (EXP1 < 400) {
        M1 -= 200;
    } else {
        M1 -= 120;
        fExp1 *= 1.13;
    }

    M1 = roundUp(M1); 
    M1 = validateM(M1);

    EXP1 = roundUp(fExp1); 
    EXP1 = validateExp(EXP1);
}

void subWay02_03(int &EXP1, int &M1) {
    float fExp1 = EXP1;
    if (EXP1 < 300) {
        M1 -= 100;
    } else {
        M1 -= 120;
    }
    fExp1 *= 0.9;

    M1 = roundUp(M1); 
    M1 = validateM(M1);

    EXP1 = roundUp(fExp1); 
    EXP1 = validateExp(EXP1);
}

int mission02_Way02(int &HP1, int &EXP1, int &M1, int E2) {
    float fExp1 = EXP1;
    float fHp1 = HP1;
    if (E2 % 2 != 0) {
        // M1 = 100
        int M1_bandau = M1 * 0.5; // 50% số tiền ban đầu -> 50
        while(1) {
            if (M1 <= M1_bandau) {
                break;
            }
            subWay02_01(HP1, M1); // M1 -> 80, M1->45
            
            if (M1 <= M1_bandau) {
                break;
            }
            subWay02_02(EXP1, M1); // M1 ->79

            if (M1 <= M1_bandau) {
                break;
            }
            subWay02_03(EXP1, M1); // M1 ->65
        }

    } else {
        if(M1 > 0) {
            subWay02_01(HP1, M1); // M1 -> 80, M1->45
        }

        if (M1 > 0) {
            subWay02_02(EXP1, M1); // M1 ->79
        }

        if (M1 > 0) {
            subWay02_03(EXP1, M1); // M1 ->65
        }
        
    }

    fHp1 = HP1 * 0.83;
    fExp1 = EXP1 * 1.17;

    HP1 = roundUp(fHp1); 
    HP1 = validateHP(HP1);

    EXP1 = roundUp(fExp1); 
    EXP1 = validateExp(EXP1);

    float S;
    float P2;
    float S1 = sqrt(EXP1);
    int S2 = round(S1);
    S = S2 * S2;
    float p2_1, p2_2;
    p2_1 = (EXP1 >= S) ? 1 : ((EXP1 / S) + 80)/123;
    p2_1 = round(p2_1 * 100.0)/100.0;
    p2_2 = p2_1 * 100;
    P2 = round(p2_2);
    return P2;
}

int mission02_Way03(int &HP1, int &EXP1, int &M1, int E3) {
    int arr[10]={32,47,28,79,100,50,22,83,64,11};
	int i; 
    float P3;
	if (E3 < 10) {
		 i = E3;
		 P3 = arr[i]; 
	}
	else {
		int hangchuc = E3 / 10;
		int hangdv = E3 % 10;
		int tong = hangchuc + hangdv;
		i = tong % 10;
		P3 = arr[i]; 
	} 
    return P3;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {

    int way01 = mission02_Way01(HP1, EXP1, M1, E2); // 65,8333% ->66% ->0,66
    int way02 = mission02_Way02(HP1, EXP1, M1, E2); // %
    int way03 = mission02_Way03(HP1, EXP1, M1, E2);

    float fExp1 = validateExp(EXP1);
    float fHp1 = validateExp(HP1);

    float p;
    if (way01 == way02 == way03 == 100 ) {
        fExp1 *= 0.75;
    } else {
        p = (way01 + way02 + way03) / 3;
    }
    if (p < 50) {
        fHp1 *= 0.85;
        fExp1 *=1.15;
    } else {
        fHp1 *= 0.9;
        fExp1 *= 1.2;
    }
    HP1 = roundUp(fHp1); 
    HP1 = validateHP(HP1);

    EXP1 = roundUp(fExp1); 
    EXP1 = validateExp(EXP1);

    M1 = validateM(M1);

    return HP1 + EXP1 + M1;
}

    // Task 3
int maxPoint(int matran_bando[10][10], int x, int y) {
    int max = -99999999;
    int col = 10 - 1;
    int row = 10 - 1;

    // đường chéo left top
    int i = x;
    int j = y;
    while (i > 0 && j > 0 && i < row && j < col) {
        i--;
        j--;
        int num = matran_bando[i][j];
        if (num > max) {
            max = num;
        }
    }
    // đường chéo right bottom
    i = x;
    j = y;
    while (i > 0 && j > 0 && i < row && j < col) {
        i++;
        j++;
        int num = matran_bando[i][j];
        if (num > max) {
            max = num;
        }
    }
    // đường chéo left bottom
    i = x;
    j = y;
    while (i > 0 && j > 0 && i < row && j < col) {
        i++;
        j--;
        int num = matran_bando[i][j];
        if (num > max) {
            max = num;
        }
    }
    // đường chéo right top
    i = x;
    j = y;
    while (i > 0 && j > 0 && i < row && j < col) {
        i--;
        j++;
        int num = matran_bando[i][j];
        if (num > max) {
            max = num;
        }
    }
    return max;
}

int maxNumber(int num) {
    while (num >= 10) {
        num = num /10 + num % 10;
    }
    return num;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    int matran_bando[10][10];
    int matran_diemso[10][10];

    // khởi tạo ma trận bản đồ và điểm số
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran_bando[i][j] = 0;
            matran_diemso[i][j] = 0;
        }
    }

    // khởi tạo điểm số taxi
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran_bando[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }

    // tính vị trí gặp nhau
    int x = 0;
    int y = 0;
    int duong = E3 * 2;
    int am = -E3;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int num = matran_bando[i][j];
            if (num > duong) {
                x++;
            } 
            if (num < am) {
                y++;
            }
        }
    }
    // tọa độ gặp nhau
    x = maxNumber(x);
    y = maxNumber(y);

    int taxiPoint = matran_bando[x][y];
    int swPoint = maxPoint(matran_bando, x, y); 
    if (abs(taxiPoint) > swPoint) {
        EXP1 *= 0.88;
        EXP2 *= 0.88;
        HP1 *= 0.9;
        HP2 *= 0.9;
    } else {
        EXP1 *= 1.12;
        EXP2 *= 1.12;
        HP1 *= 1.1;
        HP2 *= 1.1;
    }

    return (abs(taxiPoint) > swPoint) ? taxiPoint : swPoint;
}

    // Task 4
    // pass: 123, email: giangphivan@gmail.com
int checkPassword(const char *s, const char *email) {
    // check pass lenght < 8
    if (strlen(s) < 8) {
        return -1;
    }

    // check pass lenght > 20
    if (strlen(s) > 20) {
        return -2;
    }

    // check contain se
    size_t vitri = strcspn(email, "@");
    char se[100];
    strncpy(se, email, vitri);
    se[vitri] = '\0';
    const char *sei = strstr(s, se);
    if (sei != nullptr) {
        return -(300 + (sei - s));
    }

    // check có a-z, A-Z,0-9, @, #, %, $, !
    bool hasSpecialChar = false;
    for (size_t i = 0; i < strlen(s); ++i) {
        char c = s[i];

        if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!') {
            hasSpecialChar = true;
        }

        if(!(c >= 'a' && c <= 'z') 
            && !(c >= 'A' && c <= 'Z') 
            && !(c >='0' && c <= '9') 
            && c != '@' 
            && c != '#' 
            && c != '%' 
            && c != '$' 
            && c != '!') {
            return i;
        }

        // 
        if (i >= 2) {
            char s1 = s[i - 1];
            char s2 = s[i - 2]; 
            if (s[i] == s1 && s[i] == s2) {
                return -(400 + i - 2); 
            }
        }
    }

    // ít nhất 1 ký tự đặc biệt
    if (hasSpecialChar == false) {
        return -5;
    }

    // pass hợp lệ
    return -10;
}

    //Task 5
/**
 * Array = {"apple", "taxi", "car", "apple", "car", "camera", "banana", "apple", "camera"}
 * 1/ xem cac phan tu trong mang, xuat hien bao nhieu lan
 * 2/ tim phan tu xuat hien nhieu lan nhat
 * 3/ so sanh xem phan tu nao co chieu dai lon hon
 * 
*/
struct PasswordItem {
    const char* name;
    int count;
    int index;
};

/**
 * arr_pwds = {"apple", "taxi", "car", "apple", "car", "camera", "banana", "apple", "camera", "oo"}
 * passStruct = {
 *  [0] -> struct name="apple", count=2, index = 0
 *  [1] -> struct name="taxi", count=1, index = 1
 *  [2] -> struct name="car", count=2, index = 2
 *  [3] -> struct name="camera", count=1, index = 5
 * 
 * } 
 * 
 * passIndex -> 1
*/
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {

    PasswordItem* passStruct = new PasswordItem[num_pwds];
    int passIndex = 0;

    // for qua tung phan tu cua arr_pwds
    for (int i = 0; i < num_pwds; i++) {
        const char* pass = arr_pwds[i];

        bool found = false;
        for (int j = 0; j < passIndex; j++) {
            PasswordItem* passItem = &passStruct[j];
            const char* passName = passItem->name;
            if (strcmp(pass, passName) == 0) {
                passItem->count++;
                found = true;
            }
        }

        if(!found) {
            PasswordItem passItem;
            passItem.name = pass;
            passItem.count = 1;
            passItem.index = i;

            passStruct[passIndex] = passItem;
            passIndex++;
        }
    }

    // tim phan tu co so count xuat hien nhieu nhat
    const PasswordItem* maxItem = &passStruct[0];
    for (int i = 0; i < passIndex; i++) {
        PasswordItem* tmp = &passStruct[i];
        if ((tmp->count > maxItem->count) ||
            (tmp->count == maxItem->count && strlen(tmp->name) > strlen(maxItem->name))
        ){
            maxItem = tmp;
        }
    }
    
    // vi tri cua item trong mang 
    int index = maxItem->index;

    delete[] passStruct;
    return index;
}

// int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // const int max_password_length = 100;
    // int countPassword[max_password_length] = {0};
    // const char* maxcountPassword = nullptr;
    // int maxcountPasswordIndex = -1;
    // for (int i = 0; i < num_pwds; i++) {
    //     int len = strlen(arr_pwds[i]); 
    //     countPassword[len]++; 
    //     if (countPassword[len] > countPassword[strlen(maxcountPassword)]) {
    //         maxcountPassword = arr_pwds[i];
    //         maxcountPasswordIndex = i;  
    //     }
    // }

    // if (maxcountPasswordIndex != -1) {
    //     return maxcountPasswordIndex;
    // } 
    // return -1; 
// }
    

    ////////////////////////////////////////////////
    /// END OF STUDENT'S ANSWER
    ////////////////////////////////////////////////