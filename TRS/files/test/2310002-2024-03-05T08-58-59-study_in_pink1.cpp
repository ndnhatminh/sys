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
// hàm làm tròn thành số nguyên và tăng 1 đơn vị
int roundUp(double num)
{
    int roundedNum;
    if (num < 0)
    {
        num = 0;
        roundedNum = static_cast<int>(num);
        return roundedNum;
    }
    else
    {
        roundedNum = static_cast<int>(num);
        if ((num - roundedNum) > 0.0000000001)
        {
            return ++roundedNum;
        }
        else
        {
            return roundedNum;
        }
    }
}
// hàm giới hạn giá trị
int limit(int value, int min, int max)
{
    int newValue = value;
    // kiểm tra nếu value nhỏ hơn minValue, thì gán value bằng giá trị minValue
    if (newValue < min)
    {
        newValue = min;
    }
    // nếu không thì kiểm tra nếu value lớn hơn maxValue, thì gán value bằng giá trị maxValue
    else if (newValue > max)
    {
        newValue = max;
    }

    return newValue;
}

int limitHP(int HP)
{
    return limit(HP, 0, 666); // HP trong đoạn từ 0 đến 666
}

int limitEXP(int EXP)
{
    return limit(EXP, 0, 600); // EXP trong đoạn từ 0 đến 600
}

int limitM(int M)
{
    return limit(M, 0, 3000); // M trong đoạn từ 0 đến 3000
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    const int expCase1Info1 = 29;
    const int expCase1Info2 = 45;
    const int expCase1Info3 = 75;
    const int expCase1Info4 = expCase1Info1 + expCase1Info2 + expCase1Info3;

    // Trường hợp 1:
    // Thay đổi exp2 dựa vào các trường hợp của e1
    if (e1 >= 0 && e1 <= 3)
    {
        // Đảm bảo exp1 và exp2 nằm trong đoạn cho phép
        exp1 = limitEXP(exp1);
        exp2 = limitEXP(exp2);

        int exp2Update = 0;
        switch (e1)
        {
        case 0:
            exp2Update = expCase1Info1;
            break;
        case 1:
            exp2Update = expCase1Info2;
            break;
        case 2:
            exp2Update = expCase1Info3;
            break;
        case 3:
            exp2Update = expCase1Info1 + expCase1Info2 + expCase1Info3;
            break;
        default:
            return -99; // sự kiện không hợp lệ
        }

        exp2 += exp2Update;    // Cập nhật exp2 theo từng trường hợp
        exp2 = limitEXP(exp2); // Giới hạn exp2 nếu nằm ngoài đoạn cho phép

        // tính D:
        int D = e1 * 3 + exp1 * 7; // Do D là số nguyên
        double DTemp = D;          // Nên phải đổi D về giá trị thực để tính toán
        if (D % 2 == 0)
        {
            exp1 = limitEXP(roundUp(exp1 + DTemp / 200.0)); // D là số chẵn, Sherlock chọn Afghanistan(chọn đúng)
        }
        else
        {
            exp1 = limitEXP(roundUp(exp1 - DTemp / 100.0)); // D là số lẻ, Sherlock chọn Iraq (chọn sai)
        }

        return exp1 + exp2;
    }

    // Trường hợp 2:
    else if (e1 >= 4 && e1 <= 99)
    {
        // Đảm bảo exp1 và exp2 nằm trong đoạn cho phép
        exp1 = limitEXP(exp1);
        exp2 = limitEXP(exp2);

        double exp2Update = 0;

        // thông tin 1
        if (e1 >= 4 && e1 <= 19)
        {
            exp2Update = (e1 / 4.0 + 19);
            exp2 = limitEXP(roundUp(exp2 + exp2Update));
        }
        // thông tin 2
        else if (e1 >= 20 && e1 <= 49)
        {
            exp2Update = (e1 / 9.0 + 21);
            exp2 = limitEXP(roundUp(exp2 + exp2Update));
        }
        // thông tin 3
        else if (e1 >= 50 && e1 <= 65)
        {
            exp2Update = (e1 / 16.0 + 17);
            exp2 = limitEXP(roundUp(exp2 + exp2Update));
        }
        // thông tin 4
        else if (e1 >= 66 && e1 <= 79)
        {
            exp2Update = (e1 / 4.0 + 19);
            exp2 = limitEXP(roundUp(exp2 + exp2Update));
            if (exp2 > 200)
            {
                exp2Update = (e1 / 9.0 + 21);
                exp2 = limitEXP(roundUp(exp2 + exp2Update));
            }
        }
        // thông tin 5
        else if (e1 >= 80 && e1 <= 99)
        {
            exp2Update = (e1 / 4.0 + 19);
            exp2 = limitEXP(roundUp(exp2 + exp2Update));
            exp2Update = (e1 / 9.0 + 21);
            exp2 = limitEXP(roundUp(exp2 + exp2Update));
            if (exp2 > 400)
            {
                exp2Update = (e1 / 16.0 + 17);
                exp2 = limitEXP(roundUp((exp2 + roundUp(exp2Update)) * 1.15));
            }
        }
        // EXP1 của Sherlock bị giảm đi E1 EXP
        exp1 = limitEXP(exp1 - e1);

        return exp1 + exp2;
    }
    else
    {
        return -99; // Nếu E1 nằm ngoài đoạn [0;99] thì hàm không làm gì và chỉ trả về -99
    }
}

// Task 2

// Hàm tính giá trị tuyệt đối:
double my_abs(double x)
{
    if (x < 0)
    {
        return -x;
    }
    return x;
}

// Hàm tính căn bậc hai:
double my_sqrt(double S)
{
    S = my_abs(S); // chắc chắn rằng S dương
    double x0 = S; // giả định x0 = S
    double x1;

    do
    {
        x1 = 0.5 * (x0 + S / x0); // cập nhật giá trị của x0 cho lần lặp tiếp theo
        x0 = x1;
    } while (my_abs(x1 * x1 - S) > 0.0001); // điều kiện dừng khi đạt độ chính xác mong muốn

    return x1;
}

// Hàm tính xác suất P của từng con đường:
double Probability(double EXP)
{
    
    double a = static_cast<int>(my_sqrt(EXP)) * static_cast<int>(my_sqrt(EXP));
    
    double b = (static_cast<int>(my_sqrt(EXP)) + 1) * (static_cast<int>(my_sqrt(EXP)) + 1);

    int S;
    if ((EXP - a) <= (b - EXP)) 
    {
        S = a; 
    }
    else 
    {
        S = b; 
    }

    // Tính P:
    double P;
    if (EXP >= S)
    {
        P = 1; // xác suất P = 100%
    }
    else
    {
        P = (EXP / S + 80) / 123; // nếu không thì P được tính theo công thức sẵn
    }

    return P;
}

// hàm tính giá trị i:
int caculateI(int event)
{
    int i;
    // nếu E2 là số một chữ số thì gán i = E2
    if (event < 10)
    {
        i = event;
    }
    // nếu E2 là số có hai chữ số thì cộng hai số hàng đơn vị lại và lấy hàng đơn vị của kết quả tống đó gán vào i
    else
    {
        i = (event / 10 + event % 10) % 10;
    }
    return i;
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    // TODO: Complete this function

    // Đảm bảo E2 nằm trong đoạn cho phép
    if (E2 < 0 || E2 > 99)
    {
        return -99; // Giá trị không hợp lệ
    }
    // Nếu giá trị E2 hợp lệ thì tiếp tục thực hiện như bình thường
    else
    {
        // Đảm bảo từ đầu HP1, EXP1 và M1 nằm trong mỗi đoạn giá trị cho phép
        HP1 = limitHP(HP1);
        EXP1 = limitEXP(EXP1);
        M1 = limitM(M1);

        // con đường 01:

        // số chính phương: k = a^2, trong đó a nguyên
        double exp1 = EXP1;            
        double P1 = Probability(exp1); // Tính P1

        // con đường 02:

        // Gán giá trị của các biến nguyên đầu vào cho các biến thực để tính toán:
        double hp1 = HP1;      // HP1 của Sherlock
        double m1 = M1;        // M1 thực tế
        double m1Initial = M1; // M1 ban đầu
        double m1Used = 0;     // M1 đã dùng

        // Nếu ngay từ lúc đầu M1 = 0 thì Sherlock sẽ không làm gì cả và chuyển sang con đường 03
        if (M1 == 0)
        {
            hp1 = limitHP(roundUp(hp1 * 0.83));    // hp1 giảm 17%
            exp1 = limitEXP(roundUp(exp1 * 1.17)); // exp1 tăng 17%
        }
        // Nếu không thì thực hiện như bình thường
        else
        {
            // Trường hợp 1: Nếu E2 lẻ thì:
            if (E2 % 2 == 1)
            {
                // Vào vòng lặp để xử lý:
                for (int i = 0; i < 500; i++)
                {
                    // Giai đoạn 1:
                    // Nếu hp1 < 200 thì Sherlock sẽ chọn mua thức ăn và nước uống:
                    if (hp1 < 200)
                    {
                        m1 -= 150; // Sherlock tiêu 150
                        // Nếu tiền thực tế sau câu lệnh trên không là số dương
                        if (m1 <= 0)
                        {
                            // Thì Sherlock sẽ thực hiện nốt hành động này rồi thoát ra khỏi vòng lặp
                            hp1 = limitHP(roundUp(hp1 * 1.3)); // hp1 tăng lên 30%
                            break;
                        }
                        m1Used += 150;                     // Tiền sử dụng là 150
                        hp1 = limitHP(roundUp(hp1 * 1.3)); // hp1 tăng lên 30%

                        // nếu số tiền đã dùng lớn hơn 50% tiền ban đầu thì Sherlock sẽ không tiêu tiền trong đoạn đường 02 còn lại
                        if (m1Used > 0.5 * m1Initial)
                        {
                            break;// Thoát ra khỏi vòng lặp và chuyển sang con đường 03
                        }
                    }
                    // Nếu không thì hp1 không nhỏ hơn 200 thì Sherlock sẽ chọn mua nước uống:
                    else if (hp1 >= 200)
                    {
                        m1 -= 70; // Tiền thực tế giảm 70
                        // Nếu tiền thực tế sau câu lệnh trên không là số dương
                        if (m1 <= 0)
                        {
                            // Thì Sherlock sẽ thực hiện nốt hành động này rồi thoát ra khỏi vòng lặp
                            hp1 = limitHP(roundUp(hp1 * 1.1)); 
                            break;
                        }
                        m1Used += 70;                      
                        hp1 = limitHP(roundUp(hp1 * 1.1)); 
                        // nếu số tiền đã dùng lớn hơn 50% tiền ban đầu thì Sherlock sẽ không tiêu tiền trong đoạn đường 02 còn lại
                        if (m1Used > 0.5 * m1Initial)
                        {
                            break;// Thoát ra khỏi vòng lặp và chuyển sang con đường 03
                        }
                    }

                    // Giai đoạn 2:
                    
                    if (exp1 < 400)
                    {
                        m1 -= 200; 
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 1.13)); 
                            break;
                        }
                        m1Used += 200;                        
                        exp1 = limitEXP(roundUp(exp1 * 1.13)); 
                        
                        if (m1Used > 0.5 * m1Initial)
                        {
                            break;
                        }
                    }

                    
                    else if (exp1 >= 400)
                    {
                        m1 -= 120; 
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 1.13)); 
                            break;
                        }
                        m1Used += 120;                         
                        exp1 = limitEXP(roundUp(exp1 * 1.13)); 
                        
                        if (m1Used > 0.5 * m1Initial)
                        {
                            break;
                        }
                    }

                    // Giai đoạn 3:
                    
                    if (exp1 < 300)
                    {
                        m1 -= 100; 
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 0.9)); 
                            break;
                        }
                        m1Used += 100;                        
                        exp1 = limitEXP(roundUp(exp1 * 0.9)); 
                        
                        if (m1Used > 0.5 * m1Initial)
                        {
                            break;
                        }
                    }

                    
                    else if (exp1 >= 300)
                    {
                        m1 -= 120; 
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 0.9)); 
                            break;
                        }
                        m1Used += 120;                        
                        exp1 = limitEXP(roundUp(exp1 * 0.9)); 
                        
                        if (m1Used > 0.5 * m1Initial)
                        {
                            break;
                        }
                    }
                }
            }

            // Trường hợp 2: Nếu không thì E2 là số chẵn thì:
            // Các giai đoạn xảy ra giống trường hợp E2 lẻ nhưng Sherlock chỉ thực hiện 3 giai đoạn 1 lần
            else if (E2 % 2 == 0)
            {
                // Vào vòng lặp 1 lần:
                for (int i = 0; i < 1; i++)
                {
                    // Giai đoạn 1:
                    if (hp1 < 200)
                    {
                        m1 -= 150;
                        
                        if (m1 <= 0)
                        {
                            
                            hp1 = limitHP(roundUp(hp1 * 1.3));
                            break;
                        }
                        m1Used += 150;
                        hp1 = limitHP(roundUp(hp1 * 1.3));
                        
                        if (m1Used > m1Initial)
                        {
                            break;
                        }
                    }
                    else if (hp1 >= 200)
                    {
                        m1 -= 70;
                        
                        if (m1 <= 0)
                        {
                            
                            hp1 = limitHP(roundUp(hp1 * 1.1));
                            break;
                        }
                        m1Used += 70;
                        hp1 = limitHP(roundUp(hp1 * 1.1));
                        
                        if (m1Used > m1Initial)
                        {
                            break;
                        }
                    }

                    // Giai đoạn 2:
                    if (exp1 < 400)
                    {
                        m1 -= 200;
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 1.13));
                            break;
                        }
                        m1Used += 200;
                        exp1 = limitEXP(roundUp(exp1 * 1.13));
                        
                        if (m1Used > m1Initial)
                        {
                            break;
                        }
                    }
                    else if (exp1 >= 400)
                    {
                        m1 -= 120;
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 1.13));
                            break;
                        }
                        m1Used += 120;
                        exp1 = limitEXP(roundUp(exp1 * 1.13));
                        
                        if (m1Used > m1Initial)
                        {
                            break;
                        }
                    }

                    // Giai đoạn 3:
                    if (exp1 < 300)
                    {
                        m1 -= 100;
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 0.9));
                            break;
                        }
                        m1Used += 100;
                        exp1 = limitEXP(roundUp(exp1 * 0.9));
                        
                        if (m1Used > m1Initial)
                        {
                            break;
                        }
                    }
                    else if (exp1 >= 300)
                    {
                        m1 -= 120;
                        
                        if (m1 <= 0)
                        {
                            
                            exp1 = limitEXP(roundUp(exp1 * 0.9));
                            break;
                        }
                        m1Used += 120;
                        exp1 = limitEXP(roundUp(exp1 * 0.9));
                        
                        if (m1Used > m1Initial)
                        {
                            break;
                        }
                    }
                }
            }

            hp1 = limitHP(roundUp(hp1 * 0.83));    
            exp1 = limitEXP(roundUp(exp1 * 1.17)); 
            // Nếu tiền thực tế sau khi trải qua con đường 02 không là số dương
            if (m1 < 0)
            {
                // Thì tiền thực tế sẽ được set về 0
                m1 = limitM(static_cast<int>(m1));
            }
        }

        // Tính xác suất tìm được vali trên con đường 02:
        double P2 = Probability(exp1);

        // con đường 03:
        int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; // Khai báo mảng cố định P gồm 10 phần tử giá trị xác suất
        int i = caculateI(E2);                               // Tính toán i dựa trên E2
        double P3 = static_cast<double>(P[i]) / 100.0;       // Chuyển đổi P[i] thành số thực để đảm bảo P3 thực

        // Nếu ba giá trị xác suất tìm được vali trên mỗi con đường đều bằng 100% thì:
        if (P1 == 1 && P2 == 1 && P3 == 1)
        {
            exp1 = limitEXP(roundUp(exp1 * 0.75)); // Sherlock sẽ phải tính toán lại và bị giảm 25% exp
        }
        // Nếu không thì sẽ tính xác suất cuối cùng tìm được vali của 3 con đường:
        else
        {
            double PSum;               // Giá trị xác suất cuối cùng tìm được vali
            PSum = (P1 + P2 + P3) / 3; // PSum bằng trung bình cộng của 3 giá trị xác suất
            // Nếu xác suất tổng nhỏ hơn 50% thì Sherlock sẽ rất vất vả để tìm được vali:
            if (PSum < 0.5)
            {
                hp1 = limitHP(roundUp(hp1 * 0.85));    // hp1 giảm 15%
                exp1 = limitEXP(roundUp(exp1 * 1.15)); // exp1 tăng 15%
            }
            // Ngược lại nếu giá trị này lớn hơn hoặc bằng 50% thì Sherlock sẽ nhanh chóng tìm được vali:
            else if (PSum >= 0.5)
            {
                hp1 = limitHP(roundUp(hp1 * 0.9));    // hp1 giảm 10%
                exp1 = limitEXP(roundUp(exp1 * 1.2)); // exp1 tăng 20%
            }
        }

        HP1 = hp1;   // trả giá trị hp1 sau khi trải qua 3 tuyến đường về HP1 của Sherlock
        EXP1 = exp1; // trả giá trị exp1 sau khi trải qua 3 tuyến đường về EXP1 của Sherlock
        M1 = m1;     // trả giá trị m1 sau khi trải qua 3 tuyến đường về M1 của Sherlock

        return HP1 + EXP1 + M1;
    }
}

// Task 3

// Hàm tìm số lớn nhất giữa hai số:
int my_max(int a, int b)
{
    int max;
    if (a > b)
    {
        max = a;
    }
    else
    {
        max = b;
    }

    return max;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    // TODO: Complete this function

    // Đảm bảo E3 nằm trong đoạn cho phép
    // Nếu nằm ngoài đoạn giá trị cho phép thì hảm chỉ trả về giá trị -99
    if (E3 < 0 || E3 > 99)
    {
        return -99; // Giá trị không hợp lệ
    }
    // Nếu không thì tiếp tục thực hiện tính toán
    else
    {
        // Đảm bảo từ đầu HP1, EXP1, HP2 và EXP2 nằm trong mỗi đoạn giá trị cho phép
        HP1 = limitHP(HP1);
        EXP1 = limitEXP(EXP1);
        HP2 = limitHP(HP2);
        EXP2 = limitEXP(EXP2);
        // Khởi tạo ma trận 10x10:
        int matrix[10][10] = {0};
        

        // Nhập giá trị vào từng ô của ma trận theo công thức sẵn
        for (int m = 0; m < 10; ++m)
        {
            for (int n = 0; n < 10; ++n)
            {
                matrix[m][n] = ((E3 * n) + (m * 2)) * (m - n);
            }
        }

        // Tìm số giá trị dương trong ma trận lớn hơn (E3 * 2)
        int numPositive = 0; // là số giá trị dương lớn hơn (E3 *2)
        for (int m = 0; m < 10; ++m)
        {
            for (int n = 0; n < 10; ++n)
            {
                // Quét và so sánh giá trị từng ô với (E3 * 2)
                if (matrix[m][n] > (E3 * 2))
                {
                    ++numPositive; // nếu thỏa mãn thì tăng numPositive lên 1
                }
            }
        }

        // Tính i:
        int i; // là số hàng của ô chứa giá trị điểm của Taxi
        // Nếu numPositive là số có ba chữ số, chắc chắn là 100
        if (numPositive == 100)
        {
            // Thì i được tính như sau:
            i = 1 + 0 + 0;
        }
        // Nếu không thì numPositive là số có hai chữ số
        else if (numPositive > 9)
        {
            // Thì i được tính bằng cách cộng hai chữ số hàng chục và đơn vị lại, kết quả ra một số có một chữ số
            // Và gán giá trị đó cho i:
            i = ((numPositive / 10) + (numPositive % 10));
            // Nếu kết quả trên không là số có một chữ số thì
            if (i > 9)
            {
                // Thì i được tính bằng cách cộng tiếp hai chữ số hàng chục và đơn vị lại, kết quả ra một số có một chữ số
                i = ((i / 10) + (i % 10));
            }
        }
        // Nếu không thì numPositive là số có một chữ số
        else
        {
            // Thì i bằng giá trị của numPositive
            i = numPositive;
        }

        // Tìm số giá trị âm trong ma trận nhỏ hơn (-E3)
        int numNegative = 0;
        for (int m = 0; m < 10; ++m)
        {
            for (int n = 0; n < 10; ++n)
            {
                
                if (matrix[m][n] < (-E3))
                {
                    ++numNegative; 
                }
            }
        }

        // Tính j:
        int j; // là số cột của ô chứa giá trị điểm của Taxi
        
        if (numNegative == 100)
        {
            // Thì j được tính như sau:
            j = 1 + 0 + 0;
        }
        
        else if (numNegative > 9)
        {
            
            j = ((numNegative / 10) + (numNegative % 10));
            
            if (j > 9)
            {
                
                j = ((j / 10) + (j % 10));
            }
        }
        
        else
        {
            
            j = numNegative;
        }

        int taxiScore = matrix[i][j]; // Điểm của Taxi
        int I = i;                    // Gán giá trị i vào I để tính toán
        int J = j;                    // Gán giá trị j vào J để tính toán

        // Tìm số lớn nhất từ các ô tạo nên hai đường chéo trái và phải đi qua ô có giá trị điểm của Taxi
        // Để tìm điểm của Sherlock và Watson

        // Bắt đầu từ nửa đường chéo bên trái ở nửa trên ô mang điểm taxi:
        int A = matrix[I][J]; // A là giá trị lớn nhất của ô nằm trên đường chéo trái trên
        // Vòng lặp 10 lần để đảm bảo trường hợp xét 10 ô chéo
        for (int m = 0; m < 10; ++m)
        {
            // xét các ô phía trên bên trái thì số hàng giảm 1, số cột giảm 1
            I -= 1;
            J -= 1;

            // Nếu số hàng nhỏ hơn 0 thì sẽ xảy ra lỗi, do đó thoát vòng lặp
            if (I < 0)
            {
                break;
            }

            // Nếu số cột nhỏ hơn 0 thì sẽ xảy ra lỗi, do đó thoát vòng lặp
            if (J < 0)
            {
                break;
            }

            // Kết quả sau cùng của A là giá trị lớn nhất của ô nằm trên nửa đường chéo trái trên
            A = my_max(A, matrix[I][J]);
        }

        // Reset giá trị của I và J để tiếp tục xét phần tiếp theo
        I = i;
        J = j;

        // Tiếp theo xét nửa dưới đường chéo trái:
        int B = matrix[I][J]; // B là giá trị lớn nhất của ô nằm trên nửa dưới đường chéo trái
        
        for (int m = 0; m < 10; ++m)
        {
            
            I += 1;
            J += 1;
            
            if (I > 9)
            {
                break;
            }
            
            if (J > 9)
            {
                break;
            }
            
            B = my_max(B, matrix[I][J]);
        }

        
        I = i;
        J = j;
        
        int C = matrix[I][J]; 
        
        for (int m = 0; m < 10; ++m)
        {
            
            I += 1;
            J -= 1;
            
            if (I > 9)
            {
                break;
            }
            
            if (J < 0)
            {
                break;
            }
            
            C = my_max(C, matrix[I][J]);
        }

        
        I = i;
        J = j;
        // Cuối cùng xét nửa đường chéo phải phía trên:
        int D = matrix[I][J]; // D là giá trị lớn nhất của ô nằm trên nửa trên đường chéo phải
        
        for (int m = 0; m < 10; ++m)
        {
            
            I -= 1;
            J += 1;
            
            if (I < 0)
            {
                break;
            }
            
            if (J > 9)
            {
                break;
            }
            // Kết quả sau cùng của D là giá trị lớn nhất của ô nằm trên nửa trên đường chéo phải
            D = my_max(D, matrix[I][J]);
        }

        // Tìm điểm số của Sherlock và Watson:
        // Là ô có giá trị cao nhất giữa bốn phần đường chéo A, B, C, D
        int SWScore = my_max(A, B);
        SWScore = my_max(SWScore, C);
        SWScore = my_abs(my_max(SWScore, D)); // Lấy trị tuyệt đối là ra điểm của S và W

        // Gán giá trị của bốn biến nguyên EXP1, EXP2, HP1 và HP2 lần lượt vào các biến thực tương ứng để tính toán
        double exp1 = EXP1;
        double exp2 = EXP2;
        double hp1 = HP1;
        double hp2 = HP2;

        // Nếu độ lớn điểm của taxi lớn hơn điểm của Sherlock và Watson thì S và W sẽ không đuổi kịp taxi
        if (my_abs(taxiScore) > SWScore)
        {
            // thì EXP và HP của 2 người sẽ bị giảm tương ứng
            exp1 = limitEXP(roundUp((exp1 * 88) / 100));
            exp2 = limitEXP(roundUp((exp2 * 88) / 100));
            hp1 = limitHP(roundUp((hp1 * 90) / 100));
            hp2 = limitHP(roundUp((hp2 * 90) / 100));
            // Gán giá trị của EXP1, EXP2, HP1 và HP2 lần lượt vào các biến thực tương ứng để trả về kết quả
            EXP1 = exp1;
            EXP2 = exp2;
            HP1 = hp1;
            HP2 = hp2;

            return taxiScore;
        }
        // Nếu không, Sherlock và Watson sẽ đuổi kịp taxi
        else
        {
            // thì EXP và HP của 2 người sẽ được tăng tương ứng
            exp1 = limitEXP(roundUp((exp1 * 112) / 100));
            exp2 = limitEXP(roundUp((exp2 * 112) / 100));
            hp1 = limitHP(roundUp((hp1 * 110) / 100));
            hp2 = limitHP(roundUp((hp2 * 110) / 100));
            // Gán giá trị của EXP1, EXP2, HP1 và HP2 lần lượt vào các biến thực tương ứng để trả về kết quả
            EXP1 = exp1;
            EXP2 = exp2;
            HP1 = hp1;
            HP2 = hp2;

            return SWScore;
        }
    }
}


// Task 4
// hàm tìm kiếm chuỗi con trong chuỗi mẹ
const char* My_strstr(const char* mainString, const char* subString) {
    if (*subString == '\0') return mainString;  // Nếu subString rỗng, trả về mainString

    while (*mainString != '\0') {
        const char* m = mainString;
        const char* s = subString;

        // kiểm tra các ký tự giống nhau liên tiếp
        while (*s != '\0' && *m == *s) {
            ++m;
            ++s;
        }

        // Nếu đã tìm thấy subString trong mainString, trả về vị trí đầu tiên của subString trong mainString
        if (*s == '\0') return mainString;

        // Tiến hành kiểm tra tiếp chuỗi con tiếp theo trong mainString
        ++mainString;
    }

    return nullptr;  // không tìm thấy subString trong mainString
}

int checkPassword(const char* s, const char* email) {
    // Khai báo biến
    int s_length = 0;
    int se_length = 0;
    bool has_special_char = false;
    bool has_not_special_char = false;

    // Tìm chuỗi 'se'
    while (email[se_length] != '@')
        ++se_length;
    char se[se_length + 1];
    for (int i = 0; i < se_length; ++i)
        se[i] = email[i];
    se[se_length] = '\0';

    // kiểm tra độ dài của mật khẩu
    while (s[s_length] != '\0')
        ++s_length;
    if (s_length < 8)
        return -1; // trả về -1 nếu độ dài ngắn hơn độ dài tối thiểu
    if (s_length > 20)
        return -2; // Trả về -2 nếu độ dài dài hơn độ dài tối đa

    // kiểm tra chuỗi 'se' trong mật khẩu
    if (My_strstr(s, se) != NULL)
        return -(300 + My_strstr(s, se) - s); // Trả về -(300 + vị trí đầu tiên của 'se' trong 's')

    // kiểm tra các ký tự liên tiếp và giống nhau
    for (int i = 0; i < s_length - 2; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i); // trả về -(400 + vị trí đầu tiên của chuỗi trùng lặp)
    }

    // kiểm tra s có chứa ký tự đặc biệt:
    char special_chars[] = {'@', '#', '%', '$', '!'};
    for (int i = 0; i < s_length; ++i) {
        for (char c : special_chars) {
            if (s[i] == c) {
                has_special_char = true;
                break;
            }
        }
    }
    if (!has_special_char)
        return -5; // trả về -5 nếu không có ký tự đặc biệt trong mật khẩu

    int I = 0;
    char not_special_chars[] = {'^','&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', ':', ';', 
    '<', '>', '?', ',', '.', '/', '|', '~', '`', ':', ';'};
    for (int i = 0; i < s_length; ++i) {
        if (has_not_special_char) break;
        for (char c : not_special_chars) {
            if (s[i] == c) {
                has_not_special_char = true;
                I = i;
                break;
            }
        }
    }
    if (has_not_special_char)
        return I; // trả về vị trí I nếu có ký tự không đặc biệt trong mật khẩu

    // nếu không có vấn đề nào thì trả về -10
    return -10;
}

// Hàm so sánh hai chuỗi và trả về true nếu chuỗi giống nhau, ngược lại trả về false
bool my_strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return false;
        }
        ++str1;
        ++str2;
    }
    // Kiểm tra nếu đã duyệt qua cả hai chuỗi và các ký tự ở cùng vị trí đều giống nhau
    return (*str1 == '\0' && *str2 == '\0');
}

// Hàm tính độ dài của chuỗi
int my_strlen(const char *str)
{
    int length = 0;
    while (*str != '\0')
    {
        ++length;
        ++str;
    }
    return length;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int max_count = 0;  // Số lần xuất hiện nhiều nhất của một mật khẩu
    int max_length = 0; // Độ dài của mật khẩu xuất hiện nhiều nhất
    int index = -1;     // Vị trí đầu tiên của mật khẩu đúng trong arr_pwds

    // Đếm số lần xuất hiện của mỗi mật khẩu và tìm mật khẩu có số lần xuất hiện nhiều nhất
    for (int i = 0; i < num_pwds; ++i)
    {
        const char *current_pwd = arr_pwds[i];
        int count = 1; // Đếm số lần xuất hiện của mật khẩu hiện tại

        // Kiểm tra các mật khẩu khác trong mảng để đếm số lần xuất hiện của mật khẩu hiện tại
        for (int j = i + 1; j < num_pwds; ++j)
        {
            if (my_strcmp(current_pwd, arr_pwds[j]))
            {
                ++count;
            }
        }

        // Nếu số lần xuất hiện của mật khẩu hiện tại bằng max_count thì
        if (count == max_count)
        {
            // Nếu độ dài của mật khẩu hiện tại lớn hơn max_length, cập nhật max_length và lưu vị trí của mật khẩu đó
            if (my_strlen(current_pwd) > max_length)
            {
                max_length = my_strlen(current_pwd);
                index = i;
            }
        }
        // Nếu số lần xuất hiện của mật khẩu hiện tại lớn hơn max_count,
        // thì cập nhật max_count và max_length và lưu vị trí của mật khẩu đó
        else if (count > max_count)
        {
            max_count = count;
            max_length = my_strlen(current_pwd);
            index = i;
        }
       
    }
        return index;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////