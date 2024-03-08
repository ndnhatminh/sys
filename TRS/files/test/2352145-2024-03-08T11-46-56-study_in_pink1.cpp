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

//check input
int mau(int& HP) {
    if (HP > 666)
        HP = 666;
    else if (HP < 0)
        HP = 0;
    return HP;
}
int kn(int& EXP) {
    if (EXP > 600)
        EXP = 600;
    else if (EXP < 0)
        EXP = 0;
    return EXP;
}
int tien(int& M) {
    if (M > 3000)
        M = 3000;
    else if (M < 0)
        M = 0;
    return M;
}
int nv(int& E) {
    if (E < 0 || E>99)
        E = -99;
    return E;
}
//round 
int roundup(double n) {
    int m=n;
    double t=n;
    
    if (t-m<0.0001){
        return m;
    }
    else{
        return ceil(t);
    }
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1){
    // TODO: Complete this function
    
    
if (e1 == -99) {
    int sum = exp1 + exp2;
    return sum = -99;
}

else if (e1 == 0) {
    exp1= kn(exp1);
    exp2 = kn(exp2);
    int D = e1 * 3 + exp1 * 7;
    exp2 += 29;
    if (D % 2 == 0) {
        exp1 = roundup(exp1+D/200.0);
        
        
        
    }
    else{
        exp1 = roundup(exp1-D/100.0);
        
        
        
    }
}

else if (e1 == 1) {
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    int D = e1 * 3 + exp1 * 7;
    exp2 += 45;
    if (D % 2 == 0) {
        exp1 = roundup(exp1+D/200.0);
        
        
    }
    else{ 
        exp1 = roundup(exp1-D/100.0);
        
        
    }
}

else if (e1 == 2) {
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    int D = e1 * 3 + exp1 * 7;
    exp2 += 75;
    if (D % 2 == 0) {
        exp1 = roundup(exp1+D/200.0);
        
        
    }
    else{
        exp1 = roundup(exp1-D/100.0);
        
        
    }
}

else if (e1 == 3) {
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    int D = e1 * 3 + exp1 * 7;
    exp2 += 29 + 45 + 75;
    if (D % 2 == 0) {
        exp1 = roundup(exp1+D/200.0);
        
        
    }
    else {
        exp1 = roundup(exp1-D/100.0);
        
        
    }
}

else if (e1 >= 4 && e1 <= 19) {
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    int i = roundup(e1/4.0);
    exp2 += i + 19;
    
    exp1 -= e1;
    
}

else if (e1 >= 20 && e1 <= 49) {
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    int j = roundup(e1/9.0);
    exp2 += j + 21;
    
    exp1 -= e1;
   
}

else if (e1 >= 50 && e1 <= 65) {
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    int k =roundup(e1/16.0);
    exp2 += k + 17;
    
    exp1 -= e1;
    
}

else if (e1 >= 66 && e1 <= 79) {
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    int l = roundup(e1/4.0);
    exp2 += l + 19;
    
    exp1 -= e1;
    if (exp2 > 200) {
        int m = roundup(e1/9.0);
        exp2 += m + 21;
        
    }
   
}
else if (e1 >= 80 && e1 <= 99){
    exp1 = kn(exp1);
    exp2 = kn(exp2);
    
    exp2 = roundup(exp2 + 19+ e1/4.0);
    
    
    exp1 -= e1;
    exp2 = roundup(exp2 +  21+ e1/9.0);
    
    
    if (exp2 > 400) {
        
        exp2 = roundup(exp2+17+e1/16.0);
        
        exp2= roundup(exp2+0.15*1.0*exp2);
        
        
    }
   
    
}

else {
    return -99;
}
    exp1 = kn(exp1);

    exp2 = kn(exp2);

    return exp1 + exp2;
}

//So chinh phuong
int cp(int &n){
   int a = sqrt(n);
   int b = sqrt(n)+1;
   int d1= abs(a*a-n);
   int d2 = abs (b*b-n);
   if (d1>d2) return b*b;
   else return a*a;

}


//P1
float street1 (int &exp1){
    int S = cp(exp1);
    float P1;
    if (exp1>=S){
        P1= 1;
        
    }
    else{
        P1= ((1.0*exp1/S)+80.0) / 123.0;
        
     }
     return P1;
    
}
// P2
void sk1(int& HP1, int& M1, int& sum) {
    if (HP1 < 200) {
        HP1 = roundup(1.3*HP1);
        

        sum = 150;
        M1 -= sum;


    }

    else {
        sum = 70;
        M1 -= sum;


        HP1 = roundup(1.1*HP1);
        
    }

    
    HP1 = mau(HP1);
    M1 = tien(M1);
    
    
}


void sk2(int& M1, int &EXP1, int& sum) {
    if (EXP1 < 400) {
        sum = 200;
        M1 -= sum;
    }
    else {
        sum = 120;
        M1 -= sum;
    }
    EXP1 = roundup( 1.13 * EXP1);
    
    EXP1 = kn(EXP1);
    M1 = tien(M1);
    
    
    
}

void sk3(int &M1, int &EXP1, int &sum) {
    if (EXP1 < 300) {
        sum = 100;
        M1 -= sum;
    }
    else {
        sum = 120;
        M1 -= sum;
    }
    EXP1 = roundup(0.9 * EXP1);
    
    EXP1 = kn(EXP1);
    M1 = tien(M1);
    
    
    
}

void final(float& P1, float& P2, float& P3, int& HP1, int& EXP1) {
    if (P1 == 1 && P2 == 1 && P3 == 1) {
        EXP1 = roundup(EXP1 * 0.75);
        
    }
    else {
        float P = (P1 + P2 + P3) / 3.0;
        if (P < 0.5) {
            HP1 = roundup(HP1 * 0.85);
            
            EXP1 = roundup(1.15 * EXP1);
            
            
        }
        else {
            HP1 = roundup(HP1 * 0.9);
            
            EXP1 = roundup(1.2 * EXP1);
            
           
        }
    }
    EXP1 = kn(EXP1);
    HP1 = mau(HP1);
    
    

}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    
    
    
    if (E2 == -99){
        int result = HP1 + EXP1 + M1;
        return result = -99;
    }

    else if (E2>=0 && E2<=99){
        
        if (E2 %2 != 0){
            if (M1==0){ 
                return -99;}
            else{
                HP1 = mau(HP1);
                EXP1 = kn(EXP1);
                M1 = tien (M1);
                float P1 = street1(EXP1);
               
                
                float nuasotienbandau = 0.5 *M1;
                int sum=0;
                
                int a = 0;
                while (a < nuasotienbandau) {
    
                    sk1(HP1, M1, sum);
                    a = a + sum;
                    if (a > nuasotienbandau) break;
                    sk2(M1, EXP1, sum);
                    a = a + sum;
    
                    if (a > nuasotienbandau) break;
                    sk3(M1, EXP1, sum);
                    a = a + sum;
                    if (a > nuasotienbandau) break;
}
                    HP1= roundup(HP1*0.83);
                    
                    EXP1 =roundup(EXP1*1.17);
                    
                    EXP1 = kn(EXP1);
                    HP1 = mau(HP1);
                    float P2 = street1(EXP1);
                    float P3;
                    float arr[10] = {0.32, 0.47, 0.28, 0.79, 1.0 , 0.50, 0.22, 0.83, 0.64, 0.11};
                    for (int i=0; i<10;i++){
                        if (E2<10){
                            P3 = arr[E2];
                        }
        
                        else{
                            int s = (E2 / 10) + (E2 % 10);
                            
            
                            P3 = arr[s%10];
                        }
                    }
        

    
                    final(P1,P2,P3,HP1,EXP1);
        }
    }
    
    
        else{
            if (M1==0){return -99;}
            else {
            HP1 = mau(HP1);
            EXP1 = kn(EXP1);
            M1 = tien(M1);
            float P1 = street1(EXP1);
            
            int s=0;
            for (int i=0;i<1;i++){
                sk1(HP1,M1,s);
                if (M1==0) break;
                sk2(M1,EXP1,s);
                if (M1==0) break;
                sk3(M1,EXP1,s);
                if (M1==0) break;

            }
            
            
            
                
        
            
            HP1=roundup(HP1*0.83);
            EXP1=roundup(EXP1*1.17);
           
            EXP1 = kn(EXP1);
            HP1 = mau(HP1);
            float P2 = street1(EXP1);
            float P3;
            float arr[10] = {0.32, 0.47, 0.28, 0.79, 1.0, 0.50, 0.22, 0.83, 0.64, 0.11};
            for (int i=0; i<10;i++){
                if (E2<10){
                    P3 = arr[E2];
                }
        
                else{
                    int s = (E2 / 10) + (E2 % 10);
                    P3 = arr[s%10];
                }
            }
        

    
    final(P1,P2,P3,HP1,EXP1);
        }}
    }
    
else{
        return -99;
    }
        HP1 = mau(HP1);
        EXP1 = kn(EXP1);
        M1 = tien(M1);
    
    
    
    
    return HP1 + EXP1 + M1;
}

//Calculate (i,j)

int index(int& count) {
    int sum = 0;
    while (count != 0) {
        sum += count % 10;
        count /= 10;
    }

    int k = sum;
    int i = 0;
    if (k >= 10) {
        while (k != 0) {
            i += k % 10;
            k /= 10;
        }
    }
    else i = k;
    return i;

}
//max
int findMax(int& a, int& b) {
    int max = a;
    if (b > a) {
        max = b;
    }
    return max;
}



// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if (E3>=0&&E3<=99){
    HP1 = mau(HP1);
    HP2 = mau(HP2);
    EXP1 = kn(EXP1);
    EXP2 = kn(EXP2);
    E3 = nv(E3);
    int m[10][10];
    int SW[10][10];

    int countpos = 0;
    int countneg = 0;
    for (int a = 0;a<10;a++){
        for (int b = 0;b<10;b++){
            m[a][b] = ((E3 * b) + (a * 2)) * (a - b);
            if (m[a][b]>E3*2){
                countpos++;
            }
            else if (m[a][b]<(-E3)){
                countneg++;
            }
        }
    }
    int i = index(countpos);
    int j = index(countneg);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
        int max = m[i][j];
        for (int o = i, n = j; o < 10 && n >= 0; o++, n--) {
            max = findMax(m[o][n], max);
        }
        for (int o = i, n = j; o >= 0 && n < 10; o--, n++) {
            max = findMax(m[o][n], max);
        }
        for (int o = i, n = j; o < 10 && n < 10; o++, n++) {
            max = findMax(m[o][n], max);
        }
        for (int o = i, n = j; o >= 0 && n >= 0; o--, n--) {
            max = findMax(m[o][n], max);
        }
        SW[i][j] = max;

    }
}
    if (abs(m[i][j])>SW[i][j]){
        
        EXP1 =roundup(EXP1 *0.88);
        HP1 =roundup(HP1 * 0.9);
        EXP2=roundup(EXP2 * 0.88);
        HP2 =roundup(HP2 * 0.9);
        
        EXP1 = kn(EXP1);
        HP1 = mau(HP1);
        EXP2 = kn(EXP2);
        HP2 = mau(HP2);
        return m[i][j];
    }
    else {
        EXP1 =roundup(EXP1 *1.12);
        HP1 =roundup(HP1 * 1.1);
        EXP2 =roundup(EXP2 * 1.12);
        HP2 =roundup(HP2 * 1.1);
        EXP1 = kn(EXP1);
        HP1 = mau(HP1);
        EXP2 = kn(EXP2);
        HP2 = mau(HP2);
        
        
        return SW[i][j];
    }
    }
    else{
        return -99;
    }


    

 
    return -1;
}

//a - z:97-122
//A-Z:65-90
//0-9:48-57

         
    


//contain more than 2 consecutive and identical characters.

bool consect(string a){
    for (int i = 2; i < a.length(); ++i) {
        if (a[i] == a[i - 1] && a[i] == a[i - 2]) {
            return true;  
        }
    }
        
    return false;
        
    
    
}



//find index of the first more than 2 consect

int Index(string a){
    int i;
    for (i = 2; i < a.length(); ++i) {
        if (a[i] == a[i - 1] && a[i] == a[i - 2]) {
            return i-2;  
        }

}
return i-2;
}

//check se in s

bool check(string a, string b) {
    if (b.find(a) != string::npos){
        return true;
    }
    else {
        return false;
    }

}



//find position of se

int findPosition(string a, string b) {
    
    size_t position = b.find(a);

    

        
    return static_cast<int>(position);
    
}

//tra ve vi tri sai

bool valid(char c){
    if (('0' <= c && c <= '9') || ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '@' || c == '#' || c == '%' || c == '$' || c == '!'){
        return true;
    }
    else {
        return false;
    }

}


//check ki tu thuong hoa so db
bool Isvalid(string &a, bool &b){
    b=false;
    for (char c:a){
        if(('0' <= c && c <= '9') && ('a' <= c && c <= 'z') && ('A' <= c && c <= 'Z') && c == '@' && c == '#' && c == '%' && c == '$' && c == '!'){
            b=true;

        }
        else{
            b=false;
        }


}
return b;
}




// Task 4
int checkPassword(const char * s, const char * email){
    // TODO: Complete this function
    string e(email);
    string pw(s);
    string se=e.substr(0,e.find('@'));
    bool Charspec = false;
    for (int i=0;i<pw.length();i++){
        if(pw[i] == '@' || pw[i] == '#' || pw[i] == '%' || pw[i] == '$' || pw[i] == '!'){
            Charspec =true;
        }
    }

    bool checking;
    Isvalid(pw, checking);
    
    if(pw.length()<8){
        return -1;
    }
    else if(pw.length()>20){
        return -2;
    }
    else if (check(se,pw)){
        int c=findPosition(se,pw);
        return -(300+c);
    }
    else if(consect(pw)){
        int a =Index(pw);
        return -(400+a);
    }
    else if(!Charspec){
        return -5;
    }
    else if(!checking){
        for (int i=0;i<pw.length();i++){
            if(!valid(pw[i])){
                return i;
                break;
            }
                    
        }
    }
    else {
        return -10;
    }
return -10;
return -99;
}

    
    

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int maxCount = 0;           
    int maxLength = 0;             
    string Loop; 

   
    for (int i = 0; i < num_pwds; ++i) {
        string current = arr_pwds[i];
        int count = 1;  
        int length = current.length(); 

        
        for (int j = i + 1; j < num_pwds; ++j) {
            if (arr_pwds[j] == current) {
                ++count; 
            }
        }

       
        if (count > maxCount || (count == maxCount && length > maxLength)) {
            maxCount = count;
            maxLength = length;
            Loop = current;
        }
    }

    
    for (int i = 0; i < num_pwds; ++i) {
        if (arr_pwds[i] == Loop) {
            return i; 
        }
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////