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
int LimitE(int e){
if (e>99||e<0) return -99;
else return e;
}
// Task 1
int firstMeet(int &exp1, int &exp2, int e1){
int D = e1*3 + exp1*7;
e1 = LimitE(e1);
if (e1 ==-99) return -99;
if (exp1 > 600) exp1 =600;
else if (exp1 <0) exp1 =0;
else exp1 =exp1;
if (exp2 > 600) exp2 =600;
else if (exp2 <0) exp2 =0;
else exp2 =exp2;

if (e1 <= 3){
	int TangExp2[4] ={29,45,75,149}      ;
  switch(e1) {
            case 0:
	exp2 += TangExp2[0];
break;
            case 1:
               exp2 += TangExp2[1];
break;
            case 2:
                exp2 += TangExp2[2];
break;
            case 3:
             	exp2 += TangExp2[3];
break;
        }
if (exp2 > 600) exp2 =600;
if((e1+exp1)%2 == 0){
            if(D%200 == 0) exp1 += D/200;
            else exp1 += D/200 + 1;
        }
else{
            exp1 = ceil(exp1 - D/100);
        }
    }
if (exp1 > 600) exp1 =600;

    if(e1 >= 4 ){
        bool banhiemvu = true;
        if( e1 <= 19){
	exp2 = ceil(exp2 + (e1 / (2*2))) + 19;
	if (exp2 > 600) exp2 =600;
        }
        if(e1 >=20 && e1 <= 49){
	exp2 = ceil(exp2 + (e1 / (3*3))) + 21;
	if (exp2 > 600) exp2 =600;
        }
        if(e1 >= 50 && e1 <= 65){
	exp2 = ceil(exp2 + (e1 / (4*4))) + 17;
	if (exp2 > 600) exp2 =600;
        }
        if(e1 >= 66 && e1 <= 79){
	exp2 = ceil(exp2 + (e1 / (2*2))) + 19;
	if (exp2 > 600) exp2 =600;
            	if(exp2 > 200){
                exp2 = ceil(exp2 + (e1 / (3*3))) + 21;
	if (exp2 > 600) exp2 =600;
            }
        }
        if(e1 >= 80){
	exp2 = ceil(exp2 + (e1 / (2*2))) + 19;
	if (exp2 > 600) exp2 =600;
               exp2 = ceil(exp2 + (e1 / (3*3))) + 21;
	if (exp2 > 600) exp2 =600;
if(exp2 > 400){
               exp2 = ceil(exp2 + (e1 / (4*4))) + 17;
	if (exp2 > 600) exp2 =600;
               banhiemvu = false;
            }
        }

        if(!banhiemvu){
            exp2 = exp2*2 - int(exp2*0.85);
	if (exp2 > 600) exp2 =600;
        }
        exp1 -=  e1;
	if (exp1 <0) exp1 =0;
    }
    exp1 = max(0, min(exp1, 600));
    exp2 = max(0, min(exp2, 600));
    return exp1 + exp2;
}
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
E2 = LimitE(E2);
if (E2 == -99) return -99;
if (EXP1 > 600) EXP1 =600;
else if (EXP1 <0) EXP1 =0;
else EXP1 =EXP1;
float P1;
int x = floor(sqrt(EXP1));
int lower = x*x;
int upper =(x+1)*(x+1);
if ((EXP1 - lower) <= (upper - EXP1)) P1 =1 ;
else P1 = (EXP1 /upper +80)/123;
    M1 = min(max(M1, 0), 3000);
    int paid = 0;
    float HALFM = M1 *0.5;
    int m = M1;
    if (E2 % 2 == 1){
        while( m >= HALFM){
            	if (HP1 < 200){
               	 HP1 =ceil(HP1*1.3 );
               	 HP1 = min(max(HP1, 0), 666);
             	 	 paid = 150;
                	m -= paid;
                	if (m < HALFM) break;
            } 
	else {
                HP1 = ceil(HP1*1.1);
                HP1 = min(max(HP1, 0), 666);
                paid =70;
                m -= paid;

                if (m < HALFM) break;
            }
            	paid = (EXP1 < 400)? 200 : 120;
            	m -= paid;
	EXP1 = ceil(EXP1*1.13);
           	EXP1 = min(max(EXP1, 0), 600);

            if (m < HALFM) break;
	paid = (EXP1 < 300)? 100 : 120;
            	m -= paid;
	EXP1 = ceil(EXP1*0.9);
            	EXP1 = min(max(EXP1, 0), 600);
            if (m < HALFM) break;

        }

            HP1 =ceil( 0.83*HP1 );
            EXP1 = ceil(1.17*EXP1) ;
            EXP1 = min(max(EXP1, 0), 600);

    }

    else {
while(true){
        if (HP1 < 200){
            HP1 =ceil(HP1*1.3 );
            HP1 = min(max(HP1, 0), 666);
            paid = 150;
            m -= paid;

        } else {
            HP1 = ceil(HP1*1.1);
            HP1 = min(max(HP1, 0), 666);
            paid =70;
            m -= paid;

        }
if (m <= 0 )break;
if (EXP1 < 400) paid = 200;
else paid = 120;
m -= paid;
EXP1 = ceil(EXP1*1.13);
EXP1 = min(max(EXP1, 0), 600);
if (m <=0)break;
if (EXP1 < 300) paid = 100 ;
else paid = 120;
m =m- paid;
EXP1 = ceil(EXP1*0.9);
EXP1 = min(max(EXP1, 0), 600);
HP1 =ceil( 0.83*HP1 );
EXP1 = ceil(1.17*EXP1) ;
EXP1 = min(max(EXP1, 0), 600);

break; 
}
}
float P2;
int y = floor(sqrt(EXP1));
int lowery = y*y;
int uppery =(y+1)*(y+1);
if ((EXP1 - lowery) <= (uppery - EXP1)) P2 =1 ;
else P2 = (EXP1 /uppery +80)/123;
int arrayP3[20] = {32,47,28, 79, 100, 50, 22, 83, 64, 11,0,0,0,0,0,0,0,0,0,0};
float P3;
const int thapphan =10;
    if (E2 >= 0 && E2 <= 9) {
        P3 =  static_cast<float>(arrayP3[E2]) / (thapphan*thapphan) ;
    } else if (E2 >= thapphan&& E2 <= 99) {
        int sum = E2 / 10 + E2 % 10;
        int i = sum % 10;
        P3 = static_cast<float>(arrayP3[i]) /100;
    }
if (P1 ==1) {
if (P2 ==1 ){
if (P3 ==1){
EXP1 -= int(EXP1*0.25);
}
}
}
float P ;
P = (P1 + P2 + P3)/3;
    if (P >= 0.5){
        HP1 =ceil(HP1*0.9);
        EXP1 =ceil(EXP1*1.20);
    } 
	else {
	        HP1 =ceil(HP1*0.85);
       		 EXP1 =ceil(EXP1*1.15);
    }
EXP1 = min(max(EXP1, 0), 600);
HP1 = min(max(HP1, 0), 666);
M1 = min(max(M1, 0), 3000);
    return HP1+EXP1+M1;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3) {
E3 = LimitE(E3);
if ( E3 = -99) return -99;
const int size = 10;
int arr[size][size] = {0};
int di = 0, dj = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            arr[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            if (arr[i][j] > E3 * 2) di++;
            if (arr[i][j] < E3 * (-1)) dj++;
        }
    }

    while (di > 9) di = (di % size) + (di /size);
    while (dj > 9) dj = (dj % size) + (dj / size);

    int taxipoint = arr[di][dj], sherlockpoint = arr[di][dj];
    for (int i = 0; i < size; i++) { 
        int j = i + (dj - di);
        if (j >= 0 && j < size) {
            sherlockpoint = max(sherlockpoint, arr[i][j]);
        }
    }


    for (int i = 0; i < size; i++) { 
        int j = dj + (di - i);
        if (j >= 0 && j < size) {
            sherlockpoint = max(sherlockpoint, arr[i][j]);
        }
    }
    if ((taxipoint *taxipoint ) <  (sherlockpoint*sherlockpoint)) {
        EXP1 = min(600, static_cast<int>(ceil(EXP1 * 1.12)));
        HP1 = min(666, static_cast<int>(ceil(HP1 * 1.1)));
        EXP2 = min(600, static_cast<int>(ceil(EXP2 * 1.12)));
        HP2 = min(666, static_cast<int>(ceil(HP2 * 1.1)));
        return static_cast<double>(taxipoint);
    } else {
         EXP1 = min(600, static_cast<int>(ceil(EXP1 * 0.88)));
        HP1 = min(666, static_cast<int>(ceil(HP1 * 0.9)));
        EXP2 = min(600, static_cast<int>(ceil(EXP2 * 0.88)));
        HP2 = min(666, static_cast<int>(ceil(HP2 * 0.9)));
        return static_cast<double>(sherlockpoint);
    }
}
bool CheckChar(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
           (c == '@' || c == '#' || c == '%' || c == '$' || c == '!');
}
int checkPassword(const char* s, const char* email) {
    int length = strlen(s);
    if (length < 8) return -1; 
    if (length > 20) return -2; 
    bool spec = true;
string temp = "";
string se = "";
    for (int i = 0; i < (length-1); i++) {
        if (email[i] == '@') break;
        se.push_back(email[i]);
    }
for (int i = 0; i < length; i++) {
        if (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!') spec = false;
        temp.push_back(s[i]);
    }
    bool Substr = true;
    int SubIndex;
    for (int i = 0; i <= temp.length() - se.length(); i++) {
        if (temp.substr(i, se.length()) == se) {
            Substr = false;
            SubIndex = i;
            break;
        }
    }
if (!Substr) return (SubIndex + 300) * (-1); 
    for (int i = 0; i < length - 2; i++) {
        if (temp[i] == temp[i + 1] && temp[i + 1] == temp[i + 2])
            return (400 + i) * (-1); 
    }
    if (spec) return -5; 
    for (int i = 0; i < length; i++) {
        if (!CheckChar(temp[i])) return i;
    }

    return -10; 
}
int findCorrectPassword(const char* PassList[], int PassCount) {
    int MaxOcc= 0, maxLength = 0, Index = 0;
    bool ProcPass[PassCount] = {false};

    for (int i = 0; i < PassCount; ++i) {
        if (ProcPass[i] || PassList[i] == nullptr || strlen(PassList[i]) == 0) {
            continue; 
        }

        int currentOcc = 1; 

        for (int j = i + 1; j < PassCount; ++j) {
            if (!ProcPass[j] && PassList[j] != nullptr && strcmp(PassList[i], PassList[j]) == 0) {
                currentOcc=currentOcc+1;
                ProcPass[j] = true;
            }
        }

        if (currentOcc > MaxOcc|| (currentOcc == MaxOcc&& strlen(PassList[i]) > maxLength)) {
            MaxOcc= currentOcc;
            maxLength = strlen(PassList[i]);
            Index = i;
        }
    }
    return Index;
}
