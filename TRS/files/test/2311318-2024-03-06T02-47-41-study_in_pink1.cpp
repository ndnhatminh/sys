#include "study_in_pink1.h"

#define lt 0.999

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

//Kiểm tra các chỉ số: 
void checkHP(int & HP){
    if (HP >666) HP =666;
    else if (HP <0) HP =0;
    return;
}

void checkEXP(int & EXP){
    if (EXP >600) EXP =600;
    else if (EXP <0) EXP =0;
    return;
}

void checkM(int & M){
    if (M >3000) M =3000;
    else if (M <0) M =0;
    return;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >99 || e1 <0) return -99;
    checkEXP(exp1); checkEXP(exp2);
    if (e1 >=0 && e1 <=3){
        if (e1 ==0) exp2 +=29;
        else if (e1 ==1) exp2 +=45;
        else if (e1 ==2) exp2 +=75;
        else if (e1 ==3) exp2 +=149;
        checkEXP(exp2);
        int D =e1 *3 +exp1 *7;
        if (D %2 ==0){
            exp1 =(exp1 + D /200.0) +lt; // Sherlock đưa ra lựa chọn Afghanistan và EXP của Sherlock tăng
        }
        else{
            exp1 =(exp1 -D /100.0) +lt; // Sherlock đưa ra lựa chọn là Iraq và EXP của Sherlock giảm
        }
        checkEXP(exp1);
    }
    else if (e1 >=4 && e1 <=99){
        if (e1 >=4 && e1 <=19){
            exp2 =(exp2 +e1 /4.0 +19) +lt;
        }
        else if (e1 >=20 && e1 <=49){
            exp2 =(exp2 +e1 /9.0 +21) +lt;
        }
        else if (e1 >=50 && e1 <=65){
            exp2 =(exp2 +e1 /16.0 +17) +lt;
        }
        else if (e1 >=66 && e1 <=79){
            exp2 =(exp2 +e1 /4.0 +19) +lt;
            checkEXP(exp2);
            if (exp2 >200) exp2 =(exp2 +e1 /9.0 +21) +lt;
        }
        else if (e1 >=80 && e1 <=99){
            exp2 =(exp2 +e1 /4.0 +19) +lt;
            exp2 =(exp2 +e1 /9.0 +21) +lt;
            checkEXP(exp2);
            if (exp2 >400){
                exp2 =(exp2 +e1 /16.0 +17) +lt;
                exp2 =exp2 *1.15 +lt;
            }
        }
        exp1 -=e1;
        checkEXP(exp1); checkEXP(exp2);
    }
    
    return exp1 + exp2;
}

// Task 2
int findSquareNumber(int num){
    //Tìm số nguyên chính phương lớn hơn num và nhỏ nhất
    int sqNumLarger =sqrt(num) +lt;
    sqNumLarger *=sqNumLarger;
    //Tìm số nguyên chính phương nhỏ hơn num và lớn nhẩt
    int sqNumSmaller =0;
    for (int i =0; i <=num; ++i ){
        if (i *i >=num) break;
        if ((i *i) >sqNumSmaller) sqNumSmaller =i *i;
    }
    if (abs(sqNumLarger -num) <abs(sqNumSmaller -num)) return sqNumLarger;
    return sqNumSmaller;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 >99 || E2 <0) return -99;
    checkHP(HP1); checkEXP(EXP1); checkM(M1);
    float P1, P2, P3; // Xác suất trên từng con đường
    //Trên con đường 01:
    int S1 =findSquareNumber(EXP1);
    P1 =(EXP1 <S1) ? (EXP1 /float(S1) +80) /123.0 : 1; // Xác suất con đường 01
    //Trên con đường 02:
    if (E2 %2==1){
        int tmp =M1 *0.50, pay =0;
        while (pay <=tmp && M1 >0) {
            if (HP1 <200 && M1 >0){
                HP1 =HP1 *1.30 +lt;
                M1 =M1 -150;
                pay +=150;
            }
            else if (HP1 >=200 && M1 >0){
                HP1 =HP1 *1.10 +lt;
                M1 =M1 -70;
                pay +=70;
            }
            if (pay <=tmp && M1 >0 && EXP1 <400){
                M1 =M1 -200;
                pay +=200;
            }
            else if (pay <=tmp && M1 >0 && EXP1 >=400){
                M1 =M1 -120;
                pay +=120;
            }
            else break;
            EXP1 =EXP1 *1.13 +lt;
            if (pay <=tmp && M1 >0 && EXP1 <300){
                M1 =M1 -100;
                pay +=100;
            }  
            else if (pay <=tmp && M1 >0 && EXP1 >=300){
                M1 =M1 -120;
                pay +=120;
            }
            else break;
            EXP1 =EXP1 *0.90 +lt;
            checkHP(HP1); checkEXP(EXP1); checkM(M1);
        }
        checkHP(HP1); checkEXP(EXP1); checkM(M1);
    }
    else {
        if (HP1 <200 && M1 >0){
            HP1 =HP1 *1.30 +lt;
            M1 =M1 -150;
        }
        else if (HP1 >=200 && M1 >0){
            HP1 =HP1 *1.10 +lt;
            M1 =M1 -70;
        }
        if (M1 >0 && EXP1 <400){
            EXP1 =EXP1 *1.13 +lt;
            M1 =M1 -200;
        }
        else if (M1 >0 && EXP1 >=400){
            EXP1 =EXP1 *1.13 +lt;
            M1 =M1 -120;
        }
        if (M1 >0 && EXP1 <300){
            EXP1 =EXP1 *0.90 +lt;
            M1 =M1 -100;
        }  
        else if (M1 >0 && EXP1 >=300){
            EXP1 =EXP1 *0.90 +lt;
            M1 =M1 -120;
        }
        checkHP(HP1); checkEXP(EXP1); checkM(M1);
    }
    HP1 =HP1 *0.83 +lt; EXP1 =EXP1 *1.17 +lt;
    checkHP(HP1); checkEXP(EXP1); checkM(M1);
    int S2 =findSquareNumber(EXP1);
    P2 =(EXP1 <S2) ? (EXP1 /float(S2) +80) /123.0 : 1; // Xác suất con đường 02
    //Trên con đường 03:
    const int P[10] ={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 >=0 && E2 <=9){
        P3 =P[E2] /100.0;
    }
    else if (E2 >=10 && E2 <=99){
        int Sum =E2 /10 +E2 %10;
        P3 =P[Sum %10] /100.0; // Xác suất con đường 03
    }
    //Sau khi đã đi qua 3 con đường
    if (P1 ==1 && P2 ==1 && P3 ==1){
        EXP1 =EXP1 *0.75 +lt; checkEXP(EXP1);
    }
    else{
        float P =(P1 +P2 +P3) /3.0;
        if (P <0.50){
            HP1 =HP1 *0.85 +lt; EXP1 =EXP1 *1.15 +lt;
        }
        else if (P >=0.50){
            HP1 =HP1 *0.90 +lt; EXP1 =EXP1 *1.20 +lt;
        }
        checkHP(HP1); checkEXP(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 >99 || E3 <0) return -99;
    checkHP(HP1); checkEXP(EXP1); checkHP(HP2); checkEXP(EXP2);
    int mt[11][11] ={0}, point[11][11] ={0}, cnt1 =0, cnt2 =0;
    //Khởi tạo mảng:
    for (int i =0; i <=9; ++i){
        for (int j =0; j <=9; ++j){
            mt[i][j] =(E3 *j +i *2) *(i -j);
            if (mt[i][j] >E3 *2) ++cnt1;
            else if (mt[i][j] <-E3) ++cnt2;
        }
    }
    //Mảng lưu điểm:
    for (int i =0; i <=9; ++i){
		for (int j =0; j <=9 -i; ++j){
			point[j][j +i +1] =mt[0][i +1];
			point[j +i +1][j] =mt[9][8 -i];
		}
	}
	for (int i =9; i >=0; --i){
		for (int j =0; j <=9; ++j){
			for (int k =1; k <=9; ++k){
				int imoi =i -k;
				int jmoi =j +k;
				if (mt[imoi][jmoi] >point[i][j] && imoi >=0 && imoi <=9 && jmoi >=0 && jmoi <=9){
                    point[i][j] =mt[imoi][jmoi];
                }
			}
			for (int k =9; k >=1; --k){
				int imoi =i +k;
				int jmoi =j -k;
				if (mt[imoi][jmoi] >point[i][j] && imoi >=0 && imoi <=9 && jmoi >=0 && jmoi <=9){
                    point[i][j] =mt[imoi][jmoi];
                }
			}
		}
	}
    int I =cnt1 /10 +cnt1 %10;
    while (I >9){
        I =I /10 +I %10;
    }
    int J =cnt2 /10 +cnt2 %10;
    while (J >9){
        J =J /10 +J %10;
    }
    if (abs(mt[I][J]) >point[I][J]){
        EXP1 =EXP1 *0.88 +lt; HP1 =HP1 *0.90 +lt;
        checkEXP(EXP1); checkHP(HP1);
        EXP2 =EXP2 *0.88 +lt; HP2 =HP2 *0.90 +lt;
        checkEXP(EXP2); checkHP(HP2);
        return mt[I][J];
    }
    else {
        EXP1 =EXP1 *1.12 +lt; HP1 =HP1 *1.10 +lt;
        checkEXP(EXP1); checkHP(HP1);
        EXP2 =EXP2 *1.12 +lt; HP2 =HP2 *1.10 +lt;
        checkEXP(EXP2); checkHP(HP2);
        return point[I][J];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    char whiLst[5] ={'@', '#', '%', '$', '!'};
    int lenE =strlen(email), lenP =strlen(s);
    string se=""; int idx =0;
    while (email[idx] !=whiLst[0]){
        se +=email[idx];
        ++idx;
    }
    //Kiểm tra độ dài: 
    if (lenP <8) return -1;
    else if (lenP >20) return -2;
    //Kiểm tra chuỗi se trong chuỗi s: 
    for (int i =0; i <=lenP -1; ++i){
        string tmp ="";
        for (int k =i; k <=idx +i -1; ++k){
            if (idx +i -1 >lenP) break;
            else {
                tmp +=s[k];
            }
        }
        if (tmp ==se) return -(300 +i);
    }
    //Kiểm tra 2 ký tự liên tiếp trong chuỗi s:
    for (int i =0; i <=lenP -1; ++i){
        if (i <=lenP && (i +1) <=lenP && (i +2) <=lenP){
            if (s[i] ==s[i +1] && s[i +1] ==s[i +2]) return -(400 +i);
        }
    }
    //Kiểm tra kí tự đặc biệt trong chuỗi s:
    bool tick =0;
    for (int i =0; i <=lenP -1; ++i){
        for (int j =0; j <=4; ++j){
           if (s[i] ==whiLst[j]) tick =1;
        }
    }
    if (tick ==0) return -5;
    for (int i =0; i <=lenP -1; ++i){
        if ((s[i] <48 || (s[i] >=58 && s[i] <=64) || (s[i] >=91 && s[i] <=96) || (s[i] >=123 && s[i] <=126)) && (s[i] !=33 && s[i] !=35 && s[i] !=36 && s[i] !=37 && s[i] !=64)) return i;
    }
    return -10;
}

// Task 5
struct psswd{
        int len, fre;
        string pwd;
        };

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    if (num_pwds ==1) return 0;
    psswd pass[num_pwds +1];
    for (int i =0; i <=num_pwds -1; ++i){
        pass[i].fre =0;
        pass[i].len =0;
        pass[i].pwd ="0";
    }
    for (int i =0; i <=num_pwds -1; ++i){
        pass[i].pwd =arr_pwds[i]; pass[i].len =strlen(arr_pwds[i]);
        for (int j =0; j <=num_pwds -1; ++j){
            if (i ==j) continue;
            else {
                if (pass[i].pwd ==arr_pwds[j]){
                    pass[i].fre +=1;
                    pass[j].fre +=1; 
                }
            }
        }
    }
    psswd passInvalid =pass[0];
    for (int i =0; i <=num_pwds -1; ++i){
        if (passInvalid.fre <pass[i].fre){
            passInvalid =pass[i];
        }
        else if (passInvalid.fre ==pass[i].fre && passInvalid.pwd ==pass[i].pwd) continue;
        else if (passInvalid.fre ==pass[i].fre && passInvalid.pwd !=pass[i].pwd){
            if (passInvalid.len <pass[i].len) {
                passInvalid =pass[i];
            }
        }
    }
    for (int i =0; i <=num_pwds -1; ++i){
        if (passInvalid.pwd ==arr_pwds[i]) return i;
    }    
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////