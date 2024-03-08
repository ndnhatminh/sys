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
/// STUDENT'S ANSWER BEGINS HERE - TRAN ANH KHOA
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

// Task 1
int Check_EXP(int &exp1, int &exp2){
        if(exp1 < 0){exp1 = 0;} else if(exp1 > 600){exp1 = 600;}
        if(exp2 < 0){exp2 = 0;} else if(exp2 > 600){exp2 = 600;}
        return 0;}

int firstMeet(int & exp1, int & exp2, int e1) {
    int D; 
    if (e1< 0 || e1 > 99){return -99;} else{
        Check_EXP(exp1, exp2);
        if (e1 == 0 || e1 == 1 || e1 == 2 || e1 == 3){      // TH1
            switch (e1){
            case 0:
                exp2 += 29;
                Check_EXP(exp1, exp2);
                break;
            case 1:
                exp2 += 45;
                Check_EXP(exp1, exp2);
                break;
            case 2:
                exp2 += 75;
                Check_EXP(exp1, exp2);
                break;
            case 3:
                exp2 = exp2 + 29 + 45 + 75;
                Check_EXP(exp1, exp2);
                break;
            }
            D = e1*3 + exp1*7;
            if (D%2==0){
                exp1 += D/200;
                if(D % 200 != 0){exp1 += 1;}
                Check_EXP(exp1, exp2);
            } else{
                exp1 -= D/100;
                Check_EXP(exp1, exp2);}
        } else if(4 <= e1 && e1 <= 99){               // TH2
            if(4 <= e1 && e1 <= 19){
                exp2 += (e1/4 + 19);
                if(e1%4 != 0){exp2 += 1;}
                Check_EXP(exp1, exp2);
            }

            else if(20 <= e1 && e1 <= 49){
                exp2 += (e1/9 + 21);
                if(e1%9 != 0){exp2 += 1;}
                Check_EXP(exp1, exp2);
                }

            else if(50 <= e1 && e1 <= 65){
                exp2 += (e1/16 + 17);
                if(e1%16 != 0){exp2 += 1;}
                Check_EXP(exp1, exp2);
                }

            else if(66 <= e1 && e1 <= 79){
                exp2 += (e1/4 + 19);
                if(e1%4 != 0){exp2 += 1;}
                Check_EXP(exp1, exp2);
                if (exp2 > 200){exp2 += (e1/9 + 21);if(e1%9 != 0){exp2 += 1;}; Check_EXP(exp1, exp2);}
                }
            else if(80 <= e1 && e1 <= 99){
                exp2 += (e1/4 + 19);
                if(e1%4 != 0){exp2 += 1;}
                Check_EXP(exp1, exp2);
                exp2 += (e1/9 + 21);
                if(e1%9 != 0){exp2 += 1;}
                Check_EXP(exp1, exp2);
                if (exp2 > 400){
                    exp2 += (e1/16 + 17);
                    if(e1%16 != 0){exp2 += 1;}
                    Check_EXP(exp1, exp2);
                    if(exp2%100 != 0){exp2 = exp2*1.15 + 1;} else{exp2 = exp2*1.15;}
                    Check_EXP(exp1, exp2);
                    } else {}
            }
            exp1 -= e1;
            Check_EXP(exp1, exp2);
        } 
        return exp1 + exp2; 
    }
}

// Task 2
int Check_EXP1(int &exp1){
        if(exp1 < 0){exp1 = 0;} else if(exp1 > 600){exp1 = 600;}
        return exp1;}

int Check_HP1(int &HP1){
        if(HP1 < 0){HP1 = 0;} else if(HP1 > 666){HP1 = 666;}
        return HP1;}

int Check_M1(int &M1){
        if(M1 < 0){M1 = 0;} else if(M1 > 3000){M1 = 3000;}
        return M1;}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if(E2<0 || E2>99){return -99;} else {
        Check_HP1(HP1); Check_EXP1(EXP1); Check_M1(M1);
        int S1,S2;
        bool stat = true;
        float P1, P2, P3;
        int ChinhPhuong[25];
        int M1_begin = M1;
        int M1_used;
        int M1_half; 
        if(M1_begin % 2 == 0){M1_half = M1_begin /2;} else{M1_half = M1_begin/2 + 0.5;}

        for (int i = 0; i <25; i++){                                                                // Tạo array số cphuong
            ChinhPhuong[i] = i*i;}
        int ABS1 = abs(ChinhPhuong[0] - EXP1);
        for (int j = 1; j < 25; j++){                                                               //Tìm S2
            if(abs(ChinhPhuong[j]-EXP1) < ABS1){S1 =ChinhPhuong[j]; ABS1 = abs(ChinhPhuong[j]-EXP1);}
        }
        if (EXP1 >= S1){P1=1;}else{P1 = (float)((EXP1/S1)+80)/123;} //P1
        
        if (E2%2 != 0){
            while (1){                
                if (1){
                    if(HP1<200){HP1 = HP1 + 0.3*HP1 + 0.9999;Check_HP1(HP1); M1-=150;Check_M1(M1);} else{HP1 = HP1 + 0.1*HP1 + 0.9999;Check_HP1(HP1); M1-=70;Check_M1(M1);}
                    M1_used = M1_begin - M1;
                    if (M1_used > M1_half){break;}

                    if (1){
                        if(EXP1<400){M1-=200;Check_M1(M1); EXP1 = EXP1 + 0.13*EXP1 + 0.9999;Check_EXP1(EXP1);} else{M1-=120;Check_M1(M1); EXP1 = EXP1 + 0.13*EXP1 + 0.9999;Check_EXP1(EXP1);}
                        M1_used = M1_begin - M1;
                        if (M1_used > M1_half){break;}

                        if(1){
                            if(EXP1<300){M1-=100;Check_M1(M1); EXP1 = EXP1 - 0.1*EXP1 + 0.9999;Check_EXP1(EXP1);} else {M1-=120;Check_M1(M1); EXP1 = EXP1 - 0.1*EXP1 + 0.9999;Check_EXP1(EXP1);}
                            M1_used = M1_begin - M1;
                            if (M1_used > M1_half){break;}}
                    }
                }
            }     
            HP1 = HP1 - 0.17*HP1 + 0.9999; EXP1 = EXP1 + 0.17*EXP1 + 0.9999; Check_HP1(HP1); Check_EXP1(EXP1);
        } 
        else {
            if (M1 != 0){
                if(HP1<200){HP1 = HP1 + 0.3*HP1 + 0.9999;Check_HP1(HP1); M1-=150;Check_M1(M1);} else{HP1 = HP1 + 0.1*HP1 + 0.9999;Check_HP1(HP1); M1-=70;Check_M1(M1);}
                if(M1 !=0){
                    if(EXP1<400){M1-=200;Check_M1(M1); EXP1 = EXP1 + 0.13*EXP1 + 0.9999;Check_EXP1(EXP1);} else{M1-=120;Check_M1(M1); EXP1 = EXP1 + 0.13*EXP1 + 0.9999;Check_EXP1(EXP1);}
                    if (M1 !=0){
                        if(EXP1<300){M1-=100;Check_M1(M1); EXP1 = 0.9*EXP1 + 0.9999;Check_EXP1(EXP1);} else {M1-=120;Check_M1(M1); EXP1 = 0.9*EXP1 + 0.9999;Check_EXP1(EXP1);}
                    }
                }
            }
            HP1 = HP1 - 0.17*HP1 + 0.9999; EXP1 = EXP1 + 0.17*EXP1 + 0.9999; Check_HP1(HP1); Check_EXP1(EXP1);
        }

        int ABS2 = abs(ChinhPhuong[0] - EXP1);
        for (int m = 1; m < 25; m++){                                                               //Tìm S2
            if(abs(ChinhPhuong[m]-EXP1) < ABS2){S2 =ChinhPhuong[m]; ABS2 = abs(ChinhPhuong[m]-EXP1);}
        }
        if (EXP1 >= S2){P2=1;}else{P2 = (float)((EXP1/S2)+80)/123;}             // P2
        
        int array[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        if(E2%10 == E2){P3 =(float)array[E2%10]/100;} else {P3 = (float)array[((E2 - E2%10) /10 + (E2%10)) % 10]/100 ;} // P3

        if (P1 == 1 && P2 == 1 && P3 == 1){EXP1 = EXP1*0.75 + 0.9999; Check_EXP1(EXP1);}
        else {
            if ( (P1 + P2 + P3)/3 < 0.5 ){HP1 = HP1*0.85 + 0.9999; EXP1 = EXP1*1.15 + 0.9999; Check_EXP1(EXP1); Check_HP1(HP1);}
            else {HP1 = HP1*0.9 + 0.9999; EXP1 = EXP1*1.2 + 0.9999; Check_EXP1(EXP1); Check_HP1(HP1);}
        }
        return HP1 + EXP1 + M1;
    }
}

// Task 3
int Check_HP(int &HP1, int &HP2){
        if(HP1 < 0){HP1 = 0;} else if(HP1 > 666){HP1 = 666;}
        if(HP2 < 0){HP2 = 0;} else if(HP2 > 666){HP2 = 666;}
        return 0;}

int Check_Max(int Taxi[][10], int E3){
    int max = E3*2;
    int countMax =0;
    for(int a1 =0; a1 < 10; a1++){
        for(int a2=0; a2 <10; a2++){
            if(Taxi[a1][a2] >= 0){
                if(Taxi[a1][a2] > max){countMax +=1;}}}}

    int i, temp;
    temp = countMax%10 + (countMax - countMax%10)/10;
    i = temp%10 + (temp - temp%10)/10;  // nếu là số 2 chữ số thì sau bước này sẽ thành 1 chữ số, nếu là số 1 chữ số thì ko thay đổi
    return i;}

int Check_Min(int Taxi[][10], int E3){
    int min = -E3;
    int countMin =0;
    for(int a1 =0; a1 < 10; a1++){
        for(int a2=0; a2 <10; a2++){
            if(Taxi[a1][a2] < 0){
                if(Taxi[a1][a2] < min){countMin +=1;}}}}

    int j, temp;
    temp = countMin%10 + (countMin - countMin%10)/10;
    j = temp%10 + (temp - temp%10)/10;
    return j;}

int Check_Diagonal(int Taxi[][10], int x, int y){
    int Sherlock[10][10];

    int LeftBegin_i, LeftBegin_j, RightBegin_i, RightBegin_j;

    for(int a1 =0; a1 < 10; a1++){for(int a2=0; a2 < 10; a2++){Sherlock[a1][a2] = 0;}}

    for(int i=0; i < 10; i++){                                         // Tạo matrix điểm Sherlock
        for(int j=0; j < 10; j++){
            if(i < j){
                LeftBegin_i =0; LeftBegin_j= j-i;
                if(i + j >= 9){RightBegin_i = i - (9-j); RightBegin_j = 9;}
                else{RightBegin_i =0; RightBegin_j = i + j;}
            } else if (i > j){
                LeftBegin_i = i-j; LeftBegin_j = 0;
                if(i + j >= 9){RightBegin_i = i - (9-j); RightBegin_j = 9;}
                else{RightBegin_i = 0; RightBegin_j = i+j;}
            } else{
                LeftBegin_i =0; LeftBegin_j =0;
                if(i ==0 || i ==9){RightBegin_i=i; RightBegin_j=j;}
                else if (0<i && i<5){RightBegin_i=0; RightBegin_j=2*i;}
                else if (5<i && i<10){RightBegin_i=2*i - 9; RightBegin_j=9;}}           // Tìm điểm bắt đầu của 2 đường chéo tại mỗi điểm trong ma trận

                                                                           
            int max_left = Taxi[LeftBegin_i][LeftBegin_j];
            int max_right = Taxi[RightBegin_i][RightBegin_j];
            
            while(1){                                                     //Left Diagonal
                if(LeftBegin_i <= 9 && LeftBegin_j <= 9){
                    if (max_left <= Taxi[LeftBegin_i][LeftBegin_j]){max_left = Taxi[LeftBegin_i][LeftBegin_j];}
                    LeftBegin_i +=1; LeftBegin_j +=1;
                } else {break;}
            }
                                                             
            while(1){                                                   //Right Diagonal
                if(RightBegin_i <= 9 && RightBegin_j >= 0){
                    if (max_right <= Taxi[RightBegin_i][RightBegin_j]){max_right = Taxi[RightBegin_i][RightBegin_j];}
                    RightBegin_i +=1; RightBegin_j -=1;
                } else {break;}
            }

            Sherlock[i][j] = max(max_left, max_right);
        }
    }

    return Sherlock[x][y];
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3<0 || E3 >99){return -99;}
    else{
        int Taxi[10][10];
        for(int a1 =0; a1 < 10; a1++){for(int a2=0; a2 < 10; a2++){Taxi[a1][a2] = 0;}} // khởi tạo mảng 10x10 giá trị 0
        for(int b1=0; b1 < 10; b1++){for(int b2=0; b2 < 10; b2++){Taxi[b1][b2]= ((E3*b2) + (b1*2)) * (b1-b2);}} // gán giá trị cho mảng

        int i = Check_Max(Taxi, E3);
        int j = Check_Min(Taxi, E3);

        int Sherlock_Score = Check_Diagonal(Taxi, i, j);
        int Taxi_Score = Taxi[i][j];
        if(abs(Taxi_Score) <= Sherlock_Score){EXP1 = EXP1*1.12 + 0.9999;
                                            EXP2 = EXP2*1.12 + 0.9999; 
                                            HP1 = HP1*1.10 + 0.9999; 
                                            HP2 = HP2*1.10 + 0.9999;
                                            Check_EXP(EXP1, EXP2); Check_HP(HP1, HP2);
                                            return Sherlock_Score;}
        else{EXP1 = EXP1*0.88 + 0.9999;
            EXP2 = EXP2*0.88 + 0.9999; 
            HP1 = HP1*0.90 + 0.9999; 
            HP2 = HP2*0.90 + 0.9999;
            Check_EXP(EXP1, EXP2); Check_HP(HP1, HP2);
            return Taxi_Score;}
    }
}

// Task 4
int find_se(const string & email){
    int i;
    for (i =0; i<email.length(); i++){
        if(email[i] == '@'){break;}
    }
    return i;
}
int check_Char(const string &s){
    int SpecialChar=0, UnvalidChar=0;

    for(int i =0; i < s.length(); i++){
        if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z') && !(s[i] >= '0' && s[i] <= '9')){
            if(s[i] == '!' || s[i] == '@' || s[i] =='#' || s[i] == '$' || s[i] =='%'){SpecialChar = 1;}
            else{UnvalidChar=1;}
        }
    }

    if(SpecialChar == 0){return -5;}
    else if (SpecialChar ==1){
        if(UnvalidChar == 1){
            for (int j =  0; j < s.length(); j++){
                if (!(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <= 'Z') && !(s[j] >= '0' && s[j] <= '9')){
                    if(s[j] != '!' && s[j] != '@' && s[j] !='#' && s[j] != '$' && s[j] !='%'){return j;}}}
        } else {return 100;}
    }
    return 100;
}

int check_Continue(const string &S){
    for(int i = 0; i < S.length(); i++)
        if(S[i] == S[i+1] && S[i+1] == S[i+2]){
            return i;
        }
    return -1;
}

int check_Substring(const string& S, const string& se) {
    size_t found = S.find(se);
    if (found != string::npos) {return (int)found;}
    return -1;
}

int checkPassword(const char * s, const char * email) {
    string S = s;
    string Email = email;
    int i = find_se(email);
    string se = Email.substr(0, i);

    if (8 > S.length()){return -1;}                               // check ngắn hơn
    else if (S.length() > 20){return -2;}                         // check dài hơn
    else if(check_Substring(S, se) != -1){return -(300 + check_Substring(S, se));}// check chứa se                                                                           
    else if (check_Continue(S) != -1){return -(400 + check_Continue(S));} // check số liên tiếp
    else if (check_Char(S) == -5){return check_Char(S);}                // ko chứa kí tự đặc biệt 
    else if (check_Char(S) != 100){return check_Char(S);}               // chứa kí tự đặc biệt nhưng chứa kí tự sai
    else{return -10;}
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int Numstring[num_pwds];    // array chứa số lần trùng mật khẩu của mỗi phần tử
    for (int m = 0; m < num_pwds; m++){Numstring[m]=1;}
    for(int i = 0; i < num_pwds; i++){
        for (int j =0; j < num_pwds; j++){
            if(i != j){
                if(strcmp(arr_pwds[i], arr_pwds[j]) == 0){Numstring[i] = Numstring[i] + 1;}
            }
        }
    }
    int max_repeat = Numstring[0];
    int n=0;
    while (n < num_pwds){
        if(max_repeat < Numstring[n]){max_repeat = Numstring[n];} // tìm số lần trùng max_repeat có trong array
        n++;
    }
    int max_length = 0;
    int k =0;
    while(k < num_pwds){
        if(Numstring[k] == max_repeat){
            if(strlen(arr_pwds[k]) >= max_length){max_length = strlen(arr_pwds[k]);}} //tìm độ dài max_length của những phần tử có số lần trùng max_repeat
        k++;
    }
    int l=0;
    while(l < num_pwds){
        if(Numstring[l] == max_repeat){
            if(strlen(arr_pwds[l]) == max_length){break;}} // tìm vị trí đầu tiên mà phần tử có số lần trùng max và có độ dài max
        l++;
    }
    return l;

}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////