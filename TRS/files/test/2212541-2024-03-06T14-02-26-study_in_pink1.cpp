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
void checkEXP (int &EXP1, int &EXP2)
{
  if (EXP1 <= 0)
 EXP1 = 0;
 if (EXP2 <= 0)
 EXP2 = 0;
    if (EXP1 >= 600)
    EXP1=600;
    if (EXP2 >= 600)
    EXP2=600;
}
int findPSquare(int a)
{
    int b, c;
    b = floor(sqrt(a));
    c =
        (a - pow(b, 2)) < (pow((b + 1), 2) - a) ? pow(b, 2) : pow((b + 1), 2);
    return c;
}

int calculatorSum(int a)
{
    int sum = 0;
    sum += a % 10;
    sum += a / 10;
    int b = sum % 10;
    return b;
}

void check(int &HP1, int &EXP1, int &M1)
{
    if (HP1 < 0)
        HP1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (EXP1 < 0)
        EXP1 = 0;
    if (EXP1 > 600)
        EXP1 = 600;
    if (M1 < 0)
        M1 = 0;
    if (M1 > 3000)
        M1 = 3000;
}
void checktaxi(int &HP1, int &HP2, int &EXP1, int &EXP2){
    if (EXP1 <= 0)
    EXP1 = 0;
    if (EXP2 <= 0)
    EXP2 = 0;
    if (EXP1 >= 600)
    EXP1=600;
    if (EXP2 >= 600)
    EXP2=600;
    if (HP1 < 0)
        HP1 = 0;
    if (HP1 > 666)
        HP1 = 666;
    if (HP2 < 0)
        HP2 = 0;
    if (HP2 > 666)
        HP2 = 666;
}
int calculatorSumUntilHave1Number(int a){
    while (a>=10){
        int sum =0;
        int temp =a;
        while (temp>0){
            sum+=temp%10;
            temp/=10;
        }
        a=sum;
    }
    return a;
}
//! Task 1
int
firstMeet (int &EXP1, int &EXP2, int E1)
{
  checkEXP(EXP1, EXP2);
  if (E1 < 0 || E1 > 99)
 return -99;
  if (E1 >= 0 && E1 <= 3)
 {
   if (E1 == 0)
  EXP2 += 29;
   if (E1 == 1)
  EXP2 += 45;
   if (E1 == 2)
  EXP2 += 75;
   if (E1 == 3)
  EXP2 = EXP2 + 29 + 45 + 75;

   int D;
   D = E1 * 3 + EXP1 * 7;

   if (D % 2 == 0)
  EXP1 = ceil (EXP1 + D / 200.0);
   else
  EXP1 = ceil (EXP1 - D / 100.0);
 }
  if (E1 >= 4 && E1 <= 99)
 {
   if (E1 >= 4 && E1 <= 19)
  EXP2 = ceil (EXP2 + (E1 / 4.0 + 19));
   if (E1 >= 20 && E1 <= 49)
  EXP2 = ceil (EXP2 + (E1 / 9.0 + 21));
   if (E1 >= 50 && E1 <= 65)
  EXP2 = ceil (EXP2 + (E1 / 16.0 + 17));
   if (E1 >= 66 && E1 <= 79)
  {
    EXP2 = ceil (EXP2 + (E1 / 4.0 + 19));
    if (EXP2 > 200)
   EXP2 = ceil (EXP2 + (E1 / 9.0 + 21));
  }
   if (E1 >= 80 && E1 <= 99)
  {
    EXP2 = ceil (EXP2 + (E1 / 4.0 + 19));
    EXP2 = ceil (EXP2 + (E1 / 9.0 + 21));
    if (EXP2 > 400)
   {
     EXP2 = ceil (EXP2 + (E1 / 16.0 + 17));
     EXP2 = ceil (EXP2 + EXP2 * 0.15);
   }
  }
   EXP1 = EXP1 - E1;
 }
  checkEXP(EXP1, EXP2);
  return EXP1 + EXP2;
}
//! Task 2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    check(HP1, EXP1, M1);
    int totalMoney = M1;
    // TODO: Complete this function
    if (E2 > 99 || E2 < 0)
        return -99;
    // con duong 1
    float P1, P2, P3;
    int S = findPSquare(EXP1);
    if (EXP1 >= S)
        P1 = 100;
    else
        P1 = ((((EXP1 * 1.0 / 1) / S) + 80) / 123)*100;
    // con duong 2
    if ((E2 % 2) == 1)
    {
        while (1)
        {
            // su kien 1
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 13.0 / 10);
                M1 -= 150;

                if (M1 < (totalMoney / 2) || M1 <= 0)
                    break;
            }
            else
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 -= 70;

                if (M1 < (totalMoney / 2) || M1 <= 0)
                    break;
            }
            // su kien 2
            if (EXP1 < 400)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                M1 -= 200;

                if (M1 < (totalMoney / 2) || M1 <= 0)
                    break;
            }
            else
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                M1 -= 120;

                if (M1 < (totalMoney / 2) || M1 <= 0)
                    break;
            }
            // su kien 3
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 9.0 / 10);

                if (M1 < (totalMoney / 2) || M1 <= 0)
                    break;
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 9.0 / 10);

                if (M1 < (totalMoney / 2) || M1 <= 0)
                    break;
            }
        }
        HP1 = ceil(HP1 * 83.0 / 100);
        EXP1 = ceil(EXP1 * 117.0 / 100);
    }
    else
    {
        for (int i = 0; i < 1; i++)
        {
            // su kien 1
            if (HP1 < 200)
            {
                HP1 = ceil(HP1 * 13.0 / 10);
                M1 -= 150;

                if (M1 <= 0)
                    break;
            }
            else
            {
                HP1 = ceil(HP1 * 11.0 / 10);
                M1 -= 70;

                if (M1 <= 0)
                    break;
            }
            // su kien 2
            if (EXP1 < 400)
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                M1 -= 200;
                if (M1 <= 0)
                    break;
            }
            else
            {
                EXP1 = ceil(EXP1 * 113.0 / 100);
                M1 -= 120;
                if (M1 <= 0)
                    break;
            }
            // su kien 3
            if (EXP1 < 300)
            {
                M1 -= 100;
                EXP1 = ceil(EXP1 * 9.0 / 10);
                if (M1 <= 0)
                    break;
            }
            else
            {
                M1 -= 120;
                EXP1 = ceil(EXP1 * 9.0 / 10);
                if (M1 <= 0)
                    break;
            }
        }
        HP1 = ceil(HP1 * 83.0 / 100);
        EXP1 = ceil(EXP1 * 117.0 / 100);
    }
    int H = findPSquare(EXP1);
    if (EXP1 >= H)
        P2 = 100;
    else
        P2 = ((((EXP1 * 1.0 / 1) / S) + 80) / 123)*100;
    // con duong 3
    int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    int i = 0;
    if (E2 / 10 == 0)
        i = E2;
    else
    {
        i = calculatorSum(E2);
    }
    P3 = arr[i];
    // kiem tra cuoi cung
    if (P1 == 100 && P2 == 100 && P3 == 100)
        EXP1 = ceil(EXP1 * 75.0 / 100);
    else
    {
        float P = (P1 + P2 + P3) / 3;
        if (P < 50.00)
        {
            HP1 = ceil(HP1 * 85.0 / 100);
            EXP1 = ceil(EXP1 * 115.0 / 100);
        }
        else
        {
            HP1 = ceil(HP1 * 9.0 / 10);
            EXP1 = ceil(EXP1 * 12.0 / 10);
        }
    }
    check(HP1, EXP1, M1);
    return HP1 + EXP1 + M1;
}

//! Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{   
    if (E3<0||E3>99) return -99;
    checktaxi(HP1, HP2, EXP1, EXP2);
    int arr[10][10]={0};
    int bigger=0, smaller=0;
    int posI,posJ;
    int sherlockPoint, taxiPoint;

    for (int i=0; i<10;i++){
        for (int j=0; j<10;j++){
            arr[i][j]=((E3*j)+(i*2))*(i-j);
            if (arr[i][j]>(2*E3)) bigger++;
            if (arr[i][j]<-E3) smaller++;
        }
    }
    posI=calculatorSumUntilHave1Number(bigger);
    posJ=calculatorSumUntilHave1Number(smaller);
    sherlockPoint=arr[posI][posJ];
    taxiPoint=arr[posI][posJ];
    for (int i=1;i<10;i++){
        if (((posI-i)<0)||((posJ-i)<0)) break;
        if (arr[posI-i][posJ-i]>sherlockPoint) sherlockPoint=arr[posI-i][posJ-i];
    }
     for (int i=1;i<10;i++){
        if (((posI-i)<0)||((posJ+i)>=10)) break;
        if (arr[posI-i][posJ+i]>sherlockPoint) sherlockPoint=arr[posI-i][posJ+i];
    }
    for (int i=1;i<10;i++){
        if (((posI+i)>=10)||((posJ+i)>=10)) break;
        if (arr[posI+i][posJ+i]>sherlockPoint) sherlockPoint=arr[posI+i][posJ+i];
    }
    for (int i=1;i<10;i++){
        if (((posI+i)>=10)||((posJ-i)<0)) break;
        if (arr[posI+i][posJ-i]>sherlockPoint) sherlockPoint=arr[posI+i][posJ-i];
    }
    sherlockPoint=abs(sherlockPoint);
    bool flag=0;
    if(abs(taxiPoint)>sherlockPoint){
        EXP1=ceil(EXP1*88.0/100);
        EXP2=ceil(EXP2*88.0/100);
        HP1=ceil (HP1*9.0/10);
        HP2=ceil (HP2*9.0/10);
        flag =1;
    }
    else {
        EXP1=ceil(EXP1*112.0/100);
        EXP2=ceil(EXP2*112.0/100);
        HP1=ceil (HP1*11.0/10);
        HP2=ceil (HP2*11.0/10);
    }
    checktaxi(HP1, HP2, EXP1, EXP2);
    if (flag==true)return taxiPoint;
    else return sherlockPoint;
}

//! Task 4
int checkPassword(const char *s, const char *email)
{
    int length_of_S = 0;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        length_of_S++;
    }
    if (length_of_S < 8)
        return -1;
    if (length_of_S > 20)
        return -2;
    // copy se
    const char *se = nullptr;
    char newString[101];
    int i;
    for ( i = 0; email[i] != '@'; ++i)
    {
        newString[i] = email[i];
    }
    newString[i] = '\0';
    se = newString;
    if (newString[0] == '\0')
        return -300;
    // kiem tra do dai
    // kiem tra se co trong s hay khong
    const char *result = strstr(s, se);
    size_t sei = result - s;
    if (result != nullptr)
        return -(300 + sei);

    // kiem tra co ki tu lap lai 3 lan hay khong
    const char *start = nullptr;
    int consecutiveCount = 1;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] == s[i + 1])
        {
            consecutiveCount++;
            if (consecutiveCount == 3)
            {
                start = &s[i - 1];
                break;
            }
        }
        else
        {
            consecutiveCount = 1;
        }
    }
    if (start != nullptr)
    {
        size_t sci = start - s;
        return -(400 + sci);
        // kiem tra ki tu dac biet
    }
    
    
    if (strchr(s,'@') == nullptr && strchr(s,'#') == nullptr && strchr(s,'%') == nullptr
 && strchr(s,'$') == nullptr && strchr(s,'!') == nullptr)
    {
        return -5;
    }

    // kiem tra xem mat khau co vi pham tieu chuan khac nua khong
    bool hasViolation = false;
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (!isdigit(s[i]) && !islower(s[i]) && !isupper(s[i]) && s[i]!='#'
        && s[i]!='@'&& s[i]!='%'&& s[i]!='$'&& s[i]!='!' )
        {
            hasViolation = true;
            return i;
        }
    }
    return -10;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int maxCount = 0; 
    int maxLength = 0; 
    int correctPasswordIndex = -1;
    const char* correctPassword = nullptr; 

    //duyet mang de tim mk dung
    for (int i = 0; i < num_pwds; ++i) {
        const char* currentPassword = arr_pwds[i];
        int currentCount = 1;

        // dem so lan xuat hien
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strstr(arr_pwds[j], currentPassword) != nullptr&&(strlen(arr_pwds[j]) == strlen(currentPassword))) {
                ++currentCount;
            }
        }

        // So sanh voi mat khau dung hien tai
        if (currentCount > maxCount || (currentCount == maxCount && strlen(currentPassword) > maxLength)) {
            maxCount = currentCount;
            maxLength = strlen(currentPassword);
            correctPassword = currentPassword;
            correctPasswordIndex = i; 
        }
    }
    return correctPasswordIndex;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////