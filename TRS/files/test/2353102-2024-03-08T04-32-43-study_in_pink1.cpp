#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
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

// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
int D;
if (e1 < 0 or e1 > 99) return -99;
else{ 
    if (exp1 <= 0) exp1 = 0;
    else if (exp1 >=600) exp1 = 600;
    if (exp2 <= 0) exp2 = 0;
    else if (exp2 >=600) exp2 = 600;
    if (e1 == 0) 
        exp2 += 29;
    else if (e1 == 1)
        exp2 += 45;
    else if (e1 == 2) 
        exp2 += 75;
    else if (e1 == 3) 
        exp2 += 149;
    else if (e1 >= 4 && e1 <= 19) 
        exp2 += (int)(e1 / 4.0 + 0.999) + 19;
    else if (e1 >= 20 && e1 <= 49) 
        exp2 += (int)(e1 / 9.0 + 0.999) + 21;
    else if (e1 >= 50 && e1 <= 65) 
        exp2 += (int)(e1 / 16.0 + 0.999) + 17;
    else if (e1 >= 66 && e1 <= 79) {
        exp2 += (int)(e1 / 4.0 + 0.999) + 19;
        if (exp2 > 200) 
            exp2 += (int)(e1 / 9.0 + 0.999) + 21;
    }
    else if (e1 >= 80 && e1 <= 99) {
        exp2 += (int)(e1 / 4.0 + 0.999) + 19;
        exp2 += (int)(e1 / 9.0 + 0.999) + 21;
        if (exp2 > 400) 
            exp2 = (int)(((exp2 + e1/16 + 17 + 0.999)*1.15)+0.999);
    }

    if (e1 >= 0 && e1 <= 3) {
        D = e1 * 3 + exp1 * 7;
        if (D % 2 == 0)
             exp1 = (int)(exp1 + (D / 200.0) + 0.999);
        else if(D % 2 == 1)
            exp1 = (int)(exp1 - (D / 100.0) + 0.999);
    }
    if (e1 > 3 && e1 < 100) 
        exp1 -= e1;
    
    if (exp1 <= 0) exp1 = 0;
    else if (exp1 >=600) exp1 = 600;
    if (exp2 <= 0) exp2 = 0;
    else if (exp2 >=600) exp2 = 600;
    return static_cast<int>(exp1 + exp2);
}}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
       if (E2 < 0 or E2 > 99) return -99;
    if (EXP1 <= 0) EXP1 = 0;
        else if (EXP1 >=600) EXP1 = 600;
    if (HP1 <= 0) HP1 = 0;
        else if (HP1 >=666) HP1 = 666;
    if (M1 <= 0) M1 = 0;
        else if (M1 >3000) M1 = 3000;
    
        double P1;
        double nearestsquare = static_cast<int>(sqrt(EXP1) + 0.5);
        int S = nearestsquare * nearestsquare;
            if (EXP1 >= S) {
                P1 = 100.0;
                    } else {
                P1 = (EXP1/S + 80.0)/123.0 * 100.0;
}
    
        int check = 0;
        int half = M1 * 0.5;
        if(E2 % 2 == 1) {
            for (int i = 0; i < 10 && check <= half; ++i){
                if (HP1 < 200) {
                    HP1 += (int)(HP1 * 0.3 + 0.999); // Hồi phục sức khỏe
                    M1 -= 150;
                    check += 150;
                } else {
                    HP1 += (int)(HP1 * 0.1 + 0.999); // Hồi phục sức khỏe
                    M1 -= 70;
                    check += 70;
                }
                    if (check > half) break;
                if (EXP1 < 400) {
                    M1 -= 200;
                    check += 200;// Chi phí thuê taxi
                    EXP1 = (int)(EXP1*1.13+0.999); // Tăng kinh nghiệm
                } else {
                    M1 -= 120;
                    check += 120;// Chi phí thuê xe ngựa
                    EXP1 = (int)(EXP1*1.13+0.999); // Tăng kinh nghiệm
                }
                    if (check > half) break;
                if (EXP1 < 300) {
                    M1 -= 100;
                    check += 100;
                    EXP1 = (int)(EXP1*0.9+0.999);// Giảm kinh nghiệm
                } else {
                    M1 -= 120;
                    check += 120;
                    EXP1 = (int)(EXP1*0.9+0.999); // Giảm kinh nghiệm
                }
                if (check > half) break;
            
            }
            
        }
         else { 
        if (M1 > 0){
              // Con đường 02
             if (HP1 < 200) {
                HP1 += (int)(HP1 * 0.3 + 0.999); // Hồi phục sức khỏe
                M1 -= 150;
            } else {
                HP1 += (int)(HP1 * 0.1 + 0.999); // Hồi phục sức khỏe
                M1 -= 70;
            }
        }
        if (M1 > 0){
            if (EXP1 < 400) {
                M1 -= 200;
                check += 200;// Chi phí thuê taxi
                EXP1 = (int)(EXP1*1.13+0.999); // Tăng kinh nghiệm
            } else {
                M1 -= 120;
                check += 120;// Chi phí thuê xe ngựa
                EXP1 = (int)(EXP1*1.13+0.999); // Tăng kinh nghiệm
            }
        }
         if(M1 > 0){
            if (EXP1 < 300) {
                M1 -= 100;
            } else {
                M1 -= 120;
            }
        EXP1 = (int)(EXP1*0.9 + 0.999); // Giảm kinh nghiệm
        }
    }
        
        HP1 = (int)((HP1*0.83) + 0.999); // Giảm sức khỏe
        EXP1 = (int)((EXP1 * 1.17) + 0.999); // Tăng kinh nghiệm
       
        double P2;
        double nearestsquare2 = static_cast<int>(sqrt(EXP1) + 0.5);
        double S2 = nearestsquare2 * nearestsquare2;
        if (EXP1 >= S2) {
            P2 = 100.0;
        } else {
            P2 = (EXP1 / S2 + 80.0) / 123.0 * 100.0;
        }
    // Con đường 03
        int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        int i;
        if (E2 < 10) {
            i = E2;
        } else {
            i = (E2 / 10 + E2 % 10) % 10;
    }
    double P3 = P[i];

    double tb = (int)(((P1 + P2 + P3) / 3) + 0.999);

    if(tb == 100){
        EXP1 = (int)((EXP1 * 0.75) + 0.999);
        HP1 = (int)((HP1 * 0.9 )+0.999); // Giảm sức khỏe
        EXP1 = (int)((EXP1 * 1.2) + 0.999); // Tăng kinh nghiệm
    }
    else if (tb < 50) {
        HP1 = (int)((HP1 * 0.85) + 0.999); // Giảm sức khỏe
        EXP1 = (int)((EXP1 * 1.15) + 0.999); // Tăng kinh nghiệm
    } else {
        HP1 = (int)((HP1 * 0.9 )+0.999); // Giảm sức khỏe
        EXP1 = (int)((EXP1 * 1.2) + 0.999); // Tăng kinh nghiệm
    }

    if (EXP1 <= 0) EXP1 = 0;
    else if (EXP1 >=600) EXP1 = 600;
    if (HP1 <= 0) HP1 = 0;
    else if (HP1 >=666) HP1 = 666;
    if (M1 <= 0) M1 = 0;
    else if (M1 >3000) M1 = 3000;

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    if (E3 < 0 or E3 > 99) return -99; 
    if (EXP1 <= 0) EXP1 = 0;
        else if (EXP1 >=600) EXP1 = 600;
    if (HP1 <= 0) HP1 = 0;
        else if (HP1 >=666) HP1 = 666;
    if (EXP2 <= 0) EXP2 = 0;
        else if (EXP2 >=600) EXP2 = 600;
    if (HP2 <= 0) HP2 = 0;
        else if (HP2 >=666) HP2 = 666;
    int map_taxi[10][10];
    int check_point_i, posI;
    int check_point_j, posJ;

    //Ma tran tim check_point
    for (int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            map_taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            
            if (map_taxi[i][j] < -E3) check_point_j += 1;          
            if (map_taxi[i][j] > E3*2) check_point_i += 1;
            
        }        
    }

    //tim posI va posJ
    posI = (check_point_i / 10) + (check_point_i % 10);
    if (posI >= 10) posI = (posI / 10) + (posI % 10);
        
    posJ = (check_point_j / 10) + (check_point_j % 10);
    if (posJ >= 10) posI = (posJ / 10) + (posJ % 10);

    //tim so diem cua shr va ws
    int shr_point = map_taxi[posI][posJ];
    int i_for_loop = posI;
    int j_for_loop = posJ;                                    
    //duong cheo tren trai (-i -j)
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop -= 1;
        j_for_loop -=1;
        
        if (shr_point < map_taxi[i_for_loop][j_for_loop]) shr_point = map_taxi[i_for_loop][j_for_loop];
    }
    
    //duong cheo tren phai (-i +j)
    i_for_loop = posI;
    j_for_loop = posJ;
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop -= 1;
        j_for_loop +=1;
        
        if (shr_point < map_taxi[i_for_loop][j_for_loop]) shr_point = map_taxi[i_for_loop][j_for_loop];
    }
    
    //duong cheo duoi trai (+i -j)
    i_for_loop = posI;
    j_for_loop = posJ;
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop += 1;
        j_for_loop -=1;
        
        if (shr_point < map_taxi[i_for_loop][j_for_loop]) shr_point = map_taxi[i_for_loop][j_for_loop];
    }
    
    //duong cheo duoi trai (+i +j)
    i_for_loop = posI;
    j_for_loop = posJ;
    while (i_for_loop > 0 && i_for_loop < 9 && j_for_loop > 0 && j_for_loop < 9)
    {   
        i_for_loop += 1;
        j_for_loop +=1;
        
        if (shr_point < map_taxi[i_for_loop][j_for_loop]) shr_point = map_taxi[i_for_loop][j_for_loop];
    }

    if (shr_point < 0) shr_point = abs(shr_point);

    int result = 0;
    if (abs(map_taxi[posI][posJ]) > shr_point)
    {
        EXP1 = (int)((EXP1 - 0.12*EXP1) + 0.999);
        HP1 = (int)((HP1 - 0.1*HP1) + 0.999);
        EXP2 = (int)((EXP2 - 0.12*EXP2) + 0.999);
        HP2 = (int)((HP2 - 0.1*HP2) + 0.999);
        result = map_taxi[posI][posJ];
    }
    else if (abs(map_taxi[posI][posJ]) <= shr_point)
    {
        EXP1 = (int)((EXP1 + 0.12*EXP1) + 0.999);
        HP1 = (int)((HP1 + 0.1*HP1) + 0.999);
        EXP2 = (int)((EXP2 + 0.12*EXP2)+0.999);
        HP2 = (int)((HP2 + 0.1*HP2) + 0.999);
        result = shr_point;
    }
        
    if (EXP1 <= 0) EXP1 = 0;
        else if (EXP1 >=600) EXP1 = 600;
    if (HP1 <= 0) HP1 = 0;
        else if (HP1 >=666) HP1 = 666;
    if (EXP2 <= 0) EXP2 = 0;
        else if (EXP2 >=600) EXP2 = 600;
    if (HP2 <= 0) HP2 = 0;
        else if (HP2 >=666) HP2 = 666;

    return result;
}

// Task 4
int checkPassword(const char * s, const char * email)
{char se[101]; 
    
    const char *chr = "@";
    
    const char *save = strstr(email, chr);
    
    int len = save - email;
    
    for (int i = 0; i < strlen(s); i++)
   {
        if (!isalnum(s[i]) || !islower(s[i]) || !isupper(s[i]) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!' )
        {
        continue;
        }  
        else return 0;
   }
    for (int i = 0; i < len; i++)
    {
        se[i] = email[i];
    }
  
    //Dk 1
    if (strlen(s) < 8) return -1;

    //Dk2
    if (strlen(s) > 20) return -2;
       
     //Dk3
    const char *check = strstr(s, se);
    int a = -(300 + (check - s));
    if (check != nullptr) 
    {
        return a;
    }

    //Dk4
    for(int i = 0; i <strlen(s); i++)
    {
        if(s[i] == s[i + 1] && s[i] == s[i + 2])
        {
           return -(400 + i);
        }
    }

   

    //Dk5
    const char *check_chr = "@#%$!";
    int count = 0;
    for (int i = 0; i < strlen(check_chr); i++)
    {
        for(int j = 0; j < strlen(s); j++)
        {
            if (check_chr[i] == s[j]) break;
            count += 1;
        }
            if (count != strlen(s) * (i + 1)) break;
    }
    if (count == strlen(s) * strlen(check_chr)) return -5;
    else return -10;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
   int freOfapp[30];
    string psw_ktn[30]; // phan tu khac nhau
    
    psw_ktn[0] = arr_pwds[0];
    
    int count = 1;
    int count1 = 0;
    
    //Tim phan tu rieng biet
    for (int i = 1; i < num_pwds; i++)
    {
        count1 = 0;
        for (int j = 0; j < count; j++)
        {     
            if(arr_pwds[i] != psw_ktn[j])
            {
                count1 += 1;
            } else break;
        }
        
        if (count1 == count) 
        {
            psw_ktn[count] = arr_pwds[i];
            count += 1;
        }    
        
    }
    //Tim tan suat moi phan tu rieng biet 
    for (int i = 0; i < count; i++)
    {
        freOfapp[i] = 0;
        for (int j = 0; j < num_pwds; j++)
        {
            if (psw_ktn[i] == arr_pwds[j])
            {
                freOfapp[i] += 1;
            }
        }
    }
    //Tim tan suat xuat hien nhieu nhat
    int max = freOfapp[0];
    for (int i = 1; i < count; i++)
    {
        if (max < freOfapp[i]) max = freOfapp[i];
    }
    //Tim vi tri cac phan tu co tan suat xuat hien nhieu nhat 
    int index[30];
    int count2 = 0;
    int dk = 0;
    for (int i = 0; i < count; i++)
    {
        if (max == freOfapp[i])
        {
            index[count2] = 0;
            index[count2] = i;
            count2 += 1;
            dk += 1;
        }
    }
    //neu co nhieu max giong nhau
    int max_length = psw_ktn[index[0]].length();
    int position = 0;
    if (dk > 1) 
    {
        for (int i = 1; i < dk; i++)
        {
            if (max_length < psw_ktn[index[i]].length())
            {
                max_length = psw_ktn[index[i]].length();
                position = i;
            }
        }
    } 
    
    cout<<index[position]<<endl;
    
    int a;
    for (int i = 0; i < num_pwds; i++)
    {
        if (psw_ktn[index[position]] == arr_pwds[i])
        {
            a = i;
            break;
        }
    }

    return a;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////