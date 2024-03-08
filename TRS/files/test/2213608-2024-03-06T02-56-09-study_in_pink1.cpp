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

void setExp1(int& EXP1)
{
    if (EXP1 > 600) EXP1 = 600;
    if (EXP1 < 0) EXP1 = 0;
 }
void setHP1(int& HP1) {
    if (HP1 > 666) HP1 = 666;
    if (HP1 < 0) HP1 = 0;
}
void setExp2(int& EXP2)
{
    if (EXP2 > 600) EXP2 = 600;
    if (EXP2 < 0) EXP2 = 0;
}
void setHP2(int& HP2)
{
    if (HP2 > 666) HP2 = 666;
    if (HP2 < 0) HP2 = 0;
}
void setM1(int& M1) {
    if (M1 > 3000) M1 = 3000;
    if (M1 < 0) M1 = 0;
}
void setM2(int& M2) {
    if (M2 > 3000) M2 = 3000;
    if (M2 < 0) M2 = 0;
}
int firstMeet(int& EXP1, int& EXP2, int E1) {
    // TODO: Complete this function
   
    //Trường hợp 1
    if (E1 >= 0 && E1 <= 99) {
        setExp1(EXP1);
        setExp2(EXP2);
       
        if (E1 >= 0 && E1 <= 3) {
            int D;
            if (E1 == 0) {
                EXP2 = EXP2 + 29;
                setExp2(EXP2);
            }
            else if (E1 == 1) {
                EXP2 = EXP2 + 45;
                setExp2(EXP2);
            }
            else if (E1 == 2) {
                EXP2 = EXP2 + 75;
                setExp2(EXP2);
            }
            else if (E1 == 3) {
                EXP2 = EXP2 + 29 + 45 + 75;
                setExp2(EXP2);
            }
            D = E1 * 3 + EXP1 * 7;
            if (D % 2 == 0) {
                EXP1 = ceil((double)EXP1 + ((double)D / 200));
                setExp1(EXP1);
            }
            else {
                EXP1 = ceil((double)EXP1 - ((double)D / 100));
                setExp1(EXP1);
            }
        }

        //Trường hợp 2
        else {
            if (E1 >= 4 && E1 <= 19) {
                EXP2 = ceil((double)EXP2 + (((double)E1 / 4) + 19));
                setExp2(EXP2);
            }
            else if (E1 >= 20 && E1 <= 49) {
                EXP2 = ceil((double)EXP2 + (((double)E1 / 9) + 21));
                setExp2(EXP2);
            }
            else if (E1 >= 50 && E1 <= 65) {
                EXP2 = ceil((double)EXP2 + (((double)E1 / 16) + 17));
                setExp2(EXP2);
            }
            else if (E1 >= 66 && E1 <= 79) {
                EXP2 = ceil((double)EXP2 + (((double)E1 / 4) + 19));
                setExp2(EXP2);
                if (EXP2 > 200) {
                    EXP2 = ceil((double)EXP2 + (((double)E1 / 9) + 21));
                    setExp2(EXP2);
                }
            }
            else if (80 <= E1&&E1 <= 99) {
                EXP2 = ceil((double)EXP2 + (((double)E1 / 4) + 19));
                setExp2(EXP2);
                EXP2 = ceil((double)EXP2 + (((double)E1 / 9) + 21));
                setExp2(EXP2);
                if (EXP2 > 400) {
                    EXP2 = ceil((double)EXP2 + (((double)E1 / 16) + 17));
                    setExp2(EXP2);
                    EXP2 = ceil((double)EXP2 + (0.15 * (double)EXP2));
                    setExp2(EXP2);
                }
            }
            EXP1 = EXP1 - E1;
            setExp1(EXP1);

        }
        return EXP1 + EXP2;
    }
    else {return -99;}
   

}
bool isperfectsquare(int s) {
    int check = sqrt(s);
    return (check * check == s);
}
// task 2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2) {
    // todo: complete this function
   
    
   
  if(E2>=0&&E2<=99){
    //con đường 01:
    //kiểm tra số chính phương
      setExp1(EXP1);
      setHP1(HP1);
      setM1(M1);
    double p1, p2, p3,averageofp;
    
    int smaller = EXP1;
    int larger = EXP1;
    for (int i=0;i<1000;i++) {
        if (isperfectsquare(smaller)) {
            p1 = 1;
            
        }

        else if (isperfectsquare(larger)) {
            p1 = ((1.0*EXP1 / larger) + 80) / 123;
         
        }
        else {
            smaller--;
            larger++;
        }
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //con đường 2:
    //e2 lẻ
    if (E2 % 2 != 0) {
        double half_money = M1 / 2;
        double total_cash = 0;
        for (int i=0;i<10;i++) {
            //*1:
            if (HP1 < 200) {
                HP1 = ceil(HP1 + (0.3 * HP1)); //heal
                setHP1(HP1);
                M1 = M1 - 150; //pay for heal
                setM1(M1);
                total_cash = total_cash + 150;
                if (total_cash > half_money) {
                    HP1 = ceil(HP1 - (0.17 * HP1));
                    setHP1(HP1);
                    EXP1 = ceil(EXP1 + (0.17 * EXP1));
                    setExp1(EXP1);
                    break;
                }
            }
            else {
                HP1 = ceil(HP1 + (0.1 * HP1));//heal
                setHP1(HP1);
                M1 =  M1 - 70;//pay for heal
                setM1(M1);
                total_cash = total_cash + 70;
                if (total_cash > half_money) {
                    HP1 = ceil(HP1 - (0.17 * HP1));
                    setHP1(HP1);
                    EXP1 = ceil(EXP1 + (0.17 * EXP1));
                    setExp1(EXP1);
                    break;
                }
            }
            //*2:
            if (EXP1 < 400) {
                //taxi time bro!!!
                M1 = M1 - 200;
                setM1(M1);
                EXP1 = ceil(EXP1 + (0.13 * EXP1));
                setExp1(EXP1);
                total_cash = total_cash + 200;
                if (total_cash > half_money) {
                    HP1 = ceil(HP1 - (0.17 * HP1));
                    setHP1(HP1);
                    EXP1 = ceil(EXP1 + (0.17 * EXP1));
                    setExp1(EXP1);
                    break;
                }
            }
            else {
                M1 = M1 - 120;
                setM1(M1);
                EXP1 = ceil(EXP1 + (0.13 * EXP1));
                setExp1(EXP1);
                total_cash = total_cash + 120;
                if (total_cash > half_money) {
                    HP1 = ceil(HP1 - (0.17 * HP1));
                    setHP1(HP1);
                    EXP1 = ceil(EXP1 + (0.17 * EXP1));
                    setExp1(EXP1);
                    break;
                }
            }
            ///
          //*3:
            if (EXP1 < 300) {
                M1 = M1 - 100;
                setM1(M1);
                EXP1 = ceil(EXP1 - (0.1 * EXP1));
                setExp1(EXP1);
                total_cash = total_cash + 100;
                if (total_cash > half_money) {
                    HP1 = ceil(HP1 - (0.17 * HP1));
                    setHP1(HP1);
                    EXP1 = ceil(EXP1 + (0.17 * EXP1));
                    setExp1(EXP1);
                    break;
                }
            }
            else {
                M1 = M1 - 120;
                setM1(M1);
                EXP1 = ceil(EXP1 - (0.1 * EXP1));
                setExp1(EXP1);
                total_cash = total_cash + 120;
                if (total_cash > half_money) {
                    HP1 = ceil(HP1 - (0.17 * HP1));
                    setHP1(HP1);
                    EXP1 = ceil(EXP1 + (0.17 * EXP1));
                    setExp1(EXP1);
                    break;
                }
            }
           
        }
    }
    
    //e2 chẵn
    else {
        //*1:
        if (HP1 < 200) {
            HP1 = ceil(HP1 + (0.3 * HP1)); //heal
            setHP1(HP1);
            M1 = M1 - 150; //pay for heal
            setM1(M1);
            if (M1 < 0) {
                M1 = 0;
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);

            }
        }
        else {
            HP1 = ceil(HP1 + (0.1 * HP1));//heal
            setHP1(HP1);
            M1 = M1 - 70;//pay for heal
            setM1(M1);
            if (M1 < 0) {
                M1 = 0;
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);

            }
        }

        //*2:
        if (EXP1 < 400) {
            //taxi time bro!!!
            M1 = M1 - 200;
            setM1(M1);
            EXP1 = ceil(EXP1 + (0.13 * EXP1));
            setExp1(EXP1);
            if (M1 < 0) {
                M1 = 0;
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);

            }
        }
        else {
            M1 = M1 - 120;
            setM1(M1);
            EXP1 = ceil(EXP1 + (0.13 * EXP1));
            setExp1(EXP1);
            if (M1 < 0) {
                M1 = 0;
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);

            }
        }
        ///
        //*3:
        if (EXP1 < 300) {
            M1 = M1 - 100;
            setM1(M1);
            EXP1 = ceil(EXP1 - (0.1 * EXP1));
            setExp1(EXP1);
            if (M1 < 0) {
                M1 = 0;
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);

            }
            else {
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);

            }
        }
        else {
            M1 = M1 - 120;
            setM1(M1);
            EXP1 = ceil(EXP1 - (0.1 * EXP1));
            setExp1(EXP1);
            if (M1 < 0) {
                M1 = 0;
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);

            }
            else {
                HP1 = ceil(HP1 - (0.17 * HP1));
                setHP1(HP1);
                EXP1 = ceil(EXP1 + (0.17 * EXP1));
                setExp1(EXP1);
            }
        }
    }


    ///
    //xác suất tìm thấy vali ở con đường 02:
    
    int smaller1 = EXP1;
    int larger1 = EXP1;
    for (int i = 0;i<1000;i++) {
        if (isperfectsquare(smaller1)) {
            p2 = 1;
            break;
        }

        else if (isperfectsquare(larger1)) {
            p2 = ((1.0*EXP1 / larger1) + 80) / 123;
            break;
        }
        else {
            smaller1--;
            larger1++;
        }
    }
    ///////////////////////////////////////////////////////////////
    //con đường 03:
    int p[10] = { 32,47,28,79,100,50,22,83,64,11 };
    int i;
    /// nếu e2 là số có một chữ số, giá trị đó là giá trị của i. nếu e2 là số có 2 chữ số,tính tổng của 2 chữ số đó và lấy số hàng đơn vị của giá trị tổng làm giá trị cho i

    if (E2 < 10) {
        i = E2;
        p3 = (double)p[i] / 100;
    }
    else {
        i = (E2 / 10) + (E2 % 10);
        i = i % 10;
        p3 = (double)p[i] / 100;
    }
    ////////////////////
    if (p1 == 1 && p2 == 1 && p3 == 1) {
        EXP1 = ceil(EXP1 - (0.25 * EXP1));
        setExp1(EXP1);
    }
    else {
        averageofp = (p1 + p2 + p3) / 3;
        if (averageofp < 0.50) {
            HP1 = ceil(HP1 - (0.15 * HP1));
            setHP1(HP1);
            EXP1 = ceil(EXP1 + (0.15 * EXP1));
            setExp1(EXP1);
        }
        else {
            HP1 = ceil(HP1 - (0.1 * HP1));
            setHP1(HP1);
            EXP1 = ceil(EXP1 + (0.2 * EXP1));
            setExp1(EXP1);
        }
    }
    return HP1 + EXP1 + M1;
 }
   else { return -99;}
}

// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    if (E3 >= 0 && E3 <= 99) {
        int A[10][10];
        int SoDuong = 0;
        int SoAm = 0;
        //Set Taxi array:
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                A[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (A[i][j] > (E3 * 2)) SoDuong = SoDuong + 1;
                if (A[i][j] < (-E3)) SoAm = SoAm + 1;
            }
        }
        while (true) {
            if (SoDuong > 9) {
                SoDuong = (SoDuong / 10) + (SoDuong % 10);
            }
            else break;
        }
        while (true) {
            if (SoAm > 9) {
                SoAm = (SoAm / 10) + (SoAm % 10);
            }
            else break;
        }
        int SkillofTaxi, SkillofMain;

        SkillofTaxi = A[SoDuong][SoAm];
        SkillofMain = A[SoDuong][SoAm];
        //Tìm giá trị của thằng Main
        //Lấy chéo từ trái sang phải "/"
        for (int n = 0; n < 10; n++) {

            int newSoDuong, newSoAm;
            newSoDuong = SoDuong - n;
            newSoAm = SoAm + n;
            if (A[newSoDuong][newSoAm] > SkillofMain) {
                SkillofMain = A[newSoDuong][newSoAm];
            }
            if (newSoDuong == 0 || newSoAm == 9) {
                break;
            }

        }
        //Lấy chéo từ phải sang trái"/"
        for (int n = 0; n < 10; n++) {

            int newSoDuong, newSoAm;
            newSoDuong = SoDuong + n;
            newSoAm = SoAm - n;
            if (A[newSoDuong][newSoAm] > SkillofMain) {
                SkillofMain = A[newSoDuong][newSoAm];
            }
            if (newSoDuong == 9 || newSoAm == 0) {
                break;
            }

        }
        //Lấy chéo từ phải sang trái"\"
        for (int n = 0; n < 10; n++) {
            int newSoDuong, newSoAm;
            newSoDuong = SoDuong + n;
            newSoAm = SoAm + n;
            if (A[newSoDuong][newSoAm] > SkillofMain) {
                SkillofMain = A[newSoDuong][newSoAm];
            }
            if (newSoDuong == 9 || newSoAm == 9) {
                break;
            }
        }
        //Lấy chéo từ trái sang phải"\"
        for (int n = 0; n < 10; n++) {
            int newSoDuong, newSoAm;
            newSoDuong = SoDuong - n;
            newSoAm = SoAm - n;
            if (A[newSoDuong][newSoAm] > SkillofMain) {
                SkillofMain = A[newSoDuong][newSoAm];
            }
            if (newSoDuong == 0 || newSoAm == 0) {
                break;
            }
        }
        //Kiểm tra xem có đuổi kịp không?
        //Đuổi kịp:
        if (abs(SkillofMain) >= abs(SkillofTaxi)) {
            EXP1 = EXP1 + EXP1 * 0.12;
            setExp1(EXP1);
            EXP2 = EXP2 + EXP2 * 0.12;
            setExp2(EXP2);
            HP1 = HP1 + HP1 * 0.1;
            setHP1(HP1);
            HP2 = HP2 + HP2 * 0.1;
            setHP2(HP2);
            return SkillofMain;
        }
        //No
        else {
            EXP1 = EXP1 - EXP1 * 0.12;
            setExp1(EXP1);
            EXP2 = EXP2 - EXP2 * 0.12;
            setExp2(EXP2);
            HP1 = HP1 - HP1 * 0.1;
            setHP1(HP1);
            HP2 = HP2 - HP2 * 0.1;
            setHP2(HP2);
            return SkillofTaxi;
        }
    }
    else {
        return -99;
}
    ////////////////
  

   
}
bool laSo(char str) {
    return str >= 48 && str <= 57;
}
bool laKitu(char str) {
    return (str >= 65 && str <= 90) || (str >= 97 && str <= 122);
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char backupofemail[101];
    strncpy(backupofemail, email, 100);
    backupofemail[100] = '\0';
    const char* se = strtok(backupofemail, "@");
    int length = strlen(s);
    if (length > 20) {
        return -2;
    }
    if (length < 8) {
        return -1;
    }
    if (strstr(s, se)) {
        return -(300 + (strstr(s, se) - s));
    }
    int soluongtrung = 0;
    for (int i = 0; i < length-1; i++) {
        
        if (s[i] == s[i + 1]) {
            soluongtrung = soluongtrung + 1;
        }
        if (s[i] != s[i + 1]) {
            soluongtrung = 0;
        }
        if (soluongtrung == 2) {
            return -(400 + (i - 2));
        }
        
    }
    int check = 0;
    for (int i = 0; i < length; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            check = check + 1;
        }
    }
        if (check == 0) {
            return -5;
        }
     
        for (int i = 0; i < length; i++) {
            if (check != 0) {
                if (!laSo(s[i]) && !laKitu(s[i])) {
                    return i;
                }
              
            }
   }

   
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int Maxsimilar=0, Maxoflength=0;
    int backupofPW = 0;
    for (int i = 0; i < num_pwds; i++) {
        {
            int similar=0;
            for (int j = 0; j < num_pwds; j++) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    similar = similar + 1;
                }
            }
            int lengthofpass = strlen(arr_pwds[i]);
            if (similar > Maxsimilar ) {
                Maxsimilar = similar; 
                backupofPW = i;
            }
            if (similar == Maxsimilar && lengthofpass > Maxoflength) {
                Maxoflength = lengthofpass;
                backupofPW = i;
            }
            
        }
    }
    return backupofPW;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////