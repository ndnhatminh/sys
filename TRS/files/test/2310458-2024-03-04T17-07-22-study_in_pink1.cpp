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

// lập khoảng số đo và làm tròn các số liệu inout
void healthscale(double & HP){
    while(HP<0||HP>666)
    if(HP > 666){
        HP = 666;
    }
    else{
        HP = 0;
    }
    HP = ceil(HP); 
}
void expscale(double & exp){
    while(exp<0||exp>600)
    if(exp > 600){
        exp = 600;
    }
    else{
        exp = 0;
    }
    exp = ceil(exp); 
}

void moneyscale(double & M){
    while(M<0||M>3000)
    if(M > 3000){
        M = 3000;
    }
    else{
        M = 0;
    }
    M = ceil(M); 
}
int firstMeet(int & EXP1, int & EXP2, int E1) {
      // TODO: Complete this function
    double floatEXP1=EXP1;
    double floatEXP2=EXP2;
    double floatE1=E1;
    if (E1>=0 && E1 <=3) {
        switch (E1){
            case 0:
            floatEXP2 += 29;
            break;
            case 1:
            floatEXP2 += 45;
            break;
            case 2:
            floatEXP2 += 75;
            break;
            case 3:
            floatEXP2 +=149;
            break;
        }
        int D = E1 * 3 + EXP1 * 7;
        if ( D %2 == 0 ){
            floatEXP1 += D/200 ;
            expscale(floatEXP1);
        }
        else{
            floatEXP1 -= D/100. ;
            expscale(floatEXP1);
        }
    } else if (E1 >= 4 && E1 <= 19) {
        floatEXP2 += floatE1/4.0f + 19;
        floatEXP1 = floatEXP1-E1;
    } else if (E1 >= 20 && E1 <= 49) {
        floatEXP2 += floatE1/9 + 21;
        floatEXP1 = floatEXP1-E1;
    } else if (E1 >= 50 && E1 <= 65) {
        floatEXP2 += floatE1/16 + 79;
        
        floatEXP1 = floatEXP1-E1;
    } else if (E1 >= 66 && floatE1 <= 79) {
        floatEXP2 += floatE1/4 + 19;
        expscale(floatEXP2);
        if (floatEXP2 > 200 ) {
            floatEXP2 += floatE1/9 + 21;
            
        }
        floatEXP1 = floatEXP1-E1;
    }else if (E1 >= 80 && E1 <= 99) {
        floatEXP2 += floatE1/4 + 19;
        expscale(floatEXP2);
        floatEXP2 += floatE1/9 + 21;
        
        if(floatEXP2 > 400 && E1>=80){
            floatEXP2 += floatE1/16 + 17;
            expscale(floatEXP2);
            floatEXP2 *= 1.15;
            
        }
        floatEXP1 = floatEXP1-E1;
    }
    expscale(floatEXP2);
    EXP2 = floatEXP2;
    expscale(floatEXP1);
    EXP1 = floatEXP1;
    return EXP1 + EXP2;
}

// Task 2
bool chan_le(int& E2){
    bool even;
    if (E2%2==0){
        return 1;
    }else{
        return 0;
    }
}
double percentage(int EXP){
    double S;
    double P;
     if ( EXP - pow((int) sqrt(EXP),2)<pow((int) sqrt(EXP)+1,2)-EXP){
        S = pow ((int) sqrt(EXP),2);
        P=1;
    } else if (EXP <= pow((int) sqrt(EXP)+1,2)){
        S = pow ( (int) sqrt(EXP) + 1, 2);
        P = (EXP/S +80)/123;
    }
    return P;
}

void road_2(double & floatHP1, double & floatEXP1, double & floatM1, int & E2,double P2, int money) {
    if(floatHP1 < 200)
    {
        floatHP1 *= 1.3;
        floatM1 -= 150;
    }
    else
    {
        floatHP1 *= 1.1;
        floatM1 -= 70;
    }
    healthscale(floatHP1);
    moneyscale(floatM1);
    if (chan_le(E2) == true && floatM1 <= 0){
        return;
    }
    else if (chan_le(E2) == false && floatM1 < money){
        return;
    }
    if(floatEXP1 < 400){ 
        floatM1 -= 200;
    }
    else{
        floatM1 -= 120;
        floatEXP1 *= 1.13;
        expscale(floatEXP1);
    }
    healthscale(floatHP1);
    moneyscale(floatM1);
    if (chan_le(E2) == true && floatM1 <= 0){
        return;
    }
    else if (chan_le(E2) == false && floatM1 < money){
        return;
    }

    if(floatEXP1 < 300){
        floatM1 -= 100;
    }
    else{
        floatM1 -= 120;
        floatEXP1*=0.9;
    }
    healthscale(floatHP1);
    moneyscale(floatM1);
    expscale(floatEXP1);
}
double road_3( int E2){ 
    int i;
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E2 < 10) {
        i = E2;
    } else {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }
    return P[i];
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double floatHP1 = HP1;
    double floatEXP1 = EXP1;
    double floatM1 = M1;
    int S;
    double P1;
    double P2;
    double P3;
    const int money = ceil(floatM1/2);
    P1 = percentage(floatEXP1);
    if(chan_le(E2)==true){
        road_2(floatHP1,floatEXP1,floatM1,E2,P2,money);
        floatHP1*=0.83;
        floatEXP1*=1.17;
        expscale(floatEXP1);
        healthscale(floatHP1);
        P2 = percentage(floatEXP1);
    }else if(chan_le(E2)==false){
        while(floatM1 >= money){
            road_2(floatHP1,floatEXP1,floatM1,E2,P2,money);
            P2 = percentage(floatEXP1);
            //kiểm tra số tiền
            if(floatM1<money){
                floatHP1*=0.83;
                floatEXP1*=1.17;
                expscale(floatEXP1);
                healthscale(floatHP1);
            }
        }
    }
    P2 = percentage(floatEXP1);
    P3 = road_3(E2)/100;
    double averageP = (P1+P2+P3)/3;
    if ( round(averageP)==1 ){
        floatEXP1*=0.75;
        expscale(floatEXP1);
    }else if(averageP<1 && averageP>=0.5 ){
        floatHP1*=0.9;
        healthscale(floatHP1);
        floatEXP1*=1.2;
        expscale(floatEXP1);
    }else {
        floatHP1*=0.85;
        healthscale(floatHP1);
        floatEXP1*=1.15;
        expscale(floatEXP1);
    }

    M1=floatM1;
    HP1=floatHP1;
    EXP1=floatEXP1;
    return  M1+HP1+EXP1;
}
// Task 3
int taxiscore(int i, int j, int E3) {
    return ((E3 * j) + (i * 2)) * (i - j);
}
int maxcheotrai( int i, int j,int E3) {
    int score = 0;
    while (i!=0 && j !=0) {
        //đg chéo lên bên trái
        if(score < taxiscore(i,j,E3)){
            score=abs(taxiscore(i,j,E3));
        }
        i--;
        j--;
    }
    while (i!=10 && j !=10) {
        //đg chéo xuống phải
        if(score < taxiscore(i,j,E3)){
            score=abs(taxiscore(i,j,E3));
        }
        i++;
        j++;
}
    return score;
}

int maxcheophai( int i, int j, int E3) {
    int score = 0;
    while (i!=10 && j !=0) {
        //đường chéo lên bên phải
        if(score < taxiscore(i,j,E3)){
            score=abs(taxiscore(i,j,E3));
        }
        i++;
        j--;
    }
    while (i!=0 && j !=10) {
        //đường chéo xuống bên trái
        if(score < taxiscore(i,j,E3)){
            score = abs(taxiscore(i,j,E3));
        }
        i--;
        j++;
        }
    return score;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    double floatHP1=HP1;
    double floatEXP1=EXP1;
    double floatHP2=HP2;
    double floatEXP2=EXP2;

    int matrix[10][10] ;
    //khai triển ma trận của taxi
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = taxiscore(i, j, E3);
        }
    }
    //khai triển ma trận của sherlock theo taxi bằng các đường chéo
    int sherlockmatrix[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            //lấy giá trị lớn nhất của hai đường
            sherlockmatrix[i][j]=max(abs(maxcheophai(i,j,E3)),abs(maxcheotrai(i,j,E3)));
        }
    }
    //Đếm I và J để tính tọa độ điểm gặp
    int I=0;
    int J=0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(taxiscore(i,j,E3)>E3*2){
                I++;
            }
            if(taxiscore(i,j,E3)<-E3){
                J++;
            }
        }
    }
    while(I>=10){
        I= I%10 + I/10;
    }
    while(J>=10){
        J= J%10 + J/10;
    }
    //so sánh độ lớn của taxi và sherlock tại điểm gặp
    //tính toán thay đổi của các giá trị
    if(abs(matrix[I][J])<=abs(sherlockmatrix[I][J])){
        HP1=ceil(floatHP1*1.1);
        HP2=ceil(floatHP2*1.1);
        EXP1=ceil(floatEXP1*1.12);
        EXP2=ceil(floatEXP2*1.12);
        return sherlockmatrix[I][J];
    }else{
        HP1=ceil(floatHP1*0.9);
        HP2=ceil(floatHP2*0.9);
        EXP1=ceil(floatEXP1*0.88);
        EXP2=ceil(floatEXP2*0.88);
        return matrix[I][J];
    }

    // Return the winner's score
}

// Task 4
//hàm contain để kiểm tra kí tự có trong chuỗi
bool contains(char *arr, char c, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (arr[i] == c) {
            return true;
        }
    }
    return false;
}

int checkPassword(const char *s, const char *email) {
    if (strlen(s) < 8) {
        return -1;
    } else if (strlen(s) > 20) {
        return -2;
    }

    size_t atPos = strcspn(email, "@");
    if (email[atPos] == '\0' || atPos >= 100) {
        return -3;
    }
    std::string se(email, atPos);

    size_t sePos = strcspn(s, se.c_str());
    if (s[sePos] != '\0') {
        return -(300 + static_cast<int>(sePos));
    }

    char specialChars[] = {'@', '#', '$', '%', '!'};
    bool hasSpecialChar = false;
    for (size_t i = 0; i < strlen(s); ++i) {
        if (contains(specialChars, s[i], sizeof(specialChars) / sizeof(char))) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        return -5;
    }

    for (size_t i = 0; i < strlen(s) - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + static_cast<int>(i));
        }
    }

    for (size_t i = 0; i < strlen(s); ++i) {
        if (!isalnum(s[i]) && !contains(specialChars, s[i], sizeof(specialChars) / sizeof(char))) {
            return static_cast<int>(i);
        }

        if (i < strlen(s) - 2 && s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + static_cast<int>(i));
        }
    }

    return -10;
}



// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    while (num_pwds <= 0) {
        return -1;  // Trả về -1 nếu không có mật khẩu nào
    }

    const char *Password = arr_pwds[0];
    int Count;
    //dùng static_cast để ép kiểu 
    int Length = static_cast<int>(strlen(arr_pwds[0]));//strlen đo độ dài string

    for (int i = 0; i < num_pwds; ++i) {
        const char *currentPassword = arr_pwds[i];
        int currentCount = 1;
        int j = i + 1;
        while ( j < num_pwds) {
            if (strcmp(currentPassword, arr_pwds[j]) == 0) {
                currentCount++;
            }
            j++;
        }
        // Cập nhật mật khẩu xuất hiện nhiều lần nhất
        while (currentCount > Count ||(currentCount == Count && static_cast<int>(strlen(currentPassword)) > Length)) {
            Password = currentPassword;
            Count = currentCount;
            Length = static_cast<int>(strlen(currentPassword));
            break;
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu xuất hiện nhiều lần nhất
    int i=0;
    while( i < num_pwds) {
        if (strcmp(arr_pwds[i], Password) == 0) {
            return i;
        }
        i++;
    }

    return -1;  // Trả về -1 nếu không tìm thấy mật khẩu đúng
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////