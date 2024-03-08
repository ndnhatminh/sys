

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
//kiem tra exp
int checkexp(int & exp) {
    if (exp < 0) exp = 0;
    if (exp > 600) exp = 600;
    return exp;
    }
// kiem tra HP
int checkhp(int &hp) {
    if (hp < 0) hp = 0;
    if (hp > 666) hp = 666;
    return hp;
}
// kiem tra M
int checkm(int &m) {
    if (m < 0) m = 0;
    if (m > 3000) m = 3000;
    return m;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1<0 || e1>99) {
        return -99;
    }
    else {
    exp1 = checkexp(exp1);
    exp2 = checkexp(exp2);
    // truong hop 1
    if (e1>=0 && e1<4) {
        if (e1==0) exp2 += 29;
        else if (e1==1) exp2 += 45;
        else if (e1==2) exp2 += 75;
        else exp2 += 149;
        exp2 = checkexp(exp2);
        int D = e1*3 + exp1*7;
        if(D%2 == 0) exp1 = ceil(exp1 + D*1.0000/200);
        else exp1 = ceil(exp1 - D*1.0000/100);
        exp1 = checkexp(exp1);
    }
    //truong hop 2
    else if (e1>3 && e1<100) {
        if (e1>3 && e1<20) exp2 = ceil(exp2 + e1*1.0000/4 + 19 - 0.00001);
        else if (e1>19 && e1<50) exp2 = ceil(exp2 + e1*1.0000/9 + 21 - 0.00001);
        else if (e1>49 && e1<66) exp2 = ceil(exp2 + e1*1.0000/16 + 17 - 0.00001);
        else if (e1>65 && e1<80) {
            exp2 = ceil(exp2 + e1*1.0000/4 + 19 - 0.00001);
            if (exp2 > 200) exp2 = ceil(exp2 + e1*1.0000/9 + 21 - 0.00001);
        }
        else {
            exp2 = ceil(exp2 + e1*1.0000/4 + 19 - 0.00001);
            exp2 = ceil(exp2 + e1*1.0000/9 +21 - 0.00001);
            if (exp2 > 400) {
                exp2 = ceil(exp2 + e1*1.0000/16 + 17 - 0.00001);
                exp2 = ceil(exp2*1.15 - 0.00001);
            }
        }
        exp2 = checkexp(exp2);
        exp1 -=e1;
        exp1 = checkexp(exp1);
    }
    return exp1 + exp2;
    }
}


// Task 2
// tinh xac suat
float xacsuat(int & EXP) {
 float P;
 float S;  // so chinh phuong gan EXP nhat
 int nho = sqrt(EXP);
 int lon = nho + 1;
 if ((EXP-nho*nho)<(lon*lon-EXP)) P=100;
 else {
    S = lon*lon;
    P = (EXP*1.0000/S+80*1.0000)/123*100.0000;
 }
return P;
}
// nhiem vu 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
//kiem tra E
if(E2<0 || E2>99)
return -99;
else {
checkhp(HP1);
checkexp(EXP1);
checkm(M1);
float P1, P2, P3, P;
// con duong 1
P1 = xacsuat(EXP1);
//con duong 2
if (E2%2 != 0) {
float tien = M1;
float dung = 0;
while (dung <= (0.5*tien) && M1 !=0) {
 // mua thuc an nuoc uong
 if(HP1 < 200) {
    HP1 = ceil(HP1*1.3 - 0.00001);
    M1 -= 150;
 }
 else {
    HP1 = ceil(HP1*1.1 - 0.00001);
    M1 -=70;
 }
 checkhp(HP1);
 checkm(M1);
 dung = tien - M1;
 if (dung > (0.5*tien) ) break;
  //thue taxi hoac ngua
  if(EXP1 < 400) M1 -= 200; // taxi
  else M1 -= 120; //ngua
  checkm(M1);
  EXP1 = ceil(EXP1*1.13 - 0.00001);
  checkexp(EXP1);
  dung = tien - M1;
  if (dung > (0.5*tien)) break;
  //gap nguoi vo gia cu
  if(EXP1 < 300) M1 -= 100;
  else M1 -= 120;
  checkm(M1);
  EXP1 = ceil(EXP1*0.9 - 0.00001);
  checkexp(EXP1);
  dung = tien - M1;
  if(dung > (0.5*tien)) break;
}
}
else {
int lap = 0;
while (lap == 0) {
if (M1 == 0) break;
     // mua thuc an nuoc uong
 if(HP1 < 200) {
    HP1 = ceil(HP1*1.3 - 0.00001);
    M1 -= 150;
 }
 else {
    HP1 = ceil(HP1*1.1 - 0.00001);
    M1 -=70;
 }
 checkhp(HP1);
 checkm(M1);
 if (M1 == 0 ) break;
  //thue taxi hoac ngua
  if(EXP1 < 400) M1 -= 200; // taxi
  else M1 -= 120; //ngua
  checkm(M1);
  EXP1 = ceil(EXP1*1.13 - 0.00001);
  checkexp(EXP1);
  if (M1 == 0) break;
  //gap nguoi vo gia cu
  if(EXP1 < 300) M1 -= 100;
  else M1 -= 120;
  checkm(M1);
  EXP1 = ceil(EXP1*0.9 - 0.00001);
  checkexp(EXP1);
  if(M1 == 0) break;
  lap = 1;
}
}
//di bo den cuoi
HP1 = ceil(HP1*0.83 - 0.00001);
checkhp(HP1);
EXP1 = ceil(EXP1*1.17 - 0.0001);
checkexp(EXP1);
P2 = xacsuat(EXP1);
// con duong 3
int xs[10]={32,47,28,79,100,50,22,83,64,11};
int i; // chi so xac suat
if (E2 < 10) i = E2;
else {
    int chuc = E2/10;
    int donvi = E2%10;
    i = (chuc+donvi)%10;
}
P3 = xs[i];
// ca 3 duong
if ((P1+P2+P3) == 300) {
EXP1 = ceil(EXP1*0.75 - 0.00001);
checkexp(EXP1);
}
else {
P = (P1+P2+P3)*1.0000/3;
if(P < 50) {
HP1 = ceil(HP1*0.85 - 0.00001);
checkhp(HP1);
EXP1 = ceil(EXP1*1.15 - 0.00001);
checkexp(EXP1);
}
else {
HP1 = ceil(HP1*0.9 - 0.00001);
checkhp(HP1);
EXP1 = ceil(EXP1*1.2 - 0.00001);
checkexp(EXP1);
}
}
    return HP1 + EXP1 + M1;
}
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
if (E3 < 0 || E3 > 99) {
   return -99;
}
else {
HP1 = checkhp(HP1);
HP2 = checkhp(HP2);
EXP1 = checkexp(EXP1);
EXP2 = checkexp(EXP2);
int matran[10][10] = {}; //khoi tao ma tran
//nhap gia tri cho ma tran
for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++)
        matran[i][j] = ((E3*j) + (i*2))*(i-j);
}
int x = 0, y = 0; // diem gap nhau
for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j ++) {
        if(matran[i][j] > (E3*2)) x +=1;
        if(matran[i][j] < (-E3)) y +=1;
    }
}
while (x > 9) {
    int chucx = x/10;
    int donvix = x%10;
    x = chucx + donvix;
}
while (y > 9) {
    int chucy = y/10;
    int donviy = y%10;
    y = chucy + donviy;
}
int taxi = matran[x][y]; // diem taxi tai diem gap nhau
int nguoi = taxi; // diem cua 2 nguoi tai diem gap nhau
int a = x, b = y;
while (a>=0 && a<10 && b>=0 && b<10) {
    a++;
    b++;
    if (matran[a][b] > nguoi) nguoi = matran[a][b];
}
a = x; b = y;
while (a>=0 && a<10 && b>=0 && b<10) {
    a--;
    b--;
    if (matran[a][b] > nguoi) nguoi = matran[a][b];
}
a = x; b = y;
while (a>=0 && a<10 && b>=0 && b<10) {
    a++;
    b--;
    if (matran[a][b] > nguoi) nguoi = matran[a][b];
}
a = x; b = y;
while (a>=0 && a<10 && b>=0 && b<10) {
    a--;
    b++;
    if (matran[a][b] > nguoi) nguoi = matran[a][b];
}
if (abs(taxi) <= nguoi) {
 EXP1 = ceil(EXP1*1.12 - 0.00001);
 HP1 = ceil(HP1*1.1 - 0.00001);
 EXP2 = ceil (EXP2*1.12 - 0.00001);
 HP2 = ceil(HP2*1.1 - 0.000001);
}
else {
    EXP1 = ceil(EXP1*0.88 - 0.00001);
    HP1 = ceil(HP1*0.9 - 0.00001);
    EXP2 = ceil(EXP2*0.88 - 0.00001);
    HP2 = ceil(HP2*0.9 - 0.00001);
}
EXP1 = checkexp(EXP1);
EXP2 = checkexp(EXP2);
HP1 = checkhp(HP1);
HP2 = checkhp(HP2);
if (nguoi >= abs(taxi)) return nguoi;
else return taxi;
}
}


// Task 4
int checkPassword(const char * s, const char * email) {
int l = 0; // do dai cua mat khau
while( s[l] != '\0' ) l++;
char se[100] = {};
for(int i = 0; i <100; i++) {
    if(email[i] != '@')
    se[i] = email[i];
    else break;
}
int lm=0; // do dai se
while (se[lm] != '\0') lm++;
// kiem tra s co trung se khong
bool trung = true;
for(int i = 0; i < lm; i++) {
    trung = true;
    for(int j = 0; j < l; j++){
        if(se[i] != s[j])
        trung = false;
        else {
            trung = true;
            break;
        }
    }
}

//kiem tra ki tu dac biet
bool kitudb = false;
for(int i = 0; i < l; i++) {
    if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')
    kitudb = true;
    break;
}

// 2 ki tu lien tiep
bool kitult = false;
int vitrikt;
for(int i=0; i < l; i++) {
    if((s[i] == s[i+1]) && (s[i+1] == s[i+2]))
    kitult = true;
    vitrikt = i; 
    break;
}

if (l > 7 && l < 21 && !trung && !kitult && kitudb) return -10;
else if (l < 8) return -1; // do dai duoi 8
else if (l > 20) return -2; // do dai qua 20
else if(trung) {
    for(int i = 0; i < l; i++) {
    if(s[i] == se[0]) {
         return -(300 + i);
         break;
    }
}
}
else if(kitult) {
    return -(400 + vitrikt);
}
else if (!kitudb) {
    return -5;
}

return 100;
} 




// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
int vitri; // vi tri mat khau
int max = 0; //so luong mat khau nhieu nhat
int lmax = 0; // chieu dai chuoi dai nhat
int count = 0; // dem
int a[30] ={}; // mang danh dau
string pass0, pass; // mat khau luu tam va mat khau dung
for (int i=0; i < num_pwds; i++) {
count = 0;
for(int j=0; j < num_pwds; j++) {
if (arr_pwds[i]==arr_pwds[j] && a[j] ==0) {
count +=1;
a[j] =1;
}
}
pass0 = arr_pwds[i];
if ((count > max)||((count==max) && (pass0.size() > lmax)) ) {
max = count;
pass = pass0;
lmax = pass.size();
}
}
for(int i=0; i < num_pwds; i++) {
if(arr_pwds[i] == pass) {
vitri = i; 
break;
}
}
return vitri;
}


////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////



