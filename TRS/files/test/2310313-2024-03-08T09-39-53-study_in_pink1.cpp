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
int sochinhphuong(int x){
    int a;
    a = round(sqrt(x));
    return a * a;
}
int cheotrai(int arr[10][10], int a, int b) {
    int maxval = 0;
    int c=INT_MIN;
    for (int i = a, j = b; i < 10 && j < 10; i++, j++) {
        if (arr[i][j] > c) {
            c = arr[i][j];
        }
    }
    for (int i = a, j = b; i >= 0 && j >= 0; i--, j--) {
        if (arr[i][j] > c) {
            c = arr[i][j];
        }
    }
    maxval=abs(c);
    return maxval;
}

int cheophai(int arr[10][10], int a, int b) {
    int maxval = 0;
    int c=INT_MIN;
    for (int i = a, j = b; i >= 0 && j < 10; i--, j++) {
        if (arr[i][j] > c) {
            c = arr[i][j];
        }
    }
    for (int i = a, j = b; i < 10 && j >= 0; i++, j--) {
        if (arr[i][j] > c) {
            c = arr[i][j];
        }
    }
    maxval=abs(c);
    return maxval;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    int d=e1*3+exp1*7;
    if(e1>=0&&e1<=3){
        if(d%2==0){
            exp1=(exp1+d/200.0)+0.999;
        }else{
            exp1=(exp1-d/100.0)+0.999;
        }
        if(exp1<0){
            exp1=0;
        }
        else if(exp1>600){
            exp1=600;
        }
        switch (e1){
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
                exp2+=29 + 45 + 75;
                break;
            default:
                return -99;
        }
        if(exp2<0){
            exp2=0;
        }
        else if(exp2>600){
            exp2=600;
        }
        
        return exp1 + exp2;
    }
    else if(e1>=4&&e1<=99){
        if(e1>=4&&e1<=19){
            exp2+=ceil(e1/4.0+19.0);
            exp1=exp1-e1;
            
        }
        else if(e1>=20&&e1<=49){
            exp2+=ceil(e1/9.0+21.0);
            exp1=exp1-e1;
            
        }
        else if(e1>=50&&e1<=65){
            exp2+=ceil(e1/16.0+17.0);
            exp1=exp1-e1;
        }
        else if(e1>=66&&e1<=79){
            exp2+=ceil(e1/4.0+19.0);
            if(exp2>200){
               exp2+=ceil(e1/9.0+21.0); 
            }
            exp1=exp1-e1;
        }
        else if(e1>=80&&e1<=99){
            exp2+=ceil(e1/4.0+19.0);
            exp2+=ceil(e1/9.0+21);
            if(exp2>400){
                exp2+=ceil(e1/16.0+17.0);
                exp2=ceil(exp2*1.15);
            }
            exp1=exp1-e1;
        }
        //khoang
        if(exp1<0){
        exp1=0;
        }
        else if(exp1>600){
            exp1=600;
        }
        if(exp2<0){
        exp2=0;
        }
        else if(exp2>600){
            exp2=600;
        }
        //khoang
        return exp1 + exp2;
    }
    else{
        return -99;
    }
   
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double p1;
    double p2;
    double p3;
    int a=M1/2;
    int b;
    if(E2>=0&&E2<=99){
        //con duong 1
        if(EXP1>=sochinhphuong(EXP1)){
            p1=1;
        }
        else{
            p1=(EXP1/sochinhphuong(EXP1)+80.0)/123.0;
        }

        //con duong 2
        do{
           if(HP1<200){
               
                HP1=ceilf(HP1*1.3);
                M1=ceilf(M1-150);
                b+=150;
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
                if(E2%2==0){
                    if(M1<=0){
                        HP1=ceilf(HP1*0.83);
                        EXP1=ceilf(EXP1*1.17);
                        EXP1=max(0,min(EXP1,600));
                        HP1=max(0,min(HP1,666));
                        break;
                    }
                }
                if(E2%2!=0){
                    if(b>a){
                    HP1=ceilf(HP1*0.83);
                    EXP1=ceilf(EXP1*1.17);
                    EXP1=max(0,min(EXP1,600));
                    HP1=max(0,min(HP1,666));
                    M1=max(0,min(M1,3000));
                    break;
                    }
                }
                
    
            }
            else{
                HP1=ceilf(HP1*1.1);
                M1=ceilf(M1-70);
                b+=70;
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
                if(E2%2==0){
                    if(M1<=0){
                        HP1=ceilf(HP1*0.83);
                        EXP1=ceilf(EXP1*1.17);
                        EXP1=max(0,min(EXP1,600));
                        HP1=max(0,min(HP1,666));
                        break;
                    }
                }
                if(E2%2!=0){
                    if(b>a){
                    HP1=ceilf(HP1*0.83);
                    EXP1=ceilf(EXP1*1.17);
                    EXP1=max(0,min(EXP1,600));
                    HP1=max(0,min(HP1,666));
                    M1=max(0,min(M1,3000));
                    break;
                    }
                }
            }
            if(EXP1<400){
                M1=ceilf(M1-200);
                b+=200;
                EXP1=ceilf(EXP1*1.13);
                EXP1=max(0,min(EXP1,600));
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
                if(E2%2==0){
                    if(M1<=0){
                        HP1=ceilf(HP1*0.83);
                        EXP1=ceilf(EXP1*1.17);
                        EXP1=max(0,min(EXP1,600));
                        HP1=max(0,min(HP1,666));
                        break;
                    }
                }
                if(E2%2!=0){
                    if(b>a){
                    HP1=ceilf(HP1*0.83);
                    EXP1=ceilf(EXP1*1.17);
                    EXP1=max(0,min(EXP1,600));
                    HP1=max(0,min(HP1,666));
                    M1=max(0,min(M1,3000));
                    break;
                    }
                }
            }
            else{
                M1=ceilf(M1-120);
                b+=120;
                EXP1=ceilf(EXP1*1.13);
                EXP1=max(0,min(EXP1,600));
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
                if(E2%2==0){
                    if(M1<=0){
                        HP1=ceilf(HP1*0.83);
                        EXP1=ceilf(EXP1*1.17);
                        EXP1=max(0,min(EXP1,600));
                        HP1=max(0,min(HP1,666));
                        break;
                    }
                }
                if(E2%2!=0){
                    if(b>a){
                    HP1=ceilf(HP1*0.83);
                    EXP1=ceilf(EXP1*1.17);
                    EXP1=max(0,min(EXP1,600));
                    HP1=max(0,min(HP1,666));
                    M1=max(0,min(M1,3000));
                    break;
                    }
                }
            }
            if(EXP1<300){
                M1=ceilf(M1-100);
                b+=100;
                EXP1=ceilf(EXP1*0.9);
                EXP1=max(0,min(EXP1,600));
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
                if(E2%2==0){
                    if(M1<=0){
                        HP1=ceilf(HP1*0.83);
                        EXP1=ceilf(EXP1*1.17);
                        EXP1=max(0,min(EXP1,600));
                        HP1=max(0,min(HP1,666));
                        break;
                    }
                }
                if(E2%2!=0){
                    if(b>a){
                    HP1=ceilf(HP1*0.83);
                    EXP1=ceilf(EXP1*1.17);
                    EXP1=max(0,min(EXP1,600));
                    HP1=max(0,min(HP1,666));
                    M1=max(0,min(M1,3000));
                    break;
                    }
                }
            }
            else{
                M1=ceilf(M1-120);
                b+=120;
                EXP1=ceilf(EXP1*0.9);
                EXP1=max(0,min(EXP1,600));
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
                if(E2%2==0){
                    if(M1<=0){
                        HP1=ceilf(HP1*0.83);
                        EXP1=ceilf(EXP1*1.17);
                        EXP1=max(0,min(EXP1,600));
                        HP1=max(0,min(HP1,666));
                        break;
                    }
                }
                if(E2%2!=0){
                    if(b>a){
                    HP1=ceilf(HP1*0.83);
                    EXP1=ceilf(EXP1*1.17);
                    EXP1=max(0,min(EXP1,600));
                    HP1=max(0,min(HP1,666));
                    M1=max(0,min(M1,3000));
                    break;
                    }
                }
            }
            if(E2%2==0){
            HP1=ceilf(HP1*0.83);
            EXP1=ceilf(EXP1*1.17);
            }
        }
        while(E2%2!=0);
        if(EXP1>=sochinhphuong(EXP1)){
            p2=1;
        }
        else{
            p2=(EXP1/sochinhphuong(EXP1)+80.0)/123.0;
        }

        //con duong 3
        int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        if(0<=E2&&E2<=9){
            p3=arr[E2];
        }
        else{
            p3=arr[(E2/10+E2%10)%10];

        }
        p3=p3/100;

        if(p1==1&&p2==1&&p3==1){
            EXP1=ceilf(EXP1*0.75);
            EXP1=max(0,min(EXP1,600));
            HP1=max(0,min(HP1,666));
            M1=max(0,min(M1,3000));
        }
        else{
            double trungbinhcong=(p1+p2+p3)/3;
            if (trungbinhcong < 0.5){
                HP1=ceilf(HP1*0.85);
                EXP1=ceilf(EXP1*1.15);
                EXP1=max(0,min(EXP1,600));
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
            } 
            else{
                HP1=ceilf(HP1*0.9);
                EXP1=ceilf(EXP1*1.2);
                EXP1=max(0,min(EXP1,600));
                HP1=max(0,min(HP1,666));
                M1=max(0,min(M1,3000));
            }
        }
        
        
        return HP1 + EXP1 + M1;
    
    }
    else{
        return -99;
    }
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0||E3>99){
        return -99;
    }
    //taxi matrix
    int a=0;
    int b=0;
    int arr1[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            arr1[i][j]= ((E3*j) + (i*2))* (i -j);
            if(((E3 * j) + (i * 2)) * (i - j)>(E3*2)){
                a++;
            }
            if(((E3 * j) + (i* 2)) * (i - j)<(-E3)){
                b++;
            }
        }
    }
    //gapnhau
    while(a/10>=1){
        a=a/10+a%10;
    }
    while(b/10>=1){
        b=b/10+b%10;
    }
    //sherlock matrix
    int arr2[10][10];
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int maxtrai = cheotrai(arr1, i, j);
            int maxphai = cheophai(arr1, i, j);
            if(maxtrai>=maxphai){
                arr2[i][j]=maxtrai;
            }
            else{
                arr2[i][j]=maxphai;
            }
        }
    }
    //duoikiptaxi
    if(arr2[a][b]>=abs(arr1[a][b])){
        EXP1=EXP1*1.12+0.999;
        HP1=HP1*1.10+0.999;
        EXP2=EXP2*1.12+0.999;
        HP2=HP2*1.10+0.999;
        EXP1=max(0,min(EXP1,600));
        HP1=max(0,min(HP1,666));
        EXP2=max(0,min(EXP2,600));
        HP2=max(0,min(HP2,666));
        return arr2[a][b];
    }
    else{
        EXP1=EXP1*0.88+0.999;
        HP1=HP1*0.9+0.999;
        EXP2=EXP2*0.88+0.999;
        HP2=HP2*0.9+0.999;
        EXP1=max(0,min(EXP1,600));
        HP1=max(0,min(HP1,666));
        EXP2=max(0,min(EXP2,600));
        HP2=max(0,min(HP2,666));
        return arr1[a][b];
    }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //vitricua@
    string emailchuoi = email;
    string schuoi = s;
    size_t vitria = emailchuoi.find('@');
    string se = emailchuoi.substr(0, vitria);
    // Nếu s có độ dài ngắn hơn độ dài tối thiểu thì trả về -1.
    // Nếu s có độ dài dài hơn độ dài tối đa thì trả về -2.
    if(strlen(s)<8){
        return -1;
    }
    if(strlen(s)>20){
        return -2;
    }
   //Nếu s có chứa se thì trả về -(300+<sei>) với <sei> là vị trí xuất hiện đầu tiên của se.
    size_t vitrise=schuoi.find(se);
    if(vitrise!=string::npos){
        return -(300+vitrise);
    }
//     Nếu s có chứa nhiều hơn 2 ký tự liên tiếp thì trả về -(400+<sci>) với <sci> là vị
// trí đầu tiên của chuỗi đầu tiên gồm nhiều hơn 2 ký tự liên tiếp.
   for(int i = 0; i < strlen(s)-2; i++){
        if(s[i]==s[i+1] && s[i+1]==s[i+2]){
            return -int(400+i);
        }
    }

    int dem=0;
    for(int i=0;i<strlen(s);i++){
        if(s[i]!='@' && s[i]!='!' && s[i]!='#' && s[i]!='$' && s[i]!='%'){
            dem++;
            //Nếu s không chứa ký tự đặc biệt thì trả về -5.
            
        }
    }
    if(dem==strlen(s)){
        return -5;
    }
 
    for(int i=0;i<strlen(s);i++){
        if(!isalpha(s[i])&&!isdigit(s[i])&&s[i]!='@'&&s[i]!='!'&&s[i]!='#'&&s[i]!='$'&&s[i]!='%'){
            return i;
        }
    }
    //kiem tra email
    int dema=0;
    for(int i=0;i<strlen(email);i++){
        if(email[i]=='@'){
            dema++;
        }
    }
    if(dema!=1){
        return vitria;
    }
    if(strlen(email)>100){
        return 100;
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int dodaimax=0;
    int dem=0;
    int trung=1;
    int vitri=0;
    string arr[num_pwds];
    for(int i=0; i<num_pwds;i++){
        int dodai=strlen(arr_pwds[i]);
        for(int j=i+1;j<num_pwds;j++){
            if(strcmp(arr_pwds[i],arr_pwds[j])==0){
                trung++;
            }
        }
        if(trung>dem||(dodai>dodaimax&&trung==dem)){
            dem=trung;
            dodaimax=dodai;
            vitri=i;
        }
        trung=1;
    }
    return vitri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////