#include "study_in_pink1.h"

bool readFile(const string &filename,int &HP1,int &HP2,int &EXP1,int &EXP2,int &M1,int &M2,int &E1,int &E2,int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
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

/* ...........................................dãy phân cách .............................................*/

//Hàm làm tròn số  nguyên gần nhất
// int convertToInt ( float n){
//     return static_cast<int>(n+0.999);
// }

// Hàm làm tròn số nguyên theo quy tắc chuẩn
// int convertToInt01 ( float n){
//     return (n+0.5);
// }
int valueLimited(int n, int min, int max){
    return ((n>max)? max : (n<min)? min : n );
}
// Khoảng giá trị các hàm
void scopeHP(int &hp){
    // hp=convertToInt(hp);
    hp=valueLimited(hp,0,666);
}

void scopeEXP(int &exp){
    // exp=convertToInt(exp);
    exp=valueLimited(exp,0,600);
}

void scopeM(int &m){
    // m=convertToInt(m);
    m=valueLimited(m,0,3000);
}

/* ...........................................dãy phân cách .............................................*/
bool checkHalfMoney( int &m1,int &m2){
    return (m1>=m2);
}

void road_2_EVEN(int &HP1, int &EXP1, int &M1, int E2){
            //Heal
            if(HP1<200){
                HP1=HP1*1.3 +0.999;
                M1-=150;
            }
            else {
                HP1=HP1*1.1+0.999;
                M1-=70;
            }
            scopeHP(HP1);
            scopeM(M1);
            if(M1!=0){
                // taxi or horse
                if(EXP1<400){
                    M1-=200;
                }
                else{ 
                    M1-=120;
                }

                EXP1=EXP1*1.13+0.999;
                scopeEXP(EXP1);
                scopeHP(HP1);
                scopeM(M1);
                if(M1!=0){
                    //homeless man
                    if(EXP1<300){
                        M1-=100;
                    }
                    else {
                        M1-=120;
                    }
                    EXP1=EXP1*0.9+0.999;
                    scopeEXP(EXP1);
                    scopeHP(HP1);
                    scopeM(M1);
                }
            }
}
void road_2_ODD(int &HP1, int &EXP1, int &M1, int E2){
        int halfM1= M1*0.5+0.999;
        int spendM1=0;
        bool shouldStop = false;
        while(!(E2%2==0) && (M1 > 0) && !shouldStop ){   
            if(checkHalfMoney(halfM1, spendM1)){
            // are u hungry?
                if(HP1 < 200){
                    HP1=HP1*1.3 +0.999;
                    M1-=150;
                    spendM1+=150;
                }
                else {
                    HP1=HP1*1.1+0.999;
                    M1-=70;
                    spendM1+=70;
                }
                scopeHP(HP1);
                scopeM(M1);
                // cout<<"HP1: "<<HP1<<endl;
                if(checkHalfMoney(halfM1, spendM1)){
                        // taxi or horse
                        if(EXP1<400){
                            M1-=200;
                            EXP1=EXP1*1.13+0.999;
                            spendM1+=200;
                        }
                        else {
                            M1-=120;
                            EXP1=EXP1*1.13+0.999;
                            spendM1+=120;
                        }
                        scopeHP(HP1);
                        scopeM(M1);
                        if(checkHalfMoney(halfM1, spendM1)){
                            //homeless man
                            if(EXP1<300){
                                M1-=100;
                                spendM1+=100;
                            }
                            else {
                                M1-=120;
                                spendM1+=120;
                            }
                            EXP1=EXP1*0.9+0.999;
                            scopeEXP(EXP1);
                            scopeHP(HP1);
                            scopeM(M1);
                        }
                        else {shouldStop = true;}    
                }
                else {shouldStop = true;}

            }
            else {shouldStop = true;}
        }

}
// void road_2(int &HP1, int &EXP1, int &M1, int &E2, int $halfM1, int $spendM1){
//     int halfM1= M1*0.5;
//     int spendM1=0;
// // are u hungry?
//     if(HP1 < 200){
//         HP1*=1.3;
//         M1-=150;
//         spendM1+=150;
//     }
//     else {
//         HP1*=1.1;
//         M1-=70;
//         spendM1+=70;
//     }
//     scopeHP(HP1);
//     scopeM(M1);
//     if(checkMoney(M1)){
//         return;
//     }
// // taxi or horse
//     if(EXP1<400){
//         M1-=200;
//         spendM1+=200;
//     }
//     else {
//         M1-=120;
//         EXP1*=1.13;
//         EXP1+=0.999;
//         spendM1+=120;
//     }
//     scopeHP(HP1);
//     scopeM(M1);
//     if(checkMoney(M1)){
//         return;
//     }
// //homeless man
//     if(EXP1<300){
//         M1-=100;
//         spendM1+=100;
//     }
//     else {
//         M1-=120;
//         spendM1+=120;
//     }
//     EXP1*=0.9;
//     scopeEXP(EXP1);
//     scopeHP(HP1);
//     scopeM(M1);
//     if(checkMoney(M1)){
//         return;
//     }
// }


/* ...........................................dãy phân cách .............................................*/
// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1) {
    // TODO: Complete this function
    if(E1<0 || E1>99){
        return -99;
    }
    if(E1>=0 && E1<=3){
        switch(E1){
            case 0: EXP2+=29;
                    break;
            case 1: EXP2+=45;
                    break;
            case 2: EXP2+=75;
                    break;
            case 3: EXP2+=149;
                    break;
        }
        scopeEXP(EXP2);
        int D=E1*3 + EXP1*7;
        float x1=D/200.0+0.999;
        float x2=D/100.0;
        if(D%2==0){
            EXP1+=x1;
        }
        else {
            EXP1=EXP1-x2+0.999;
            // EXP1=EXP1+0.999;
        }
        // EXP1+=0.999;
        scopeEXP(EXP1);
    }
    
    if(E1>=4 && E1<=99){
        float b1=(E1/4.0+19)+0.999;
        float b2=(E1/9.0+21)+0.999;
        float b3=(E1/16.0+17)+0.999;
        if(E1>=4 && E1<=19){
            EXP2+=b1;
            scopeEXP(EXP2);
        }
        else if(E1>=20 && E1<=49){
            EXP2+=b2;
            scopeEXP(EXP2);
        }
        else if(E1>=50 && E1<=65){
            EXP2+=b3;
            scopeEXP(EXP2);
        }
        else if(E1>=66 && E1<=79){
            EXP2+=b1;
            scopeEXP(EXP2);
            if(EXP2>200){
                EXP2+=b2;
                scopeEXP(EXP2);
            }
        }
        else if(E1>=80 && E1<=99){
            EXP2+=b1;
            scopeEXP(EXP2);
            EXP2+=b2;
            scopeEXP(EXP2);
            if(EXP2>400){
                EXP2+=b3;
                scopeEXP(EXP2);
                EXP2=EXP2*1.15+0.999;
                scopeEXP(EXP2);
            }
        }
        EXP1-=E1;
        scopeEXP(EXP1);
    }
    
    return EXP1 + EXP2;
}

/* ...........................................dãy phân cách .............................................*/
// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99){
        return -99;
    }
    
/*.........road_1...........*/
    double P1,P2,P3;
    int t1=sqrt(EXP1)+0.5;
    int S1=t1*t1;
    if(EXP1>=S1){
        P1=100;
    }
    else{
        float sx1=float(EXP1)/float(S1);
        float hx=(float(sx1) +80.0)/123.0;
        P1= hx * 100.0 ;
    }
/*..........road_2.............*/
    if(E2%2==0){
        road_2_EVEN(HP1,EXP1,M1,E2);
    }
    else{
        road_2_ODD(HP1,EXP1,M1,E2);
    }
    HP1=HP1*0.83+0.999;
    EXP1=EXP1*1.17+0.999;
    scopeEXP(EXP1);
    scopeHP(HP1);
    scopeM(M1);
    // cout<<"HP1 T: "<<HP1<<endl;
    int u1=sqrt(EXP1)+0.5;
    int S2=u1*u1;
    if(EXP1>=S2){
        P2=100;
    }
    else {
        float sx2=float(EXP1)/float(S2);
        float hx2=(float(sx2) +80.0)/123.0;
        P2= hx2 * 100.0 ;
    }
/*..........road_3.............*/
    int i=0;
    if (E2 < 10) {i=E2;} 
    else {
        int sum = (E2 / 10) + (E2 % 10); // Tính tổng của hai chữ số của E2
        i = sum % 10;
    }

    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    P3= p[i];
    // cout<<"P3: "<<P3<<endl;
/*..........result.............*/
    if((P1==100)&&(P2==100)&&(P3==100)){
        EXP1=EXP1*0.75+0.999;
    }
    else {
        float average = (P1+P2+P3)/3.0;
        if(average<50){
            HP1=HP1*0.85+0.999;
            EXP1=EXP1*1.15+0.999;
        }
        else{
            HP1=HP1*0.9+0.999;
            EXP1=EXP1*1.2+0.999;
        }
    }
    scopeEXP(EXP1);
    scopeHP(HP1);
    scopeM(M1);
    return HP1 + EXP1 + M1;
}

/* ...........................................dãy phân cách .............................................*/
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0 || E3>99){
        return -99;
    }
    // TODO: Complete this function
    int taxiMap[10][10] = {0}; // Khởi tạo ma trận taxi với các giá trị ban đầu là 0
    int i, j; // Biến lưu vị trí gặp nhau của Sherlock và Watson với taxi

    // Tính điểm của taxi tại mỗi vị trí trong ma trận
    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            taxiMap[row][col] = ((E3 * col) + (2 * row)) * (row - col);
        }
    }

    // Tính vị trí gặp nhau của Sherlock và Watson với taxi
    int MoreE3Count = 0;
    int LessNegE3Count = 0;

    for (int row = 0; row < 10; ++row) {
        for (int col = 0; col < 10; ++col) {
            if (taxiMap[row][col] > E3 * 2) {
                MoreE3Count++;
            } else if (taxiMap[row][col] < -E3) {
                LessNegE3Count++;
            }
        }
    }

    // Kiểm tra và cập nhật vị trí gặp nhau
    while (MoreE3Count >= 10) {
        int sum = 0;
        while (MoreE3Count != 0) {
            sum += MoreE3Count%10;
            MoreE3Count/=10;
        }
        MoreE3Count = sum;
    }

    while (LessNegE3Count >= 10) {
        int sum = 0;
        while (LessNegE3Count != 0) {
            sum += LessNegE3Count%10;
            LessNegE3Count/=10;
        }
        LessNegE3Count = sum;
    }

    i = MoreE3Count;
    j = LessNegE3Count;
    // cout<<"i:"<<i<<", j:"<<j<<endl;

/*So sánh điểm của taxi với điểm của Sherlock và Watson tại vị trí gặp nhau*/
    int taxiScore = taxiMap[i][j];
    // cout<<"TaxiScore:"<<taxiScore<<endl;
    // Tính điểm của Sherlock và Watson tại vị trí gặp nhau (i, j)
    int leftDcheo = 0, rightDcheo = 0;
    for (int k = 0; k < 10; ++k) {
        int a = i - k;
        int b = j - k;
        int c = i + k;
        if (a>=0 && b>=0 && a<10 && b<10) {
            leftDcheo = max(leftDcheo, taxiMap[i - k][j - k]);
        }
        if (b >= 0 && c >= 0 && b < 10 && c <10) {
            rightDcheo = max(rightDcheo, taxiMap[i + k][j - k]);
        }
    }
    int sherlockWatsonScore = max(leftDcheo, rightDcheo);
        

    // Nếu điểm của taxi lớn hơn hoặc bằng điểm của Sherlock và Watson, trả về -1 (taxi không bị bắt)
    if (abs(taxiScore) > abs(sherlockWatsonScore)) {
        EXP1=EXP1*0.88+0.999;
        HP1=HP1*0.9+0.999;  
        EXP2=EXP2*0.88+0.999;
        HP2=HP2*0.9+0.999;  
    } else { 
        EXP1=EXP1*1.12+0.999;
        HP1=HP1*1.1+0.999;  
        EXP2=EXP2*1.12+0.999;
        HP2=HP2*1.1+0.999;
    }
    scopeEXP(EXP1);
    scopeEXP(EXP2);
    scopeHP(HP1);
    scopeHP(HP2);
    // Trả về kết quả: hàm trả về điểm số lớn hơn giữa taxi và Sherlock & Watson
    // (lưu ý: trả về giá trị âm nếu điểm số là âm)
    if (abs(taxiScore) > abs(sherlockWatsonScore)){
        return taxiScore;
    }
    else {
        return sherlockWatsonScore;
    }
}

/* ...........................................dãy phân cách .............................................*/
// Task 4
int checkPassword(const char *s, const char *email) {
    // Lấy chuỗi se
    // TODO: Complete this function
    const char *Acong = strchr(email, '@');
    int seLength = Acong - email;
    char se[101];
    strncpy(se, email, seLength);
    se[seLength] = '\0';

    // Kiểm tra chiều dài của chuỗi
    int passLength = strlen(s);
    if (passLength < 8) return -1; // Password ngắn hơn độ dài tối thiểu
    if (passLength > 20) return -2; // Password dài hơn độ dài tối đa

    // Kiểm tra tồn tại chuỗi se trong password
    const char *sePos = strstr(s, se);
    if (sePos != NULL) return -(300 + (sePos - s)); // Password chứa chuỗi se

    // Kiểm tra có nhiều hơn 2 ký tự liên tiếp giống nhau không
    for (int i = 0; i < passLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Password chứa nhiều hơn 2 ký tự liên tiếp giống nhau
        }
    }
    // Kiểm tra xem password có chứa ký tự đặc biệt không
    const char *specialChars = "@#%$!";
    bool isSpecialChar = false;
    for (int i = 0; i < passLength; ++i) {
        if (strchr(specialChars, s[i]) != NULL) {
            isSpecialChar = true;
            break;
        }
    }
    if (!isSpecialChar) return -5; // Password không chứa ký tự đặc biệt
    
    for (int i = 0; i < passLength; ++i) {
        char c = s[i];
        if (!(('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || strchr(specialChars, c) != nullptr))
            return i; // Ký tự không hợp lệ được tìm thấy ở vị trí i
    }



    return -10; // Password hợp lệ
}


/* ...........................................dãy phân cách .............................................*/
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int maxCount = 0;   // chuỗi xuất hiện nhiều nhất
    int maxLen = 0;  // chuỗi dài nhất 
    int index = -1;     // vị trí xuất hiện đầu tiên của chuỗi

    for(int i=0; i<num_pwds; ++i){
        const char * newpwds = arr_pwds[i];
        int curLen = strlen(newpwds);
        int curCount = 1;

        //Duyệt các chuỗi khác xem có giống không
        for(int j=i+1; j<num_pwds; ++j){
            if(strcmp(newpwds, arr_pwds[j]) == 0){
                curCount++;
            }
        }
        if(curCount>maxCount || (curCount==maxCount && curLen > maxLen)){
            maxLen=curLen;
            maxCount=curCount;
            index=i;
        }
    }
    return index;

}

/* ...........................................dãy phân cách .............................................*/
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////