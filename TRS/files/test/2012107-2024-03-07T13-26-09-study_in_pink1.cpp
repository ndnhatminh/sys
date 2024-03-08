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
int firstMeet(int & exp1, int & exp2, int e1)
{
    if (e1 < 0 || e1 > 99) // Check if e valid
    {
        return -99;
    }

    if (e1 >= 0 && e1 <= 3)
    {
        switch (e1)
        {
        case 0:
            exp2 += 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += (29 + 45 + 75);
            break;
        default:
            return -99;
        }
        int decision = e1 * 3 + exp1 * 7;
        exp2 = std::max(0, std::min(600, exp2));

        if (decision % 2 == 0)
        {
            exp1 = (exp1 + decision / 200) + ((exp1 + decision) % 200 > 0);
        }
        else
        {
             exp1 = (exp1 - decision / 100) + ((exp1 - decision) % 100 > 0);
        }
        exp1 = std::max(0, std::min(600, exp1));
    }
   else if (e1 >= 4 && e1 <= 99)
{
    
    if (e1 >= 4 && e1 <= 19)
    {
        exp2 = ceil(exp2 + (e1 / 4.0 + 19));
    }
    else if (e1 >= 20 && e1 <= 49)
    {
        exp2 = (ceil)(exp2 + (e1 / 9.0 + 21));
    }
    else if (e1 >= 50 && e1 <= 65)
    {
        exp2 = (ceil)(exp2 + (e1 / 16.0 + 17));
    }
    else if (e1 >= 66 && e1 <= 79)
    {
        exp2 = (ceil)(exp2 + (e1 / 4.0 + 19));

        if (exp2 > 200)
        {
            exp2 = (ceil)(exp2 + (e1 / 9.0 + 21));
        }
    }
    else
    {
        exp2 = (ceil)(exp2 + (e1 / 4.0 + 19));

        exp2 = (ceil)(exp2 + (e1 / 9.0 + 21));

        if (exp2 > 400)
        {
            exp2 = (ceil)(exp2 + (e1 / 16.0 + 17));
            exp2 = (ceil)(exp2 + exp2 *0.15);
        }
    }

    exp1 -= e1;

    exp1 = std::max(0, std::min(600, exp1));
    exp2 = std::max(0, std::min(600, exp2));
}


        
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    if (E2 < 0 || E2 > 99) // Check if e valid
    {
        return -99;
    }
    float P1, P2, P3;
    //CHẶNG ĐƯỜNG 1
    int num1 = static_cast<int>(std::round(std::sqrt(EXP1)));
    int S1 = num1*num1;
    if (EXP1 >= S1) 
    {
        P1 = 1.00;
    } else {
        P1 = (EXP1/S1 + 80.0)/123.0;
    }
    
    //CHẶNG ĐƯỜNG 2
    int M1_shopping;
    
    /// TRƯỜNG HỢP E2 LÀ SỐ LẺ 
    int M1_start = ceil(0.5 * M1);
    bool completed_event = false;
    if (E2 % 2 == 1){
    
    for(int num = 0; !completed_event;) {
        if (HP1 < 200)
        {
        M1_shopping = M1 - 150;
        num += 150;
        if (M1_shopping > 0 && M1_start >= num) {
            M1 = M1_shopping;
            HP1 = ceil(HP1 + 0.3*HP1);
        } else if (M1_shopping > 0 && M1_start < num )
        {
            M1 = M1_shopping;
            HP1 = ceil(HP1 + 0.3*HP1);
            completed_event = true;
            break;
        }
            else
        {
            M1 = 0;
            HP1 = ceil(HP1 + 0.3*HP1);
            completed_event = true;
            break;
        }
        HP1 = std::max(0, std::min(666, HP1));
            
        } else {
            M1_shopping = M1 - 70;
            num += 70;
            if (M1_shopping > 0 && M1_start >= num) 
            {
                M1 = M1_shopping;
                HP1 = ceil(HP1 + 0.1*HP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                HP1 = ceil(HP1 + 0.1*HP1);
                completed_event = true;
                HP1 = std::max(0, std::min(666, HP1));
                break;
            }
                else
            {
                M1 = 0;
                HP1 = ceil(HP1 + 0.1*HP1);
                completed_event = true;
                HP1 = std::max(0, std::min(666, HP1));
                break;
            }
            HP1 = std::max(0, std::min(666, HP1));
        }

        if (EXP1 < 400){
            
            M1_shopping = M1 - 200;
            num += 200;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
        } else {
            M1_shopping = M1 - 120;
            num += 120;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                completed_event = true;
                break;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }

        if (EXP1 < 300){
            M1_shopping = M1 - 100;
            num += 100;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        } else {
            M1_shopping = M1 - 120;
            num += 120;
            if (M1_shopping > 0 && M1_start > num) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else if (M1_shopping > 0 && M1_start < num )
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                completed_event = true;
                break;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }
    }
    HP1 = ceil(HP1 - 0.17 * HP1);
    EXP1 = ceil(EXP1 + 0.17 * EXP1);

    EXP1 = std::max(0, std::min(600, EXP1));
    HP1 = std::max(0, std::min(666, HP1));
    
} 
 

///TRUONG HOP E2 LA SO CHAN
    else {
    bool keepwalking = true;
    if (HP1 < 200)
        {
        M1_shopping = M1 - 150;
        if (M1_shopping > 0) {
            M1 = M1_shopping;
            HP1 = ceil(HP1 + 0.3*HP1);
        } 
            else
        {
            M1 = 0;
            HP1 = ceil(HP1 + 0.3*HP1);
            
            keepwalking = false;
        }
        HP1 = std::max(0, std::min(666, HP1));
            
        } else{
            M1_shopping = M1 - 70;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                HP1 = ceil(HP1 + 0.1*HP1);
            } 
                else
            {
                M1 = 0;
                HP1 = ceil(HP1 + 0.1*HP1);
                keepwalking = false;
            }
            HP1 = std::max(0, std::min(666, HP1));
        }

        if (keepwalking && EXP1 < 400){
            
            M1_shopping = M1 - 200;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                
                keepwalking = false;
            }
        } else if (keepwalking && EXP1 >= 400) {
            M1_shopping = M1 - 120;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 + 0.13*EXP1);
                
                keepwalking = false;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }

        if (keepwalking && EXP1 < 300){
            M1_shopping = M1 - 100;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                
                keepwalking = false;
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        } else if (keepwalking && EXP1 >= 300) {
            M1_shopping = M1 - 120;
            if (M1_shopping > 0) 
            {
                M1 = M1_shopping;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
            } 
                else
            {
                M1 = 0;
                EXP1 = ceil(EXP1 - 0.1*EXP1);
                
            }
            EXP1 = std::max(0, std::min(600, EXP1));
        }

    HP1 = ceil(HP1 - 0.17 * HP1);
    EXP1 = ceil(EXP1 + 0.17 * EXP1);

    EXP1 = std::max(0, std::min(600, EXP1));
    HP1 = std::max(0, std::min(666, HP1));
}


    int num2 = static_cast<int>(std::round(std::sqrt(EXP1)));
    int S2 = num2*num2;
    if (EXP1 >= S2) 
    {
        P2 = 1.00;
    } else {
        P2 = (EXP1/S2 + 80.0)/123.0;
    }
//CHẶNG ĐƯỜNG 3
   float P[] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int sumDigits = (E2 / 10) + (E2 % 10);
        i = sumDigits % 10;
    }
    P3 = P[i];
    if (P1 == 1 && P2 == 1 && P3 == 1) {
    // Nếu cả 3 đều là 100%, giảm EXP1 đi 25%
    EXP1 = ceil(EXP1 - 0.25 * EXP1);

    EXP1 = std::max(0, std::min(600, EXP1));
    
} else {
    // Nếu không phải tất cả đều là 100%, tính trung bình cộng xác suất
    float avgProbability = (P1 + P2 + P3) / 3.00;

    // Kiểm tra xác suất cuối cùng
    if (avgProbability < 0.50) {
        // Nếu xác suất trung bình nhỏ hơn 50%, giảm HP1 và tăng EXP1
        HP1 = ceil(HP1 - 0.15 * HP1);
        EXP1 = ceil(EXP1 + 0.15 * EXP1);

        EXP1 = std::max(0, std::min(600, EXP1));
        HP1 = std::max(0, std::min(666, HP1));
    } else {
        // Nếu xác suất trung bình lớn hơn hoặc bằng 50%, giảm HP1 và tăng EXP1
        HP1 = ceil(HP1 - 0.10 * HP1);
        EXP1 = ceil(EXP1 + 0.20 * EXP1);

        EXP1 = std::max(0, std::min(600, EXP1));
        HP1 = std::max(0, std::min(666, HP1));
    }
}   

    return HP1 + EXP1 + M1;
}
    

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
   
    if (E3 < 0 || E3 > 99) // Check if e valid
    {
        return -99;
    }

    // TODO: Complete this function
    int taxi_arr[10][10] = {0};
    
    // Taxi di qua tung diem
    
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < 10; ++j)
        {
            
            taxi_arr[i][j] =  ((E3 * j) + (i * 2))* (i - j);
        }
    }
     

    // Diem so cua s&W khi di loi tat: Max cua duong cheo trai va cheo phu tai X
    // X am thi lay absolute
    
    // Taxi gap s&w tai (i,j)
    // Tim i: So diem taxi > E*2
    int iCount = 0;
    int iGreeter = E3 * 2;
    for(int i = 0; i < 10; i++)
    {
        for(int j =0 ; j <10 ; j++)
        {
            if(taxi_arr[i][j] > iGreeter)
            {
                iCount++;
            }
        }
    }
    while(iCount >= 10)
    {
        int sum = 0;
        while(iCount != 0)
        {
            sum += iCount%10;
            iCount /= 10;
        }
        iCount = sum;
    }
   
    // Tim j: So diem taxi < -E3
    // Neu i hoac j co 2 chu so thi cong 2 chu so do den khi con 1(while)
    int jCount = 0;
    int jSmaller = -E3;
    for(int i = 0; i < 10; i++)
    {
        for(int j =0 ; j <10 ; j++)
        {
            if(taxi_arr[i][j] < jSmaller)
            {
                jCount++;
            }
        }
    }
    while(jCount >= 10)
    {
        int sum = 0;
        while(jCount != 0)
        {
            sum += jCount%10;
            jCount /= 10;
        }
        jCount = sum;
    }
   
    // Gap nhau tai (iCount, jCount)
    int sherlockNWatsonPoint = taxi_arr[iCount][jCount];
    if (jCount > iCount){
        int j = jCount - iCount;
        for(int i = 0; i < 10; ++i) // Duyet tu tren xun
        {
            // So sanh vs max
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);
            
            // Qua o moi
            ++j;
            if(j == 10) // Het cot
            {
                break;
            }
        }
    }
    //di duong cheo trai -> tim so cot cua cot dau tien (i,0)
    // Cach tinh: j = jVal - (iVal)
    if (iCount > jCount){
        int i = iCount - jCount;
        for(int j = 0; j < 10; ++j) // Duyet tu tren xun
        {
            // So sanh vs max
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);
            
            // Qua o moi
            ++i;
            if(i == 10) // Het cot
            {
                break;
            }
        }
    }
    if ((iCount + jCount) < 9){
        int j = iCount + jCount;
        for(int i = 0; i < 10; ++i) // Duyet tu tren xun
        {
            // So sanh vs max
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);
            
            // Qua o moi
            --j;
            if(j == -1) // Het cot
            {
                break;
            }
        }
    }

    if ((iCount + jCount) > 9){
        int i = ((iCount + jCount )/10 + (iCount + jCount)%10);
        for(int j = 9; j > 0; --j) // Duyet tu tren xun
        {
            // So sanh vs max
            sherlockNWatsonPoint = std::max(sherlockNWatsonPoint, taxi_arr[i][j]);
            
            // Qua o moi
            i++;
            if(i == 10) // Het cot
            {
                break;
            }
        }
    }
    
    if(sherlockNWatsonPoint <0)
    {
        sherlockNWatsonPoint = -sherlockNWatsonPoint;
    }

    
    // Tai diem do,abs diem taxi > diem s&w thi k duoi kip. Va nguoc lai
    // Duoi kip: Tang 12% exp. tang 10% HP. Va nguoc lai
    int result = 0;
    int absTaxi = taxi_arr[iCount][jCount];
    if (absTaxi < 0)
    {
        absTaxi = -absTaxi;
    }
    
    if (sherlockNWatsonPoint >= absTaxi)
    {
        EXP1 = 1.12*EXP1 + 0.999;
        EXP1 = std::max(0, std::min(600, EXP1));

        HP1 = 1.1*HP1 + 0.999;
        HP1 = std::max(0, std::min(666, HP1));

        EXP2 = 1.12*EXP2 + 0.999;
        EXP2 = std::max(0, std::min(600, EXP2));

        HP2 = 1.1*HP2 + 0.999;
        HP2 = std::max(0, std::min(666, HP2)); 
        result = sherlockNWatsonPoint;
    }
    else
    {
        EXP1 = 0.88*EXP1 + 0.999;
        EXP1 = std::max(0, std::min(600, EXP1));

        HP1 = 0.9*HP1 + 0.999;
        HP1 = std::max(0, std::min(666, HP1));

        EXP2 = 0.88*EXP2 + 0.999;
        EXP2 = std::max(0, std::min(600, EXP2));

        HP2 = 0.9*HP2 + 0.999;
        HP2 = std::max(0, std::min(666, HP2));
        result = taxi_arr[iCount][jCount];
    }
    // Return so lon hon giua taxi va s&w (so am neu co)

     return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // Lấy chuỗi se từ email
    char se[101];
    int i = 0;
    while (email[i] != '@') {
        se[i] = email[i];
        i++;
    }
    se[i] = '\0';

    // Kiểm tra độ dài của mật khẩu
    int len = strlen(s);
    if (len < 8) return -1;
    if (len > 20) return -2;

    // Kiểm tra xem có chứa chuỗi se không
    const char *found = strstr(s, se);
    if (found != NULL) {
        int sei = found - s;
        return -(300 + sei);
    }

    // Kiểm tra ký tự liên tiếp và giống nhau
    for (i = 0; i < len - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            int start = i;
            while (i < len - 1 && s[i] == s[i + 1]) {
                i++;
            }
            return -(400 + start);
        }
    }

    // Kiểm tra ký tự đặc biệt
    bool hasSpecialChar = false;
    for (i = 0; i < len; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) return -5;


    // Kiểm tra các điều kiện khác
    for (i = 0; i < len; i++) {
        if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') || s[i] == '@' || s[i] == '#' || s[i] == '%' ||
              s[i] == '$' || s[i] == '!')) {
            return i;
        }
    }

    // Mật khẩu hợp lệ
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;
    int maxLength = 0;
    int correctIndex = -1;

    for (int i = 0; i < num_pwds; ++i) {
        const char *password = arr_pwds[i];
        int count = 1; // Đếm mật khẩu hiện tại

        // Kiểm tra với các mật khẩu còn lại
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(password, arr_pwds[j]) == 0) {
                count++;
            }
        }

        // So sánh với mật khẩu có số lần xuất hiện nhiều nhất
        if (count > maxCount || (count == maxCount && strlen(password) > maxLength)) {
            maxCount = count;
            maxLength = strlen(password);
            correctIndex = i;
        }
    }

    return correctIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////