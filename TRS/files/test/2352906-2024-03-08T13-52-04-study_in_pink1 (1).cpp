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

// All made by Nguyen Huu Nam Phong
// Student ID: 2352906
// Email: phong.nguyenhuunam@hcmut.edu.vn
// Github: https://github.com/Windyy-1007

//Task 0: Data checking after doing ANY calculation that changes value
int expCheck(int a){
    if (a>600){
        return 600;
    }
    else if (a<0){
        return 0;
    }
    else {
        return a;
    }
}

int hpCheck(int a){
    if (a>666){
        return 666;
    }
    else if (a<0){
        return 0;
    }
    else {
        return a;
    }
}

int mCheck(int a){
    if (a>3000){
        return 3000;
    }
    else if (a<0){
        return 0;
    }
    else {
        return a;
    }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1 < 0 || e1 > 99){
        return -99;
    }
    exp1 = expCheck(exp1);
    exp2 = expCheck(exp2);
    //Case 1
    if( 0 <= e1 && 3 >= e1) {
        //Part 1: exp2 changes
        switch(e1){
            case 0:
                exp2 = 0.999999 + (exp2 + 29);
                exp2 = expCheck(exp2);
                break;
            case 1:
                exp2 = 0.999999 + (exp2 + 45);
                exp2 = expCheck(exp2);
                break;
            case 2:
                exp2 = 0.999999 + (exp2 + 75);
                exp2 = expCheck(exp2);
                break;
            case 3:
                exp2 = 0.999999 + (exp2 + 29 + 45 + 75);
                exp2 = expCheck(exp2);
                break;
            default:
                break;
        }
    
        //Part 2: exp1 changes
        int d=round(e1*3 + exp1*7);
        if(d%2 ==0){
        exp1 = 0.999999 + (exp1 + (float)d/200);
        exp1 = expCheck(exp1);
        }
        else{
        exp1 = 0.999999 + (exp1 - (float)d/100);
        exp1 = expCheck(exp1);
        }
    }

    //Case 2
    if(4 <= e1 && 99 >= e1){
        if(4<= e1 && 19 >= e1){
            exp2 = 0.999999 + (exp2 + (float)e1/4 + 19);
            exp2 = expCheck(exp2);
        }
        if(20<= e1 && 49 >= e1){
            exp2 = 0.999999 + (exp2 + (float)e1/9 + 21);
            exp2 = expCheck(exp2);
        }
        if(50<= e1 && 65 >= e1){
            exp2 = 0.999999 + (exp2 + (float)e1/16 + 17);
            exp2 = expCheck(exp2);
        }
        if(66<= e1 && 79 >= e1){
            exp2 = 0.999999 + (exp2 + (float)e1/4 + 19);
            exp2 = expCheck(exp2);
            if(exp2 > 200){
                exp2 = 0.999999 + (exp2 + (float)e1/9 + 21);
                exp2 = expCheck(exp2);
            }
        }
        if(80<= e1 && 99 >= e1){
            exp2 = 0.999999 + (exp2 + (float)e1/4 + 19);
            exp2 = expCheck(exp2);
            exp2 = 0.999999 + (exp2 + (float)e1/9 + 21);
            exp2 = expCheck(exp2);
            if(exp2 > 400){
                exp2 = 0.999999 + (exp2 + (float)e1/16 + 17);
                exp2 = expCheck(exp2);
                exp2 = 0.999999 + (1.15*exp2);
                exp2 = expCheck(exp2);
            }
        }
        exp1 = 0.999999 + (exp1 - e1);
        exp1 = expCheck(exp1);
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) { 
    if(E2 < 0 || E2 > 99){
        return -99;
    }
    HP1 = hpCheck(HP1);
    EXP1 = expCheck(EXP1);
    M1 = mCheck(M1);
    //Road 1
    float p1=0;
        //Find closest S to EXP1:
        int s = round(sqrt(EXP1));
        s = s*s;
        //Check case:
        if(EXP1 >= s){
            p1 = 1;
        } else {
            p1 = ((float)EXP1/s + 80)/123;
        }
    //Road 2
    float p2=0;
        //Journey:
    int intial_M1 = M1;
    do{
        //Event 1:
    if(M1>0){
        if(HP1 < 200){
            HP1 = 0.999999 + (1.3 * HP1);
            HP1 = hpCheck(HP1);
            M1 = 0.999999 + (M1 - 150);
            M1 = mCheck(M1);
        } else {
            HP1 = 0.999999 + (1.1*HP1);
            HP1 = hpCheck(HP1);
            M1 = 0.999999 + (M1 - 70);
            M1 = mCheck(M1);
        }
    }
    if((M1 < 0.5*intial_M1 && (E2 %2)==1) || M1 == 0){break;} 
        //Event 2:
    if(M1>0){
        if(EXP1 < 400){
            M1 = 0.999999 + (M1 -200);
            M1 = mCheck(M1);
        } else {
            M1 = 0.999999 + (M1 - 120);
            M1 = mCheck(M1);
        }
        EXP1 = 0.999999 + (1.13*EXP1);
        EXP1 = expCheck(EXP1);
    }
    if((M1 < 0.5*intial_M1 && (E2 %2)==1) || M1 == 0){break;}    
        //Event 3:
    if(M1>0){
        if(EXP1 < 300){
            M1 = M1 -100;
            M1 = mCheck(M1);
        } else {
            M1 = M1 -120;
            M1 = mCheck(M1);
        }
        EXP1 = 0.999999 + (0.9*EXP1);
        EXP1 = expCheck(EXP1);
    }
    if((M1 < 0.5*intial_M1 && (E2 %2)==1) || M1 == 0){break;} 
    } while((E2 %2)==1);
        //Let's walk:
        HP1 = 0.999999 + (0.83*HP1);
        HP1 = hpCheck(HP1);
        EXP1 = 0.999999 + (1.17*EXP1);
        EXP1 = expCheck(EXP1);

        //Giải thích thuật toán Road 2:
        //Loop lần 1: chạy như bình thường. nếu M1 < 0.5*intial_M1 và E2 là số lẻ thì break khỏi loop.
        //Loop lần 2 tới n: chỉ chạy khi E2 là số lẻ. nếu M1 < 0.5*intial_M1 và E2 là số lẻ thì break khỏi loop.
        //Nếu E2 là số chẵn thì không chạy loop lần 2 tới n. Khi M=0 thì không chạy các event sau đó.
        //Walk sẽ được kích hoạt khi M1=0 (case E2 chẵn hết tiền) hoặc E2 là số lẻ.

        //Find P:
        s = round(sqrt(EXP1));
        s = s*s;
        if(EXP1 >= s){
            p2 = 1;
        } else {
            p2 = ((float)EXP1/s + 80)/123;
        }
    //Road 3:
        int intial_p3[10] = {32,47,28,79,100,50,22,83,64,11};
        float p3=0;
        int i=0;
        if(E2 < 10){
            p3 = (float)intial_p3[E2]/100;
        } else {
            i=E2%10 + E2/10;
            if(i>9){
                i=i%10;
            }
            p3 = (float)intial_p3[i]/100;
        }
    //Epilogue:
    float P = (p1 + p2 + p3)/3;
    if (P==1){
        EXP1 = 0.999999 + (0.75*EXP1);
        EXP1 = expCheck(EXP1);
    } else if(P<0.5){
        HP1 = 0.999999 + (0.85*HP1);
        HP1 = hpCheck(HP1);
        EXP1 = 0.999999 + (1.15*EXP1);
        EXP1 = expCheck(EXP1);
    } else {
        HP1 = 0.999999 + (0.9*HP1);
        HP1 = hpCheck(HP1);
        EXP1 = 0.999999 + (1.2*EXP1);
        EXP1 = expCheck(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3 < 0 || E3 > 99){
        return -99;
    }
    HP1 = hpCheck(HP1);
    EXP1 = expCheck(EXP1);
    HP2 = hpCheck(HP2);
    EXP2 = expCheck(EXP2);
    int a[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            a[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }
    int b[10][10];
    int max = 0;
    //Giải thích thuật toán:
    //Tại điểm X bất kì, scan dọc theo đường chéo theo 4 hướng: ++, +-, -+, -- 
    //cho đến khi 1 trong 2 giá trị x,y chạm 0 hoặc 9.
    //Khi đó, trở về tọa độ i, j và scan theo hướng kế tiếp.
    //Biến max sẽ dùng để lưu giá trị lớn nhất tìm được.

    //Biết điểm gặp nhau là được. Đi đâu cũng phải đi hết :))
    int x;
    int y;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            max = a[i][j];
            x=i;
            y=j;
            //Scan theo hướng ++
            while(x >=0 && x <= 9 && y>=0 && y<=9){
                if (a[x][y] > max){
                    max = a[x][y];
                }
                x++;
                y++;
            }
            x=i;
            y=j;
            //Scan theo hướng --
            while(x >=0 && x <= 9 && y>=0 && y<=9){
                if (a[x][y] > max){
                    max = a[x][y];
                }
                x--;
                y--;
            }
            x=i;
            y=j;
            //Scan theo hướng +-
            while(x >=0 && x <= 9 && y>=0 && y<=9){
                if (a[x][y] > max){
                    max = a[x][y];
                }
                x++;
                y--;
            }
            x=i;
            y=j;
            //Scan theo hướng -+
            while(x >=0 && x <= 9 && y>=0 && y<=9){
                if (a[x][y] > max){
                    max = a[x][y];
                }
                x--;
                y++;
            }
            b[i][j] = abs(max);
        }
    }
    //Tìm điểm gặp nhau x,y:
    x=0;
    y=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(a[i][j] > E3*2){
                x++;
            } 
            if(a[i][j] < -E3){
                y++;
            }
        }
    }

    while(x>9){
        x = x/10 + x%10;
    }

    while(y>9){
        y = y/10 + y%10;
    }

    //Kiểm tra vị trí gặp nhau:
    int winner = 0;
    int loser = 0; //Biến phục vụ testing
    if(abs(a[x][y]) > b[x][y]){
        //Thua
        EXP1 = 0.999999 + (0.88*EXP1);
        EXP1 = expCheck(EXP1);
        HP1 = 0.999999 + (0.9*HP1);
        HP1 = hpCheck(HP1);
        EXP2 = 0.999999 + (0.88*EXP2);
        EXP2 = expCheck(EXP2);
        HP2 = 0.999999 + (0.9*HP2);
        HP2 = hpCheck(HP2);
        winner = a[x][y];
        loser = b[x][y];

    } else {
        //Thắng, thay vì trừ thì cộng
        EXP1 = 0.999999 + (1.12*EXP1);
        EXP1 = expCheck(EXP1);
        HP1 = 0.999999 + (1.1*HP1);
        HP1 = hpCheck(HP1);
        EXP2 = 0.999999 + (1.12*EXP2);
        EXP2 = expCheck(EXP2);
        HP2 = 0.999999 + (1.1*HP2);
        HP2 = hpCheck(HP2);
        winner = b[x][y];
        loser = a[x][y];
    }
    return winner;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    //kiểu const char* cơ bản khóa hết mọi tính năng của string, nên cần chuyển qua string để xử lý =)))
    string pass = s;
    string fix_mail = email;
    //cắt chuỗi se từ email
    string se;
    for(int i=0; i<fix_mail.length(); i++){
        if(fix_mail[i] == '@'){
            se = fix_mail.substr(0, i);
        break;
        }
    }
    //kiểm tra chuỗi
        //kiểm tra độ dài (8-20):
        if(pass.length() < 8){
            return -1;
        }
        if(pass.length() > 20){
            return -2;
        }
        //kiểm tra xem mật khẩu có chưa se không:
        if(pass.find(se) != string::npos){
            return -(300+pass.find(se));
        }
        //kiểm tra xem mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp không:
        for(int i=2; i<pass.length(); i++){
            if(pass[i] == pass[i-1] && pass[i] == pass[i-2]){
                return -(400+(i-2));
            }
        }
        //kiểm tra xem mật khẩu có chứa ký tự đặc biệt không:
        if(pass.find_first_of("@#%$!") == string::npos){
            //Có thể thay bằng việc thêm biến count và tăng count lên 1 mỗi khi tìm thấy ký tự đặc biệt.
            return -5;
        }
        //kiểm tra xem mật khẩu có chứa ký tự lạ không:
        for(int i=0; i<pass.length(); i++){
            if(pass[i] != 33 && pass[i] != 35 && pass[i] != 36 && pass[i] != 37 && pass[i] != 64 && !(pass[i] >= 48 && pass[i] <= 57) && !(pass[i] >= 65 && pass[i] <= 90) && !(pass[i] >= 97 && pass[i] <= 122)){
                return i;
            }
        }
    //đã pass toàn bộ kiểm tra
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    //như task 4, chuyển const char* qua string
    string pass[num_pwds];
    for(int i=0; i<num_pwds; i++){
        pass[i] = arr_pwds[i];
    }
    //Giải thích thuật toán:
    //Đặt biến max và tie-break có giá trị khởi đầu = 0.
    //Duyệt qua từng chuỗi trong mảng, tại mỗi chuỗi, lại duyệt qua từng chuỗi thêm một lần nữa.
    //Tại mỗi lần duyệt (loop trong), đếm số chuỗi trùng với chuỗi hiện tại. Nếu nó lớn hơn max thì gán max = số chuỗi trùng. ==> Chuỗi pass mới
    //Đồng thời, gán tie-break = x (lenght của chuỗi trùng).
    //Nếu số chuỗi trùng bằng max thì so sánh lenght của chuỗi trùng với tie-break. Nếu nó lớn hơn thì gán tie-break = lenght của chuỗi trùng. ==> Chuỗi pass mới

    int max = 0;
    int tie_break = 0;
    int result = 0;
    int count = 0;
    for(int i=0; i<num_pwds; i++){
        count = 0;
        for(int j=0; j<num_pwds; j++){
            if(pass[i] == pass[j]){
                count++;
            }
        }
        if(count > max){
            max = count;
            tie_break = pass[i].length();
            result = i;
        }
        if(count == max){
            if(pass[i].length() > tie_break){
                tie_break = pass[i].length();
                result = i;
            }
        }
    }

    //Đề yêu cầu tìm vị trí đầu tiên, nên chỉ cần find lại giá trị đầu tiên trong array pass trùng với pass[result] là được.
    for(int i=0; i<num_pwds; i++){
        if(pass[i] == pass[result]){
            return i;
        }
    }

    return -99;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////