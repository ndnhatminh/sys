

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
    int & E3) 
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) 
    {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else 
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//Check gioi han cua exp, hp, m
void CheckHP(int &HP){          
    if (HP > 666) HP = 666;
    if (HP < 0) HP = 0;
}
void CheckEXP(int &EXP){
    if (EXP > 600) EXP = 600;
    if (EXP < 0) EXP = 0;
}
void CheckM(int &M){
    if (M > 3000) M = 3000;
    if (M < 0) M = 0;}
// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    //case1
    // nếu e1 vượt quá giới hạn, hàm trả về -99
    if (E1<0 || E1 > 99) {
        return -99;
    } 
    if (E1 >=0 && E1<=3) {
   		if(E1==0){
            EXP2 += 29;
            CheckEXP(EXP2);
        }
        if(E1==1){
            EXP2 += 45; 
            CheckEXP(EXP2);
        }
        if(E1==2){
            EXP2 += 75; 
            CheckEXP(EXP2);
        }
        if(E1==3){
            EXP2 += (29+45+75);
            CheckEXP(EXP2);
        }
		
        int D = 0;
		D = E1*3 + EXP1*7;
		if (D%2==0) {
            EXP1 = ceil(EXP1 + (D*1.0/200));
            CheckEXP(EXP1);
        } 
        else {
            EXP1 = ceil(EXP1 -(D*1.0/100)); 
            CheckEXP(EXP1);
        }
    }
    //case2
   	if (E1>=4 && E1<=99) {
   		if (E1 >=4 && E1<=19) {
            EXP2 = ceil(EXP2 + ((E1*1.0)/4 + 19));
            CheckEXP(EXP2);
        }
        if (E1>=20 && E1<=49) {
            EXP2 = ceil(EXP2 + ((E1*1.0)/9 +21)); 
            CheckEXP(EXP2); 
        }  
        if (E1>=50 && E1<=65) {
            EXP2 = ceil(EXP2 + ((E1*1.0)/16 +17)); 
            CheckEXP(EXP2);
        }
	    if (E1>=66 && E1<=79) {
            EXP2 = ceil(EXP2 + ((E1*1.0)/4 + 19)); 
            CheckEXP(EXP2);
            if (EXP2 > 200) {
                EXP2 = ceil(EXP2 + ((E1*1.0)/9 +21)); 
                CheckEXP(EXP2);
            }
        }
        if  (E1>=80 && E1<=99){
            EXP2 = EXP2 + float(E1)/4 + 19 + 0.999; 
            CheckEXP(EXP2);
            EXP2 = EXP2 + float(E1)/9 +21 + 0.999; 
            CheckEXP(EXP2);
            if (EXP2 > 400 ) {
                EXP2 = ceil(EXP2 + ((E1*1.0)/16 +17));
                CheckEXP(EXP2);
                EXP2 = ceil(EXP2 + ((EXP2*1.0)/100*15)); 
                CheckEXP(EXP2);
            }
        }
        EXP1 -= E1; CheckEXP(EXP1);
    }
    return EXP1 + EXP2;
}

// Task 2
double Chinhphuong(int & EXP1){
        double RoundUp = ceil(sqrt(EXP1));
        double RoundDown = floor(sqrt(EXP1));
        double Nearest = ((abs(RoundUp*RoundUp - EXP1) < abs(RoundDown*RoundDown - EXP1)) ? abs(RoundUp*RoundUp) : abs(RoundDown*RoundDown));
    return (abs(Nearest));
}
int traceLuggage(int & HP1, int & EXP1 , int & M1, int E2) {
    if (E2<0 || E2>99) {return -99;} // khi e2 vượt giới hạn

    CheckEXP(EXP1); CheckHP(HP1); CheckM(M1);
    double S, P1;
    S = Chinhphuong(EXP1);
    //Road1
    if (EXP1 >= S) {
        P1 = 100;
    }
    else {
        P1 = (((float(EXP1)/S + 80)/123)*100) + 0.999;
    }
    //Road2
    int UsedMoney = 0, initialMoney = M1;
    if(E2%2==1){
        while (float(UsedMoney) <= (0.5*float(initialMoney))){
           //Đi ăn uống
            if (HP1 < 200) {
                HP1 = (HP1 + float(HP1)*0.3)+0.999; CheckHP(HP1); 
                M1 -= 150; CheckM(M1); 
                UsedMoney += 150;
            } else if(HP1 >= 200) {
                HP1 =  (HP1 + float(HP1)*0.1)+0.999; CheckHP(HP1); 
                M1 -= 70; CheckM(M1);
                UsedMoney += 70;
            }
            //Sau khi hoàn thành sự kiện, check điều kiện
            if(float(UsedMoney) > (0.5*float(initialMoney))) break; 
            //Đi taxi hay ngựa
            if (EXP1 < 400) {
                M1 -= 200; CheckM(M1); 
                UsedMoney+=200;
            }
            else if(EXP1 >= 400) {
                M1 -= 120; CheckM(M1);
                UsedMoney+=120;
            }
            EXP1 = (EXP1 + float(EXP1)*0.13)+0.999; CheckHP(EXP1);
            //Sau khi hoàn thành sự kiện, check điều kiện
            if(float(UsedMoney) > (0.5*float(initialMoney))) break; 
            //Gặp người vô gia cư
            if(EXP1 < 300) {
                M1-=100; CheckM(M1); 
                UsedMoney+=100;
                }
            else if(EXP1 >= 300) {
                M1-=120; CheckM(M1);
                UsedMoney+=120; 
            }
            EXP1 = (EXP1 - float(EXP1)*0.1)+0.999; CheckEXP(EXP1);
            //Sau khi hoàn thành sự kiện, check điều kiện
            if(float(UsedMoney) > (0.5*float(initialMoney))) break;
        } 
        HP1 = (HP1 - 0.17*float(HP1)+0.999); CheckHP(HP1);
        EXP1 = (EXP1 + float(EXP1)*0.17)+0.999; CheckEXP(EXP1);
    }
    if(E2%2==0){
        for(int i=0; i<=1; i++){ //E2 chẵn nên thực hiện 1 lượt
              //Đi ăn uống
            if (HP1 < 200) {
                HP1 = (HP1 +float(HP1)*0.3) + 0.999; CheckHP(HP1); 
                M1 -= 150; CheckM(M1); 
                UsedMoney += 150;
            } else if(HP1 >= 200) {
                HP1 =  (HP1 + float(HP1)*0.1) + 0.999; CheckHP(HP1); 
                M1 -= 70; CheckM(M1);
                UsedMoney += 70;
            }
            //Sau khi hoàn thành sự kiện, check điều kiện
            if(M1==0) break; 
            //Đi taxi hay ngựa
            if (EXP1 < 400) {
                M1 -= 200; CheckM(M1); 
                UsedMoney+=200;
            }
            else if(EXP1 >= 400) {
                M1 -= 120; CheckM(M1);
                UsedMoney+=120;
            }
            EXP1 = (EXP1 + float(EXP1)*0.13) + 0.999; CheckHP(EXP1);
            //Sau khi hoàn thành sự kiện, check điều kiện
            if(M1==0) break; 
            //Gặp người vô gia cư
            if(EXP1 < 300) {
                M1-=100; CheckM(M1); 
                UsedMoney+=100;
                }
            else if(EXP1 >= 300) {
                M1-=120; CheckM(M1);
                UsedMoney+=120; 
                }
            EXP1 = (EXP1 - float(EXP1)*0.1) + 0.999; CheckEXP(EXP1);
            //Sau khi hoàn thành sự kiện, check điều kiện
            if( M1==0) break;
            i++;
        } 
        HP1 = (HP1 - 0.17*float(HP1)) + 0.999; CheckHP(HP1);
        EXP1 = (EXP1 + 0.17*float(EXP1)) + 0.999; CheckEXP(EXP1);
    }
    int S2=Chinhphuong(EXP1);
    double P2;
    if (EXP1 >= S2) {P2 = 100;}
        else {
            P2 =(((float(EXP1)/S2 + 80)/123)*100) + 0.999;
        }
    //Road3
    int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3;

    if(E2>=0 && E2<10) {
        P3 = P[E2]; 
    }
    else if (E2>=10 && E2<=99) { 
        E2 = E2 % 10 + E2 / 10;
        E2 = E2 % 10;
        }
        P3= P[E2];
    //Sau đi cả ba tuyến đường
    int p = (float(P1+P2+P3)/3) + 0.999;
    if (P1==100 && P2==100 && P3==100) {
        EXP1 = (EXP1 - float(EXP1)*0.25)+0.999; CheckEXP(EXP1);
    }  
    if(p < 50) {
        HP1 = (HP1 - float(HP1)*0.15) + 0.999; CheckHP(HP1);
        EXP1 = (EXP1 + float(EXP1)*0.15) +0.999; CheckEXP(EXP1);
    } 
    else if (p >= 50 && p < 100){
        HP1 = (HP1 - float(HP1)*0.10) + 0.999; CheckHP(HP1);
        EXP1 = (EXP1 + float(EXP1)*0.20) + 0.999; CheckEXP(EXP1);
    }
    return HP1 + EXP1 + M1;
}
// Task 3
int sumOfTwoNumber(int num) {
    int a=0;
    a=a+num/10+num%10;
    int b=0;
    b=b+a/10+a%10;
    return b;
}
int maxOfGrade (int &x, int &y,int arr[10][10]){
    int num=arr[x][y]; //vị trí gặp nhau
     int i1,j1;
    //lên chéo phải
    i1=x+1; j1=y-1;
    while(i1>=0 && i1<=9 && j1>=0 && j1<=9){
        num = max(num, arr[i1][j1]);
        i1++; j1--;
    }
    //lên chéo trái

    i1=x-1; j1=y-1;
    while( j1>=0 && j1<=9 && i1>=0 && i1<=9){
       num = max(num, arr[i1][j1]);
        i1--; j1--;
    }
    //xuống chéo phải
    i1=x+1; j1=y+1;
    while(i1>=0 && i1<10 && j1>=0 && j1<10){
        num = max(num, arr[i1][j1]);
        i1++; j1++;
    }
    //Xuống chéo trái
    i1=x-1; j1=y+1;
    while(i1>0 && j1>0 && i1<10 && j1<10){
        num = max(num, arr[i1][j1]);
        i1--; j1++;
    }
    return num;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3<0 || E3>99) {return -99;} // khi e2 vượt giới hạn
    int arr[10][10];
    int i,j;
    for(i=0; i<10; i++){
        for (j=0; j<10; j++){
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);     //Cập nhật điểm tại các vị trí taxi đi qua
        }
    }
    int PositiveNum=0, NegativeNum=0, x,y, taxiScore, sherlockScore;

    for (int i=0;i<10;i++){
            for (j=0; j<10; j++){
    if (arr[i][j] > 0 && arr[i][j] > (E3*2)) {
        PositiveNum++;
    }if (arr[i][j] < 0 && arr[i][j] < (E3 * (-1))) {
        NegativeNum++;
        }
        }
    }
    x = sumOfTwoNumber(PositiveNum);
    y = sumOfTwoNumber(NegativeNum);
    taxiScore = arr[x][y];
    sherlockScore = maxOfGrade(x,y,arr);
    if(abs(taxiScore) > abs(sherlockScore)){
        EXP1 =ceil(EXP1-0.12*EXP1*1.0);
        HP1 =ceil(HP1-0.1*HP1*1.0);
        EXP2 =ceil(EXP2-0.12*EXP2*1.0);
        HP2 =ceil(HP2-0.1*HP2*1.0);
        CheckEXP(EXP1);
        CheckEXP(EXP2);
        CheckHP(HP1);
        CheckHP(HP2);
        return taxiScore;
    }else {
        EXP1 =ceil(EXP1+0.12*1.0*EXP1);
        HP1 =ceil(HP1+0.1*1.0*HP1);
        EXP2 =ceil(EXP2+0.12*1.0*EXP2);
        HP2 =ceil(HP2+0.1*1.0*HP2);
        CheckEXP(EXP1);
        CheckEXP(EXP2);
        CheckHP(HP1);
        CheckHP(HP2);
        return abs(sherlockScore);
        }

}

// Task 4
int CheckRepeat(string s1, string se1) {
    if (se1.length() > s1.length()) return -1;
    
    for (int i = 0; i <= int(s1.length()); i++) {
        bool CheckRepeatOK = true;
        for (int j = 0; j < int(se1.length()); j++) {
            if (s1[i + j] != se1[j]) {
                CheckRepeatOK = false;
                break;
            }
        }
        if (CheckRepeatOK) {
            return i;
        }
    }
    return -1; 
}


int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string email1; email1 = string(email);
    string se1, s1; s1 = string(s); 
   
    if (email1.length()>100) {return -99;}
    for (int i=0; i < int(email1.length()); i++) {
        if ((email1)[i] == '@') {
            se1 += email1[i];
        } 
    }
    // Kiểm tra độ dài của mật khẩu
    if (int(s1.length()) < 8) { return -1;}
    if (int(s1.length()) > 20) {return -2;}
    //Kiểm tra se có nằm trong s không
    int r = CheckRepeat(s1,se1);
    if(r!=-1) return -300-r;
    //kiểm tra 2 ký tự liên tiếp giống nhau
    for(int i=0;i<int(s1.length())-2;i++){
        if(s1[i] == s1[i+1] && s1[i+1] == s1[i+2]){
            return -(400+i);
        }
    }
    
    bool hasSpecialChar = false;
    for(int i=0; i< int(s1.size()); i++){
        if (s1[i] == '@' || s1[i] == '#' || s1[i] == '%' || s1[i] == '$' || s1[i] == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if(!hasSpecialChar) return -5; //TH: Không có ký hiệu đặc biệt nào
    else{
        for(int i=0; i < int(s1.size()); i++){ //nếu chứa các ký tự không cho phép, check tăng lên 1 và trả về vị trí kí tự không hợp lệ đó
            if((s1[i]) >'a' && (s1[i])<'z') continue;
            if(s1[i] >'A' && s1[i] <'Z') continue;
            if(s1[i] == '@' || s1[i]=='#' || s1[i]=='%' || s1[i]=='$' || s1[i]=='!') continue;
            else 
                return i;
        }
    }
    return -10; //Mật khẩu hợp lý
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int CorrectLocation = -1, MaxAppear = 0, MaxLength = 0;
    for (int i = 0; i < num_pwds; i++) {
        int appear = 0;
        int length = strlen(arr_pwds[i]); // tính độ dài chuỗi tại vị trí i
        
        for (int j = 0; j < num_pwds; j++) {
            if (i != j && strcmp(arr_pwds[i], arr_pwds[j]) == 0)
                appear++;
        }
            //Điều kiện
            if ((appear > MaxAppear) || (appear == MaxAppear && length > MaxLength)) {
                    MaxAppear = appear;
                    MaxLength = length;
                    CorrectLocation = i;
            }
    }
    return CorrectLocation;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////

