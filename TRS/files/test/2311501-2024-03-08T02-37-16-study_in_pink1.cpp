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

void checkHP(int&HP){
    if(HP>666) HP=666;
    if(HP<0) HP=0;
}
void checkEXP(int&EXP){
    if(EXP>600) EXP=600;
    if(EXP<0) EXP=0;
}
void checkMoney(int & Money){
    if(Money>3000) Money=3000;
    if(Money<0) Money=0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1<0||e1>99) return -99;
    int sum;
    double temp1;
    double temp2;
    checkEXP(exp1);
    checkEXP(exp2);
    if(e1<=3) {
        if(e1==0) exp2+=29;
        else if(e1==1) exp2+=45;
        else if(e1==2) exp2+=75;
        else exp2+=(29+45+75);

        int D=e1*3+exp1*7; //Gia tri quyet dinh
        if(D%2==0) {
            temp1=exp1+double(D)/200; //Sherlock tra loi dung
            exp1=exp1+D/200;
        }
        else {
            temp1=exp1-double(D)/100; //Sherlock tra loi sai
            exp1=exp1-D/200;
        }
        if(temp1 - static_cast<int>(temp1)>0) exp1 = temp1 + 1;
        else exp1=temp1;
        checkEXP(exp1);
        checkEXP(exp2);
        sum=(exp1+exp2);
    }
    else {
        if(e1<=19)
        {
            temp2=exp2+double(e1)/4+19;
            exp2=exp2+e1/4+19;
        }
        else if(e1<=49)
        {
            temp2=exp2+double(e1)/9+21;
            exp2=exp2+e1/9+21;
        }
        else if(e1<=65)
        {
            temp2=exp2+double(e1)/16+17;
            exp2=exp2+e1/16+17;
        }
        else if(e1<=79)
        {
             temp2=exp2+double(e1)/4+19;
             if(temp2 - static_cast<int>(temp2)>0) exp2 = temp2 + 1;
             else exp2=temp2;
             checkEXP(exp2);
             if(exp2>200) temp2=exp2+double(e1)/9+21;

        }
        else
        {
             temp2=exp2+double(e1)/4+19;
             if(temp2 - static_cast<int>(temp2)>0) exp2 = temp2 + 1;
             else exp2=temp2;
             temp2=exp2+double(e1)/9+21;
             if(temp2 - static_cast<int>(temp2)>0) exp2 = temp2 + 1;
             else exp2=temp2;
             checkEXP(exp2);
             if(exp2>400)
             {
                temp2=exp2+double(e1)/16+17;
                if(temp2 - static_cast<int>(temp2)>0) exp2 = temp2 + 1;
                else exp2=temp2;
                checkEXP(exp2);
                temp2=exp2+double(exp2)*15/100; //Watson duoc cong them 15% EXP hien co (sau khi da cap nhat EXP cho ca 3 thong tin )
             }
        }
        exp1-=e1;//Sherlock sai vi Harry la chi gai
        if(temp2 - static_cast<int>(temp2)>0) exp2 = temp2 + 1;
        else exp2=temp2;
        checkEXP(exp1);
        checkEXP(exp2);
        sum=(exp1+exp2);
    }
    return sum;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    if(E2<0||E2>99) return -99;

/////Con duong 1/////

    double P1; //Xac suat 1 de Sherlock tim thay vali
    int S; //So chinh phuong gan voi EXP1 nhat
    checkHP(HP1);
    checkEXP(EXP1);
    checkMoney(M1);
    int SqrtExp1=sqrt(EXP1);
    if (SqrtExp1*SqrtExp1 == EXP1) { //Kiểm tra xem EXP1 có phải là số chính phương không
        S = EXP1;
    } else {
        int lowerSqr=SqrtExp1*SqrtExp1; //Lấy số chính phương gần nhất nhỏ hơn
        int upperSqr=(SqrtExp1+1)*(SqrtExp1+1); //Lấy số chính phương gần nhất lớn hơn
        S=(upperSqr-EXP1)<(EXP1-lowerSqr)?upperSqr:lowerSqr; //So sánh để chọn số chính phương gần nhất
    }
    if(EXP1>=S) P1=100;
    else P1=(double(EXP1)/S+80)*100/123;

/////Con duong 2/////
    double roundMoney=double(M1)*0.5;
    double P2; //Xac suat 2 de Sherlock tim thay vali
    double temp1;
    double temp2;
    if(E2%2!=0)
    {
        int moneyAtFirst=M1; //So tien ban dau
        while (M1>0)
        {
            //Su kien 1//
            if(HP1<200)
            {
                temp1=double(HP1)*1.3;
                HP1=HP1*1.3;
                if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
                else HP1=temp1;
                M1-=150;
            }
            else
            {
                temp1=double(HP1)*1.1;
                HP1=HP1*1.1;
                if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
                else HP1=temp1;
                M1-=70;
            }
            checkHP(HP1);
            checkMoney(M1);
            if((moneyAtFirst-M1)>roundMoney) break;

            //Su kien 2//
            if(EXP1<400) M1-=200;
            else M1-=120;
            temp2=double(EXP1)*1.13;
            EXP1=EXP1*1.13;
            if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
            else EXP1=temp2;
            checkEXP(EXP1);
            checkMoney(M1);
            if((moneyAtFirst-M1)>roundMoney) break;

            //Su kien 3//
            if(EXP1<300) M1-=100;
            else M1-=120;
            temp2=double(EXP1)*0.9;
            EXP1=EXP1*0.9;
            if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
            else EXP1=temp2;
            checkEXP(EXP1);
            checkMoney(M1);
            if((moneyAtFirst-M1)>roundMoney) break;
        }

    temp1=double(HP1)*0.83;
    HP1=HP1*0.83;
    temp2=double(EXP1)*1.17;
    EXP1=EXP1*1.17;

    if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
    else HP1=temp1;
    if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
    else EXP1=temp2;

    checkEXP(EXP1);
    checkHP(HP1);
    checkMoney(M1);

    }

    else
    {
        while(M1>0)
        {
            //Su kien 1//
            if(HP1<200)
            {
                temp1=double(HP1)*1.3;
                HP1=HP1*1.3;
                if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
                else HP1=temp1;
                M1-=150;
            }
            else
            {
                temp1=double(HP1)*1.1;
                HP1=HP1*1.1;
                if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
                else HP1=temp1;
                M1-=70;
            }

            checkHP(HP1);
            checkMoney(M1);
            if(M1<=0) break;

            //Su kien 2//
            if(EXP1<400) M1-=200;
            else M1-=120;
            temp2=double(EXP1)*1.13;
            EXP1=EXP1*1.13;
            if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
            else EXP1=temp2;
            checkEXP(EXP1);
            checkMoney(M1);
            if(M1<=0) break;

            //Su kien 3//
            if(EXP1<300) M1-=100;
            else M1-=120;
            temp2=double(EXP1)*0.9;
            EXP1=EXP1*0.9;
            if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
            else EXP1=temp2;
            checkEXP(EXP1);
            checkMoney(M1);
            if(M1<=0) break;

            break;
        }

    temp1=double(HP1)*0.83;
    HP1=HP1*0.83;
    temp2=double(EXP1)*1.17;
    EXP1=EXP1*1.17;

    if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
    else HP1=temp1;

    if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
    else EXP1=temp2;

    checkEXP(EXP1);
    checkHP(HP1);
    checkMoney(M1);

    }

    SqrtExp1=sqrt(EXP1);
    if (SqrtExp1 * SqrtExp1 == EXP1) {
        S = EXP1;
    } else {
        int lowerSqr = SqrtExp1 * SqrtExp1;
        int upperSqr = (SqrtExp1 + 1) * (SqrtExp1 + 1);
        S = (upperSqr - EXP1) < (EXP1 - lowerSqr) ? upperSqr : lowerSqr;
    }
    if(EXP1>=S) P2=100;
    else P2=(double(EXP1)/S+80)*100/123;

///Con duong 3///
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int i; //Tri so gia tri xac suat Pi
    if(E2>=10) {
        E2=E2/10+E2%10;
        if(E2>=10) i=E2-(E2/10)*10;
        else i=E2;
    }
    else i=E2;
    double P3=P[i];

///Sau khi di het 3 con duong///
    double finalProbability=(P1+P2+P3)/3;
    if(P1==P2&&P1==P3&&P1==100) {
        temp2=double(EXP1)*0.75; //Sherlock nham lan
        if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
        else EXP1=temp2;
    }
    else if(finalProbability<50)
    {
        temp1=double(HP1)*0.85;
        temp2=double(EXP1)*1.15;
        if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
        else HP1=temp1;
        if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
        else EXP1=temp2;

    }
    else
    {
        temp1=double(HP1)*0.9;
        temp2=double(EXP1)*1.2;
        if(temp1 - static_cast<int>(temp1)>0.001) HP1 = temp1 + 1;
        else HP1=temp1;
        if(temp2 - static_cast<int>(temp2)>0.001) EXP1 = temp2 + 1;
        else EXP1=temp2;

    }

    checkEXP(EXP1);
    checkHP(HP1);
    checkMoney(M1);
    int sum=HP1+EXP1+M1;

    return sum;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0||E3>99) return -99;
    long long taxiPoint[10][10]; //Ma tran diem cua taxi
    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            taxiPoint[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    int countBigger=0, countSmaller=0;
    for(int i=1; i<10; i++) {
        for(int j=0; j<i; j++) {
            if(taxiPoint[i][j]>(E3*2)) countBigger++;
        }
    }
    while(countBigger>=10)
    {
        countBigger=countBigger/10+countBigger%10;
    }
    for(int j=1; j<10; j++) {
        for(int i=0; i<j; i++) {
            if(taxiPoint[i][j]<(-E3)) countSmaller++;
        }
    }
    while(countSmaller>=10)
    {
        countSmaller=countSmaller/10+countSmaller%10;
    }
    int i=countBigger, j=countSmaller; //i, j la toa do cua taxi
    long long mark[10][10]; //Ma tran cua Sherlock va Watson (chua tính gia tri lon nhat)
    for(int u=0; u<10; u++){
        for(int v=0; v<10; v++){
            if(u>=v&&u-v==i-j) mark[u][v]=taxiPoint[u][v];
            else if(v>u&&v-u==j-i) mark[u][v]=taxiPoint[u][v];
            else if(u+v==i+j) mark[u][v]=taxiPoint[u][v];
            else mark[u][v]=0;
        }
    }
    long long pointOfSherlockteam=mark[0][0];
     for(int u=0; u<10; u++){
        for(int v=0; v<10; v++){
            if(mark[u][v]>pointOfSherlockteam) pointOfSherlockteam=mark[u][v];
        }
    }
    double temp1;
    double temp2;
    double temp3;
    double temp4;
    if(abs(taxiPoint[i][j])<=pointOfSherlockteam){
        temp1=double(EXP1)*1.12;
        temp2=double(EXP2)*1.12;
        temp3=double(HP1)*1.1;
        temp4=double(HP2)*1.1;
        if(temp1 - static_cast<int>(temp1)>0.001) EXP1 = temp1 + 1;
        else EXP1=temp1;
        if(temp2 - static_cast<int>(temp2)>0.001) EXP2 = temp2 + 1;
        else EXP2=temp2;
        if(temp3 - static_cast<int>(temp3)>0.001) HP1 = temp3 + 1;
        else HP1=temp3;
        if(temp4 - static_cast<int>(temp4)>0.001) HP2 = temp4 + 1;
        else HP2=temp4;
    } //Duoi kip taxi
    else {
        temp1=double(EXP1)*0.88;
        temp2=double(EXP2)*0.88;
        temp3=double(HP1)*0.9;
        temp4=double(HP2)*0.9;

        if(temp1 - static_cast<int>(temp1)>0.001) EXP1 = temp1 + 1;
        else EXP1=temp1;
        if(temp2 - static_cast<int>(temp2)>0.001) EXP2 = temp2 + 1;
        else EXP2=temp2;
        if(temp3 - static_cast<int>(temp3)>0.001) HP1 = temp3 + 1;
        else HP1=temp3;
        if(temp4 - static_cast<int>(temp4)>0.001) HP2 = temp4 + 1;
        else HP2=temp4;
    } //Khong duoi kip taxi

    checkHP(HP1);
    checkHP(HP2);
    checkEXP(EXP1);
    checkEXP(EXP2);

    long long finalPoint;
    if(abs(taxiPoint[i][j])<=pointOfSherlockteam) finalPoint=pointOfSherlockteam;
    else finalPoint=taxiPoint[i][j];

    return finalPoint;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    string passNeededtoCheck=s;
    int result=-10;

    //Tao se - chuoi ki tu nam truoc @
    int Position;
    for(int i = 0; i<strlen(email); i++) {
        if(email[i] == '@') {
            Position = i;
        }
    }
    char* se=new char[Position+1];
    strncpy(se, email, Position);
    se[Position]='\0';

    string allowedChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%$!";
    int x=passNeededtoCheck.find_first_not_of(allowedChars);
    if(x>=0&&x<=strlen(s)) result=x;

    int hasSpecial=0;
    for (int i=0; s[i]!='\0'; i++)
    {
        if (s[i] == '@' || s[i]== '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') hasSpecial=1;
    }
    if(hasSpecial==0) result= -5;

    int pos1;
    for(int i=0; i<strlen(s)-2; i++)
    {
        if(s[i]==s[i+1]&&s[i+1]==s[i+2])
        {
            pos1=i;
            break;
        }
        else pos1=100;
    }

    int pos2;
    const char *temp = strstr(s, se);
    if(temp != NULL) {
        pos2 = temp - s;
    }
    else pos2=100;

    if(pos1!=100) result=-(400+pos1);
    if(pos2!=100) result=-(300+pos2);

    if(strlen(s)<8) result= -1; //Co do dai ngan hon do dai toi thieu
    if(strlen(s)>20) result= -2; //Co do dai dai hon do dai toi da

    return result;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    int Correct=0;
    int Length=0;
    const char* correctPass;
    for(int i=0; i<num_pwds; i++)
    {
        int count=0;
        for(int j=0; j<num_pwds; j++)
        {
            if(strcmp(arr_pwds[i], arr_pwds[j]) == 0)
            {
                count++;
            }
        }
        if(count>Correct||(count==Correct&&strlen(arr_pwds[i])>Length))
        {
                correctPass=arr_pwds[i];
                Length=strlen(arr_pwds[i]);
                Correct=count;
        }
    }
    int pass;
    for(int i=0; i<num_pwds; i++){
        if(arr_pwds[i]==correctPass)
            {
                pass=i;
                break;
            }
    }
    return pass;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
