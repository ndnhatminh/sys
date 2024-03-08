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

//Setting HP, EXP and M
int setHP(int &HP) {
    HP = (HP > 666) ? 666 : (HP < 0 ? 0 : HP);
    return HP;
}

int setEXP(int &EXP) {
    EXP = (EXP > 600) ? 600 : (EXP < 0 ? 0 : EXP);
    return EXP;
}

int setM(int &M) {
    M = (M > 3000) ? 3000 : (M < 0 ? 0 : M);
    return M;
}

// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1) {
    // TODO: Complete this function
    EXP1= setEXP(EXP1); EXP2= setEXP(EXP2);
    
    if (E1 < 0 || E1 > 99) return -99;
    
    else if(E1 <=3) {
        switch(E1) {
            case 0: EXP2+= 29; break;
            case 1: EXP2+= 45; break;
            case 2: EXP2+= 75; break;
            case 3: EXP2+= 29 + 45 + 75; break;
        }
        int D = E1*3 + EXP1*7;
        EXP1 = (D%2 == 0) ? ceil(EXP1+D/200.0) : ceil(EXP1-D/100.0);
        }
        
    else {
        if (E1 <= 19) EXP2+= ceil(E1/4.0 + 19);         //Theo thong tin 1
        else if (E1 <= 49) EXP2+= ceil(E1/9.0 + 21);    //Theo thong tin 2
        else if (E1 <= 65) EXP2+= ceil(E1/16.0 + 17);   //Theo thong tin 3
        else if (E1 <= 79) {
            EXP2+= ceil(E1/4.0 + 19);
            if (EXP2 > 200) EXP2+= ceil(E1/16.0 + 17);
        }
        else {
            EXP2+= ceil(E1/4.0 + 19); EXP2+= ceil(E1/9.0 + 21); 
            if (EXP2 > 400) EXP2+= ceil(E1/16.0 + 17);
            EXP2*= 1.15; setEXP(EXP2);
        }
        EXP1-= E1;
    }
    return EXP1 + EXP2;
}

// Task 2
int nearSquare(int &x) {
    int output = abs(floor(sqrt(x)) - sqrt(x)) < abs(ceil(sqrt(x)) - sqrt(x)) ? floor(sqrt(x)) : ceil(sqrt(x));
    return output*output;
}

int xacSuat(int &x) { 
    //Trace 3
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11}; int j, tcs; //tcs la tong cac chu so cua Pi neu Pi co 2 chu so
    if (x >= 0 && x < 10) j = x; 
    else  { tcs = x/10 + x%10; j = (tcs > 9) ? tcs%10 : tcs; }
    return P[j];
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2) {
    // TODO: Complete this function
    if (E2 < 0 || E2 > 99) return -99;
    
    HP1= setHP(HP1); EXP1= setEXP(EXP1); M1= setM(M1);
   
    //Trace 1
        int S = nearSquare(EXP1); double P1, P2;
        if (EXP1 >= S) P1 = 1; else P1 = ((double) EXP1/S + 80)/123.0;

    //Trace 2
        int expense = 0; const double MONEY = M1/2.0; //Tong so tien can chi tra
        while (M1 != 0)
        { 
            //Mua thuc an nuoc uong
            if (HP1 < 200) { HP1= ceil(HP1*1.3); M1-= 150; expense+= 150; } else {HP1= ceil(HP1*1.1); M1-= 70; expense+= 70;}  
            HP1= setHP(HP1); M1= setM(M1); 
            if (expense > MONEY) break;
            
            //Di taxi hay ngua
            if (EXP1 < 400) {M1-= 200; expense+= 200; } else {M1-= 120; expense+= 120; }
            EXP1= ceil(EXP1*1.13); EXP1= setEXP(EXP1); M1= setM(M1); 
            if (expense > MONEY) break;
            
            //Nguoi dan duong
            if (EXP1 < 300) {M1-= 100; expense+= 100; } else {M1-= 120; expense+= 120; }
            EXP1= ceil(EXP1*0.9); EXP1= setEXP(EXP1); M1= setM(M1); 
            if (expense > MONEY) break;
            
            if (E2%2 == 0) break;
        }
       
        //Di bo
        HP1= ceil(HP1*0.83); EXP1= ceil(EXP1*1.17); HP1= setHP(HP1); EXP1= setEXP(EXP1); 
        
        //Xac suat
        if (EXP1 >= S) P2 = 1; else P2 = ((double) EXP1/S + 80)/123.0;
      
    //Trace 3
        int P3 = xacSuat(E2);

    //Total
        if (P1 == 1 && P2 == 1 && P3 == 100) EXP1= ceil(EXP1*0.75); //P1 = P2 = 1 = 100%, P3 = 100(%) 
        else {
            double P = (P1 + P2 + P3/100.0)/3.0;
            if (P < 0.5) { HP1= ceil(HP1*0.85); EXP1= ceil(EXP1*1.15);  }
            else { HP1= ceil(HP1*0.9); EXP1= ceil(EXP1*1.2); }
        } 
        EXP1= setEXP(EXP1); HP1= setHP(HP1); 
        
    return HP1 + EXP1 + M1; 
}

// Task 3

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
/****************************************************
    if (E3 < 0 || E3 > 99) return -99;
    
    int i, j, Arr1[10][10], Arr2[10][10];
    for (i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) Arr1[i][j] = ((E3*j) + (i*2))*(i - j); 
    }
    
    for (j = 0; j < 10; j++) {
        for (j = 0; j < 10; j++) Arr1[i][j] = ((E3*j) + (i*2))*(i - j); 
    }
******************************************/
    return -1;
}


// Task 4
int checkDouble(const string &c) {
    for (int i = 0; i < c.length(); i++) {
        if ((c[i] == c[i+1]) && (c[i+1] == c[i+2]) ) return i;
    }
    return -1;
}

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    int i; string se, tam; 
    for(i = 0; i < strlen(email); i++) {
        string tam = email;
        if (email[i] == '@') { se = tam.substr(0, i);  break; }
    }
    
    string mk = s;
    
    //Kiem tra dieu kien
    if (strlen(s) < 8) return -1;
    if (strlen(s) > 20) return -2;
    if (mk.find(se) != -1) { int a = (int) mk.find(se); return -300 - a; } 
    if (checkDouble(mk) != -1) return -(400 + checkDouble(mk));

    //Kiem tra khong chua ky tu dac biet (chi co so, chu hoa, chu thuong)
    int count = 0;
    for(i = 0; i < strlen(s); i++) {
        if (!((s[i] > 47 && s[i] < 59) || (s[i] > 64 && s[i] < 91) || (s[i] > 96 && s[i] < 123)))  count++;
    }
    if (count == 0) return -5;
    
    //Chua cac ky tu dac biet khac ngoai de bai
    for(i = 0; i < strlen(s); i++) {
        if (!( s[i] == 33 || (s[i] > 34 &&  s[i] < 38) || (s[i] > 47 && s[i] < 59) || (s[i] > 63 && s[i] < 91) 
        || (s[i] > 96 && s[i] < 123))) { return i; break; }
    }
    
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
         
    const int a = num_pwds; int num, i, dem_sl[a]; const char * pos_pwds[a+1]; 
    //Dung mang phu dung de luu cac mat khau co kha nang la dung
    int max = 0; 
   
    for (i = 0; i < a; i++) {
        pos_pwds[i] = arr_pwds[i];
        int dem = 0;
        for (int j = 0; j < a; j++) {
            if (arr_pwds[j] == pos_pwds[i]) dem++; 
        }
        dem_sl[i] = dem;
        if (dem >= max) max = dem; else pos_pwds[i] = "0"; 
    }
    
    
    //Loc lai cac mat khau co so dem nho hon max, bang max giu nguyen
    for (i = 0; i <= a-1; i++) {
        if (dem_sl[i] < max) pos_pwds[i] = "0"; 
    }
    
    //Tim chuoi co do dai lon nhat
    pos_pwds[a] = pos_pwds[0]; //Phan tu nay luu mat khau dai nhat trong cac mk xuat hien nhieu nhat (mk dung)
    for (i = 1; i <= a-1; i++) {
        if ((strlen(pos_pwds[i]) > strlen(pos_pwds[a])) && (dem_sl[i] == max)) pos_pwds[a] = pos_pwds[i];
    }
        
    //Tim vi tri de in ra    
    for (i = 0; i < num_pwds-1; i++) {
        if (strcmp(pos_pwds[a], arr_pwds[i]) == 0) break;
    }
    return i;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////