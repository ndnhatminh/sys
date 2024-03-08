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
// Task 1
//Tạo hàm giống hàm ceil
int round_up(float num) {
    int int_num = static_cast<int>(num);
    if (num - int_num > 0) {
        return int_num + 1;
    } else {
        return int_num;
    }
}

int firstMeet(int & exp1, int & exp2, int e1)
{
    if (e1 >= 0 && e1 <= 3) {
        exp1 = max(0, min(600, exp1));
        exp2 = max(0, min(600, exp2));
        switch (e1) {
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
                exp2 += 29 + 45 + 75;
                break;
        }
        exp1 = max(0, min(600, exp1));
        exp2 = max(0, min(600, exp2));
        int D = e1 * 3 + exp1 * 7;
        float m = 0;
        if (D % 2 == 0) {
            m = exp1 + static_cast<float>(D) / 200;
            exp1 = round_up(m);
        }
        else {
            m = exp1 - static_cast<float>(D) / 100;
            exp1 = round_up(m);
        }
    }
    else if (e1 >= 4 && e1 <= 99) {
        float n = 0;
        exp1 = max(0, min(600, exp1));
        exp2 = max(0, min(600, exp2));
        if (e1 >= 4 && e1 <= 19) {
            n = exp2 + e1 / 4.0 + 19;
            exp2 = round_up(n);
        }
        else if (e1 >= 20 && e1 <= 49) {
            n = exp2 + e1 / 9.0 + 21;
            exp2 = round_up(n);
        }
        else if (e1 >= 50 && e1 <= 65) {
            n = exp2 + e1 / 16.0 + 17;
            exp2 = round_up(n);
        }
        else if (e1 >= 66 && e1 <= 79) {
            n = exp2 + e1 / 4.0 + 19;
            exp2 = round_up(n);
            if (exp2 > 200) {
                n = exp2 + e1 / 9.0 + 21;
                exp2 = round_up(n);
            }
        }
        else {
            n = exp2 + e1/4.0 + 19;
            exp2 = round_up(n);
            n = exp2 + e1/9.0 + 21;
            exp2 = round_up(n);

            //exp2 > 400 Sherlock gthich thong tin 3
            if (exp2 > 400){
                n = (exp2 + e1/16.0 + 17);
                exp2 = round_up(n);
                exp2 = round_up(exp2 * 1.15);
            }
        }
        //exp 1 bi giam
        exp1 = exp1 - e1;
    }
    else {
        return -99;
    }

    exp1 = max(0, min(600, exp1));
    exp2 = max(0, min(600, exp2));

    return exp1 + exp2;
    return -1;
}



// Task 2
int closest(int num) {
    int below_num = sqrt(num);
    int above_num = below_num + 1;
    if (abs(num - below_num * below_num) < abs(num - above_num * above_num)) {
        return below_num * below_num;
    } else {
        return above_num * above_num;
    }
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2)
{
    if (E2 < 0 || E2 > 99) {
        return -99;
    }
    HP1 = max(0, min(666, HP1));
    EXP1 = max(0, min(600, EXP1));
    M1 = max(0, min(3000, M1));
    // Con đường 01
    // Tính số chính phương gần EXP1 nhất
    int S = closest(EXP1);
    double P1;
    if (EXP1 >= S) {
        P1 = 1.0;
    } else {
        P1 = ((EXP1 * 1.0) / S + 80) / 123.0;
    }

        // Con đường 02
        if (E2 % 2 != 0) {
            double M_half = M1 * 0.5;
            int M_sum = 0;
            while (true) {
                if (M1 == 0)
                    break;
                // Sự kiện 1
                if (HP1 < 200) {
                    HP1 = round_up(HP1 * 1.3);
                    M_sum += 150;
                } else {
                    HP1 = round_up(HP1 * 1.1);
                    M_sum += 70;
                }
                HP1 = max(0, min(666, HP1));
                if (M_sum > M_half)
                    break;


                EXP1 = max(0, min(600, EXP1));
                M1 = max(0, min(3000, M1));
                // Sự kiện 2
                if (EXP1 < 400) {
                    M_sum += 200;
                } else {
                    M_sum += 120;
                }
                EXP1 = round_up(EXP1 * 1.13);

                EXP1 = max(0, min(600, EXP1));
                M1 = max(0, min(3000, M1));
                if (M_sum > M_half)
                    break;

                EXP1 = max(0, min(600, EXP1));
                M1 = max(0, min(3000, M1));
                // Sự kiện 3
                if (EXP1 < 300) {
                    M_sum += 100;
                } else {
                    M_sum += 120;
                }
                EXP1 = round_up(EXP1 * 0.9);
                if (M_sum > M_half)
                    break;
            }
            M1 -= M_sum;
            HP1 = round_up(HP1 * 0.83);
            EXP1 = round_up(EXP1 * 1.17);
        } else {
            // Trong trường hợp E2 là số chẵn
            int M_sum = 0;
            int count = 0;
            while (count != 1 && M1 > 0) {
                // Sự kiện 1

                if (HP1 < 200) {
                    HP1 = round_up(HP1 * 1.3);
                    M_sum += 150;
                } else {
                    HP1 = round_up(HP1 * 1.1);
                    M_sum += 70;
                }
                M1 -= M_sum;
                HP1 = max(0, min(666, HP1));
                if (M1 < 0) {
                    M1 = 0;
                    break;
                }

                EXP1 = max(0, min(600, EXP1));
                M1 = max(0, min(3000, M1));
                // Sự kiện 2
                int M_event2;
                if (EXP1 < 400) {
                    M_event2 = 200;
                } else {
                    M_event2 = 120;
                }
                EXP1 = round_up(EXP1 * 1.13);
                M_sum += M_event2;
                M1 -= M_event2;

                EXP1 = max(0, min(600, EXP1));
                M1 = max(0, min(3000, M1));

                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }

                EXP1 = max(0, min(600, EXP1));
                M1 = max(0, min(3000, M1));
                // Sự kiện 3
                int M_event3;
                if (EXP1 < 300) {
                    M_event3 = 100;
                } else {
                    M_event3 = 120;
                }
                EXP1 = round_up(EXP1 * 0.9);
                M_sum += M_event3;
                M1 -= M_event3;

                HP1 = max(0, min(666, HP1));
                EXP1 = max(0, min(600, EXP1));
                M1 = max(0, min(3000, M1));
                if (M1 <= 0) {
                    M1 = 0;
                    break;
                }
                count += 1;
            }
            HP1 = round_up(HP1 * 0.83);
            EXP1 = round_up(EXP1 * 1.17);
        }

    HP1 = max(0, min(666, HP1));
    EXP1 = max(0, min(600, EXP1));
    M1 = max(0, min(3000, M1));

    // Tính xác suất P2 tìm thấy hành lý trên con đường 02
    int S2 = closest(EXP1);
    double P2;
    if (EXP1 >= S2) {
        P2 = 1.0;
    } else {
        P2 = ((EXP1 * 1.0) / S2 + 80) / 123.0;
    }

    // Tính xác suất P3 tìm thấy hành lý trên con đường 03
    int P_array[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if (E2 < 10) {
        i = E2;
    } else {
        int sum = E2 / 10 + E2 % 10;
        i = sum % 10;
    }
    double P3 = static_cast<double>(P_array[i]) / 100.0;

    // Kiểm tra xác suất trên từng con đường
    double P_mean = (P1 + P2 + P3) / 3.0;
    if (P_mean == 1.0) {
        // Nếu cả 3 con đường đều có xác suất 100%, Sherlock đã nhầm lẫn
        EXP1 = round_up(EXP1 * 0.75); // Giảm kinh nghiệm 25%
    } else {
        // Tính xác suất trung bình
        if (P_mean < 0.5) {
            HP1 = round_up(HP1 * 0.85); // Giảm sức khoẻ 15%
            EXP1 = round_up(EXP1 * 1.15); // Tăng kinh nghiệm 15%
        } else {
            HP1 = round_up(HP1 * 0.9); // Giảm sức khoẻ 10%
            EXP1 = round_up(EXP1 * 1.2); // Tăng kinh nghiệm 20%
        }
    }
    HP1 = max(0, min(666, HP1));
    EXP1 = max(0, min(600, EXP1));
    M1 = max(0, min(3000, M1));
    return HP1 + EXP1 + M1;
}

// Task 3

//Tạo hàm cộng hai chữ số
int digital_sum(int n)
{
	int sum = 0;
	while(n > 0 || sum > 9)
	{
		if(n == 0)
		{
			n = sum;
			sum = 0;
		}
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    // Khởi tạo ma trận và tính toán điểm số tại từng vị trí
    const int rows = 10, columns = 10;
    int matrix[rows][columns];
    int count_pos = 0, count_neg = 0;

    for (int u = 0; u < rows; u++) {
        for (int v = 0; v < columns; v++) {
            matrix[u][v] = ((E3 * v) + (u * 2)) * (u - v);
            if (matrix[u][v] > 0 && matrix[u][v] > (E3*2)) {
                count_pos++;
            }
            else if (matrix[u][v] < 0 && matrix[u][v] < (-E3)) {
                count_neg++;
            }
        }
    }

    // Tìm (i,j)
    int i = digital_sum(count_pos);
    int j = digital_sum(count_neg);

    // Tìm giá trị tại điểm gặp
    int pos_score = matrix[i][j];

    // Tìm giá trị lớn nhất ở hai đường chéo
    int max_score = pos_score;

    for(int k = 0; k < 10; k++){
        if (i - k < 0 || j - k < 0){
            break;
        }
        if (matrix[i-k][j-k] > max_score){
            max_score = matrix[i-k][j-k];
        }
    }

    for(int k = 0; k < 10; k++){
        if (i + k > 9 || j + k > 9){
            break;
        }
        if (matrix[i+k][j+k] > max_score){
            max_score = matrix[i+k][j+k];
        }
    }

    for(int k = 0; k < 10; k++){
        if (i - k < 0 || j + k > 9){
            break;
        }
        if (matrix[i-k][j+k] > max_score){
            max_score = matrix[i-k][j+k];
        }
    }

    for(int k = 0; k < 10; k++){
        if (i + k > 9 || j - k < 0){
            break;
        }
        if (matrix[i+k][j-k] > max_score){
            max_score = matrix[i+k][j-k];
        }
    }

    // Đảm bảo các giá trị HP và EXP nằm trong phạm vi cho phép lần 1
    HP1 = max(0, min(666, HP1));
    EXP1 = max(0, min(600, EXP1));
    HP2 = max(0, min(666, HP2));
    EXP2 = max(0, min(600, EXP2));
    // So sánh pos_score và max_score
    if (abs(pos_score) > max_score){
        EXP1 = round_up(EXP1*0.88);
        HP1 = round_up(HP1*0.9);
        EXP2 = round_up(EXP2*0.88);
        HP2 = round_up(HP2*0.9);
        HP1 = max(0, min(666, HP1));
        EXP1 = max(0, min(600, EXP1));
        HP2 = max(0, min(666, HP2));
        EXP2 = max(0, min(600, EXP2));
        return pos_score;
    } else {
        EXP1 = round_up(EXP1*1.12);
        HP1 = round_up(HP1*1.1);
        EXP2 = round_up(EXP2*1.12);
        HP2 = round_up(HP2*1.1);
        HP1 = max(0, min(666, HP1));
        EXP1 = max(0, min(600, EXP1));
        HP2 = max(0, min(666, HP2));
        EXP2 = max(0, min(600, EXP2));
        return max_score;
    }


    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    // Tách chuỗi ở dấu "@"
    string email_str(email);
    string se;
     for (char ch : email_str) {
        if (ch == '@') {
            break;
        }
        se += ch;
    }

    //Kiểm tra độ dài tối đa, tối thiểu
    string s_str(s);
    int len_s = s_str.length();

    if (len_s < 8){
        return -1;
    }
    else if (len_s > 20){
        return -2;
    }

    //Kiểm tra s có chứa se
    size_t sei = s_str.find(se);
    if (sei != string::npos) {
        return -(300 + sei);
    }

    //Kiểm tra s có chứa hơn 2 ký tự liên tiếp và giống nhau
    for (size_t i = 0; i < len_s - 2; i++){
        if (s_str[i] == s_str[i+1] && s_str[i] == s_str[i+2]){
            return -(400 + i);
        }
    }

    //Kiểm tra s có chứa kí tự đặc biệt
    string spec_char = "@#%$!";
    bool has_spec = false;
    for (char ch : s_str) {
        if (spec_char.find(ch) != string::npos) {
            has_spec = true;
            break;
        }
    }
    if (!has_spec)
        return -5;

    // Trường hợp còn lại, trả về vị trí của ký tự đầu tiên vi phạm yêu cầu hợp lệ
    bool isValid = true;

    for (size_t i = 0; i < len_s; ++i) {
        if (!isalnum(s[i]) && s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!') {
            return i;
        }
    }

    // Mật khẩu hợp lệ
    if (isValid) return -10;

    return -99;
}

// Task 5
//Tính độ dài string char
int calculate_len_s(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
//So sánh 2 strings
int compare_2_str(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }
    return str1[i] == '\0' && str2[i] == '\0';
}
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int max_count = 0, max_len = 0;
    int index_return = 0;

    for (int i = 0; i < num_pwds; i++) {
        const char* temp_pwd = arr_pwds[i];
        int temp_len = calculate_len_s(temp_pwd);

        // Kiểm tra xem mật khẩu temp
        bool checked = false;
        for (int j = 0; j < i; j++) {
            if (compare_2_str(arr_pwds[j], temp_pwd)) {
                checked = true;
                break;
            }
        }

        if (checked) {
            continue;
        }
        //Kiểm tra từng mật khẩu trùng với mật khẩu hiện tại
        //Có thì +1 count_pwds
        int count_pwds = 0;
        for (int j = i; j < num_pwds; j++) {
            if (compare_2_str(arr_pwds[j], temp_pwd)) {
                count_pwds++;
            }
        }
        //Kiểm tra phải mật khẩu xuất hiện 1st không
        if ((count_pwds == max_count && temp_len > max_len) || count_pwds > max_count ) {
            max_count = count_pwds;
            max_len = temp_len;
            index_return = i;
        }
    }
    return index_return;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
