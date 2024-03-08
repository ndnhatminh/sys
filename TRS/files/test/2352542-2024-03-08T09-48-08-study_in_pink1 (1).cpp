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
int valid_Check_HP1 (int & HP1) {
     if (HP1>666) HP1=666;
    else if (HP1<0) HP1=0;
    return HP1;
};
int valid_Check_HP2 (int & HP2) {
     if (HP2>666) HP2=666;
    else if (HP2<0) HP2=0;
    return HP2;
};
int valid_Check_EXP1 (int & EXP1) {
     if (EXP1>600) EXP1=600;
    else if (EXP1<0) EXP1=0;
    return EXP1;
};
int valid_Check_EXP2 (int & EXP2) {
     if (EXP2>600) EXP2=600;
    else if (EXP2<0) EXP2=0;
    return EXP2;
};
int valid_Check_M1 (int & M1) {
     if (M1>3000) M1=3000;
    else if (M1<0) M1=0;
    return M1;
};
int valid_Check_M2 (int & M2) {
     if (M2>3000) M2=3000;
    else if (M2<0) M2=0;
    return M2;
};


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1<0 and e1>99) return -99;
    float E=e1;
    // TH1
    int D={0};
    if (e1>=0 and e1<=3){
        switch(e1) {
            case 0:
            exp2+=29;
            break;
            case 1:
            exp2+=45;
            break;
            case 2:
            exp2+=75;
            break;
            case 3:
            exp2+=149;
            break;
        }
        D=e1*3+exp1*7;
        if (D%2==0){
        exp1+=(D/200);
        }
        else{
        exp1-=(D/100);
        }
    }
    //TH2
    else if(e1>=4 and e1<=99){
         if(e1>=4 and e1<=19) {
            exp2+=ceil(E/4 + 19);
            
        }
        else if(e1>=20 and e1<=49) {
            exp2+=ceil(E/9 + 21);
            
        }
        else if(e1>=50 and e1<=65) {
            exp2+=ceil(E/16 + 17);
            
        }
        else if(e1>=66 and e1<=79) {
            exp2+=ceil(E/4 + 19);
            if(exp2>200) {
                exp2=ceil(E/9 + 21); 
                
            }
            
        }
        else if(e1>=80 and e1<=99) {
            exp2+=ceil(E/4 + 19);
            exp2+=ceil(E/9 + 21);
            if(exp2>400) {
                exp2+=ceil(E/16 + 18);
                exp2=ceil(1.15*exp2);
            }
        }
        exp1-=e1;
    };
    valid_Check_EXP1(exp1);
    valid_Check_EXP2(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 and E2>99) return -99;
    //Con đường 1
    float P1,P2,P3;
    float A=sqrt(EXP1);
    float S=round(A)*round(A);
    if(EXP1>=S) {
        P1=100;
    }
    else {
        P1=(EXP1/S+80)/1.23;
    };
    //Con đường 2
    int Mbd=M1;
    Gate:
    if (HP1<200) {
        HP1=ceil(HP1*1.3);
        M1-=150;
    }
    else {
        HP1=ceil(HP1*1.1);
        M1-=70;
    };
      if (M1<=0.5*(Mbd) and E2%2!=0) {
          goto Endroad;
      }
      else if (M1<0 and E2%2==0) {
          M1=0;
          goto Endroad;
      };
    if (EXP1<400) {
        M1-=200;
    }
    else {
        M1-=120;
    };
    EXP1=ceil(EXP1*1.13);
      if (M1<=0.5*(Mbd) and E2%2!=0) {
          goto Endroad;
      }
      else if (M1<0 and E2%2==0) {
          M1=0;
          goto Endroad;
      };
    if (EXP1<300) {
        M1-=100;
    }
    else {
        M1-=120;
    }
    EXP1=ceil(EXP1*0.9);
      if (M1<=0.5*(Mbd) and E2%2!=0) {
          goto Endroad;
      }
      else if (M1<0 and E2%2==0) {
          M1=0;
          goto Endroad;
      };
    if (E2%2!=0) {
        goto Gate;
    }
    Endroad:
    HP1=ceil(HP1*0.83);
    EXP1=ceil(EXP1*1.17);
    A=sqrt(EXP1);
    S=round(A)*round(A);
    if(EXP1>=S) {
        P2=100;
    }
    else {
        P2=(EXP1/S+80)/1.23;
    };
    //Con đường 3
    int i;
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10) {
        i=E2;
    }
    else {
        i=((E2/10)+(E2%10))%10;
    }
    P3=P[i];
    float Ps;
    if (P1==P2==P3==100) {
        EXP1=ceil(EXP1*0.75);
    }
    else {
         Ps=(P1+P2+P3)/3;
        if (Ps<50) {
            HP1=ceil(HP1*0.85);
            EXP1=ceil(1.15*EXP1);
        }
        else {
            HP1=ceil(HP1*0.9);
            EXP1=ceil(1.2*EXP1);
        }
    };
    valid_Check_HP1 (HP1);
    valid_Check_EXP1 (EXP1);
    valid_Check_M1 (M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3<0 and E3>99) return -99;  
// Khởi tạo mảng bản đồ biểu diễn điểm số kỹ năng của taxi
    int Taxi_P[10][10]={};
// Khởi tạo điểm kỹ năng tại tất cả vị trí mà taxi đi qua và vị trí [i,j] mà cả 2 gặp nhau
    int ix=0, jx=0;
    for (int i=0;i<10;i++) {
        for (int j=0;j<10;j++) {
            Taxi_P[i][j]=((E3*j)+(i*2))*(i-j);
            if (Taxi_P[i][j]>(E3*2)) {
                ix++;
            }
            else if (Taxi_P[i][j]<(-E3)) {
                jx++;
            };
        }
    };
    while (ix>=10) {
        ix=ix/10+ix%10;
    };
     while (jx>=10) {
        jx=jx/10+jx%10;
    }; 
// Giá trị điểm số kỹ năng của Sherlock và Waston
    int cross[]={};
    int a=ix, b=jx, c=ix, d=jx, m=0;
    for (int k=-9;k<10;k++) {
        a+=k;
        b+=k;
        c+=k;
        d-=k;
        if (a>=0 and a<=9 and b>=0 and b<=9) {
            cross[m]=Taxi_P[a][b];
            m++;
        };
         if (c>=0 and c<=9 and d>=0 and d<=9) {
            cross[m]=Taxi_P[c][d];
            m++;
        };
        a=ix, b=jx, c=ix, d=jx;
    };
    int SaW_P=cross[0];//Đĩ niểm kăng của Sherlock và Waston
    for (int i=1;i<=m;i++) {
        if (SaW_P<cross[i]) {
            SaW_P=cross[i];
        };
    };
    SaW_P=abs(SaW_P);
//Kiểm tra Sherlock và Waston có đuổi kịp taxi và tổng điểm
    if (abs(Taxi_P[ix][jx])>SaW_P) {
        EXP1=ceil(EXP1*0.88);
        EXP2=ceil(EXP2*0.88);
        HP1=ceil(HP1*0.9);
        HP2=ceil(HP2*0.9);
        return Taxi_P[ix][jx];
    }
    else {
        EXP1=ceil(EXP1*1.12);
        EXP2=ceil(EXP2*1.12);
        HP1=ceil(HP1*1.1);
        HP2=ceil(HP2*1.1);
        return SaW_P;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string pass_w=s;
    string email_add=email;
    string se="", test; 
    int i=0,rep_check=1, point=0;
    //Tìm chuỗi se trong email
    for (int i=0;i< email_add.length();i++) {
        if (email_add[i]==64) point=i;
    }
    se=email_add.substr(0, point-1);
    //Điều kiện dài ngắn của mật khẩu
    if (pass_w.length()<8) {
        return -1;
    }
    else if (pass_w.length()>20) {
        return -2;
    };
    //Kiểm tra se có trong email không
  for (int i=0;i<pass_w.length();i++) {
        test =  pass_w.substr(i, se.length());
        if(test==se) return -(300+i);    
    }
    //Tìm các kí tự liên tiếp trùng nhau
    int j;
    for (int i=0;i<pass_w.length();i++) {
        int j=i;
        while (pass_w[j]=pass_w[j+1]) {
            j++;
            rep_check++;
            if (rep_check>3) {
                return -(400+i);
            }
        };

        rep_check=1;
    };
    //Kiểm tra đk các kí tự khác không hợp lệ
    int valid=0,not_valid=0;
    for (int i=0;i<pass_w.length();i++) {
         if ((pass_w[i] >= 32 and pass_w[i] <= 47) || (pass_w[i] >= 58 && pass_w[i] <= 64) || (pass_w[i] >= 91 and pass_w[i] <= 96) || (pass_w[i] >= 123 and pass_w[i] <= 126)) {
            if (pass_w[i] == 33 || pass_w[i] == 64 || (pass_w[i] >= 35 && pass_w[i] <= 37)) valid++;
            else not_valid++; 
         }
    }
    if (valid==0) return -5;
    else if (not_valid>0) return (pass_w.length()-not_valid);
    return -10;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int Appearance[30]={0};
    int Position[30]={0};
    string Pass[30]={};
    int x=0, count=0, max=0;
    for (int i=0;i<num_pwds;i++) {
        if (arr_pwds[i]!=Pass[x]) {
            Pass[x+1]=arr_pwds[i];
            Position[x+1]=i;
            for (int j=0;j<num_pwds;j++) {
                if (arr_pwds[j]==Pass[x+1]) {
                    count++;
                }
            };
            Appearance[x+1]=count;
            count=0;
            x++;
        }
    }
    for (int k=1;k<=x;k++) {
        if (Appearance[k]>max) {
            max=k;
        }
        else if (Appearance[k]==max) {
            if (Pass[k].length()>Pass[max].length()) max=k;
        }
    }
    return Position[max];
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////