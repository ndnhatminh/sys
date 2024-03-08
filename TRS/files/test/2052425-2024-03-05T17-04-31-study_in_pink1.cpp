  #include "study_in_pink1.h"

  bool readFile(const string &filename, int &HP1, int &HP2, int &EXP1, int &EXP2,
                int &M1, int &M2, int &E1, int &E2, int &E3) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
      ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
      return true;
    } else {
      cerr << "The file is not found" << endl;
      return false;
    }
  }

  ////////////////////////////////////////////////////////////////////////
  /// STUDENT'S ANSWER BEGINS HERE
  /// Complete the following functions
  /// DO NOT modify any parameters in the functions.
  ////////////////////////////////////////////////////////////////////////
  int clampHP(int &HP) { return max(0, min(HP, 666)); }
  int clampEXP(int &EXP) { return max(0, min(EXP, 600)); }
  int clampM(int &M) { return max(0, min(M, 3000)); }
  int nearest_square(int &num) {return pow(round((sqrt(num))), 2);}
  int div_ceil(int n, int d) { return n / d + (((n < 0) ^ (d > 0)) && (n % d)); }
  int getLastDigit(int num){
    string strnum = to_string(num);
    if (strnum.length() == 1) {
      return (strnum[0] - '0');
    } else {
      int sum = 0;
      for (int i = 0; i < 2; i++) {
        sum += strnum[i]-'0';
      }
      return sum%10;
    }
  }

int left_max(int arr[10][10], int row, int col) {
        int lmax = 0;
        if (row < 0 || col < 0 || row >= 10 || col >= 10){
          return lmax;
        }
        lmax = arr[row][col];
        int row_increment = row;
        int col_increment = col;
        while (row_increment >= 0 && col_increment >= 0){
          lmax = max(lmax, arr[row_increment][col_increment]);
          row_increment--; col_increment--;
        }
        row_increment = row;
        col_increment = col;
        while (row_increment < 10 && col_increment < 10){
          lmax = max(lmax, arr[row_increment][col_increment]);
          row_increment++; col_increment++;
        }
        return lmax;
      }
int right_max(int arr[10][10], int row, int col) {
        int rmax = 0;
        if (row < 0 || col < 0 || row >= 10 || col >= 10){
          return rmax;
        }
        rmax = arr[row][col];
        int row_increment = row;
        int col_increment = col;
        while (row_increment >= 0 && col_increment < 10){
          rmax = max(rmax, arr[row_increment][col_increment]);
          row_increment--; col_increment++;
        }
        row_increment = row;
        col_increment = col;
        while (row_increment < 10 && col_increment >= 0){
          rmax = max(rmax, arr[row_increment][col_increment]);
          row_increment++; col_increment--;
        }
        return rmax;
      }
  void printt(int HP1,int EXP1, int M1){
        cout << "EXP1: " << EXP1 << ", HP1: " << HP1<< ", M1: " << M1 << endl;
  }
  // Task 1
  int firstMeet(int &exp1, int &exp2, int e1) {
    // TODO: Complete this function
    if (e1 > 99 || e1 < 0) {
      return -99;
    }
    exp1 = clampEXP(exp1);
    exp2 = clampEXP(exp2);
    if (e1 <= 3) {
      switch (e1) {
      case 0:
        exp2 += 29;
        exp2 = clampEXP(exp2);
        break;
      case 1:
        exp2 += 45;
        exp2 = clampEXP(exp2);
        break;
      case 2:
        exp2 += 75;
        exp2 = clampEXP(exp2);
        break;
      case 3:
        exp2 += (29 + 45 + 75);
        exp2 = clampEXP(exp2);
        break;
      }
      int d = 3 * e1 + 7 * exp1;
      if (d % 2 == 0) {
        exp1 = (exp1 + div_ceil(d, 200));
        exp1 = clampEXP(exp1);
      } else {
        exp1 = (exp1 + div_ceil(-d, 100));
        exp1 = clampEXP(exp1);
      }
      return (int)exp1 + exp2;
    }
    if (e1 < 20) {
      exp2 = (exp2 + div_ceil(e1, 4) + 19);
      exp2 = clampEXP(exp2);
    } else if (e1 < 50) {
      exp2 = (exp2 + div_ceil(e1, 9) + 21);
      exp2 = clampEXP(exp2);
    } else if (e1 < 66) {
      exp2 = (exp2 + div_ceil(e1, 16) + 17);
      exp2 = clampEXP(exp2);
    } else if (e1 < 80) {
      exp2 = (exp2 + div_ceil(e1, 4) + 19);
      exp2 = clampEXP(exp2);
      exp2 = (exp2 > 200) ? exp2 = (exp2 + div_ceil(e1, 9) + 21) : exp2;
      exp2 = clampEXP(exp2);
    } else {
      exp2 = (exp2 + div_ceil(e1, 4) + 19);
      exp2 = clampEXP(exp2);
      exp2 = (exp2 + div_ceil(e1, 9) + 21);
      exp2 = clampEXP(exp2);
      exp2 = (exp2 > 400) ? exp2 = ceil(float(((exp2 + div_ceil(e1, 16) + 17) * 1.15)))
                          : exp2;
      exp2 = clampEXP(exp2);
    }
    exp1 = exp1 - e1;
    exp1 = clampEXP(exp1);
    return exp1 + exp2;
  }
  // Task 2
  int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0) {
      return -99;
    }
    HP1 = clampHP(HP1);
    EXP1 = clampEXP(EXP1);
    M1 = clampM(M1);
    int starting_money = div_ceil(M1,2);
    int S1 = nearest_square(EXP1);
    double P1 = 100.00;
    if (EXP1 < S1) {
      P1 = ((float)(EXP1 / S1 + 80)) / 123;
    }
    restart:
      M1 -= (HP1 < 200) ? 150 : 70;
      M1 = clampM(M1);
      HP1 = (HP1 < 200) ? static_cast<int>(ceil((float)(float(HP1)*1.3))) 
                        : static_cast<int>(ceil((float)(float(HP1)*1.1)));
      HP1 = clampHP(HP1);
      if (((E2 % 2 == 0) && (M1 == 0))||((E2%2 != 0 )&&(M1 < starting_money))) {
        goto end;
      }

      M1 -= (EXP1 < 400) ? 200 : 120;
      M1 = clampM(M1);
      EXP1 += static_cast<int>(ceil((float)(float(EXP1) * 0.13)));
      EXP1 = clampEXP(EXP1);
      if (((E2 % 2 == 0) && (M1 == 0))||((E2%2 != 0 )&&(M1 < starting_money))) {
        goto end;
      }

      M1 -= (EXP1 < 300) ? 100 :120;
      M1 = clampM(M1);
      EXP1 += static_cast<int>(ceil(-(float)(float(EXP1) * 0.1)));
      EXP1 = clampEXP(EXP1);
      if (((E2 % 2 == 0) && (M1 == 0))||((E2%2 != 0 )&&(M1 < starting_money))) {
        goto end;
      }
      if ((E2 % 2 == 0)){
        goto end;
      }
      goto restart;

    end:
 
    HP1 = static_cast<int>(ceil((float)(float(HP1) * (1-.17))));
    HP1 = clampHP(HP1);
    EXP1 += static_cast<int>(ceil((float)(float(EXP1) * 0.17)));
    EXP1 = clampEXP(EXP1);
 
    int S2 = nearest_square(EXP1);
    float P2 = 100;
    if (EXP1 < S2) {
      P2 = float(EXP1 / S2 + 80) / 123;
    }

    int p_arr[10]{32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    string E2_str = to_string(E2);
    int P3 = 0;
    if (E2_str.length() == 1) {
      P3 = p_arr[E2];
    } else {
      int sum = 0;
      for (int i = 0; i < 2; i++) {
        sum += E2_str[i]-'0';
      }
      P3 = p_arr[sum%10];
    }
    auto mean_P = (float)(P1*100+ P2*100 + P3) / 3;
    if (P1 == 100 && P2 == 100 && P3 == 100) {
      EXP1 += static_cast<int>(ceil((float)-(float(EXP1) * 0.25)));
      EXP1 = clampEXP(EXP1);
    }
    else {
      if (mean_P < 50) {
      HP1 = static_cast<int>(ceil((float)(float(HP1) * (1-0.15))));
      HP1 = clampHP(HP1);
      EXP1 += static_cast<int>(ceil((float)(float(EXP1) * 0.15)));
      EXP1 = clampEXP(EXP1);
    } else {
      HP1 = static_cast<int>(ceil((float)(float(HP1) * (1-0.1))));
      HP1 = clampHP(HP1);
      EXP1 += static_cast<int>(ceil((float)(float(EXP1) * 0.2)));
      EXP1 = clampEXP(EXP1);
    }
 
    }
    return HP1 + EXP1 + M1;
  }

  // Task 3
  int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    // TODO: Complete this function
    if (E3 > 99 || E3 < 0) {
      return -99;
    }
    HP1 = clampHP(HP1);
    EXP1 = clampEXP(EXP1);
    HP2 = clampHP(HP2);
    EXP2 = clampEXP(EXP2);

    const int rows = 10;
    const int cols = 10;
    int i_meet = 0, j_meet = 0; 
    
    int taxi_matrix[rows][cols];
    for (int i = 0; i < rows; i++){
      for (int j = 0; j < cols; j++){
        taxi_matrix[i][j] = ((E3*j)+(i*2))*(i-j);
        i_meet += (taxi_matrix[i][j] > (E3*2)) ? 1 : 0;
        j_meet += (taxi_matrix[i][j] < (-E3)) ? 1 : 0;
      } 
    }
    i_meet = getLastDigit(i_meet);
    j_meet = getLastDigit(j_meet);
    int taxi_score = taxi_matrix[i_meet][j_meet];
    int detect_score = max(left_max(taxi_matrix, i_meet, j_meet),right_max(taxi_matrix, i_meet, j_meet));
    if (abs(taxi_score) > abs(detect_score)){
      HP1 = static_cast<int>(ceil((float)(float(HP1) * (1-0.1))));
      HP1 = clampHP(HP1);
      EXP1 = static_cast<int>(ceil((float)(float(EXP1) * (1-0.12))));
      EXP1 = clampEXP(EXP1);

      HP2 = static_cast<int>(ceil((float)(float(HP2) * (1-0.1))));
      HP2 = clampHP(HP2);
      EXP2 = static_cast<int>(ceil((float)(float(EXP2) * (1-0.12))));
      EXP2 = clampEXP(EXP2);
      return taxi_score;
    }
    else {
      HP1 = static_cast<int>(ceil((float)(float(HP1) * (1+0.1))));
      HP1 = clampHP(HP1);
      EXP1 = static_cast<int>(ceil((float)(float(EXP1) * (1+0.12))));
      EXP1 = clampEXP(EXP1);

      HP2 = static_cast<int>(ceil((float)(float(HP2) * (1+0.1))));
      HP2 = clampHP(HP2);
      EXP2 = static_cast<int>(ceil((float)(float(EXP2) * (1+0.12))));
      EXP2 = clampEXP(EXP2);
      return detect_score;
    }
  }


  // Task 4
  int checkPassword(const char *s, const char *email) {
    // TODO: Complete this function
    string email_str(email);
    string pwd_str(s);
    string delim = "@";
    string se = email_str.substr(0, email_str.find(delim));
    int cei = pwd_str.find(se);
    if (pwd_str.length() < 8 ){
      return -1;
    }
    if (pwd_str.length() > 20){
      return -2;
    }
    if (pwd_str.find(se) != -1){
      return -(300+pwd_str.find(se));
    }
    for (int i = 0; i < pwd_str.length(); i++){
      if (pwd_str[i] == pwd_str[i+1]){
        return -(400+i);
      }
    }
    string special_char = "@#%$!";
    for (int i = 0; i < pwd_str.length(); i++){
      if (special_char.find(pwd_str[i])){
        break;
      }
      return -5;
    }
    for (int i = 0; i < pwd_str.length(); i++){
      if(!((pwd_str[i] >= 'a' && pwd_str[i] <= 'z')|| (pwd_str[i] >= 'A' && pwd_str[i] <= 'Z') || (special_char.find(pwd_str[i])!= string::npos))){
        return i;
      }

    } 
    return -10;
  }
  // Task 5
  int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    int freq_idx = 0;
    int freq_length = 0;
    int freq_frequency = 0;
    for (int i = 0; i < num_pwds; i++){
      int counter = 0;
      for (int j = i + 1; j < num_pwds; j++){
        if (strcmp(arr_pwds[i], arr_pwds[j]) == 0){
          counter++;
        }
      }
      if (counter >= freq_frequency){
        if (counter == freq_frequency){
          if (strlen(arr_pwds[i]) < freq_length)
            continue;
        }
        freq_idx = i;
        freq_length = strlen(arr_pwds[i]);
        freq_frequency = counter;
      }
    }

    return freq_idx;
  }

  ////////////////////////////////////////////////
  /// END OF STUDENT'S ANSWER
  ////////////////////////////////////////////////
