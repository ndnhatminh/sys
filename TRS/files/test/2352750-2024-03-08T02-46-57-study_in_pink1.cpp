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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //trường hợp 1
        if(e1<0||e1>99) return -99;
        if (e1 >= 0 && e1 <= 3) {
        switch(e1) {
        case 0:
            exp2+= 29;
            break;
        case 1:
            exp2 += 45;
            break;
        case 2:
            exp2 += 75;
            break;
        case 3:
            exp2 += 149;
            break;
        }

        //dự đoán của Sherlock
        int d= 3*e1 + exp1*7;
        if (d % 2 == 0) {
            exp1 =ceil(float((exp1+ d/200.0)));
        }
        else {
            exp1 =ceil(float(exp1-d/100.0));
        }
    }

    //Trường hợp 2
    else {
        if(e1>=4 && e1<=19) exp2 =ceil(float(exp2+(e1/4.0+19))); // thông tin 1
        if(e1>=20 && e1<=49) exp2 =ceil(float(exp2+(e1/9.0+21))); // thông tin 2
        if(e1>=50 && e1<=65) exp2 =ceil(float(exp2+(e1/16.0+17))); //thông tin 3

        //thông tin 4
        if(e1>=66 && e1<=79) {
            exp2 =ceil(float(exp2+(e1/4.0 + 19)));
            if (exp2 > 200) {
                exp2 = ceil(float(exp2+(e1/9.0 + 21)));
            }
        }

        //thông tin 5
        if(e1 >= 80 && e1<=99) {
            exp2 = ceil(float(exp2 + (e1/4.0+19) + (e1/9.0+21)));
            if (exp2 > 400) {
                exp2 =ceil(float(exp2+ (e1/16.0 + 17)));
            }
            exp2 = ceil(exp2*1.15);
        }
        exp1 =exp1-e1;   //Sherlock bị bất ngờ trước sai lầm
    }
        // check điều kiện exp
    if (exp1 > 600) { exp1 = 600; }
	if (exp2 > 600) { exp2 = 600; }
	if (exp1 < 0) { exp1 = 0; }
	if (exp2 < 0) { exp2 = 0; }
    return exp1 + exp2;
}
// tìm số chính phương gần nhất
int SoChinhPhuongGanNhat(int EXP1)
{
    float x = round(sqrt(EXP1));
    int a = int(x * x);
    return a;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
   // Con đường 1
    int s1 = SoChinhPhuongGanNhat(EXP1);
    float P1, P2;
    if (EXP1 >= s1)
    {
        P1 = 1;
    } 
    else
    {
        P1 = float((EXP1 / s1 + 80)) / 123;
    }
    // Con đường 2
    int lastMoney = 0; // số tiền cần chi trả
    // Xét E2
    if (E2 % 2 == 1){
        while (lastMoney < (0.5 * M1)){
            // Mua thức ăn
            if (HP1 < 200){
                HP1 = ceil(HP1 * 1.3);
                lastMoney += 150;
            }
            else{
                HP1 = ceil(HP1 * 1.1);
                lastMoney += 70;
            }
            if (lastMoney > (0.5 * M1)){
                break;
            }
            // Đi xe ngựa hoặc taxi
            if (EXP1 < 400){
                lastMoney += 200;
            }
            else{
                lastMoney += 120;
            }
            EXP1 = ceil(EXP1*1.13);
            if (lastMoney > 0.5 * M1){
                break;
            }
            // Gặp người vô gia cư
            if (EXP1 < 300){
                lastMoney += 100;
            }
            else{
                lastMoney += 120;
            }
            EXP1 *= 0.9;
        }
        // cập nhật
        M1 -= lastMoney;
    }
    else {
        if(M1 > 0) {
            if (HP1 < 200){
                HP1 = ceil(HP1*1.3);
                M1 -= 150;
            }
            else{
                HP1 = ceil(HP1*1.1);
                M1 -= 70;
            }
        }
        else M1 = 0;
        // Đi xe ngựa hoặc taxi
        if(M1 > 0) {
            if (EXP1 < 400){
                M1 -= 200;
            }
            else{
                M1 -= 120;
            }
            EXP1 = ceil(EXP1*1.13);
        }
        else M1 = 0;
        // Gặp người vô gia cư
        if(M1 > 0) {
            if (EXP1 < 300){
                M1 -= 100;
            }
            else{
                M1 -= 120;
            }
            EXP1 = ceil(EXP1*0.9);
        }
        else M1 = 0;
    }
    HP1 = ceil(HP1*0.83);
    EXP1 = ceil(EXP1*1.17);
    int s2 = SoChinhPhuongGanNhat(EXP1);
    if (EXP1 >= s2) // xác suất tìm P2
    {
        P2 = 1;
    }
    else {
        P2 = float((EXP1 / s2 + 80)) / 123;
    }
    // Con đường 3
    float P3;
    int a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};// mảng cố định gồm 10 xác suất
    if (E2 < 10) // nếu E2 là 1 số có một chữ số
    {
        P3 = float(a[E2]) / 100; //xác suất P3
    }
    else
    {
        int temp = E2 / 10 + E2 % 10; // lấy tổng của 2 chữ số nếu E2 có 2 chữ số
        int idx = temp % 10; //lấy hàng đơn vị của tổng đó
        P3 = float(a[idx]) / 100; // xác suất P3
    }
    // Tổng kết
    if (P1 == P2 && P2 == P3 & P3 == 1) // nếu cả 3 đều có xác suất 100%
    {
        EXP1 = ceil(EXP1*0.75); //EXP1 giảm đi 25%
    }
    else
    {
        float Ps = (P1 + P2 + P3) / 3; // trung bình cộng 3 giá trị là giá trị cuối cùng
        if (Ps < 0.5) // nếu xác suất < 50%
        {
            HP1 = ceil(HP1 * 0.85);//làm tròn HP1
            EXP1 = ceil(EXP1*1.15);
        }
        else // xác suất >= 50%
        {
            HP1 = ceil(HP1 * 0.9);
            EXP1 =ceil(EXP1*1.2);
        }
    }
    //check điều kiện exp1
    if (EXP1 > 600)
    {
        EXP1 = 600;
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    // điều kiện exp và hp
    if (EXP1 > 600)  EXP1 = 600; 
	if (EXP2 > 600)  EXP2 = 600; 
	if (HP1 > 666)  HP1 = 666; 
	if (HP2 > 666)  HP2 = 666; 
	if (EXP1 < 0)  EXP1 = 0; 
	if (EXP2 < 0)  EXP2 = 0; 
	if (HP1 < 0)  HP1 = 0; 
	if (HP2 < 0)  HP2 = 0;
	int i1 = 0, j1 = 0;
	int B[10][10]; // tạo mảng 10x10
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			B[i][j] = ((E3 * j) + (i * 2)) * (i - j);//điếm số của taxi tại điểm i,j
			if (B[i][j] > (E3 * 2))  i1 +=1; //i=số giá trị điểm của taxi>E3*2
			if (B[i][j] < (E3 * (-1)))  j1 += 1; //j=số giá trị điểm của taxi<-E3
		}
	}
	while (i1 >= 10)//nếu i là 1 số có 2 chữ số
	{
		i1 = i1 % 10 + i1 / 10;
	}
	while (j1 >= 10) // nếu j là 1 số có 2 chữ số
	{
		j1 = j1 % 10 + j1 / 10;
	}
	int taxi = B[i1][j1];//vị trí gặp taxi
	int max = B[i1][j1];
	int S = i1 + j1, M = abs(i1 - j1);
    for (int i = i1; ((i >= 0) && (i <= 9) && (M + i >= 0) && (M + i <= 9)); i--)
	{
		if (max < B[i][M + i]) { max = B[i][M + i]; } //tìm giá trị lớn nhất phía trên đường chéo trái
	}
	for (int i=i1;((i>=0)&&(i<=9));i++)
	{
		if (max < B[i][S - i])  max = B[i][S - i];  //tìm giá trị lớn nhất phía dưới đường chéo trái
	}
	for (int i = i1; ((i >= 0) && (i <= 9) && (S - i >= 0) && (S - i <= 9)); i--)
	{
		if (max < B[i][S - i]) { max = B[i][S - i]; } //tìm giá trị lớn nhất phía trên đường chéo phải
	}
	for (int i = i1; ((i >= 0) && (i <= 9) && (M + i >= 0) && (M + i <= 9)); i++)
	{
		if (max < B[i][M + i]) { max = B[i][M + i]; }//tìm giá trị lớn nhất phía dưới đường chéo phải
	}
	if (abs(taxi) > max)
	{
		EXP1 = round(EXP1 * 0.88);
		HP1 = round(HP1 * 0.9);
		EXP2 = round(EXP2 * 0.88);
		HP2 = round(HP2 * 0.9);
		return taxi;
	}
	else
	{
		EXP1 = round(EXP1 * 1.12);
		HP1 = round(HP1 * 1.1);
		EXP2 = round(EXP2 * 1.12);
		HP2 = round(HP2 * 1.1);
		if (EXP1 > 600) { EXP1 = 600; }
		if (EXP2 > 600) { EXP2 = 600; }
		if (HP1 > 666) { HP1 = 666; }
		if (HP2 > 666) { HP2 = 666; }
		if (EXP1 < 0) { EXP1 = 0; }
		if (EXP2 < 0) { EXP2 = 0; }
		if (HP1 < 0) { HP1 = 0; }
		if (HP2 < 0) { HP2 = 0; }
		return max;
}
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
       // Tính độ dài của chuỗi email
    int lengthEmail = strlen(email);

    // Tìm vị trí của ký tự '@' trong chuỗi email
    const char *atSign = strchr(email, '@');
    if (atSign == NULL) {
        // Không tìm thấy ký tự '@' trong email
        return -3; // hoặc mã lỗi phù hợp
    }

    // Tính toán độ dài của chuỗi "se"
    int lengthSe = atSign - email;
    char se[lengthSe + 1]; // Cần phải thêm 1 cho ký tự null kết thúc chuỗi
    strncpy(se, email, lengthSe);
    se[lengthSe] = '\0';

    int lengthS = strlen(s);
    // kiểm tra độ dài
    if(lengthS < 8) return -1;

    // kiểm tra độ dài
    if(lengthS > 20) return -2;
    
    // check mật khẩu có kí tự ngoài không 
    for(int i = 0; i < lengthS; i++){
        if(!isalpha(s[i])&&(s[i]!='0'&&s[i] !='1'&& s[i] !='2' && s[i] != '3'&&s[i]!='4'&&s[i] != '5'&&s[i] !='6' &&s[i] !='7' && s[i]!='8' &&s[i] != '9' ) &&(s[i] != '@' && s[i] != '#' && s[i] != '%' && s[i] != '$' && s[i] != '!')) {
            return i;
        }
    }
    
    // s chứa se
const char* found = strstr(s, se);
    if (found != nullptr) {
        return -(300 + (found-s));
    }

    // check kí tự liên tiếp giống nhau
    int length2 = 1;
    char c = s[0];
    int pos2 = 0;
    for(int i = 1; s[i] != '\0'; i++){
        if(s[i] == c) {
            length2++;
            if(length2 > 2) {
                return -(400 + pos2);   
            }
        }
        else {
            c = s[i];
            pos2 = i;
            length2 = 1;
        }
    }

    // không có kí tự đặc biệt
    int cnt = 0;
    for(int i = 0; i < lengthS; i++) {
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            cnt++;
        }
    }
    if(cnt == 0) return -5;

    // mật khẩu hợp lý
    
     return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
        pair<const char*, int> a[num_pwds]; // khởi tạo mảng pair
    for(int i = 0; i < num_pwds; i++) {
        a[i].first = arr_pwds[i];
        a[i].second = 0;
    } 
    // đếm số lần số hiện của mỗi chuỗi trong mảng
    for(int i = 0; i < num_pwds; i++) {
        for(int j = 0; j < num_pwds; j++) {
            if(string(arr_pwds[i]) == a[j].first) {
                a[j].second++;
                break;
            }
        }
    }
    int pos;
    int maxcnt = 0;
    for(int i = 0; i < num_pwds; i++) {
        bool checked = false; // check chuỗi đã được duyệt chưa
        for(int j = 0; j < i; j++) {
            if(a[i].first == a[j].first) { // nếu được duyệt rồi thì check bằng true
                checked = true;
                break;
            }
        }
        if(!checked) { // nếu chuỗi chưa được duyệt thì duyệt
            if(a[i].second > maxcnt) {
                maxcnt = a[i].second;
                pos = i;
            }
            else if(a[i].second == maxcnt) {
                if(strlen(a[i].first) > strlen(a[pos].first)) {
                    pos = i;
                }
            }
        }
    }
    return pos;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
