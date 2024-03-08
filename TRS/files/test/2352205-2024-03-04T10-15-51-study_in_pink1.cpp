#include "study_in_pink1.h"

bool readFile(
    const string &filename,
    int &HP1,
    int &HP2,
    int &EXP1,
    int &EXP2,
    int &M1,
    int &M2,
    int &E1,
    int &E2,
    int &E3)
{
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open())
    {
        ifs >> HP1 >> HP2 >> EXP1 >> EXP2 >> M1 >> M2 >> E1 >> E2 >> E3;
        return true;
    }
    else
    {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

//! Task 1
int firstMeet(int & EXP1, int & EXP2, int E1) {
    //TODO
    if (E1 < 0 || E1 > 99) return -99;

    if (E1 >= 0 && E1 <= 3){
        if(E1 == 0){EXP2 += 29;}
        else if(E1==1){EXP2 += 45;}
        else if(E1==2){EXP2 += 75;}
        else if (E1 == 3){EXP2 += 149;}
        
        int D = E1*3 + EXP1*7;
        if(D%2 == 0){EXP1 =ceil(EXP1 + double(D)/200);}
        else {EXP1 = ceil(EXP1 - double(D)/100);}
        
    }

    if (E1>=4 && E1<=99){
        if(E1>=4 && E1<=19){EXP2 =ceil( EXP2 + double(E1)/4 + 19);}
        else if(E1>=20 && E1<=49){EXP2 = ceil(EXP2 + double(E1)/9 + 21);}
        else if(E1>=50 && E1<=65){EXP2 = ceil(EXP2 + double(E1)/16 + 17);}
        else if(E1>=66 && E1<=79){
            EXP2 = ceil(EXP2 + double(E1)/4 + 19);
            if(EXP2 > 200){
                EXP2 = ceil(EXP2 + double(E1)/9 + 21);
                }
        }
        else if(E1>=80 && E1<=99){
            EXP2 = ceil(EXP2 + double(E1)/4 + 19);
            EXP2 = ceil(EXP2 + double(E1)/9 + 21);
            if(EXP2 >400){
                EXP2 = ceil(EXP2 + double(E1)/16 + 17);
                EXP2 = ceil(double(EXP2)*1.15);
            }
            
        }
        EXP1 -= E1;
    }

    
    if(EXP1<0) {EXP1=0;} 
    if(EXP1>600) {EXP1=600;}
    if(EXP2<0) {EXP2=0;}
    if(EXP2>600) {EXP2=600;}

    return EXP1 + EXP2;
}

//Task2
int traceLuggage(int& HP1, int& EXP1, int& M1, int E2)
{
// TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    double P1,P2,P3; 
    int S,c,d,e;
    c = round(sqrt(double(EXP1)));
    d = EXP1 - c*c; e = (c+1)*(c+1) - EXP1;
    if(d<e) S = c*c;
    else S = (c+1)*(c+1);

    if (EXP1 >= S) P1 = 100;
    else P1 = (double(EXP1)/S + 80)/1.23;
    if( E2%2 != 0){
        int a = M1; 
        int m =0; 
        while(true){
            //sự kiện 1
            if(HP1 < 200) 
            {
                if(M1 > 150) {M1 -=150; HP1 = ceil(double(HP1)*13/10); m += 150;}
                else {M1 = 0; HP1 = ceil(double(HP1)*13/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1>70) {M1 -= 70; HP1 = ceil(double(HP1)*11/10); m+= 70;}
                else {M1 = 0; HP1 = ceil(double(HP1)*11/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
            if(m>ceil(double(a)/2)) break;
            
            if(EXP1 < 400)
            {
                if(M1 > 200){M1 -= 200; EXP1 = ceil(double(EXP1)*11.3/10); m += 200;}
                else {M1 = 0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1 >120) {M1 -= 120; EXP1 = ceil(double(EXP1)*11.3/10); m+=120;}
                else {M1=0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
            if(m>ceil(double(a)/2)) break;
            
            if(EXP1 <300)
            {
                if(M1 > 100){M1 -= 100; EXP1 = ceil(double(EXP1)*9/10); m+=100; }
                else {M1 = 0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            else
            {
                if(M1>120){M1 -= 120; EXP1 = ceil(double(EXP1)*9/10); m+= 120;}
                else {M1=0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
            if(m>ceil(double(a)/2)) break;
        }
        HP1 = ceil(double(HP1)*8.3/10); EXP1 = ceil(double(EXP1)*11.7/10);
    }
    else
    {
        for(int i = 0; i < 1; i++){
            if(HP1 < 200) 
            {
                if(M1 > 150) {M1 -=150; HP1 = ceil(double(HP1)*13/10);}
                else {M1 = 0; HP1 = ceil(double(HP1)*13/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1>70) {M1 -= 70; HP1 = ceil(double(HP1)*11/10); }
                else {M1 = 0; HP1 = ceil(double(HP1)*11/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;

            if(EXP1 < 400)
            {
                if(M1 > 200){M1 -= 200;  EXP1 = ceil(double(EXP1)*11.3/10);}
                else {M1 = 0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break; }
            }
            else 
            {
                if(M1 >120) {M1 -= 120; EXP1 = ceil(double(EXP1)*11.3/10);}
                else {M1=0; EXP1 = ceil(double(EXP1)*11.3/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;

            if(EXP1 <300)
            {
                if(M1 > 100){M1 -= 100; EXP1 = ceil(double(EXP1)*9/10); }
                else {M1 = 0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            else
            {
                if(M1>120){M1 -= 120; EXP1 = ceil(double(EXP1)*9/10);}
                else {M1=0; EXP1 = ceil(double(EXP1)*9/10);if(EXP1 > 600) EXP1 = 600;if(EXP1 < 0) EXP1 = 0;  if(HP1 > 666) HP1 = 666;if(HP1 < 0) HP1 = 0; if(M1 > 3000) M1 = 0;if(M1 < 0) M1 = 0; break;}
            }
            if(EXP1 > 600) EXP1 = 600;
            if(EXP1 < 0) EXP1 = 0; 
            if(HP1 > 666) HP1 = 666;
            if(HP1 < 0) HP1 = 0;
            if(M1 > 3000) M1 = 0;
            if(M1 < 0) M1 = 0;
        }
        HP1 = ceil(double(HP1)*83/100); EXP1 = ceil(double(EXP1)*11.7/10);
    }
    if(EXP1 > 600) EXP1 = 600;
    if(EXP1 < 0) EXP1 = 0; 
    if(HP1 > 666) HP1 = 666;
    if(HP1 < 0) HP1 = 0;
    if(M1 > 3000) M1 = 0;
    if(M1 < 0) M1 = 0;

    int c2,d2,e2,S2;
    c2 = round(sqrt(double(EXP1)));
    d2 = EXP1 - c2*c2; e2 = (c2+1)*(c2+1) - EXP1;
    if(d2<e2) S2 = c2*c2;
    else S2 = (c2+1)*(c2+1);

    if (EXP1 >= S2) P2 = 100;
    else P2 = (double(EXP1)/S2 + 80)/1.23;

    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(E2 < 10) { i = E2;}
    else { i = (E2/10 + E2%10)%10; }
    P3 = P[i];

    if(P1 == 100 && P2 == 100 && P3 == 100) { EXP1 = ceil(double(EXP1)*7.5/10);}
    else
    {
        double Pave = (P1 + P2 + P3)/3;
        if(Pave < 50) { HP1 = ceil(double(HP1)*85/100); EXP1 = ceil(double(EXP1)*11.5/10); }
        else { HP1 = ceil(double(HP1)*9/10); EXP1 = ceil(double(EXP1)*12/10); }
    }
    if(EXP1 > 600) EXP1 = 600;
    if(EXP1 < 0) EXP1 = 0; 
    if(HP1 > 666) HP1 = 666;
    if(HP1 < 0) HP1 = 0;
    if(M1 > 3000) M1 = 0;
    if(M1 < 0) M1 = 0;
    return HP1 + EXP1 + M1;
}

//! Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3 < 0 || E3 > 99) return -99;
    int map[10][10];
    for( int i = 0; i < 10; i ++ ){
        for ( int j = 0; j < 10 ; j ++)
        { 
            map[i][j] = ((E3*j) + (i*2))*(i-j);
        }
    }

    int x = 0, y = 0; 
    for( int i = 0; i < 10; i ++ ){
        for ( int j = 0; j < 10 ; j ++)
        { 
            if( map[i][j] > E3*2 ) x ++;
            else if ( map[i][j] < -E3) y++;
        }
    }
    while ( x >= 10 && x <= 99) { x = x/10 + x%10; }
    while (y >= 10 && y <= 99) { y = y/10 + y%10;}
    
    int taxipoint = map[x][y];
  
    int max[4] = {taxipoint,taxipoint,taxipoint,taxipoint};

    int a = x, b = y;
   
    while(a <= 9 && b >= 0 ){
        if(map[a][b] > max[0]) { max[0] = map[a][b];}
        a++; b--;
    } 
   
    a = x, b = y;
    while(a >= 0 && b >= 0 ){
        if(map[a][b] > max[1]) { max[1] = map[a][b];}
        a--; b--;
    } 
    
    a = x, b = y;
    while(a <= 9 && b <=9 ){
        if(map[a][b] > max[2]) { max[2] = map[a][b];}
        a++; b++;
    } 
   
    a = x, b = y;
    while(a >= 0 && b <= 9 ){
        if(map[a][b] > max[3]) { max[3] = map[a][b];}
        a--; b++;
    } 
    
    
    int sherlockpoint = max[0];
    for(int i = 1; i <4;  i++){
        if(sherlockpoint < max[i]) sherlockpoint = max[i];
    }
    
    if(abs(taxipoint) > sherlockpoint ) {
        EXP1 = ceil(double(EXP1)*88/100);
        HP1 = ceil(double(HP1)*9/10);
        EXP2 = ceil(double(EXP2)*88/100);
        HP2 = ceil(double(HP2)*9/10);
        if(EXP1 > 600) EXP1 = 600;
        if(EXP1 < 0) EXP1 = 0; 
        if(HP1 > 666) HP1 = 666;
        if(HP1 < 0) HP1 = 0;
        if(EXP2 > 600) EXP2 = 600;
        if(EXP2 < 0) EXP2 = 0; 
        if(HP2 > 666) HP2 = 666;
        if(HP2 < 0) HP2 = 0;
        return taxipoint;
     }
    
     else {
        EXP1 = ceil(double(EXP1)*11.2/10);
        HP1 = ceil(double(HP1)*11/10);
        EXP2 = ceil(double(EXP2)*11.2/10);
        HP2 = ceil(double(HP2)*11/10);
        if(EXP1 > 600) EXP1 = 600;
        if(EXP1 < 0) EXP1 = 0; 
        if(HP1 > 666) HP1 = 666;
        if(HP1 < 0) HP1 = 0;
        if(EXP2 > 600) EXP2 = 600;
        if(EXP2 < 0) EXP2 = 0; 
        if(HP2 > 666) HP2 = 666;
        if(HP2 < 0) HP2 = 0;
        return sherlockpoint;
     }
}

//! Task 4
int checkPassword(const char *s, const char *email){
    char* strprt;
    string a = string(email);
    string Ss = string(s);
   
    int c = a.find("@");
    string se = a.substr(0,c);

    if(Ss.size() <8) { return -1; }
    else if(Ss.length() >20) { return -2;}
    
    char* matkhau = new char[se.length()];
    strcpy(matkhau, se.c_str());
    const char* result = strstr(s,matkhau);
    if (result != nullptr) { int o = result - s; return -(300 + o);}
    
    
    for(int i =0; i < Ss.length(); i++ ){
        if(Ss[i] == Ss[i+1] && Ss[i] == Ss[i+2]) { return -(400+i);}
    }
    
    for(int j =0;j<1;j++){
    int d = Ss.find("@");
    if(d == -1){
        int d1 = Ss.find("#");
        if(d1 == -1){
            int d2 = Ss.find("$");
            if(d2 == -1){
                int d3 = Ss.find("%");
                if(d3 == -1){
                    int d4 = Ss.find("!");
                    if(d4 == -1){return -5; break;}
                }
            }
        }
    }
    string kthl = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM!@#$%1234567890";
    int e=0;
    for(int k = 0; k < Ss.size();k++){
        int f = kthl.find(Ss[k]);
        if(f == -1) { return k; break;}
        else {e+=1;}
    }
    if(e == Ss.size()) {return -10;}
    }
    return -1;
}

//! Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int count[num_pwds] = {0};
    int length[num_pwds] = {0};
    for (int i = 0; i < num_pwds; i++) {
        int j = 0;
        while (arr_pwds[i][j] != '\0') {
            length[i]++;
            j++;
        }
        for (int k = i + 1; k < num_pwds; k++) {
            if (strcmp(arr_pwds[i], arr_pwds[k]) == 0) {
                count[i]++;
            }
        }
    }
    int correctpwd = 0;
    int a = count[0];
    int b = length[0];
    for (int i = 1; i < num_pwds; i++) {
        if (count[i] > a || (count[i] == a && length[i] > b)) {
            a = count[i];
            b = length[i];
            correctpwd = i;
        }
    }
    return correctpwd; 
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////