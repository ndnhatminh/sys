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
void checkHp(int & HP)
{
    if (HP>666)
    {
        HP=666;
    }
    if (HP<0)
    {
        HP=0;
    }
}


int up(double  a) {
    if (abs(a-int(a)) <= 10E-10) 
    return int (a);
    else 
    return int(a)+1;
}
void checkUp (int & EXP)
{   
    if (EXP > 600)
    {
        EXP=600;
    }
    if (EXP<0)
    {
        EXP=0;
    }
    
}

// Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    // TODO: Complete this function
    
  


    if (E1 < 0 || E1 > 99) return -99;

    
    if (E1 >=0 && E1<=3)

    { 
    switch (E1)
    {
    case 0:
        EXP2+=29;
        break;
    case 1:
        EXP2+=45;
        break;
    case 2:
        EXP2+=75;
        break;
    case 3:
        EXP2+=29+45+75;
        break;
    }
    int D = E1*3+EXP1*7;
    if (D%2==0)
    {
        EXP1=up(EXP1 + (D/200.0));
        
    }
    else if (D%2==1)
    {
        EXP1= up( EXP1 - (D/100.0));
    }
    
    }
    else if (E1>=4 && E1<=99)
    {
        if (E1>=4 && E1<=19)
        {
            EXP2+=up((E1/4.0) + 19);
        }
        else if (E1>=20 && E1<=49)
        {
            EXP2+=up((E1/9.0) + 21);
        }
        else if (E1>=50 && E1<=65)
        {
            EXP2+=up((E1/16.0) + 17);
        }
        else if (E1>=66 && E1<=79)
        {
            EXP2+=up((E1/4.0) + 19);
            if (EXP2<200 )
              {
                
              }
            else if (EXP2>200)
            {
                EXP2+=up((E1/9.0) + 21);
            }
            
              
        }
        else if (E1>=80 && E1<=99)
        {
            EXP2+=up((E1/4.0) + 19);
            EXP2+=up((E1/9.0) + 21);
            if (EXP2<400)
            {
                
            }
            else if (EXP2>400)
            {
                EXP2+=up((E1/16.0) + 17);
                EXP2+=up( EXP2*(15.0/100));
            }
            
        }
        EXP1 -=  E1;
        
        
        
    }
    checkUp(EXP1);
    checkUp(EXP2);
    
    return EXP1 + EXP2;
    
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    int b=M1;
   
    float P1, P2, P3;
    if (E2 < 0 || E2 > 99) {
        return -99;
    }

    
    // Road 01
    int c = round( sqrt(EXP1));
    if (EXP1>=c*c) P1 = 1;
    else P1 = (EXP1/(c*c) + 80)/123.0;

    // Road 02
    if (E2%2 == 1) {
        int  event = 2;
        while (M1 >= 0.5*b) {
            switch (event = ++event % 3) {
                case 0: // event 1
                    if (HP1 < 200) {
                        HP1 = up(HP1*1.30);
                        M1 -= 150;
                        
                    }
                    else 
                    
                    {
                        HP1 = up(HP1*1.10);
                        M1 -= 70;
                        
                    }
                     
                    if (HP1 > 666) 
                    {HP1 = 666;
                    }
                    if (M1 < 0) 
                    {M1 = 0;
                    }
                    break;

                case 1: // event 2
                    if (EXP1 < 400) {
                        M1 -= 200;
                      
                    }
                    else {
                        M1 -= 120;
                      
                    }
                    EXP1 = up(EXP1*1.13);
                    if (M1 < 0) M1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                    break;

                case 2: // event 3
                    if (EXP1 < 300) {
                        M1 -= 100;
                   
                    }
                    else {
                        M1 -= 120;
                      
                    }
                    EXP1 = up(EXP1*0.9);
                    if (M1 < 0) 
                    {M1 = 0;
                    }
            }
        }
    }

    else {
        int event = 0;
        do {
            switch (event++) {
                case 0: // event 1
                    if (HP1 < 200) {
                        HP1 = up(HP1*1.30);
                        M1 -= 150;
                    }
                    else {
                        HP1 = up(HP1*1.10);
                        M1 -= 70;
                    }
                    if (HP1 > 666) {HP1 = 666;}
                    if (M1 < 0) {M1 = 0;}
                    break;

                case 1: // event 2
                    if (EXP1 < 400) {M1 -= 200;}
                    else {M1 -= 120;}
                    EXP1 = up(EXP1*1.13);
                    if (M1 < 0) M1 = 0;
                    if (EXP1 > 600) EXP1 = 600;
                    break;

                case 2: // event 3
                    if (EXP1 < 300) {M1 -= 100;}
                    else {M1 -= 120;}
                    EXP1 = up(EXP1*0.9);
                    if (M1 < 0) {M1 = 0;}
            }
        }
        while (event != 3 && M1 != 0);
    }

    HP1 = up(HP1*0.83);
    EXP1 = up(EXP1*1.17);
    if (EXP1 > 600) EXP1 = 600;

    c = round( sqrt(EXP1));
    if (EXP1>=c*c) P2 = 1;
    else P2 =(EXP1/(c*c) + 80)/123.0;

 
    int i;
    i = (E2/10 + E2%10)%10;
    double PV[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    P3 = PV[i]*0.01;

  
    if (P1 == 1 && P2 == 1 && P3 == 1) 
    {EXP1 = up(EXP1*0.75);
    }
    else {
        double P = (P1 + P2 + P3)/3;
        if (P < 0.5) {
            HP1 = up(HP1*0.85);
            EXP1 = up(EXP1*1.15);
        }
        else {
            HP1 = up(HP1*0.90);
            EXP1 = up(EXP1*1.20);
        }
    }
    if (EXP1 > 600) 
    {EXP1 = 600;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
   {
    if (E3 < 0 || E3 > 99)
    {
        return -99;
    }
    int matrix[10][10] = {0};
    int iPosition = 0;
    int jPosition = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            matrix[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (matrix[i][j] > E3 * 2)
            {
                iPosition++;
            }
            if (matrix[i][j] < -E3)
            {
                jPosition++;
            }
        }
    }
    // find position (i,j)
    while (iPosition >= 10)
    {
        iPosition = iPosition % 10 + iPosition / 10;
    }
    while (jPosition >= 10)
    {
        jPosition = jPosition % 10 + jPosition / 10;
    }
    int taxiPoint = matrix[iPosition][jPosition];

    /// START find Sherlock and Watson point
    int point = matrix[iPosition][jPosition];
    // to top left
    for (int c = jPosition - 1, r = iPosition - 1; c > 0 && r > 0; c--, r--)
    {
        if (matrix[r][c] > point)
        {
            point = abs(matrix[r][c]);
        }
    }
    // to top right
    for (int c = jPosition + 1, r = iPosition - 1; c < 10 && r > 0; c++, r--)
    {
        if (matrix[r][c] > point)
        {
            point = abs(matrix[r][c]);
        }
    }
    // to bottom left
    for (int c = jPosition - 1, r = iPosition + 1; c > 0 && r < 10; c--, r++)
    {
        if (matrix[r][c] > point)
        {
            point = abs(matrix[r][c]);
        }
    }
    // to bottom right
    for (int c = jPosition + 1, r = iPosition + 1; c < 10 && r < 10; c++, r++)
    {
        if (matrix[r][c] > point)
        {
            point = abs(matrix[r][c]);
        }
    }
    /// END find Sherlock and Watson point

    if (abs(taxiPoint) > point)
    {
        EXP1 = up(EXP1 * 0.88);
        HP1 = up(HP1 * 0.9);
        EXP2 = up(EXP2 * 0.88);
        HP2 = up(HP2 * 0.9);
    }
    else
    {
        EXP1 = up(EXP1 * 1.12);
        HP1 = up(HP1 * 1.10);
        EXP2 = up(EXP2 * 1.12);
        HP2 = up(HP2 * 1.10);
    }
    checkUp(EXP1);
    checkUp(EXP2);
    return abs(taxiPoint) > point ? taxiPoint : point;
}


}

// Task 4
bool containsSpecialCharacter(const string& password) {
    const string specialChars = "@#%$!";
    for (char ch : password) {
        if (specialChars.find(ch) != string::npos) {
            return true;
        }
    }
    return false;
}

// Hàm kiểm tra chuỗi ký tự liên tiếp
bool containsSequentialChars(const string& password, int& position) {
    for (size_t i = 0; i < password.length() - 2; ++i) {
        if (password[i] == password[i + 1] && password[i + 1] == password[i + 2]) {
            position = i;
            return true;
        }
    }
    return false;
}

// Hàm kiểm tra mật khẩu
int checkPassword(const char* s, const char* email) {
    string password = s;
    string emailStr = email;
    size_t atPos = emailStr.find('@');
    string se = emailStr.substr(0, atPos);

    // Kiểm tra độ dài của mật khẩu
    if (password.length() < 8) return -1;
    if (password.length() > 20) return -2;

    // Kiểm tra sự xuất hiện của se trong mật khẩu
    size_t foundSe = password.find(se);
    if (foundSe != string::npos) return -(300 + foundSe);
    // Kiểm tra chuỗi ký tự liên tiếp
    int seqCharPosition;
    if (containsSequentialChars(password, seqCharPosition)) return -(400 + seqCharPosition);


    // Kiểm tra ký tự đặc biệt
    if (!containsSpecialCharacter(password)) return -5;

  
    // Kiểm tra mỗi ký tự trong mật khẩu
    for (size_t i = 0; i < password.length(); ++i) {
        char ch = password[i];
        if (!isalnum(ch) && ch != '@' && ch != '#' && ch != '%' && ch != '$' && ch != '!') {
            return i ; // Trả về vị trí của ký tự vi phạm
        }
    }

    // Nếu tất cả điều kiện đều được thỏa mãn
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

 
     int max_index = 0; // Vị trí của mật khẩu đúng hiện tại
    int max_count = 0; // Số lần xuất hiện của mật khẩu đúng hiện tại
    int max_length = 0; // Độ dài của mật khẩu đúng hiện tại

    for (int i = 0; i < num_pwds; ++i) {
        std::string current_password = arr_pwds[i];
        int current_count = 0; // Số lần xuất hiện của mật khẩu hiện tại
        int current_length = current_password.size(); // Độ dài của mật khẩu hiện tại

        // Đếm số lần xuất hiện của mật khẩu hiện tại
        for (int j = 0; j < num_pwds; ++j) {
            if (arr_pwds[j] == current_password) {
                current_count++;
            }
        }

        // Kiểm tra xem mật khẩu hiện tại có phải là mật khẩu đúng không
        if ((current_count > max_count) || (current_count == max_count && current_length > max_length)) {
            max_index = i;
            max_count = current_count;
            max_length = current_length;
        }
    }

    return max_index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////