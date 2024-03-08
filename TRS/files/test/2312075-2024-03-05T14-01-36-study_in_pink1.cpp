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

void VoidEXP (int &a) {
   if (a>600){
      a=600;
   }
   else if (a<0) {
      a=0;
   }
}
void VoidHP (int &b) {
   if (b>666){
      b=666;
   }
   else if (b<0) {
      b=0;
   }
}
void VoidM (int &c){
   if (c>3000){
      c=3000;
   }
   else if (c<0){
      c=0;
   }
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
int D;
D = e1*3 + exp1*7;
if ((e1>99) || (e1<0)) {
   return -99;
}
// trường hợp 1
else if ((e1<=3)&&(e1>=0)){
   if (e1 == 1) {
      exp2 = exp2 + 45; 
      VoidEXP(exp2);
      if ((D%2)==0){
         exp1 = ceil((float)exp1 + (float)(D*1.0/200));
         VoidEXP(exp1);
      }
      else {
         exp1 = ceil((float)exp1 - (float)(D*1.0/100));
         VoidEXP(exp1);
      }
   }
   else if (e1 == 2) {
   exp2 = exp2 + 75;
   VoidEXP(exp2);
   if ((D%2)==0){
         exp1 = ceil((float)exp1 + (float)(D*1.0/200));
         VoidEXP(exp1);
      }
      else {
         exp1 = ceil((float)exp1 - (float)(D*1.0/100));
         VoidEXP(exp1);
      }
   }
   else if (e1 == 3) {
   exp2 = exp2 + 29 + 45 + 75;
   VoidEXP(exp2);
   if ((D%2)==0){
         exp1 = ceil((float)exp1 + (float)(D*1.0/200));
         VoidEXP(exp1);
      }
      else {
         exp1 = ceil((float)exp1 - (float)(D*1.0/100));
         VoidEXP(exp1);
      }
   }
   else {
   exp2 = exp2 + 29;
   VoidEXP(exp2);
   if ((D%2)==0){
         exp1 = ceil((float)exp1 + (float)(D*1.0/200));
         VoidEXP(exp1);
      }
      else {
        exp1 = ceil((float)exp1 - (float)(D*1.0/100));
         VoidEXP(exp1);
      }
   }
   return exp1 + exp2;
}
// trường hợp 2
else if (e1>3)
{
   if ((e1>=4)&&(e1<=19)) {
   exp1 = exp1 - e1;
   VoidEXP(exp1);
   exp2 = ceil((float)exp2 + (float)((e1/4.0)+ 19.0));
   VoidEXP(exp2); }
   else if ((e1>=20)&&(e1<=49)) {
   exp1 = exp1 - e1;
   VoidEXP(exp1);
   exp2 = ceil((float)exp2 + (float)((e1/9.0)+ 21.0));
   VoidEXP(exp2); }
else if ((e1>=50)&&(e1<=65))
{
   exp1 = exp1 - e1;
   VoidEXP(exp1);
   exp2 = ceil((float)exp2 + (float)((e1/16.0)+ 17.0));
   VoidEXP(exp2); }
else if ((e1>=66)&&(e1<=79)) {
   exp1 = exp1 - e1;
   VoidEXP(exp1);
   exp2 = ceil((float)exp2 + (float)((e1/4.0)+ 19.0));
   VoidEXP(exp2); 
   if (exp2>200){
      exp2 = ceil((float)exp2 + (float)((e1/9.0)+ 21.0));
   VoidEXP(exp2); } 
   else{
      exp2 = ceil((float) exp2);
      VoidEXP(exp2);
   }
   }
else if ((e1>=80)&&(e1<=99)) {
exp1 = exp1 - e1;
   VoidEXP(exp1);
exp2 = ceil((float)exp2 + (float)((e1/4.0)+ 19.0));
   VoidEXP(exp2);
exp2 = ceil((float)exp2 + (float)((e1/9.0)+ 21.0));
   VoidEXP(exp2);
   if (exp2>400)
   {
     exp2 = ceil((float)exp2 + (float)((e1/16.0)+ 17.0));
   VoidEXP(exp2);
   exp2 = ceil((float) exp2*1.15);
   VoidEXP(exp2);
   }
   

}
return exp1 + exp2;
}

}



//Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    // con đường 1
int S;
float P1, P2, P3;
int x = sqrt(EXP1);
if ((E2<0)||(E2>99)){
   return -99;
}
if (x*x == EXP1) {
   S = EXP1;
}
else if (x*x != EXP1){
   int head = (x)*(x), back = ((x+1)*(x+1));
   int cantim = abs(back - EXP1);
   int cxvay = abs(head - EXP1);
   if (cantim < cxvay){
      S = back;
   }
   if (cantim > cxvay){
      S = head;
   }
}
if (EXP1 >= S){
   P1 = 1;
} 
else if (EXP1 < S) {
   P1 = (float)((((float)EXP1/S)+80.0)/123.0);
}   

// con đường 2    
   int usedMoney = 0;
   float fee = 0.5*M1;
 if ((E2%2) != 0 ){
    while 
    (usedMoney<fee)
    {
      if (HP1<200){
         HP1 = ceil((float)((float)HP1 + (float)HP1*(30.0/100.0)));
         VoidHP(HP1);
         M1 = M1 - 150;
         VoidM(M1);
         usedMoney = usedMoney + 150;
         if (usedMoney>fee)
         {
            break;
         }
         }
      else if (HP1>= 200){
         HP1 = ceil((float)((float)HP1 + (float)HP1*(10.0/100.0)));
         VoidHP(HP1);
         M1 = M1 - 70;
         VoidM(M1);
         usedMoney = usedMoney + 70;
         if (usedMoney>fee)
         {
            break;
         }
         }
      if (EXP1 < 400){
         EXP1 = ceil((float)((float)EXP1 + (float)EXP1*(13.0/100.0)));
         VoidEXP(EXP1);
         M1 = M1 - 200;
         VoidM(M1);
         usedMoney = usedMoney + 200;
         if (usedMoney>fee)
         {
            break;
         }
}
      else if (EXP1>=400){
         EXP1 = ceil((float)((float)EXP1 + (float)EXP1*(13.0/100.0)));
         VoidEXP(EXP1);
         M1= M1-120;
         VoidM(M1);
         usedMoney = usedMoney + 120;
         if (usedMoney>fee)
         {
            break;
         }
      }
      if (EXP1>=300)
    {
      EXP1 = ceil((float)((float)EXP1 - (float)EXP1*(10.0/100.0)));
      VoidEXP(EXP1);
      M1 = M1 - 120;
      VoidM(M1);
      usedMoney = usedMoney + 120;
         if (usedMoney>fee)
         {
            break;
         }
    }
      else if (EXP1<300) {
      EXP1 = ceil((float)((float)EXP1 - (float)EXP1*(10.0/100.0)));
      VoidEXP(EXP1);
      M1 = M1 - 100;
      VoidM(M1);
      usedMoney = usedMoney + 100;
        if (usedMoney>fee){
         break;
        }
    }
   }
   }
   if ((E2%2) == 0)
   {
      while 
       (M1 != 0)
      {
         if (HP1<200){
         HP1 =ceil((float)((float)HP1 +(float)HP1*(30.0/100.0)));
         VoidHP(HP1);
         M1 = M1 - 150;
         VoidM(M1);
         if (M1 == 0){
            break;
            }
      }
         else if (HP1>= 200){
         HP1 = ceil((float)((float)HP1 + (float)HP1*(10.0/100.0)));
         VoidHP(HP1);
         M1 = M1 - 70;
         VoidM(M1);
         if (M1 == 0){
            break;
            }
            }
         if (EXP1 < 400){
         EXP1 = ceil((float)((float)EXP1 + (float)EXP1*(13.0/100.0)));
         VoidEXP(EXP1);
         M1 = M1 - 200;
         VoidM(M1);
         if (M1 == 0){
            break;
           }
      }
         else if (EXP1>=400){
         EXP1 = ceil((float)((float)EXP1 + (float)EXP1*(13.0/100.0)));
         VoidEXP(EXP1);
         M1= M1-120;
         VoidM(M1);
         if (M1 == 0){
            break;
         }
    }
         if (EXP1>=300)
    {
      EXP1 = ceil((float)((float)EXP1 - (float)EXP1*(10.0/100.0)));
      VoidEXP(EXP1);
      M1 = M1 - 120;
      VoidM(M1);
      if (M1 == 0){
            break;
           }
    }
         else if (EXP1<300){
      EXP1 = ceil((float)((float)EXP1 - (float)EXP1*(10.0/100.0)));
      VoidEXP(EXP1);
      M1 = M1 - 100;
      VoidM(M1);
      if (M1 == 0){
            break;
            }
         }
     break; }
   }
EXP1 = ceil((float)((float)EXP1 + (float)EXP1*(17.0/100.0)));
VoidEXP(EXP1);
HP1 = ceil((float)((float)HP1 - (float)HP1*(17.0/100.0)));
VoidHP(HP1);
int y = sqrt(EXP1);
if (y*y == EXP1) {
   S = EXP1;
}
else if (y*y != EXP1){
   int head2 = (y)*(y), back2 = (y+1)*(y+1);
   int cantim2 = abs(back2 - EXP1);
   int cxvay2 = abs(head2 - EXP1);
   if (cantim2 < cxvay2){
      S = back2;
   }
   if (cantim2 > cxvay2){
      S = head2;
   }
}
if (EXP1 >= S)
{
   P2 = 1;
} 
else if (EXP1 < S) {
   P2 = (float)((((float)EXP1/S)+80.0)/123.0);
}   

// con đường 3
int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
 if ((E2<=9)&&(E2>=0)){
        P3 = P[E2];
    }
    else if (E2>=10) {
        int sum = E2/10 + E2%10;
        int i;
        if (sum >= 10){
            i = sum % 10;
            P3 = P[i];
        }
        else if ((sum>=0)&&(sum<=9)){
            i = sum;
            P3 = P[i];
        }
    }
float tbc = (float)(((float)P1 + (float)P2 + (float)(P3/100.0))/3.0);
if (tbc == 1) {
   EXP1 = ceil((float)((float)EXP1 - (float)EXP1*(25.0/100.0)));
    VoidEXP(EXP1);   
}
if ((tbc >= 0.5)&&(tbc<1)){
   EXP1 = ceil((float)((float)EXP1 + (float)EXP1*(20.0/100.0)));
    VoidEXP(EXP1); 
   HP1 = ceil((float)((float)HP1 - (float)HP1*(10.0/100.0)));
    VoidHP(HP1);
}
if ((tbc < 0.5)&&(tbc>0)){
   EXP1 = ceil(((float)EXP1 + (float)EXP1*(15.0/100.0)));
    VoidEXP(EXP1); 
   HP1 = ceil(((float)HP1 - (float)HP1*(15.0/100.0)));
    VoidHP(HP1);
}
  return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
    // Kiểm tra giá trị của E3
    if (E3 < 0 || E3 > 99) {
        return -99;
    }

    // Khai báo hằng số size cho kích thước ma trận
    const int size = 10;
    // Khởi tạo ma trận 10x10 cho taxi
    int taxi[size][size];
    // Điểm số của taxi tại mỗi vị trí
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            taxi[i][j] = ((E3*j) + (i*2)) * (i-j);
        }
    }
    // Khởi tạo ma trận 10x10 cho Sherlock và Watson
    int sw[size][size];
    // Điểm số của họ tại mỗi vị trí
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            // Tìm giá trị lớn nhất ở đường chéo trái và phải của taxi tại vị trí (i, j)
            int max_left = taxi[i][j];
            int max_right = taxi[i][j];
            // Đường chéo trái
            int x = i;
            int y = j;
            while (x >= 0 && y >= 0) {
                if (taxi[x][y] > max_left) {
                    max_left = taxi[x][y];
                }
                x--;
                y--;
            }
            x = i + 1;
            y = j + 1;
            while (x < size && y < size) {
                if (taxi[x][y] > max_left) {
                    max_left = taxi[x][y];
                }
                x++;
                y++;
            }
            // Đường chéo phải
            x = i;
            y = j;
            while (x >= 0 && y < size) {
                if (taxi[x][y] > max_right) {
                    max_right = taxi[x][y];
                }
                x--;
                y++;
            }
            x = i + 1;
            y = j - 1;
            while (x < size && y >= 0) {
                if (taxi[x][y] > max_right) {
                    max_right = taxi[x][y];
                }
                x++;
                y--;
            }
            // Lấy giá trị lớn nhất và lấy giá trị tuyệt đối
            sw[i][j] = max(max_left, max_right);
            if (sw[i][j] < 0) {
                sw[i][j] = abs(sw[i][j]);
            }
        }
    }
    // Tìm vị trí gặp nhau của taxi và Sherlock và Watson
    int i, j;
    // Số giá trị dương trong ma trận taxi lớn hơn E3 * 2
    int count = 0;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (taxi[x][y] > E3 * 2) {
                count++;
            }
        }
    }
    // Tính i
    i = 0;
    while (count > 0) {
        i += count % 10;
        count /= 10;
    }
    while (i > 9) {
        i = i / 10 + i % 10;
    }
    // Số giá trị âm trong ma trận taxi nhỏ hơn -E3
    count = 0;
    for (int x = 0; x < size; x++) {
        for (int y = 0; y < size; y++) {
            if (taxi[x][y] < -E3) {
                count++;
            }
        }
    }
    // Tính j
    j = 0;
    while (count > 0) {
        j += count % 10;
        count /= 10;
    }
    while (j > 9) {
        j = j/10 + j%10;
    }
    // Kiểm tra xem có đuổi kịp taxi hay không
    bool catch_up = false;
    if (abs(taxi[i][j]) <= sw[i][j]) {
        catch_up = true;
    }
    if (catch_up) {
        int result = sw[i][j];
        EXP1 = ceil((float) EXP1 * 1.12);
        VoidEXP(EXP1); 
        HP1 = ceil((float)HP1 +(float)HP1*(10.0/100.0));
        VoidHP(HP1);
        EXP2 = ceil((float) EXP2 * 1.12);
        VoidEXP(EXP2);
        HP2 = ceil((float) HP2 * 1.1);
        VoidHP(HP2);
        return result;
    } else {
        int result = taxi[i][j];
        EXP1 = ceil((float) EXP1 * 0.88);
        VoidEXP(EXP1); 
        HP1 = ceil((float) HP1 * 0.9);
        VoidHP(HP1);
        EXP2 = ceil((float) EXP2 * 0.88); 
        VoidEXP(EXP2);
        HP2 = ceil((float) HP2 * 0.9);
        VoidHP(HP2);
        return result;
    }
}



// Task 4
// Hàm kiểm tra mật khẩu
int checkPassword(const char *s, const char *email) {
    // Tìm chuỗi se
    // above là số lượng kí tự trước '@'
    int above = 0;
    while (email[above] != '@') {
        above++;
    }
    char se[100]; 
    // chép số lượng kí tự email vào se 
    for (int i = 0; i < above; i++) {
        se[i] = email[i];
    }

    // Kiểm tra độ dài của mật khẩu
    int length = strlen(s); // dùng hàm strlen để lấy độ dài của chuỗi
    if (length < 8) {
        return -1;
    }
    if (length > 20) {
        return -2; 
    }

    // Kiểm tra các ký tự đặc biệt trong mật khẩu
    bool ktdb = false; // có ký tự đặc biệt hay không
    int same = 1; // số lượng ký tự liên tiếp và giống nhau
    char prev = s[0]; // ký tự trước đó
    for (int i = 0; i < length; i++) {
        char c = s[i]; // ký tự hiện tại
        // Kiểm tra xem c có phải là chữ cái thường, chữ cái in hoa hay ký tự đặc biệt
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!' || c == '^' || c == '*' || c == '+' || c == ',' || c == '-' || c == '.' || c == '/' || c == ':' || c == ';' || c == '<' || c == '=' || c == '>' || c == '?' || c == '[' || c == '\\' || c == ']' || c == '_' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~' || c == '\'' || c == '\"' || c == '(' || c == ')') { // thêm các ký tự đặc biệt còn thiếu
            if (c == '@' || c == '#' || c == '%' || c == '$' || c == '!' || c == '^' || c == '*' || c == '+' || c == ',' || c == '-' || c == '.' || c == '/' || c == ':' || c == ';' || c == '<' || c == '=' || c == '>' || c == '?' || c == '[' || c == '\\' || c == ']' || c == '_' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~' || c == '\'' || c == '\"' || c == '(' || c == ')') { // thêm các ký tự đặc biệt còn thiếu
                ktdb = true;
            }
            if (c == prev) {
                same++;
            } 
            else { 
                same = 1;
                prev = c;
            }
            if (same > 2) {
                return -(400 + i); 
            }
        }
        else {
            return i; 
        }
    }
    // Kiểm tra xem mật khẩu có chứa se hay không
    for (int i = 0; i < length - above + 1; i++) {
        bool match = true; // kiểm tra mk có chứa se hay không
        for (int j = 0; j < above; j++) {
            if (s[i + j] != se[j]) {
                match = false; 
                break;
            }
        }
        if (match) {
            return -(300 + i);
        }
    }
    if (!ktdb) {
        return -5;
    }
    return -10;
}


// Task 5
 //TO DO FUNCTION
int findCorrectPassword(const char *arr_pwds[], int num_pwds) {
    int tansuat[30] = {0}; // Mảng để lưu số lần xuất hiện của mỗi mật khẩu
    int maxcount = 0; //số lần xuất hiện cao nhất
    int maxlenght = 0; // độ dài lớn nhất
    int mkdung = -1;
    
    for (int i = 0; i < num_pwds; i++) {
        int count = 0;
        int lenght = strlen(arr_pwds[i]);

        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                count++;
            }
        }

        if (count > maxcount || (count == maxcount && lenght > maxlenght)) {
            maxcount = count;
            maxlenght = lenght;
            mkdung = i;
        }
    }
    
    return mkdung;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////