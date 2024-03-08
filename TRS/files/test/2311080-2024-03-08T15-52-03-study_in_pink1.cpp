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


void hpCheck1(int & HP1){
    if( HP1 < 0 ) HP1=0;
    if( HP1 > 666) HP1=666;
}
void hpCheck2(int & HP2){
    if( HP2 < 0) HP2=0;
    if( HP2 > 666) HP2=666;
}
void expCheck1(int & EXP1){
    if( EXP1 < 0 ) EXP1=0;
    if( EXP1 > 600) EXP1=600;
}
void expCheck2(int & EXP2){
    if( EXP2 < 0) EXP2=0;
    if( EXP2 > 600) EXP2=600;
}
void mCheck1(int & M1){
    if( M1 < 0 ) M1=0;
    if( M1 > 3000) M1=3000;
}
void mCheck2(int & M2){
    if( M2 < 0 ) M2=0;
    if( M2 > 3000) M2=3000;
}

int squareClosest( int & EXP1){
    int sqLeft, sqRight;
    float x;
    x=sqrt(1.0*EXP1);
    sqLeft = floor(x) * floor(x);
    sqRight = ceil(x) * ceil(x);
    if ((EXP1 - sqLeft) < (sqRight - EXP1)) return sqLeft;
    return sqRight;
}

int unitNum( int n){
    	for ( int i=0; i >-1; i++){
    	if( float(n)/10 < 1){
    		n = n % 10;
    		break;
		}
		else{
			n = (n % 10) + floor(float(n)/10);
		}
    	
	}
	return n;
}
int ktlt(const char *s){
	int len = strlen(s);
	for ( int i=0; i< len -1; i++){
		if ( s[i] == s[i+1] && (s[i] == s[i+2])){
			return i;
		}
	}
	return -1;
}

int outRange( const char *s){

    for ( int i=0; i <strlen(s); i++){
        if ( (s[i] <33) || ( s[i] == 34) || ((s[i] > 38) && ( s[i] < 48)) || ( (s[i] > 57) && ( s[i] < 64)) || ( (s[i] > 90) && ( s[i] < 97)) || (s[i] >122)){
                return i;
        }

    }

return -1;
}



// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    expCheck1(exp1);
    expCheck2(exp2);
    if((e1 < 0) || (e1 > 99)) return -99;
    //Truong hop 1:
    else if ((e1 >= 0) && (e1 <= 3)){
            int D;
            float i;
            D=e1*3 + exp1*7;
            if ((D%2) == 0){
                exp1 = ceil( exp1 + (D*1.0)/200);
            }else{
                exp1 = ceil( exp1 - (D*1.0)/100);
            }
            if(e1 == 0) exp2 += 29;
            else if(e1 == 1) exp2 += 45;
            else if(e1 == 2) exp2 += 75;
            else exp2 += 149;
    }
    //Truong hop 2:
    else if ((e1 >=4) && (e1 <=99)){
            exp1 -= e1;
            if ((e1 >= 4) && (e1 <= 19)) exp2 += ceil(((e1*1.0)/4)+19);
            if ((e1 >= 20) && (e1 <= 49)) exp2 += ceil(((e1*1.0)/9)+21);
            if ((e1 >= 50) && (e1 <= 65)) exp2 += ceil(((e1*1.0)/16)+17);
            if ((e1 >= 66) && (e1 <= 79)){
                exp2 = ceil( exp2 + ((e1*1.0)/4)+19);
                if (exp2 > 200) exp2 = ceil(exp2 + ((e1*1.0)/9)+21);
            }
            if ((e1 >= 80) && (e1 <= 99)){
                exp2 = ceil( exp2 + ((e1*1.0)/4)+19);
                exp2 = ceil(exp2 + ((e1*1.0)/9)+21);
                if ( exp2 > 400 ){
                    exp2 = ceil(exp2 +((e1*1.0)/16)+17);
                    exp2 = ceil( 1.15 * exp2 );
                }

            }

    }
    expCheck1(exp1);
    expCheck2(exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    hpCheck1(HP1);
    expCheck1(EXP1);
    mCheck1(M1);
    float hp1f;
    if (( E2 < 0) || ( E2 > 99)){
        return -99;
    }
    const int mbandau = M1;
    //Con duong 1:
    int S = squareClosest(EXP1);
    float P1;
    if ( EXP1 >= S ) P1 = 100;
    else P1 = (((EXP1*1.0/S) + 80 )*100)/123;

    //Con duong 2:
    // E2 la so le:
    if(( E2 % 2) != 0){
    for( int i=0; i > -1; i++){
    //Su Kien 1:
    if( HP1 < 200 ){
        hp1f = HP1 * 1.3;
        HP1 = ceil(hp1f);
        M1 -= 150;
        hpCheck1(HP1);
        mCheck1(M1);
    }
    else{
        hp1f = HP1 *1.1;
        HP1 = ceil(hp1f);
        M1 -= 70;
        hpCheck1(HP1);
        mCheck1(M1);}
    if( (mbandau -M1) > (0.5*mbandau)) break;
    // Su kien 2:
    if ( EXP1 < 400){
        M1 -= 200;
        mCheck1(M1);
    }
    else {
        M1 -= 120;
        mCheck1(M1);
    }
    EXP1 = ceil(1.13 * EXP1);
    expCheck1(EXP1);

    if( (mbandau -M1) > (0.5*mbandau)) break;
    // Su kien 3:
    if ( EXP1 < 300) {
        M1 -= 100;
        mCheck1(M1);
    }
    else {
        M1 -=120;
        mCheck1(M1);
    }
    EXP1 = ceil( EXP1 * 0.9);
    expCheck1(EXP1);
    if( (mbandau -M1) > (0.5*mbandau)) break;
    }

    // E2 la so chan:
    } else{
    //Su Kien 1:
    if( (HP1 >= 0) && (HP1 < 200)){
        hp1f = HP1 * 1.3;
        HP1 = ceil( hp1f);
        M1 -= 150;
        hpCheck1(HP1);
    }
    else if( (HP1 >= 200) && (HP1 <=666)){
        hp1f = HP1 * 1.1;
        HP1 = ceil(hp1f);
        M1 -= 70;
        hpCheck1(HP1);
    }
    if (M1 < 0){
        M1 = 0;
        goto label;
    } 
    // Su kien 2:
    if ( EXP1 < 400){
        M1 -= 200;
    }
    else M1 -= 120;
    EXP1 = ceil(1.13 * EXP1);
    expCheck1(EXP1);
    if (M1 < 0){
        M1 = 0;
        goto label;
    } 
    // Su kien 3:
    if ( EXP1 < 300) M1 -= 100;
    else M1 -=120;
    EXP1 = ceil( EXP1 * 0.9);
    expCheck1(EXP1);
    if (M1 < 0){
        M1 = 0;
        goto label;
    } 
    }

    label:
    HP1 = ceil( HP1 * 0.83);
    EXP1 = ceil( EXP1 * 1.17);
    hpCheck1(HP1);
    expCheck1(EXP1);
    //Tinh P2:
    S = squareClosest(EXP1);
    float P2;
    if ( EXP1 >= S ) P2 = 100;
    else P2 = (((EXP1*1.0/S) + 80 )*100)/123;

    // Con duong 3:
    // Tinh P3:
    int P[10]= {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int P3, x;
    if ( floor(E2 /10) == 0){
        x = E2;
        P3 = P[x];
    }else{
        x = (( floor(E2 /10)) + ( E2 %10));
        x %= 10;
        P3 = P[x];
    }

    if (( P1 +P2 +P3) == 300){
        EXP1 = ceil( EXP1 *0.75);
        expCheck1(EXP1);
    }
    else if( ((P1 +P2 +P3) /3) <50){
        HP1 = ceil( HP1 *0.85);
        EXP1 = ceil( EXP1 *1.15);
        hpCheck1(HP1);
        expCheck1(EXP1);
    }
    else{
        HP1 = ceil( HP1 *0.9);
        EXP1 = ceil( EXP1 *1.2);
        hpCheck1(HP1);
        expCheck1(EXP1);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    hpCheck1(HP1);
    expCheck1(EXP2);
    hpCheck2(HP2);
    expCheck2(EXP2);
    if (( E3 < 0) || ( E3 > 99)){
        return -99;
    }
    // Gan gia tri cho ma tran:
    int M[10][10];
    for( int i=0; i<10; i++){
        for( int j=0; j<10; j++){
            M[i][j] = ((E3*j) +(i*2)) *(i-j);
        }
    }
    // Vi tri gap nhau:
    int nCount =0, pCount =0;
    for( int i=0; i<10; i++){
        for( int j=0; j<10; j++){
            if( (M[i][j] >(E3*2))) pCount +=1;
            else if ( (M[i][j] < -E3)) nCount +=1;
        }
    }
    pCount = unitNum(pCount);
    nCount = unitNum(nCount);

    // Tinh max min cheo trai cheo phai
    int max = M[pCount][nCount];
	int a = pCount;
	int b = nCount;
	for ( int i=0; i > -1; i++){
		--a;
		++b;
		if (((a >= 0) && (a <=9)) && ((b >= 0) && (b <=9))){
			if (M[a][b] > max) max = M[a][b];
		}
		else break;
	}
	
	a = pCount;
	b = nCount;
	for ( int i=0; i > -1; i++){
		++a;
		--b;
		if (((a >= 0) && (a <=9)) && ((b >= 0) && (b <=9))){
			if (M[a][b] > max) max = M[a][b];
		}
		else break;
	}
	
	a = pCount;
	b = nCount;
	for ( int i=0; i > -1; i++){
		++a;
		++b;
		if (((a >= 0) && (a <=9)) && ((b >= 0) && (b <=9))){
			if (M[a][b] > max) max = M[a][b];
		}
		else break;
	}
	
	a = pCount;
	b = nCount;
	for ( int i=0; i > -1; i++){
		--a;
		--b;
		if (((a >= 0) && (a <=9)) && ((b >= 0) && (b <=9))){
			if (M[a][b] > max) max = M[a][b];
		}
		else break;
	}
    if( max < 0) max = abs(max);
    // So sanh:
        if ( max >= abs((M[pCount][nCount]))){
            float con;
            con = EXP1*1.12;
            EXP1 = ceil(con);
            con = EXP2*1.12;
            EXP2 = ceil(con);
            con = HP1*1.1;
            HP1 = ceil(con);
            con = HP2*1.1;
            HP2 = ceil(con);
            hpCheck1(HP1);
            expCheck1(EXP2);
            hpCheck2(HP2);
            expCheck2(EXP2);
        }
        else{
            float con;
            con = EXP1*0.88;
            EXP1 = ceil(con);
            con = EXP2*0.88;
            EXP2 = ceil(con);
            con = HP1*0.9;
            HP1 = ceil(con);
            con = HP2*0.9;
            HP2 = ceil(con);
            hpCheck1(HP1);
            expCheck1(EXP2);
            hpCheck2(HP2);
            expCheck2(EXP2);
        }
    if ( max > abs(M[pCount][nCount])) return max;
    else return M[pCount][nCount];
}

// Task 4
int checkPassword(const char * s, const char * email) {
	int slen =strlen(s);
    int elen= strlen(email);
	// Pass ngan hoac dai:
	if ( slen < 8) return -1;
    else if (slen > 20) return -2;
	
    //Lay chuoi truoc @ va xet s co chua se ko:
    char *se = new char[strlen(email) + 1];
    char *seTemp = se;
    for (int i = 0; i < elen; ++i) {
        if (*email == '@') {
            *seTemp = '\0';
            break;
        }
        *seTemp = *email;
        ++email;
        ++seTemp;
        if (*email == '@') {
            *seTemp = '\0';
            break;
        }
    }
    const char *res2 = strstr(s, se);
    if (res2){
        int msei = -(300 + res2 -s);
        return msei;
    }
    delete[] se;

// 2 kt lien tiep
int msci = -(400 + ktlt(s));
if (ktlt(s) != -1) return msci;

// Ki tu dac biet:
{
    int count1 =0;
	bool hoang;
	for ( int i=0; i <slen; i++){
    	if( (*s == '!') || (*s == '@') || (*s == '#') || (*s == '$') || (*s == '%')){
    		hoang = 1;
    		break;
		}
		else if ( *s == '\0'){
			break;
		}
        else{
            ++s;
            ++count1;
        }	
	}
	if (hoang != 1) return -5; 
    s -= count1;
}
if ( outRange(s) != -1) return outRange(s);
return -10;
}



// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
       int *Count = new int[num_pwds];
    bool *checked = new bool[num_pwds];
    

    int maxCount = 0;
    int maxCountIndex = -1;
    int maxLength = 0;
    int result = -1;
    memset(Count, 0, num_pwds * sizeof(int));
    memset(checked, false, num_pwds * sizeof(bool));
    for (int i = 0; i < num_pwds; i++) {
        if (checked[i] == 0) {
            for (int j = i; j < num_pwds; ++j) {
                if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                    Count[i]++;
                    checked[j] = 1;
                }
            }

            if (Count[i] > maxCount || ((Count[i] == maxCount) && (strlen(arr_pwds[i]) > maxLength))) {
                maxCount = Count[i];
                maxCountIndex = i;
                maxLength = strlen(arr_pwds[i]);

            }
        }
    }

    if (maxCountIndex != -1) {
        for (int i = 0; i < num_pwds; ++i) {
            if (strcmp(arr_pwds[i], arr_pwds[maxCountIndex]) == 0 && strlen(arr_pwds[i]) == maxLength) {
                result = i;
                break;
            }
        }
    }

    delete[] Count;
    delete[] checked;
    return result;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////