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
int lamtron(double i) {
    if (i>=0) {
        return (int)(i + 0.999);
    }
    else { return (int)i; }
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if (0<= e1 && e1 <= 3) {
        if (e1 == 0 )
        { exp2 = (exp2 + 29);}
        else if (e1 == 1)
        { exp2 = (exp2 + 45);}
        else if (e1 == 2)
        { exp2 = (exp2 + 75);}
        else if (e1 == 3)
        { exp2 = (exp2 + 29 + 45 + 75);}
    int D = ceil((e1 * 3 + exp1 * 7)*1.0);
    if ( D % 2 == 0)
    { exp1 = ceil((exp1 + ( D/200))*1.0);}
    else { exp1 = ceil((exp1 - ( D/100))*1.0);}
    }
    else if (4<= e1 && e1 <= 99) {
    exp1 = exp1 - e1;
        if ( 4<= e1 && e1 <= 19)
        {  exp2 = lamtron((exp2 + ( e1/4.0 + 19)));}
        else if ( 20<= e1 && e1 <= 49)
        { exp2 = lamtron((exp2 + ( e1/9.0 + 21)));}
        else if ( 50<= e1 && e1 <= 65)
        { exp2 = lamtron((exp2 + ( e1/16.0 + 17)));}
        else if ( 66<= e1 && e1 <= 79) {
            exp2 = lamtron((exp2 + ( e1/4.0 + 19)));
            if (exp2 > 200) 
            { exp2 = lamtron((exp2 + ( e1/9.0 + 21)));}
        }
        else if ( 80 <= e1 && e1 <= 99) {
            exp2 = lamtron((exp2 + ( e1/4.0 + 19) + ( e1/9.0 + 21)));
            if (exp2 > 400)
            { exp2 = lamtron(((exp2 + ( e1/16.0 +17))*1.15));}
        }
        if (exp2 > 600)
        {exp2 = 600;}
        if (exp1 >600)
        {exp1 = 600;}
    }
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    int Sb1; // SoCP be hon EXP1 gan nhat
    int Sl1; // SoCP lon hon EXP1 gan nhat
    int S1; // SoCP duoc su dung trong bai
    double P1;
    // Road1//
    //Tim Sb
    int a1= EXP1;
    while ( a1 <= EXP1 && a1 > 0 ) {
        int sqr = sqrt (a1);
        if ( a1 == sqr * sqr ) {
            Sb1 = a1;
            break;
        }
        else (a1--);
    }
    //Tim Sl
    int b1= EXP1;
    while ( b1 >= EXP1 ) {
        int sqr = sqrt (b1);
        if ( b1 == sqr * sqr ) {
            Sl1 = b1;
            break;
        }
        else (++b1);
    }
    //Tim S
    if ((EXP1 - Sb1) < (Sl1 - EXP1))
    { S1 = Sb1;}
    else if ((EXP1 - Sb1) > (Sl1 - EXP1))
    { S1 = Sl1;}
    else { S1 = Sb1;} 
    //Tim P1
    if (EXP1 >= S1) 
    { P1 = 100; }
    else { P1 =(double) (((EXP1/(S1*1.0)+80)/123));}

    //Road2//
    int T = M1;
    int m1 = M1 * 0.5;
    if (E2 % 2 != 0) {
        do {
            //khoi lenh 1
            if ( HP1 < 200) {
                HP1 = ceil((HP1* 1.30));
                M1 = M1 - 150; }
            else {
                HP1 = ceil((HP1* 1.10));
                M1 = M1 - 70; }
            //khoi lenh 1
            if ((T - M1)>m1) {
                break;
            }
            else {
                //khoi lenh 2
                if ( EXP1 < 400) 
                { M1 = M1 - 200;}
                else { M1 = (M1 - 120);}
                EXP1 = ceil((EXP1 * 1.13));
                //khoi lenh 2
                if ((T - M1)>m1) {
                    break;
                }
                else {
                    //khoi lenh 3
                    if ( EXP1 < 300)
                    { M1 = (M1 - 100);}
                    else {( M1 = (M1 - 120));}
                    EXP1 = ceil((EXP1 * 0.9));
                    //khoi lenh 3
                    }
            } 
        }
        while ((T - M1)<m1);
    }
    else {
        //khoi lenh 1
        if ( HP1 < 200) {
            HP1 = ceil((HP1* 1.30));
            M1 = M1 - 150; }
        else {
            HP1 = ceil((HP1* 1.10));
            M1 = M1 - 70; }
        //khoi lenh 1
        if ( M1 == 0 )
        { goto Batdau; }
        else {
            //khoi lenh 2
            if ( EXP1 < 400) 
            { M1 = M1 - 200;}
            else { M1 = (M1 - 120);}
            EXP1 = ceil((EXP1 * 1.13));
            //khoi lenh 2
            if ( M1 == 0 )
            { goto Batdau; }
            else {
                //khoi lenh 3
                if ( EXP1 < 300)
                { M1 = (M1 - 100);}
                else {( M1 = (M1 - 120));}
                EXP1 = ceil((EXP1 * 0.9));
                //khoi lenh 3
            }
        }
    }
    Batdau:
    HP1 = ceil((HP1 * 0.83));
    EXP1 = ceil((EXP1 * 1.17));

    //Tim P2
    int Sb2; // SoCP be hon EXP1 gan nhat
    int Sl2; // SoCP lon hon EXP1 gan nhat
    int S2; // SoCP duoc su dung trong bai
    double P2;
    //Tim Sb2
    int a2= EXP1;
    while ( a2 <= EXP1 && a2 > 0 ) {
        int sqr = sqrt (a2);
        if ( a2 == sqr * sqr ) {
            Sb2 = a2;
            break;
        }
        else (a2--);
    }
    //Tim Sl2
    int b2= EXP1;
    while ( b2 >= EXP1 ) {
        int sqr = sqrt (b2);
        if ( b2 == sqr * sqr ) {
            Sl2 = b2;
            break;
        }
        else (++b2);
    }
    //Tim S2
    if ((EXP1 - Sb2) < (Sl2 - EXP1))
    { S2 = Sb2;}
    else if ((EXP1 - Sb2) > (Sl2 - EXP1))
    { S2 = Sl2;}
    else { S2 = Sb2;} 
    //Tim P2
    if (EXP1 >= S2) 
    { P2 = 100; }
    else { P2 =(double) (((EXP1/(S2*1.0)+80)/123));}


    //Road3//
    double P3;
    double PT;
    int Pi[]= {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if ( 0 <= E2 && E2 <= 9) 
    { P3 = Pi[(E2-1)];}
    else if ( 10<= E2 && E2 <= 99) {
        int hchuc1 = E2/10;
        int hdonvi1 = E2%10;
        int sum1 = hchuc1 + hdonvi1;
        int hdonvi2 = sum1%10;
        P3 = Pi[hdonvi2];
        P3 = P3*0.1;
    }
    //End//
    if ( P1==100 && P2==100 && P3==100) {
        EXP1 = EXP1 * 0.75;
    }
    else {
        PT = (( P1 + P2 + P3 )/3);
        if (PT < 0.5) {
            HP1 = ceil(HP1* 0.85);
            EXP1 = ceil(EXP1 * 1.15);
        }
        else {
            HP1 = ceil(HP1*0.9);
            EXP1 = ceil(EXP1*1.2);
        }
    }
    if ( EXP1 > 600 )
    {EXP1 = 600;}
    if ( HP1 > 666 )
    {HP1 = 666;}
    if ( M1 > 3000 )
    {M1 = 3000;}
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    int a;
    int b;
    int M[10][10] = {};
    for (a=0; a < 10; a++) {
        for (b=0; b < 10; ++b) {
            M[a][b] = ((E3*b)+(a*2))*(a-b);
        }
    }
    
    int i=0; //So diem lon hon E3*2
    int j=0; //So diem be hon -E3
    int EE3 = E3*2;
    int e3 = -(E3);
    for ( int y=0; y<10; y++ ) {
        for ( int z=0; z<10; z++ ) {
            if (M[y][z] > EE3)
            { ++i; }
            if (M[y][z] < e3)
            { ++j; }
        }
    }
    //Tim duoc so diem lon hon E3*2 va be hon -E3
    int ic;
    int jc;
    if ( 10 <= i && i <= 99 ) {
        int hchuci = i/10;
        int hdonvii = i%10;
        int sumi = hchuci + hdonvii;
        if (sumi == 10)
        { ic = 1;}
        else {ic = sumi%10;}
    }
    if ( 10 <= j && j <= 99 ) {
        int hchucj = j/10;
        int hdonvij = j%10;
        int sumj = hchucj + hdonvij;
        if (sumj == 10)
        { jc = 1;}
        else {jc = sumj%10;}
    }
    //Tim duoc toa do gap nhau (ic;jc)
    int diemmax;
    //Tim diem max trai tren
    int diemmaxtt;
    int tti=ic;
    int ttj=jc;
    while (tti>0 && ttj>0) {
        diemmaxtt = M[tti][ttj];
        if ( M[tti-1][ttj-1] > diemmaxtt) {
            diemmaxtt = M[tti-1][ttj-1];
            tti--;
            ttj--;
        }
        else {break;}
    }
    //Tim diem max phai duoi
    int diemmaxpd;
    int pdi=ic;
    int pdj=jc;
    while (pdi<9 && pdj<9) {
        diemmaxpd = M[pdi][pdj];
        if ( M[pdi+1][pdj+1] > diemmaxpd) {
            diemmaxpd = M[pdi+1][pdj+1];
            pdi++;
            pdj++;
        }
        else {break;}
    }
    //Tim diem max phai tren
    int diemmaxpt;
    int pti=ic;
    int ptj=jc;
    while (pti>0 && ptj<9) {
        diemmaxpt = M[pti][ptj];
        if ( M[pti-1][ptj+1] > diemmaxpt) {
            diemmaxpt = M[pti-1][ptj+1];
            pti--;
            ptj++;
        }
        else {break;}
    }
    //Tim diem max trai duoi
    int diemmaxtd;
    int tdi=ic;
    int tdj=jc;
    while (tdi<9 && tdj>0) {
        diemmaxtd = M[tdi][tdj];
        if ( M[tdi+1][tdj-1] > diemmaxtd) {
            diemmaxtd = M[tdi+1][tdj-1];
            tdi++;
            tdj--;
        }
        else {break;}
    }
    diemmax = diemmaxtt;
    if (diemmax < diemmaxpt)
    { diemmax = diemmaxpt;}
    if (diemmax < diemmaxtd)
    { diemmax = diemmaxtd;}
    if (diemmax < diemmaxpd)
    { diemmax = diemmaxpd;}

    
    if ( abs(M[ic][jc]) > diemmax ) {
        EXP1 = lamtron(EXP1 * 0.88);
        EXP2 = lamtron(EXP2 * 0.88);
        HP1 = lamtron(HP1 * 0.9);
        HP2 = lamtron(HP2 * 0.9);
    }
    else {
        EXP1 = lamtron(EXP1 * 1.12);
        EXP2 = lamtron(EXP2 * 1.12);
        HP1 = lamtron(HP1 * 1.1);
        HP2 = lamtron(HP2 * 1.1);
    }
    if ( EXP1 > 600 ) {
        EXP1 = 600;
    }
    if ( EXP2 > 600 ) {
        EXP2 = 600;
    }
    if ( HP1 > 666 ) {
        HP1 = 666;
    }
    if ( HP2 > 666 ) {
        HP2 = 666;
    }
    if (abs(M[ic][jc]) > diemmax) {
        return M[ic][jc];
    }
    else {return diemmax;}
}


// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se = email;
    se = se.substr(0, se.find('@')); // Lay cac ki tu truoc @

    int minLength = 8;
    int maxLength = 20;

    //Kiem tra ki tu dac biet
    bool Dacbiet = false;
    for (const char *ptr = s; *ptr != '\0'; ++ptr) {
        if (*ptr == '@' || *ptr == '#' || *ptr == '%' || *ptr == '$' || *ptr == '!') {
            Dacbiet = true;
            break;
        }
    }

    // Kiem tra ki tu lien tiep giong nhau
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0' && s[i + 2] != '\0'; ++i) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) {
            return -(400 + i); 
        }
    }

    // Kiem tra chieu dai pass
    int length = strlen(s);
    if (length < minLength) {
        return -1; 
    }
    if (length > maxLength) {
        return -2; 
    }

    // Kiem tra neu lap chuoi se
    const char *chuoise = strstr(s, se.c_str());
    if (chuoise != nullptr) {
        return -(300 + (chuoise - s)); 
    }

    //Khong chua ki tu dac biet
    if (!Dacbiet) {
        return -5; 
    }

    return -10; 
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    const int MP = 30;
    const int ML = 50; //Do dai toi da chuoi pass

    char passwords[MP][ML];
    int count[MP] = {0};
    int length[MP] = {0};

    for (int i = 0; i < num_pwds; ++i) {
        int len = strlen(arr_pwds[i]);
        strncpy(passwords[i], arr_pwds[i], len);
        passwords[i][len] = '\0'; // Ket thuc chuoi
        length[i] = len;

        for (int j = 0; j <= i; ++j) {
            if (strcmp(passwords[j], passwords[i]) == 0) {
                count[j]++;
                break;
            }
        }
    }

    int maxcount = 0, maxlength = 0, resultIndex = -1;
    for (int i = 0; i < num_pwds; ++i) {
        if (count[i] > maxcount || (count[i] == maxcount && length[i] > maxlength)) {
            maxcount = count[i];
            maxlength = length[i];
            resultIndex = i;
        }
    }

    return (resultIndex);
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////