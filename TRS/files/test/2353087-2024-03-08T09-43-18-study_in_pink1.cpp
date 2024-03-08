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

///// 0 <= HP <= 666
int limitHP(int HP) {
    if(HP<0){HP=0;}
    else if(HP>666){
    HP=666;
    } else HP=HP;
    return HP;
}
///// 0 <= EXP <= 600
int limitEXP(int EXP) {
    if(EXP<0){EXP=0;}
    else if(EXP>600){
    EXP=600;
    } else EXP=EXP;
    return EXP;
}
///// 0 <= M <= 3000
int limitMoney(int M) {
    if(M<0){M=0;}
    else if(M>3000){
    M=3000;
    } else M=M;
    return M;
}
///// 0 <= E <= 99

//làm tròn lên
int lamtronlen(double a){
    if(a > (int)a) return (int)(a+0.99999);
    else return (int)a;
}

//số chính phương gần nhất
int scp(int EXP1){
    int S1;
    double P1;
    int kc=600;
    for(int i=0;i<=24;i++){
        int a=i*i; 
        int hieu = abs(a-EXP1);
        if (hieu < kc){
            kc=hieu;
            S1=a;
        }
    }
    return S1;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //biến làm tròn
    double lamtron;
    //ktra giá trị hợp lệ
    if(e1>99 || e1<0) return -99;
    else{
    //limit exp
    exp1=limitEXP(exp1);
    exp2=limitEXP(exp2);
    // trường hợp 1
    if(0<=e1 && e1<=3){
        if (e1==0){
            exp2=exp2+29;
            exp2=limitEXP(exp2);
        } 
        else if(e1==1){
            exp2=exp2+45;
            exp2=limitEXP(exp2);
        }else if(e1==2){
            exp2=exp2+75;
            exp2=limitEXP(exp2); 
        }else if(e1==3){
            exp2=exp2+149;
            exp2=limitEXP(exp2);
        } 
        int D;
        D=e1*3+exp1*7;
        if (D%2==0){
            lamtron = exp1 + D/200.0;
            exp1=lamtronlen(lamtron);
            exp1=limitEXP(exp1);
        } 
        else{
            lamtron = exp1 - D/100.0;
            exp1=lamtronlen(lamtron);
            exp1=limitEXP(exp1);
        }
    }
    // trường hợp 2
    if (4<=e1 && e1<=99){
    if (4<=e1 && e1<=19){
        lamtron = exp2 + e1/4.0 + 19;
        exp2=lamtronlen(lamtron);
        exp2=limitEXP(exp2);
    }
    else if (20<=e1 && e1<=49){
        lamtron = exp2 + e1/9.0 + 21;
        exp2=lamtronlen(lamtron);
        exp2=limitEXP(exp2);
    }
    else if (50<=e1 && e1<=65){
        lamtron = exp2 + e1/16.0 + 17;
        exp2=lamtronlen(lamtron);
        exp2=limitEXP(exp2);
    }
    else if (66<=e1 && e1<=79){
        lamtron = exp2 + e1/4.0 + 19;
        exp2=lamtronlen(lamtron);
        exp2=limitEXP(exp2);
        if (exp2>200){
            lamtron = exp2 + e1/9.0 + 21;
            exp2=lamtronlen(lamtron);
            exp2=limitEXP(exp2);
        } 
    }
    else if (80<=e1 && e1<=99){
        //thông tin 1
        lamtron = exp2 + e1/4.0 + 19;
        exp2=lamtronlen(lamtron);
        exp2=limitEXP(exp2);
        //thong tin 2
        lamtron=exp2 + e1/9.0 + 21;
        exp2=lamtronlen(lamtron);   
        exp2=limitEXP(exp2);
        if (exp2>400){
            //thông tin 3
            lamtron = exp2 + e1/16.0 + 17;
            exp2=lamtronlen(lamtron);
            exp2=limitEXP(exp2);
            //thưởng thêm 15%
            lamtron=exp2*1.15;
            exp2=lamtronlen(lamtron);
            exp2=limitEXP(exp2);
        }
    }
    //exp1 
    exp1=(exp1)-(e1);
    exp1=limitEXP(exp1);
    }  
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    //làm tròn lên 
    double lamtron;
    //ktra E2 hợp lệ
    if(E2>99 || E2<0) return -99;
    else{
    HP1=limitHP(HP1);
    EXP1=limitEXP(EXP1);
    M1=limitMoney(M1);
    //con đường 1
    int S1; //scp gần nhất 1
    double P1; //xác xuất tìm thấy 1
    S1=scp(EXP1);
    if(EXP1>=S1) P1=1.0;
    else{
        P1=(double)EXP1/S1;
        P1=(P1+80)/123.0;
    } 

    //con đường 2
    double m=M1/2.0;
    int spent=0;
    if(M1 == 0){
        lamtron=HP1*0.83;
        HP1=lamtronlen(lamtron);
        HP1=limitHP(HP1);

        lamtron=EXP1*1.17;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
    }else{
    if(E2%2 != 0){
    while (spent<=m){
    if(HP1<200){
        lamtron=HP1*1.3;
        HP1=lamtronlen(lamtron);
        HP1=limitHP(HP1);
        M1=M1-150;
        M1=limitMoney(M1);
        spent+=150;
        if(spent>m) break;
        
    }else{
        lamtron=HP1*1.1;
        HP1=lamtronlen(lamtron);
        HP1=limitHP(HP1);
        M1=M1-70;
        M1=limitMoney(M1);
        spent+=70;
        if(spent>m) break;
    }
    if(EXP1<400){
        M1=M1-200;
        M1=limitMoney(M1);   
        lamtron=EXP1*1.13;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
        spent+=200;
        if(spent>m) break;
    }else{
        M1=M1-120;
        M1=limitMoney(M1);
        lamtron=EXP1*1.13;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
        spent+=120;
        if(spent>m) break;
    }

    if(EXP1<300){
        lamtron=EXP1*0.9;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
        M1=M1-100;
        M1=limitMoney(M1);
        spent+=100;
        if(spent>m) break;    
        
    }else{
        M1=M1-120;
        M1=limitMoney(M1);   
        spent+=120;
        lamtron=EXP1*0.9;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
        if(spent>m) break; 
    }
    }
    if(spent > m){
        lamtron=HP1*0.83;
        HP1=lamtronlen(lamtron);
        HP1=limitHP(HP1);

        lamtron=EXP1*1.17;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
    }
    }else{
    if(HP1<200){
        lamtron=HP1*1.3;
        HP1=lamtronlen(lamtron);
        HP1=limitHP(HP1);
        M1=M1-150;
        M1=limitMoney(M1);
    }else{
        lamtron=HP1*1.1;
        HP1=lamtronlen(lamtron);
        HP1=limitHP(HP1);   
        M1=M1-70;
        M1=limitMoney(M1);
    }
    if(M1 == 0){
        lamtron=HP1*0.83;
        HP1=lamtronlen(lamtron);
        HP1=limitHP(HP1);

        lamtron=EXP1*1.17;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);}
    else{
        if(EXP1<400){
        M1=M1-200;
        M1=limitMoney(M1);
        lamtron=EXP1*1.13;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
        }else{
            M1=M1-120;
            M1=limitMoney(M1);   
            lamtron=EXP1*1.13;
            EXP1=lamtronlen(lamtron);
            EXP1=limitEXP(EXP1);
        }
        if(M1 == 0){
            lamtron=HP1*0.83;
            HP1=lamtronlen(lamtron);
            HP1=limitHP(HP1);

            lamtron=EXP1*1.17;
            EXP1=lamtronlen(lamtron);
            EXP1=limitEXP(EXP1);   
        }else{ 
            if(EXP1<300){
                M1=M1-100;
                M1=limitMoney(M1); 
                lamtron=EXP1*0.9;
                EXP1=lamtronlen(lamtron);
                EXP1=limitEXP(EXP1);

                //đi bộ tới hết
                lamtron=HP1*0.83;
                HP1=lamtronlen(lamtron);
                HP1=limitHP(HP1);

                lamtron=EXP1*1.17;
                EXP1=lamtronlen(lamtron);
                EXP1=limitEXP(EXP1);       
            }else{
                if(EXP1>=300){
                    M1=M1-120;
                    M1=limitMoney(M1);
                    lamtron=EXP1*0.9;
                    EXP1=lamtronlen(lamtron);
                    EXP1=limitEXP(EXP1);
                    
                    //đi bộ tới hết
                    lamtron=HP1*0.83;
                    HP1=lamtronlen(lamtron);
                    HP1=limitHP(HP1);

                    lamtron=EXP1*1.17;
                    EXP1=lamtronlen(lamtron);
                    EXP1=limitEXP(EXP1);
                } 
            }
            }
        }
    }
    }   
    int S2; //scp gần nhất 2
    double P2; //xác xuất tìm thấy 2
    S2=scp(EXP1);
    if(EXP1>=S2) P2=1;
    else{
        P2=(double)EXP1/S2;
        P2=(P2+80)/123.0;
    } 

    //con đường 3
    int P[]={32,47,28,79,100,50,22,83,64,11};
    int i;
    int a,b;
    if(0<=E2 && E2<=9) i=E2;
    else if(10<=E2 && E2<=99){
        a=E2/10;
        b=E2%10;
        i=(a+b)%10;
    }
    double P3=P[i]/100.0;
    //ktra
    if(P1==1 && P2==1 && P3==1){
        lamtron=EXP1*0.75;
        EXP1=lamtronlen(lamtron);
        EXP1=limitEXP(EXP1);
    }else{
        double Ptb=(P1+P2+P3)/3;
        if(Ptb<0.5){
            lamtron=EXP1*1.15;
            EXP1=lamtronlen(lamtron);
            EXP1=limitEXP(EXP1);

            lamtron=HP1*0.85;
            HP1=lamtronlen(lamtron);
            HP1=limitHP(HP1);
        }else{
            lamtron=EXP1*1.20;
            EXP1=lamtronlen(lamtron);
            EXP1=limitEXP(EXP1);

            lamtron=HP1*0.9;
            HP1=lamtronlen(lamtron);
            HP1=limitHP(HP1);
        }
    }
    return HP1 + EXP1 + M1;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int ans=0;
    //ktra E3 hợp lệ
    if(E3>99 || E3<0) return -99;
    else{
    //limit input
    HP1=limitHP(HP1);
    EXP1=limitEXP(EXP1);
    HP2=limitHP(HP2);
    EXP2=limitEXP(EXP2);

    //làm tròn lên
    double lamtron;
    
    //tạo ma trận
    int route[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            route[i][j]=((E3*j) + (i*2))*(i-j);
        }
    }
    int a=0;
    int b=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(route[i][j]>E3*2){
                a+=1;
            }
            if(route[i][j]<0-E3){
                b+=1;
            }
    }
    }
    // tìm tọa độ điểm gặp nhau
    int i,j;
    // chỉ cần chạy 2 lần vì tổng 2 số không bao giờ lớn hơn 18
    if(a>10){
        int a1=a/10;
        int a2=a%10;
        i=a1+a2;
        if (i>=10){
            a1=i/10;
            a2=i%10;
            i=a1+a2;
        }    
    } else i=a;
    if(b>10){
        int b1=b/10;
        int b2=b%10;
        j=b1+b2;
        if (j>=10){
            b1=j/10;
            b2=j%10;
            j=b1+b2;
        }    
    }
    else j=b;
    //tìm chéo trái chéo phải
    int max=route[i][j];
    int taxi=0;
    int temp1=i;
    int temp2=j;
    // chéo lên trái
    while(i-1>=0 && j-1>=0){
        if(route[i-1][j-1]>route[i][j]){
            max=route[i-1][j-1];
        }
        i=i-1;
        j=j-1;
    }
    i=temp1;
    j=temp2;
    // chéo xuống trái
    while(i+1<=9 && j+1<=9){
        if(route[i+1][j+1]>max){
            max=route[i+1][j+1];
        }
        i=i+1;
        j=j+1;
    }
    i=temp1;
    j=temp2;
    // chéo lên phải
    while(i-1>=0 && j+1<=9){
        if(route[i-1][j+1]>max){
            max=route[i-1][j+1];
        }
        i=i-1;
        j=j+1;
    }
    i=temp1;
    j=temp2;
    // chéo xuống phải
    while(i+1<=9 && j-1>=0){
        if(route[i+1][j-1]>max){
            max=route[i+1][j-1]; 
        }
        i=i+1;
        j=j-1;
    }
    i=temp1;
    j=temp2;
    //lưu max
    temp1=max;
    temp2=route[i][j];
    //đưa về số dương
    if(max<0) max=max*(-1);
    if(route[i][j]<0) taxi=route[i][j]*(-1);
    else taxi=route[i][j];
    // xét độ lớn
    // kết quả
    if(max>=taxi){
        lamtron=EXP1*1.12;
        EXP1=lamtronlen(lamtron);

        lamtron=HP1*1.10;
        HP1=lamtronlen(lamtron);

        lamtron=EXP2*1.12;
        EXP2=lamtronlen(lamtron);

        lamtron=HP2*1.10;
        HP2=lamtronlen(lamtron);

        EXP1=limitEXP(EXP1);
        HP1=limitHP(HP1);
        EXP2=limitEXP(EXP2);
        HP2=limitHP(HP2);
        ans=temp1;
    }else if(max<taxi){
        lamtron=EXP1*0.88;
        EXP1=lamtronlen(lamtron);

        lamtron=HP1*0.90;
        HP1=lamtronlen(lamtron);

        lamtron=EXP2*0.88;
        EXP2=lamtronlen(lamtron);

        lamtron=HP2*0.90;
        HP2=lamtronlen(lamtron);

        EXP1=limitEXP(EXP1);
        HP1=limitHP(HP1);
        EXP2=limitEXP(EXP2);
        HP2=limitHP(HP2);
        ans=temp2;
    }
}
    return ans;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string pass = s;
    string mail = email;
    string se;
    for(int i=0;i<mail.length();i++){
        if(mail[i]=='@'){
            se = mail.substr(0,i);
        }
    }
    //ktra mật khẩu hợp lệ
    if (pass.length()<8) 
    return -1;
    if (pass.length()>20) 
    return -2;
    // ktra trùng với email
    int vitri1=0;
    int length_pass = pass.length();
    int length_se = se.length();
    int count = 0; 
    if(se.empty()) return -300;
    for (int i = 0; i <= length_pass - length_se; i++){
        count = 0;
        for (int j = 0; j < length_se; j++){
            vitri1=i;
            if (se[j] == pass[i + j]){
            count=count+1;}
            else{count=0;} 
            if (count == length_se){
            return -(300+vitri1);
            }
        }
    }

    //ktra kí tự liên tiếp
    int vitri2=-1;
    for(int i=0;i<length_pass-1;i++){
        if(pass[i]==pass[i+1] && pass[i+1] == pass[i+2]){
            vitri2=i;
            break;  
        }
    }
    if(vitri2 != -1){
        return -(400+vitri2);
    }
    //ktra kí tự đặc biệt
    int kitudacbiet = 0;
    for(int i=0;i<length_pass;i++){
        if(pass[i]=='@' || pass[i]=='#' || pass[i]=='%' || pass[i]=='$' || pass[i]=='!'){
            kitudacbiet+=1;
        }
    }
    if(kitudacbiet<1){
        return -5;
    }
    //lỗi của yêu cầu hàm
    int kitukhac=0;
    int vitri3=0;
    for(int i=0;i<length_pass;i++){
        int a = (int)pass[i];
        if(pass[i]!='@' && pass[i]!='#' && pass[i]!='%' && pass[i]!='$' && pass[i]!='!'){
            if(!((48<=a && a<=57) || (65<=a && a<=90) || (97<=a && a<=122))){
                kitukhac+=1;
                vitri3=i;
                break;
            }
        }
    }
    if(kitukhac>0){
        return vitri3;
    }
    //hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int samepwds1 = 0;
    int samepwds=0;
    string pwds;
    string pwds1;
    int loct=0;
    for(int i=0;i<num_pwds;i++){
        samepwds1=0;
        for(int j=0;j<num_pwds;j++){
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){
                samepwds1+=1;
                pwds1=arr_pwds[i];
            }
        }
        if(samepwds1>samepwds){
            samepwds=samepwds1;
            pwds=pwds1;
        }
        else{ 
            if(samepwds1==samepwds){
                if(pwds.length()<pwds1.length()){
                    samepwds=samepwds1;
                    pwds=pwds1;
                } 
            }
        }
    }
    for(int i=0;i<num_pwds;i++){
        if(arr_pwds[i]==pwds){
            loct=i;
            break;
        }
    }
    return loct;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////