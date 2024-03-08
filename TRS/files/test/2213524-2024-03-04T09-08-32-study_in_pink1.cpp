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
struct FCP{
    public:
    string name;
    int freq=0;
    FCP(){};
};
void check(int & HP1, int & HP2, int & EXP1, int & EXP2){
    HP1 = HP1>=666 ? 666 : HP1;
    HP2 = HP2>=666 ? 666 : HP2;
    HP1 = HP1<=0 ? 0 : HP1;
    HP2 = HP2<=0 ? 0 : HP2;
    EXP1 = EXP1>=600 ? 600 : EXP1;
    EXP2 = EXP2>=600 ? 600 : EXP2;
    EXP1 = EXP1<=0 ? 0 : EXP1;
    EXP2 = EXP2<=0 ? 0 : EXP2;
}
void CP(int& EXP1, double& p1){
    if(int(sqrt(EXP1)) == double(sqrt(EXP1))) p1=100;
    else {
        int S;
        int temp1 = int(sqrt(EXP1)), temp2 = temp1 + 1;
        if(min(EXP1-temp1*temp1,temp2*temp2-EXP1) == EXP1-temp1*temp1) S=temp1*temp1;
        else S=temp2*temp2;
        if(EXP1>=S) {p1=100;}
        else {p1=((double(EXP1)/S + 80)/123)*100;}
    }
    //cout<<p1<<"--------------";
}
void food(int&HP1, int&M1, int& sum){
    if(M1==0) return; 
    if(HP1 < 200) {HP1=ceilf(HP1*1.3); M1-=150; sum+=150;}
    else {HP1=ceilf(HP1*1.1); M1-=70; sum+=70;}
    HP1 = HP1>=666 ? 666 : HP1;
    M1= M1<=0 ? 0 : M1;
    //cout<<"HP1 after food: " <<HP1<<"--------"<<endl;
    //cout<<sum<<" ---------------\n";
}

void race(int&exp1, int&M1, int& sum){
    if(M1==0) return;
    if(exp1<400) {M1-=200; sum+=200;}
    else {M1-=120; sum+=120;}
    exp1=ceilf(exp1*1.13);
    exp1 = exp1 >=600 ? 600 : exp1;
    M1= M1<=0 ? 0 : M1;
    //cout<<"EXP1 after race: " <<exp1<<"--------"<<endl;
    //cout<<sum<<" ---------------\n";
}

void homeless(int&exp1, int&M1, int& sum){
    if(M1==0) return;
    if(exp1<300) {M1-=100; sum+=100;}
    else{ M1-=120; sum+=120;}
    exp1=ceilf(exp1*0.9);
    M1= M1<=0 ? 0 : M1;
    //cout<<"EXP1 after homeless: " <<exp1<<"--------"<<endl;
    //cout<<sum<<" ---------------\n";
}

int hehe(string se, const char* s){
    string kk(s);
    int index = kk.find(se);
    if(index!=string::npos) return index;
    return -1;
}
int left(int taxi[10][10],int i, int j){
    int sum=INT_MIN;
    while(i!=-0 && j!=-0) {i--; j--;}
    while(i!=10 && j!=10) {sum=max(sum,taxi[i][j]);i++; j++;}
    return sum;
}
int right(int taxi[10][10],int i, int j){
    int sum=INT_MIN;
    while(i!=-0 && j!=9) {i--; j++;}
    while(i!=10 && j!=0) {sum=max(sum,taxi[i][j]);i++; j--;}
    return sum;
}
int twoletter(const char* s){
    if(strlen(s)<2) return false;
    
    for(int i =1; i<strlen(s)-1;i++){
        if(s[i]==s[i+1] &&s[i-1]==s[i]) return i-1;
    }
    return -1;
}
bool specialletter(const char* s){
    int length = strlen(s);
    for(int i=0;i<length;i++) {if(s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') return 1;}
    return 0;
}
int shitletter(const char* s){
    int length = strlen(s);
    for(int i=0;i<length;i++) {
        if(s[i]=='@' || s[i]=='#' || s[i]=='%' || s[i]=='$' || s[i]=='!') continue;
        if(s[i]>=' ' && s[i] <='/' || s[i]>=':' && s[i]<='@' || s[i]>='[' && s[i]<='`' || s[i]>='{' && s[i]<='~') return i;
    }
    return -1;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    
    if(e1<0 || e1>99) return -99;
    exp1 = exp1>=600 ? 600 : exp1;
    exp2 = exp2>=600 ? 600 : exp2;
    exp1 = exp1<=0 ? 0 : exp1;
    exp2 = exp2<=0 ? 0 : exp2;
    if(e1<=3){
    switch (e1)
    {
        case 0: exp2+=29;   break;
        case 1: exp2+=45;   break;
        case 2: exp2+=75;   break;
        case 3: exp2+=149;  break;
    }
        exp2 = exp2 >=600 ? 600 : exp2;
        int D= e1*3 + exp1*7;
        if(D%2==0) exp1=ceilf(exp1+double(D)/200);
        else exp1=ceilf(exp1-double(D)/100);
    }
    else {
        if(e1>=4 && e1<=19)         exp2=ceilf(exp2 + double(e1)/4 + 19);
        else if(e1>=20 && e1<=49)   exp2=ceilf(exp2 + double(e1)/9 + 21);
        else if(e1>=50 && e1<=65)   exp2=ceilf(exp2 + double(e1)/16 + 17);
        else if(e1>=66 && e1<=79)  {
            exp2 =ceilf(exp2 + double(e1)/4 + 19); 
            if(exp2>200) exp2=ceilf(exp2 + double(e1)/9 + 21);
            }
        else if(e1>=80 && e1<=99)  {
            exp2=ceilf(exp2 + double(e1)/4 + 19); 
            exp2=ceilf(exp2 + double(e1)/9 + 21);
            if(exp2>400) {exp2=ceilf(exp2 + double(e1)/16 + 17); exp2=ceilf(exp2*1.15);}
        }
        exp1 -= e1;

    }
        exp1 = exp1 <=0 ? 0 : exp1;
        exp1 = exp1 >=600 ? 600 : exp1;
        exp2 = exp2 >=600 ? 600 : exp2;
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99) return -99;
    HP1 = HP1>=666 ? 666 : HP1;     HP1 = HP1<=0 ? 0 : HP1;
    EXP1 = EXP1>=600 ? 600 : EXP1;  EXP1 = EXP1<=0 ? 0 : EXP1;
    M1 = M1>=3000 ? 3000 : M1;  M1 = M1<=0 ? 0 : M1;
    double p1, p2, p3;
    int sum=0;
    // **********************************************    ROAD 1    **********************************************
    CP(EXP1,p1);
    // **********************************************    ROAD 2    **********************************************
    if(E2%2==0){
        food(HP1,M1,sum);       
        race(EXP1,M1,sum);
        homeless(EXP1,M1,sum);
    }
    else {
        int limit=M1/2;
        while(1){
            food(HP1,M1,sum);       if(sum>limit) break;
            race(EXP1,M1,sum);      if(sum>limit) break;
            homeless(EXP1,M1,sum);  if(sum>limit) break;
            
        }
    }
        HP1=ceilf(HP1*0.83);
        EXP1=ceilf(EXP1*1.17);
        EXP1 = EXP1 >=600 ? 600 : EXP1;
     //cout<<"EXP1 after road 2: "<<EXP1<<endl;
    // cout<<"HP1 after road 2: "<<HP1<<endl;
    CP(EXP1,p2);
    // **********************************************    ROAD 3    **********************************************
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2/10==0) p3=P[E2];
    else {
        int i = E2/10 + E2%10;
        i = i>=10 ? i%10 : i;
        p3 = P[i];
    }
    
    double avr;
    if(p1==100 && p2==100 && p3==100) {
    EXP1=ceilf(EXP1*0.75);
    return HP1 + EXP1 + M1;
    //traceLuggage(HP1,EXP1,M1,E2);
    }
        //cout<<p1<<"-----"<<p2<<"-----"<<p3<<endl;
        avr=(p1+p2+p3)/3;
        //cout<<avr<<endl;
        if(avr<50) {
            HP1=ceilf(HP1*0.85);
            EXP1=ceilf(EXP1*1.15);
        }
        else {
            
            HP1=ceilf(HP1*0.9);
            EXP1=ceilf(EXP1*1.2);
        }
        EXP1 = EXP1 >=600 ? 600 : EXP1;
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3<0 || E3>99) return -99;
    HP1 = HP1>=666 ? 666 : HP1;
    HP2 = HP2>=666 ? 666 : HP2;
    HP1 = HP1<=0 ? 0 : HP1;
    HP2 = HP2<=0 ? 0 : HP2;
    EXP1 = EXP1>=600 ? 600 : EXP1;
    EXP2 = EXP2>=600 ? 600 : EXP2;
    EXP1 = EXP1<=0 ? 0 : EXP1;
    EXP2 = EXP2<=0 ? 0 : EXP2;
    int taxi[10][10];
        int genus=0, minus=0,i,j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            taxi[i][j] = (E3 * j + i * 2) * (i - j);
            //cout << taxi[i][j] << " ";
            if(taxi[i][j]>E3*2)     genus++;
            if(taxi[i][j]<(0-E3))   minus++;
        }
        //cout << endl;
    }
    do {genus=genus/10 + genus%10;} while(genus>=10);
    do {minus=minus/10 + minus%10;} while(minus>=10);
    cout<<left(taxi,genus,minus)<<" "<<right(taxi,genus,minus)<<endl;
    int t=max(left(taxi,genus,minus), right(taxi,genus,minus));
    if(abs(taxi[genus][minus]) > t){
        HP1=ceilf(HP1*0.9);
        EXP1=ceilf(EXP1*0.88);
        HP2=ceilf(HP2*0.9);
        EXP2=ceilf(EXP2*0.88);
        return taxi[genus][minus];
    }
    else{
        HP1=ceilf(HP1*1.1);
        EXP1=ceilf(EXP1*1.12);
        HP2=ceilf(HP2*1.1);
        EXP2=ceilf(EXP2*1.12);
        EXP1 = EXP1 >=600 ? 600 : EXP1;
        EXP2 = EXP2 >=600 ? 600 : EXP2;
        HP1 = HP1 >=666 ? 666 : HP1;
        HP2 = HP2 >=666 ? 666 : HP2;
        return t;
    }

}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    string se;
    int length = strlen(s);
    int i = 0;
    while (email[i] != '@') {
        se += email[i];
        i++;
    }
    if(length<8) return -1;
    else if(length>20) return -2;
    if(!se.empty()) {if(hehe(se,s)!=-1) {return -(300+hehe(se,s));}}
    else return -300;
    if(twoletter(s)!=-1) return -(400+twoletter(s));
    if(!specialletter(s)) return -5;
    if(shitletter(s)!=-1) return shitletter(s);
    return -10;
}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    FCP* manage = new FCP[num_pwds];
    int count = 0;

    for (int i = 0; i < num_pwds; i++) {
        bool found = false;

        for (int j = 0; j <= count; j++) {
            if (strcmp(manage[j].name.c_str(), arr_pwds[i]) == 0) {
                manage[j].freq++;
                found = true;
                break;
            }
        }

        if (!found) {
            manage[count].name = arr_pwds[i];
            manage[count].freq = 1;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        for (int j = 0; j < count - 1; j++) {
            if (manage[j].freq < manage[j + 1].freq) {
                swap(manage[j], manage[j + 1]);
            }
        }
    }

    string t = manage[0].name;

    for (int i = 1; i < count; i++) {
        if (manage[i].freq != manage[i - 1].freq) {
            break;
        }

        if (manage[i].name.length() > t.length()) {
            t = manage[i].name;
        }
    }

    int result = -1;
    for (int i = 0; i < num_pwds; i++) {
        if (strcmp(arr_pwds[i], t.c_str()) == 0) {
            result = i;
            break;
        }
    }

    delete[] manage;
    return result;
}
//  ************************************ Author's code is Ha Thai Toan ************************************
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////