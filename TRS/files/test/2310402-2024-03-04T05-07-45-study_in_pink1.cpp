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
int checkHP(int HP){
    if(HP<0) HP=0;
    else if(HP>666) HP=666;
    else;
    return HP;
}
int checkEXP(int EXP){
    if(EXP<0) EXP=0;
    else if(EXP>600) EXP=600;
    else;
    return EXP;
}
int checkM(int M){
    
    if(M<0) M=0;
    else if(M>3000) M=3000;
    else;
    return M;
}
int sochinhphuong(int EXP1){
    double a,b;
    int t;
    a=ceil(sqrt(EXP1));
    b=floor(sqrt(EXP1));
    if(abs(a*a-EXP1)<abs(b*b-EXP1)) t=a*a;
    else if(abs(a*a-EXP1)>abs(b*b-EXP1)) t=b*b;
    return t;
}
bool soluong(int n) {
	if (n >= 8 && n <= 20) return true;
	else return false;
}
bool kitu(string s) {
	int t = 0;
	char ch[100] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
		,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'@','#','%','$','!','1','2','3','4','5','6','7','8','9','0'};
	for (int i = 0; i < s.size(); i++) {
		for (int a = 0; a <= 67; a++) {
			if (s[i] == ch[a]) {
				t++;
				break;
			}
			else;
		}
	}
	if (t == s.size()) return true;
	else return false;
}
bool chua_se(string s, string se) {
	string a, b;
	int t = 0, k, kq = 0, n;
	n = s.size();
	for (int i = 0; i < s.size(); i++) {
			a = s.substr(i, n);
			b = se;
			if (a == b && kq == 0) {
				kq++;
			}
	}
	if (kq > 0) return true;
	else return false;
}
int tinh_sei(string s, string se) {
	string a, b;
	int t = 0, k, kq = 0, n,sei=0;
	n = se.size();
	for (int i = 0; i < s.size(); i++) {
		a = s.substr(i, n);
		b = se;
		if (a == b && kq == 0) {
			sei = i;
			kq++;
		}
	}
	return sei;
}
bool lientiep(string s) {
	int t = 0, r, l, kq = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) continue;
		else {
			l = i - 1;
			r = i;
			if (s[r] = s[l]) kq++;
			else;
		}
	}
	if (kq != 0) return true;
	else return false;
}int tinh_sci(string s) {
	int t = 0, r, l, kq = 0,sci=0;
	for (int i = 0; i < s.size(); i++) {
		if (i == 0) continue;
		else {
			l = i - 1;
			r = i;
			if (s[r] = s[l]) {
				if (kq == 0) {
					kq++;
					sci = i;
				}
			}
		}
	}
	return sci;
	}
bool ktdb(string s) {
	int t = 0;
	char ch[5] = { '@','#','%','$','!' };
	for (int i = 0; i < s.size(); i++) {
		for (int a = 0; a < 5; a++)
			if (s[i] == ch[a]) t++;
	}
	if (t > 0) return true;
	else return false;
}
int length(const char* pwds) {
	string s(pwds);
	int t = 0;
	char ch[100] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
		,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
		'@','#','%','$','!','1','2','3','4','5','6','7','8','9','0' };
	for (int i = 0; i < s.size(); i++) {
		for (int a = 0; a <= 67; a++) {
			if (s[i] == ch[a]) {
				t++;
				break;
			}
			else;
		}
	}
	return t;
}
//Task 1
int firstMeet(int & exp1, int & exp2, int e1){ 
    double E1=e1,Exp1=exp1,Exp2=exp2;
    if(E1<0 || E1>99) return -99;
    else if(E1>=0 && E1<=3){ 
        int d;
        d=E1*3+Exp1*7;
        if(E1==0) Exp2+=29;
        else if(E1==1) Exp2+=45;
        else if(E1==2) Exp2+= 75;
        else if(E1==3) Exp2+=29+45+75;
        Exp1=checkEXP(Exp1);
        if(d%2==0) Exp1+=(d/200);
        else Exp1-=(d/100);
        exp1=ceil(Exp1);
        exp2=ceil(Exp2);
        exp1=checkEXP(exp1);
    }
    else if(E1>=4 && E1<=99){
        if(E1>=4 && E1<=19) Exp2+=(E1/4+19);
        else if(E1>=20 && E1<=49) Exp2+=(E1/9+21);
        else if(E1>=50 && E1<=65) Exp2+=(E1/16+17); 
        else if(E1>=66 && E1<=79){
            Exp2+=(E1/4+19);
            if(Exp2>200) Exp2+=(E1/9+21);
        }
        else if(E1>=80 && E1<=99){
            Exp2+=(E1/4+19)+(E1/9+21);
            if(Exp2>400){
                 Exp2=(Exp2+(E1/16+17))*1.15;
                 if(Exp2>600) Exp2=600;
            }}
        exp1=ceil(Exp1-E1);
        exp2=ceil(Exp2);
        Exp2=checkEXP(Exp2);
}
    return exp1 + exp2;
}
// Task 2

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    double S, P,P1={}, P2 = {}, hp1 = HP1, exp1 = EXP1, m1 = M1, mang[10] = { 32,47,28,79,100,50,22,83,64,11 }, P3;
    int t = 0,  pay = 0;
    if (E2 >= 0 && E2 <= 99) {
        M1 = checkM(M1);
        //Duong so 1
        S = sochinhphuong(EXP1);
        if (EXP1 >= S) P1 = 1;
        else if (EXP1 < S) P1 = ((EXP1 / S) + 80) / 123;
        // << "P1= " << P1 << endl;
        //Duong so 2
        if (E2 % 2 != 0) {
            while (pay < m1 / 2) {
                //Su kien 1
                if (HP1 < 200) {
                    hp1 *= 1.30;
                    pay += 150;
                }
                else if (HP1 >= 200) {
                    hp1 *= 1.10;
                    pay += 70;
                }
                HP1 = ceil(hp1);
                HP1 = checkHP(HP1);
                // << "HP1= " << HP1;
                if (pay >= m1 / 2) break;
                //Su kien 2
                else {
                    hp1 = HP1;
                    if (exp1 < 400) pay += 200;
                    else if (exp1 >= 400) pay += 120;
                    exp1 *= 1.13;
                    EXP1 = ceil(exp1);
                    EXP1 = checkEXP(EXP1);
                    // << " EXP1= " << EXP1;
                    if (pay >= m1 / 2) break;
                    else {
                        exp1 = EXP1;
                        if (exp1 < 300) pay += 100;
                        else if (exp1 >= 300) pay += 120;
                        exp1 *= 0.9;
                        EXP1 = ceil(exp1);
                        EXP1 = checkEXP(EXP1);
                        // << " EXP1= " << EXP1<<endl;
                    }
                    if (pay >= m1 / 2) break;
                }
            }
        }
        else if (E2 % 2 == 0) {
            while (pay < m1) {
                if (HP1 < 200) {
                    hp1 *= 1.30;
                    pay += 150;
                }
                else if (HP1 >= 200) {
                    hp1 *= 1.10;
                    pay += 70;
                }
                HP1 = ceil(hp1);
                HP1 = checkHP(HP1);
                if (pay >= m1) break;
                else {
                    hp1 = HP1;
                    if (exp1 < 400) pay += 200;
                    else if (exp1 >= 400) pay += 120;
                    exp1 *= 1.13;
                    EXP1 = ceil(exp1);
                    EXP1 = checkEXP(EXP1);
                    if (pay >= m1) break;
                    else {
                        exp1 = EXP1;
                        if (exp1 < 300) pay += 100;
                        else if (exp1 >= 300) pay += 120;
                        exp1 *= 0.9;
                    }
                }
            }
        }
        hp1 =HP1* 0.83;
        exp1 =EXP1* 1.17;
        HP1 = ceil(hp1);
        HP1 = checkEXP(HP1);
        EXP1 = ceil(exp1);
        EXP1 = checkEXP(EXP1);
        M1 -= pay;
        S = sochinhphuong(EXP1);
        if (EXP1 >= S) P2 = 1;
        else if (EXP1 < S) P2 = ((EXP1 / S) + 80) / 123;
        // << endl<< "-2- HP1= " << HP1 << " EXP1= " << EXP1 << " M1= " << M1 << endl;
        // << "P2= " << P2 << endl;
    }
    //Duong 3
    exp1 = EXP1;
    hp1 = HP1;
    if (E2 >= 0 && E2 < 10) P3 = mang[E2];
    else {
        t = (E2 / 10 + E2 % 10) % 10;
        P3 = mang[t]/100;
        // << P3 << endl;
    }
    P = (P1 + P2 + P3) / 3;
    // << P<<endl;
    if (P == 1) {
        exp1 *= 0.75;
    }
    else if (P != 1) {
        if (P < 0.50) {
            hp1 *= 0.85;
            exp1 *= 1.15;
        }
        else if (P >= 0.50) {
            hp1 *= 0.90;
            exp1 *= 1.20;
        }
    }
    HP1 = ceil(hp1);
    HP1 = checkEXP(HP1);
    EXP1 = ceil(exp1);
    EXP1 = checkEXP(EXP1);
    return HP1 + EXP1 + M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int taxi[10][10] = {}, SW[10][10] = {},so_duong = 0, so_am = 0, a, b, max_cheophai, max_cheotrai,maxf;
    double hp1 = HP1, exp1 = EXP1, hp2 = HP2, exp2 = EXP2;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (taxi[i][j] > E3 * 2) so_duong++;
            else if (taxi[i][j] < -E3) so_am++;
        }
    }
    while (so_duong >= 10) so_duong = so_duong / 10 + so_duong % 10;
    while (so_am >= 10) so_am = so_am / 10 + so_am % 10;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            max_cheotrai = 0;
            max_cheophai = 0;
            //cheophai_xuong
            a = i;
            b = j;
            while (a >= 0 && b >= 0 && a<10 && b<10) {
                if (taxi[a][b] > max_cheophai)
                    max_cheophai = taxi[a][b];
                a++;
                b--;
            }
            //cheophai_len
            a = i;
            b = j;
            while (a >= 0 && b >= 0 && a < 10 && b < 10) {
                if (taxi[a][b] > max_cheophai)
                    max_cheophai = taxi[a][b];
                a--;
                b++;
            }
            //cheotrai_len
            a = i;
            b = j;
            while (a >= 0 && b >= 0 && a < 10 && b < 10) {
                if (taxi[a][b] > max_cheotrai)
                    max_cheotrai = taxi[a][b];
                a--;
                b--;
            }
            //cheophai_len
            a = i;
            b = j;
            while (a >= 0 && b >= 0 && a < 10 && b < 10) {
                if (taxi[a][b] > max_cheotrai)
                    max_cheotrai = taxi[a][b];
                a++;
                b++;
            }
            SW[i][j] = max(max_cheophai, max_cheotrai);
        }
    }
    if (abs(taxi[so_duong][so_am]) > SW[so_duong][so_am]) {
        maxf = taxi[so_duong][so_am];
        EXP1 = checkEXP(ceil(exp1 * 88/100));
        HP1 = checkHP(ceil(hp1 * 90/100));
        EXP2 = checkEXP(ceil(exp2 * 88/100));
        HP2 = checkHP(ceil(hp2 * 90/100));
    }
    else if (abs(taxi[so_duong][so_am]) <= SW[so_duong][so_am]) {
        maxf = SW[so_duong][so_am];
        EXP1 = checkEXP(ceil(exp1 * 112/100));
        HP1 = checkHP(ceil(hp1 * 110/100));
        EXP2 = checkEXP(ceil(exp2 * 112/100));
        HP2 = checkHP(ceil(hp2 * 110/100));
    }
    return maxf;
}

// Task 4
int checkPassword(const char * S, const char * EMAIL) {
string email(EMAIL);
string s(S);
string se;
// << email << endl << s << endl;
int n = s.size(), k = 0,kq=0, sei = 0, sci;
se = email;
for (int i = 0; i < se.size(); i++) {
	if (se[i] == '@')
		se.erase(se.begin() + i, se.end());
}
// << se << endl;
if (soluong(n) && kitu(s) && !chua_se(s, se) && !lientiep(s) && ktdb(s)) kq= -10;
else {
	if (!soluong(n)) {
		if (n < 8) {
			kq= -1;
		}
		else if (n > 10) {
			kq= -2;
		}
	}
	else if (soluong(n)) {
		if (chua_se(s, se)) {
			sei = tinh_sei(s, se);
			kq= -(300 + sei);
		}
		else if (!chua_se(s, se)) {
			if (lientiep(s)) {
				sci = tinh_sci(s);
				kq= -(400 + sci);
			}
			else if (!lientiep(s)) {
				if (!ktdb(s))
					kq= -5;
			}
		}
	}
}
    return kq;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    	char* ch[30] = {};
	int	mang[30][30] = {}, pos[30] = {}, pos_max = 0, t = 0, s = 0, max, max_len = 0, k;
	for (int i = 0; i < num_pwds; i++) mang[0][i] = 0;
	for (int i = 0; i < num_pwds; i++) {
		t = 1;
		for (int a = i + 1; a < num_pwds; a++) {
			if (mang[0][i] != -1) {
				if (arr_pwds[i] == arr_pwds[a]) {
					mang[0][a] = -1;
					t++;
				}
				else continue;
			}
		}
		if (t > 1) mang[0][i] = t;
		else if (t == 1 && mang[0][i] != -1) mang[0][i] = 0;
        }
	// << endl;
	max = mang[0][0];
	t = 1;
	for (int i = 0; i < num_pwds; i++) {
		if (mang[0][i] > max) {
			max = mang[0][i];
			pos_max = i;
		}
		else if (mang[0][i] == max) {
			t++;
		}
	}
	if (t == 1) pos_max=pos_max;
	else if (t > 1) {
		max_len = mang[1][0];
		for (int i = 0; i < num_pwds; i++) {
			if (mang[0][i] == max) {
				mang[1][i] = length(arr_pwds[i]);
				if (mang[1][i] > max_len)
					max_len = mang[1][i];
			}
			else mang[1][i] = 0;
		}
		// << endl;
		for (int i = 0; i < num_pwds; i++) {
			if (mang[1][i] == max_len) pos_max=i;
		}
	}
    return pos_max;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////