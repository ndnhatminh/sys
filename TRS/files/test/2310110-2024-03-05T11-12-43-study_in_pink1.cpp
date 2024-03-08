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

//Condition of input
int checkhp (int a){
   if (a < 0) {a = 0;}
    else if ( a > 666 ) {a = 666;}
    else {a = a;}
    return a; 
}
int checkexp (int a){
    if (a < 0) {a = 0;}
    else if ( a > 600 ) {a=600;}
    else {a = a;}
    return a;
}
int checkM (int a){
    if (a < 0) {a = 0;}
    else if ( a > 3000 ) {a = 3000;}
    else {a = a;}
    return a;
}
int squareNnearest(int a) {     // Tìm số chính phương gần nhất 
    int n=0, d, S, min ;
    min= a +10 ;
    for (n = 0; n<=25 ; n++){
         d= abs (a-n*n);
        if (min > d) { min = d; S=n*n;}
        else { break;}
    }
    return S;
}  
int two_digitsum(int n){
    int s = 0, a, b;
        a = n / 10;
        b = n % 10;
        s = a + b ;
        if (s > 9) {
            int c,d;
            c = s / 10;
            d = s % 10;
            s = c+d;
        }
    return s;
}
int checkchar( const char *s){
    for (int i=0; s[i]!='\0';i++){
        if (!( (s[i] >= 'a' && s[i] <='z' )
        || (s[i] >= 'A' && s[i] <= 'Z' )
        || (s[i] >= '0' && s[i] <= '9' )
        || (s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] =='!'))){
            return i;
        }
    }
    return -1;
}
int specialc(const char *s){
    int dem=0;
    for (int i=0 ; i < strlen(s) ; i++){
        if ((s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] =='!')){
           dem = 1;
           //break;
        }
    }
    if (dem == 0) return -99;
    else return -9;
}
int checksame (const char *s){
   int l=strlen(s); 
   int check=0, num=-1;
   for (int i=0 ; i < l ; i++){
        if (s[i] == s[i+1]){
          check++;
          if (check == 2) {
            num= i-1;
            break;}
      }
      else check=0;
      
 }   
 return num;
}
int checkse (const char *s, const char *email){
    const char *x = strchr (email,'@'); // xuất ra thứ tự @....
    int d = x - email; //số kí tự trước @
    
    char *se = new char [d+1];

    strncpy (se,email,d);
    se[d]='\0';
    //cout << " " << d << " " << se << endl;;
    const char *y = strstr (s,se);//kt có se TH4
    int l  ; // vị trí se
    if (y == NULL){
        return -99;
    }
    else 
    { l = y -s ; 
    return l;}
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
   exp1 = checkexp(exp1); 
   exp2 = checkexp(exp2); 
   int D;
   if (e1<=3 && e1>=0) {   // TH1
    switch (e1){
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
        exp2 += 29 + 45 + 75 ;
    }
    exp2 = checkexp(exp2); 
    D = e1 * 3 + exp1 * 7;
    float iexp1;
    if (D % 2 == 0) {
        iexp1 = exp1 + (D /200.0) ;
    }
    else iexp1 = exp1 - (D /100.0);
    exp1 = ceil(iexp1); exp1 = checkexp(exp1); 
  }
  else if (e1 <= 99 && e1 >= 4) {   //TH2
    float iexp2;
    if (e1 <= 19 && e1 >=4) 
       { iexp2 = exp2 + ((e1 / 4.0) + 19.0);    exp2 = ceil(iexp2);exp2 = checkexp(exp2); }
    else if ( e1 <= 49) 
        {iexp2 = exp2 + ((e1 /9.0) + 21.0 );    exp2 = ceil(iexp2);exp2 = checkexp(exp2); }
    else if ( e1 <= 65) 
       { iexp2 = exp2 + ((e1 / 16.0) + 17.0) ;    exp2 = ceil(iexp2);exp2 = checkexp(exp2); }
    else if ( e1 <= 79) {
        iexp2 = exp2 + ((e1/4.0) + 19.0); exp2 = ceil(iexp2);exp2 = checkexp(exp2); 
        if (exp2 > 200.0 ) {iexp2 = exp2 + ((e1 / 9.0 ) + 21.0);  exp2 = ceil(iexp2);exp2 = checkexp(exp2);   }
    }
    else {
        iexp2 = exp2 + ((e1/4.0) + 19.0); exp2 = ceil(iexp2);exp2 = checkexp(exp2); 
        iexp2 = exp2 + ((e1 /9.0) + 21.0 ); exp2 = ceil(iexp2);exp2 = checkexp(exp2); 
        if (exp2 > 400.0) {
            {
                iexp2 = (exp2 +((e1 / 16.0) + 17.0));  exp2 = ceil(iexp2);exp2 = checkexp(exp2); 
                iexp2 = exp2 * 1.15;   exp2 = ceil(iexp2);exp2 = checkexp(exp2);
                   }
    }
  }
     exp1 = exp1 - e1;exp1 = checkexp(exp1); 
}
else {return -99; } // Lỗi nhập E1
exp1 = checkexp(exp1); 
exp2 = checkexp(exp2);
    return exp1 + exp2;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    HP1 = checkhp (HP1); EXP1 = checkexp(EXP1); M1 = checkM(M1) ; 
    int S;
    float p1, p2, p3, p;
    float iHP1,iEXP1;
    if (E2 <=99 && E2 >=0){
    //Road1
    S = squareNnearest(EXP1); 
    if ( EXP1 >= S ) { p1 = 1 ;}
    else { p1 = ((EXP1 / (S * 1.00)) + 80) / 123.00;} 
    // Road2
    float m = 0.5 * M1 ; 
    if (E2 % 2 != 0) { //e lẻ
    if ( HP1 < 200) {
        iHP1 = HP1 * (1 + 0.3); HP1 = ceil (iHP1); 
        M1 -= 150; 
    }
    else {
        iHP1 = HP1 * (1 + 0.1); HP1 = ceil (iHP1); 
        M1 -= 70;       
    }HP1 = checkhp (HP1);
        tryAgain:
    if (M1 >= m)  //sk1
       {//chạy sk2
        if ( EXP1 < 400 ){
        M1 -= 200; }
        else M1 -= 120; 
        iEXP1 = EXP1 * ( 1 + 0.13); EXP1 = ceil (iEXP1); EXP1=checkexp(EXP1);
        if (M1 >= m ) 
        { //chạy sk3
            if ( EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            iEXP1 = EXP1 * ( 1 - 0.1 ); EXP1 = ceil(iEXP1);EXP1=checkexp(EXP1);
            if (M1 >= m){
                if ( HP1 < 200) {//chạy sk1
                iHP1 = HP1 * (1 + 0.3); HP1 = ceil (iHP1); 
                M1 -= 150; 
            }
            else {
                iHP1 = HP1 * (1 + 0.1); HP1 = ceil (iHP1); 
                M1 -= 70;       
            }HP1 = checkhp (HP1);
            goto tryAgain;}
        }
    }
    }
    else { // e chẵn
      if ( HP1 < 200) {
        iHP1 = HP1 * (1 + 0.3); HP1 = ceil (iHP1); 
        M1 -= 150; 
    }
    else {
        iHP1 = HP1 * (1 + 0.1); HP1 = ceil (iHP1); 
        M1 -= 70;       
    }HP1 = checkhp (HP1);
    if (M1 > 0)  //sk1
       {//chạy sk2
        if ( EXP1 < 400 ){
        M1 -= 200; }
        else M1 -= 120; 
        iEXP1 = EXP1 * ( 1 + 0.13); EXP1 = ceil (iEXP1); EXP1=checkexp(EXP1);
        if (M1 > 0 ) 
        { //chạy sk3
            if ( EXP1 < 300) M1 -= 100;
            else M1 -= 120;
            iEXP1 = EXP1 * ( 1 - 0.1 ); EXP1 = ceil(iEXP1);EXP1=checkexp(EXP1);
        }
    }  
    }
    iHP1 = HP1 * ( 1 - 0.17 ); HP1 = ceil(iHP1);HP1 = checkhp (HP1);
    iEXP1 = EXP1 * ( 1 + 0.17 ); EXP1 = ceil(iEXP1); EXP1=checkexp(EXP1);
    S = squareNnearest(EXP1);
    if ( EXP1 >= S ) { p2 = 1 ;}
    else { p2 = ((EXP1 / (S * 1.00)) + 80) / 123.00;}
    // Road 3
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if ( E2 <= 9 && E2 >= 0) {
        p3 = (arr [E2]) / 100.00 ;
    }
    else  {
        int s = 0, a, b;
        a = E2 / 10;
        b = E2 % 10;
        s = a + b ;
        if (s > 9) {
            int c; 
            c = s % 10;
            p3 = (arr[c]) /100.00;
        }
        else p3 = (arr[s]) / 100.00;
    }
    // Xác suất trung bình
    if ( (p1 == 1) && (p2 == 1)) {
        if (p3 == 1) {
            iEXP1 = EXP1 * ( 1 - 0.25);
            EXP1 = ceil(iEXP1);EXP1=checkexp(EXP1);
        }
        else { 
            p = (p1 + p2 + p3) / 3.0;
            if ( p < 0.5 ) { 
            iHP1 = HP1 * 0.85; HP1 = ceil(iHP1);
            iEXP1 = EXP1 * 1.15; EXP1 = ceil(iEXP1);
            }
            else {
             iHP1 = HP1 * 0.9; HP1 = ceil(iHP1);
            iEXP1 = EXP1*  1.2; EXP1 = ceil(iEXP1);
            }}
    }
    else { p = (p1 + p2 + p3) / 3.0;
    if ( p < 0.5 ) { 
        iHP1 = HP1 * 0.85; HP1 = ceil(iHP1);
        iEXP1 = EXP1 * 1.15; EXP1 = ceil(iEXP1);
    }
    else {
        iHP1 = HP1 * 0.9; HP1 = ceil(iHP1);
        iEXP1 = EXP1*  1.2; EXP1 = ceil(iEXP1);
    }}
    
    HP1 = checkhp (HP1); EXP1 = checkexp(EXP1); M1 = checkM(M1) ; 
    return HP1 + EXP1 + M1;}
    else { return -99;}
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    HP1 = checkhp (HP1); EXP1 = checkexp(EXP1); 
    HP2 = checkhp (HP2); EXP2 = checkexp(EXP2);
    if ( E3 > 99 || E3 < 0) return -99;
    int i, j, countI = 0, countJ = 0, m, n;
    int A[10][10]; //ma trận điểm taxi
    for ( i = 0; i < 10 ; i++){//Nhập ma trận
        for ( j = 0 ; j < 10 ; j++) {
            A[i][j] = ((E3 * j) + ( i * 2 )) * ( i - j);
            if (A[i][j] > (E3 * 2)){
            countI++;
            }
            if (A[i][j] < (- E3)){
            countJ++;
            }
        }
    }
    m=two_digitsum(countI);
    n=two_digitsum(countJ);
    int max = -1000000000;
    // đường chéo trái
    int x = m , y = n;
    while ( (x < 10) && (y< 10)){
        if (max < A[x][y]) {
            max = A[x][y]; 
        }
        x++; y++;
    }
    x=m, y=n;
    while ((x>=0) && (y>=0)){
        if (max < A[x][y]) {
            max = A[x][y]; 
        }
        x--; y--;
    }
    // Đường chéo phải
   x = m , y = n;
    while ( (x < 10) && (y>= 0)){
        if (max < A[x][y]) {
            max = A[x][y]; 
        }
        x++; y--;
    }
    x=m, y=n;
    while ((x>=0) && (y<10)){
        if (max < A[x][y]) {
            max = A[x][y]; 
        }
        x--; y++;
    }
    float iEXP1,iEXP2, iHP1,iHP2;
    if ((abs (A[m][n]) - (max))<= 0 ) {
        iHP1 = HP1 * 1.1; HP1 = ceil (iHP1); HP1 = checkhp (HP1);
        iEXP1 = EXP1 * 1.12; EXP1 = ceil (iEXP1); EXP1 = checkexp(EXP1);
        iHP2 = HP2 * 1.1; HP2 = ceil (iHP2); HP2 = checkhp (HP2);
        iEXP2 = EXP2 *1.12; EXP2 = ceil (iEXP2); EXP2 = checkexp(EXP2);
        return max;
    }
    else {
        iHP1 = HP1 * 0.9; HP1 = ceil (iHP1); HP1 = checkhp (HP1);
        iEXP1 = EXP1 * 0.88; EXP1 = ceil (iEXP1); EXP1 = checkexp(EXP1);
        iHP2 = HP2 * 0.9; HP2 = ceil (iHP2); HP2 = checkhp (HP2);
        iEXP2 = EXP2 * 0.88; EXP2 = ceil (iEXP2); EXP2 = checkexp(EXP2);
        return (A[m][n]);
    }
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    int length = strlen (s);
    int se = checkse(s,email); 
    int same = checksame(s);// kt 2 kí tự liên tiếp giống nhau TH5
    int sc = specialc (s); //kt kí tự đặc biệt TH6
    int m = checkchar(s); //kt có vi phạm input TH7
    if (length < 8) {return -1;}
    else if (length > 20) {return -2;}
    else if (se != -99) {return -300 - se;}
    else if (same != -1) {return -400 - same;}
    else if (sc == -99) { return -5;}
    else if (m != -1) {return m;}
    else {return -10;}
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
 int b[200] = {0}; int i,j; int max = 0; int lct, length, lengthmax=0 , dem;// lct=location
    for( i = 0; i < num_pwds; i++){
        if(b[i] == 0){
            dem = 1;
            const char* x = arr_pwds[i];
            for( j = i + 1; j < num_pwds; j++){
                const char* y = arr_pwds[j];
                if(strcmp (x,y) == 0){
                    ++dem;
                    b[j] = 1;  // đánh dấu 
                }  
            }
           length=strlen(arr_pwds[i]); 
        }
        if (dem > max || dem == max && length > lengthmax ) {
           max = dem ; 
            lct = i;
            lengthmax = length ; 
            }   
    }
    return lct;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////