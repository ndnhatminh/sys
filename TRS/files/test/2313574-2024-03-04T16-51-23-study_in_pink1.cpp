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


//! Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    // TH1
     if (E1 < 0 || E1 > 99) return -99;
     else if (E1 >= 0 && E1 <= 3){
        if (E1 == 0)
            EXP2 += 29;
        else if (E1 == 1)
            EXP2 += 45;
        else if (E1 == 2)
            EXP2 +=75;
        else if (E1 == 3)
            EXP2 = EXP2 + 29 + 45 + 75;
        int D = E1 * 3 + EXP1 * 7;
        if (D%2 == 0)
            EXP1 = ceil(EXP1 + (double)D/200);
            else
                EXP1 = ceil(EXP1 - (double)D/100);
    }

    // TH2
    else if (E1 >= 4 && E1 <= 99) {
        if (E1 >= 4 && E1 <= 19)
            EXP2 = ceil(EXP2 + E1 / 4.0 + 19);
        else if (E1 >= 20 && E1 <= 49)
            EXP2 = ceil(EXP2 + E1 / 9.0 + 21);
        else if (E1 >= 50 && E1 <= 65)
            EXP2 = ceil(EXP2 + E1 / 16.0 + 17);
        else if (E1 >= 66 && E1 <= 79) {
             EXP2 = ceil(EXP2 + E1 / 4.0 + 19);
            if (EXP2 > 200)
                EXP2 = ceil(EXP2 + E1 / 9.0 + 21);
            else
                EXP2 = ceil(EXP2);
        }
        else if (E1 >= 80 && E1 <= 99) {
            EXP2 = ceil(EXP2 + E1 / 4.0 + 19);
            EXP2 = ceil(EXP2 + E1 / 9.0 + 21);
            if (EXP2 > 400) {
                EXP2 = ceil(EXP2 + E1 / 16.0 + 17);
                EXP2 = ceil(EXP2 * 1.15);
            }
        }
        EXP1 = EXP1 - E1;
    }
    if(EXP1 > 600)
        EXP1 = 600;
    else if (EXP1 < 0)
        EXP1 = 0;
    if (EXP2 > 600)
        EXP2 = 600;
    else if (EXP2 < 0)
        EXP2 = 0;
    
    return EXP1 + EXP2;
}
//! Task 2
bool laSoChinhPhuong(int x) {
  int can = sqrt(x);
  return can * can == x;
}

int soChinhPhuongGanNhat(int n) {
  if (laSoChinhPhuong(n)) {
    return n;
  }
  int tren = n + 1;
  int duoi = n - 1;
  while (true) {
    if (laSoChinhPhuong(tren)) {
      return tren;
    }
    if (laSoChinhPhuong(duoi)) {
      return duoi;
    }
    tren++;
    duoi--;
  }
}

int checkhp(int n){
    n = (n>666) ? 666 : (n<0) ? 0 : n;
    return n;
}

int checkmoney(int n){
    n = (n>3000) ? 3000 : (n<0) ?0 : n;
    return n;
}

int checkexp(int n){
    n = (n > 600) ? 600 : (n<0) ? 0 : n;
    return n;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99) return -99;
    // Road 1
    double P1;
    int s = soChinhPhuongGanNhat(EXP1);
    if (EXP1 >= s)
        P1 = 1;
        else
            P1 = ((float)EXP1/s + 80)/123;
    // Road 2
    int originalM1 = M1; // Số tiền ban đầu
    float N = 0.5 * M1; // 50% số tiền ban đầu
    if (E2 % 2 != 0){
        while (true) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 + 0.3 * HP1);
            M1 -= 150;
        } else {
            HP1 = ceil(HP1 + 0.1 * HP1);
            M1 -= 70;
        }
        HP1 = checkhp(HP1);
        M1 = checkmoney(M1);
        if (M1 < N || M1 <= 0)
            break;
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 = ceil(EXP1 + 0.13 * EXP1);
        } else {
            M1 -= 120;
            EXP1 = ceil(EXP1 + 0.13 * EXP1);
        }
        M1 = checkmoney(M1);
        EXP1 = checkexp(EXP1);
        if (M1 < N || M1 <= 0)
            break;
        int homelessMoney = (EXP1 < 300) ? 100 : 120;
        M1 -= homelessMoney;
        EXP1 = ceil(EXP1 - 0.1 * EXP1);
        M1 = checkmoney(M1);
        EXP1 = checkexp(EXP1);
        if (M1 < N || M1 <= 0)
            break;
    }
    }
        else{
            while (true) {
        if (HP1 < 200) {
            HP1 = ceil(HP1 + 0.3 * HP1);
            M1 -= 150;
        } else {
            HP1 = ceil(HP1 + 0.1 * HP1);
            M1 -= 70;
        }
        HP1 = checkhp(HP1);
        M1 = checkmoney(M1);
        if (M1 <= 0)
            break;
        if (EXP1 < 400) {
            M1 -= 200;
            EXP1 = ceil(EXP1 + 0.13 * EXP1);
        } else {
            M1 -= 120;
            EXP1 = ceil(EXP1 + 0.13 * EXP1);
        }
        M1 = checkmoney(M1);
        EXP1 = checkexp(EXP1);
        if (M1 <= 0)
            break;
        int homelessMoney = (EXP1 < 300) ? 100 : 120;
        M1 -= homelessMoney;
        EXP1 = ceil(EXP1 - 0.1 * EXP1);
        M1 = checkmoney(M1);
        EXP1 = checkexp(EXP1);
        if (M1 <= 0)
            break;
            break;
    }
        }

    // Kết thúc các sự kiện trên con đường 2
    HP1 = ceil(HP1 - 0.17 * HP1);
    EXP1 = ceil(EXP1 + 0.17 * EXP1);
    HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    // Tính xác suất P2
    double P2;
    s = soChinhPhuongGanNhat(EXP1);
    if (EXP1 >= s)
        P2 = 1;
        else
            P2 = ((float)EXP1/s + 80)/123;
    // cout << "hp1: " << hp1 << " exp1: " << exp1 << " p2: " << p2 << " p1: " << p1;

    //road 3
    int p[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 >= 0 && E2 <=9)
        i = E2;
        else{
            int chuc = E2 / 10;
            int donvi = E2 % 10;
            i = (chuc + donvi) % 10;
        }
    float P3 = p[i]/100.0;

    // tong ket
    if (P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = ceil(EXP1 - 0.25*EXP1);
    }
        else{
            float P = (P1 + P2 + P3)/3;
            if (P < 0.5){
                HP1 = ceil(HP1 - 0.15*HP1);
                EXP1 = ceil(EXP1 + 0.15*EXP1);
            }
                else{
                    HP1 = ceil(HP1 - 0.1*HP1);
                    EXP1 = ceil(EXP1 + 0.2*EXP1);
                }
        }
    if(EXP1 > 600)
        EXP1 = 600;
    else if (EXP1 < 0)
        EXP1 = 0;
    if (M1 < 0)
        M1 = 0;
        else if (M1 > 3000)
        M1 = 3000;
    return HP1 + EXP1 + M1;
   // return -1;
}



//! Task 3
int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    if (sum >= 10) {
        return sumOfDigits(sum); // Recursion if sum has more than 1 digit
    }
    return sum;
}

// Function to initialize a 10x10 matrix with all elements initialized to 0
void taoarr(int arr[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[i][j] = 0;
        }
    }
}

// Function to calculate the taxi's score at each position on the map
void diembando(int arr[10][10], int E3) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
        }
    }
}

// Function to calculate the maximum score for Sherlock and Watson at each position on the map
void diemSW(const int taxi[10][10], int SW[10][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int cheotraimax = taxi[i][j];
            int cheophaimax = taxi[i][j];
            for (int k = i + 1, l = j + 1; k < 10 && l < 10; ++k, ++l) {
                if (taxi[k][l] > cheotraimax) {
                    cheotraimax = taxi[k][l];
                }
            }
            for (int k = i + 1, l = j - 1; k < 10 && l >= 0; ++k, --l) {
                if (taxi[k][l] > cheophaimax) {
                    cheophaimax = taxi[k][l];
                }
            }
            SW[i][j] = max(cheotraimax, cheophaimax);
            if (SW[i][j] < 0) {
                SW[i][j] = abs(SW[i][j]);
            }
        }
    }
}

// Function to calculate the meeting position of taxi with Sherlock and Watson
pair<int, int> tinhvtgapnhau(const int taxi[10][10], int E3) {
    int i = 0, j = 0;
    int lon = 0, nho = 0;
    for (int x = 0; x < 10; ++x) {
        for (int y = 0; y < 10; ++y) {
            if (taxi[x][y] > E3 * 2) {
                lon++;
            }
            if (taxi[x][y] < -E3) {
                nho++;
            }
        }
    }
    i = sumOfDigits(lon);
    j = sumOfDigits(nho);
    return make_pair(i, j);
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
     if (E3 < 0 || E3 > 99) return -99;
    //lưu trữ thông tin về điểm số của taxi và điểm số tương ứng của Sherlock và Watson trên bản đồ.
    int taxi[10][10];
    int SW[10][10];
    // khởi tạo ma trận taxiMap với các giá trị ban đầu là 0.
    taoarr(taxi);
    // tính toán điểm số của taxi tại mỗi vị trí trên bản đồ dựa trên mã sự kiện E3.
    diembando(taxi, E3);
    // tính toán điểm số tối đa của Sherlock và Watson tại mỗi vị trí trên bản đồ dựa trên điểm số của taxi.
    diemSW(taxi, SW);
    // tính toán vị trí gặp nhau của taxi với Sherlock và Watson trên bản đồ.
    pair<int, int> vtgapnhau = tinhvtgapnhau(taxi, E3);
    // điểm số của taxi và điểm số tối đa của Sherlock và Watson tại vị trí gặp nhau từ các ma trận đã tính toán.
    int diemtaxi = taxi[vtgapnhau.first][vtgapnhau.second];
    int diemSWmax = SW[vtgapnhau.first][vtgapnhau.second];
    
    if (abs(diemtaxi) > diemSWmax) {
        HP1 = ceilf(HP1*0.9); HP1 = checkhp(HP1);
        EXP1 = ceilf(EXP1*0.88); EXP1 = checkexp(EXP1);
        HP2 = ceilf(HP2*0.9); HP2 = checkhp(HP2);
        EXP2 = ceilf(EXP2*0.88); EXP2 = checkexp(EXP2);
        return diemtaxi;
    } else {
        HP1 = ceilf(HP1*1.1); HP1 = checkhp(HP1);
        EXP1 = ceilf(EXP1*1.12); EXP1 = checkexp(EXP1);
        HP2 = ceilf(HP2*1.1); HP2 = checkhp(HP2);
        EXP2 = ceilf(EXP2*1.12); EXP2 = checkexp(EXP2);
        return diemSWmax;
    }
    /*HP1 = checkhp(HP1);
    EXP1 = checkexp(EXP1);
    HP2 = checkhp(HP2);
    EXP2 = checkexp(EXP2); */
    
}

//! Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //find se part in the email
    string se = email;
    se = se.substr(0, se.find('@'));

    // Kiểm tra độ dài của mật khẩu
    int length = strlen(s);
    if (length < 8) return -1; // Quá ngắn
    if (length > 20) return -2; // Quá dài

    // Kiểm tra xem mật khẩu có chứa se hay không
    const char *pos = strstr(s, se.c_str());
    if (pos != nullptr) return -(300 + (pos - s)); // Có chứa se

    // Kiểm tra xem mật khẩu có chứa nhiều hơn 2 ký tự liên tiếp và giống nhau hay không
    for (int i = 0; i < length - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + i); // Có chứa
    }

    // Kiểm tra xem mật khẩu có chứa ít nhất 1 ký tự đặc biệt hay không
    bool hasSpecial = false;
    const char *special = "@#$!"; // Các ký tự đặc biệt cho phép
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (strchr(special, c) != nullptr) {
            hasSpecial = true; // Có chứa
            break;
        }
    }
    if (!hasSpecial) return -5; // Không chứa

    // Kiểm tra xem mỗi ký tự trong mật khẩu có phải là chữ số, chữ cái thường, chữ cái in hoa, hay ký tự đặc biệt hay không
    for (int i = 0; i < length; i++) {
        char c = s[i];
        if (!isdigit(c) && !islower(c) && !isupper(c) && strchr(special, c) == nullptr) {
            return i; // Không phải
        }
    }

    // Nếu mật khẩu thỏa mãn tất cả các điều kiện, trả về -10
    return -10;

}

//! Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_count = 0;
  int max_length = 0;
  int correct_index = -1;

  // Duyệt qua mảng các mật khẩu
  for (int i = 0; i < num_pwds; i++) {
    // Lấy mật khẩu hiện tại
    string pwd = arr_pwds[i];

    // Đếm số lần xuất hiện của mật khẩu hiện tại trong mảng
    int count = 0;
    for (int j = 0; j < num_pwds; j++) {
      if (arr_pwds[j] == pwd) {
        count++;
      }
    }

    // Nếu số lần xuất hiện của mật khẩu hiện tại lớn hơn số lần xuất hiện của mật khẩu đúng
    // hoặc bằng nhưng độ dài lớn hơn
    if (count > max_count || (count == max_count && pwd.length() > max_length)) {
      // Cập nhật số lần xuất hiện, độ dài, và vị trí của mật khẩu đúng
      max_count = count;
      max_length = pwd.length();
      correct_index = i;
    }
  }

  // Trả về vị trí của mật khẩu đúng
  return correct_index; 
    
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////