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
inline bool UnvalidEvent(int E){
    if(E>=0 && E<=99) return false;
    return true;
}

inline bool EvenOrOdd(int num){
    if(num%2 == 0){
        return true;
    }
    else{
        return false;
    }
}

inline double take_the_decimal(double num, int n){
    int a = pow(10,n);
    double number = (round(num * a))/a;
    return number;
}

inline int hplimit(int hp){
    if(hp > 666) return hp = 666;
    if(hp < 0) return hp = 0;
    return hp;
}

inline int explimit(int exp){
    if(exp > 600) return exp = 600;
    if(exp < 0) return exp = 0;
    return exp;
}
inline int moneylimit(int m){
    if(m > 3000) return m = 3000;
    if(m < 0) return m = 0;
    return m;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(UnvalidEvent(e1)) return -99;

    exp1 = explimit(exp1);
    exp2 = explimit(exp2);



    if(e1>=0 && e1<=3){
        int D = e1*3 + exp1*7;

        if(EvenOrOdd(D)){
            exp1 = ceil(exp1 + (D/200.00));
        }else{
            exp1 = ceil(exp1 - (D/100.00));
        }

        if(e1==0) exp2 +=29;
        else if (e1==1) exp2 += 45;
        else if (e1==2) exp2 += 75;
        else if (e1==3) exp2 += (29 + 45 + 75);

        exp1 = explimit(exp1);
        exp2 = explimit(exp2);
    }

    if(e1>=4 && e1<=99){
        exp1 = explimit(exp1 - e1);
        
        if(e1>=4 && e1<=19){
            exp2 = explimit(ceil(exp2 + (e1/4.00 + 19)));
        }
        else if(e1>=20 && e1<=49){
            exp2 = explimit(ceil(exp2 + (e1/9.00 + 21)));
        }
        else if(e1>=50 && e1<=65){
            exp2 = explimit(ceil(exp2 + (e1/16.00 + 17)));
        }
        else if(e1>=66 && e1<=79){
            exp2 = explimit(ceil(exp2 + (e1/4.00 + 19)));
            if(exp2 > 200){
               exp2 = explimit(ceil(exp2 + (e1/9.00 + 21))); 
            }
        }
        else {
            exp2 = explimit(ceil(exp2 + (e1/4.00 + 19)));
            exp2 = explimit(ceil(exp2 + (e1/9.00 + 21)));
            if(exp2 > 400){
                exp2 = ceil(exp2 + (e1/16.00 + 17));
                exp2 = ceil(exp2*1.15);
                exp2 = explimit(exp2);
            }
            
        }
    }
    return exp1 + exp2;
}



/////////////////////////////////////////////////////////////////////////////////////////////
// Task 2
inline float poly(float x, float a, float b){
    return  ceil(a*x+b);
}

float SCP_gan_nhat(int N) {
    int x = sqrt(N);
    if ((x * x) == N) {
        cout << N <<endl;
        return N;
    }

    int aboveN = (x + 1) * (x + 1);
    int belowN = x * x;
    int chenhlech1 = aboveN - N;
    int chenhlech2 = N - belowN;

    if (chenhlech1 > chenhlech2)
       return belowN ;
    else
       return aboveN ;
}

inline float AvgP( float P1, float P2, float P3){
    float result = (P1 + P2 + P3)/3;
    return result;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(UnvalidEvent(E2)) return -99;
    HP1 = hplimit(HP1);
    EXP1 = explimit(EXP1);
    M1 = moneylimit(M1);

    float P1,P2,P3;
    const int TongTienBanDau = M1;
    const float NuaTienBanDau = M1/2.00;

    // Road 1
    if( SCP_gan_nhat(EXP1)<= EXP1){
        P1 = 1;
    } else {
        P1 = (EXP1/SCP_gan_nhat(EXP1) + 80)/123.00;
        //P1 = take_the_decimal(P1, 2);
    }

    // Road 2
    if(EvenOrOdd(E2)){
        int TongTienDaChi = 0;
        while(TongTienDaChi<TongTienBanDau){
            if(HP1<200){
                HP1 = hplimit(poly(HP1,1.30,0));
                M1 = moneylimit(poly(M1,1,-150));
                TongTienDaChi += 150;
            } else {
                HP1 = hplimit(poly(HP1,1.10,0));
                M1 = moneylimit(poly(M1,1,-70));
                TongTienDaChi += 70;
            }
            if(TongTienDaChi>TongTienBanDau){
                M1 = 0;
                break;
            }

            if(EXP1<400){
                EXP1 = explimit(poly(EXP1,1.13,0));
                M1 = moneylimit(poly(M1,1,-200));
                TongTienDaChi += 200;
            } else {
                EXP1 = explimit(poly(EXP1,1.13,0));
                M1 = moneylimit(poly(M1,1,-120));
                TongTienDaChi += 120;
            }
            if(TongTienDaChi>TongTienBanDau){
                M1 = 0;
                break;
            }
            if(EXP1<300){
                EXP1 = explimit(poly(EXP1,0.90,0));
                M1 = moneylimit(poly(M1,1,-100));
                TongTienDaChi += 100;

            } else {
                EXP1 = explimit(poly(EXP1,0.90,0));
                M1 = moneylimit(poly(M1,1,-120));
                TongTienDaChi += 120;
                }
                
            if(TongTienDaChi>TongTienBanDau){
                M1 = 0;
                break;
            } else {
                break;
            }
        }
        HP1 = hplimit(poly(HP1,0.83,0));
        EXP1 = explimit(poly(EXP1,1.17,0));

    } else {
        int TongTienDaChi = 0;
        while(TongTienDaChi < NuaTienBanDau){
            if(HP1<200){
                HP1 = hplimit(poly(HP1, 1.30, 0));
                M1 = moneylimit(poly(M1,1,-150));
                TongTienDaChi += 150;
            } else {
                HP1 = hplimit(poly(HP1, 1.10, 0));
                M1 = moneylimit(poly(M1,1,-70));
                TongTienDaChi += 70;
            }
            if(TongTienDaChi > NuaTienBanDau) break;
            if(EXP1<400){
                M1 = moneylimit(poly(M1,1,-200));
                EXP1 = explimit(poly(EXP1, 1.13, 0));
                TongTienDaChi += 200;
            } else {
                M1 = moneylimit(poly(M1,1,-120));
                EXP1 = explimit(poly(EXP1, 1.13, 0));
                TongTienDaChi += 120;
                }
            if(TongTienDaChi > NuaTienBanDau) break;
            if(EXP1<300){
                M1 = moneylimit(poly(M1,1,-100));
                EXP1 = explimit(poly(EXP1, 0.90, 0));
                TongTienDaChi += 100;
            } else {
                M1 = moneylimit(poly(M1,1,-120));
                EXP1 = explimit(poly(EXP1, 0.90, 0));
                TongTienDaChi += 120;
            }
            if(TongTienDaChi > NuaTienBanDau) break;
        }
        HP1 = hplimit(poly(HP1, 0.83, 0));
        EXP1 = explimit(poly(EXP1, 1.17, 0));
    }

    if( SCP_gan_nhat(EXP1)<= EXP1){
        P2 = 1;
    } else {
        P2 = (EXP1/SCP_gan_nhat(EXP1) + 80)/123.00;
        //P2 = take_the_decimal(P1, 2);
    }

    // Road 3
    float P[]{32,47,28,79,100,50,22,83,64,11};
    int sum = 0;
    int lastdigit;

    while (E2 > 0) {
        int digit = E2 % 10;
        sum += digit;
        E2 /= 10;
    }
    lastdigit= sum%10;
    P3 = P[lastdigit]/100.00;

    // Result6
    if(AvgP(P1,P2,P3) == 1){
        EXP1 = explimit(ceil(EXP1*0.75));
    }
    else if(AvgP(P1,P2,P3) < 0.5){
        HP1 = hplimit(poly(HP1, 0.85, 0));
        EXP1 = explimit(ceil(EXP1*1.15));

    }
    else if(AvgP(P1,P2,P3) >= 0.5){
        HP1 = hplimit(poly(HP1, 0.90, 0));
        EXP1 = explimit(ceil(EXP1*1.2));
    }
    return HP1 + EXP1 + M1;
}





/////////////////////////////////////////////////////////////////////////////////////////////
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(UnvalidEvent(E3)) return -99;

    HP1 = hplimit(HP1);
    EXP1 = explimit(EXP1);
    HP2 = hplimit(HP2);
    EXP2 = explimit(EXP2);

    int mapTaxi[10][10];
    int num1 = 0;
    int num2 = 0;


    for(int i=0; i<10; ++i){
        for(int j=0; j<10; ++j){
            mapTaxi[i][j] = ((E3*j) + (i*2))*(i-j);

            if((mapTaxi[i][j]>0) && (mapTaxi[i][j]>E3*2)) num1++;
            if(mapTaxi[i][j]<0 && (mapTaxi[i][j]<(-E3))) num2++;
        }
    }

    //cout<<endl<<num1<<" "<<num2<<endl;
    int pos1,pos2;
    while(num1>=10){
        pos1= num1/10 + num1%10;
        num1 = pos1 ;
    }
    while(num2>=10){
        pos2= num2/10 + num2%10;
        num2 = pos2 ;
    }
    //cout<<endl<< num1<<" "<<num2<<endl;

    int mapSherlock[10][10];
    for(int m =0 ; m<10; m++){
        for(int n =0 ; n<10; n++){
            int max = mapTaxi[m][n];
            int a=m, b=n;

        while(m>0 && n>0){
            m--;
            n--;
            if(max < mapTaxi[m][n]) max = mapTaxi[m][n];
            if(m==0||n==0){
                break;
            }
        }
        m=a;n=b;

        while(m<9 && n<9){
            n++;
            m++;
            if(max < mapTaxi[m][n]) max = mapTaxi[m][n];
            if(n==9||m==9){
                break;
            }
        }
        m=a;n=b;

        while(m>0 && n<9){
            m--;
            n++;
            if(max < mapTaxi[m][n]) max = mapTaxi[m][n];
            if(m==0||n==9){
                break;
            }
        }
        m=a;n=b;

        while(m<9 && n>0){
            m++;
            n--;
            if(max < mapTaxi[m][n]) max = mapTaxi[m][n];
            if(m==9||n==0){
                break;
            }
        }
        m=a;n=b;
        mapSherlock[n][m] = max;
        }
    }

    /*for(int i = 0; i<10; i++){
        for(int j= 0; j<10; j++){
            cout<< mapTaxi[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 0; i<10; i++){
        for(int j= 0; j<10; j++){
            cout<< mapSherlock[j][i]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;*/
    
    int result;
    if(abs(mapTaxi[pos1][pos2]) > mapSherlock[pos2][pos1]){
        HP1= hplimit(poly(HP1,0.9,0));
        HP2= hplimit(poly(HP2,0.9,0));
        EXP1= explimit(poly(EXP1,0.88,0));
        EXP2= explimit(poly(EXP2,0.88,0));
        result = mapTaxi[pos1][pos2];
    } 
    else if(abs(mapTaxi[pos1][pos2]) <= mapSherlock[pos2][pos1]){
        HP1= hplimit(poly(HP1,1.1,0));
        HP2= hplimit(poly(HP2,1.1,0));
        EXP1= explimit(poly(EXP1,1.12,0));
        EXP2= explimit(poly(EXP2,1.12,0));
        result = mapSherlock[pos2][pos1];
    }
    return result;
}




/////////////////////////////////////////////////////////////////////////////////////////////
// Task 4
int checkPassword(const char * s, const char * email) {
    string Email(email);

    if(Email.find('@') >= strlen(email)) return -99; 

    string se = Email.substr(0, Email.find('@'));

    int length = strlen(s);
    if (length < 8) return -1;
    if (length > 20) return -2;

    const char* found = strstr(s, se.c_str());
    int sei = found - s;
    if (found != 0) return -(300 + sei);

    for (int i = 0; i < length - 2; ++i) {
        int sci = i;
        if (s[i] == s[i + 1] && s[i] == s[i + 2]) return -(400 + sci);
    }

    bool hasSpecialCharacters = false;
    for (int i = 0; i < length; ++i) {
        char c = s[i];
        if (!isalnum(c) && c == '@' || c == '#' || c == '%' || c == '$' || c == '!')
            hasSpecialCharacters = true;
    }
    if (!hasSpecialCharacters)
        return -5;
    
    for (int i = 0; i < length; ++i) {
        char c = s[i];
        if (!isalnum(c) && c != '@' && c != '#' && c != '%' && c != '$' && c != '!')
            return i;
    }

    return -10;
}




/////////////////////////////////////////////////////////////////////////////////////////////
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string arr_pwds2[num_pwds];
    for(int i = 0; i < num_pwds; i++){
        arr_pwds2[i] = arr_pwds[i];
    }

    int max_count = 0, max_length = 0, pos_First = -1;
    
    for (int i = 0; i < num_pwds; ++i) {
        int countFrequency = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (arr_pwds2[i] == arr_pwds2[j])
                countFrequency++;
        }
        if (countFrequency > max_count || (countFrequency == max_count && arr_pwds2[i].length() > max_length)) {
            max_count = countFrequency;
            max_length = arr_pwds2[i].length();
            pos_First = i;
        }
    }

    if(pos_First != -1) return pos_First;
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////