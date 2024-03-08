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
    // DO NOT MODIFY THIS FUNCTION
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
int firstMeet(int & exp1, int & exp2, int e1) {
    if(e1 >= 0 && e1 <= 3) //TH1 (0.5đ)
    {
        if (e1 == 0)
        {
            exp2 += 29;
        }
        else if (e1 == 1)
        {
            exp2 += 45;
        }
        else if (e1 == 2)
        {
            exp2 += 75;
        }
        else if (e1 == 3)
        {
            exp2 += 149; //sum point of 3 information
        }
        int d = e1 * 3 + exp1 * 7;
        double temp;
        if(d % 2 == 0)
        {
            temp = exp1 + (double)d/200; // select true: add exp1
            exp1 = ceil(temp);
        }
        else
        {
            temp = exp1 - (double)d/100; //select false
            exp1 = ceil(temp);
        } 
    }
    else if(e1 >= 4 && e1 <= 99)//TH2 (1đ)
    {
        double temp;
        bool testNumInfo = false;
        if(e1 >= 4 && e1 <= 19) // information 1
        {
            temp = exp2 + (e1/4.0 + 19);
            exp2 = ceil(temp);
        }
        else if(e1 >= 20 && e1 <= 49) // information 2
        {
            temp = exp2 + (e1/9.0 + 21); 
            exp2 = ceil(temp);
        }
        else if(e1 >= 50 && e1 <= 65) // information 3
        {
            temp = exp2 + (e1/16.0 + 17);
            exp2 = ceil(temp);
        }
        else if (e1 >= 66 && e1 <= 79) // information 4
        {
            temp = exp2 + (e1/4.0 + 19); // explain info 1 and continue
            exp2 = ceil(temp);
            if (exp2 > 200) //allow explain info 2
            {
                temp = exp2 + (e1/9.0 + 21); //explain info 2
                exp2 = ceil(temp);
            }
        }
        else if (e1 >= 80 && e1 <= 99) //information 5
        {
            temp = exp2 + (e1/4.0 + 19);
            exp2 = ceil(temp);
            // explain info 1 and continue
            temp = exp2 + (e1/9.0 + 21); 
            exp2 = ceil(temp);
            // explain info 2 and continue
            if(exp2 > 400) //allow explain info 3
            {
                testNumInfo = true;
                temp = exp2 + (e1/16.0 + 17);
                exp2 = ceil(temp);
            }
        }
        if(testNumInfo) //if explain 3 information 1, 2, 3; point' exp2 add 15%
        {
            temp = 1.15*exp2;
            exp2 = ceil(temp);
        }
        exp1 -= e1;
    }
    if(exp1 < 0) exp1 = 0; //return 0 if exp < 0
    if(exp2 < 0) exp2 = 0;
    if(exp1 > 600) exp1 = 600; //return 600 if exp > 600
    if(exp2 > 600) exp2 = 600;
    return exp1 + exp2;
}

// fuction test isPerfectSquare
bool isPerfectSquare(int n) 
{
    int sqrt_n = sqrt(n);
    return sqrt_n * sqrt_n == n;
}

// fuction find nearest PerfectSquare
int nearestPerfectSquare(int n)
{
    int smaller = n - 1;
    int larger = n + 1;
    while (true) {
        if (isPerfectSquare(smaller))
            return smaller;
        else if (isPerfectSquare(larger))
            return larger;
        else {
            smaller--;
            larger++;
        }
    }
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{   //lưu các biến hp1 exp1 m1 e2
    int saveHP1 = HP1;
    int saveEXP1 = EXP1;
    int saveM1 = M1;
    int saveE2 = E2;

    int SM = M1; // value SM (start money)
    // road 1
    int s1 = nearestPerfectSquare(EXP1); // value s1 save nearest PerfectSquare
    double p1;
    if (EXP1 >= s1) p1 = 1; //p1 = 100%
    else
    {
        p1 = (1.0*EXP1 / s1 + 80) / 123;
    }
    
    // road 2
    double temp;
    if(E2%2 != 0)
    {
        while(true)
        {
            // buy food
            if(HP1 < 200)
            {
                temp = 1.3*HP1;
                HP1 = ceil(temp);
                M1 -= 150;
            }
            else
            {
                temp = 1.1*HP1;
                HP1 = ceil(temp);
                M1 -= 70;
            }
            if((SM - M1) > 0.5*SM) // số tiền đã chi trả (SM-M1) > 50% tiền ban đầu thì đi bộ
                break;

            // rent car
            if(EXP1 < 400) M1 -= 200;
            else M1 -= 120;
            temp = 1.13*EXP1; // exp1 of Sherlock add 13%
            EXP1 = ceil(temp);
            if((SM - M1) > 0.5*SM) // số tiền đã chi trả (SM-M1) > 50% tiền ban đầu thì đi bộ
                break;

            // meet homeless people
            if(EXP1 < 300) M1 -= 100;
            else if (EXP1 >= 300) M1 -= 120;
            temp = 0.9*EXP1; // homeless people was mistaken and exp1 minus 10%
            EXP1 = ceil(temp);
            if((SM - M1) > 0.5*SM) // số tiền đã chi trả (SM-M1) > 50% tiền ban đầu thì đi bộ
                break;
        }
        temp = 0.83*HP1;
        HP1 = ceil(temp);
        temp = 1.17*EXP1;
        EXP1 = ceil(temp);
    }
    if(E2%2 == 0)
    {
        // buy food
        if(HP1 < 200 && M1 > 0)
        {
            temp = 1.3*HP1;
            M1 -= 150;
            HP1 = ceil(temp);
        }
        else if (HP1 >= 200 && M1 > 0)
        {
            temp = 1.1*HP1;
            M1 -= 70;
            HP1 = ceil(temp);
        }

        // rent car
        if(EXP1 < 400 && M1 > 0) M1 -= 200;
        else if (EXP1 >= 400 && M1 > 0) M1 -= 120;
        temp = 1.13*EXP1; // exp1 of Sherlock add 13%
        EXP1 = ceil(temp);
        
        // meet homeless people
        if(EXP1 < 300 && M1 > 0) M1 -= 100;
        else if (EXP1 >= 300 && M1 > 0) M1 -= 120;
        temp = 0.9*EXP1; // homeless people was mistaken and exp1 minus 10%
        EXP1 = ceil(temp);
        
        //check money
        if(M1 <= 0) M1 = 0;
        temp = 0.83*HP1;
        HP1 = ceil(temp);
        temp = 1.17*EXP1;
        EXP1 = ceil(temp);
    }
    int s2 = nearestPerfectSquare(EXP1); // value s save nearest PerfectSquare
    double p2;
    if (EXP1 >= s2) p2 = 1; //p1 = 100%
    else
    {
        p2 = (EXP1 / s2 + 80) / 123;
        p2 = ceil(p2);
    }
    
    //road3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    double p3;
    if(E2 >= 0 && E2 <= 9)
    {
        p3 = 1.0*P[E2]/100;
    }
    else if(E2 >= 10 && E2 <=99)
    {
        int ten = E2 / 10; // Lấy chữ số hàng chục
        int unit = E2 % 10; // Lấy chữ số hàng đơn vị
        int sum = ten + unit; // Tính tổng hai chữ số
        int unitOfSum = sum % 10; // Lấy chữ số hàng đơn vị của tổng
        p3 = 1.0*P[unitOfSum]/100;
    }

    //check xác suất
    if(p1 == 1 && p2 == 1 && p3 == 1)
    {
        traceLuggage(saveHP1, saveEXP1, saveM1, saveE2);
        temp = 1.13*EXP1; // exp1 of Sherlock minus 25%
        EXP1 = ceil(temp);
    }
    double p = (p1 + p2 + p3)/3;
    if(p < 0.5)
    {
        temp = 0.85*HP1;
        HP1 = ceil(temp);
        temp = 1.15*EXP1;
        EXP1 = ceil(temp);
    }
    else if(p >= 0.5)
    {
        temp = 0.9*HP1;
        HP1 = ceil(temp);
        temp = 1.2*EXP1;
        EXP1 = ceil(temp);
    }
    if(EXP1 < 0) EXP1 = 0;
    else if(EXP1 > 600) EXP1 = 600;
    if(HP1 < 0) HP1 = 0;
    else if(HP1 > 666) HP1 = 666;
    if(M1 < 0) M1 = 0;
    else if(M1 > 3000) M1 = 3000;
    return HP1 + EXP1 + M1;
}

// Task 3
int sumDigits(int num) 
{
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
// hàm tính tổng các chữ số có 2 chữ số
int reduceToOneDigit(int num) 
{
    while (num > 9) {
        num = sumDigits(num);
    }
    return num;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) 
{
    double temp;
    // delcare array 2D used to save points of Taxi
    int taxi[10][10] = {0};
    for(int i = 0; i<10; ++i)
    {
        for(int j = 0; j<10; ++j)
        {
            taxi[i][j] = (E3*j + i*2) * (i-j);
        }
    }

    // delcare array 2D used to save points of Sherlock Holms
    int SH[10][10] = {0};
    for (int i = 0; i < 10; ++i) 
	{
        for (int j = 0; j < 10; ++j) 
		{
            int diagonal1 = taxi[i][j], diagonal2 = taxi[i][j];
            for (int k = -max(i, j); k < 10; ++k)
			{
                // Tính giá trị trên đường chéo trái
                if (i + k < 10 && i + k >= 0 && j + k < 10 && j + k >= 0)
                    diagonal1 = max(diagonal1, taxi[i + k][j + k]);
                    
                // Tính giá trị trên đường chéo phải
                if (i + k < 10 && i + k >= 0 && j - k >= 0 && j - k < 10)
                    diagonal2 = max(diagonal2, taxi[i + k][j - k]);
            }
            // Lưu giá trị lớn nhất của 2 đường chéo vào ma trận B
            SH[i][j] = max(diagonal1, diagonal2);
        }
    }

    //function find point where Sherlock detect Taxi
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i<10; ++i)
    {
        for(int j = 0; j<10; ++j)
        {
            if(taxi[i][j] > 2*E3) count1++;
            if(taxi[i][j] < -E3)  count2++;
        }
    }
    if(count1 > 9) count1 = reduceToOneDigit(count1);
    if(count2 > 9) count2 = reduceToOneDigit(count2);

    if(abs(taxi[count1][count2]) > abs(SH[count1][count2])) // not detected
    {
        temp = 0.88*EXP1; //minus exp and hp
        EXP1 = ceil(temp);
        temp = 0.9*HP1;
        HP1 = ceil(temp);

        temp = 0.88*EXP2;
        EXP2 = ceil(temp);
        temp = 0.9*HP2;
        HP2 = ceil(temp);

        return taxi[count1][count2];
    }
    else    // detected
    {
        temp = 1.12*EXP1; //add exp and hp
        EXP1 = ceil(temp);
        temp = 1.1*HP1;
        HP1 = ceil(temp);

        temp = 1.12*EXP2;
        EXP2 = ceil(temp);
        temp = 1.1*HP2;
        HP2 = ceil(temp);

        return SH[count1][count2];
    }
}

//function get se 
string se(const char * email)
{
    string str;
    for(int i = 0; i<strlen(email); ++i)
    {
        if(email[i] != '@')
        {
            str.push_back(email[i]);   
        }
        else break;
    }
    return str;
}

int checkPassword(const char * s, const char * email) 
{
	// độ dài 
    if(strlen(s) < 8)
    {
    	return -1; //độ dài mk < 8
	}
    else if(strlen(s) > 20)
    {
    	return -2; //độ dài mk > 20
	}

	//chuỗi con
    string temp = se(email);
    size_t found = string(s).find(temp); // Tạo đối tượng string từ chuỗi const char *
    if(found != string::npos)
    {
        return -(300 + found); //mk chứa tên của gmail
    }

	//chuỗi trùng liên tiếp 
    int sci = -1;
     for(int i = 0; i < strlen(s) - 2; ++i) {
        if(s[i] == s[i+1] && s[i] == s[i+2]) {
            sci = i;
            break;
        }
    }
    if(sci != -1)
	{
		return -(400 + sci); //chuỗi mk có nhiều hơn 2 kí tự trùng nhau liên tiếp
	}
        
    
    //kí tự đặc biệt
    bool checkchar = false;
    for(int i = 0; i<strlen(s); ++i)
    {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
        {
            checkchar = true;
            break;
        }
    }
    if(!checkchar)
    {
    	return -5; //không có kí tự đặc biệt
	}

	//ngoài kí tự thông thường
    for(int i = 0; i<strlen(s); ++i)
    {
        if(!((s[i] >= 48 && s[i] <= 57) || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') )
        {
        	return i; //chuỗi mk có kí tự nằm ngoài những kí tự đã quy định
		}
    }
    return -10; //mật khẩu đúng
}

// Task 5
const char * findpwdslonger(const char * a, const char * b) //hàm tìm mật khẩu có độ dài dài hơn
{
	return (strlen(a) > strlen(b)) ? a : b;
}

int findmax(int a[], const char * arr_pwds[], int size)
{
	int max = a[0];
	int index = 0;
	bool check = false;
	int re = 0;
	for(int i = 0; i<size; ++i)
	{
			if(a[i] > max)
			{
				max = a[i];
				index = i;
			}
	}
	const char * save = arr_pwds[index];
	for(int i = index + 1; i<size; ++i)
	{
		if(max == a[i])
			save = findpwdslonger(arr_pwds[i], save);
	}
	for(int i = 0; i<size; ++i)
	{
		if(save == arr_pwds[i]) 
		{
			re = i;
			break;
		}
	}
	return re;
}

int findCorrectPassword(const char * arr_pwds[], int num_pwds) // hàm tìm số lượng mật khẩu giống nhau trong mảng
{
	int re = -1;
	int a[30] = {0};
	for(int i = 0; i<num_pwds; ++i) 
	{
		int count = 1;
		for(int j = i + 1; j<num_pwds; ++j)
		{
			if(arr_pwds[i] == arr_pwds[j])
			{
				count++;
				a[j] = -1;
				arr_pwds[j] = "null";
			}
		}
		if(a[i] != -1)
			a[i] = count;
	}
	re = findmax(a, arr_pwds, num_pwds);
	return re;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////