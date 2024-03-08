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

// Task 0
void checkTask1(int &EXP1, int &EXP2)
{
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 < 0)
    {
        EXP1 = 0;
    }

    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    else if (EXP2 < 0)
    {
        EXP2 = 0;
    }
}

void checkTask2(int &HP1, int &EXP1, int &M1)
{
    // EXP1
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    // HP1
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    else if (HP1 < 0)
    {
        HP1 = 0;
    }
    // M1
    if (M1 > 3000)
    {
        M1 = 3000;
    }
    else if (M1 < 0)
    {
        M1 = 0;
    }
}

void checkTask3(int &HP1, int &EXP1, int &HP2, int &EXP2)
{
    // EXP1
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    else if (EXP1 < 0)
    {
        EXP1 = 0;
    }
    // HP1
    if (HP1 > 666)
    {
        HP1 = 666;
    }
    else if (HP1 < 0)
    {
        HP1 = 0;
    }
    // EXP2
    if (EXP2 > 600)
    {
        EXP2 = 600;
    }
    else if (EXP2 < 0)
    {
        EXP2 = 0;
    }
    // HP2
    if (HP2 > 666)
    {
        HP2 = 666;
    }
    else if (HP2 < 0)
    {
        HP2 = 0;
    }
}

bool checkE(int E)
{
    if (E > -1 && E < 100)
    {
        return true;
    }

    return false;
}

bool isPerfectSquare(int n) {
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

int nearestPerfectSquare(int n) {
    
    if (isPerfectSquare(n)) {
        return n;
    }

    int smaller = n - 1;
    int larger = n + 1;

    while (true) {
        if (isPerfectSquare(smaller))
            return smaller;
        else if (isPerfectSquare(larger))
            return larger;

        smaller--;
        larger++;
    }
}

int getPi(int E2){
    if (E2 < 10) {
        return E2;
    } else {
        int sum = (E2 / 10) + (E2 % 10);
        return sum % 10;
    }
}

const char* findForbiddenSubstring(const char* email) {
    const char* atPos = strchr(email, '@'); // Find the position of the '@' symbol
    if (atPos == nullptr) {
        return nullptr; // If no '@' symbol found, return nullptr
    }

    // Calculate the length of the forbidden substring
    size_t forbiddenLength = atPos - email;

    // Allocate memory for the forbidden substring
    char* forbiddenSubstring = (char*)malloc(forbiddenLength + 1);
    if (forbiddenSubstring == nullptr) {
        return nullptr; // Memory allocation failed
    }

    // Copy the forbidden substring
    strncpy(forbiddenSubstring, email, forbiddenLength);
    forbiddenSubstring[forbiddenLength] = '\0'; // Null-terminate the string

    return forbiddenSubstring;
}

int sumDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

//! Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
    if (!checkE(E1))
    {
        return -99;
    }
    checkTask1(EXP1, EXP2);
    // case 1 [0,3]
    if (0 <= E1 && E1 <= 3)
    {
        if (E1 == 0)
        {
            EXP2 += 29;
            checkTask1(EXP1, EXP2);
        }
        else if (E1 == 1)
        {
            EXP2 += 45;
            checkTask1(EXP1, EXP2);
        }
        else if (E1 == 2)
        {
            EXP2 += 75;
            checkTask1(EXP1, EXP2);
        }
        else if (E1 == 3)
        {
            EXP2 += 149;
            checkTask1(EXP1, EXP2);
        }
        // d & EXP1
        int d = E1 * 3 + EXP1 * 7;

        if (d % 2 == 0)
        {
            EXP1 = ceil(d / 200.0 + EXP1);
            checkTask1(EXP1, EXP2);
        }
        else
        {
            EXP1 = ceil(EXP1 - d / 100.0);
            checkTask1(EXP1, EXP2);
        }
    }
    else
    { // case2
        if (4 <= E1 && E1 <= 19)
        {
            EXP2 = ceil(E1 / 4.0 + 19 + EXP2);
            checkTask1(EXP1, EXP2);
        }
        else if (20 <= E1 && E1 <= 49)
        {
            EXP2 = ceil(E1 / 9.0 + 21 + EXP2);
            checkTask1(EXP1, EXP2);
        }
        else if (50 <= E1 && E1 <= 65)
        {
            EXP2 = ceil(E1 / 16.0 + 17 + EXP2);
            checkTask1(EXP1, EXP2);
        }
        else if (66 <= E1 && E1 <= 79)
        {
            EXP2 = ceil(E1 / 4.0 + 19 + EXP2);
            checkTask1(EXP1, EXP2);
            if (EXP2 > 200)
            {
                EXP2 = ceil(E1 / 9.0 + 21 + EXP2);
                checkTask1(EXP1, EXP2);
            }
        }
        else if (80 <= E1 && E1 <= 99)
        {
            EXP2 = ceil(E1 / 4.0 + 19 + EXP2);
            checkTask1(EXP1, EXP2);
            EXP2 = ceil(E1 / 9.0 + 21 + EXP2);
            checkTask1(EXP1, EXP2);
            if (EXP2 > 400)
            {
                EXP2 = ceil(E1 / 16.0 + 17 + EXP2);
                checkTask1(EXP1, EXP2);
                EXP2 = ceil(EXP2 + (EXP2 * 15) / 100.0);
                checkTask1(EXP1, EXP2);
            }
        }
        EXP1 = EXP1 - E1;
        checkTask1(EXP1, EXP2);
    }

    checkTask1(EXP1, EXP2);

    return EXP1 + EXP2;
}

// Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{

    if (!checkE(E2))
    {
        return -99;
    }
    checkTask2(HP1, EXP1, M1);
    //first way
    double s = nearestPerfectSquare(EXP1);
    double tam = EXP1;
    double p1 = 0;
    if (EXP1 >= s) {
        p1 = 1;
    } else {
        p1 = (tam/s + 80)/123.0;
    }
    //second way
    double counter = 0;
    double ahalf = M1/2.0;

    if (E2%2 != 0){ // option1
        again:
        if (M1==0) { goto end;}
        //2.1
        if (HP1 < 200) {
            HP1 = ceil(round(HP1 * 1.3 * 100) / 100);
            checkTask2(HP1, EXP1, M1);
            M1 = M1 - 150;
            counter +=150;
        } else {
            HP1 = ceil(round(HP1 * 1.1 * 100) / 100);
            checkTask2(HP1, EXP1, M1);
            M1 = M1 - 70;
            counter +=70;
        }
        if (counter > ahalf) {goto end;}
        //2.2
        if (EXP1 < 400) {
            M1 = M1 - 200;
            counter += 200;
        } else {
            M1 = M1 - 120;
            counter += 120;
        }
        //EXP tang 13%
        EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
        checkTask2(HP1, EXP1, M1);
        if (counter > ahalf) {goto end;}
        //2.3
        if (EXP1 < 300) {
            M1 = M1 - 100;
            counter += 100;
        } else {
            M1 = M1 - 120;
            counter += 120;
        }
        //EXP giam 10%
        EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
        checkTask2(HP1, EXP1, M1);
        if (counter > ahalf) {goto end;}
        goto again;
    } else { //option2
        //2.1
        if (M1 <= 0) {
            M1 = 0;
            goto end;
        }
        if (HP1 < 200) {
            HP1 = ceil(round(HP1 * 1.3 * 100) / 100);
            checkTask2(HP1, EXP1, M1);
            M1 = M1 - 150;
        } else {
            HP1 = ceil(round(HP1 * 1.1 * 100) / 100);
            checkTask2(HP1, EXP1, M1);
            M1 = M1 - 70;
        }
        if (M1 <= 0) {
            M1 = 0;
            goto end;
        }
        //2.2
        if (EXP1 < 400) {
            M1 = M1 - 200;
        } else {
            M1 = M1 - 120;
        }
        //EXP tang 13%
        EXP1 = ceil(round(EXP1 * 1.13 * 100) / 100);
        checkTask2(HP1, EXP1, M1);
        if (M1 <= 0) {
            M1 = 0;
            goto end;
        }
        //2.3
        if (EXP1 < 300) {
            M1 = M1 - 100;
        } else {
            M1 = M1 - 120;
        }
        //EXP giam 10%
        EXP1 = ceil(round(EXP1 * 0.9 * 100) / 100);
        checkTask2(HP1, EXP1, M1);
        if (M1 <= 0) {
            M1 = 0;
            goto end;
        }
    }
    end:
        HP1 = ceil(round(HP1 * 0.83 * 100) / 100);
        EXP1 = ceil(round(EXP1 * 1.17 * 100) / 100);
        checkTask2(HP1, EXP1, M1);
        int l = nearestPerfectSquare(EXP1);
        double p2 = 0;
        double tam2 = EXP1;
        if (EXP1 >= l) {
            p2 = 1;
        } else {
            p2 = (tam2/l + 80)/123.0;
        }

    //third way
    double* proba = new double[10];
    proba[0] = 0.32;
    proba[1] = 0.47;
    proba[2] = 0.28;
    proba[3] = 0.79;
    proba[4] = 1;
    proba[5] = 0.5;
    proba[6] = 0.22;
    proba[7] = 0.83;
    proba[8] = 0.64;
    proba[9] = 0.11;
    int pi = getPi(E2);
    double p3 = proba[pi];

    if (p1 == 1 && p2 == 1 && p3 == 1) {
        EXP1 = ceil(round(EXP1 * 0.75 * 100) / 100);
        checkTask2(HP1, EXP1, M1);
    } else {
        double p = (p1 + p2 + p3)/3.0;
        if (p < 0.5)
        {
            HP1 = ceil(round(HP1 * 0.85 * 100) / 100);
            EXP1 = ceil(round(EXP1 * 1.15 * 100) / 100);
            checkTask2(HP1, EXP1, M1);
        }
        else
        {
            HP1 = ceil(round(HP1 * 0.9 * 100) / 100);
            EXP1 = ceil(round(EXP1 * 1.2 * 100) / 100);
            checkTask2(HP1, EXP1, M1);
        }
    }

    checkTask2(HP1, EXP1, M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    
    if (!checkE(E3))
    {
        return -99;
    }
    checkTask3(HP1, EXP1, HP2, EXP2);
    int matrix[10][10];


    for (int i = 0; i < 10; ++i) {
        // Loop through each column in the current row
        for (int j = 0; j < 10; ++j) {
            matrix[i][j] = 0; // Set the value to zero
        }
    }

    int i = 0;
    int j = 0;
    // Tính điểm số của taxi tại mỗi điểm trong ma trận
    for (int h = 0; h < 10; ++h) {
        for (int k = 0; k < 10; ++k) {
            matrix[h][k] = ((E3 * k) + (h * 2)) * (h - k);
            if (matrix[h][k] > E3 * 2) {
                i++;
            }
            if (matrix[h][k] < -E3) {
                j++;
            }
        }
    }

    // Tính tổng các chữ số của i
    while (i >= 10) {
        i = sumDigits(i);
    }

    // Tính tổng các chữ số của j
    while (j >= 10) {
        j = sumDigits(j);
    }

    //Tim maxvalue
    int max = matrix[i][j];

    int x = i;
    int y = j;

    // len phai
    while (x > 0 && y < 9) {
        x--;
        y++;
        if (matrix[x][y] > max) {
            max = matrix[x][y];
        }
    }

    //Xuong phai
    x = i;
    y = j;
    while (x < 9 && y < 9) {
        x++;
        y++;
        if (matrix[x][y] > max) {
            max = matrix[x][y];
        }
    }

    //Len trai
    x = i;
    y = j;
    while (x > 0 && y > 0) {
        x--;
        y--;
        if (matrix[x][y] > max) {
            max = matrix[x][y];
        }
    }
    //Xuong trai
    x = i;
    y = j;
    while (x < 9 && y > 0) {
        x++;
        y--;
        if (matrix[x][y] > max) {
            max = matrix[x][y];
        }
    }

    if (max < 0) {
        max = abs(max);
    }

    int value_return;

    if (abs(matrix[i][j]) > max) {
        EXP1 = ceil((EXP1 * 88) / 100.0);
        EXP2 = ceil((EXP2 * 88) / 100.0);
        HP1 = ceil((HP1 * 90) / 100.0);
        HP2 = ceil((HP2 * 90) / 100.0);
        value_return = matrix[i][j];
    } else {
        EXP1 = ceil((EXP1 * 112) / 100.0);
        EXP2 = ceil((EXP2 * 112) / 100.0);
        HP1 = ceil((HP1 * 110) / 100.0);
        HP2 = ceil((HP2 * 110) / 100.0);
        value_return = max;
    }

    checkTask3(HP1, EXP1, HP2, EXP2);

    return value_return;
}

// Task 4
int checkPassword(const char *s, const char *email) {
    // 1. Check password length
    int passwordLength = strlen(s);
    if (passwordLength < 8) {
        return -1; // Password length less than 8
    } else if (passwordLength > 20) {
        return -2; // Password length greater than 20
    }

    // 2. Check for forbidden substring "se"
    const char *forbiddenSubstring = findForbiddenSubstring(email);
    const char *forbiddenSubstringPos = strstr(s, forbiddenSubstring);
    if (forbiddenSubstringPos != nullptr) {
        return -(300 + (forbiddenSubstringPos - s)); // Position of forbidden substring
    }

    // 3. Check for more than 2 consecutive characters
    for (int i = 0; i < passwordLength - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); // Position of first occurrence of more than 2 consecutive characters
        }
    }

    // 4. Check for at least one special character
    bool hasSpecialChar = false;
    const char *specialChars = "@#%$!";
    for (int i = 0; i < passwordLength; ++i) {
        if (strchr(specialChars, s[i]) != nullptr) {
            hasSpecialChar = true;
            break;
        }
    }
    if (!hasSpecialChar) {
        return -5; // No special character present
    }

    // 5. Có ký tự nằm ngoài vùng
    int i = 0;
    while (s[i] != '\0') {
        if (!((s[i] >= '0' && s[i] <= '9') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'))) {
            // Nếu ký tự không thuộc các loại ký tự cho phép
            return i; // Trả về vị trí của ký tự đầu tiên vi phạm
        }
        i++;
    }
    // If all conditions are satisfied, return -10 for valid password
    return -10;
}

// Task 5
struct PasswordInfo {
    const char *password;
    int count;
    int length;
};

int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // Tạo một mảng để lưu thông tin về mật khẩu
    PasswordInfo passwords[num_pwds];

    // Khởi tạo thông tin cho mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        passwords[i].password = arr_pwds[i];
        passwords[i].count = 0;
        passwords[i].length = strlen(arr_pwds[i]);
    }

    // Đếm số lần xuất hiện của mỗi mật khẩu
    for (int i = 0; i < num_pwds; ++i) {
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(passwords[i].password, arr_pwds[j]) == 0) {
                passwords[i].count++;
            }
        }
    }

    // Tìm mật khẩu có số lần xuất hiện nhiều nhất và có độ dài lớn nhất
    const char *most_common_password = nullptr;
    int max_count = 0;
    int max_length = 0;
    for (int i = 0; i < num_pwds; ++i) {
        if (passwords[i].count > max_count || (passwords[i].count == max_count && passwords[i].length > max_length)) {
            most_common_password = passwords[i].password;
            max_count = passwords[i].count;
            max_length = passwords[i].length;
        }
    }

    // Tìm vị trí đầu tiên của mật khẩu xuất hiện nhiều nhất trong mảng
    for (int i = 0; i < num_pwds; ++i) {
        if (strcmp(arr_pwds[i], most_common_password) == 0) {
            return i;
        }
    }
    return 0;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
