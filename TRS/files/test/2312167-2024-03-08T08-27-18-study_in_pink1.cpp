
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
        int &E3
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
    } else {
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
int kn(int n) {
n = (n < 0) ? 0 : (n > 600) ? 600 : n;
return n;
}
int mau(int n) {
n = (n < 0) ? 0 : (n > 666) ? 666 : n;
return n;
}
int tien(int n) {
n = (n < 0) ? 0 : (n > 3000) ? 3000 : n;
return n;
}
int lamtron(float n){
    int k=round(n);
    if(k*1.0-n<0){
        return k+1;
    } else return k;
}

int firstMeet(int & EXP1, int & EXP2, int  & E1) {
    // TODO: CoMplEtE this function
    if (E1 < 0 || E1>99){
        return -99;
    } 
    EXP1 = kn(EXP1);
    EXP2 = kn(EXP2);
    if(E1<4){
        switch(E1){
            case 0:
                EXP2+=29;
                EXP2 = kn(EXP2);
                break;
            case 1:
                EXP2+=45;
                EXP2 = kn(EXP2);
                break;
            case 2:
                EXP2+=75;
                EXP2 = kn(EXP2);
                break;
            case 3:
                EXP2+=149;
                EXP2 = kn(EXP2);
                break;
        }
        int d=E1*3+EXP1*7;
        if(d%2==0){
            EXP1=lamtron(EXP1*1.0+d*1.0/200);
            EXP1 = kn(EXP1);
        } else {
        EXP1=lamtron(EXP1*1.0-d*1.0/100);
        EXP1= kn(EXP1);}
    } else {
    if(E1<=19){
        EXP2=lamtron(EXP2*1.0+E1*1.0/4+19);
    } else if(E1<50){
        EXP2=lamtron(EXP2*1.0+E1*1.0/9+21);
    } else if(E1<66){
        EXP2=lamtron(EXP2*1.0+E1*1.0/16+17);
    } else if(E1<80){
        EXP2=lamtron(EXP2*1.0+E1*1.0/4+19);
        if(EXP2>200){
            EXP2=lamtron(EXP2*1.0+E1*1.0/9+21);
        }
    } else if(E1<100){
        EXP2+=lamtron(E1*1.0/4+19);
        EXP2+=lamtron(E1*1.0/9+21);
        if(EXP2>400){
            EXP2+=lamtron(E1*1.0/16+17);
            EXP2+=lamtron(EXP2*15.0/100);
        }
    }
    EXP1-=E1;
    EXP1 = kn(EXP1);
    EXP2 = kn(EXP2);
    }
    
    return EXP1 + EXP2;
}

// Task 2
int chinhphuong(int s){
    int k=sqrt(s);
    int square1 = k * k;
    int square2 = (k + 1) * (k + 1);

    if (abs(s - square1) < abs(s - square2))
        return square1;
    else
        return square2;
}
int tongchuso(int n){
    int sum=0;
    while(n!=0){
    sum=sum+n%10;
    n/=10;
    }
    return sum%10;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int & E2){
    
    if(E2<0|| E2>99){ 
    return -99;
    }
    HP1=mau(HP1);
    EXP1=kn(EXP1);
    M1=tien(M1);
    float p,p1,p2,p3;
    
    // lane1
    int S=chinhphuong(EXP1);
    if(EXP1>=S){
        p1=1;
    } else p1=(EXP1*1.0000/S+80)/123;
    //lane2
    if(E2%2==0){
        for(int i=0;i<1;i++){
            //hd1
            if(M1==0) break;
            if(HP1<200){
                HP1+=lamtron(HP1*30.0000/100);
                M1-=150;
            } else {
                HP1+=lamtron(HP1*10.0000/100);
                M1-=70;
            }
            HP1=mau(HP1);
            M1=tien(M1);
            if(M1==0) break;
            // hd2
            if(EXP1<400){
                M1-=200;
            } else M1-=120;
            EXP1+=lamtron(EXP1*13.0000/100);
            EXP1=kn(EXP1);
            M1=tien(M1);
            if(M1==0) break;
            // hd3
            if(EXP1<300){
                M1-=100;
            } else M1-=120;
            EXP1=lamtron(EXP1*90.0000/100);
            M1=tien(M1);
            EXP1=kn(EXP1);
        }
    } else{
        float k=M1*1.0000/2;
        while (M1>=k){
            if(M1<k) break;
            if(HP1<200){
                HP1+=lamtron(HP1*30.0000/100);
                M1-=150;
            } else {
                HP1+=lamtron(HP1*10.0000/100);
                M1-=70;
            }
            HP1=mau(HP1);
            M1=tien(M1);
            if(M1<k) break;
            // hd2
            if(EXP1<400){
                M1-=200;
            } else M1-=120;
            EXP1+=lamtron(EXP1*13.0000/100);
            EXP1=kn(EXP1);
            M1=tien(M1);
            if(M1<k) break;
            // hd3
            if(EXP1<300){
                M1-=100;
            } else M1-=120;
            EXP1=lamtron(EXP1*90.0000/100);
            M1=tien(M1);
            EXP1=kn(EXP1);
            if (M1<k) break;
        }
    }
    HP1=mau(HP1);
    EXP1=kn(EXP1);
    HP1=lamtron(HP1*83.0000/100);
    EXP1+=lamtron(EXP1*17.0000/100);
    HP1=mau(HP1);
    EXP1=kn(EXP1);
    int S2=chinhphuong(EXP1);
    if(EXP1>=S2){
        p2=1;
    } else p2=(EXP1*1.0000/S2+80)/123;
    //lane3
    int P[10]={32,47,28,79,100,50,22,83,64,11};
    int k=tongchuso(E2);
    p3=P[k]*1.0000/100;
    //tongket
    p=(p1+p2+p3)/3;
    if(p>=1){
        EXP1=lamtron(EXP1*75.0000/100);
    } else if(p>=0.5){
        HP1=lamtron(HP1*90.0000/100);
        EXP1+=lamtron(EXP1*20.0000/100);
    } else {
        HP1=lamtron(HP1*85.0000/100);
        EXP1+=lamtron(EXP1*15.0000/100);
    }
    EXP1=kn(EXP1);
    HP1=mau(HP1);
    return EXP1+HP1+M1;
}

// Task 3
int tongtask3(int n){
    int sum=0;
    while(n!=0){
        sum=sum+n%10;
        n/=10;
    }
    if (sum<10){
        return sum;
    } else return tongtask3(sum);
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int & E3) {
    // TODO: CoMplEtE this function
    if (E3 < 0 || E3 > 99) return -99;
    HP1=mau(HP1);
    EXP1=kn(EXP1);
    HP2=mau(HP2);
    EXP2=kn(EXP2);
    int A[10][10]={0};
    int duong=0,am=0;
    //j cot i hang
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            A[i][j]=((E3*j)+(i*2))*(i-j);
            if(A[i][j]<E3*(-1)){
                am++;
            } else if(A[i][j]>E3*2){
                duong++;
            }
        }
    }
    int B[10][10];
    for(int j=0;j<10;j++){
        for(int i=0;i<10;i++){
            int Max=A[i][j];
            int M=i,n=j;
            while (M<10||n<10){
            Max=A[M][n];
            M++;
            n++;
    }
            int a=i,b=j;
            while (a>-1||b>-1){
            Max=A[a][b];
            a--;
            b--;
    }
            int c=i,d=j;
            while (c>-1||d<10){
            Max=A[c][d];
            c--;
            d++;
    }
            int E=i,f=j;
            while (E<10||f>-10){
            Max=A[E][f];
            E++;
            f--;
    }
            B[i][j]=abs(Max);
        }
    }
    int i=tongtask3(duong);
    int j=tongtask3(am);
    if(abs(A[i][j])>B[i][j]){
        EXP1=lamtron(EXP1-EXP1*12.0/100);
        HP1=lamtron(HP1-HP1*10.0/100);     
        EXP2=lamtron(EXP2-EXP2*12.0/100);
        HP2=lamtron(HP2-HP2*10.0/100);     
    } else {
         EXP1+=lamtron(EXP1*12.0/100);
        HP1+=lamtron(HP1*10.0/100);     
        EXP2+=lamtron(EXP2*12.0/100);
        HP2+=lamtron(HP2*10.0/100); 
    }
     HP1=mau(HP1);
    EXP1=kn(EXP1);
    HP2=mau(HP2);
    EXP2=kn(EXP2);
    
   if(abs(A[i][j])>B[i][j]){
    return A[i][j];
   } else return B[i][j];
}

// Task 4


int checkPassword(const char * s, const char * email) {
    // TODO: CoMplEtE this function
    int k= strlen(s);
    char se[100];
    for(int i=0;i<strlen(email);i++){
        if(email[i]=='@'){
            break;
        } else 
        se[i]=email[i];
    }
    char copys[100];
    for(int i=0;i<k;i++){
        
        copys[i]=s[i];
    }
   
    if (k < 8) {
        return -1;
    }
    if (k > 20) {
        return -2; 
    }

    char *kq= strstr(copys,se);
	int h=strlen(se);
    for(int i=0;i<k-h+1;i++){
    	int dem=0;
    	for(int j=0;j<h && s[i+j]==se[j];j++){
    		dem++;
		}
		if(dem==h) {
		return -(300+i);
		}
	}
    for (int i = 1; i < k; ++i) {
        if (s[i] == s[i - 1]) {
            return -(400 + i); 
        }
    }

    bool check = false;
    for (int i=0;k;i++) {
        if (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!') {
            check = true;
            break;
        }
    }
    if (check==false) {
        return -5;
    }

    return -10; 
}
// Task 5

 bool kiemtra2chuoi(string a,string b){
    int k=a.length();
    for(int i=0;i<k;i++){
        if(a[i]!=b[i]){
            return false;
        }
    }
    return true;
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: CoMplEtE this function
   
    int Max=0,size=0;
    int cnt[10000]={0};
    for(int i=0;i<num_pwds;i++){
        int dem=0;
        for(int j=i+1;j<num_pwds;j++){
            if(kiemtra2chuoi(arr_pwds[i],arr_pwds[j])){
                dem++;
            }
        }
        cnt[i]=dem;
        if(dem>Max){
            Max=dem;
        }
        
    }
    for(int i=0;i<num_pwds;i++){
        if(Max==cnt[i]){
            if(size<strlen(arr_pwds[i])){
            size=strlen(arr_pwds[i]);
        }
        }
    }
for(int i=0;i<num_pwds;i++){
        if(Max==cnt[i]){
            if(size==strlen(arr_pwds[i])){
            return i;
        }
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

