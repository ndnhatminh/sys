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

void check(int & k, int code) {
    if (code == 1) {
        if (k>666) k=666;
        if (k<0) k=0;
    }
    if (code == 2) {
        if (k>600) k=600;
        if (k<0) k=0;
    }
    if (code == 3) {
        if (k>3000) k=3000;
        if (k<0) k=0;
    }
    return;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    check(exp1,2);
    check(exp2,2);
    if ((e1>=0) && (e1<=3)) {
        if(e1==0) exp2+=29; else
        if(e1==1) exp2+=45; else
        if(e1==2) exp2+=75; else
        if(e1==3) exp2+=149;
        check(exp2,2);
        int d=e1*3+exp1*7;
        if (d%2==0) exp1=ceil(exp1+(d/200.0)); else  exp1=ceil(exp1-(d/100.0));
        check(exp1,2);
    } else 
    if ((e1>=4) && (e1<=99)) {
        if ((e1>=4) && (e1<=19)) exp2=ceil(exp2+(e1/4.0+19));
        if ((e1>=20) && (e1<=49)) exp2=ceil(exp2+(e1/9.0+21));
        if ((e1>=50) && (e1<=65)) exp2=ceil(exp2+(e1/16.0+17));
        check(exp2,2);
        if ((e1>=66) && (e1<=79)) {
            exp2=ceil(exp2+(e1/4.0+19));
            check(exp2,2);
            if (exp2>200) exp2=ceil(exp2+(e1/9.0+21));
            check(exp2,2);
        } 
        if ((e1>=80) && (e1<=99)) {
            exp2=ceil(exp2+(e1/4.0+19));
            check(exp2,2);
            exp2=ceil(exp2+(e1/9.0+21));
            check(exp2,2);
            if (exp2>400) {
                exp2=ceil(exp2+(e1/16.0+17));
                check(exp2,2);
                exp2=ceil(exp2+exp2*0.15);
                check(exp2,2);
            }
        }
        exp1-=e1;   
        check(exp1,2);
    } else return -99;
    return exp1 + exp2;
}

int cp(int k) {
    int i=0;
    while (1) {
        if(trunc(sqrt(k+i))==sqrt(k+i)) return k+i;
        if(trunc(sqrt(k-i))==sqrt(k-i)) return k-i;
        i++;
    } 
}

void sk(int & HP1, int & EXP1, int & M1, int E2, int & spend, float hm) {
    if (HP1<200) {
        spend+=150;
        HP1=ceil(HP1+HP1*0.3);
        check(HP1,1);
        if (((float)spend>hm) && (E2%2==1)) return;
        if ((float)spend>M1) {
            M1=0;
            return;
        }
    } else {
        spend+=70;
        HP1=ceil(HP1*1.1);
        check(HP1,1);
        if (((float)spend>hm) && (E2%2==1)) return;
        if ((float)spend>M1) {
            M1=0;
            return;
        }
    }
    if (EXP1<400) spend+=200; else spend+=120;
    EXP1=ceil(EXP1*1.13);
    check(EXP1,2);
    if (((float)spend>hm) && (E2%2==1)) return;
    if ((float)spend>M1) {
            M1=0;
            return;
        }
    if (EXP1<300) spend+=100; else spend+=120;
    EXP1=ceil(EXP1*0.9);
    check(EXP1,2);
    if (((float)spend>hm) && (E2%2==1)) return;
    if ((float)spend>M1) {
            M1=0;
            return;
        }
    return;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    check(HP1,1);
    check(EXP1,2);
    check(M1,3);
    if ((E2<0)  || (E2>99)) return -99;
    int s=cp(EXP1);
    float p1;
    if (EXP1>=s) p1=1.0; else p1=((float)EXP1/s+80)/123.0;

    float hm=(float)M1/2;
    int spend=0;
    if(E2%2==1) {
        while((float)spend<=hm) {
            sk(HP1,EXP1,M1,E2,spend,hm);
        }
    } else {
        sk(HP1,EXP1,M1,E2,spend,hm);
    }
    if (M1>0) M1-=spend;
    HP1=ceil(HP1*0.83);
    check(HP1,1);
    EXP1=ceil(EXP1*1.17);
    check(EXP1,2);
    int ss=cp(EXP1);
    float p2;
    if (EXP1>=ss) p2=1.0; else p2=((float)EXP1/ss+80)/123.0;

    int pp[10]={32,47,28,79,100,50,22,83,64,11};
    int idx;
    if (E2>9) {
        idx=E2/10+E2%10;
        idx%=10;
    } else idx=E2;
    float p3=(float)pp[idx] / 100;

    if (p1==p2==p3==(float)1) EXP1=ceil(EXP1*0.75);
    check(EXP1,2);
    float tbc=(p1+p2+p3)/3;
    if (tbc<0.5) {
        HP1=ceil(HP1*0.85);
        check(HP1,1);
        EXP1=ceil(EXP1*1.15);
        check(EXP1,2);
    } else {
        HP1=ceil(HP1*0.9);
        check(HP1,1);
        EXP1=ceil(EXP1*1.2);
        check(EXP1,2);
    }
    return HP1 + EXP1 + M1; 
}

int xulidem(int dem){
     while (dem/10!=0) {
        int tam=0;
        while (dem) {
            tam+=dem%10;
            dem/=10;
        }
        dem=tam;
    }
    return dem;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3<0)  || (E3>99)) return -99;
    check(HP1,1);
    check(HP2,1);
    check(EXP1,2);
    check(EXP2,2);
    int a[10][10];
    int demd=0;
    int dema=0;
    for (int i=0;i<=9;i++) 
        for (int j=0;j<=9;j++) {
            a[i][j]=((E3*j)+(i*2))*(i-j);
            if (a[i][j]>E3*2) demd++;
            if (a[i][j]<-E3) dema++;
        }
    int x=xulidem(demd);
    int y=xulidem(dema);
    int maxx=a[x][y];
    int i=1;
    while (((x-i>=0)&&(y-i>=0)) || ((x-i>=0)&&(y+i<=9)) || ((x+i<=9)&&(y+i<=9)) || ((x+i<=9)&&(y-i>=0))) {
        if ((x-i>=0)&&(y-i>=0)) maxx=max(maxx,a[x-i][y-i]);
        if ((x-i>=0)&&(y+i<=9)) maxx=max(maxx,a[x-i][y+i]);
        if ((x+i<=9)&&(y+i<=9)) maxx=max(maxx,a[x+i][y+i]);
        if ((x+i<=9)&&(y-i>=0)) maxx=max(maxx,a[x+i][y-i]);
        i++;
    }
    if (abs(maxx)>=abs(a[x][y])) {
        EXP1=ceil(EXP1*1.12);
        HP1=ceil(HP1*1.1);
        EXP2=ceil(EXP2*1.12);
        HP2=ceil(HP2*1.1);
        check(HP1,1);
        check(HP2,1);
        check(EXP1,2);
        check(EXP2,2);
        return maxx;
    } else {
        EXP1=ceil(EXP1*0.88);
        HP1=ceil(HP1*0.9);
        EXP2=ceil(EXP2*0.88);
        HP2=ceil(HP2*0.9);
        check(HP1,1);
        check(HP2,1);
        check(EXP1,2);
        check(EXP2,2);
        return a[x][y];
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string st(s);
    string ste(email);
    if (st.length()<8) return -1;
    if (st.length()>20) return -2;
    string se="";
    for (int i=0;i<ste.length();i++) {
        if (ste[i]!='@') se+=ste[i]; else break;
    }
    int found=st.find(se);
    if (found !=-1) return -(300+found);
    for (int i=0;i<st.length()-1;i++) 
        if (st[i]==st[i+1]) return -(400+i);
    string sp="@#%$!";
    bool ok=1;
    for (int i=0;i<st.length();i++) {
        if (sp.find(st[i])!=-1) ok=0; 
        if (( ((int)st[i]<48) || (((int)st[i]>57) && ((int)st[i]<65)) || (((int)st[i]>90) && ((int)st[i]<97)) || ((int)st[i]>122)) && (sp.find(st[i])==-1)) return i;
    }
    if (ok) return -5;
    return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxl=strlen(arr_pwds[0]);
    int maxx=1;
    int vt=0;
    for (int i=0;i<num_pwds;i++) {
        int dem=1;
        for (int j=i+1;j<num_pwds;j++) {
            if (arr_pwds[i]==arr_pwds[j]) dem++;
        }
        if (((dem==maxx) && (strlen(arr_pwds[i])>maxl)) || (dem>maxx)) {
            maxl=strlen(arr_pwds[i]);
            maxx=dem;
            vt=i;
        }
    }
    return vt;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////