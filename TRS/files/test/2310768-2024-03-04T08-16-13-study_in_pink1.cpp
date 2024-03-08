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

// Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
  if (E1 < 0 || E1 > 99) return -99;
    if (E1 >= 0 && E1 <= 3)
    {
        if (E1 == 0) EXP2 += 29;
        else if (E1 == 1) EXP2 += 45;
        else if (E1 == 2) EXP2 += 75;
        else if (E1 == 3) EXP2 = EXP2 + 29 + 45 + 75;
        int D = E1 * 3 + EXP1 * 7;
        if (D%2==0) EXP1 = ceil(EXP1 + D/200.0);
        else EXP1 = ceil(EXP1 - D/100.0);
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
    }
    if (E1 >= 4 && E1 <= 99)
    {
        if (E1 <= 19) EXP2 += ceil(E1/4.0)+19;
        else if (E1 <= 49) EXP2 += ceil(E1/9.0)+21;
        else if (E1 <= 65) EXP2 += ceil(E1/16.0)+17;
        else if (E1 <= 79)
        {
            EXP2 += ceil(E1/4.0)+19;
            if (EXP2 > 200) EXP2 += ceil(E1/9.0)+21;
        }
        else if (E1 <= 99)
        {
            EXP2 += ceil(E1/4.0)+19;
            EXP2 += ceil(E1/9.0)+21;
            if (EXP2 > 400) 
            {
                EXP2 += ceil(E1/16.0)+17;
                EXP2 += ceil((15 * EXP2)/100.0);
            }
        }
        EXP1 -= E1;
        if (EXP1 < 0) EXP1 = 0;
        if (EXP1 > 600) EXP1 = 600;
        if (EXP2 < 0) EXP2 = 0;
        if (EXP2 > 600) EXP2 = 600;
    }
    return EXP1 + EXP2;
}

// Task2
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{
    if (E2 > 99 || E2 < 0)
        return -99;
    int S, root=floor(sqrt(EXP1));
    double P1,P2,P3;
    if ((EXP1-root*root)>(root+1)*(root+1)-EXP1)
    S=(root+1)*(root+1);
    else S=root*root;
    if (S<=EXP1) P1=1;
    else P1=((EXP1/(S*1.0))+80)/123.0;
    // e2 even
    if (E2%2==0)
    {
        while (M1 >= 0)
        {
            if (M1 > 3000) M1=3000;
            if (M1 <= 0)
            {
                HP1 = ceil(HP1*83.0/100);
                EXP1 += ceil(EXP1*17.0/100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                break;
            }
            if (HP1 < 200)
            {
                HP1 += ceil(HP1*30.0/100);
                M1-=150;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            else
            {
                HP1 += ceil(HP1*10.0/100);
                M1-=70;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            // stop loop
            if (M1<=0)
            {
                HP1 = ceil(HP1*83.0/100);
                EXP1 += ceil(EXP1*17.0/100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                M1=0;
                break;
            }
            if (EXP1 < 400)
            {
                EXP1+=ceil(EXP1*13.0/100);
                M1-=200;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            else
            {
                EXP1+=ceil(EXP1*13.0/100);
                M1-=120;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            //stop loop
            if (M1<=0)
            {
                HP1 = ceil(HP1*83.0/100);
                EXP1 += ceil(EXP1*17.0/100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                M1=0;
                break;
            }
            if (EXP1 < 300)
            {
                EXP1 = ceil(EXP1*90.0/100);
                M1-=100;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            else
            {
                EXP1 = ceil(EXP1*90.0/100);
                M1-=120;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            HP1 = ceil(HP1*83.0/100);
            EXP1 += ceil(EXP1*17.0/100);
            if (EXP1 < 0) EXP1 = 0;
            if (EXP1 > 600) EXP1 = 600;
            if (HP1 < 0) HP1 = 0;
            if (HP1 > 666) HP1 = 666;
            if (M1 <=0) M1=0;
            break; 
        }
    }
    // e2 odd
    else
    {
        int totalM = 0,M0 = M1;
        while (M1 >= 0)
        {
            if (M1 > 3000) M1=3000;
            if (M1 <= 0)
            {
                HP1 = ceil(HP1*83.0/100);
                EXP1 += ceil(EXP1*17.0/100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                break;
            }
            if (HP1 < 200)
            {
                HP1 += ceil(HP1*30.0/100);
                M1 -= 150;
                totalM += 150;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            else
            {
                HP1 += ceil(HP1*10.0/100);
                M1 -= 70;
                totalM += 70;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            // stop loop
            if (totalM > M0*0.5)
            {
                HP1 = ceil(HP1*83.0/100);
                EXP1 += ceil(EXP1*17.0/100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (M1<0) M1=0;
                break;
            }
            if (EXP1 < 400)
            {
                EXP1 += ceil(EXP1*13.0/100);
                M1 -= 200;
                totalM += 200;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            else
            {
                EXP1 += ceil(EXP1*13.0/100);
                M1 -= 120;
                totalM += 120;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            //stop loop
            if (totalM > M0*0.5)
            {
                HP1 = ceil(HP1*83.0/100);
                EXP1 += ceil(EXP1*17.0/100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (M1<0) M1=0;
                break;
            }
            if (EXP1 < 300)
            {
                EXP1 = ceil(EXP1*90.0/100);
                M1-= 100;
                totalM += 100;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            else
            {
                EXP1 = ceil(EXP1*90.0/100);
                M1-= 120;
                totalM += 120;
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
            }
            // stop loop
            if (totalM > M0*0.5)
            {
                HP1 = ceil(HP1*83.0/100);
                EXP1 += ceil(EXP1*17.0/100);
                if (EXP1 < 0) EXP1 = 0;
                if (EXP1 > 600) EXP1 = 600;
                if (HP1 < 0) HP1 = 0;
                if (HP1 > 666) HP1 = 666;
                if (M1<0) M1=0;
                break;
            }
        }
    }
    int S1, root1=floor(sqrt(EXP1));
    if ((EXP1-root1*root1)>(root1+1)*(root1+1)-EXP1)
    S1=(root1+1)*(root1+1);
    else S1=root1*root1;
    if (S1<=EXP1) P2=1;
    else P2=((EXP1/(S1*1.0))+80)/123.0;
    int P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    if(E2 < 10) P3=P[E2]/100.0;
    else 
    {
        int chuc = (E2-E2%10)/10.0, dvi = E2%10;
        int i = (chuc + dvi)%10;
        P3=P[i]/100.0;
    }
    if (P1==1&&P2==1&&P3==1) EXP1 = ceil(EXP1*75.0/100);
    else
    {
        double Ptb=(P1+P2+P3)/3.0;
        if (Ptb < 0.5)
        {
            HP1 = ceil(HP1*85.0/100);
            EXP1 += ceil(EXP1*15.0/100);
        }
        else
        {
            HP1 = ceil(HP1*90.0/100);
            EXP1 += ceil(EXP1*20.0/100);
        }
    }
    if (EXP1 < 0) EXP1 = 0;
    if (EXP1 > 600) EXP1 = 600;
    if (HP1 < 0) HP1 = 0;
    if (HP1 > 666) HP1 = 666;
    return HP1 + EXP1 + M1;
}



// Task 3
int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if(E3 < 0 || E3 > 99) return -99;
    long long int a[10][10],b[50];
    int pos_taxi=0,neg_taxi=0,i_taxi,j_taxi,mid_i,mid_j;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
        a[i][j]=(E3*j+2*i)*(i-j);
        if((a[i][j] != 0) && (a[i][j] > 2*E3)){
            pos_taxi++;
        }
        if((a[i][j] != 0) &&(a[i][j] < -1*E3)){
            neg_taxi++;
        }
     }
    }
    // the place of taxi
    if(pos_taxi >= 10)
    {
    mid_i = (pos_taxi - pos_taxi%10)/10.0 + pos_taxi%10;
    if(mid_i >= 10)
     {
        i_taxi = (mid_i - mid_i%10)/10.0 + mid_i%10;
     }
        else i_taxi = mid_i;
    }
    else i_taxi = pos_taxi;
    if(neg_taxi >= 10)
    {
    mid_j = (neg_taxi - neg_taxi%10)/10.0 + neg_taxi%10;
    if(mid_j >= 10)
     {
        j_taxi = (mid_j - mid_j%10)/10.0 + mid_j%10;
     }
        else j_taxi = mid_j;
    }
    else j_taxi = neg_taxi;
    // copy the score into a new array
    int index1=0 , leftDown = j_taxi - 1;
    for(int i = i_taxi + 1 ; i < 10; i++){
        if (i_taxi + 1 == 10) break;
        b[index1]=a[i][leftDown];
        index1++;
        leftDown--;
        if(leftDown < 0) break;
    }
    int index2 = index1, leftUp = j_taxi - 1;
    for(int i = i_taxi -1 ; i>=0 ; i--){
        if(i_taxi - 1 == -1) break;
        b[index2] = a[i][leftUp];
        index2++;
        leftUp--;
        if(leftUp < 0) break;
    }
    int index3 = index2, rightDown = j_taxi + 1;
    for(int i = i_taxi + 1 ; i<10; i++){
        if(i_taxi + 1 == 10) break;
        b[index3] = a[i][rightDown];
        index3++;
        rightDown++;
        if(rightDown >= 10) break;
    }
    int index4 = index3, rightUp = j_taxi + 1;
    for(int i = i_taxi - 1; i<=0; i--){
        if(i_taxi - 1 == -1) break;
        b[index4] = a[i][rightUp];
        index4++;
        rightUp++;
        if(rightUp >= 10) break;
    }
    b[index4] = a[i_taxi][j_taxi];
    // b[] has index4 +1 numbers, from b[0] to b[index4], we find max of b array (it's sherlock's score)
    int max_score = b[0];
    for(int i=1; i < index4; i++)
    {
        if (b[i]> max_score)
        max_score = b[i];
    }
    // compare abs(Sherlock's score) and abs(taxi's score)
    int sherlock=abs(max_score) , taxi = abs(a[i_taxi][j_taxi]);
    if(taxi > sherlock )
    {
        EXP1 = ceil(EXP1*88/100.0);
        EXP2 = ceil(EXP2*88/100.0);
        HP1 = ceil(HP1*90/100.0);
        HP2 = ceil(HP2*90/100.0);
        return a[i_taxi][j_taxi];
    }
    else
    {
        EXP1 = ceil(EXP1*112/100.0);
        EXP2 = ceil(EXP2*112/100.0);
        HP1 = ceil(HP1*110/100.0);
        HP2 = ceil(HP2*110/100.0);
        if (EXP2 > 600) EXP2 = 600;
        if (EXP1 > 600) EXP1 = 600;
        if (HP1 > 666) HP1 = 666;
        if (HP2 > 666) HP2 = 666;
        return sherlock;
    }
    return -1;
}

// Task 4
int checkPassword(const char *s, const char *email)
{
    // create "se" array
    char se[101];
    const char* atSpec = strchr(email, '@');
    int count = atSpec - email;
    strncpy(se,email,count);
    se[count]='\0';
    // length of "s"
    size_t length = strlen(s);
    int length_s = static_cast<int>(length);
    if(length_s < 8)
        return -1;
    if(length_s > 20)
        return -2;
    // "se" in "s"
    const char* place = strstr(s,se);
    if(place != nullptr)
    {
        int sei= place - s;
        return -300-sei;
    }
    //more than 2 continuous and same char in "s"
    int sci = 0;
    const char* p1=s;
    while (*p1) {
        if ((*(p1 + 2) && *p1 == *(p1 + 1)) && *p1 == *(p1 + 2)) {
            return -400-sci;
        }
        ++p1;
        ++sci;
    }
    //"s" didn't have special char ’@’, ’#’, ’%’,’$’, ’!’
    int check=0;
    const char* p2=s;
    while (*p2) {
        if(*p2!='@'&&*p2!='#'&&*p2!='%'&&*p2!='$'&&*p2!='!')
        ++check;
        ++p2;
    }
    if (check == length_s)
        return -5;
    // other cases
    const char* p3=s;
    while (*p3) {
        if(*p3!='@'&&*p3!='#'&&*p3!='%'&&*p3!='$'&&*p3!='!'&&
           !(*p3 >= '0' && *p3 <= '9') &&
           !(*p3 >= 'A' && *p3 <= 'Z') &&
           !(*p3 >= 'a' && *p3 <= 'z')) {
            return p3 - s;
        }
        ++p3;
    }
    return -10;
}


// Task 5
int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    char arr[30][101];
    int repo[30] = {0};
    int count = 0;
    for (int i = 0; i < num_pwds; i++) 
    {
        bool same = false;
        for (int j = 0; j < count; j++) 
        {
            if (strcmp(arr[j], arr_pwds[i]) == 0) 
            // dont do if two strings not same
            {
                same = true;
                repo[j]++;
                break;
            }
        }
        if (!same) 
        // two strings same will copy to arr
        {
            strcpy(arr[count], arr_pwds[i]);
            repo[count] = 1;
            count++;
        }
    }
    //find max of repo array
    int max_repo = repo[0];
    int latest_index = 0;
    for(int i=1; i < count; i++)
    {
        if(repo[i] > max_repo)
        {
            max_repo = repo[i];
            latest_index = i;
        }
    }
    //find the index which arr[index] appear most and have most chars
    size_t final_max_length = strlen(arr[latest_index]);
    int final_max_index = latest_index;
    for(int i = latest_index + 1 ; i < count ; i++)
    {
        if(max_repo == repo[i])
        {
            size_t new_length = strlen(arr[i]);
            if(new_length > final_max_length)
            {
                final_max_length = new_length;
                final_max_index = i;
            }
        }
    }
    // final_max_index is the index of arr[] which string is what we find
    const char* final_string = arr[final_max_index];
    for(int i=0; i<num_pwds; i++)
    {
        if(strcmp(final_string,arr_pwds[i])==0)
        return i;
    }
    return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////