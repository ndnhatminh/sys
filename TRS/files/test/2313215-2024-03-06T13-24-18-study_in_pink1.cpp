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
//ham kiem tra
void kiemtraEXP(int & EXP){
	if(EXP>600){
		EXP=600;
	}else if(EXP<0){
		EXP=0;
	}
}
void kiemtraHP(int & HP){
	if(HP>666){
		HP=666;
	}else if(HP<0){
		HP=0;
	}
}
void kiemtraM(int & M){
	if(M>3000){
		M=3000;
	}else if(M<0){
		M=0;
	}
}
//
// Task 1
//ham lam tron len
int lam_tron_len(double n){
	int phu = static_cast<int>(n);
	if(n==phu){
		return n;
	}else{
		return n+1;
	}
}
//
//ham firstmeet
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    //truong hop 1
    //
    if((e1>99)||(e1<0)){
    	return -99;
	}
    int D;
    if((e1>=0) && (e1<=3)){
    	if(e1==0){
    		exp2+=29;
		}else if(e1==1){
    		exp2+=45;
		}else if(e1==2){
			exp2+=75;
		}else if(e1==3){
			exp2 = exp2 +29 +45+75;
		}
		kiemtraEXP(exp2);
	D=e1*3 + exp1*7;
	if(D%2==0){
		exp1= lam_tron_len(exp1 +static_cast<double>(D)/200);
		kiemtraEXP(exp1);
	}else{
		exp1= lam_tron_len(exp1 -static_cast<double>(D)/100);
		kiemtraEXP(exp1);
	}
	}
    //het truong hop 1
    //
    //truong hop 2
    if((e1>=4) && (e1<=99)){
    	if((e1>=4) && (e1<=19)){
    		exp2=lam_tron_len(exp2+ static_cast<double>(e1)/4+19);
		}else if((e1>=20) && (e1<=49)){
			exp2=lam_tron_len(exp2+ static_cast<double>(e1)/9+21);
		}else if((e1>=50) && (e1<=65)){
			exp2=lam_tron_len(exp2+ static_cast<double>(e1)/16+17);
		}else if((e1>=66) && (e1<=79)){
			exp2=lam_tron_len(exp2+ static_cast<double>(e1)/4+19);
			if(exp2>200){
				exp2=lam_tron_len(exp2+ static_cast<double>(e1)/9+21);
			}
		}else if((e1>=80) && (e1<=99)){
			exp2=lam_tron_len(exp2+ static_cast<double>(e1)/4+19);
			exp2=lam_tron_len(exp2+ static_cast<double>(e1)/9+21);
			if(exp2>400){
				exp2=lam_tron_len(exp2+ static_cast<double>(e1)/16+17);
				exp2=lam_tron_len(static_cast<double>(exp2)*1.15);
			}
		}
		exp1= exp1-e1;
		kiemtraEXP(exp1);
		kiemtraEXP(exp2);
	}
    //het truong hop 2
    return exp1 + exp2;
}
//
// Task 2
//su kien 1
void sk1_cd2(int & HP1, int & M_da_dung, int & M1){
	if(HP1<200){
		HP1=lam_tron_len(static_cast<double>(HP1)*1.3);
		kiemtraHP(HP1);
		M1=M1-150;
		kiemtraM(M1);
		M_da_dung+=150;
	}else{
		HP1=lam_tron_len(static_cast<double>(HP1)*1.1);
		kiemtraHP(HP1);
		M1=M1-70;
		kiemtraM(M1);
		M_da_dung+=70;
	}
}
//su kien 2
void sk2_cd2(int & EXP1, int & M1,int & M_da_dung ){
	if(EXP1<400){
		M1=M1-200;
		kiemtraM(M1);
		M_da_dung+=200;
	}else{
		M1=M1-120;
		kiemtraM(M1);
		M_da_dung+=120;
	}
	EXP1=lam_tron_len(static_cast<double>(EXP1)*1.13);
	kiemtraEXP(EXP1);
}
//su kien 3
void sk3_cd2(int & EXP1, int & M1, int & M_da_dung){
	if(EXP1<300){
		M1-=100;
		kiemtraM(M1);
		M_da_dung+=100;
	}else{
		M1-=120;
		kiemtraM(M1);
		M_da_dung+=120;
	}
	EXP1=lam_tron_len(static_cast<double>(EXP1)*0.9);
	kiemtraEXP(EXP1);
}
int scp_gn(int n){
	int a[25];
	for(int i=0; i<=24; i++){
		if(i*i > n){
			a[i]=i*i-n;
		}else{
			a[i]=n-i*i;
		}
	}
	int kq;
	int min=a[0];
	for(int i=1; i<=24; i++){
		if(a[i]<min){
			min=a[i];
			kq=i*i;
		}
	}
	return kq;
}
void road_2(int & HP1, int & EXP1, int & M1, int E2, int nua_M, int & M_da_dung){
	//E2 le
	if(E2%2!=0){
		//su kien 1
		sk1_cd2(HP1, M_da_dung, M1);
		//
		if(M_da_dung>nua_M){
			return;
		}
		//su kien 2
		sk2_cd2(EXP1, M1, M_da_dung);
		//
		if(M_da_dung>nua_M){
			return;
		}
		//su kien 3
		sk3_cd2(EXP1, M1, M_da_dung);
		//
		if(M1<0){
			M1=0;
		}
		if(M_da_dung>nua_M){
			return;
	 }else{
			return road_2(HP1, EXP1, M1, E2, nua_M, M_da_dung);
		}
	}
	//
	//E2 chan
	if(E2%2==0){
	//su kien 1
	sk1_cd2(HP1, M_da_dung, M1);
	//
	if(M1<0){
		M1=0;
		return;
	}
	//su kien 2
	sk2_cd2(EXP1, M1, M_da_dung);
	//
	if(M1<0){
		M1=0;
		return;
	}
	//su kien 3
	sk3_cd2(EXP1, M1, M_da_dung);
	//
	if(M1<0){
		M1=0;
		return;
	}
}
}
void road_3(double & p3, int E2){
	double p[10]={0.32,0.47,0.28,0.79,1.0,0.5,0.22,0.83,0.64,0.11};
	int hang_chuc;
	int hang_don_vi;
	int hdv;
	if(E2/10==0){
		p3=p[E2];
	}else{
		hang_chuc=E2/10;
		hang_don_vi=E2%10;
		hdv=(hang_chuc+hang_don_vi)%10;
		p3=p[hdv];
	}
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if((E2>99)||(E2<0)){
    	return -99;
	}
   	double p1,p2,p3,Pt;
	//
	//con duong 1

	if(EXP1>=scp_gn(EXP1)){
		p1=1.0;
	}else{
		p1=(static_cast<double>(EXP1)/scp_gn(EXP1) +80)/123;
	}
	//het con duong 1
	//
	//con dong 2
	int nua_M=M1/2;
	int M_da_dung=0;
	road_2(HP1, EXP1, M1, E2, nua_M, M_da_dung);
	EXP1=lam_tron_len(static_cast<double>(EXP1)*1.17);
	HP1=lam_tron_len(static_cast<double>(HP1)*0.83);
	kiemtraEXP(EXP1);
	kiemtraHP(HP1);
	//het con duong 2
	if(EXP1>=scp_gn(EXP1)){
		p2=1.0;
	}else{
		p2=(static_cast<double>(EXP1)/scp_gn(EXP1 +80))/123;
	}
	//
	//con duong 3
	road_3(p3, E2);
	//het con duong 3
	if((p1==1.0)&&(p2==1.0)&&(p3==1.0)){
		EXP1=EXP1*0.75;
		return traceLuggage(HP1, EXP1, M1, E2);
	}else{
	Pt=(p1+p2+p3)/3;
	if(Pt>0.5){
		HP1= lam_tron_len(static_cast<double>(HP1)*0.9);
		EXP1= lam_tron_len(static_cast<double>(EXP1)*1.2);
		kiemtraEXP(EXP1);
		kiemtraHP(HP1);
		
	}else{
		HP1= lam_tron_len(static_cast<double>(HP1)*0.85);
		EXP1= lam_tron_len(static_cast<double>(EXP1)*1.15);
		kiemtraEXP(EXP1);
	kiemtraHP(HP1);
	kiemtraEXP(EXP1);	
}

}
		 return HP1 + EXP1 + M1;
}
//
// Task 3
//khai bao hang trong task 3
const int ROWS=10;
const int COLS=10;
//
//ham lam so co 2 chu so thanh so co 1 chu so
int doi_2_thanh_1(int a){
	if(a/10<=0){
		return a;
	}else{
		int b=a%10;
		int c=a/10;
		return doi_2_thanh_1(b+c);
	}
}
//
//ham tinh tri tuyet doi
int tri_tuyet_doi_1(int a){
	if(a<0){
		return -a;
	}else{
		return a;
	}
}
//
//gia tri lon nhat
int gt_ln(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
} 
//
//gia tri nho nhat
int gt_nn(int a, int b){
	if(a>b){
		return b;
	}else{
		return a;
	}
} 
//
//gia tri lon nhat cua cheo trai
int gia_tri_lon_nhat_cheo_trai(int matrix[ROWS][COLS], int row, int col){
    int maxVal = matrix[row][col]; // khoi tao gia tri lon nhat
    // duyet len tren qua trai
    for (int r = row - 1, c = col - 1; r >= 0 && c >= 0; --r, --c){
        maxVal = gt_ln(maxVal, matrix[r][c]);
    }
	//
    // Duyet xong duoi va qua phai
    for (int r = row + 1, c = col + 1; r < ROWS && c < COLS; ++r, ++c){
        maxVal = gt_ln(maxVal, matrix[r][c]); // So sánh và c?p nh?t giá tr? l?n nh?t
    }
	//
    return maxVal;
}
//
// gia tri lon nhat cua cheo phai
int gia_tri_lon_nhat_cheo_phai(int matrix[ROWS][COLS], int row, int col){
    int maxVal = matrix[row][col];

    // Duyet len tren va qua phai
    for (int r = row - 1, c = col + 1; r >= 0 && c < COLS; --r, ++c){
        maxVal = gt_ln(maxVal, matrix[r][c]);
    }

    // Duyet xuong duoi va qua trai
    for (int r = row + 1, c = col - 1; r < ROWS && c >= 0; ++r, --c) {
        maxVal = gt_ln(maxVal, matrix[r][c]); 
    }
    //
    return maxVal;
}
//
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3){
    // TODO: Complete this function
    if((E3>99)||(E3<0)){
    	return -99;
	}
    int duong=0;
    int am=0;
	    int matrix[10][10]={0};
	//duyet gia tri cho ma tran
	for(int i=0; i<=9; i++){
		for(int j=0; j<=9; j++){
			matrix[i][j]=((E3 * j) + (i * 2)) * (i - j);
			if(matrix[i][j]>E3*2){
				duong = duong +1;
			}else if(matrix[i][j]< -E3){
				am = am +1;
			}
		}
	}
	duong = doi_2_thanh_1(duong);
	am = doi_2_thanh_1(am);
	//gap nhau tai diem co toa do la 
	//
	//tao ma tran de chua diem cua sherlock va watson
	int newmatrix[10][10]={};
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			int max_of_left=gia_tri_lon_nhat_cheo_trai(matrix, i, j);
			int max_of_right=gia_tri_lon_nhat_cheo_phai(matrix, i, j);
			newmatrix[i][j]=tri_tuyet_doi_1(gt_ln((max_of_left),(max_of_right)));
		}
	}
	if(tri_tuyet_doi_1(matrix[duong][am])>newmatrix[duong][am]){
		EXP1=lam_tron_len(static_cast<double>(EXP1)*0.88);
		HP1=lam_tron_len(static_cast<double>(HP1)*0.9);
		EXP2=lam_tron_len(static_cast<double>(EXP2)*0.88);
		HP2=lam_tron_len(static_cast<double>(HP2)*0.9);
		kiemtraEXP(EXP1);
		kiemtraHP(HP1);
		kiemtraEXP(EXP2);
		kiemtraHP(HP2);		
		return matrix[duong][am];
	}else{
		EXP2=lam_tron_len(static_cast<double>(EXP2)*1.12);
		HP2=lam_tron_len(static_cast<double>(HP2)*1.1);	
		EXP1=lam_tron_len(static_cast<double>(EXP1)*1.12);
		HP1=lam_tron_len(static_cast<double>(HP1)*1.1);	
		kiemtraEXP(EXP1);
		kiemtraHP(HP1);
		kiemtraEXP(EXP2);
		kiemtraHP(HP2);	
		return newmatrix[duong][am];
	}
    
}
//

// Task 4
//
// Ham tinh chieu dai cua chuoi
int stringL(const char* s){
    int len = 0;
    while (s[len] != '\0'){
        len++;
    }
    return len;
}
//
// ham tim vi tri cua chuoi con tron chuoi
int find_vi_tri(const char* s, const char* sub){
    int subLen = stringL(sub);
    int len = stringL(s);

    for (int i = 0; i <= len - subLen; i++){
        int j;
        for (j = 0; j < subLen; j++){
            if (s[i + j] != sub[j]){
                break;
            }
        }
        if (j == subLen){
            return i;
        }
    }
    return -1;
}
//
int checkPassword(const char* s, const char* email){
    // chieu dai toi thieu va toi da cua mat khau
    const int minL = 8;
    const int maxL = 20;
	//
    // kiem tra do dai cua mat khau
    int len = stringL(s);
    if (len < minL){
        return -1;
    }
    if (len > maxL){
        return -2;
    }
	//
    // tim vi tri chuoi se trong mat khau
    int Vi_tri_Se = find_vi_tri(s, "se");
    if (Vi_tri_Se != -1){
        return -(300 + Vi_tri_Se);
    }
	//
    // kiem tra mat khau co chua ki tu dac biet hay khon
    bool ki_tu_db = false;
    for (int i = 0; i < len; i++){
        char c = s[i];
        if (c == '#' || c == '#' || c == '!' || c == '$' || c == '@'){
            ki_tu_db = true;
            break;
        }
    }
    if (!ki_tu_db) {
        return -5;
    }
	//
    //kiem tra 2 ki tu lien tiep 
    for (int i = 0; i < len - 2; ++i){
        if (s[i] == s[i + 1] && s[i] == s[i + 2]){
            return -(400 + i);
        }
    }
	//
    // lay chuoi se
    int posAt = find_vi_tri(email, "@");
    char se[101];
    for (int i = 0; i < posAt; i++) {
        se[i] = email[i];
    }
    se[posAt] = '\0';
	//
    // kiem tra mat khau co se khong
    int t = find_vi_tri(s, se);
    if (t != -1) {
        return -(300 + t);
    }
	//
    return -10;
}
//

// Task 5
// so sanh chuoi
bool strE(const char* s1, const char* s2){
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] != s2[i]){
            return false;
        }
        i++;
    }
    return s1[i] == '\0' && s2[i] == '\0';
}
//
//
int findCorrectPassword(const char * arr_pwds[], int num_pwds){
    // TODO: Complete this function
int max_dem = 0;
    int max_of_do_dai = 0;
    char mat_khau_chinh_xac[20] = "";
    int vi_tri = -1;

    for (int i = 0; i < num_pwds; ++i){
        int t = 1;
        int l = stringL(arr_pwds[i]);

        bool counted = false;
        for (int j = 0; j < i; ++j) {
            if (strE(arr_pwds[i], arr_pwds[j])){
                counted = true;
                break;
            }
        }
        if (!counted){
            for (int j = i + 1; j < num_pwds; ++j){
                if (strE(arr_pwds[i], arr_pwds[j])){
                    t++;
                }
            }
            //cap nhat mat khau dung
            if (t > max_dem || (t == max_dem && l > max_of_do_dai)){
                max_dem = t;
                max_of_do_dai = l;
                for (int k = 0; k < l; ++k){
                    mat_khau_chinh_xac[k] = arr_pwds[i][k];
                }
                mat_khau_chinh_xac[l] = '\0';
                vi_tri = i;
            }
        }
    }
    return vi_tri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
