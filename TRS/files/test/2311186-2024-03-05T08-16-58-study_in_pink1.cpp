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

//Author: Nguyen Khac Khanh Huy - 2311186 - L01



void change_hp(int & hp) {
    if (hp > 666) hp = 666;
    if (hp < 0) hp = 0;
}

void change_exp(int & exp) {
    if (exp > 600) exp = 600;
    if (exp < 0) exp = 0;
}

void change_money(int & m) {
    if (m > 3000) m = 3000;
    if (m < 0) m = 0;
}

int nearest_square_number(int & exp) {
    if (exp <= 0) return 0;
    return pow(round(sqrt(exp)),2);
}

int E2_can_tim (int & E2) {
    int a = E2 % 10;
    int b = E2 / 10;
    int c = a + b;
    if (c > 9) c = c % 10;
    return c;
}

int so_can_tim (int & k) {
    do {
        int a = k % 10;
        int b = k / 10;
        k = a + b;
    } while (k > 9);
    return k;
}

bool ba_ki_tu_lt (string & s_string, int & so_ki_tu, int & sci) {
    for (int i = 0; i < so_ki_tu; i++) {
        for (int j = i + 1; j <= i+1; j++) {
            if ((s_string[i] == s_string[j]) && (s_string[j] == s_string[j+1])) {
                sci = i;
                return true;
            }
        }
    }
    return false;
}

bool ki_tu_dac_biet(string & s_string, int & so_ki_tu) {
    for (int i = 0; i < so_ki_tu; i++) {
        if (s_string[i] == '@' || s_string[i] == '#' || s_string[i] == '%' || s_string[i] == '$' || s_string[i] == '!') return true;
    }
    return false;
}

bool vi_pham(string & s_string, int & so_ki_tu, int & vi_tri_vi_pham) {
    for (int i = 0; i < so_ki_tu; i++) {
        if (((s_string[i] == ' ') || 
        (s_string[i] < '0') || 
        (s_string[i] > '9' && s_string[i] < 'A') || (s_string[i] > 'Z' && s_string[i] < 'a') || (s_string[i] > 'z'))
        && (s_string[i] != '@' && s_string[i] != '#' && s_string[i] != '%' && s_string[i] != '$' && s_string[i] != '!')) {
            vi_tri_vi_pham = i;
            return true;
        }
    }
    return false;
}

int ket_qua(int & num_pwds, int so_lan_xuat_hien[], int do_dai_chuoi[], int & vi_tri_tra_ve) {
    int max = so_lan_xuat_hien[0];
    int dai_max = do_dai_chuoi[0];
    for (int i = 1; i < num_pwds; i++) {
        if ((so_lan_xuat_hien[i] > max) || ((so_lan_xuat_hien[i] == max) && (do_dai_chuoi[i] > dai_max))) {
            max = so_lan_xuat_hien[i];
            dai_max = do_dai_chuoi[i];
            vi_tri_tra_ve = i;
        }
    }
    return vi_tri_tra_ve;
}

int ceil1(float & a) {
    a += 0.9999;
    return a;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (e1 < 0 || e1 > 99) return -99;
    else {
        change_exp(exp1);
        change_exp(exp2);
        float exp1_float, exp2_float;
        if (0 <= e1 && e1 <= 3) {
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
            change_exp(exp2);
            int D = e1*3 + exp1*7;
            (D % 2 == 0) ? (exp1_float = exp1 + 1.0*D/200) : (exp1_float = exp1 - 1.0*D/100);
            exp1 = ceil1(exp1_float);
        } else {
            if (4 <= e1 && e1 <= 19) {
                exp2_float = exp2 + (1.0*e1/4 + 19);
                exp2 = ceil1(exp2_float);
            } else if (20 <= e1 && e1 <= 49) {
                exp2_float = exp2 + (1.0*e1/9 + 21);
                exp2 = ceil1(exp2_float);
            } else if (50 <= e1 && e1 <= 65) {
                exp2_float = exp2 + (1.0*e1/16 + 17);
                exp2 = ceil1(exp2_float);
            } else if (66 <= e1 && e1 <= 79) {
                exp2_float = exp2 + (1.0*e1/4 + 19);
                exp2 = ceil1(exp2_float);
                if (exp2 > 200) {
                    exp2_float = exp2 + (1.0*e1/9 + 21);
                    exp2 = ceil1(exp2_float);
                }
            } else {
                exp2_float = exp2 + (1.0*e1/4 + 19);
                exp2 = ceil1(exp2_float);
                exp2_float = exp2 + (1.0*e1/9 + 21);
                exp2 = ceil1(exp2_float);
                bool info5 = exp2 > 400;
                if (info5) {
                    exp2_float = exp2 + (1.0*e1/16 + 17);
                    exp2 = ceil1(exp2_float);
                    exp2_float = exp2*1.15;
                    exp2 = ceil1(exp2_float);
                }                
            }
            exp1 -= e1;
        }   
    }
    change_exp(exp1);
    change_exp(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
        change_hp(HP1);
        change_exp(EXP1);
        change_money(M1);
        float P,P1,P2,P3,hp_float,m_float,exp_float;
        float money_peak = 0.5*M1;
        int total_money_spend = 0;
        bool E2_odd_even = (E2 % 2 == 0);
    //Duong 1
        int S = nearest_square_number(EXP1);
        if (EXP1 >= S) P1 = 1.0;
        else P1 = (1.0*EXP1/S + 80)/123;
    //Duong 2
        if (M1 == 0) {
            //Di bo den cuoi duong
            hp_float = HP1 - (0.17*HP1);
            HP1 = ceil1(hp_float);
            exp_float = EXP1 + (0.17*EXP1);
            EXP1 = ceil1(exp_float);
            change_hp(HP1);
            change_exp(EXP1);

        int K = nearest_square_number(EXP1);
        if (EXP1 >= K) P2 = 1.0;
        else P2 = (1.0*EXP1/K + 80)/123;
        }
        else {
            do {
        //HP
            bool check_hp = HP1 < 200;
            if (check_hp) {
                hp_float = HP1 + (0.3*HP1);
                HP1 = ceil1(hp_float);
                M1 -= 150;
                total_money_spend += 150;
            } else {
                hp_float = HP1 + (0.1*HP1);
                HP1 = ceil1(hp_float);
                M1 -= 70;
                total_money_spend += 70;
            }
            change_hp(HP1);
            change_money(M1);
            if (M1 <= 0) break;
            else if ((!E2_odd_even) && (total_money_spend > money_peak)) break;
        //Taxi va ngua
            bool check_exp = EXP1 < 400;
            if (check_exp) {
                M1 -= 200;
                total_money_spend += 200;
            } else {
                M1 -= 120;
                total_money_spend += 120;
            }
            change_money(M1);
            exp_float = EXP1 + (0.13*EXP1);  
            EXP1 = ceil1(exp_float);
            change_exp(EXP1);
            if (M1 <= 0) break;
            else if ((!E2_odd_even) && (total_money_spend > money_peak)) break;
        //Nguoi vo gia cu
            check_exp = EXP1 < 300;
            if (check_exp) {
                M1 -= 100;
                total_money_spend += 100;
            } else {
                M1 -= 120;
                total_money_spend += 120;
            }
            exp_float = EXP1 - (0.1*EXP1);
            EXP1 = ceil1(exp_float);
            change_money(M1);
            change_exp(EXP1);
            if (M1 <= 0) break;
            else if ((!E2_odd_even) && (total_money_spend > money_peak)) break;
        } while (!E2_odd_even);
        //Di bo den cuoi duong
            hp_float = HP1 - (0.17*HP1);
            HP1 = ceil1(hp_float);
            exp_float = EXP1 + (0.17*EXP1);
            EXP1 = ceil1(exp_float);
            change_hp(HP1);
            change_exp(EXP1);

        int K = nearest_square_number(EXP1);
        if (EXP1 >= K) P2 = 1.0;
        else P2 = (1.0*EXP1/K + 80)/123;
        }

    //Duong 3
        float P_i[10] = {32,47,28,79,100,50,22,83,64,11};
        if (0 <= E2 && E2 <= 9) P3 = P_i[E2]/100;
        else {
            int i = E2_can_tim(E2);
            P3 = P_i[i]/100;
        }
    //Sau khi di het ca 3 tuyen duong
        if (P1 == 100/100 && P1 == P2 & P2 == P3) {
            exp_float = EXP1 - 1.0*25/100*EXP1;
            EXP1 = ceil1(exp_float);
            change_exp(EXP1);
            return HP1 + EXP1 + M1;
        } else P = (P1+P2+P3)/3;

        if (P < 0.5) {
            hp_float = HP1 - 1.0*15/100*HP1;
            HP1 = ceil1(hp_float);
            exp_float = EXP1 + 1.0*15/100*EXP1;
            EXP1 = ceil1(exp_float);
        } else {
            hp_float = HP1 - 1.0*10/100*HP1;
            HP1 = ceil1(hp_float);
            exp_float = EXP1 + 1.0*20/100*EXP1;
            EXP1 = ceil1(exp_float);
        }
    change_exp(EXP1);
    change_hp(HP1);
    change_money(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3 < 0 || E3 > 99) return -99;
    else {
        change_hp(HP1);
        change_exp(EXP1);
        change_hp(HP2);
        change_exp(EXP2);
        float exp1_float, hp1_float, exp2_float, hp2_float;
        int matran[10][10];
        int i,j;
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                matran[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        int count1 = 0;
        int count2 = 0;
        for (i = 0; i < 10; i++) {
    	    for (j = 0; j < 10; j++) {
    		    if (matran[i][j] > 0 && matran[i][j] > (E3*2)) count1++;
    		    else if (matran[i][j] < 0 && matran[i][j] < (-E3)) count2++;
		    }
	    }
    //Xac dinh vi tri gap nhau
        i = so_can_tim(count1);
        j = so_can_tim(count2);
        int a = i;
        int b = j;
    //Tim Max
        int max = matran[i][j];
        for (a = i; a < 10; a++) {
            if (matran[a][b] > max) max = matran[a][b];
            b--;
            if (b < 0 || b > 9) break;
        }
        //a = i;
        b = j;
        for (a = i; a < 10; a++) {
            if (matran[a][b] > max) max = matran[a][b];
            b++;
            if (b < 0 || b > 9) break;
        }
        //a = i;
        b = j;
        for (a = i; a >= 0; a--) {
            if (matran[a][b] > max) max = matran[a][b];
            b--;
            if (b < 0 || b > 9) break;
        }
        //a = i;
        b = j;
        for (a = i; a >= 0; a--) {
            if (matran[a][b] > max) max = matran[a][b];
            b++;
            if (b < 0 || b > 9) break;
        }
        if (max < 0) max = abs(max); //Diem so cua 2 nguoi
    //Duoi kip hay khong kip
        if (abs(matran[i][j]) <= max) {
            exp1_float = EXP1 + 0.12*EXP1;
            hp1_float = HP1 + 0.1*HP1;
            exp2_float = EXP2 + 0.12*EXP2;
            hp2_float = HP2 + 0.1*HP2;
            EXP1 = ceil1(exp1_float); change_exp(EXP1);
            HP1 = ceil1(hp1_float);  change_hp(HP1);
            EXP2 = ceil1(exp2_float); change_exp(EXP2);
            HP2 = ceil1(hp2_float); change_hp(HP2);
            return max;
        } else {
            exp1_float = EXP1 - 0.12*EXP1;
            hp1_float = HP1 - 0.1*HP1;
            exp2_float = EXP2 - 0.12*EXP2;
            hp2_float = HP2 - 0.1*HP2;
            EXP1 = ceil1(exp1_float); change_exp(EXP1);
            HP1 = ceil1(hp1_float); change_hp(HP1);
            EXP2 = ceil1(exp2_float); change_exp(EXP2);
            HP2 = ceil1(hp2_float); change_hp(HP2);
            return matran[i][j];
        }
    }
    return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    //Khai bao mot so ten bien
    string se;
    string email_string = email;
    string s_string = s;
    int sci = 0;
    se = email_string.substr(0,email_string.find("@"));
    int so_ki_tu = s_string.size();
    int sei = s_string.find(se);
    int vi_tri_vi_pham = 0;

    if (so_ki_tu < 8) return -1;
    else if (so_ki_tu > 20) return -2;
    else if ((0 <= sei) && (sei <= so_ki_tu)) return -(300 + sei);
    else if (ba_ki_tu_lt(s_string,so_ki_tu,sci)) return -(400 + sci);
    else if (!(ki_tu_dac_biet(s_string,so_ki_tu))) return -5;
    else if (vi_pham(s_string,so_ki_tu,vi_tri_vi_pham)) return vi_tri_vi_pham;
    else return -10;
    return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    //Truyen mang char vao mang string
    string str_pwds[num_pwds];
    for (int i = 0; i < num_pwds; ++i) {
        str_pwds[i] = arr_pwds[i];
    }
    int so_lan_xuat_hien[num_pwds];
    int do_dai_chuoi[num_pwds];

    //Dem so lan xuat hien
    for (int i = 0; i < num_pwds; i++) {
        so_lan_xuat_hien[i] = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (str_pwds[i] == str_pwds[j]) so_lan_xuat_hien[i]++;
        }
    }

    //Do dai chuoi
    for (int i = 0; i < num_pwds; i++) {
        do_dai_chuoi[i] = str_pwds[i].size();
    }
    int vi_tri_tra_ve = 0;
    int kqua = ket_qua(num_pwds,so_lan_xuat_hien,do_dai_chuoi,vi_tri_tra_ve);
    
    return kqua;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////