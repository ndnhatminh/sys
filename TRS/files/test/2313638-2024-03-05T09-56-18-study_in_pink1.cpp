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
int timS(int a){
    int sbh= floor(sqrt(a));
    int slh= ceil(sqrt(a));
    if (sbh==slh) return sbh*sbh;
    else if (abs(a-sbh*sbh)<abs(a-slh*slh)) return sbh*sbh;
    else return slh*slh;
}

int tinh(int a){
    return ((a/10)+(a%10))%10;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1>=0 && e1 <= 3){
        if (e1 == 0 ) exp2+=29;
        else if (e1==1) exp2+=45;
        else if (e1==2) exp2+=75;
        else if (e1==3) exp2+=149;
        int d= e1*3 + exp1*7;
        if (d%2==0) exp1=(exp1+d/200.0+0.999);
        else exp1=(exp1-d/100.0+0.999); 
    }
    else if (e1 >=4 && e1<= 99){
        if (e1<=19) exp2=(exp2 + (e1/4.0 + 19)+0.999); // thong tin 1
        else if (e1<=49) exp2=(exp2 + (e1/9.0 + 21)+0.999); // thong tin 2
        else if (e1<=65) exp2=(exp2 + (e1/16.0 + 17)+0.999); // thong tin 3
        else if (e1<=79) {
            exp2=(exp2 + (e1/4.0 + 19)+0.999); 
            if (exp2 > 200 ) exp2=(exp2 + (e1/9.0 + 21)+0.999);
        
        }
        else if (e1 <= 99) {
            exp2=(exp2 + (e1/4.0 + 19)+0.999);
            exp2 = (exp2 + (e1/9.0 + 21)+0.999);
            
            if (exp2 > 400) {
                exp2=(exp2 + (e1/16.0 + 17)+0.999);
                exp2=(exp2*1.15+0.999);
            }
        }    
        exp1-=e1;
    }
    else return -99;

    exp2 = (exp2 > 600 ? 600 : exp2);
    exp1 = (exp1 > 600 ? 600 : exp1);
    exp1 = (exp1 < 0 ? 0 : exp1);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 || E2 > 99) return -99;
    // TODO: Complete this function

    int s = timS(EXP1);
    double p1 = 0.0, p2=0.0, p3 = 0.0;
    
    //Con duong 01
    if (EXP1 >= s) p1 = 1.0;
    else p1 = round((EXP1/(s*1.0) + 80)/123.0*100)/100; 
    // lam tron 2 chu so tphan
    
    //Con duong 02
    int sotienbatdau=ceil(M1/2.0);
    int sotiendachi=0;
    // E chan thi lap lai cho den khi thoa dk
    if (E2%2!=0) while(sotiendachi<=sotienbatdau) {
        //Su kien 1
        if (HP1 <200) { 
            HP1=(HP1*1.3+0.999); // mua thuc an
            M1-=150;
            sotiendachi+=150;
        }
        else {
            HP1=(HP1+HP1/10.0+0.999); // mua nuoc
            M1-=70;
            sotiendachi+=70;
        }
        //Kiem tra dk
        M1 = (M1 < 0 ? 0 : M1);
        HP1 = (HP1 > 666 ? 666 : HP1);
        if (sotiendachi>sotienbatdau||M1<=0) break;

        //Su kien 2
        if (EXP1 < 400) {
            M1-=200; // di taxi
            sotiendachi+=200;
        }
        else {
            M1-=120; // di ngua
            sotiendachi+=120;
        }
        EXP1=(EXP1*1.13+0.999); 

        //kiem tra dk
        M1 = (M1 < 0 ? 0 : M1);
        EXP1 = (EXP1 > 600 ? 600 : EXP1);
        if (sotiendachi>sotienbatdau||M1<=0) break;

        //Su kien 3
        if (EXP1 < 300) {M1-=100; sotiendachi+=100;}
        else if (EXP1 >= 300) {M1-=120; sotiendachi+=120;}
        EXP1=(EXP1*0.9+0.999);
        
        //ktr dk 
        M1 = (M1 < 0 ? 0 : M1);
        EXP1 = (EXP1 > 600 ? 600 : EXP1);
        if (sotiendachi>sotienbatdau||M1<=0) break;

    }
    else { // E le thi thuc hien 1 lan
        int j=1;
        while(j--) {
            //Su kien 1
            if (HP1 <200) { 
                HP1=(HP1*1.3+0.999); // mua thuc an
                M1-=150;
                sotiendachi+=150;
            }
            else {
                HP1=(HP1+HP1/10.0+0.999); // mua nuoc
                M1-=70;
                sotiendachi+=70;
            }
            //Kiem tra dk
            M1 = (M1 < 0 ? 0 : M1);
            HP1 = (HP1 > 666 ? 666 : HP1);
            if (M1<=0) break;

            //Su kien 2
            if (EXP1 < 400) {
                M1-=200; // di taxi
                sotiendachi+=200;
            }
            else {
                M1-=120; // di ngua
                sotiendachi+=120;
            }
            EXP1=(EXP1*1.13+0.999); 

            //kiem tra dk
            M1 = (M1 < 0 ? 0 : M1);
            EXP1 = (EXP1 > 600 ? 600 : EXP1);
            if (M1<=0) break;

            //Su kien 3
            if (EXP1 < 300) {M1-=100; sotiendachi+=100;}
            else if (EXP1 >= 300) {M1-=120; sotiendachi+=120;}
            EXP1=(EXP1*0.9+0.999);
            
            //ktr dk 
            M1 = (M1 < 0 ? 0 : M1);
            EXP1 = (EXP1 > 600 ? 600 : EXP1);
            if (M1<=0) break;
        }
    }
    
    // ket thuc duong 02 
    HP1=(HP1*0.83+0.999);
    EXP1=(EXP1*1.17+0.999);
    
    // ktr dk
    EXP1 = (EXP1 > 600 ? 600 : EXP1);
    EXP1 = (EXP1 < 0 ? 0 : EXP1);
    HP1 = (HP1 > 666 ? 666 : HP1);
    HP1 = (HP1 < 0 ? 0 : HP1);

    // tinh p2
    s= timS(EXP1);
    if (EXP1 >= s) p2=1.0;
    else p2 = round((EXP1/(s*1.0) + 80)/123.0*100)/100;

    // con duong 03
    int a[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    p3=a[tinh(E2)]/100.0;

    // Sau khi di het 3 con duong
    if (p3==1.0 && p2==1.0 && p1 ==1.0) {
        EXP1=(EXP1*0.75+0.999);
    }
    else {
        double ptb = (p3+p2+p1)/3.0;
        
        if (ptb<0.5) {// kho khan 
            HP1=(HP1*0.85+0.999);
            EXP1=(EXP1*1.15+0.999);
        }
        else if (ptb >= 0.5) {// de dang
            HP1=(HP1*0.9+0.999);
            EXP1=(EXP1*1.2+0.999);
        }
    }

    //ktr dk
    EXP1 = (EXP1 > 600 ? 600 : EXP1);
    EXP1 = (EXP1 < 0 ? 0 : EXP1);
    HP1 = (HP1 > 666 ? 666 : HP1);
    HP1 = (HP1 < 0 ? 0 : HP1);

    return HP1 + EXP1 + M1;
}

// ham tinh toan o task 3
int tinh2(int a){
    if (a < 10) return a;
    int s=(a/10)+(a%10);
    while (s >= 10){
        a=s;
        s=(a/10)+(a%10);
    }
    return s;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3<0||E3>99) return -99;
    int a[10][10];
    // xay dung ma tran
    for (int i=0;i<10;i++) 
        for (int j=0; j<10; j++) a[i][j]=((E3*j)+(2*i))*(i-j);
    
    // tim diem gap nhau
    int i1=0,j1=0;
    for (int i=0; i<10; i++)
        for (int j=0;j<10; j++){
            if (a[i][j] > E3 * 2) i1++;
            if (a[i][j] < -1*E3) j1++;
        }
    i1=tinh2(i1); j1=tinh2(j1);
    
    // tim max tren dg cheo trai - dg cheo tong
    // i+j = const
    // TIM MAX
    int ma=a[i1][j1];
    //Huong Dong Bac
    int i=i1,j=j1; i--;j++;
    while( i>0&&j<10 ){
        //cout << "j :" << j << endl;
        if (a[i][j]>ma) ma=a[i][j]; 
        j=j1; i--;j++;
        //a[i][j]=-1;
    }
    //cout << "max : " << ma << endl;
    //Huong Tay Nam 
    i=i1;j=j1;i++;j--;
    while(i<10&&j>0 ){
        if (a[i][j]>ma) ma=a[i][j];
        i++;j--;
        //a[i][j]=-1;
    }
    //Huong Tay Bac
    i=i1;j=j1;i--; j--;
    while(i>0&&j>0) {
        if (a[i][j]>ma) ma=a[i][j];
        i--; j--;
        //a[i][j]=-1;
    }
    //Huong Dong Nam
    i=i1;j=j1;i++;j++;
    while(i<10&&j<10) {
        if (a[i][j]>ma) ma=a[i][j];
        i++;j++;
        //a[i][j]=-1;
    }  
    /* 
    for (int i=0;i<10;i++){
        for (int j=0; j<10; j++) cout << a[i][j] << " ";
        cout << endl;
    }
    */
    //cout << "Max la: " << ma << endl;
    if (abs(a[i1][j1]) > abs(ma)) { // taxi nhanh hon
        EXP1=(EXP1*0.88+0.999);
        EXP2=(EXP2*0.88+0.999);
        HP1=(HP1*0.9+0.999);
        HP2=(HP2*0.9+0.999);
        return a[i1][j1];
    }
    else { // sherlock bat kip taxi
        EXP1=(EXP1*1.12+0.999);
        EXP2=(EXP2*1.12+0.999);
        HP1=(HP1*1.1+0.999);
        HP2=(HP2*1.1+0.999);
        EXP1 = (EXP1 > 600 ? 600 : EXP1);
        HP1 = (HP1 > 666 ? 666 : HP1);
        EXP2 = (EXP2 > 600 ? 600 : EXP2);
        HP2 = (HP2 > 666 ? 666 : HP2);
        return ma;
    }
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    string s2="",email2="";
    for (int i=0;i<strlen(s);i++) s2+=s[i];
    for (int i=0;i<strlen(email);i++) email2+=email[i];

    // Kiem tra do dai
    if (strlen(s)<8) return -1;
    else if (strlen(s)>20) return -2;

    // xay dung chuoi se
    string se="";
    for (int i=0;i<email2.size();i++){
        if (email2[i]!='@') se+=email2[i];
        else break;
    }

    int t = s2.find(se);
    if (t!=-1) return -(300+t);
 
    //Kiem tra ki tu lien tiep giong nhau 
    int dem=1;
    for(int i=1;i<strlen(s); i++){  
        if (s[i]==s[i-1]) dem++;
        else dem=1;
        if (dem>2) {
            return -(400+(i-2)); 
            //i-2 la vi tri dau tien cua xau con can tim
        }
    }

    //kiem tra s co chua ki tu dac biet khong
    bool check=true;
    for (int i=0;i<strlen(s);i++){
        if (s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'){
            check = false; // s chua ki tu dac biet
            break;
        }
    }
    if (check) return -5; 
    for (int i=0;i<strlen(s);i++){
        if (!((s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A')||(s[i]=='!'||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%')||(s[i]>='0'&&s[i]<='9'))) {
            return i;
        }
    }
    // Neu hop le
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int dodai[100];
    int xhien[100];
    for (int i=0;i<num_pwds;i++){
        xhien[i]=1; dodai[i]=strlen(arr_pwds[i]);
        for(int j=0;j<num_pwds;j++){
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) { xhien[i]++; }
            //cout << arr_pwds[i] << " " << arr_pwds[j] << endl;
        }
    }
    //for (int i=0;i<num_pwds;i++) cout << arr_pwds[i] << " xuat hien: " << xhien[i] << endl;
    int max_xh=1,max_dodai=1;
    for (int i=0;i<num_pwds;i++) {
        if  (xhien[i]>max_xh) max_xh=xhien[i];
    }
    
    for (int i=0;i<num_pwds;i++) {
        if (xhien[i]==max_xh && dodai[i]>max_dodai) max_dodai=dodai[i];
    }
    //cout << "Max xhien :" << max_xh << endl;
    /*cout << "Max do dai: " << max_dodai << endl;  */
    //for (int i=0;i<num_pwds;i++) cout << arr_pwds[i] << " do dai " << dodai[i] << endl;

    for (int i=0; i<num_pwds; i++)
        if (xhien[i]==max_xh && dodai[i]==max_dodai) return i;
    return -1; 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////