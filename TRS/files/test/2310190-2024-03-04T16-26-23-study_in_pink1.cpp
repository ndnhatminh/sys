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
    if (E1>99 || E1<0) return -99;
    //Truong hop 1
    int D;
    float temp;
    if (E1==0) {EXP2+= 29;}
        else if (E1==1) {EXP2+= 45;}
            else if (E1==2) {EXP2+= 75;}
                else if (E1==3) {EXP2+= 149;}
    if (E1>=0&&E1<=3) {
        D=E1*3+EXP1*7;
        if (D%2==0) EXP1= ceil(EXP1+D/200.0);
            else EXP1= ceil(EXP1-D/100.0);
        }
    //Truong hop 2
    if (E1>=4&&E1<=19) {EXP2= ceil(EXP2+E1/4.0+19);}
        else if (E1>=20&&E1<=49) {EXP2= ceil(EXP2+E1/9.0+21);}
            else if (E1>=50&&E1<=65) {EXP2= ceil(EXP2+E1/16.0+17);}
                else if (E1>=66&&E1<=79) {
                    EXP2=ceil(EXP2+ E1/4.0+19);
                    if (EXP2>200) {EXP2=ceil(EXP2+E1/9.0+21);}
                    }
                         else if (E1>=80&&E1<=99){
                            temp= ceil(EXP2+E1/4.0+19);
                           EXP2= ceil(temp+E1/9.0+21);
                           if (EXP2>400) {
                            temp= ceil(EXP2+E1/16.0+17);
                            EXP2= ceil (temp*115.0/100);
                           }     
                         }
    //check dieu kien dau vao
    if (E1>=4&&E1<=99) EXP1=EXP1-E1;
    if (EXP1<0) EXP1=0;
    if (EXP2<0) EXP2=0;
    if (EXP1>600) EXP1=600;
    if (EXP2>600) EXP2=600;
    return EXP1+EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) return -99;
    double P1, P2, P3;
    int M=0, M0;
    M0=M1;
    //---------------------------------------------Road 01-------------------------------------------------
    int S=sqrt(EXP1);
    if (((EXP1-(S*S))<((S+1)*(S+1)-EXP1))||S==sqrt(EXP1)) {P1=100/100.0;}
        else {P1=(((float(EXP1)/float((S+1)*(S+1)))+80.0)/123.0);}
   //---------------------------------------------Road 0w-------------------------------------------------
    for(int i=0; i<=10; i++){
        if (M0==0) {
            HP1=ceil(HP1*83.0/100);
            EXP1=ceil(EXP1*117.0/100);
            break;
        }
        if (HP1<200) {
            HP1=ceil(HP1*13.0/10);
            M1=M1-150;
            M=M+150;
        } else {
            HP1=ceil(HP1*11.0/10);
            M1=M1-70;
            M+=70;
        } 
        if (EXP1<0) EXP1=0;
        if (EXP1>600) EXP1=600;
        if (HP1<0) HP1=0;
        if (HP1>666) HP1=666; 
        if (M1<0) M1=0;
        if (M1>3000) M1=3000;
        if (E2%2!=0&&M>(M0/2)) {
            HP1=ceil(HP1*83.0/100);
            EXP1=ceil(EXP1*117.0/100);
            break;
            }else if (E2%2==0&&M1==0) {
                HP1=ceil(HP1*83.0/100);
                EXP1=ceil(EXP1*117.0/100);
                break;
        }
        if (EXP1<400) {
            M1=M1-200;
            M+=200;
            EXP1=ceil(EXP1*113.0/100);
        } else {
            M1=M1-120;
            M+=120;
            EXP1=ceil(EXP1*113.0/100);
        }
        if (EXP1<0) EXP1=0;
        if (EXP1>600) EXP1=600;
        if (HP1<0) HP1=0;
        if (HP1>666) HP1=666; 
        if (M1<0) M1=0;
        if (M1>3000) M1=3000;
        if (E2%2!=0&&(M>(M0/2))) {
            HP1=ceil(HP1*83.0/100);
            EXP1=ceil(EXP1*117.0/100);
            break;
            }else if (E2%2==0&&M1==0) {
                HP1=ceil(HP1*83.0/100);
                EXP1=ceil(EXP1*117.0/100);
                break;
        }
        if (EXP1<300) {
            M1-=100;
            M+=100;
            EXP1=ceil(EXP1*9.0/10);
        } else {
            M1-=120;
            M+=120;
            EXP1=ceil(EXP1*9.0/10);
        }
        if (EXP1<0) EXP1=0;
        if (EXP1>600) EXP1=600;
        if (HP1<0) HP1=0;
        if (HP1>666) HP1=666; 
        if (M1<0) M1=0;
        if (M1>3000) M1=3000;
        if (E2%2!=0&&M>(M0/2)) {
            HP1=ceil(HP1*83.0/100);
            EXP1=ceil(EXP1*117.0/100);
            break;
            }else if (E2%2==0&&M1==0) {
                HP1=ceil(HP1*83.0/100);
                EXP1=ceil(EXP1*117.0/100);
                break;
        }
        if (E2%2==0){
            HP1=ceil(HP1*83.0/100);
            EXP1=ceil(EXP1*117.0/100);
            break;
        }
    }
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666; 
    if (M1<0) M1=0;
    if (M1>3000) M1=3000;
    int S1=sqrt(EXP1);
    if (((EXP1-(S1*S1))<((S1+1)*(S1+1)-EXP1))||S1==sqrt(EXP1)) {P2=(100/100.0);}
    else {P2=(((float(EXP1)/float((S1+1)*(S1+1)))+80)/123.0);}
   //---------------------------------------------Road 03-------------------------------------------------
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2<10) {P3= float(P[E2])/100.0;}
        else {
            int temp=floor(E2/10.0)+(E2-(floor(E2/10.0)*10));
            if (temp>=10) {temp-=10;}
            P3= float(P[temp])/100.0;
            }
    if (P1==1.0&&P2==P1&&P3==P1) {EXP1=ceil(EXP1*75.0/100);}
        else if (((P1+P2+P3)/3.0)<(5.0/10)) {
            HP1=ceil(HP1*85.0/100);
            EXP1=ceil(EXP1*115.0/100);
        } else if (((P1+P2+P3)/3.0)>=(5.0/10)) {
            HP1=ceil(HP1*9.0/10);
            EXP1=ceil(EXP1*12.0/10);
        }
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666; 
    if (M1<0) M1=0;
    if (M1>3000) M1=3000;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    //khai bao mang 2 chieu luu diem taxi
    if (E3<0||E3>99) return -99;
    int Matrix[10][10];
    for (int a=0; a<10; a++){
        for (int b=0; b<10; b++){
            Matrix[a][b]=((E3*b)+(a*2))*(a-b);
        }
    }
    //tim so bigger va smaller (so voi de cho)
    int bigger=0, smaller=0;
    for (int c=0; c<10; ++c){
        for (int d=0; d<10; ++d){
            if (Matrix[c][d]>(2*E3)) bigger=bigger+1;
                else if (Matrix[c][d]<(-E3)) smaller=smaller+1;
        }
    }
    //tim toa do i j la diem ma gap taxi
    int i, j, temp1, temp2;
    temp1=bigger;
    if (bigger<10) {
        i=bigger;
    } else {
        for(int e=0;e<10;++e){
            i=floor(temp1/10.0)+(temp1-floor(temp1/10.0)*10);
            temp1=i;
            if(i<10) break;
    }
    }
    temp2=smaller;
    if (smaller<10) {
        j=smaller;
    } else {
        for(int f=0;f<10;++f){
            j=floor(temp2/10.0)+(temp2-floor(temp2/10.0)*10);
            temp2=j;
            if (j<10) break;
    }
    }
    int TaxiPoint;
    TaxiPoint=Matrix[i][j];
    //tim gia tri lon nhat tai ca 2 duong cheo tinh tu diem gap nhau=> diem Sherlock
    int SherlockPoint;
    SherlockPoint=Matrix[i][j];
    for (int g=0; g<10; ++g){
        if ((i-g)<0||(j-g)<0) break;
        if(Matrix[i-g][j-g]>SherlockPoint) {
            SherlockPoint=(Matrix[i-g][j-g]);
        }
    }
    for (int k=0; k<10; ++k){
        if ((i+k)>9||(j+k)>9) break;
        if(Matrix[i+k][j+k]>SherlockPoint) {
            SherlockPoint=(Matrix[i+k][j+k]);
        }
    }
    for (int l=0; l<10; ++l){
        if ((i-l)<0||(j+l)>9) break;
        if(Matrix[i-l][j+l]>SherlockPoint) {
            SherlockPoint=(Matrix[i-l][j+l]);
        }
    }
    for (int m=0; m<10; ++m){
        if ((i+m)>9||(j-m)<0) break;
        if(Matrix[i+m][j-m]>SherlockPoint) {
            SherlockPoint=(Matrix[i+m][j-m]);
        }
    }
    if (abs(TaxiPoint)>abs(SherlockPoint)){
        EXP1=ceil(EXP1*88.0/100);
        EXP2=ceil(EXP2*88.0/100);
        HP1=ceil(HP1*9.0/10);
        HP2=ceil(HP2*9.0/10);
        if (EXP1<0) EXP1=0;
        if (EXP2<0) EXP2=0;
        if (EXP1>600) EXP1=600;
        if (EXP2>600) EXP2=600;
        if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
        if(HP2<0) HP2=0;
        if(HP2>666) HP2=666;
        return TaxiPoint;
    } else {
        EXP1=ceil(EXP1*112.0/100);
        EXP2=ceil(EXP2*112.0/100);
        HP1=ceil(HP1*11.0/10);
        HP2=ceil(HP2*11.0/10);
        if (EXP1<0) EXP1=0;
        if (EXP2<0) EXP2=0;
        if (EXP1>600) EXP1=600;
        if (EXP2>600) EXP2=600;
        if(HP1<0) HP1=0;
        if(HP1>666) HP1=666;
        if(HP2<0) HP2=0;
        if(HP2>666) HP2=666;
    }
    return SherlockPoint;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    char se[100];
    for(int i=0 ; email[i]!='\0' ; ++i){
        if(email[i] == '@'){
            se[i] = '\0';
            break;
        }
        se[i] = email[i];
    }
    int L1=0;
    for(int i=0; se[i]!='\0';++i){
        L1+=1;
    }
    int L0=0;
    for(int j=0;s[j]!='\0';++j){
        L0+=1;
    }
    if (L0<8) return -1;
    if (L0>20) return -2;
    int a=0, b=0;
    if(se[0]=='\0') return -300;
    else {for(int i=0;i<=L0-L1;++i){
            for(int j=0 ; j<L1 ;++j){
                if(s[i+j]==se[j]) a+=1;
            }if(a==L1){
                b=i+1; //tim vi tri ma chuoi se xuat hien dau tien trong s, +1 de phan biet voiw TH =0 
                break;
            }
            a=0;
            }
         }
    if(b!=0) return -(300+b-1);//vi nay +1 de phan bien nen bay gio tru 1
    for (int i=0; i<L0; i++){
        if(s[i]==s[i+1]&&s[i+1]==s[i+2]) return -(400+i);
    }
    int q=0;
    for (int i=0; s[i]!='\0'; i++){
        if ((s[i]!='@')&&(s[i]!='#')&&(s[i]!='%')&&(s[i]!='$')&&(s[i]!='!')){q+=1;}
    } if (q==L0) return -5;
    int dc=0;
    for (int i=0; s[i]!='\0'; i++){
        if ((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')||s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
            dc+=1; //khong quan tam dc
        }else return i;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int a, pwFreq=0, maxfreq=0, pwDir, pwLength, maxlength;
    for (int i=0; i<num_pwds; i++){
        pwLength=strlen(arr_pwds[i]);
        for (int j=0;j<num_pwds; j++){
            a=strcmp(arr_pwds[i],arr_pwds[j]);
            if (a==0) {pwFreq+=1;}
        }// so sanh tan so va gan gt kich thuoc tai i=0 cho max length
        if(pwFreq>maxfreq){
            maxfreq=pwFreq;
            pwDir=i;
            maxlength=pwLength;
        }else if(pwFreq==maxfreq&&(pwLength>maxlength)){
            pwDir=i;
            maxlength=pwLength;
        }
        pwFreq=0; //bat dau lai chu ki moi cho viec tinh tan so
    }
    return pwDir;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////