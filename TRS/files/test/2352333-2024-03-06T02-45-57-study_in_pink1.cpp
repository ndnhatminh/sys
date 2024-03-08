#include "study_in_pink1.h"

int find_near_square(int &exp1);

void food_and_beverage(int &hp1, int &m1);

void transport(int &exp1, int &m1);

void help_homeless(int &exp1, int &m1);


bool checkword(const char *s);
bool next_to_char(const char *s);
bool special_char(const char *s);



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
//task2 test case







// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {

    int D;
    if(e1>=0 && e1<=3) {
        switch (e1) {
            case 0:
                exp2 = exp2 + 29;
                break;
            case 1:
                exp2 = exp2 + 45;
                break;
            case 2:
                exp2 = exp2 + 75;
                break;
            case 3:
                exp2 = exp2 + 149;
                break;
            default:
                break;
        }
        D = e1 * 3 + exp1 * 7;

        if (D % 2 == 0) {
            exp1 = exp1 + D / 200; // Gán giá trị vào exp1
        } else {
            exp1 = exp1 - D / 100; // Gán giá trị vào exp1
        }
    }else if(e1>=4 && e1<=99)
    {
    if(e1<=19) exp2=exp2+(e1/4)+19;
    else if(e1>=20 && e1<=49 ) exp2=ceil(exp2 +(double)e1/9+21);
    else if(e1>=50 && e1<=65) exp2=ceil(exp2 + (double)e1/16+17);
    else if(e1>=66 && e1<= 79)
        {
            exp2=ceil(exp2+(double)e1/4+19);
            if (exp2>200) exp2=ceil(exp2 + (double) e1/9+21);
        }
    else if(e1>=80 && e1<=99)
        {
        exp2=ceil(exp2+(double)13*e1/36+40);
        if(exp2>400)
            {
            exp2=ceil(exp2+(double)e1/16+17);
            exp2= ceil((double)exp2*1.15);
            }
        }
    exp1=ceil(exp1-e1);
}
    if(exp1<0) exp1=0;
    if(exp2<0) exp2=0;
    if(exp1>600) exp1=600;
    if(exp2>600) exp2=600;
    return exp1 + exp2;
}


// Task 2
int traceLuggage (int & HP1, int & EXP1, int & M1, int E2) {
    if(HP1>666) HP1=666;
    if(EXP1>600) EXP1=600;
    if(M1>3000) M1=3000;
    if(E2>99) E2=99;

    if(HP1<0) HP1=0;
    if(EXP1<0) EXP1=0;
    if(M1<0) M1=0;
    if(E2<0) E2=0;
    int k=0;
    double p1,p2;
    int half_money= ceil((double)M1/2);
    int s= find_near_square(EXP1);
    if(EXP1> s) p1=1;
    else p1= ((double)EXP1/s +80)/123;

if(E2%2!=0)
{
    while(M1>half_money) {

        food_and_beverage(HP1, M1);
        if(M1<=0)
        {
            M1=0;
            break;
        }
        if(M1<half_money)  break;

        transport(EXP1, M1);
        if(M1<=0)
        {
            M1=0;
            break;
        }
        if(M1<half_money) break;
        help_homeless(EXP1, M1);
        if(M1<=0)
        {
            M1=0;
            break;
        }
        if(M1<half_money) break;
    }
HP1=ceil((double)HP1*0.83);
EXP1=ceil((double)EXP1*1.17);
    if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
}else {
    while (k < 1) {
        food_and_beverage(HP1, M1);
        if (M1 <= 0) {
            M1 = 0;
            break;
        }
        transport(EXP1, M1);
        if (M1 <= 0) {
            M1 = 0;
            break;
        }
        help_homeless(EXP1, M1);
        if (M1 <= 0) {
            M1 = 0;
            break;
        }
        k++;
    }
    HP1=ceil((double)HP1*0.83);
    EXP1=ceil((double)EXP1*1.17);

}
    if(EXP1> s) p2=1;
    else p2=((double)EXP1/s +80)/123;
    int i;
    int p3[10]={32,47,28,79,100,50,22,83,64,11};
    if(E2>=10)
    {
        i=(E2%10+E2/10)%10;
    }else i=E2;
    if(p1*100==100 && p2*100==100 && p3[i]==100)
    {
    EXP1= ceil((double)EXP1*0.75);
    }else
        {
        double avg=(p1*100+p2*100+p3[i])/3;
            if(avg<50)
            {
                HP1=ceil((double)HP1*0.85);
                EXP1=ceil((double)EXP1*1.15);
            }else
            {
                HP1= ceil((double)HP1*0.9);
                EXP1= ceil((double)EXP1*1.2);
            }
        }
    if(HP1>666) HP1=666;
    if(EXP1>600) EXP1=600;
    if(M1>3000) M1=3000;
    if(E2>99) E2=99;

    if(HP1<0) HP1=0;
    if(EXP1<0) EXP1=0;
    if(M1<0) M1=0;
    if(E2<0) E2=0;

    return HP1 + EXP1 + M1;
}

void food_and_beverage(int &hp1, int &m1)
        {
            if (hp1<200)
            {
                hp1=ceil((double)hp1*1.3);
                m1=m1-150;
            }else
            {
                hp1=ceil((double)hp1*1.1);
                if(hp1>666) hp1=666;
                if(hp1<0) hp1=0;
                m1=m1-70;
            }
        }

void help_homeless(int &exp1, int &m1) {
    if (exp1<300)m1-=100;
    else m1-=120;
    exp1= ceil((double )exp1*0.9);
}

void transport(int &exp1, int &m1) {
    if(exp1<400) m1-=200;
    else m1-=120;
    exp1= ceil((double )exp1*1.13);
    if(exp1>600) exp1=600;
    if(exp1<0) exp1=0;
}


int find_near_square(int &exp1)
{
    int a,b;
    a= sqrt(exp1);
    b= sqrt(exp1)+1;
    if (exp1- pow(a,2)> pow(b,2)-exp1) return pow(b,2);
    else if (exp1 - pow(a, 2) < pow(b, 2) -exp1) {
        return pow(a,2);
    } else if (exp1 == pow(a, 2)) return pow(a,2);
    return 0;
}


// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    int i,j;
    int a[10][10];
//taxi's score
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            a[i][j]=(E3*j+2*i)*(i-j);
        }
    }


//meeting place
int m=0,n=0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(a[i][j]>E3*2) m++;
            if(a[i][j]<-E3) n++;
        }
    }
    while(m>=10)
    {
        m=m/10+m%10;
    }
    while(n>=10) {
        n = n / 10 + n % 10;
    }
//find the largest LEFT
    int maxScoreLeft = 0;
    int row = m, col = n;
    while (row < 10 && col >= 0) {
        maxScoreLeft = max(maxScoreLeft, a[row][col]);
        row++;
        col--;
    }
    row = m, col = n;
    while(row<=0 && col<10)
    {
        maxScoreLeft= max(maxScoreLeft,a[row][col]);
        row--;
        col++;
    }


//find the largest RIGHT
    int maxScoreRight = a[m][n];
     row = m, col = n;

    while (row <10 && col < 10) {
        maxScoreRight = max(maxScoreRight, a[row][col]);
        row++;
        col++;
    }
    row = m, col = n;
    while (row >=0 && col >=0) {
        maxScoreRight = max(maxScoreRight, a[row][col]);
        row--;
        col--;
    }
    //final result
int LeftRightLargest;
    LeftRightLargest=max(maxScoreRight,maxScoreLeft);

        if(abs(a[m][n])>LeftRightLargest)
        {
            EXP1= ceil((double)EXP1*0.88);
            HP1= ceil((double)HP1*0.9);
            EXP2= ceil((double)EXP2*0.88);
            HP2= ceil((double)HP2*0.9);
            return a[m][n];
        } else
        {
            EXP1= ceil((double)EXP1*1.12);
            HP1= ceil((double)HP1*1.1);
            EXP2= ceil((double)EXP2*1.12);
            HP2= ceil((double)HP2*1.1);
            return LeftRightLargest;
        }


}




// Task 4
int checkPassword(const char * s, const char * email) {
 char se[100] ;
int length_email=strlen(email);
int length_s= strlen(s);
int i;
    for(i=0; i<length_email;i++)
    {
        if(email[i] == '@') break;
        else se[i]=email[i];
    }
    se[i]='\0';
    const char* found = strstr(s, se);
  if(length_s<=20 && length_s>=8 && checkword(s)== true && strstr(s,se)== nullptr && next_to_char(s)== true &&
  special_char(s)==true) return  -10;
if(length_s<8) return -1;
if(length_s>20) return -2;

if(strstr(s,se)!= nullptr)
{

    return -300-(found-s);
}

if(next_to_char(s)==false)
{
    for(int i=0;s[i] != '\0'&& s[i+1] != '\0';i++)
    {
        if(s[i]==s[i+1]) return -400-i;
    }
}
if(special_char(s)==false) return -5;

    return 0;

}

bool checkword(const char *s) {

    const char valid[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@#%$!";
    for (int i = 0; s[i] != '\0'; i++) {
        bool found = false;
        for (int j = 0; valid[j] != '\0'; j++) {
            if (s[i] == valid[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}
bool next_to_char(const char *s)
{
    for(int i=0;s[i] != '\0'&& s[i+1] != '\0';i++)
    {
        if(s[i]==s[i+1]) return false;
    }
    return true;
}
bool special_char(const char *s)
{
    const char valid[]="@#%$!";
    for(int i=0;s[i] != '\0';i++ )
    {
        for(int j=0;valid[j] !='\0';j++)
        {
            if(s[i]== valid[j]) return true;

        }
    }
    return false;
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int count_time[30];
    int count_char[200];
    for(int i=0; i<num_pwds;i++) {
        count_time[i] = 0;
        for (int j = 0; j < num_pwds; j++) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) count_time[i]++;
        }
    }
    for (int i = 0; i <num_pwds ; i++) {
        count_char[i]= strlen(arr_pwds[i]);
    }

    const char* a;
    int max_time=0;
    int max_char=0;
    int k=0;
    for(int i=0; i<num_pwds;i++)
    {
        //truong hop chi co 1 pass lap nhieu lan nhat
        if (count_time[i]>max_time) {
            max_time = count_time[i];
            max_char =count_char[i];
            k=i;
        }
            // truong hop co cac pass lap bang nhau
        else if(count_time[i]==max_time)
        {
            if(count_char[i]>max_char)
            {
               max_char = count_char[i];
                k=i;
            }
        }
    }

    return k;
}





////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////