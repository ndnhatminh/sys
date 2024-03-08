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

#define exp 2
#define hp 1
#define m 3

//Ham phu
void Add(int & Value, float AddAmount,int type ){
//
    if((int)AddAmount - AddAmount<0)
    Value += ++AddAmount;
    else 
    Value += AddAmount;
//
    switch (type)
    {
    case 1:
        if(Value>666)
            Value=666;
        break;
    case 2:
        if(Value>600)
            Value=600;
        break;
    case 3:
        if(Value>3000)
            Value=3000;
        break;
    }
}
//
void Drop(int & Value, float DropAmount){
//
    if((int)DropAmount - DropAmount < 0)
    Value -= --DropAmount;
    else 
    Value -= DropAmount;
//
    if(Value<0)
        Value=0;
}
//
void Check(int & Value, int type){
    if(Value<0){
        Value=0;
    }
    else
        switch (type)
        {
        case 1:
            if(Value>666)
                Value=666;
            break;
        case 2:
            if(Value>600)
                Value=600;
            break;
        case 3:
            if(Value>3000)
                Value=3000;
            break;
        }      
}




// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
//Check 
    if(e1<0 || e1>99)
    return -99;
    Check(exp1,exp);
    Check(exp2,exp);
//Tinh
    if(e1<4){
        if(e1 == 0)
            Add(exp2,29,exp);
        if(e1 == 1)
            Add(exp2,45,exp);
        if(e1 == 2)
            Add(exp2,75,exp);
        if(e1 == 3){
            Add(exp2,29,exp);
            Add(exp2,45,exp);
            Add(exp2,75,exp);
        }
        int D=e1*3 + exp1*7;
        if(D%2 == 0)
            Add(exp1,D*1.0/200,exp);
        else
            Drop(exp1,D*1.0/100);
    }
    else {
        if(e1<=19)
            Add(exp2, (e1*1.0/4 + 19) , exp);
        else if(e1 <= 49)
            Add(exp2, (e1*1.0/9+21) ,exp);
        else if(e1 <= 65)
            Add(exp2, (e1*1.0/16+17) ,exp);
        else if(e1 <= 79){
            Add(exp2, (e1*1.0/4 + 19) , exp);
            if(exp2>200)
                Add(exp2, (e1*1.0/9+21) ,exp);
        }
        else {
            Add(exp2, (e1*1.0/4 + 19) , exp);
            Add(exp2, (e1*1.0/9 + 21),exp);   
            if(exp2 > 400){ 
                Add(exp2, (e1*1.0/16+17) ,exp);   
                Add(exp2, (exp2*15.0/100) , exp);
            } 
        }
        Drop(exp1,e1);       
    }
        return exp1 + exp2;
}

// Task 2
int traceLuggage(int & hp1, int & exp1, int & m1, int e2) {
//Check
    if(e2<0 || e2>99)
        return -99;
    Check(hp1,hp);
    Check(exp1,exp);
    Check(m1,m);
//Con duong 1
    float P1;
    float S = pow(round(sqrt(exp1)),2);
    if(exp1 >= S)
        P1 = 1;
    else 
        P1 = ((exp1/S + 80)/123);
//Con duong 2  (xem lai lam tron cua P)
float Half = m1*1.0/2;
//Lan n
    if((e2%2)!=0){
        while (m1 >= Half)
        {
            if(hp1<200){
                Add(hp1,hp1*30.0/100,hp);
                Drop(m1,150);
            }
            else{
                Add(hp1,hp1*10.0/100,hp);
                Drop(m1,70);
            }
            if(m1 < Half)
                break;
            //
            if(exp1 < 400)
                Drop(m1,200);
            else Drop(m1,120);
            Add(exp1,exp1*13.0/100,exp);///////

            if(m1 < Half)
                break;       
            //      
            if(exp1<300)
                Drop(m1,100);
            else Drop(m1,120);
            Drop(exp1, exp1*10.0/100);
            if(m1 < Half)
                break;   
        }
       
    }
    else{
        if(m1!=0)
        if(hp1<200){
            Add(hp1,hp1*30.0/100,hp);
            Drop(m1,150);
        }
        else{
            Add(hp1,hp1*10.0/100,hp);
            Drop(m1,70);
        }
        //
        if(m1!=0){
            if(exp1 < 400)
                Drop(m1,200);
            else{ 
                Drop(m1,120);
                //////////
            }
            Add(exp1,exp1*13.0/100,exp);
        }  
        //
        if(m1!=0){
            if(exp1<300)
                Drop(m1,100);
            else
                Drop(m1,120);
            Drop(exp1,exp1*10.0/100);
        }
    }
    Drop(hp1, hp1*17.0/100);
    Add(exp1, exp1*17.0/100, exp);
//Tinh P2
    float P2;
    S = pow(round(sqrt(exp1)),2);
    if(exp1 >= S)
        P2 = 1;
    else 
        P2 = ((exp1/S + 80)/123);
//
//Con duong 3
    int P[]={32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    float P3 ;
    P3 = P[(e2/10 + e2%10)%10]*1.0/100;

//Tom lai
    if(P1==1 && P2>=1 && P3==1)
        Drop(exp1,exp1*25.0/100);
    else if((P1+P2+P3)/3 < 0.5){
        Drop(hp1,hp1*15.0/100);
        Add(exp1,exp1*15.0/100,exp);
    }
    else{
        Drop(hp1,hp1*10.0/100);
        Add(exp1,exp1*20.0/100,exp);
    }


    return hp1 + exp1 + m1;
}

// Task 3
int chaseTaxi(int & hp1, int & exp1, int & hp2, int & exp2, int e3) {
//    
    if(e3<0 || e3>99)
        return -99;

//Tao ma tran diem cua con duong 
    int matran[10][10];
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++)
            matran[i][j]= ((e3*j)+(i*2))*(i-j);
     
//Tim vi tri
    int x=0,y=0;
    for(int i=0; i<10; i++)
        for(int j=0; j<10; j++){
            if(matran[i][j] > (e3*2))
                x++;
            if(matran[i][j]< (-e3))
                y++;
        }
//
    if(x==100)
        x=1;
    else
        while(x>9)
            x= (x/10 + x%10);
//
    if(y==100)
        y=1;
    else
        while(y>9)
            y=(y/10 + y%10);
//Tim max    
    int max= matran[x][y];
    int X, Y;
//
    X=x;
    Y=y;
    while(X!=10 && Y!=10){
        if(max < matran[X][Y])
            max= matran[X][Y];
        X++;
        Y++;
    }
//
    X=x;
    Y=y;
    while(X!=-1 && Y!=-1){
        if(max < matran[X][Y])
            max= matran[X][Y];
        X--;
        Y--;
    }   
//
    X=x;
    Y=y;
    while(X!=10 && Y!=-1){
        if(max < matran[X][Y])
            max= matran[X][Y];
        X++;
        Y--;
    }

//
    X=x;
    Y=y;
    while(X!=-1 && Y!=10){
        if(max < matran[X][Y])
            max= matran[X][Y];
        X--;
        Y++;
    }
//Cap nhat
    if(abs(matran[x][y]) > abs(max)){
        Drop(exp1,exp1*12.0/100);
        Drop(exp2,exp2*12.0/100);
        Drop(hp1,hp1*10.0/100);
        Drop(hp2,hp2*10.0/100);

        return matran[x][y];
    }
    else{
        Add(exp1,exp1*12.0/100,exp);
        Add(exp2,exp2*12.0/100,exp);
        Add(hp1,hp1*10.0/100,hp);
        Add(hp2,hp2*10.0/100,hp);

        return max;//vay truong hop 2 gia tri bang nhau va trai dau??? 
    }

}

// Task 4
int checkPassword(const char * s,const char * email) {
//    cout<<strlen(email);
//    cout<< strchr(email,'@') - email;
// strstr

//Chuyen ve string va tim se
    string S = string(s), Email=string(email);
    string se=Email.substr(0,Email.find('@'));

//Xu ly
    if(S.length()<8)
        return -1;
    if(S.length()>20)
        return -2;
//    
    int se_position = S.find(se);
    if(se_position< S.length())
        return -(300+se_position);
//
    for(int i=0; i<(S.length()-2); i++)
        if(S[i]==S[i+1] && S[i+1]==S[i+2])
            return -(400+i);
//
    int count =0;
    for(char c : S)
        if(c=='@'||c=='#'||c=='%'||c=='$'||c=='!')
            count++;
    if(count == 0)
        return -5;
//
    for(int i=0;i<S.length();i++)
        if(!((S[i]>='a'&& S[i]<='z')||(S[i]>='A'&& S[i]<='Z')||
       (S[i]>='0' && S[i]<='9')||(S[i]=='@'||S[i]=='#'||S[i]=='%'||
       S[i]=='$'||S[i]=='!')))
        return i;


    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string Arr[num_pwds];
    for(int i=0; i<num_pwds; i++)
        Arr[i]=string(arr_pwds[i]);
//   
    int frequency[num_pwds]={0};
    for(int i=0; i<num_pwds ; i++)
        for(int j=i+1; j<num_pwds; j++)
            if(Arr[i]==Arr[j])
                frequency[i]++;
//    
    int position=0;
    for(int i=1;i<num_pwds; i++)
        if(frequency[i]>frequency[position]){
            position=i;
        }
        else if(frequency[i]==frequency[position])
            if(Arr[i].length()>Arr[position].length())
                position=i;

    return position;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////