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

struct data
{
    const char* pass = "pass";
    int length=0;
    int place =0;
    int appare=1;
};
double P(double x)
{
    double S;
    if (sqrt(x) - floor(sqrt(x)) > ceil(sqrt(x)) - sqrt(x))
        S = pow(ceil(sqrt(x)), 2);
    else
        S = pow(floor(sqrt(x)), 2);
    if (x >= S)
        return 1;
    else
        return (x/S + 80)/123;
}
int check(int x, int max)//nhớ thêm check sau mỗi lần tính toán
{   
    if (x > max)
        return max;
    else if (x < 0)
        return 0;
    else
	    return x;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    double EXP1 = exp1, EXP2 = exp2, E1 = e1;
    int D;
    if (E1 >=0 && E1 < 4)
    {
        if (E1 == 0){
    	    EXP2 += 29;
            EXP2 = check (EXP2, 600);
        }
    	else if (E1 == 1){
	    	EXP2 += 45;
    	    EXP2 = check (EXP2, 600);
    	}
	    else if (E1 == 2){
	        EXP2 += 75;
	        EXP2 = check (EXP2, 600);
	    }
	    else if (E1 == 3){
	        EXP2 += 149;
	        EXP2 = check (EXP2, 600);
	    }
        D=E1*3+EXP1*7;
        if (D/2 == 0){
            EXP1 += ceil(D/200);
            EXP1 = check (EXP1, 600);
        }   
        else{
            EXP1 -= ceil(D/100);
            EXP1 = check (EXP1, 600);
        }
    } 
    else if (E1 > 3 && E1 < 100)
    {
	    if (E1 > 3 && E1 < 20){
        	EXP2 += (ceil(E1/4) + 19);
	        EXP2 = check (EXP2, 600);
	    }
    	else if (E1 > 19 && E1 < 50){
	        EXP2 += (ceil(E1/9) + 21);
    	    EXP2 = check (EXP2, 600);
    	}
	    else if (E1 > 49 && E1 < 66){
	        EXP2 += (ceil(E1/16)+ 17);
	        EXP2 = check (EXP2, 600);
	    }
    	else if (E1 > 65 && E1 < 80){
    	    EXP2 += (ceil(E1/4) + 19);
    	    EXP2 = check (EXP2, 600);
	        if (EXP2 > 200){
	            EXP2 += (ceil(E1/9) + 21);
	            EXP2 = check (EXP2, 600);
	        }
    	}
	    else if (E1 > 79 && E1 < 100){
    	    EXP2 += (ceil(E1/4) + 19);
    	    EXP2 = check (EXP2, 600);
	        EXP2 += (ceil(E1/9) + 21);
	        EXP2 = check (EXP2, 600);
	        if (EXP2 > 400){
	            EXP2 += (ceil(E1/16)+ 17);
	            EXP2 = check (EXP2, 600);
	            EXP2 = ceil(EXP2*1.15);
	            EXP2 = check (EXP2, 600);
	        }
	    }
	    EXP1 -= E1;
	    EXP1 = check (EXP1, 600);
    }
	else{
	    return -99;
		exit(0);
    }
    exp1=EXP1;
    exp2=EXP2;
    return EXP1+EXP2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99)
    {
        return -99;
        exit(0);
    }
    double P1, P2, P3, Hp1 = HP1, Exp1 = EXP1;
//Con đường 01
    P1 = P(Exp1);
//Con đường 02
    if (M1 > 0)
    {
        double bd = M1/2;
        if (E2/2 != 0){
            while (M1 >= bd)
            {
                if (Hp1 < 200){
                    Hp1 *= 1.3;
                    M1 -= 150;
                }
                else{
                    Hp1 *= 1.1;
                    M1 -= 70;}
                Hp1=ceil(Hp1);
                Hp1 = check (Hp1, 666);
                M1 = check (M1, 3000);
                
                if (M1 < bd) break;
                
                if (Exp1 < 400)     M1 -= 200;
                else                M1 -= 120;
                Exp1 *= 1.13;
                Exp1=ceil(Exp1);
                Exp1 = check (Exp1, 600);
                M1 = check (M1, 3000);
                
                if (M1 < bd) break;
                
                if (Exp1 < 300)     M1 -= 100;
                else                M1 -= 120;
                Exp1 *=0.9;
                Exp1=ceil(Exp1);
                Exp1 = check (Exp1, 600);
                M1 = check (M1, 3000);
            }
        }
        else{
            if (Hp1 < 200){
                Hp1 *= 1.3;
                M1 -= 150;}
            else{
                Hp1 *= 1.1;
                M1 -= 70;}
            Hp1=ceil(Hp1);
            Hp1 = check (Hp1, 666);
            M1 = check (M1, 3000);
            
            if (M1 > 0){
                if (Exp1 < 400)     M1 -= 200;
                else                M1 -= 120;
                Exp1 *= 1.13;
                Exp1=ceil(Exp1);
                Exp1 = check (Exp1, 600);
                M1 = check (M1, 3000);
                
                if (M1 > 0){
                    if (Exp1 < 300) M1 -= 100;
                    else            M1 -= 120;
                    Exp1 *=0.9;
                    Exp1=ceil(Exp1);
                    Exp1 = check (Exp1, 600);
                    M1 = check (M1, 3000);
                }
            }
        }
    }
    Hp1 *= 0.83;
    Exp1 *= 1.17;
    Hp1=ceil(Hp1);
    Exp1=ceil(Exp1);
    Hp1 = check (Hp1, 666);
    Exp1 = check (Exp1, 600);
    P2 = P(Exp1);
//Con đường 03
    std::array<double, 11> p = {32,47,28,79,100,50,22,83,64,11};
    if (E2/10 == 0)
        P3=p[E2]/100;
    else
        P3=p[(E2/10 + E2%10)%10]/100;
//Tổng kết 3 truyến đường
    if (P1==P2 && P1==P3)
        Exp1 *= 0.75;
    else{
        if (((P1+P2+P3)/3) < 0.5){
            Hp1 *= 0.85;
            Exp1 *= 1.15;
        }else{
            Hp1 *= 0.9;
            Exp1 *= 1.2;
        }
    }
    HP1=ceil(Hp1);
    EXP1=ceil(Exp1);
    HP1 = check(HP1, 666);
    EXP1 = check(EXP1, 600);
    M1 = check(M1, 3000);
    return HP1+M1+EXP1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3 < 0 || E3 > 99)
    {
        return -99;
        exit(0);
    }
    double Hp1 = HP1, Exp1 = EXP1, Hp2 = HP2, Exp2 = EXP2;
    long x[10][10] = { }, di=0, dj=0, max;
    for (int i=0; i<10; i++)
        for (int j=0; j<10; j++)
        {
            x[i][j]=((E3*j + i*2)*(i-j));
            if (x[i][j] > (E3*2))
                di++;
            if (x[i][j] < E3*-1)
                dj++;
        }
    while (di/10 != 0 || dj/10 != 0)
    {
        di = di/10 + di%10;
        dj = dj/10 + dj%10;
    }
    int i=0;
    int j=dj-(di-0);
    while (i<10 && j<10)
    {
        if (x[i][j] > max)      max = x[i][j];
        i++; j++;
    }
    i=0;
    j=dj+(di-0);
    while (i<10 && j>=0)
    {
        if (x[i][j] > max)      max = x[i][j];
        i++; j--;
    }
    if (abs(x[di][dj]) > max)
    {
        EXP1 = ceil(Exp1*0.88);
        EXP2 = ceil(Exp2*0.88);
        HP1 = ceil(Hp1*0.9);
        HP2 = ceil(Hp2*0.9);
        EXP1 = check (EXP1, 600);
        EXP2 = check (EXP2, 600);
        HP1 = check (HP1, 666);
        HP2 = check (HP2, 666);
//        cout << Exp1 << endl << Hp1 << endl << Exp2 << endl << Hp2 << endl;
        return x[di][dj];
    }else{
        EXP1 = ceil(Exp1*1.12);
        EXP2 = ceil(Exp2*1.12);
        HP1 =  ceil(Hp1*1.1);
        HP2 =  ceil(Hp2*1.1);
        EXP1 = check (EXP1, 600);
        EXP2 = check (EXP2, 600);
        HP1 = check (HP1, 666);
        HP2 = check (HP2, 666);
//        cout << "Exp1 "<< Exp1 << endl << "Hp1  "<< Hp1 << endl<< "Exp2 "<< Exp2 << endl<< "Hp2  " << Hp2 << endl;
        return max;
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    long error=-3, db=0, d=1, max=0;
    const char* se;
    if (strlen(s)<8){
        return -1; 
        exit(0);
    }       //đk ngắn
    if (strlen(s)>20){
        return -2;
        exit(0);
    }        //đk dài
        for (int i=0; i<strlen(email); i++)     //rút se
            if (email[i] == 64)             //@=64
                se = strndup(email, i);     //sao chép: strndup(const char *s, size_t n);
        const char* p = strstr(s, se);      //tìm chuỗi: strstr ( const char * text, const char * pattern );
        if (p != NULL){      
            return -(300+(p-s));
            exit(0);
        }                 //đk trùng
            for (int i=1; i<strlen(s); i++){
                if (s[i-1] == s[i]){
                    d++;
                    if (d>2){
                        max=-(400+(i-d+1));
                        return max;
                        exit(0);
                    }
                }else   d=1;
            }//đk lặp
    for (int i=0; i<strlen(s); i++){
        if (s[i] == 64 || s[i] == 35 || s[i] == 37 || s[i] == 36 || s[i] == 33){
            db++;
        }
        else
        if (!((s[i]>47&&s[i]<58)||(s[i]>64&&s[i]<91)||(s[i]>96&&s[i]<123))){
            error=i;
        }
    }
    if (db == 0){
        return -5;
        exit(0);
    }                       //đk ktdb
    if (error >= 0){
        return error;
        exit(0);
    }                    //đk ko hợp lệ
    return 10;                              //default: hợp lệ
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    data pwds[num_pwds];
    int n=0, i, j, J=0, amax=1, da=0; bool count = false;
    for(int i=0; i< num_pwds; i++){
        for(int j=-1; j<n; j++){
            if (pwds[j].pass == arr_pwds[i]){
                pwds[j].appare++;
                if (pwds[j].appare > amax)  amax=pwds[j].appare;
                count = true;
            }
        }
        if(count == false)
            {
                pwds[n].pass=arr_pwds[i];
                pwds[n].place = i;
                pwds[n].length = strlen(arr_pwds[i]);
                n++;
            }
        count = false;
    }     //gán mảng struct lưu dữ liệu
    for(int j=0; j<n; j++)
        if(amax == pwds[j].appare)
            da++;
    if (da == 1){
        for(int j=0; j<n; j++)
            if(amax == pwds[j].appare){
                J=j;
                break;
            }
    }
    else{
        for(int j=0; j<n; j++)
            if(amax == pwds[j].appare){
                if(pwds[J].length < pwds[j].length)
				J=j;
            }
    }
    return pwds[J].place;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////