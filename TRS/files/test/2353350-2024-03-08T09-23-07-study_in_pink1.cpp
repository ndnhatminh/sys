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
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    int D;
    if (E1 >= 0 && E1 <= 3) {
        switch (E1) {
        case 0:
            EXP2 += 29; 
            break; 
        case 1:
            EXP2 += 45; 
            break;
        case 2:
            EXP2 += 75;
            break;
        case 3: EXP2 += 149; //29+45+75
            break;
        } 
        D = E1 * 3 + EXP1 * 7;
        if (D % 2 == 0)
           { EXP1 = ceil(double(EXP1) + D / 200.00); if (EXP1>600) EXP1=600;}
        else
           { EXP1 = ceil(double(EXP1) - D / 100.00); if (EXP1<0) EXP1=0;}
        if (EXP2>600) EXP2=600;
        if (EXP2<0) EXP2=0;
        if (EXP1>600) EXP1=600;
        if (EXP1<0) EXP1=0;
        return EXP1 + EXP2;
    }
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19){
            EXP2 = ceil(EXP2 + (double(E1) / 4 + 19));
          //  if (EXP2>600) EXP2=600;
          }
        else if (E1 >= 20 && E1 <= 49){
            EXP2 = ceil(EXP2 + (double(E1) / 9 + 21));
           // if (EXP2>600) EXP2=600;
           }
        else if (E1 >= 50 && E1 <= 65){
            EXP2 = ceil(EXP2 + (double(E1) / 16 + 17));
          //  if (EXP2>600) EXP2=600;
        }
        else if (E1 >= 66 && E1 <= 79) {
            EXP2 = ceil(EXP2 + (double(E1) / 4 + 19));
            if (EXP2 > 200){
                EXP2 = ceil(EXP2 + (double(E1) / 9 + 21));
               // if (EXP2>600) EXP2=600;
               }
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 = ceil(EXP2 + (double(E1) / 4 + 19));
            EXP2 = ceil(EXP2 + (double(E1) / 9 + 21));
            if (EXP2 > 400) {
                EXP2 = ceil(EXP2 + (double(E1) / 16 + 17));
                EXP2 = ceil(EXP2 * 1.15);
                //if (EXP2>600) EXP2=600;
                
            }
        }
        ceil(EXP2);
        EXP1 -= E1;
        if (EXP2>600) EXP2=600;
        if (EXP2<0) EXP2=0;
        if (EXP1>600) EXP1=600;
        if (EXP1<0) EXP1=0;
        return EXP1 + EXP2;
    }
    else return -99;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function

    int koi_1, S, koi,i,koi_2,a;
    double P1,P2,P3,P;
if (E2>=0&&E2<=99){
        // Con duong 1
    koi_1 = EXP1;
    a = round(sqrt(EXP1));
        if (koi_1==0||koi_1==1)
            S = 2;
        else if (koi_1 % a != 0)
            S = pow(a, 2);
        else if (koi_1 % a == 0)
            S = EXP1;
    if (EXP1 >= S)
        P1 = 1;
    else
        P1 = (double(EXP1) / S + 80) / 123;
    // Con duong 2
    koi = M1;
    do {
        // AN UONG
        if (HP1 < 200) {
            HP1 = ceil(HP1 * 1.3); 
            M1 -= 150;
        }
        else {
            HP1 = ceil(HP1 * 1.1);
            M1 -= 70;
        }
        if (M1<0) M1=0;
        if (M1>3000) M1=3000;
        if (M1 <= 0.5 * koi && E2 % 2 != 0) break;

        // DI CHUYEN
        if (M1 <= 0 && E2 % 2 == 0) {
            M1 = 0; break;
        }
        if (EXP1 < 400)
            M1 -= 200;
        else
            M1 -= 120;
        EXP1 = ceil(EXP1 * 1.13); 
        if (M1<0) M1=0;
        if (M1>3000) M1=3000;
        if (M1 <= 0.5 * koi && E2 % 2 != 0) break;

        // GIUP DO
        if (M1 <= 0 && E2 % 2 == 0) {
            M1 = 0; break;
        }
        if (EXP1 < 300)
            M1 -= 100;
        else if (EXP1 >= 300)
            M1 -= 120;
        EXP1 = ceil(EXP1 * 0.9);
        if (M1<0) M1=0;
        if (M1>3000) M1=3000;
        if (M1 <= 0.5 * koi && E2 % 2 != 0) break;
    } while (E2 % 2 != 0);

        HP1 = ceil(HP1 * 0.83);
        EXP1 = ceil(EXP1 * 1.17);

        koi_1 = EXP1;
        a = round(sqrt(EXP1));
        if (koi_1==0||koi_1==1)
            S = 2;
        else if (koi_1 % a != 0)
            S = pow(a, 2);
        else if (koi_1 % a == 0)
            S = EXP1;
        if (EXP1 >= S)
            P2 = 1;
        else
            P2 = (double(EXP1) / S + 80) / 123;

     // Con duong 3 
        int P_[10] = { 32,47,28,79,100,50,22,83,64,11 };
        if (E2 / 10 == 0)
            E2 = i;
        else {
            koi_2 = E2/10+E2%10;
            i = koi_2%10;
        }
        
        P3 = P_[i]/100.00; 

    // Sau khi di ba con duong
        if (P1 == 100 && P2 == 100 && P3 == 100)
            EXP1 = ceil(EXP1 * 0.75);
        else P = (P1 + P2 + P3)/3;
        if (P < 0.5) {
            HP1 = ceil(HP1 * 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else {
            HP1 = ceil(HP1 * 0.9);
            EXP1 = ceil(EXP1 * 1.2);
        }
        if (EXP1>600) EXP1=600;
    return HP1 + EXP1 + M1;}
    else return -99;
}
// Task 3
int chaseTaxi(int& HP1, int& EXP1, int& HP2, int& EXP2, int E3) {
    // TODO: Complete this function
    int koi_taxi[10][10];
    int koi_sherlock[10][10];
    int max;
    if (E3>=0&&E3<=99){
     //map taxi
     for(int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            koi_taxi[i][j]=(E3*j+i*2)*(i-j);
        }
     }
     //map_sherlock
     for (int a=0;a<10;a++){
        for (int b=0;b<10;b++){
            max = koi_taxi[a][b];
            for (int v=0;v<10;v++){
                for (int y=0;y<10;y++){
                    if(a+b==v+y||b-a==y-v){
                    if (koi_taxi[v][y]>=max)
                     max=koi_taxi[v][y];
                    }
                }
            }
            koi_sherlock[a][b]=abs(max);
        }
     }
     //diem gap nhau
     int nbmk=0,dvk=0;
     for (int m=0;m<10;m++){
        for(int n=0;n<10;n++){
            if (koi_taxi[m][n]>E3*2) nbmk++;
            if (koi_taxi[m][n]<-E3) dvk++;
        }
     }
    while (nbmk>=10){
        nbmk=nbmk/10+nbmk%10;
    }
    while (dvk>=10){
        dvk=dvk/10+dvk%10;
    }
   int h;
    if (abs(koi_taxi[nbmk][dvk])>=koi_sherlock[nbmk][dvk]){
        h=koi_taxi[nbmk][dvk];
        EXP1=ceil(EXP1*0.88);
        EXP2=ceil(EXP2*0.88);
        HP1=ceil(HP1*0.90);
        HP2=ceil(HP2*0.90);
    }
    else {
        h=koi_sherlock[nbmk][dvk];
        EXP1=ceil(EXP1*1.12);
        EXP2=ceil(EXP2*1.12);
        HP1=ceil(HP1*1.10);
        HP2=ceil(HP2*1.10);
    }
    if (EXP1>600 ) EXP1=600;
    if (EXP2>600 ) EXP2=600;
    if (HP1>600 ) HP1=666;
    if (HP2>600 ) HP2=666;
    if (EXP1<0 ) EXP1=0;
    if (EXP2<0 ) EXP2=0;
    if (HP1<0 ) HP1=0;
    if (HP2<0 ) HP2=0;

return h;}
else return -99;
}

// Task 4
int checkPassword(const char* s, const char* email){
    // TODO: Complete this function
    int  dchar(0), dlt(0), wr(0);
    const char *k=strstr(email,"@");
    int mkoi=(k-email)/sizeof(char);
    char se[100];
    strncpy(se,email,mkoi);
    // chieu dai
    bool length;
    if (strlen(s)>=8 && strlen(s)<=20)
       length = true;
    else {length =false; wr++;}

    // kiem tra co 1 ky tu dac biet
    bool spchar;
    for (int i=0;i<mkoi;i++)
    if (se[i]=='@'||se[i]=='#'||se[i]=='%'||se[i]=='$'||se[i]=='!')
    {spchar=true; dchar++;}
    else {spchar = false; wr++; break;}

    // khong chua se
    int sei=0;
    bool secheck;
    const char *iukoi=strstr(s,se);
    if (iukoi=NULL)
       secheck=true; 
    else {
        secheck=false; wr++;
        char d[100];
        for (int i=0;i<strlen(s);i++){
    strncpy(d,s,i);
    char *p=strstr(d,se);
    if (p==NULL) sei++;
    else break;
        }
        sei-=strlen(se);
        //int m=0;
        /*for (int i=0;i<strlen(s);i++){
            int m=0;
            for (int j=0;j<strlen(se);j++){
                if (s[i+j]==se[j]) m++;
                else break;
            }
            if(m!=strlen(se)) sei++;
            else break;*/
        }
        
//std::cout<<sei;
    // khong chua nhieu hon 2 ky tu lien tiep giong nhau
    bool ktlt;
    int sci=0;
    while (sci<mkoi-2){
        if (se[sci]==se[sci+1]&&se[sci+1]==se[sci+2]){
        ktlt=false;
        break;
        }
        else {
            ktlt=true;
            sci++; wr++;
        }
    }
     
     // kiem tra matkhau hop le

     bool mkhl;
     if (length==true && spchar==true && secheck==true && ktlt==false){
        mkhl=true;
        return -10;
     }
     else {
    
       if (strlen(s)<8)
       return -1;
       else if(strlen(s)>20)
       return -2;
       else if (secheck==false)
       return -(300+sei);
       else if (ktlt==true)
       return -(400+sci);
       else 
       return -5;
       
       }
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int count[num_pwds];
    for (int v=0;v<num_pwds;v++){
        count[v]=0;
        for (int y=0;y<num_pwds;y++){
        if (arr_pwds[v]==arr_pwds[y])
        count[v]++;
        }
    }
    int maxcount=count[0];
    for (int i=0;i<num_pwds;i++){
        if (maxcount<=count[i])
        maxcount=count[i];
    }
    int koi=0;
    for (int y=0;y<num_pwds;y++){
    if (count[y]==maxcount){
        if (strlen(arr_pwds[y])>=koi)
        koi=strlen(arr_pwds[y]);
    }
    }
    int vkee=0;
    for (int y=0;y<num_pwds;y++){
        if (count[y]==maxcount&&strlen(arr_pwds[y])==koi)
        {vkee=y; break;}
    }
  return vkee;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////