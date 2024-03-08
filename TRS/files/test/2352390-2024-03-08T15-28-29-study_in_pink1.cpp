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
void checkHP1(int & HP1){
    if (HP1>666)
        HP1=666;
    if (HP1<0)
        HP1=0;
}
void checkHP2(int & HP2){
    if (HP2>666)
        HP2=666;
    if (HP2<0)
        HP2=0;
}
void checkEXP1(int & EXP1){
    if (EXP1>600)
        EXP1=600;
    if (EXP1<0)
        EXP1=0;
}
void checkEXP2(int & EXP2){
    if (EXP2>600)
        EXP2=600;
    if (EXP2<0)
        EXP2=0;
}
void checkM1(int & M1){
    if (M1>3000)
        M1=3000;
    if (M1<0)
        M1=0;
}
void checkM2(int & M2){
    if (M2>3000)
        M2=3000;
    if (M2<0)
        M2=0;
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(e1>99||e1<0)
        return -99;
    int EXP1=exp1;
    int EXP2=exp2;
    int E1=e1;
    checkEXP1(EXP1);
    checkEXP2(EXP2);
    if(E1>=0&&E1<=3) //Truong hop 1 0.5 diem
    {
        switch (E1)
        {
            case 0:
            {
                EXP2+=29;
                break;
            }
            case 1:
            {
                EXP2+=45;
                break;
            }
            case 2:
            {
                EXP2+=75;
                break;
            }
            case 3:
            {
                EXP2=EXP2+29+45+75;
                break;
            }
            default:
                break;
        }
        checkEXP2(EXP2);
        int D = E1*3+EXP1*7;
        if(D%2==0)
            EXP1=int(ceil(float(EXP1)+float(D)/200));
        else
            EXP1=int(ceil(float(EXP1)-float(D)/100));
        checkEXP1(EXP1);
        checkEXP2(EXP2);
        exp1=EXP1;
        exp2=EXP2;
        return exp1 + exp2;
    }
    //Truong hop 2 1.0 diem
    if (E1>=4&&E1<=19)
        EXP2 = int(ceil(float(EXP2)+19+float(E1)/4)); checkEXP2(EXP2);
    if (E1>=20&&E1<=49)
        EXP2 = int(ceil(float(EXP2)+21+float(E1)/9)); checkEXP2(EXP2);
    if (E1>=50&&E1<=65)
        EXP2 = int(ceil(float(EXP2)+17+float(E1)/16)); checkEXP2(EXP2);
    if (E1>=66&&E1<=79){
        EXP2 = int(ceil(float(EXP2)+19+float(E1)/4)); checkEXP2(EXP2);
        if(EXP2>200)
            EXP2 = int(ceil(float(EXP2)+21+float(E1)/9)); checkEXP2(EXP2);
    }
    if (E1>=80&&E1<=99){
        EXP2 = int(ceil(float(EXP2)+19+float(E1)/4)); checkEXP2(EXP2);
        EXP2 = int(ceil(float(EXP2)+21+float(E1)/9)); checkEXP2(EXP2);
        if(EXP2>400){
            EXP2 = int(ceil(float(EXP2)+17+float(E1)/16)); checkEXP2(EXP2);
            EXP2 = int(ceil(float(EXP2)*115/100)); checkEXP2(EXP2);
        }
    }
    EXP1=EXP1-E1;
    checkEXP1(EXP1);
    checkEXP2(EXP2);
    exp1=EXP1;
    exp2=EXP2;
    return exp1+exp2;
}
int task2_conduong2_gd1(int &HP1, int &M1){
    int money_spent=0;
    if(HP1<200)
    {
        HP1=int(ceil(float(HP1)*13/10));
        M1=M1-150;
        money_spent+=150;
    }
    else
    {
        HP1=int(ceil(float(HP1)*11/10));
        M1=M1-70;
        money_spent+=70;
    }
    checkHP1(HP1);
    checkM1(M1);
    //cout<<"HP1="<<HP1<<endl;
    //cout<<"M1="<<M1<<endl;
    return money_spent;
}
int task2_conduong2_gd2(int &EXP1, int &M1){
    int money_spent=0;
    if(EXP1<400)
    {
        M1-=200;
        money_spent+=200;
    }
    else
    {
        M1-=120;
        money_spent+=120;
    }
    EXP1=int(ceil(float(EXP1)*113/100));
    checkEXP1(EXP1);
    checkM1(M1);
    //cout<<"EXP1="<<EXP1<<endl;
    //cout<<"M1="<<M1<<endl;
    return money_spent;
}
int task2_conduong2_gd3(int &EXP1, int &M1){
    int money_spent=0;
    if(EXP1<300)
    {
        M1-=100;
        money_spent+=100;
    }
    else
    {
        M1-=120;
        money_spent+=120;
    }
    EXP1=int(ceil(float(EXP1)*9/10.0));
    checkEXP1(EXP1);
    checkM1(M1);
    //cout<<"EXP1="<<EXP1<<endl;
    //cout<<"M1="<<M1<<endl;
    return money_spent;
}
// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function
    if(E2>99||E2<0)
        return -99;
    checkHP1(HP1);
    checkEXP1(EXP1);
    checkM1(M1);
    float P1,P2,P3;
    int S = round(sqrt(EXP1))*round(sqrt(EXP1));
    //Con duong 1
    if(EXP1>=S)
        P1=1;
    else
        P1=(float(EXP1)/float(S)+80)/123;
    //Con duong 2
    int initial_cost=M1;
    int total_cost=0;
    if(M1!=0){
        while(E2%2!=0)
        {
            total_cost+=task2_conduong2_gd1(HP1,M1);
            if(2*total_cost>initial_cost)
                break;
            total_cost+=task2_conduong2_gd2(EXP1,M1);
            if(2*total_cost>initial_cost)
                break;
            total_cost+=task2_conduong2_gd3(EXP1,M1);
            if(2*total_cost>initial_cost)
                break;
        }
        while(E2%2==0)
        {
            task2_conduong2_gd1(HP1,M1);
            if(M1==0)
                break;
            task2_conduong2_gd2(EXP1,M1);
            if(M1==0)
                break;
            task2_conduong2_gd3(EXP1,M1);
            if(M1==0)
                break;
            break;
        }
    }
    HP1=int(ceil(float(HP1)*83/100));
    EXP1=int(ceil(float(EXP1)*117/100));
    checkHP1(HP1);
    checkEXP1(EXP1);
    S = round(sqrt(EXP1))*round(sqrt(EXP1));
    if(EXP1>=S)
        P2=1;
    else
        P2=(float(EXP1)/float(S)+80)/123;
    //cout<<"het con duong 2"<<endl;
    //cout<<"HP1="<<HP1<<endl;
    //cout<<"EXP1="<<EXP1<<endl;
    //cout<<"M1="<<M1<<endl;
    //Con duong 3
    int i = (E2+E2/10)%10;
    float P[10]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    P3=P[i]/100;
    if(P1==1&&P2==1&&P3==1)
    {
        EXP1=int(ceil(float(EXP1)*75/100));
        checkEXP1(EXP1);
        checkHP1(HP1);
        checkM1(M1);
        return HP1 + EXP1 + M1;
        //traceLuggage(HP1,EXP1,M1,E2);
    }
    float P_avg = (P1+P2+P3)/3;
    if(P_avg<0.5)
    {
        HP1=int(ceil(float(HP1)*85/100));
        EXP1=int(ceil(float(EXP1)*115/100));
    }
    else
    {
        HP1=int(ceil(float(HP1)*90/100));
        EXP1=int(ceil(float(EXP1)*12/10));
    }
    checkEXP1(EXP1);
    checkHP1(HP1);
    checkM1(M1);
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(E3>99||E3<0)
        return -99;
    // TODO: Complete this function
    checkHP1(HP1);
    checkEXP1(EXP1);
    checkHP2(HP2);
    checkEXP2(EXP2);
    int TaxiMatrix[10][10];
    int E3_2x=E3*2;
    int negE3=-E3;
    int a=0;
    int b=0;
    int k;
    for (int i=0; i<=9; i++)
        for (int j=0; j<=9; j++)
        {
            TaxiMatrix[i][j]=(i-j)*(E3*j+i*2);
            if(TaxiMatrix[i][j]>E3_2x)
                a++;
            if(TaxiMatrix[i][j]<negE3)
                b++;
        }
    while(a>=10)
        a=a/10+a%10;
    while(b>=10)
        b=b/10+b%10;
    int chase_score=TaxiMatrix[a][b];
    for (k=-10;k<=10;k++)
    {
        if(a+k>=0&&a+k<=9&&b+k>=0&&b+k<=9)
            if(TaxiMatrix[a+k][b+k]>chase_score)
                chase_score=TaxiMatrix[a+k][b+k];
    }
    for (k=-10;k<=10;k++)
    {
        if(a-k>=0&&a-k<=9&&b+k>=0&&b+k<=9)
            if(TaxiMatrix[a-k][b+k]>chase_score)
                chase_score=TaxiMatrix[a-k][b+k];
    }
    chase_score=abs(chase_score);
    if(abs(TaxiMatrix[a][b])>chase_score) //ko bat kip, tra ve diem taxi co the am
    {
        HP1=int(ceil(float(HP1)*9/10));
        EXP1=int(ceil(float(EXP1)*88/100));
        HP2=int(ceil(float(HP2)*9/10));
        EXP2=int(ceil(float(EXP2)*88/100));
        checkEXP1(EXP1);
        checkHP1(HP1);
        checkEXP2(EXP2);
        checkHP2(HP2);
        return TaxiMatrix[a][b];
    }
    else //bat kip, tra ve diem sherlock, luon duong vi da lay abs
    {
        HP1=int(ceil(float(HP1)*11/10));
        EXP1=int(ceil(float(EXP1)*112/100));
        HP2=int(ceil(float(HP2)*11/10));
        EXP2=int(ceil(float(EXP2)*112/100));
        checkEXP1(EXP1);
        checkHP1(HP1);
        checkEXP2(EXP2);
        checkHP2(HP2);
        return chase_score;
    }
    
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string _s=string(s);
    string _email=string(email);
    string se=_email.substr(0,_email.find("@"));
    string s_character_id;
    if(_s.length()<8)
    {
        return -1;
    }
    if(_s.length()>20)
    {
        return -2;
    }
    int se_pos=_s.find(se);
    if(se_pos!=-1)
    {
        return -(300+se_pos);
    }
    for (int i=0; i<_s.length()-2;i++)
    {
        if(_s[i]==_s[i+1]&&_s[i]==_s[i+2])
            {
                return -(400+i);
            }
    }
    for (int i=0; i<_s.length();i++)
    {
        if(islower(_s[i]))
            s_character_id.append("1");
        else if(isupper(_s[i]))
            s_character_id.append("2");
        else if(isdigit(_s[i]))
            s_character_id.append("3");
        else if(_s[i]=='@'||_s[i]=='#'||_s[i]=='%'||_s[i]=='$'||_s[i]=='!')
            s_character_id.append("4");
        else
            s_character_id.append("0");
    }
    int special_character_pos = s_character_id.find('4');
    int other_cases_pos = s_character_id.find('0');
    if(special_character_pos==-1)
    {
        return -5;
    }
    if(other_cases_pos!=-1)
    {
        return other_cases_pos;
    }
    return -10;
}
struct password_info {
    string password;
    int repetition_count;
    int password_length;
    int index;
};

void quickSort (password_info arr[], int start, int end)
{
    if (start>=end)
        return;
    string pivot = arr[start].password;
    int count=0;
    for (int i=start+1; i<=end;i++)
    {
        if(arr[i].password<=pivot)
            count++;
    }
    int pivot_index=start+count;
    swap(arr[start],arr[pivot_index]);
    int p=start, q=end;
    while (p<pivot_index && q>pivot_index)
    {
        while(arr[p].password<=pivot)
        {
            p++;
        }
        while(arr[q].password>pivot)
        {
            q--;
        }
        if (p<pivot_index && q>pivot_index)
        {
            swap(arr[p],arr[q]);
            p++;
            q--;
        }
    }
    quickSort(arr,start,pivot_index-1);
    quickSort(arr,pivot_index+1,end);
}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    int size=num_pwds;
    password_info arr[size];
    for (int i=0; i<size; i++)
    {
        arr[i].password=string(arr_pwds[i]);
        arr[i].index=i;
        arr[i].password_length=arr[i].password.length();
    }
    quickSort(arr,0,size - 1); 
    int i=0,max_repetition=0;;
    while(i<size)
    {
        int j=i;
        int count=0;
        while(arr[i].password==arr[j].password&&j<size)
        {
            j++;
            count++;
        }
        for (int i_=i;i_<j;i_++)
        {
            arr[i_].repetition_count=count;
        }
        if(max_repetition<count)
            max_repetition=count;
        i+=count;
    }
    int max_length=0;
    for (int i=0;i<size;i++)
    {
        if(arr[i].repetition_count==max_repetition)
        {
            if(max_length<arr[i].password_length)
                max_length=arr[i].password_length;
        }
    }
    int min_index=size;
    for (int i=0;i<size;i++)
    {
        if(arr[i].repetition_count==max_repetition && arr[i].password_length == max_length)
            if(min_index>arr[i].index)
                min_index=arr[i].index;
    }
    //cout
    /*
    for (int i=0;i<size;i++)
    {
        cout<<arr[i].password<<" repetition="<<arr[i].repetition_count<<" length="<<arr[i].password_length<<" index="<<arr[i].index<<endl;
    }
    cout<<endl<<"DEBUG max repetition="<<max_repetition<<" max length="<<max_length<<" index="<<min_index<<endl;
    */
    return min_index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////