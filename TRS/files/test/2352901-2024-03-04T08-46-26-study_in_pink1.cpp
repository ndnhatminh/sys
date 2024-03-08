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
int firstMeet(int & exp1, int & exp2, int e1) {
    float temp1=exp1, temp2=exp2;
    if(temp2>600) temp2=600;
    if(temp1>600) temp1=600;
    if(temp1<0) temp1=0;
    if(temp2<0) temp2=0;
    if(e1>=0&&e1<=3){
        if(e1==0) {temp2+=29;
            if(temp2>600) temp2=600;
        }
        else if(e1==1) {
            temp2+=45;
            if(temp2>600) temp2=600;
        }
        else if(e1==2) {
            temp2+=75;
            if(temp2>600) temp2=600;
        }
        else {
            temp2+=29+45+75;
            if(temp2>600) temp2=600;
        }
        int D=e1*3+temp1*7;
        if(D%2==0){
            temp1+=(D/200.0);
            temp1=ceil(temp1);
            if(temp1>600) temp1=600;
        }
        else {temp1=(temp1)-D/100.0;
            temp1=ceil(temp1);
            if(temp1<0) temp1=0;
        }
    }
    else if(e1>=4&&e1<=99){
        if(e1>=4&&e1<=19) {
            temp2+=ceilf(double(e1)/4)+19;
            if(temp2>600) temp2=600;
        }
        else if(e1>19&&e1<50) {
            temp2+=ceilf(double(e1)/9)+21;
            if(temp2>600) temp2=600;
        }
        else if (e1>49&&e1<66) {
            temp2+=ceilf(double(e1)/16)+17;
            if(temp2>600) temp2=600;
        }
        else if (e1>65&&e1<80) {
            temp2+=ceilf(double(e1)/4)+19;
            if(temp2>200) temp2+=ceilf(double(e1)/9)+21;
            if(temp2>600) temp2=600;
        }
        else {
            temp2+=ceil(double(e1)/4.0)+19;
            temp2+=ceil(double(e1)/9.0)+21;
            if(temp2>600) temp2=600;
            if(temp2>400){
                temp2+=ceil(double(e1)/16.0)+17;
                temp2=ceil(double(temp2)*115.0/100);
                if(temp2>600) temp2=600;
            };
        }
        temp1-=e1;
        temp1=ceil(temp1);
        if(temp1<0) temp1=0;
    }
    else return -99;
    
    exp1=temp1;
    exp2=temp2;
    return exp1 + exp2;
}

// Task 2
void Tinh_P(int EXP1,double &P){
    int S=EXP1;
    int i=S,j=S;
    while (true) {
        int s=sqrt(i),q=sqrt(j);
        if(s*s==i){
            S=i;
            break;
        }
        if(q*q==j){
            S=j;
            break;
        }
        i++;
        j--;
    }
    if(EXP1>=S){
        P=1;
    }
    else{
        P=(double(EXP1)/441.0+80)/123;
    }
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2>=0&&E2<100){
        if(M1<0) M1=0;
        if(M1>3000) M1=3000;
        if(HP1>666) HP1=666;
        if(HP1<0) HP1=0;
        if(EXP1>600) EXP1=600;
        if(EXP1<0) EXP1=0;
        //con duong 1
        double P1=0;
        if(EXP1>600) EXP1=600;
        Tinh_P(EXP1, P1);
        //con duong 2
        double P2=0;
        if(E2%2!=0){
            //E2 la so le
            float temp=M1;
            while(true)
            {
                if(M1==0) {
                    break;
                }
                //su kien 1
                if(HP1<200){
                    HP1=ceil(double(HP1)*130.0/100.0);if(HP1>666) HP1=666;
                    M1-=150;
                    if(M1<=0) {
                        M1=0;
                        break;
                    }
                    if(M1<(temp/2)) break;
                }
                else{
                    HP1=ceil(double(HP1)*110.0/100.0);if(HP1>666) HP1=666;
                    M1-=70;
                    if(M1<=0) {
                        M1=0;
                        break;
                    }
                    if(M1<(temp/2)) break;
                }
                //su kien 2
                if(EXP1<400){
                    M1-=200;
                }
                else M1-=120;
                EXP1=ceil(double(EXP1)*113.0/100.0); if(EXP1>600) EXP1=600;
                if(M1<=0) {
                    M1=0;
                    break;
                }
                if(M1<(temp/2)) break;
                //su kien3
                if(EXP1<300) M1-=100;
                else M1-=120;
                EXP1=ceil(double(EXP1)*90.0/100.0);
                if(M1<=0) {
                    M1=0;
                    break;
                }
                if(M1<(temp/2)) break;
            }
        }
        //E2 la so chan
        else{
            if(M1<0) M1=0;
            if(M1>3000) M1=3000;
            if(HP1>666) HP1=666;
            if(HP1<0) HP1=0;
            if(EXP1>600) EXP1=600;
            if(EXP1<0) EXP1=0;
            int i=0;
            while( i<1)
            {
                if(M1==0) {
                    break;
                }
                //su kien 1
                if(HP1<200){
                    HP1=ceil(double(HP1)*130.0/100.0); if(HP1>666) HP1=666;
                    M1-=150;
                    if(M1<=0) {
                        M1=0;
                        break;
                    }
                }
                else{
                    HP1=ceil(double(HP1)*110.0/100.0);if(HP1>666) HP1=666;
                    M1-=70;
                    if(M1<=0) {
                        M1=0;
                        break;
                    }
                }
                //su kien 2
                if(EXP1<400){
                    M1-=200;
                }
                else M1-=120;
                EXP1=ceil(double(EXP1)*113.0/100.0); if(EXP1>600) EXP1=600;
                if(M1<=0) {
                    M1=0;
                    break;
                }
                //su kien3
                if(EXP1<300) M1-=100;
                else M1-=120;
                EXP1=ceil(double(EXP1)*90.0/100.0);
                if(M1<=0) {
                    M1=0;
                    break;
                }
                i=1;
            }
        }
        HP1=ceil(double(HP1)*83.0/100.0);
        EXP1=ceil(double(EXP1)*117.0/100.0);
        if(HP1>666) HP1=666;
        if(EXP1>600) EXP1=600;
        Tinh_P(EXP1, P2);
        //con duong so 3
        double arr[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        double P3;
        if(E2<10) i=E2;
        else{ int tong=E2%10+E2/10;
            if(tong>=10){
                i=tong%10;}
            else i=tong;
        }
        P3=(arr[i]/100);
        //    tinh EXP
        if(P1==P2&&P2==P3&&P1==1){
            EXP1=ceil(double(EXP1)*75.0/100.0);
        }
        else{
            if(((P1+P2+P3)/3)<0.5){
                HP1=ceil(double(HP1)*85.0/100.0);if(HP1>666) HP1=666;
                EXP1=ceil(double(EXP1)*115.0/100.0);
                if(EXP1>600) EXP1=600;
            }
            else{
                HP1=ceil(double(HP1)*90/100);if(HP1>666) HP1=666;
                EXP1=ceil(double(EXP1)*120/100);
                if(EXP1>600) EXP1=600;
            }
        }
        return HP1 + EXP1 + M1;
    }
    else return -99;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3>=0&&E3<100){
        if(HP2>666) HP2=666;
        if(HP2<0) HP2=0;
        if(HP1>666) HP1=666;
        if(HP1<0) HP1=0;
        if(EXP1>600) EXP1=600;
        if(EXP1<0) EXP1=0;
        if(EXP2>600) EXP2=600;
        if(EXP2<0) EXP2=0;
        int arr[10][10];
        int positive_number=0,negative_number=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                arr[i][j]=((E3*j)+(i*2))*(i-j);
                if(arr[i][j]>E3*2) positive_number+=1;
                if(arr[i][j]<E3*(-1)) negative_number+=1;
            }
        }
        //tim dia diem gap nhau
        int i,j;
        while(positive_number>9){
            positive_number=positive_number %10+positive_number/10;
        }
        while(negative_number>9){
            negative_number=negative_number %10+negative_number/10;
        }
        i=positive_number;j=negative_number;
        //tim so cua sherlock
        int taxi=arr[i][j];
        int max=arr[i][j];
        while(i<10&& j>=0)
        {
            if(arr[i][j]>max) max=arr[i][j];
            i++;j--;
        }
        i=positive_number;j=negative_number;
        while(i>=0&& j<10)
        {
            if(arr[i][j]>max) max=arr[i][j];
            i--;j++;
        }
        i=positive_number;j=negative_number;
        while(i>=0&& j>=0)
        {
            if(arr[i][j]>max) max=arr[i][j];
            i--;j--;
        }
        i=positive_number;j=negative_number;
        while(i<10&& j<10)
        {
            if(arr[i][j]>max) max=arr[i][j];
            i++;j++;
        }
        if(max>=abs(taxi)){
            HP1=ceil(double(HP1)*110.0/100.0);
            EXP1=ceil(double(EXP1)*112.0/100.0);
            if(HP1>666) HP1=666;
            if(EXP1>600) EXP1=600;
            HP2=ceil(double(HP2)*110.0/100.0);
            EXP2=ceil(double(EXP2)*112.0/100.0);
            if(HP2>666) HP2=666;
            if(EXP2>600) EXP2=600;
            return max;
        }
        else{
            HP1=ceil(double(HP1)*90/100);
            EXP1=ceil(double(EXP1)*88/100);
            if(HP1>666) HP1=666;
            if(EXP1>600) EXP1=600;
            HP2=ceil(double(HP2)*90/100);
            EXP2=ceil(double(EXP2)*88/100);
            if(HP1>666) HP1=666;
            if(EXP1>600) EXP1=600;
            return taxi;
        }
        return -1;
    }
    else return -99;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string se="";
    bool flag1=false,flag2=false,flag3=false,flag4=false;
    int sci=0,sei=0,special=0;
    for(int i=0;i<strlen(email);i++){
        if(email[i]!='@') se+=email[i];
        else break;
    }
    for(int i=0;i<strlen(s)-2;i++){
        if(s[i]==s[i+1]&&s[i+2]==s[i]){
            sci=i;
            flag1=true;
            break;
        }
    }
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='@'|| s[i]=='#'|| s[i]=='%'|| s[i]=='$'|| s[i]=='!'){
            flag2=false;
            break;
        }
        else {
            flag2 = true;
        }
    }
    for(int i=0;i<strlen(s);i++){
        if(string(s).substr(i,se.length())==se){
            flag3=true;
            sei=i;
            break;
        }
    }
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='@'|| s[i]=='#'|| s[i]=='%'|| s[i]=='$'|| s[i]=='!'||(s[i]>=48 && s[i]<=57)||(s[i]>=65&& s[i]<=90)||(s[i]>=97 && s[i]<=122)){
            flag4=false;
        }
        else {
            flag4=true;
            special=i;
            break;
        }
    }
    if(strlen(s)<8){
        return -1;
    }
    else if(strlen(s)>20){
        return -2;
    }
    else if(flag3){
        return -(300+sei);
    }
    else if(flag1){
        return -(400+sci);
    }
    else if(flag4){
        return special;
    }
    else if (flag2){
        return -5;
    }
    else return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string temp[30];
    temp[0]=arr_pwds[0];
    int k=1;
    for(int i=1;i<num_pwds;i++){
        bool flag=true;
        for(int j=0;j<i;j++)
        {
            if(arr_pwds[i]==arr_pwds[j]){
                flag=false;
                break;
            }
        }
        if(flag){
            temp[k]=arr_pwds[i];
            k+=1;
        }
    }
    int count_max=0;
    int index_max=0;
    string max="";
    for(int i=0;i<k+1;i++){
        int count=0;
        for(int j=0;j<num_pwds;j++){
            if(temp[i]==arr_pwds[j]){
                count+=1;
            }
        }
        if(count>count_max) {count_max=count;
            max=temp[i];
        }
        if(count==count_max){
            if(temp[i].length()>max.length()){
                max=temp[i];
            }
        }
    }
    for(int i=0;i<num_pwds;i++){
        if(arr_pwds[i]==max) {
            index_max=i;
            break;
        }
    }

    return index_max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
