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

// Chia hai so tu nhien va lam tron
int chia(int a, int b){
    int c;
    if (a%b==0) c = a/b;
    else c = a/b + 1;
    return c;
}

// CheckHP
int checkhp(int hp){
    int a;
    if (hp>666) a=666;
    else if (hp<0) a=0;
    else a=hp;
    return a;
}

// CheckEXP
int checkexp(int exp){
    int a;
    if (exp>600) a=600;
    else if (exp<0) a=0;
    else a=exp;
    return a;
}

// CheckM
int checkm(int m){
    int a;
    if (m>3000) a=3000;
    else if (m<0) a=0;
    else a=m;
    return a;
}

// Tim so chinh phuong 
int chinhphuong(int a){
    int b, c, d, hieu1, hieu2, cp;
    b = sqrt(a);
    c = b*b;
    d= (b+1)*(b+1);
    hieu1 = a - c;
    hieu2 = d - a;
    if (hieu1 >= hieu2) cp = d;
    else cp = c;
    return cp;    
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if ((e1>=0) && (e1<=99)) {
        exp1=checkexp(exp1);
        exp2=checkexp(exp2);
        if ((e1>=0) && (e1<=3)){
            if (e1==0) exp2 = exp2 + 29;
            if (e1==1) exp2 = exp2 + 45;
            if (e1==2) exp2 = exp2 + 75;
            if (e1==3) exp2 = exp2 + 149;
            int D;
            D = e1*3 + exp1*7;
            if (D%2==0) exp1 = exp1 + chia(D,200);
            else exp1 = exp1 - (D/100);
        }
        else {
            if ((e1>=4) && (e1<=19)) exp2 = exp2 + (chia(e1,4) +19);
            if ((e1>=20) && (e1<=49)) exp2 = exp2 + (chia(e1,9) +21);
            if ((e1>=50) && (e1<=65)) exp2 = exp2 + (chia(e1,16) +17);
            if ((e1>=66) && (e1<=79)) {
                exp2 = exp2 + (chia(e1,4) +19);
                if (exp2>200) exp2 = exp2 + (chia(e1,9) +21);
            }
            if ((e1>=80) && (e1<=99)) {
                exp2 = exp2 + (chia(e1,4) +19) + (chia(e1,9) +21);
                if (exp2>400) {
                    exp2 = exp2 + (chia(e1,16) +17);
                    exp2 = exp2 + chia(exp2*15,100);
                }
            } 
            exp1 = exp1 - e1;
        }
        exp1=checkexp(exp1);
        exp2=checkexp(exp2);

        return exp1 + exp2;
    }
    else return -99;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2>=0) && (E2<=99)) {
        HP1=checkhp(HP1);
        EXP1=checkexp(EXP1);
        M1=checkm(M1);
        // Con duong 1
        int s1;
        double p1;
        s1 = chinhphuong(EXP1);
        if (EXP1>=s1) p1=1;
        else p1=((EXP1/s1*1.00)+80)/123;

        // Con duong 2
        double bandau, sudung, p2;
        bandau= M1*0.5; 
        sudung= 0;
        if (E2%2==1){
            while (sudung<=bandau){
                if (M1==0) break;
                if (HP1<200){
                    HP1=chia(HP1*130,100);
                    M1=M1-150;
                    sudung=sudung+150;
                }
                else {
                    HP1=chia(HP1*110,100);
                    M1=M1-70;
                    sudung=sudung+70;
                }
                HP1=checkhp(HP1);
                M1=checkm(M1);
                if (sudung>bandau) break;

                if (EXP1<400) {
                    EXP1=chia(EXP1*113,100);
                    M1=M1-200;
                    sudung=sudung+200;
                }
                else {
                    EXP1=chia(EXP1*113,100);
                    M1=M1-120;
                    sudung=sudung+120;
                }
                EXP1=checkexp(EXP1);
                M1=checkm(M1);
                if (sudung>bandau) break;

                if (EXP1<300) {
                    EXP1=chia(EXP1*90,100);
                    M1=M1-100;
                    sudung=sudung+100;
                }
                else {
                    EXP1=chia(EXP1*90,100);
                    M1=M1-120;
                    sudung=sudung+120;
                }
                EXP1=checkexp(EXP1);
                M1=checkm(M1);
            }
        }
        else {
            while(true) {
                if (M1==0) break;
                if (HP1<200){
                    HP1=chia(HP1*130,100);
                    M1=M1-150;
                }
                else {
                    HP1=chia(HP1*110,100);
                    M1=M1-70;
                }
                HP1=checkhp(HP1);
                M1=checkm(M1);
                if (M1<=0) {
                    M1=checkm(M1);
                    break;
                } 

                if (EXP1<400) {
                    EXP1=chia(EXP1*113,100);
                    M1=M1-200;
                }
                else {
                    EXP1=chia(EXP1*113,100);
                    M1=M1-120;
                }
                EXP1=checkexp(EXP1);
                M1=checkm(M1);
                if (M1<=0) {
                    M1=checkm(M1);
                    break;
                } 

                if (EXP1<300) {
                    EXP1=chia(EXP1*90,100);
                    M1=M1-100;
                }
                else {
                    EXP1=chia(EXP1*90,100);
                    M1=M1-120;
                }
                EXP1=checkexp(EXP1);
                M1=checkm(M1);
                break;
            }
        }
        HP1=chia(HP1*83,100);
        HP1=checkhp(HP1);
        EXP1=chia(EXP1*117,100);
        EXP1=checkexp(EXP1);
        int s2;
        s2 = chinhphuong(EXP1);
        if (EXP1>=s2) p2=1;
        else p2=((EXP1/s2*1.00)+80)/123;
        // Con duong 3
        double P[10]={0.32,0.47,0.28,0.79,1.00,0.50,0.22,0.83,0.64,0.11};
        double p3;
        int tong, donvi;
        if ((E2/10==0)) p3 = P[E2];
        else {
            tong = (E2/10) + (E2%10);
            donvi = tong % 10;
            p3 = P[donvi];
        }

        double tb;
        if ((p1==1) && (p2==1) && (p3==1)) EXP1 =chia(EXP1*75,100);
        else {
            tb = (p1+p2+p3)/3;
            if (tb<0.5) {
                EXP1=chia(EXP1*115,100);
                HP1=chia(HP1*85,100);
            }
            else { 
                EXP1=chia(EXP1*120,100);
                HP1=chia(HP1*90,100);
            }
        }
        HP1=checkhp(HP1);
        EXP1=checkexp(EXP1);
        M1=checkm(M1);
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3>=0) && (E3<=99)) {
        HP1=checkhp(HP1);
        HP2=checkhp(HP2);
        EXP1=checkexp(EXP1);
        EXP2=checkexp(EXP2);
        int matran[10][10],dem1,dem2;
        dem1=0;
        dem2=0;
        for (int i=0;i<10;i++) {
            for (int j=0;j<10;j++){
                matran[i][j]=((E3*j)+(i*2))*(i-j);
            }
        }
        for (int i=0;i<10;i++) {
            for (int j=0;j<10;j++){
                if (matran[i][j]>E3*2) dem1++;
                if (matran[i][j]<(-E3)) dem2++;
            }
        }
        while (dem1>9) {
            dem1=dem1/10+dem1%10;
        }
        while (dem2>9) {
            dem2=dem2/10+dem2%10;
        }
        int taxi=matran[dem1][dem2];
        int diem=matran[dem1][dem2];
        int ketqua;
         for (int i=0;i<10;i++) {
            for (int j=0;j<10;j++){
                if (dem1+dem2==i+j) {
                    if (matran[i][j]>diem) diem=matran[i][j];
                }
                if (dem1-dem2==i-j) {
                    if (matran[i][j]>diem) diem=matran[i][j];
                }
            }
        }
        if (abs(diem)>=abs(taxi)) {
            EXP1=chia(EXP1*112,100);
            HP1=chia(HP1*110,100);
            EXP2=chia(EXP2*112,100);
            HP2=chia(HP2*110,100);
            ketqua=diem;
        }
        else {
            EXP1=chia(EXP1*88,100);
            HP1=chia(HP1*90,100);
            EXP2=chia(EXP2*88,100);
            HP2=chia(HP2*90,100);
            ketqua=taxi;
        }
        HP1=checkhp(HP1);
        HP2=checkhp(HP2);
        EXP1=checkexp(EXP1);
        EXP2=checkexp(EXP2);
        return ketqua;
    }
    else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    if (strlen(s)<8) return -1;
    if (strlen(s)>20) return -2;

    // Tach se ra khoi email
    const char * vitri = strchr(email,'@');
    int dodai=vitri-email;
    char se[100];
    strncpy(se,email,dodai);
    se[dodai]='\0';

    // KTra se co trong mat khau khong?
    const char * checkse = strstr(s,se);
    if (checkse != NULL) {
        int sei=(checkse-s);
        return -(300+sei);
    }

    //Ktra cac ki tu lien tiep giong nhau
    for (const char * checkmk = s; *checkmk != '\0'; checkmk++) {
        if (*checkmk == *(checkmk+1) && *(checkmk+1) == *(checkmk+2)) {
            int sci=checkmk-s;
            return -(400+sci);
        }
    }

    //Ktra ki tu dac biet
    int dem=0;
    for (const char * checkmk = s; *checkmk != '\0'; checkmk++) {
        char a=*checkmk;
        if ((a=='@')||(a=='#')||(a=='%')||(a=='$')||(a=='!')) {
            dem++;
        }      
    }
    if (dem==0) return -5;
    for (const char * checkmk = s; *checkmk != '\0'; checkmk++){
        char a = *checkmk;
        if (!((a >= 48 && a <= 57) || (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '@' || a == '#' || a == '%' || a == '$' || a == '!'))
        return (checkmk - s);
    }
    return -10;
}

// // Tao du lieu cho mk
// struct matkhau{
//     const char * mk;
//     int max;
//     int dodai;
// };

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    const char * mk=" ";
    int max=0;
    int dodai=0;

    for (int i=0; i<num_pwds; i++) {
        const char * tam1 = arr_pwds[i];
        int tam2 = strlen(tam1);
        int dem=0;
        for (int j=0;j<num_pwds;j++){
            if (arr_pwds[j]==tam1) {
                dem=dem+1;
            }
        }

       if ((dem>max) || (dem==max && tam2>dodai)){
            mk=tam1;
            max=dem;;
            dodai=tam2;
       }
    }  

    for (int i=0;i<num_pwds;i++) {
        if (arr_pwds[i]==mk) {
            return i;
        }
    }  
    return -99;
   
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////