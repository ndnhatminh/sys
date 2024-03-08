#include "study_in_pink1.h"
#define ROUND 0.99999
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

//inital
int setHP(int HP) {
    // HP = HP>666 ? 666:HP;
    // HP = HP<0 ? 0:HP;
    if(HP>666)
        return 666;
    if(HP<0)
        return 0;
    return HP;
}

int setEXP(int EXP) {
    if(EXP>600)
        return 600;
    if(EXP<0)
        return 0;
    return EXP;

}

int setM(int M) {
    if(M>3000)
        return 3000;
    if(M<0)
        return 0;
    return M;

}

//task 2
int checkPerfectSquare(int n) {
    int root = sqrt(n);
    if(root*root == n)
        return n;
    else
    {
        int fl = root*root;
        int ce = ceil(sqrt(n))*ceil(sqrt(n));
        return (n-fl)<(ce-n)?fl:ce;
    }
}

int counting(int n) {
    int de = n/10;
    int unit = n%10;
    return (de+unit)%10;
}

double upRoad02(int & HP1, int & EXP1) {
    HP1 = setHP(HP1*0.83 + ROUND);
    EXP1 = setEXP(EXP1*1.17 + ROUND);
    return road01(EXP1);
}

double road01(int exp1) {
    int S = checkPerfectSquare(exp1);
    if(exp1>=S)
        return 100;
    else
        return ((((exp1*1.0)/S)+80)/1.23);
}

double road02(int & HP1, int & EXP1, int & M1, int E2, int Max, int use){

    if(HP1<200) {
        HP1 = setHP(HP1*1.3 + ROUND);
        M1 = setM(M1-150 + ROUND);
        use += 150;
    }
    else {
        HP1 = setHP(HP1*1.1 + ROUND);
        M1 = setM(M1-70 + ROUND);
        use += 70;
    }
    if(M1 == 0 || ((use>Max)&&(E2%2==1)))
        return upRoad02(HP1, EXP1);

    int price = EXP1<400 ? 200:120;
    M1 = setM(M1 - price + ROUND);
    use += price;
    EXP1 = setEXP(EXP1*1.13 + ROUND);
    // if(!E2%2)
    // if(M1 == 0 || use>Max)
    if(M1 == 0 || ((use>Max)&&(E2%2==1)))
        return upRoad02(HP1, EXP1);


    int homeless = EXP1<300 ? 100:120;
    M1 = setM(M1 - homeless + ROUND);
    use += homeless;
    EXP1 = setEXP(EXP1*0.9 + ROUND);
    // if(!E2%2)
    // if(M1 == 0 || use>Max)
    if(M1 == 0 || ((use>Max)&&(E2%2==1)))
        return upRoad02(HP1, EXP1);

    if(E2%2==0)
        return upRoad02(HP1, EXP1);
    else {
        if(use<Max)
            return road02(HP1, EXP1, M1, E2, Max, use);
        else
            return upRoad02(HP1, EXP1);
    }
}

double road03(int E2) {
    int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2>=0 && E2<=9)
        return P[E2];
    else
        return P[counting(E2)];
}

//task 4
char * getSE(const char * mail) {
    char * mails = new char[strlen(mail)+1];
    strcpy(mails,mail);
    int len = strchr(mails,'@')-mails;
    char *SE = new char[len+1];
    strncpy(SE,mails,len);
    return SE;
}

int lenCheck(const char * s) {
    char * ss = new char[strlen(s)+1];
    strcpy(ss,s);
    int len = strlen(ss);
    //-1 lower, -2 longer, 0 correct
    if(len<8)
        return -1;
    else if(len>20)
        return -2;
    return 0;
}

int contain(const char * s, char * se) {
    char * ss = new char[strlen(s)+1];
    strcpy(ss,s);
    char * check = strstr(ss,se);
    if(check == NULL)
        return -1;
    else return -(300 + check - ss);
}

int doubleCheck(const char * s) {
    char * ss = new char[strlen(s)+1];
    strcpy(ss,s);
    int len = strlen(ss);
    for(int i=0;i < len-2;i++) {
        if(ss[i]==ss[i+1]&&ss[i]==ss[i+2])
            return -(400+i);
    }
    return -1;
}

int speCheck(const char *s) {
    char * ss = new char[strlen(s)+1];
    strcpy(ss,s);
    char k[] = "@#%$!";
    int len = strlen(ss);
    if(len == strcspn(ss,k))
        return -5;
    return 0;
}

int charCheck(const char * s) {
    char * ss = new char[strlen(s)+1];
    strcpy(ss,s);
    char strKey[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#%$!";
    if(strlen(ss)>strspn(ss,strKey))
        return strspn(ss,strKey);
    return -1;

}

bool astrcmp(char *s1, char *s2){
    int i=0;
    while(s1[i]!='\0')
    {
        if(s2[i]=='\0' || s1[i]!=s2[i])
            return 0;
        i++;
    }
    if(s2[i]=='\0')
        return 1;
    return 0;
}


// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    exp1 = exp1>600 ? 600:exp1;
    exp1 = exp1<0 ? 0:exp1;
    exp2 = exp2>600 ? 600:exp2;
    exp2 = exp2<0 ? 0:exp2;

    bool case1 = ((e1>=0)&&(e1<=3));
    bool case2 = ((e1>=4)&&(e1<=99));

    if(case1)
    {
        int point[4] = {29,45,75,149}; //Waston
        exp2 = setEXP(point[e1] + exp2);

        int D = e1*3 + exp1*7;
        int div[2] = {200,-100};
        exp1 = setEXP((D*1.0) / div[D%2] + ROUND + exp1); //Holmes
    }
    else if(case2)
    {
        bool cal1 = (e1<=19);
        bool cal2 = (e1<=49);
        bool cal3 = (e1<=65);
        bool cal4 = (e1<=79);

        { //Wastion
            if(cal1)
            {
                int point1 = ((e1*1.0)/4) + 19 + ROUND;
                exp2 = setEXP(point1 + exp2 + ROUND);
            }
            else if(cal2)
            {
                int point2 = ((e1*1.0)/9) + 21 + ROUND;
                // exp2 += point2;
                exp2 = setEXP(point2 + exp2 + ROUND);
            }
            else if(cal3)
            {
                int point3 = ((e1*1.0)/16) + 17 + ROUND;
                // exp2 += point3;
                exp2 = setEXP(point3 + exp2 + ROUND);
            }
            else if(cal4)
            {
                int point1 = ((e1*1.0)/4) + 19 + ROUND;
                int point2 = ((e1*1.0)/9) + 21 + ROUND;
                // exp2 += point1;
                exp2 = setEXP(point1 + exp2 + ROUND);
                if(exp2>200)
                    // exp2 += point2;
                   exp2 = setEXP(point2 + exp2 + ROUND);
            }
            else
            {
                int point1 = ((e1*1.0)/4) + 19 + ROUND;
                int point2 = ((e1*1.0)/9) + 21 + ROUND;
                int point3 = ((e1*1.0)/16) + 17 + ROUND;
                // exp2 += point1 + point2;
                exp2 = setEXP(point1 + exp2 + ROUND);
                exp2 = setEXP(point2 + exp2 + ROUND);
                if(exp2>400)
                {
                    // exp2 += point3;
                    exp2 = setEXP(point3 + exp2 + ROUND);
                    exp2 = setEXP(exp2*1.15 + ROUND);
                }
            }
        }

        exp1 = setEXP(exp1 + ROUND - e1); //Holmes
    }
    else
        return -99;
    
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2<0 || E2>99)
        return -99;
        
    EXP1 = EXP1>600 ? 600:EXP1;
    EXP1 = EXP1<0 ? 0:EXP1;
    HP1 = HP1>666 ? 666:HP1;
    HP1 = HP1<0 ? 0:HP1;
    M1 = M1>3000 ? 3000:M1;
    M1 = M1<0 ? 0:M1;

    double P1 = road01(EXP1);
    double P2 = road02(HP1, EXP1, M1, E2, M1/2, 0);
    double P3 = road03(E2);

    if(P1+P2+P3 == 300)
        EXP1 = setEXP(EXP1*0.75 + ROUND);
    else if((P1+P2+P3)/3 < 50) {
        HP1 = setHP(HP1*0.85 + ROUND);
        EXP1 = setEXP(EXP1*1.15 + ROUND);
    }
    else {
        HP1 = setHP(HP1*0.90 + ROUND);
        EXP1 = setEXP(EXP1*1.2 + ROUND);
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3>99 || E3<0)
        return -99;

    EXP1 = EXP1>600 ? 600:EXP1;
    EXP1 = EXP1<0 ? 0:EXP1;
    EXP2 = EXP2>600 ? 600:EXP2;
    EXP2 = EXP2<0 ? 0:EXP2;
    HP1 = HP1>666 ? 666:HP1;
    HP1 = HP1<0 ? 0:HP1;
    HP2 = HP2>666 ? 666:HP2;
    HP2 = HP2<0 ? 0:HP2;

    int Taxi[10][10];
    int CoI=0;
    int CoJ=0;
    int p=-99999;
    int tempI,tempJ;
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++) {
            Taxi[i][j]=((E3*j)+(i*2))*(i-j);
            if(Taxi[i][j] > E3*2)
                CoI++;
            else if(Taxi[i][j] < -E3)
                CoJ++;
        }

    int DesI, DesJ;
    DesI = ((CoI/10)+(CoI%10));
    DesJ = ((CoJ/10)+(CoJ%10));
    DesI = DesI>9 ? ((DesI/10)+(DesI%10)) : DesI;
    DesJ = DesJ>9 ? ((DesJ/10)+(DesJ%10)) : DesJ;

    // for(int i=0;i<10;i++){
    //     for(int j=0;j<10;j++)
    //         cout<<Taxi[i][j]<<" ";
    //     cout<<endl;
    // }

    // cout<<DesI<<" "<<DesJ<<endl;

    
        tempI = DesI;
        tempJ = DesJ;
        while(tempI>=0 && tempJ>=0)
        {
            p = max(p, Taxi[tempI][tempJ]);
            tempI--;
            tempJ--;
        }
        tempI = DesI;
        tempJ = DesJ;
        while(tempI>=0 && tempJ<10)
        {
            p = max(p, Taxi[tempI][tempJ]);
            tempI--;
            tempJ++;
        }
        tempI = DesI;
        tempJ = DesJ;
        while(tempI<10 && tempJ>=0)
        {
            p = max(p, Taxi[tempI][tempJ]);
            tempI++;
            tempJ--;
        }
        tempI = DesI;
        tempJ = DesJ;
        while(tempI<10 && tempJ<10)
        {
            p = max(p, Taxi[tempI][tempJ]);
            tempI++;
            tempJ++;
        }
    

    p = abs(p);
    // cout<<p<<" hi "<<endl;
    // cout<<Taxi[0][10]<<endl;
    // cout<<endl;
    if (p >= abs(Taxi[DesI][DesJ])){
        EXP1=setEXP(EXP1*1.12 + ROUND);
        EXP2=setEXP(EXP2*1.12 + ROUND);
        HP1=setHP(HP1*1.1 + ROUND);
        HP2=setHP(HP2*1.1 + ROUND);
        return p;
        // return 1;
    }
    else{
        EXP1=setEXP(EXP1*0.88 + ROUND);
        EXP2=setEXP(EXP2*0.88 + ROUND);
        HP1=setHP(HP1*0.9 + ROUND);
        HP2=setHP(HP2*0.9 + ROUND);
        return Taxi[DesI][DesJ];
        // return 0;
    }

    // return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function

    char *se = getSE(email);
    // cout<<"hi\n";

    int result = lenCheck(s);
    if(result != 0)
        return result;
    // cout<<"hi1\n";


    result = contain(s, se);
    if(result != -1)
        return result;
    // cout<<"hi2\n";


    result = doubleCheck(s);
    if(result != -1)
        return result;
    // cout<<"hi3\n";


    result = speCheck(s);
    if(result)
        return result;
    // cout<<"hi4\n";


    result = charCheck(s);
    if(result != -1)
        return result;
    // cout<<"hi5\n";


    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function

    int unique_num = 0;
    char * unique_pwds[30];
    int count[30];
    int index[30];

    for(int i=0;i<30;i++)
    {
        count[i]=-1;
        index[i]=-1;
    }

    for(int j=0;j<num_pwds;j++){
        bool isUnique = true;
        char *temp = new char[strlen(arr_pwds[j])+1];
        strcpy(temp, arr_pwds[j]);
        for(int i=0;i<unique_num;i++){
            if(astrcmp(unique_pwds[i],temp)){
                count[i]++;
                isUnique = false;
                break;
            }
        }
        if(isUnique){
            unique_pwds[unique_num]=temp;
            count[unique_num]=1;
            index[unique_num]=j;
            unique_num++;
        }
        // delete[] temp;
    }

    int maxi=0;
    for(int i=1;i<unique_num;i++){
        if(count[i]>count[maxi])
            maxi=i;
        if(count[i]==count[maxi] && strlen(unique_pwds[i])>strlen(unique_pwds[maxi]))
            maxi=i;
    }
    
    // for(int i=0;i<unique_num;i++){
    //     cout<<count[i]<<endl;
    // }
    // cout<<unique_num<<endl;
    // cout<<endl;
    return index[maxi];


    // return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////