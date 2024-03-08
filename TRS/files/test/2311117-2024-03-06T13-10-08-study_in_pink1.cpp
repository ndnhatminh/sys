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
int check(int n, int firstpoint, int lastpoint) {
if (n<firstpoint){
    n=firstpoint;
}
else if (n>lastpoint) {
    n=lastpoint;
}
else{
     n=n;
}
return n;
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
//Kiểm tra input
if (E1 < 0 || E1 > 99) 
return -99;
int firstpointEXP=0, lastpointEXP=600;
EXP1 = check(EXP1,firstpointEXP,lastpointEXP);
EXP2 = check(EXP2,firstpointEXP,lastpointEXP); 
// Khai báo biến
const int inform1_1=29, inform1_2=45, inform1_3=75, inform1_4=inform1_1+inform1_2+inform1_3;
int D;
float inform2_1, inform2_2, inform2_3;
inform2_1= float(E1)/4 + 19;
inform2_2= float(E1)/9 + 21;
inform2_3= float(E1)/16 + 17;
float EXP1_test = EXP1;
float EXP2_test = EXP2;
// Xét trường hợp
int informE1;
bool task1;
if (E1 <= 3){
    informE1 =E1; 
    task1 = 1;
}
else {
    informE1 = E1;
    task1 = 0;
}
//Trường hợp 1
if (task1){
    switch(informE1){
        case 0:{
            EXP2 += inform1_1;
            break;
        }
        case 1:{
            EXP2 +=inform1_2;
            break;
        }
        case 2:{
            EXP2 +=inform1_3;
            break;
        }
        case 3:{
            EXP2 +=inform1_4;
            break;
        }
    }
    D=E1*3+EXP1*7;
        if (D%2==0)
        {
            EXP1_test= ceil(EXP1_test+float(D)/200) ;
        }
        else
        {
            EXP1_test= ceil(EXP1_test-float(D)/100);
        }
    EXP1=EXP1_test;
}
//Trường hợp 2
else
{   
if (informE1>=4 && informE1<=19){
    EXP2_test+=inform2_1;
}
if (informE1>=20 && informE1<=49){
    EXP2_test+= inform2_2;
}
if (informE1>=50 && informE1<=65){
    EXP2_test+=inform2_3;
} 
if (informE1>=66 && informE1<=79){
    EXP2_test= ceil(EXP2_test+inform2_1);
    EXP2=EXP2_test;
    EXP2=check(EXP2,firstpointEXP,lastpointEXP);
    EXP2_test=EXP2;
    if (EXP2_test>200)
    {
        EXP2_test+=inform2_2;
    }
}
if (informE1>=80 && informE1<=99){
                EXP2 = EXP2 + ceil(inform2_1);
            EXP2 = check(EXP2, firstpointEXP, lastpointEXP);
            EXP2 = EXP2 + ceil(inform2_2);
            EXP2=check(EXP2,firstpointEXP,lastpointEXP);
            EXP2_test=EXP2;
            if (EXP2_test>400)
            {
                EXP2_test= ceil (EXP2_test+inform2_3);
                EXP2=EXP2_test;
                EXP2=check(EXP2,firstpointEXP,lastpointEXP);
                EXP2_test=EXP2;
                EXP2_test= ceil (EXP2_test*1.1500);
            }
}      
            EXP2_test = ceil(EXP2_test);
            EXP2=EXP2_test;
            EXP1_test=ceil(EXP1_test-float(E1));
            EXP1=EXP1_test;
}
    EXP1=check(EXP1,firstpointEXP,lastpointEXP);    
    EXP2=check(EXP2,firstpointEXP,lastpointEXP);
    return EXP1 + EXP2;
}

// Task 2
bool isPerfectSquare(int n) {
        int sqrt_n = sqrt(n);
        return sqrt_n * sqrt_n == n;
    }
int nearestPerfectSquare(int n) {
        if(n==0){
            return 0;
        }
        int smaller = n - 1;
        int larger = n + 1;
        
        while (true) {
            if (isPerfectSquare(smaller))
                return smaller;
            else if (isPerfectSquare(larger))
                return larger;
            else {
                smaller--;
                larger++;
            }
        }
    }
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    //Kiểm tra input
    int firstpointEXP=0, lastpointEXP=600;
    int firstpointHP=0, lastpointHP=666;
    int firstpointM=0, lastpointM=3000;
    if (E2 < 0 || E2 > 99) 
    return -99;
    HP1 = check(HP1, firstpointHP, lastpointHP);
    EXP1 = check(EXP1, firstpointEXP, lastpointEXP);
    M1 = check(M1, firstpointM, lastpointM);
    //Khai báo biến
    float P[10] = { 32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P1,P2,P3,P4;
    float Mhalf=float(M1)/2;
    int S;
   
    //Con đường 1
    S = nearestPerfectSquare(EXP1);
    if(EXP1>=S){
        P1=1.000;
    } 
    else{
        P1=( float(EXP1)/float(S) +80 )/123;
    }
    // //Con đường 2
    while(E2%2 != 0 ){ //E là số lẻ
        if(M1==0){
            goto downstreet;
        }
        if (HP1<200) //Sự kiện 1
        {
            HP1 =HP1* 1.300 +0.999;
            M1 -= 150;
        }
        else
        {
            HP1 =HP1* 1.1+0.999;
            M1 -= 70;
        }
        M1=check(M1,firstpointM,lastpointM);
        HP1=check(HP1,firstpointHP,lastpointHP);
        if(M1<Mhalf){   
            goto downstreet;
        }
        if (EXP1<400) // Sự kiện 2
        {
            M1 -= 200;
            EXP1 =EXP1* 1.130+0.999;
        }
        else
        {
            M1 -= 120;
            EXP1 =EXP1* 1.130+0.999;
        }
        M1=check(M1,firstpointM,lastpointM);
        EXP1=check(EXP1,firstpointEXP,lastpointEXP);
        if(M1<Mhalf)
        {  
            goto downstreet;
        }
        if (EXP1<300) // Sự kiện 3
        {
            M1 -=100;
            EXP1 =EXP1- EXP1*0.100+0.999;
        }
        else
        {
            M1 -=120;
            EXP1 =EXP1-EXP1*0.100+0.999;
        }
        M1=check(M1,firstpointM,lastpointM);
        EXP1=check(EXP1,firstpointEXP,lastpointEXP);
        if(M1<Mhalf)
        {  
            goto downstreet;
        }
        }
    if (E2%2==0) //E là số chẵn
        {
        if(M1==0){
            goto downstreet;
        }
        if (HP1<200) //Sự kiện 1
        {
            HP1 =HP1* 1.300+0.999;
            M1 -= 150;
        }
        else
        {
            HP1 =HP1*1.100 +0.999;
            M1 -= 70;
        }
        M1=check(M1,firstpointM,lastpointM);
        HP1=check(HP1,firstpointHP,lastpointHP);
        if(M1==0){
            goto downstreet;
        }
        if (EXP1<400) // Sự kiện 2
        {
            M1 -= 200;
            EXP1 =EXP1* 1.13+0.999;
        }
        else
        {
            M1 -= 120;
            EXP1 =EXP1* 1.13+0.999;
        }
        M1=check(M1,firstpointM,lastpointM);
        EXP1=check(EXP1,firstpointEXP,lastpointEXP);
        if(M1==0){
            goto downstreet;
        }
        if (EXP1<300) // Sự kiện 3
        {
            M1 -=100;
            EXP1 =EXP1- EXP1*0.10+0.999;
        }
        else
        {
            M1 -=120;
            EXP1 =EXP1- EXP1*0.10+0.999;
        }
        M1=check(M1,firstpointM,lastpointM); 
        EXP1=check(EXP1,firstpointEXP,lastpointEXP);
        if(M1==0){
            goto downstreet;
        }
        }
        downstreet:   
        EXP1 =EXP1+ EXP1*0.170+0.999;
        EXP1=check(EXP1,firstpointEXP,lastpointEXP);
        HP1 =HP1- HP1*0.170+0.999;
        HP1=check(HP1,firstpointHP,lastpointHP);
        S = nearestPerfectSquare(EXP1);
        if (EXP1>=S){
            P2=1.000;
        }
        else{
            P2=( float(EXP1)/float(S) +80 )/123;
        }
    //Con đường 3
        int i;
            if (E2 < 10) {
                i = E2;
            } else {
                int sum = (E2 / 10) + (E2 % 10); 
                i = sum % 10; 
            }
        P3=P[i]/100;
        P4=(P1+P2+P3)/3;
        if (P1==1 && P2==1 && P3==1){
            EXP1= EXP1-EXP1*0.250+0.999;
        }
        else{   
            if (P4 <0.500){   
                HP1 =HP1-HP1*0.150+0.999;
                EXP1=EXP1+EXP1*0.150+0.999;
        }
        else{
            HP1 =HP1- HP1*0.100+0.999;
            EXP1=EXP1+EXP1*0.200+0.999;  
        }
        }
        EXP1=check(EXP1,firstpointEXP,lastpointEXP);
        HP1=check(HP1,firstpointHP,lastpointHP);
        M1=check(M1,firstpointM,lastpointM);   
    return HP1 + EXP1 + M1;
}
// Task 3
int findMaxOnDiagonals(int arr[10][10], int rows, int cols, int i, int j) {
    // Xác định vị trí bắt đầu của đường chéo trái
    int startRowLeft=i;
    int startColLeft=j;
    while (startRowLeft>0 && startColLeft>0) {
        startRowLeft--;
        startColLeft--;
    }
    // Xác định vị trí kết thúc của đường chéo trái
    int endRowLeft= i;
    int endColLeft= j;
    while (endRowLeft< rows - 1 && endColLeft <cols - 1) {
        endRowLeft++;
        endColLeft++;
    }
    // Xác định vị trí bắt đầu của đường chéo phải
    int startRowRight=i;
    int startColRight=j;
    while (startRowRight>0 && startColRight<cols - 1) {
        startRowRight--;
        startColRight++;
    }
    // Xác định vị trí kết thúc của đường chéo phải
    int endRowRight= i;
    int endColRight= j;
    while (endRowRight < rows - 1 && endColRight > 0) {
        endRowRight++;
        endColRight--;
    }
    // Tìm giá trị lớn nhất trong các phần tử của đường chéo trái và đường chéo phải
    int maxDiagonal = arr[i][j];
    for (int r = startRowLeft, c = startColLeft; r <= endRowLeft && c <= endColLeft; r++, c++) {
        maxDiagonal = max(maxDiagonal, arr[r][c]);
    }
    for (int r = startRowRight, c = startColRight; r <= endRowRight && c >= endColRight; r++, c--) {
        maxDiagonal = max(maxDiagonal, arr[r][c]);
    }
    return maxDiagonal;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    //Kiểm tra input
    int firstpointEXP=0, lastpointEXP=600;
    int firstpointHP=0, lastpointHP=666;
    int firstpointM=0, lastpointM=3000;
    if (E3 < 0 || E3 > 99) return -99;
    HP1 = check(HP1, firstpointHP, lastpointHP);
    EXP1 = check(EXP1, firstpointEXP, lastpointEXP);
    HP2 = check(HP2, firstpointHP, lastpointHP);
    EXP2 = check(EXP2, firstpointEXP, lastpointEXP);
    //Khai báo 
    int greater_than=0, less_than=0;
    int point_Sherlock, point_Taxi;
    int arr[10][10] = {};
    // Gán giá trị cho phần tử trong mảng
   for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            arr[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }
    // Số giá trị dương trong ma trận lớn hơn (E3∗2)
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(arr[i][j] > E3 * 2) {
                greater_than++;
            }
        }
    }
    // Số giá trị âm trong ma trận nhỏ hơn (−E3)
     for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(arr[i][j] < -E3) {
                less_than++;
            }
        }
    }
    // Đưa i về 1 chữ số
    int i=greater_than;
    while (i >= 10) {
        int sum = (i / 10) + (i % 10); 
        i = sum; 
    }
    //Đưa j về 1 chữ số
    int j=less_than;
    while (j >= 10) {
        int sum = (j / 10) + (j % 10);
        j = sum; 
    }
    point_Taxi=arr[i][j];
    int maxOnDiagonals = findMaxOnDiagonals(arr,10, 10, i, j);
    point_Sherlock=abs(maxOnDiagonals);
    if(abs(point_Taxi)>point_Sherlock){
        EXP1 = EXP1 * 0.88 +0.999;
        HP1 = HP1 * 0.9 +0.999;
        EXP2 = EXP2 * 0.88 +0.999;
        HP2 = HP2 * 0.9 +0.999;
        HP1 = check(HP1, firstpointHP, lastpointHP);
        EXP1 = check(EXP1, firstpointEXP, lastpointEXP);
        HP2 = check(HP2, firstpointHP, lastpointHP);
        EXP2 = check(EXP2, firstpointEXP, lastpointEXP);
        return point_Taxi;
    }
    else{
        EXP1 = EXP1 * 1.12 +0.999;
        HP1 = HP1 * 1.1 +0.999;
        EXP2 = EXP2 * 1.12 +0.999;
        HP2 = HP2 * 1.1 +0.999;
        HP1 = check(HP1, firstpointHP, lastpointHP);
        EXP1 = check(EXP1, firstpointEXP, lastpointEXP);
        HP2 = check(HP2, firstpointHP, lastpointHP);
        EXP2 = check(EXP2, firstpointEXP, lastpointEXP);
        return point_Sherlock;
    }
    return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    int length_s = strlen(s); // Hàm strlen() dùng để lấy độ dài chuỗi
    // Kiểm tra độ dài của password
    if (length_s<8)
        return -1; 
    else if (length_s>20)
        return -2; 
    // Tìm vị trí ký tự '@' trong chuỗi email
    const char*ptr_char=strchr(email, '@'); // Hàm strchr tìm lần xuất hiện đầu tiên của kí tự '@' trong chuỗi 'email'
    // Tạo chuỗi se từ đầu đến ký tự '@' trong chuỗi email
    int length_se= ptr_char-email;
    char *se = new char[length_se + 1];
    strncpy(se, email, length_se); //Hàm strncpy() dùng để sao chép chuỗi 'email' sang chuỗi 'se' với độ dài "length_se"
    se[length_se]= '\0';  
    // Kiểm tra xem chuỗi s có chứa chuỗi se không
    const char *ptr_se= strstr(s, se);
    if (ptr_se!=nullptr)
        return -(300+(ptr_se - s)); // Chuỗi s chứa chuỗi se
    // Kiểm tra xem chuỗi s có chứa nhiều hơn 2 ký tự liên tiếp giống nhau không
    for (int i = 0; i < length_s; i++) {
        if (s[i]==s[i+1] && s[i]==s[i+2])
            return -(400+i); // Chuỗi s chứa nhiều hơn 2 ký tự liên tiếp và giống nhau
    }
    // Kiểm tra xem chuỗi s có chứa ít nhất 1 ký tự đặc biệt không
    bool hasSpecialChar=false;
    for (int i = 0; i < length_s; i++) {
        if (s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i] =='$' || s[i]=='!')
            hasSpecialChar = true;
    }
    if (!hasSpecialChar)
        return -5; // Không chứa ký tự đặc biệt
    // Kiểm tra xem mỗi ký tự trong chuỗi s có phù hợp không
    for (int i = 0; i<length_s; i++) {
        char c = s[i];
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
              c== '@' || c== '#' || c== '%' || c =='$' || c =='!'))
            return i; // Ký tự không hợp lệ
    }
    //Mật khẩu hợp lệ
    return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int first_position;

    for (int i=0; i< num_pwds; i++) {
        const char *password=arr_pwds[i];
        int count= 0;
        int length= strlen(password);
        // Đếm số lần xuất hiện của mật khẩu
        for (int j= 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[j],password) ==0) { //Hàm strcmp() được dùng để so sánh hai chuỗi, hàm trả về giá trị 0 nếu 2 chuỗi bằng nhau. 
                count++;
            }
        }
        // Kiểm tra điều kiện để xác định mật khẩu đúng
        if (count>maxCount || (count==maxCount&&length>maxLength)) {
            maxCount=count;
            maxLength=length;
            first_position=i;
        }
    }
    return first_position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////