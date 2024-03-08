#include "study_in_pink1.h"

bool readFile(const string &filename,int &HP1,int &HP2,int &EXP1,int &EXP2,int &M1,int &M2,int &E1,int &E2,int &E3)
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
// Task 1

// Giới hạn chỉ số
void ktMau(int &HP1, int &HP2)
{
HP1= (HP1 > 666) ? 666 : ((HP1 < 0) ? 0 : HP1);
HP2= (HP2 > 666) ? 666 : ((HP2 < 0) ? 0 : HP2);
}

void ktTien(int &M1, int &M2)
{
M1= (M1 > 3000) ? 3000 : ((M1 < 0) ? 0 : M1);
M2= (M2 > 3000) ? 3000 : ((M2 < 0) ? 0 : M2);
}
void ktEX(int &EXP1, int &EXP2)
{
EXP1= (EXP1 > 600) ? 600 : ((EXP1 < 0) ? 0 : EXP1);
EXP2= (EXP2 > 600) ? 600 : ((EXP2 < 0) ? 0 : EXP2);
}
//TH1
void firstMeet_TH1(int &ex1, int &ex2, int e1)
{
    if(e1== 0)
        ex2=ex2+ 29;
    else if(e1== 1)
        ex2=ex2+ 45;
    else if(e1== 2)
        ex2=ex2+ 75;
    else
        ex2=ex2+29+45+75; 

    int K=e1*3 + ex1*7;
    if(K%2== 0)
    ex1 = int(ex1 + (K/200.0) + 0.999); 
    else
    ex1 = int(ex1 - (K/100.0) + 0.999);
    ktEX(ex1,ex2);
}
//TH2
void firstMeet_TH2(int &exp1, int &exp2, int e1)
{
    if(e1>= 4 && e1<= 19)
     exp2= int(exp2 + (e1/4.0 + 19) + 0.999);
    else if(e1>= 20 && e1<= 49)
     exp2= int(exp2 + (e1/9.0 + 21) + 0.999);
    else if(e1>= 50 && e1<= 65)
     exp2= int(exp2 + (e1/16.0 + 17) + 0.999);
    else if(e1>= 66 && e1<= 79)
    {
     exp2= int(exp2 + (e1/4.0 + 19) + 0.999);
     if(exp2>200)
        exp2= int(exp2 + (e1/9.0 + 21) + 0.999);
    }
    else
    {
     exp2= int(exp2 + (e1/4.0 + 19) + 0.999);
     exp2= int(exp2 + (e1/9.0 + 21) + 0.999);
      if (exp2>400)
     {
        exp2= int(exp2 + (e1/16.0 + 17) + 0.999);
         exp2= int(exp2*1.15 + 0.999);
     }
    }

    exp1=exp1- e1;
    ktEX(exp1,exp2);
}

int firstMeet(int &exp1, int &exp2, int e1)
{
    // TODO: Complete this function
    if(e1<= 3 && e1>= 0)
     firstMeet_TH1(exp1,exp2,e1);
    else if(e1>= 4 && e1<= 99)
     firstMeet_TH2(exp1,exp2,e1);
    else
     return -99;
    return exp1 + exp2;
}

// Task 2
// Số chính phương gần nhất
double traceLuggage_cd1(int EXP1)
{
    int S=round(sqrt(EXP1)) * round(sqrt(EXP1));
    if(EXP1>= S)
        return 100;
    else
        return ((EXP1/S + 80)/123.0) * 100;
}
// Các sự kiện cđ2
double traceLuggage_cd2(int &HP1, int &EXP1, int &M1, int E2)
{
    double nuaM = M1*0.5;
    while(true)
    {
        // Sự kiện 1
        if(HP1< 200)
        {
            HP1= int(HP1*1.3 + 0.999);
            M1=M1- 150;
        }
        else if(HP1>= 200)
        {
            HP1= int(HP1*1.1 + 0.999);
            M1=M1- 70;
        }
        ktMau(HP1,HP1); 
        ktTien(M1,M1);    
        if(E2%2== 1 && M1< nuaM)
        {
            EXP1 = int(EXP1*1.17 + 0.999);
            HP1 = int(HP1*0.83 + 0.999);
            ktEX(EXP1,EXP1); 
            ktMau(HP1,HP1);    
            break;
        }
        else if(E2%2== 0 && M1== 0)
        {
            EXP1= int(EXP1*1.17 + 0.999);
            HP1= int(HP1*0.83 + 0.999);
            ktEX(EXP1,EXP1); 
            ktMau(HP1,HP1);  
            break;
        }

        // Sự kiện 2
        if(EXP1< 400)
            M1=M1- 200;
        else if(EXP1 >= 400)
            M1=M1- 120;
        EXP1= int(EXP1*1.13 + 0.999);
        ktEX(EXP1,EXP1);
        ktTien(M1,M1);  
        if(E2%2== 1 && M1< nuaM)
        {
            EXP1= int(EXP1*1.17 + 0.999);
            HP1= int(HP1*0.83 + 0.999);
            ktEX(EXP1,EXP1); 
            ktMau(HP1,HP1);  
            break;
        }
        else if(E2%2== 0 && M1== 0)
        {
            EXP1= int(EXP1*1.17 + 0.999);
            HP1= int(HP1*0.83 + 0.999);
            ktEX(EXP1,EXP1); 
            ktMau(HP1,HP1);  
            break;
        }

        // Sự kiện 3
        if(EXP1< 300)
            M1=M1- 100;
        else if(EXP1>= 300)
            M1=M1- 120;
        EXP1 = int(EXP1*0.9 + 0.999);
        ktEX(EXP1,EXP1); 
        ktTien(M1,M1);    
        if(E2%2== 1 && M1<= nuaM)
        {
            EXP1= int(EXP1*1.17 + 0.999);
            HP1= int(HP1*0.83 + 0.999);
            ktEX(EXP1,EXP1); 
            ktMau(HP1,HP1);  
            break;
        }
        else if(E2%2== 0)
        {
            EXP1= int(EXP1*1.17 + 0.999);
            HP1= int(HP1*0.83 + 0.999);
            ktMau(HP1,HP1); 
            ktEX(EXP1,EXP1);
            break;
        }
    }

    return traceLuggage_cd1(EXP1);
}
// cđ 3
double traceLuggage_cd3(int E2)
{
    int P[10]= {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i;
    if(E2<=9)
        i= E2;
    else
        i= (E2/10 + E2%10)%10;
    return P[i];
}

int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if(E2< 0 || E2> 99)
        return -99;
    double P1 = traceLuggage_cd1(EXP1);
    double P2 = traceLuggage_cd2(HP1, EXP1, M1, E2);
    double P3 = traceLuggage_cd3(E2);

    if(P1== 100 && P2== 100 && P3== 100)
        EXP1= int(EXP1*0.75 + 0.999);
    else
    {
        double P=(P1 + P2 + P3)/3;
        if(P< 50)
        {
            HP1= int(HP1*0.85 + 0.999);
            EXP1= int(EXP1*1.15 + 0.999);
        }
        else
        {
            HP1= int(HP1*0.9 + 0.999);
            EXP1= int(EXP1*1.2 + 0.999);
        }
    }
    ktEX(EXP1,EXP1);
    ktMau(HP1,HP1); 

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if (E3< 0 || E3> 99)
        return -99;
    int taxi[10][10] = {0};
    int sw[10][10] = {0};

    for(int i= 0; i< 10; i++)
    {
        for(int j= 0; j< 10; j++)
        {
            taxi[i][j] = ((E3*j) + (i*2))* (i-j); // Điểm taxi
        }
    }
    // Điểm của She và Was
    for(int i= 0; i< 10; i++)
    {
        for(int j= 0; j< 10; j++)
        {
            
            int maxct = taxi[i][j];
            for(int k= 0; k<min(i, j); k++)
            {
                maxct = maxct>taxi[i - k][j - k] ? maxct : taxi[i - k][j - k]; // GTLN đường chéo trái

            }
            
            int maxcp = taxi[i][j];
            for(int k= 0; k<min(10 - i, j); k++)
            {
                maxcp = maxcp>taxi[i + k][j - k] ? maxcp : taxi[i + k][j - k]; // GTLN đường chéo phải
            }
            
            sw[i][j] = maxct>maxcp ? maxct : maxcp;
            sw[i][j] = abs(sw[i][j]);
        }
    }
    // Tìm vị trí gặp nhau
    int h = 0, c = 0;
    for(int i= 0; i< 10; i++)
    {
        for(int j= 0; j< 10; j++)
        {
            if(taxi[i][j]>E3*2)
                h++;
            if(taxi[i][j]<-E3)
                c++;
        }
    }
    while(h>= 10 || c>= 10)
    {
        if(h>= 10)
        {
            h = h/10 + h%10;
        }
        if(c>= 10)
        {
            c = c/10 + c%10;
        }
    }
    // Tính điểm cuối cùng
    int dmax;
    // Không đuổi kịp
    if(abs(taxi[h][c])> sw[h][c])
    {
        EXP1= int(EXP1*0.88 + 0.999);
        HP1= int(HP1*0.9 + 0.999);
        EXP2= (EXP2*0.88 + 0.999);
        HP2= (HP2*0.9 + 0.999);
        dmax= taxi[h][c];
    }
    // Đuổi kịp
    else
    {
        EXP1= int(EXP1*1.12 + 0.999);
        HP1= int(HP1*1.1 + 0.999);
        EXP2= (EXP2*1.12 + 0.999);
        HP2= int(HP2*1.1 + 0.999);
        dmax= sw[h][c];
    }
    ktEX(EXP1,EXP2); 
    ktMau(HP1,HP2);    
    return dmax;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    string password(s);
    string userEmail(email);
    string se = userEmail.substr(0, userEmail.find('@'));

    
    if(password.length()< 8)
        return -1;
    if(password.length()> 20)
        return -2;
    if(password.find(se)!= std::string::npos)
        return -(300 + password.find(se));
    for(int i= 0; i< password.length() - 2; i++)
    {
        if(password[i] == password[i + 1] && password[i + 1] == password[i + 2])
            return -(400 + i);
    }
    string db = "@#%$!";
    bool ktdb = false;
    for(char c: password)
    {
        if(db.find(c) != std::string::npos)
        {
            ktdb = true;
            break;
        }
    }
    if(!ktdb)
        return -5;

    for(char c: password)
    {
        if(!std::isdigit(c) && !std::isalpha(c) && db.find(c) == std::string::npos)
            return password.find(c);
    }
    return -10;
}

// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int dem= 0, dai= 0, vtdau= 0;
    for(int i= 0; i< num_pwds; ++i)
    {
        int count= 0, length= strlen(arr_pwds[i]);
        for(int j= 0; j< num_pwds; ++j)
        {
            if(strcmp(arr_pwds[i], arr_pwds[j])== 0)
            {
                count++;
            }
        }
        if(count> dem || (count== dem && length > dai))
        {
            dem= count;
            dai= length;
            vtdau= i;
        }
    }
    return vtdau;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////