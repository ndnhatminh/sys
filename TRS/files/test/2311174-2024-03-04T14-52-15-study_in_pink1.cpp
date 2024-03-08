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

int check_real_integer_number(float n){
    //flag = 1 => số nguyên
    //flag = 0 => số thực

    int flag = 1;
    if (ceil(n) != floor(n)) flag = 0;
    return flag;
}

// Function ROUND UP
int Round_up(float a){
    if (check_real_integer_number(a)==0)
        return (a/1)+1;
    else    
        return a/1;
}

// Function Check Money
bool CheckMN(int a, int b){
    if (a<=b)
        return false;
    else
        return true;
}

// Function Reset Money
int ReMN(int mn){
    if (mn>3000)
        return 3000;
    else{
        if (mn<0)
            return 0;
        else    
            return mn;
    }
}

// Function Reset HP
int ReHP(int hp){
    if (hp>666)
        return 666;
    else{
        if ((hp>=0)and(hp<=666))
            return hp;
        else
            return 0;
    }
}

// Function Reset EXP
int ReEXP(int exp){
    if (exp>600)
        return 600;
    else{
        if ((exp>=0)and(exp<=600))
            return exp;
        else
            return 0;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    int d= e1*3+exp1*7;
    if ((e1<0) or (e1>99))
        return -99;
    else{
        if ((e1>=0) and (e1<=3)){

            switch (e1){
                case 0:
                    exp2 = ReEXP(exp2 +29);
                    break;
                case 1: 
                    exp2 = ReEXP(exp2 +45);
                    break;
                case 2: 
                    exp2 = ReEXP(exp2 +75);
                    break;
                default: 
                    exp2 = ReEXP(exp2 +75+29+45);
                    break;
            }

            if (d%2==0)
                exp1=ReEXP(Round_up(exp1+((float) d/200)));
            else
                exp1=ReEXP(Round_up(exp1-((float) d/100)));
            
        }
        else{
            if ((e1>=4) and (e1<=19)){
                exp2=ReEXP(Round_up(exp2 + ((float) e1/4)+19));
            }
            if ((e1>=20) and (e1<=49)){
                exp2=ReEXP(Round_up(exp2+((float) e1/9)+21));
            }
            if ((e1>=50) and (e1<=65)){
                exp2=ReEXP(Round_up(exp2+((float) e1/16)+17));
            }
            if ((e1>=66) and (e1<=79)){
                exp2=ReEXP(Round_up(exp2+((float) e1/4)+19));
                if (exp2>200)
                    exp2=ReEXP(Round_up(exp2+((float)e1/9)+21));
            }
            if ((e1>=80) and (e1<=99)){
                exp2=ReEXP(Round_up(exp2 +((float) e1/4)+19));
                exp2=ReEXP(Round_up(exp2+((float) e1/9)+21));
                if (exp2>400){
                    exp2=ReEXP(Round_up(exp2+((float) e1/16)+17));
                    exp2=ReEXP(Round_up(((float) exp2*1.15)));
                }
            }
            exp1=ReEXP(exp1-e1);
            }
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2<0) or (E2>99))
        return -99;
    else{
        int P1=100,P2=100,P3=100,P_TB;
        // Con đường 01
        int a=round(sqrt(EXP1)), S;
        if (a<sqrt(EXP1)){
            if ( abs((EXP1-a*a)) <= abs(((a+1)*(a+1)-EXP1)) )
                S = a*a;
            else
                S = (a+1)*(a+1);
        }
        else{
            if ( abs(EXP1-a*a) <= abs(EXP1-(a-1)*(a-1)) )
                S = a*a;
            else
                S = (a-1)*(a-1);
        }
        if (EXP1>=S)
            P1=100;
        else    
            P1=round(((float) ((((float) EXP1/S)+80)*100)/123));

        // Con đường 03
        int arr[10]={32,47,28,79,100,50,22,83,64,11};
        if ((E2<0) or (E2>99))
            return -99;
        else{
            if (E2<10)
                P3=arr[E2];
            else{
                int temp;
                temp = E2/10 + E2%10;
                if (temp<10)
                    P3=arr[temp];
                else
                    P3=arr[temp%10];
            }
        }

        // Con đường 02
        int sotiendadung=0, motnuasotien=round((float) (M1/2));
        if (E2%2!=0){
            while (CheckMN(sotiendadung,motnuasotien)==false){
                // Sự kiện 1: Mua đồ ăn
                if (HP1<200){
                    HP1=ReHP(Round_up(( HP1*1.3)));
                    M1=ReMN(M1-150);
                    sotiendadung+=150;
                }
                else{
                    HP1=ReHP(Round_up(( HP1*1.1)));
                    M1=ReMN(M1-70);
                    sotiendadung+=70;
                }

                if (CheckMN(sotiendadung,motnuasotien))
                    break;
                
                // Sự kiện 2: Thuê xe
                if (EXP1<400){
                    M1=ReMN(M1-200);
                    EXP1=ReEXP(Round_up( (EXP1*1.13)));
                    sotiendadung+=200;
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(Round_up( (EXP1*1.13)));
                    sotiendadung+=120;
                }

                if (CheckMN(sotiendadung,motnuasotien))
                    break;
                
                // Sự kiện 3: Tìm người hỏi đường
                if (EXP1<300){
                    M1=ReMN(M1-100);
                    EXP1=ReEXP(Round_up( (EXP1*0.9)));
                    sotiendadung+=100;
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(Round_up( (EXP1*0.9)));
                    sotiendadung+=120;
                }

                if (CheckMN(sotiendadung,motnuasotien))
                    break;

            }

            HP1=ReHP(Round_up( (HP1*0.83)));
            EXP1=ReEXP(Round_up((EXP1*1.17)));
        }
        else{
            int dem=0;
            while (dem<3){
                // Sự kiện 1: Mua đồ ăn
                if (HP1<200){
                    HP1=ReHP(Round_up(( HP1*1.3)));
                    M1=ReMN(M1-150);
                }
                else{
                    HP1=ReHP(Round_up(( HP1*1.1)));
                    M1=ReMN(M1-70);
                }

                if (M1==0)
                    break;
                dem+=1;
                
                // Sự kiện 2: Thuê xe
                if (EXP1<400){
                    M1=ReMN(M1-200);
                    EXP1=ReEXP(Round_up( (EXP1*1.13)));
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(Round_up( (EXP1*1.13)));
                }

                if (M1==0)
                    break;
                dem+=1;
                
                // Sự kiện 3: Tìm người hỏi đường
                if (EXP1<300){
                    M1=ReMN(M1-100);
                    EXP1=ReEXP(Round_up( (EXP1*0.9)));
                }
                else{
                    M1=ReMN(M1-120);
                    EXP1=ReEXP(Round_up( (EXP1*0.9)));
                }

                if (M1==0)
                    break;
                dem+=1;
            }
            HP1=ReHP(Round_up( (HP1*0.83)));
            EXP1=ReEXP(Round_up( (EXP1*1.17)));
        }
        int b=round(sqrt(EXP1)), S1;
        if (b<sqrt(EXP1)){
            if ( abs((EXP1-b*b)) <= abs(((b+1)*(b+1)-EXP1)) )
                S1 = b*b;
            else
                S1 = (b+1)*(b+1);
        }
        else{
            if ( abs(EXP1-b*b) <= abs(EXP1-(b-1)*(b-1)) )
                S1 = b*b;
            else
                S1 = (b-1)*(b-1);
        }

        if (EXP1>=S1)
            P2=100;
        else    
            P2=round(((float) ((((float) EXP1/S1)+80)*100)/123));
    
        if ((P1==100)and(P2==100)and(P3==100))
            EXP1= ReEXP(Round_up( (EXP1*0.75)));
        else{
            P_TB=round((float) ((P1+P2+P3)/3));
            if (P_TB<50){
                HP1=ReHP(Round_up( (HP1*0.85)));
                EXP1=ReEXP(Round_up( (EXP1*1.15)));
            }
            else{
                HP1=ReHP(Round_up( (HP1*0.9f)));
                EXP1=ReEXP(Round_up( (EXP1*1.2)));
            }
        }
        return HP1 + EXP1 + M1;
    }
}

// Function find i,j
int Fij(int h){
    if (h<10)
        return h;
    else
        return Fij(h/10+h%10);
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function

    if ((E3<0) or (E3>99))
        return -99;
    else {
        //Khởi tạo giá trị các phần tử của mảng
        int arr[10][10];
        for (int i=0;i<10;i++){
            for (int j=0; j<10; j++){
                arr[i][j]=((E3*j)+(i*2))*(i-j);
            }
        }
        
        // Tìm tọa độ gặp nhau (a,b)
        int a=0,b=0;
        for (int i=0;i<10;i++){
            for (int j=0; j<10; j++){
                if (arr[i][j]>0 and arr[i][j]>(E3*2))
                    a+=1;
                if (arr[i][j]<0 and arr[i][j]<(-E3))
                    b+=1;
            }
        }

        a=Fij(a);
        b=Fij(b);
        //Khởi tạo mảng chứa các phần tử nằm trên đường chéo chính và phụ tại điểm gặp
        int vt=-1, mang[30]={};
        for (int i=0;i<10;i++){
            for (int j=0; j<10; j++){
                if ((i+j)==(a+b)){
                    vt +=1;
                    mang[vt] = arr[i][j]; 
                }
                if (abs(i-9)+j==abs(a-9)+b){
                    vt +=1;
                    mang[vt] = arr[i][j]; 
                }
            }
        }
        int max1=mang[0];
        for (int p=0;p<20;p++){
            if (mang[p]>max1)
                max1=mang[p];
        }

        // Trả về kết quả
        int kq=0;
        if(abs(arr[a][b])>max1){
            EXP1=ReEXP(Round_up((float) EXP1*0.88f));
            HP1=ReHP(Round_up((float) HP1*0.9f));
            EXP2=ReEXP(Round_up((float) EXP2*0.88f));
            HP2=ReHP(Round_up((float) HP2*0.9f));
            kq = arr[a][b];
        }
        else{
            EXP1=ReEXP(Round_up((float) EXP1*1.12f));
            HP1=ReHP(Round_up((float) HP1*1.1f));
            EXP2=ReEXP(Round_up((float) EXP2*1.12f));
            HP2=ReHP(Round_up((float) HP2*1.1f));
            kq = max1;
        }

        return kq;
    }
}
bool CheckSC(string str){
    for (int i=0;i<str.length();i++){
        if ( (str[i]==64) or (str[i]==35) or (str[i]==37) or (str[i]==36) or (str[i]==33) )
            return true;
    }
    return false;
}

// Function Check Consecutive Characters
bool CheckCC(string str){
    for (int i=0;i<str.length()-2;i++){
        if ( (str[i]==str[i+1]) and (str[i+1]==str[i+2]) )
            return false;
    }
    return true;
}

// Function Canculate Same location
int CanSL(string str){
    int vt=0;
    for (int i=0;i<str.length()-2;i++){
        if ( (str[i]==str[i+1]) and (str[i+1]==str[i+2]) ){
            vt=i;
            break;
        }
    }
    return vt;
}

// Function Canculate Substring
int CanSubStr(string str, string substr){
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == substr[0]) {
            int count = 0;
            for (int j = 0; j < substr.length(); j++) {
                if (str[j + i] == substr[j])
                    count += 1;
                else
                    break;
            }
            if (count == substr.length()) 
                return i;
        }
    }
    return 0;
}

// Canculate Check Alpha Num;
int CanAN(string str){
    int k;
    for (int i=0;i<str.length();i++){
        if ( (str[i]==64) or (str[i]==35) or (str[i]==37) or (str[i]==36) or (str[i]==33) or ( str[i]>=48 and str[i]<=57 ) or (str[i]>=65 and str[i]<=90) or (str[i]>=97 and str[i]<=122) )
            k=i;
        else
            return i;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // C-style Strings convert to string 
    string emails= string(email);
    string ss=string(s);

    // Tìm se
    string se;
    int vt;
    for (int i=0;i<emails.length();i++){
        if (emails[i]==64){
            vt=i;
            break;
        }
    }

    se=emails.substr(0,vt);

    // Các trả về
    if (ss.length()<8)
        return -1;
    else if (ss.length()>20)
        return -2;
    else if (CanSubStr(ss,se)!=0)
        return -(300+CanSubStr(ss,se));
    else if  (CheckCC(ss)==false)
        return -(400+CanSL(s));
    else if (CheckSC(ss)==false)
        return -5;
    else if (CanAN(ss)!=-1)
        return CanAN(ss);
    else 
        return -10;
}

// Function Count String Length
int CountSL(string str){
    int i = 0;
   // '\0' la ky tu NULL ket thuc cua mot chuoi
   while(str[i] != '\0') {
      i++;
   }
   return i;
}

// Function Check Duplicate Element
bool CheckDE(string str1,string str2){
    if(CountSL(str1) != CountSL(str2))
        return false;
    else{
        for (int i=0;i<CountSL(str1);i++){
            if (str1[i]!=str2[i])
                return false;
        }
        return true;
    }
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // Tạo mảng chứa các phần tử không trùng nhau
    string arr[num_pwds]={};
    arr[0]=arr_pwds[0];
    int count=1;
    int vt=0;
    while (count <num_pwds){
        bool check=false;
        for (int i=0;i<count;i++){
            if (CheckDE(arr_pwds[count],arr[i])==true){
                check=true;
                break;
            }
        }
        if (check==false){
            vt+=1;
            arr[vt]=arr_pwds[count];
        }
        count +=1;
    }

    // Đếm số lần xuất hiện của các phần tử không trùng nhau đó
    int pt[count]={};
    for (int i=0;i<vt+1;i++){
        for (int j=0;j<num_pwds;j++){
            if (CheckDE(arr[i],arr_pwds[j])==true)
                pt[i]+=1;
        }
    }
    
    // Tìm tần suất xuất hiện nhiều nhất
    int max_pt=pt[0], index=0;
    for (int  i = 0; i < vt+1; i++){
        if (max_pt<pt[i]){
                max_pt=pt[i];
        }
    }

    // Tạp mảng chứa các phần tử có tần suất xuất hiện nhiều nhất
    int count1=-1;
    string arr_longest[vt+1]={};
    for (int  i = 0; i < vt+1; i++){
        if (max_pt==pt[i]){
                count1+=1;
                arr_longest[count1]=arr[i];
        }
    }

    // Tính chiều dài của các phần tử có tần suất xuất hiện nhiều nhất
    int Long_of_arr_longest[count1+1]={};
    for (int i=0;i<count1+1;i++){
        Long_of_arr_longest[i]=CountSL(arr_longest[i]);
    }

    // Tìm phần tử dài nhất trong các phần tử đã lọc
    int len_max=Long_of_arr_longest[0];
    string str=arr_longest[0];
    for (int i=0;i<count1+1;i++){
        if (Long_of_arr_longest[i]>len_max){
            len_max=Long_of_arr_longest[i];
            str=arr_longest[i];
        }
    }

    // Tìm vị trí đầu tiên của phần tử dài nhất (và có tần suất nhiều nhất) trong mảng chính
    for (int i=0; i<num_pwds;i++){
        if (CheckDE(arr_pwds[i],str)==true){
            return i;
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////