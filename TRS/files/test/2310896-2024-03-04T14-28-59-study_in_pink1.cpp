#include "study_in_pink1.h"
#include "main.h"
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
//Hàm cộng điểm theo %
int congDiem(int x, int phanTram){
    double temp = x;
    temp = x + double(x)*phanTram/100;
    x= ceil (temp);
    return x;
}
//hàm trừ điểm theo phần trăm
int truDiem(int x, int phanTram){
    double temp = x;
    temp = x - double(x)*phanTram/100;
    x= ceil (temp);
    return x;
}
//hàm kiểm tra thông số trong khoảng quy định
void kiemTraThongSo(int & HP, int & EXP){
    if (HP > 666) HP=666;
    if (HP < 0) HP=0;
    if (EXP < 0) EXP=0;
    if (EXP > 600) EXP=600;
}
// Task 1
void kiemTraThongSo1(int & EXP1, int & EXP2){
    if (EXP1 > 600) EXP1=600;
    if ( EXP2 > 600) EXP2=600; 
    if (EXP1 < 0) EXP1=0;
    if ( EXP2 < 0) EXP2=0;   
}
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    kiemTraThongSo1(exp1, exp2);
    if (e1>=0 && e1<=3){
        if (e1 == 0){
            exp2+=29;
            kiemTraThongSo1(exp1, exp2);
        }
        else if (e1 == 1){
            exp2+=45;
            kiemTraThongSo1(exp1, exp2);
        }
        else if (e1==2){
            exp2+=75;
            kiemTraThongSo1(exp1, exp2);
        }
        else{
            exp2+=29+45+75;
            kiemTraThongSo1(exp1, exp2);
        }
        int D = e1*3 + exp1*7;
        double temp1;
        double change1;   //them hai bien thuc de luu gia tri truoc khi lam tron len 
        if (D%2==0){
            change1 = double(D)/200;
            temp1 = exp1 + change1;
            exp1 = ceil(temp1);  //ham ceil lam tron` len gtri nguyen gan nhat
            kiemTraThongSo1(exp1, exp2);
        }
        else{
            change1 = double(D)/100;
            temp1 = exp1 - change1;
            exp1 = ceil(temp1);
            kiemTraThongSo1(exp1, exp2);
        }
    }
   else if (e1>=4 && e1 <=99){
        double temp2;
        double change2;
        //th1
        if (e1>=4 && e1<=19){
            change2 = double(e1)/4 + 19;
            temp2 = exp2 + change2;
        }
        //th2
        else if (e1>=20 && e1<=49){
            change2 = double(e1)/9 + 21;
            temp2 = exp2 + change2;            
        }
        //th3
        else if (e1>=50 && e1<=65){
            change2 = double(e1)/16 + 17;
            temp2 = exp2 + change2;            
        }
        //th4
        else if (e1>=66 && e1<=79){
            change2 = double(e1)/4 + 19;
            temp2 = exp2 + change2;
            //cap nhat xong thong tin 1
            temp2 = ceil(temp2);
            //lam tron sau khi cap nhat
            if (temp2 > 200){
                change2 = double(e1)/9 + 21;
                temp2 += change2;    
            }            
        }
        //th5
        else{
            change2 = double(e1)/4 + 19;
            temp2 = exp2 + change2;
            //cap nhat thong tin 1
            temp2 = ceil (temp2);
            //lam tron sau khi cap nhat
            change2 = double(e1)/9 + 21;
            temp2 += change2;
            temp2 = ceil (temp2);
            //cap nhat thong tin 2
            if (temp2 > 400){
                change2 = double(e1)/16 + 17;
                temp2 += change2;
                //khi cap nhat ca 3 thong tin exp2 tang 15%
                temp2 += temp2*15/100;  
            }
        }
        exp2 = ceil(temp2);
        exp1 -= e1;
   }
   else return -99;
   kiemTraThongSo1(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
//ham dung cho con duong 1 va cuoi con duong 2
float conDuong1(int EXP1){
    float P, canBacHai = sqrt(EXP1);
    int lamTron =round (canBacHai);
    float S = lamTron * lamTron;
    if (S <= EXP1){
        P = 100;
    }
    else{
        P = ((double(EXP1)/S + 80)/123);
        P = round (P * 100);   //ham round lam tron len so nguyen nen nhan 100 truoc roi round
    }
    return P;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) { //**!!!E3!!!!***
    // TODO: Complete this function
    float P1, P2, P3;
    //Con duong thu 1
    P1 = conDuong1 (EXP1);
    //Con duong thu 2
    // double tempHP = HP1, tempEXP = EXP1;
    int halfMoney = M1 * 0.5;
    const int firstMoney = M1;
    bool soLe = false;
    if (E3%2 != 0) soLe=true;
    do{
        if (HP1 < 200){
            HP1=congDiem(HP1, 30);
            M1 -= 150;
            if (soLe){
                if ((firstMoney-M1)>halfMoney) break;        //kiem tra tien
            }
            else{
                if (M1<=0) break;
            }
        }
        else{
            HP1=congDiem(HP1, 10);
            M1 -= 70;
            if (soLe){
                if ((firstMoney-M1)>halfMoney) break;        //kiem tra tien
            }
            else{
                if (M1<=0) break;
            }
        }
        //xong hanh dong 1 va da ktra tien
        if (EXP1 < 400){
            M1 -= 200;
            EXP1=congDiem(EXP1, 13);
            if (soLe){
                if ((firstMoney-M1)>halfMoney) break;        //kiem tra tien
            }
            else{
                if (M1<=0) break;
            }
        }
        else{
            M1 -= 120;
            EXP1=congDiem(EXP1, 13);
            if (soLe){
                if ((firstMoney-M1)>halfMoney) break;        //kiem tra tien
            }
            else{
                if (M1<=0) break;
            }
        }
        //xong hanh dong 2 va da ktra tien
        if (EXP1 < 300){
            M1 -= 100;
            EXP1=truDiem(EXP1, 10);
            if (soLe){
                if ((firstMoney-M1)>halfMoney) break;        //kiem tra tien
            }
            else{
                if (M1<=0) break;
            }
        }
        else{
            M1 -= 120;
            EXP1=truDiem(EXP1, 10);
            if (soLe){
                if ((firstMoney-M1)>halfMoney) break;        //kiem tra tien
            }
            else{
                if (M1<=0) break;
            }
        }
        //xong hanh dong 3 va da ktra tien
    } while (soLe);
    HP1=truDiem(HP1, 17);
    EXP1=congDiem(EXP1, 17);
    P2 = conDuong1(EXP1);
    kiemTraThongSo(HP1, EXP1);
    //Con duong thu 3
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if (E3 <= 9) P3 = P[E3];
    else if (E3>=10 && E3<=99){
        int soHangChuc, soHangDonVi, sum;
        soHangChuc = E3 / 10;
        soHangDonVi = E3 - soHangChuc*10;
        sum = soHangChuc + soHangDonVi;
        soHangChuc = sum / 10;
        soHangDonVi = sum - soHangChuc*10;
        P3 = P[soHangDonVi]; 
    }
    //HOAN THANH 3 CON DUONG
    if (P1==100 && P2==100 && P3==100){
        EXP1=truDiem(EXP1, 25);
        kiemTraThongSo(HP1, EXP1);
    }
    else{
        int Ptb=round((P1+P2+P3)/3);
        if (Ptb < 50){
            HP1=truDiem(HP1, 15);
            EXP1=congDiem(EXP1, 15);
            kiemTraThongSo(HP1, EXP1);
        }
        else{
            HP1=truDiem(HP1, 10);
            EXP1=congDiem(EXP1, 20);
            kiemTraThongSo(HP1, EXP1);
        }
    }
    kiemTraThongSo(HP1, EXP1);
    if (M1 < 0) M1 = 0;              //ktra sau cung theo yeu cau ban dau
    return HP1 + EXP1 + M1;
}

// Task 3
//Hàm tổng hai chữ số cho đến khi ra số có một chữ số
int tongHaiChuSo(int x){
    while (x >= 10){
        int soHangChuc, soHangDonVi;
        soHangChuc = x / 10;
        soHangDonVi = x - soHangChuc*10;
        x = soHangChuc + soHangDonVi;
    }
    return x;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int taxi[10][10];
    //nhap diem cho Taxi vao ma tran truoc
    for (int j=0; j<10; j++){
        for (int i=0; i<10; i++) taxi[i][j]=((E3 * j) + (i * 2)) * (i - j);
    }
    //Tìm điểm gặp nhau
    int iMeet=0, jMeet=0;   //iMeet va jMeet la toa do diem GAP NHAU
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if (taxi[i][j] > E3*2) iMeet++;
            if (taxi[i][j] < -E3) jMeet++;
        }
    }
    iMeet=tongHaiChuSo(iMeet);
    jMeet=tongHaiChuSo(jMeet);
    //tim duoc diem gap nhau
    //gia tri diem cua Sherlock dua vao diem cua taxi nen tim diem GAP NHAU va tim diem Sherlock tai do luon
    int max = INT_MIN;
    int x=iMeet, y=jMeet;
    while (x >=0 && y<=9){
        if (taxi[x][y] > max) max = taxi[x][y];
        x--;  y++;
    }
    x=iMeet; y=jMeet;
    while (y >=0 && x<=9){
        if (taxi[x][y] > max) max = taxi[x][y];
        x++;  y--;
    }
    x=iMeet; y=jMeet;
    while (x <=9 && y<=9){
        if (taxi[x][y] > max) max = taxi[x][y];
        x++;  y++;
    }
    x=iMeet; y=jMeet;
    while (x >=0 && y>=0){
        if (taxi[x][y] > max) max = taxi[x][y];
        x--;  y--;
    }
    int SherlockScore=max;
    int taxiScore=abs(taxi[iMeet][jMeet]);
    if (taxiScore > SherlockScore){
        HP1=truDiem(HP1, 10);
        EXP1=truDiem(EXP1, 12);
        HP2=truDiem(HP2, 10);
        EXP2=truDiem(EXP2, 12);
        kiemTraThongSo(HP1, EXP1);
        kiemTraThongSo(HP2, EXP2);
        return taxi[iMeet][jMeet];
    }
    else{
        HP1=congDiem(HP1, 10);
        EXP1=congDiem(EXP1, 12);
        HP2=congDiem(HP2, 10);
        EXP2=congDiem(EXP2, 12);
        kiemTraThongSo(HP1, EXP1);
        kiemTraThongSo(HP2, EXP2);
        return SherlockScore;   
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
	string e=email;
    int cnt=0;
	for (cnt; cnt<e.size(); cnt++){
		if (e[cnt]=='@') break;
	}
	string se = e.substr(0, cnt);  //hàm substring cut chuỗi con<tham số là điểm bắt đầu và độ dài đoạn cắt>
    string pass=s;
    if (pass.size() < 8) return -1;
    if (pass.size() >20) return -2;    //1.Quy định về độ dài
    if(pass.size()>=se.size()){
        for ( int start=0 ; start<pass.size()- se.size() ; start++){
            string temp= pass.substr(start, se.size());
            if (temp == se) return -(300 + start);
        }                           //2.Quy định không được chứa chuỗi "se"
    }
    for (int i=0; i<pass.size()-2; i++){
        int cmp=pass[i];
        int start=i;
        int cnt=1;
        while (cmp == pass[i+1]){
            cnt++;
            i++;
            if (cnt == 3) return -(400 + start);   //3.Quy định không được có 3 ký tự giống nhau liên tiếp
        }
    }
    bool check1=true;
    for (int i=0; i<pass.size(); i++){
        if (pass[i]=='@' || pass[i]=='#' || pass[i]=='%' || pass[i]=='$' || pass[i]=='!'){
            check1=false;
            break;
        }
    }
    if (check1) return -5;       //4. Quy định phải có ít nhất một ký tự đặc biệt
    for (int i=0; i<pass.size();i++){
        char k=pass[i];
        if (!(
            (k>='A' && k<='Z') || (k>='a' && k<='z') ||    //CHỮ CÁI THƯỜNG HOẶC IN HOA
            (k>='0' && k<='9')||                           //SỐ
            k=='@' || k=='#' || k=='%' || k=='$'||k=='!'   //KÝ TỰ ĐẶC BIỆT
            )) return i;                                            //**5.Quy định ký tự phù hợp                                     
    }
    return -10;          //Nếu đúng hết
}

// Task 5
struct twoInOne{
    string pass;
    int tanSuat;
    int hienDien;
};
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    // string a[num_pwds];
    // for (int i=0; i<num_pwds; i++){
    //     a[i]=arr_pwds[i];
    // }
    // int checker[32]={0};      //Khởi tạo mảng đánh dấu
    // int storage[32]={0};       //Khởi tạo mảng lưu trữ số lần xuất hiện của password
    // for(int i=0; i<num_pwds; i++){
    //     for (int j=i+1; j<num_pwds; j++){
    //         if (checker[i]!=0) continue;
    //         if (a[i]==a[j]){
    //             storage[i]++;      //lưu số lần xuất hiện của pass
    //             checker[j]++;      //đánh dấu vào phần tử trùng đằng sau
    //         }
    //     }
    // }
    // int maxIndex=0;
    // int maxStorage=storage[0];   //khởi tạo biến vị trí và giá trị xuất hiện lớn nhất
    // for (int i=1; i<num_pwds; i++){
	//     if (maxStorage < storage[i]){
	//          maxIndex=i;
	//          maxStorage = storage[i];
	//     }
	//     else if (maxStorage==storage[i+1]){
	//         if (a[i+1].size()>a[i].size()){
	// 	         maxIndex=i;
	// 	         maxStorage = storage[i]; 	            	
	//         }
	//     }
    // }
    // return maxIndex;
    // TODO: Complete this function
    twoInOne a[num_pwds];    //tạo mảng các phần tử có kiểu tự cấu hình ở trên struct
    for (int i=0; i<num_pwds; i++){
        a[i].pass=arr_pwds[i];
        a[i].hienDien=0;
        a[i].tanSuat=0;
    }
    for(int i=0; i<num_pwds; i++){
        for (int j=i+1; j<num_pwds; j++){
            if (a[i].hienDien!=0) break;
            if (a[i].pass==a[j].pass){
                a[i].tanSuat++;      //lưu số lần xuất hiện của pass
                a[j].hienDien++;      //đánh dấu vào phần tử trùng đằng sau
            }
        }
    }
    int maxIndex=0;
    int maxTanSuat=a[0].tanSuat;   //khởi tạo biến vị trí và giá trị xuất hiện lớn nhất
    for (int i=1; i<num_pwds; i++){
	    if (maxTanSuat < a[i].tanSuat){
	         maxIndex=i;
	         maxTanSuat = a[i].tanSuat;
	    }
	    else if (maxTanSuat==a[i].tanSuat){
	        if (a[i].pass.size()> a[i-1].pass.size()){
		         maxIndex=i;
		         maxTanSuat = a[i].tanSuat; 	            	
	        }
	    }
    }
    return maxIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
