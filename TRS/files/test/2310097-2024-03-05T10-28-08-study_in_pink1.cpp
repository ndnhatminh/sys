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

// Kiem tra va dieu chinh gia tri EXP neu no vuot qua hoac duoi gioi han
void checkEXP(int &EXP1, int &EXP2)
{
    if (EXP1 > 600) {
        EXP1 = 600;
    }
    else if (EXP1 < 0) {
        EXP1 = 0;
    }

    // Ki?m tra và ?i?u ch?nh giá tr? c?a EXP2
    if (EXP2 > 600) {
        EXP2 = 600;
    }
    else if (EXP2 < 0) {
        EXP2 = 0;
    }
}

// Kiem tra va dieu chinh gia tri HP neu no vuot qua hoac duoi gioi han
void checkHP(int &HP1, int &HP2)
{
    if (HP1 > 666) {
        HP1 = 666;
    }
    else if (HP1 < 0) {
        HP1 = 0;
    }

    // Ki?m tra và ?i?u ch?nh giá tr? c?a EXP2
    if (HP2 > 666) {
        HP2 = 666;
    }
    else if (HP2 < 0) {
        HP2 = 0;
    }
}

// Kiem tra va dieu chinh gia tri M neu no vuot qua hoac duoi gioi han
void checkM(int &M1, int &M2)
{
    if (M1 > 3000) {
        M1 = 3000;
    }
    else if (M1 < 0) {
        M1 = 0;
    }

    // Ki?m tra và ?i?u ch?nh giá tr? c?a EXP2
    if (M2 > 3000) {
        M2 = 3000;
    }
    else if (M2 < 0) {
        M2 = 0;
    }
}

void checkE(int& E1, int& E2, int& E3)
{
    if (E1 > 99 || E1 < 0) E1 = -99;
    if (E2 > 99 || E2 < 0) E2 = -99;
    if (E3 > 99 || E3 < 0) E3 = -99;
}
/////////////////////////// Task 1 ///////////////////////////

// Truong hop dau tien, dieu chinh gia tri EXP dua tren gia tri e1. EXP2 tang dua tren e1, EXP1 thay doi dua tren D (tinh tu e1 va EXP1). Cuoi cung, kiem tra gia tri EXP.
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >= 0 && e1 <=99)
    {
    checkE(e1, e1, e1); // Sửa thành checkE(E1, E2, E3)

    checkEXP(exp1, exp2);

    int D = 0;
    if (e1 >= 0 && e1 <= 3) {
        switch (e1) {
            case 0:
                exp2 += 29;
                break;
            case 1:
                exp2 += 45;
                break;
            case 2:
                exp2 += 75;
                break;
            case 3:
                exp2 += 29 + 45 + 75;
                break;
            default:
                break;
        }
        checkE(e1,e1,e1);
    
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0) {
            exp1 = static_cast<int>(std::ceil(exp1 + (double(D) / 200)));
        } else {
            exp1 = static_cast<int>(std::ceil(exp1 - (double(D) / 100)));
        }
        checkEXP(exp1, exp2);
    } else if (e1 >= 4 && e1 <= 19) {
        exp2 += static_cast<int>(std::ceil(double(e1) / 4) + 19);
         checkEXP(exp1, exp2);
    } else if (e1 >= 20 && e1 <= 49) {
        exp2 += static_cast<int>(std::ceil(double(e1) / 9) + 21 );
         checkEXP(exp1, exp2);
    } else if (e1 >= 50 && e1 <= 65) {
        exp2 += static_cast<int>(std::ceil(double(e1) / 16) + 17 );
         checkEXP(exp1, exp2);
    } else if (e1 >= 66 && e1 <= 79) {
        exp2 += static_cast<int>(std::ceil(double(e1) / 4) + 19 );
        if (exp2 > 200) {
            exp2 += static_cast<int>(std::ceil(double(e1) / 9) + 21 );
        }
         checkEXP(exp1, exp2);
    } else if (e1 >= 80 && e1 <= 99) {
        exp2 += static_cast<int>(std::ceil(double(e1) / 4) + 19 );
        exp2 += static_cast<int>(std::ceil(double(e1) / 9) + 21 );
        if (exp2 > 400) {
            exp2 += static_cast<int>(std::ceil(double(e1) / 16) + 17 );
            exp2 = static_cast<int>(std::ceil((double)exp2 * 1.15));
            checkEXP(exp1, exp2);
        }
    }
    if (e1 >= 4 && e1 <= 99) {
        exp1 = exp1 - e1;
        checkEXP(exp1, exp2);
    }
    return exp1 + exp2;
    } else return -99;
}

// Task 2
int demoS(int EXP1){
   return round(sqrt(EXP1))*round(sqrt(EXP1));
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 >= 0 && E2 <=99){
        checkHP(HP1, HP1);
        checkEXP(EXP1, EXP1);
        checkM(M1, M1);
        double P1, P2, P3, Ptbinh;
        if (demoS(EXP1) <= EXP1)  P1=1;
        else P1= (EXP1/demoS(EXP1)*1.00 + 80)/123.00 ;

        int Mchi=0;
        double M=M1*0.5;
        if (E2 % 2 == 1){
            while(Mchi <= M){
                if (HP1 < 200) {
                    if (M1 > 0){HP1 += ceil(0.3*HP1);}
                    else break;
                    M1 -= 150;
                    Mchi += 150; 
                    checkM(M1, M1);  
                     
                } else {
                    if (M1 > 0 )
                    {
                       HP1 += ceil(0.1*HP1);
                    } else break;
                    M1 -= 70;
                    Mchi += 70;
                    checkM(M1, M1); 
                    
                } 
                checkHP(HP1, HP1);
                checkM(M1, M1);
                if (Mchi > M){
                   break;
                }

                if (EXP1 < 400) {
                    M1 -= 200;
                    Mchi += 200;
                } else {
                    M1 -= 120;
                    Mchi += 120;
                } 
                EXP1 += ceil(0.13*EXP1);
                checkM(M1, M1);
                checkEXP(EXP1, EXP1);
                if (Mchi > M){
                   break;
                }

                if (EXP1 < 300){
                    M1 -= 100;
                    Mchi += 100;
                } else {
                    M1 -= 120;
                    Mchi += 120;
                } 
                EXP1 = ceil(EXP1*0.9);
                checkM(M1, M1);
                checkEXP(EXP1, EXP1);
                if (Mchi > M){
                   break;
                }
            }
        } else {
            while(1){
                if (HP1 < 200) {
                   if (M1 == 0){
                   break;}
                   HP1 += ceil(0.3*HP1);
                   checkHP(HP1, HP1);
                   M1 -= 150; 
                   checkM(M1, M1);  
                   
                   
                   
                } else {
                    if (M1 == 0){
                   break;}
                    M1 -= 70;
                    HP1 += ceil(0.1*HP1);
                    checkHP(HP1, HP1);  
                   checkM(M1, M1);
                    
                   
                   
                } 
                if (M1 == 0){
                   break;
                }
                checkHP(HP1, HP1);
                checkM(M1, M1);

                if (EXP1 < 400) {
                   M1 -= 200;
                } else {
                   M1 -= 120;
                }
                checkM(M1, M1);
                EXP1 += ceil(0.13*EXP1);
                if (M1 ==0){
                   break;
                }
                checkM(M1, M1);
                checkEXP(EXP1, EXP1);

                if (EXP1 < 300){
                  M1 -= 100;
                } else {
                  M1 -= 120;
                } 
                EXP1 = ceil(EXP1*0.9);
                checkM(M1, M1);
                checkEXP(EXP1, EXP1);
                break;
            }
        }
        HP1 = ceil(HP1*0.83);
        EXP1 = ceil(EXP1*1.17);
        checkEXP(EXP1, EXP1);
        checkHP(HP1, HP1);
        if (demoS(EXP1) <= EXP1)  P2=1;
        else P2= (EXP1/demoS(EXP1)*1.00 + 80)/123.00 ;

        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2 < 10) {
            i = E2;
        } else {
            int sum = E2 / 10 + E2 % 10;
            i = sum % 10;
        }
        P3 = P[i]*0.01;

        if(P1==P2 && P2==P3 && P1==1)  EXP1 = ceil(EXP1*0.75);
        else {
            Ptbinh=(P1+P2+P3)/3;
            if(Ptbinh<0.5) {
                HP1= ceil(HP1*0.85);
                EXP1 += ceil(0.15*EXP1);
            } else {
                HP1= ceil(HP1*0.90);
                EXP1 += ceil(0.2*EXP1);           
            }
           checkEXP(EXP1, EXP1);
        }

        return HP1 + EXP1 + M1;
    } else {
        return -99;
    }
}


// Task 3
int rutgon(int so) {
    while (so >= 10) {
        int s = 0;
        while (so > 0) {
            s += so % 10;
            so /= 10;
        }
        so = s;
    }
    return so;
}


int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    
    
    checkE(E3, E3, E3);
    int checkcuoi;

    if (E3 >= 0 && E3 <= 99)
    {
        checkEXP(EXP1, EXP2);
        checkHP(HP1, HP2);
    //Tao ma tran
    const int hang = 10;
    const int cot  = 10;
    int Matran[hang][cot];
    //Tim cho gap nhau, gia su diem gap nhau la Matran[a][b]
    int duong = 0, am = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            Matran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (Matran[i][j] > (E3 * 2)) {
                ++duong;
            } else if ( Matran[i][j] < (-E3)) {
                ++am;
            }
        }
    }

    

    int a = rutgon(duong);
    int b = rutgon(am);

    //tim diem so cua sherlock va  watson tai diem gap nhau
    int max = Matran[a][b];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i+j == a+b || i-j == a-b)
            {
               max = max > Matran[i][j] ? max : Matran[i][j];
            }
        }
    }

    //so sanh
    if (abs(Matran[a][b]) > abs(max) )
    {
        EXP1 = ceil(EXP1*0.88);
        HP1 = ceil(HP1 *0.9);
        EXP2= ceil(EXP2*0.88);
        HP2 = ceil(HP2 *0.9);
        checkcuoi = Matran[a][b];
    }
    else 
    {
        EXP1+= ceil(EXP1*0.12);
        HP1 += ceil(HP1 *0.1);
        EXP2+= ceil(EXP2*0.12);
        HP2 += ceil(HP2 *0.1);
        checkcuoi = max;
    }
    checkEXP(EXP1, EXP2);
    checkHP(HP1, HP2);
    return checkcuoi ;
    }
    else return -99;

}

// Task 4
//kiem tra email
    int checkemail(const char *email) {
    int dem = 0;

    for (size_t i = 0; i < strlen(email); ++i) {
        if (email[i] == '@') {
            dem++;
            if (dem > 1) {
                return i; 
            }
        }
    }

    if (dem == 1) {
        return -1; 
    }

  
    return 0;
}


int checkPassword(const char * s, const char * email)
{
    

    //kiem tra mat khau
    //do dai
    if (strlen(s) < 8 ) return -1;
    if (strlen(s) > 20) return -2;

    //tach lay phan se va kiem tra se co trong s khong
    const char * vitriA = strchr(email, '@');
    char se[99];
    int vitriAdoi = vitriA - email;
    strncpy(se, email, vitriAdoi);
    se[vitriAdoi] = '\0'; 

    const char * setrongs = strstr(s, se);
    
    if (setrongs != NULL) 
    {
        int demm = (setrongs - s);
        return -(300 + demm);
    }

    //ky tu lien tiep giong nhau
    for (const char * t = s; *t != '\0'; ++t)
    {
        if (*t == *(t+1) && *(t+1) == *(t+2))
        {
            return -(400 + t - s);
        }
    }

    
    //kiem tra ky tu dac biet
    bool dem = false;
    for (const char * t = s; *t != '\0'; ++t)
    {
    char c = *t;
    if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!' )
    {
        dem = true;
        break;
    }
    }
    if (!dem) return -5;

    

    //kiem tra thuoc ky tu hop le
    for (const char * t = s; *t != '\0'; ++t)
    {
        char d = *t;
        if (!((d >= 48 && d <= 57) || (d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z') || d == '@' || d == '#' || d == '%' || d == '$' || d == '!'))
        return (t - s);
    }

    return -10;
}

// Task 5
    bool kiemtra (const char * mk1, const char * mk2)
    {
        while (*mk1 && *mk2)
        {
            if (*mk1 != *mk2) {
                return false;
            }
            mk1++; mk2++;
        }
        return (*mk1 == *mk2);
    }

    int findCorrectPassword(const char * arr_pwds[], int num_pwds)
    {
        //tim mat khau xuat hien nhieu nhat
        const char* maxts_mk = NULL;
        int kq;
        int max_xh = 0;
        int maxlong = 0;
        for (int i = 0; i < num_pwds; ++i)
        {
            int solanxh = 1;
            for (int j = i +1 ; j < num_pwds; ++j)
            {
                if (kiemtra(arr_pwds[i], arr_pwds[j]))
                {
                    ++solanxh;
                }
            }
            if ((solanxh > max_xh) || ((solanxh == max_xh) &&strlen(arr_pwds[i]) > maxlong))
            {
                max_xh = solanxh;
                maxts_mk = arr_pwds[i];
                maxlong = strlen(arr_pwds[i]);
                kq=i;
            }

        
        }
    
    return kq;
    }

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////