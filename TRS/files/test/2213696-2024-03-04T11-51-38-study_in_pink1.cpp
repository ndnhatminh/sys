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
    // TODO: Complete this function
    if ((e1<0)||(e1>99)) return -99; //nếu số e ngoài đoạn 0->99 thì hàm không làm gì và trả về -99
    if (exp1<0) exp1=0;
    if (exp1>600) exp1=600;
    if (exp2<0) exp2=0;
    if (exp2>600) exp2=600;
    //Trường hợp 1
    if ((e1>=0) && (e1<=3)){
        if (e1==0) exp2=exp2+29; //thongtin1
        if (e1==1) exp2=exp2+45; //thongtin2
        if (e1==2) exp2=exp2+75; //thongtin3
        if (e1==3) exp2=exp2+149; //thongtin4
        if (exp2>600) exp2=600;
        //quyết định của sherlock
        int d=e1*3+exp1*7;
        if (d%2==0) exp1=ceil(exp1+d/200.0);
        if (exp1>600) exp1=600;
        if (d%2!=0) exp1=ceil(exp1-d/100.0);
        if (exp1<0) exp1=0;
    }
    //Trường hợp 2
    if ((e1>=4) && (e1<=99)){
        if ((e1>=4) && (e1<=19)) exp2=ceil(exp2+e1/4.0+19); //thongtin1
        if ((e1>=20) && (e1<=49)) exp2=ceil(exp2+e1/9.0+21); //thongtin2
        if ((e1>=50) && (e1<=65)) exp2=ceil(exp2+e1/16.0+17); //thongtin3
        if ((e1>=66) && (e1<=79)){ //thongtin4
            exp2=ceil(exp2+e1/4.0+19); 
            if (exp2>200) exp2=ceil(exp2+e1/9.0+21);
        }
        if ((e1>=80) && (e1<=99)){ //thongtin5
            exp2=ceil(exp2+e1/4.0+19);
            exp2=ceil(exp2+e1/9.0+21);
            if (exp2>400) exp2=ceil(exp2+e1/16.0+17);
            exp2=ceil(exp2+exp2*0.15); //watson được sherlock giải thích cả 3 thongtin, watson được cộng 15% Exp đang có
        }
        if (exp2>600) exp2=600;
        exp1=exp1-e1;
        if (exp1<0) exp1=0;
    }
    return exp1 + exp2;
}

//tìm số chính phương gần nhất
int findNearestPerfectSquare(int num) {
    double squareRoot = sqrt(num);
    int lowerSquare = floor(squareRoot);
    int upperSquare = ceil(squareRoot);
    int nearestPerfectSquare;
    if ((upperSquare * upperSquare - num) < (num - lowerSquare * lowerSquare)) {
        nearestPerfectSquare = upperSquare * upperSquare;
    } else {
        nearestPerfectSquare = lowerSquare * lowerSquare;
    }
    return nearestPerfectSquare;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if ((E2<0)||(E2>99)) return -99;//nếu số E ngoài đoạn 0->99 thì hàm không làm gì và trả về -99
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666;
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (M1<0) M1=0;
    if (M1>3000) M1=3000;
    //ROAD 01
    double P1;
    int S=findNearestPerfectSquare(EXP1);
    if (EXP1>=S) P1=1.0;
    if (EXP1<S) P1=((EXP1*1.0)/S+80)/123;
    //ROAD 02
    double P2;
    int MS=M1; //số tiền ban đầu
    int MP=MS-M1; //số tiền đã chi là ban đầu trừ hiện tại
    //trường hợp E2 là số lẻ
    while (E2%2!=0){ 
        if (MP>MS*0.5||M1==0){ //khi số tiền đã chi vượt quá 50% số tiền ban đầu hoặc số tiền bằng 0
            HP1=ceil(HP1-HP1*0.17);
            EXP1=ceil(EXP1+EXP1*0.17);
            if (EXP1>600) EXP1=600;
            break; //không trải qua sự kiện nào nữa
        } 
        if (MP<=MS*0.5){ //khi số tiền đã chi không vượt quá 50% số tiền ban đầu
            //sự kiện 1 mua thức ăn và nước uống
            if (HP1<200){
                HP1=ceil(HP1+HP1*0.3);
                M1=M1-150;
            }
            if (HP1>=200){
                HP1=ceil(HP1+HP1*0.1);
                if (HP1>666) HP1=666;
                M1=M1-70;
            }   
            if (M1<0) M1=0;
            MP=MS-M1; //cập nhật số tiền đã chi
        } 
        if (MP<=MS*0.5){ //khi số tiền đã chi không vượt quá 50% số tiền ban đầu
            //sự kiện 2 thuê taxi hoặc xe ngựa
            if (EXP1<400) M1=M1-200;
            if (EXP1>=400) M1=M1-120;
            if (M1<0) M1=0;
            EXP1=ceil(EXP1+EXP1*0.13);
            if (EXP1>600) EXP1=600;
            MP=MS-M1; //cập nhật số tiền đã chi
        }
        if (MP<=MS*0.5){
            //sự kiện 3 giúp đỡ người vô gia cư
            if (EXP1<300) M1=M1-100;
            if (EXP1>=300) M1=M1-120;
            if (M1<0) M1=0;
            EXP1=ceil(EXP1-EXP1*0.1);
            MP=MS-M1; //cập nhật số tiền đã chi
        }
    }
    //trường hợp E2 là số chẵn
    if (E2%2==0){ 
        if (M1>0){ //khi số tiền lớn hơn 0
            //sự kiện 1 mua thức ăn và nước uống
            if (HP1<200){
                HP1=ceil(HP1+HP1*0.3);
                M1=M1-150;
            }
            if (HP1>=200){
                HP1=ceil(HP1+HP1*0.1);
                if (HP1>666) HP1=666;
                M1=M1-70;
            }   
            if (M1<0) M1=0;
        } 
        if (M1>0){ //khi số tiền lớn hơn 0
            //sự kiện 2 thuê taxi hoặc xe ngựa
            if (EXP1<400) M1=M1-200;
            if (EXP1>=400) M1=M1-120;
            if (M1<0) M1=0;
            EXP1=ceil(EXP1+EXP1*0.13);
            if (EXP1>600) EXP1=600;
        }
        if (M1>0){ //khi số tiền lớn hơn 0
            //sự kiện 3 giúp đỡ người vô gia cư
            if (EXP1<300) M1=M1-100;
            if (EXP1>=300) M1=M1-120;
            if (M1<0) M1=0;
            EXP1=ceil(EXP1-EXP1*0.1);
        }
        HP1=ceil(HP1-HP1*0.17);
        EXP1=ceil(EXP1+EXP1*0.17);
        if (EXP1>600) EXP1=600;
    }
    S=findNearestPerfectSquare(EXP1);
    if (EXP1>=S) P2=1;
    if (EXP1<S) P2=(EXP1/S+80)/123;
    //ROAD 03
    int i;
    if (E2<10) i=E2;
    if (E2>=10) i=(E2/10+E2%10)%10;
    double P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double P3=P[i];
    //Sau khi đi hết 3 con đường
    if (P1==1.0 && P2==1.0 && P3==1.0) EXP1=ceil(EXP1-EXP1*0.25);
    if (!(P1==1.0 && P2==1.0 && P3==1.0)){
        double P=(P1+P2+P3)/3;
        if (P1<0.5) {
            HP1=ceil(HP1-HP1*0.15);
            EXP1=ceil(EXP1+EXP1*0.15);
            if (EXP1>600) EXP1=600;
        }
        if (P1>=0.5){
            HP1=ceil(HP1-HP1*0.1);
            EXP1=ceil(EXP1+EXP1*0.2);
            if (EXP1>600) EXP1=600;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if ((E3<0)||(E3>99)) return -99;//nếu số E ngoài đoạn 0->99 thì hàm không làm gì và trả về -99
    if (HP1<0) HP1=0;
    if (HP1>666) HP1=666;
    if (EXP1<0) EXP1=0;
    if (EXP1>600) EXP1=600;
    if (HP2<0) HP2=0;
    if (HP2>666) HP2=666;
    if (EXP2<0) EXP2=0;
    if (EXP2>600) EXP2=600;
    //Thiết lập ma trận
    int X[10][10]={
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    //tính giá trị cho từng vị trí trong mảng
    for (int i=0; i<10; i++){ 
        for (int j=0; j<10; j++){
            X[i][j]=((E3*j)+(i*2))*(i-j);
        }
    }
    //xác định vị trí gặp nhau
    int n=0,m=0;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (X[i][j]>E3*2) n++;
            if (X[i][j]<-E3) m++;
        }
    }
    while (n>=10) n=(n/10+n%10); //cộng các chữ số cho đến khi còn 1 chữ số
    while (m>=10) m=(m/10+m%10);
    //xác định giá trị lớn nhất của đường chéo trái và phải tại điểm gặp nhau
    //Xác định giá trị lớn nhất của đường chéo trái tại điểm gặp nhau
    int i=n,j=m, max;
    while (i>=0 && i<10 && j>=0 && j<10){
        if (X[i][j]>max) max=X[i][j];
        i--;
        j--;
    }
    i=n;
    j=m;
    while (i>=0 && i<10 && j>=0 && j<10){
        if (X[i][j]>max) max=X[i][j];
        i++;
        j++;
    }
    //xác định giá trị lớn nhất của đường chéo phải tại điểm gặp nhau
    i=n;
    j=m;
    while (i>=0 && i<10 && j>=0 && j<10){
        if (X[i][j]>max) max=X[i][j];
        i--;
        j++;
    }
    i=n;
    j=m;
    while (i>=0 && i<10 && j>=0 && j<10){
        if (X[i][j]>max) max=X[i][j];
        i++;
        j--;
    }
    //điểm của nhóm sherlock
    int sherlockpoint=abs(max);
    //không bắt kịp
    if (sherlockpoint<abs(X[n][m])){
        EXP1=ceil(EXP1-EXP1*0.12);
        HP1=ceil(HP1-HP1*0.1);
        EXP2=ceil(EXP2-EXP2*0.12);
        HP2=ceil(HP2-HP2*0.1);
        return X[n][m];
    }
    //bắt kịp
    if (sherlockpoint>=abs(X[n][m])){
        EXP1=ceil(EXP1+EXP1*0.12);
        if (EXP1>600) EXP1=600;
        HP1=ceil(HP1+HP1*0.1);
        if (HP1>666) HP1=666;
        EXP2=ceil(EXP2+EXP2*0.12);
        if (EXP1>600) EXP1=600;
        HP2=ceil(HP2+HP2*0.1);
        if (HP2>666) HP2=666;
        return sherlockpoint;
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    bool c1=0,c2=0,c3=0,c4=0,c5=0;
    bool c11=0,c12=0;
    int len; 
    len=strlen(s);
    //điều kiện thứ 1
    if (len>=8) c11=1; //độ dài tối thiểu là 8
    if (len<=20) c12=1; //độ dài tối đa là 20
    if (c11&&c12) c1=1; //thỏa mãn độ dài của mật khẩu
    //điều kiện thứ 2
    int error;
    for (int i=0; i<len; i++){
        if ((s[i]>=48 && s[i]<=57)|| //chữ số
            (s[i]>=97 && s[i]<=122)|| //chữ cái thường
            (s[i]>=65 && s[i]<=90)|| //chữ cái in hoa
            (s[i]==64 || s[i]==35 || s[i]==37 || s[i]==36 || s[i]==33)) c2=1; //kí tự đặc biệt @#$&!
        else {
            error=i;
            break;
        }
    }
    //điều kiện thứ 3
    int i=0;
    int sei;
    // Kiểm tra mật khẩu không chứa chuỗi se
    char* se = new char[100];
    while (email[i] != '@') {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0'; // Kết thúc chuỗi se
    if (strstr(s, se) == nullptr) { //nếu không chứa thì hợp lệ
        c3=1;
    }
    else sei=strstr(s, se)-s; //nếu có chứa thì vi phạm, tính vị trí đầu tiên vi phạm
    delete[] se;
    //điều kiện thứ 4
    // Kiểm tra không có nhiều hơn 2 ký tự liên tiếp và giống nhau
    int sci;
    for (int i=0; i<len-1; i++) {
        if (s[i]==s[i+1] && s[i+1]==s[i+2]) { //vi phạm
        c4=0;
        sci=i;
        break;
        }
        else c4=1; //hợp lệ
    }
    //điều kiện thứ 5
    //chứa ít nhất một ký tự đặc biệt
    for (int i=0; i<len; i++){
        if (s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!') c5=1; //hợp lệ
    }
    //trả về kết quả
    if (c1&&c2&&c3&&c4&&c5) return -10; //hợp lệ
    if (c11==0) return -1; //ngắn hơn độ dài tối thiểu
    if (c12==0) return -2; //dài hơn độ dài tối đa
    if (c3==0) return -(300+sei);
    if (c4==0) return -(400+sci);
    if (c5==0) return -5;
    if (c2==0) return error; //các trường hợp còn lại trả về vị trí vi phạm đầu tiên
    return -1;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    //tính tần suất xuất hiện của mỗi mật khẩu
    int n[num_pwds]; // mảng đếm tần suất
    for (int i=0; i<num_pwds; i++){
        n[i]=1;
        for (int j=i+1; j<num_pwds; j++){
            if (strcmp(arr_pwds[i],arr_pwds[j])==0) n[i]++; //so sánh 2 mật khẩu có giống nhau hay không
        }
    }
    //tìm mật khẩu có số lần xuất hiện nhiều nhất
    int maxfre=0;
    for (int i=0; i<num_pwds; i++){
        if (n[i]>maxfre) maxfre=n[i];
    }
    //tìm số mật khẩu có tần suất xuất hiện nhiều nhất và ngang nhau
    int pos[num_pwds]; //mảng chứa vị trí của các mật khẩu có tần suất xuất hiện nhiều nhất ngang nhau
    int a=0;
    for (int i=0; i<num_pwds; i++){
        if (n[i]==maxfre){
            pos[a]=i;
            a++;
        }
    }
    //so sánh độ dài các mật khẩu xuất hiện nhiều nhất
    size_t maxlen=0;
    int excpwd=-1;
    for (int i=0; i<a; i++){
        if (strlen(arr_pwds[pos[i]])>maxlen){
            maxlen=strlen(arr_pwds[pos[i]]);
            excpwd=pos[i];
        } 
    }
    return excpwd;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////