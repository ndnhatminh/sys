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
void StanDard_HP(int &a){
    if (a > 666) a = 666;
    if(a < 0) a = 0;
}

void StanDard_EXP(int  &a){ 
    if (a > 600) a = 600;
    if(a < 0) a = 0;
}

void StanDard_M(int & a){
    if (a > 3000) a = 3000;
    if(a < 0) a = 0;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //Trường hợp 0:
    if(e1 < 0  || e1 > 99) return -99;
    StanDard_EXP(exp1);
    StanDard_EXP(exp2);

    //Trường hợp 1 
    if(e1 >= 0 && e1 <= 3){
        //e = 0
        if(e1 == 0){
            exp2 += 29;
        }
        //e = 1
        if(e1 == 1){
            exp2 += 45;
        }
        //e = 2  
        if(e1 == 2){
            exp2 += 75;
        }
        //e = 3
        if(e1 == 3){
            exp2 = exp2 + 29 + 75 + 45;
        }
        if(exp2 > 600) exp2 = 600;

    //dua ra quyet dinh
        int D = (e1 * 3) + (exp1 * 7);
        if(D % 2 == 0){
            exp1 = ceilf(exp1 + double(D)/200);
        }
        else {
            exp1 = ceilf(exp1 - double(D)/100);
        }
    }

    //Trường hợp 2:
    if(e1 >= 4 && e1 <= 99){
        if(e1 >= 4 && e1 <= 19){
            exp2 = exp2 + ceilf(double(e1)/4 + 19);
        }
        if(e1 >= 20 && e1 <= 49){
            exp2 = exp2 + ceilf(double(e1)/9 + 21);
        }
        if(e1 >= 50 && e1 <= 65){
            exp2 = exp2 + ceilf(double(e1)/16 + 17);
        }
        if(e1 >= 66 && e1 <= 79){
            exp2 = exp2 + ceilf(double(e1)/4 + 19);
            if(exp2 > 200){
                exp2 = exp2 + ceilf(double(e1)/9 + 21);
            }
        }
        if(e1 >= 80 && e1 <= 99){
            exp2 = exp2 + ceilf(double(e1)/4 + 19);
            exp2 = exp2 + ceilf(double(e1)/9 + 21);
            if(exp2 > 400){
                exp2 = exp2 + ceilf(double(e1)/16 + 17);
                exp2 = (exp2*1.15 + 0.999);
            }
        } 
        exp1 = exp1 - e1;
    }
    StanDard_EXP(exp1);
    StanDard_EXP(exp2);
    return exp1 + exp2;
}

// Task 2
int SumOfNum(int a){
        int sum = 0;

        while(a){
            sum = sum + (a%10);
            a = a/10;
        }

        if(sum >= 10){
            sum = sum%10;
        }
        return sum;
    }

    int Sqrt_Number(int a){
        int b = floor(sqrt(a));
        int c = b + 1;
        if(abs(a- b*b) > abs(a - c*c)){
            return c*c;
        }
        else return b*b;
        return -1;
    }

    double street1(int & EXP1){
        //tinh xac suat:
        int S = Sqrt_Number(EXP1);
        if(EXP1 >= S){
            return 1;
        }
        else return ((double(EXP1)/double(S) + 80)/123);
    }

    double street2(int & HP1, int & EXP1, int & M1, int E2){
        int Half_Of_M1 = (M1/2);
        int Sum_Of_Money = 0;

        //case 1: E2 la so chan
        if(E2%2 == 0){
            for (int i = 0;M1 > 0 && i < 3; i++)
            {
                //su kien 1:
                if(i == 0){
                    if(HP1 < 200){
                        HP1 = (HP1*1.3 + 0.999);
                        M1 = M1-150;
                    }
                    else if(HP1 >= 200){
                        HP1 = (HP1*1.1 + 0.999);
                        M1 = M1 - 70;
                    }
                }
                //su kien 2:
                if(i == 1){
                    if(EXP1 < 400){
                        M1 = M1 - 200;
                        EXP1 = (EXP1*1.13 + 0.999);
                    }
                    else if(EXP1 >= 400){
                        M1 = M1 - 120;
                        EXP1 = (EXP1*1.13 + 0.999);
                    }
                }
                //su kien 3:
                if(i == 2){
                    if(EXP1 < 300){
                        M1 = M1 - 100;
                    }
                    else if(EXP1 >= 300){
                        M1 = M1 - 120;
                    }
                    EXP1 = (EXP1*0.9 + 0.999);
                }

                if(EXP1 > 600) EXP1 = 600;
                if(HP1 > 666) HP1 = 666;
                if(M1 < 0) M1 = 0;
            }
        }
        //case 2: E2 la so le
        else if(E2%2 == 1){
            for (int i = 0;Sum_Of_Money <= Half_Of_M1 && M1 > 0; i++)
            {
                //su kien 1:
                if(i%3 == 0){
                    if(HP1 < 200){
                        HP1 = (HP1*1.3 + 0.999);
                        M1 = M1-150;
                        Sum_Of_Money += 150;
                    }
                    else if(HP1 >= 200){
                        HP1 = (HP1*1.1 + 0.999);
                        M1 = M1 - 70;
                        Sum_Of_Money += 70;
                    }
                }
                //su kien 2:
                if(i%3 == 1){
                    if(EXP1 < 400){
                        M1 = M1 - 200;
                        EXP1 = (EXP1*1.13 + 0.999);
                        Sum_Of_Money += 200;
                    }
                    else if(EXP1 >= 400){
                        M1 = M1 - 120;
                        EXP1 = (EXP1*1.13 + 0.999);
                        Sum_Of_Money += 120;
                    }
                }
                //su kien 3:
                if(i%3 == 2){
                    if(EXP1 < 300){
                        M1 = M1 - 100;
                        Sum_Of_Money += 100;
                    }
                    else if(EXP1 >= 300){
                        M1 = M1 - 120;
                        Sum_Of_Money += 120;
                    }
                    EXP1 = (EXP1*0.9 + 0.999);
                }

                if(EXP1 > 600) EXP1 = 600;
                if(HP1 > 666) HP1 = 666;
                if(M1 < 0) M1 = 0;
            }

        }
            HP1 = (HP1*0.83 + 0.999);
            EXP1 = (EXP1*1.17 + 0.999);
        //tinh xac suat
        if(EXP1 > 600) EXP1 = 600;
        if(HP1 > 666) HP1 = 666;
        int S = Sqrt_Number(EXP1);
        double P = (double(EXP1)/S + 80)/123;
        if(EXP1 >= S){
            return 1;
        }
        else return P;
    }

    double street3(int E2){
        int P[10] = {32,47,28,79,100,50,22,83,64,11};
        if(E2 < 10) return double(P[E2])/100;
        else return (double(P[SumOfNum(E2)]))/100;
    }

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2 < 0  || E2 > 99) return -99;
    StanDard_EXP(EXP1);
    StanDard_HP(HP1);
    StanDard_M(M1);
     
    double P1 = street1(EXP1);
    double P2 = street2(HP1, EXP1, M1, E2);
    double P3 = street3(E2);
    double P = ((P1+P2+P3)/3)*100;
    if(P == 100){
        EXP1 = (EXP1*0.75 + 0.999);
    } 
    else if( P < 50){
        HP1 = (HP1*0.85 + 0.999);
        EXP1 = (EXP1*1.15 + 0.999);
    }
    else if( P >= 50){  
        HP1 = (HP1*0.9 + 0.999);
        EXP1 = (EXP1*1.2 + 0.999);
    }
    if(EXP1 > 600) EXP1 = 600;
    if(HP1 > 666) HP1 = 666;

    return HP1 + EXP1 + M1;
}

// Task 3
int Matrix_Taxi[10][10] = {0};
int Matrix_Holmes[10][10] = {0};

int max_fake(int a, int b){
    int max  = a;
    if(max < b) max = b;
    return max;
}

int min_fake(int a, int b){
    int min = a;
    if(min > b) min = b;
    return min;
}

void Create_Matrix_Taxi(int E3){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            Matrix_Taxi[i][j] = ((E3*j)+(i*2))*(i-j);
        }
    }  
}

void Create_Matrix_Holmes(int E3){
    int max_right = 0;
    int max_left = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            max_left = Matrix_Taxi[i][j];
            max_right = Matrix_Taxi[i][j];
            //trai tang
            for (int k = 1;max_fake(i, j) + k <= 9; k++)
            {
                if(Matrix_Taxi[i+k][j+k] > max_left) max_left = Matrix_Taxi[i+k][j+k];
            }
            //trai giam
            for (int k = 1;min_fake(i,j) - k >= 0; k++)
            {
                if(Matrix_Taxi[i-k][j-k] > max_left) max_left = Matrix_Taxi[i-k][j-k];

            }
            //phai tang
            for (int k = 1;(i-k >= 0) && (j+k <= 9); k++)
            {
                if(max_right < Matrix_Taxi[i-k][j+k]) max_right = Matrix_Taxi[i-k][j+k];  
            }
            //phai giam
            for (int k = 1;(i+k <= 9) && (j-k >= 0); k++)
            {
                if(max_right < Matrix_Taxi[i+k][j-k]) max_right = Matrix_Taxi[i+k][j-k];     
            }
            Matrix_Holmes[i][j] = abs(max_fake(max_left,max_right));
        }
    }
}

int Count_Better(int E3){
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(Matrix_Taxi[i][j] > E3*2) cnt++;
        }
    }  
    return cnt;
}

int Count_Lower(int E3){
    int cnt = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(Matrix_Taxi[i][j] < (-E3)) cnt++;
        }
    }  
    return cnt;
}

int Sum_Of_All_Num(int a){
    int sum = 0;
    while(a){
        sum = sum + a%10;
        a = a/10;
    }
    if(sum >= 10){
        a = sum;
        sum = 0;
        while (a)
        {
            sum = sum + a%10;
            a = a/10;
        }
    }
    return sum;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3 < 0  || E3 > 99) return -99;
    StanDard_HP(HP1);
    StanDard_EXP(EXP1);
    StanDard_HP(HP2);
    StanDard_EXP(EXP2);
    
    Create_Matrix_Taxi(E3);
    Create_Matrix_Holmes(E3);
    int better = Count_Better(E3);
    int sum_of_better = Sum_Of_All_Num(better);
    int lower = Count_Lower(E3);
    int sum_of_lower = Sum_Of_All_Num(lower);

    if(abs(Matrix_Taxi[sum_of_better][sum_of_lower]) > Matrix_Holmes[sum_of_better][sum_of_lower]) {
        EXP1 = (EXP1*0.88 + 0.999);
        HP1 = (HP1*0.9 + 0.999);
        EXP2 = (EXP2*0.88 + 0.999);
        HP2 = (HP2*0.9 + 0.999);
        return Matrix_Taxi[sum_of_better][sum_of_lower];
    }
    else {
        EXP1 = (EXP1*1.12 + 0.999);
        HP1 = (HP1*1.1 + 0.999);
        EXP2 = (EXP2*1.12 + 0.999);
        HP2 = (HP2*1.1 + 0.999);
        StanDard_EXP(EXP1);
        StanDard_HP(HP1); 
        StanDard_EXP(EXP2);
        StanDard_HP(HP2);
        return Matrix_Holmes[sum_of_better][sum_of_lower];
    }

    return -1;
}

// Task 4
bool Is_Sub_String(string str, string substr){
    if(str.find(substr) != string::npos) return true;
    else return false;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string s_1 = s;
    string email_1 = email;
    string se;
    int pos_1 = email_1.find('@');
    //lay chuoi se
    se = email_1.substr(0, pos_1);
    //dieu kien 2: do dai chuoi ngan hon do dai toi thieu
    if(s_1.length() < 8) return -1;
    //dieu kien 3: do dai chuoi dai hon do dai toi thieu
    if(s_1.length() > 20) return -2;
    //dieu kien 4: Xuat hien chuoi se
    if(Is_Sub_String(s_1, se)) return -(300 + s_1.find(se));
    //dieu kien 5: Co hai ki tu lien tiep giong nhau
    for (int i = 0; i < strlen(s); i++)
    {
        if(s[i] == s[i + 1] && s[i] == s[i + 2])  return(-(400 + i));
    }
    //dieu kien 6: khong co ki tu dac biet
    int flag = 0;
    for (int i = 0; i < s_1.length(); i++)
    {
        if(s_1[i] == '@' || s_1[i] == '#' || s_1[i] == '%' || s_1[i] == '$' || s_1[i] == '!') flag = 1;
    }
    if(flag == 0) return -5;
    //dieu kien 7:cac truong hop con lai
    for (int i = 0; i < s_1.length(); i++)
    {
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || 
        (s[i] == '@') || (s[i] == '#') || (s[i] == '%') || (s[i] == '$') || (s[i] == '!')))
        return i;
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string pass[1000];
    int count[1000] = {0};
    int max_count = 0;
    int max_len = 0;

    //chuyen char sang string cho de 
    for (int i = 0; i < num_pwds; i++)
    {
        pass[i] = arr_pwds[i];    
    }

    for (int i = 0;i < num_pwds; i++)
    {
        for (int j = i + 1;j < num_pwds; j++)
        {
            if (pass[i] == pass[j])
            {
                count[i]++;
            }
        }
        if ((count[i] > max_count) || (count[i] == max_count && pass[i].length() > pass[max_len].length()))
        {
            max_count = count[i];
            max_len = i;
        }
    }
    return max_len;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////