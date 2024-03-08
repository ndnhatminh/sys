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
int limitexp(int exp){
    if (exp > 600){
        exp = 600;
    } else if (exp < 0){
        exp = 0;
    }
    return exp;

}
int duongcheolonnhat(int array[10][10] ,int a, int b){
    int solonnhat = -999999;
    int c, d, e ,f;
    c=b;
    d=b;
    e=b;
    f=b;
    
    for (int g = a; g>=0 ; g+=-1){
            if(c>=0){
                if (array[g][c] > solonnhat){
                solonnhat = array[g][c];
            }
            c+=-1;
            } else {
                break;
            }

    }
    for (int h =  a; h>=0 ; h+=-1){
            if(d<10){
                if (array[h][d] > solonnhat){
                solonnhat = array[h][d];
            }
            d+=1;
            } else {
                break;
            }

    }
   for (int i = a; i<10 ; i+=1){
            if(e>=0){
                if (array[i][e] > solonnhat){
                solonnhat = array[i][e];
               
            }
            e+=-1;
            }  else {
                break;
            }

    }
    for (int j = a; j<10 ; j+=1){
            if(f<10){
                if (array[j][f] > solonnhat){
                solonnhat = array[j][f];
                
            }
            f+=1;
            }   else {
                break;
            }

    }
    return solonnhat;

}
double sochinhphuonggannhat(int a){
    
    int x=1;
    int y=2;
    while((y*y)<a){
        x+=1;
        y+=1;
    }if((a-x*x)<(y*y)-a)
{
    return x*x;
}else return y*y;
}
int expchange(int  exp, int expression) {
    if (expression > 0){
    exp +=  exp * expression / 100 + (exp * expression % 100 != 0);
    } else {
    exp -= floor(exp * -expression/100);
    }
    if (exp > 600){
        exp = 600;
    } else if (exp <= 0){
        exp = 0;
    }
    return exp;
}
int healthchange(int health, int expression) {
    if (expression > 0){
    health +=  health * expression / 100 + (health * expression % 100 != 0);
    } else {
    health -= floor(health * -expression/100);
    }
    if (health > 666){
        health = 666;
    } else if (health < 0){
        health = 0;
    }
    return health;
}
int moneychange(int money, int expression) {
    money += expression;
    money = ceil(money);
    if (money < 0) {
        money = 0;
    }
    if (money > 3000){
        money = 3000;
    }
    return money;
}
int limithp(int health){
    if (health > 666){
        health = 666;
    } else if (health < 0){
        health = 0;
    }
    return health;
}
int limitmoney(int money){
    if (money < 0) {
        money = 0;
    }
    if (money > 3000){
        money = 3000;
    }
    return money;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1<0 or e1>99){
        return -99;
    }
    if (e1<4 and exp1>0){
    switch(e1)
    {
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
        exp2 += 29 + 45 + 75;
        break;
    }
    exp2 = limitexp(exp2);
    int D = e1*3 + exp1 * 7;
    if (D%2==0){
        exp1 += ceil((double)D/200);
    } else {
        exp1 -= floor((double)D/100);
    }
    exp1 = limitexp(exp1);

    return exp1 + exp2;   
} else {
    if (e1 <= 19 and e1 >= 4){
        exp2 += ceil(((double)e1/4)+19);
    } else if (e1<=49 and e1 >= 20){
        exp2 += ceil(((double)e1/9)+21);
    } else if (e1<= 65 and e1>=50){
        exp2 += ceil(((double)e1/16)+17);
    } else if (e1<=79 and e1>=66){
        exp2 += ceil(((double)e1/4)+19);
        exp2 = limitexp(exp2);
        if (exp2>200){
            exp2 += ceil((double)e1/9 + 21);
        }
    } else if (e1<=99 and e1>=80){
        exp2 += ceil(((double)e1/4)+19);
        exp2 += ceil(((double)e1/9)+21);
        exp2 = limitexp(exp2);
        if (exp2>400){
        exp2 += ceil((double)e1/16 + 17);
        exp2 = limitexp(exp2);
        exp2 = expchange(exp2, 15);
        }
    }
    exp2 = limitexp(exp2);
    exp1 += -e1;
    exp1 = limitexp(exp1);
     return exp1 + exp2;
}
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2<0 or E2>99){
        return -99;
    }
    
    double S;
    double a = M1/2;
    double exp10 = (double)EXP1;
    S = sochinhphuonggannhat(EXP1);
    double p1, p2, p3, p4;
    if (EXP1 >= S or EXP1 == 0){
        p1 = 1;
    } else {
        p1 = (exp10/S + 80)/123;
    }
    if (E2%2==1){
        int spent = 0;
        while(true){
           if (HP1 < 200) {
                HP1 = healthchange(HP1, 30);
                M1 = moneychange(M1, -150);
                spent += 150;
                if (spent > a){
                    break;
                }
            } else if(HP1 >= 200) {
                HP1 = healthchange(HP1, 10);
                M1 = moneychange(M1, -70);
                spent += 70;
                if (spent > a){
                    break;
                }
            }
            if (EXP1<400){
                M1 = moneychange(M1, -200);
                spent += 200;
                EXP1 = expchange(EXP1, 13);
                if (spent > a){
                    break;
                }
            } else if (EXP1>=400){
                M1 = moneychange(M1, -120);
                spent += 120;
                EXP1 = expchange(EXP1, 13);
                if (spent > a){
                    break;
                }
            }
            
            if (EXP1<300){
                spent += 100;
                M1 = moneychange(M1, -100);
                EXP1 = expchange(EXP1, -10);
                if (spent > a){
                    break;
                }
            } else if(EXP1>=300){
                spent += 120;
                M1 = moneychange(M1, -120);
                EXP1 = expchange(EXP1, -10);
                if (spent > a){
                    break;
                }
            }
            
        }
    } else if(E2%2==0) {
       if (HP1 < 200) {
                HP1 = healthchange(HP1, 30);
                M1 = moneychange(M1, -150);
                if (M1 == 0){
                    goto thoat;
                }
            } else if(HP1 >= 200) {
                HP1 = healthchange(HP1, 10);
                M1 = moneychange(M1, -70);
                if (M1 == 0){
                    goto thoat;
                }
            }
            if (EXP1<400){
                M1 = moneychange(M1, -200);

            } else if (EXP1>=400){
                M1 = moneychange(M1, -120);

            }
            EXP1 = expchange(EXP1, 13);
            if (M1 == 0){
                goto thoat;
            }
            if (EXP1<300){
                M1 = moneychange(M1, -100);
            } else if(EXP1>=300){
                M1 = moneychange(M1, -120);
            }
            EXP1 = expchange(EXP1, -10); 
    }
    thoat:
    EXP1 = expchange(EXP1, 17);
    HP1 =  healthchange(HP1, -17);


    int S1;
    S1 = sochinhphuonggannhat(EXP1);
    if (EXP1 >= S1 or EXP1 == 0){
        p2 = 1;
    } else {
        p2 = (((double)EXP1/S1)+80)/123;
    }
    double P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int b;
    if (E2<10){
        p3 = P[E2]/100;
    } else {
        int h = E2/10 + E2%10;
        p3 = P[(E2/10 + E2%10)%10]/100;
    }
    if (p1 == 1 and p2 == 1 and p3 == 1){
       EXP1 = expchange(EXP1, -25);
    }else{
        p4 = (p1 + p2 + p3)/3;
        if(p4>=0.5){
            HP1 = healthchange(HP1, -10);
            EXP1 = expchange(EXP1, 20);
        } else {
            HP1 = healthchange(HP1, -15);
            EXP1 = expchange(EXP1, 15);
        }
    }
    return HP1+EXP1+M1;
}
// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (E3<0 or E3>99){
        return -99;
    }
    int x =0, y = 0;
    int matran[10][10];
     for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matran[i][j] = ((E3*j)+(i*2))*(i-j);
            if (matran[i][j] > E3 * 2) {
               x += 1;
            } else if (matran[i][j] < -E3) {
                y += 1;
            }
        }
    }
    while (x>=10){
        x = x%10 + x/10;
    }
    while (y>=10){
        y = y%10 + y/10;
    }
    int diem = duongcheolonnhat(matran, x, y);
    if (abs(matran[x][y])>diem){
        EXP1 = expchange(EXP1, -12);
        HP1 = healthchange(HP1, -10);
        EXP2 = expchange(EXP2, -12);
        HP2 = healthchange(HP2, -10);\
    } else {
        EXP1 = expchange(EXP1, 12);
        HP1 = healthchange(HP1, 10);
        EXP2 = expchange(EXP2, 12);
        HP2 = healthchange(HP2, 10);
    }
    if (abs(matran[x][y])>diem){
        return matran[x][y];
    } else {
        return diem;
    }
}
// Task 4
int checkPassword(const char * s, const char * email) {
    string password = s;
    string email1 = email;
    int a = email1.find("@");
    string se = email1.substr(0,a);
    if (password.length() < 8){
        return -1;
    } else if(password.length()>20){
        return -2;
    }
    if(password.find(se)!=string::npos and se.compare(password.substr(password.find(se),se.length()))==0){
      return -(300+  password.find(se));
    }
    for (int i = 0; i<(password.length()-2);i++){
        if (password[i]==password[i+1] and password[i]==password[i+2]){
            return  -(400+i);
    }}
    if (password.find('@')==string::npos and password.find('!')==string::npos and password.find('$')==string::npos and password.find('%')==string::npos and password.find('#')==string::npos){
        return -5;
    }
    string kituhople = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@!$%#";
    for (int i = 0; i<password.length(); i++){
       a = 0;
       for(int j =0; j<kituhople.length(); j++){
           if (password[i]==kituhople[j]){
               break;
           } else {
               a+=1;
           }
       }
       if (a==kituhople.length()){
           return i;
       }
    }
    return -10;
}
//task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string password[num_pwds];
    int a = 0, b, c ;
    int map[num_pwds][3];
    for (int i = 0; i < num_pwds; i++) {
        password[i] = arr_pwds[i];
    }
    while(a<num_pwds){
    b=0;
    c=0;
    for (int i = 0; i < num_pwds; i++) {
        if (password[a].compare(password[i])==0){
            b+=1;
            if(b==1){
                if (i<a){
                    c=i;
                } else {
                    c=a;
                }
            }
        }
    }
    map[a][0] = b;
    map[a][1] = c;
    map[a][2] = password[a].length();
    a+=1;
    }
    
    int max = 0;
    int max1 = 0;
   
    for (int i = 0; i < num_pwds; i++) {
        if (map[i][0] > max){
            max = map[i][0];
        }
    }
    for (int i = 0; i < num_pwds; i++) {
        if (map[i][0] == max and map[i][2]>max1){
            max1 = map[i][2];
        }
    }
    int k = 0;
    for (k; k < num_pwds; k++) {
        if (map[k][0]==max and map[k][2]==max1){
            break;
        }
    }
    return map[k][1];   
}
//mong la khong bi thay goi random dinh ;-;
