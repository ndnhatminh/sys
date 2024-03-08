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

// Task 1
int ktHP(int &HP)
    {
        if (HP < 0) HP= 0;
        else if (HP > 666) HP= 666;
        return HP;
    }
    
int ktexp(int &exp)
    {
        if (exp < 0) exp= 0;
        else if (exp > 600) exp= 600;
        return exp;
    }
    
int ktM(int &M)
    {
        if (M < 0) M= 0;
        else if (M > 3000) M= 3000;
        return M;
    }
int ktE(int e){
    if((e<0)||(e>99)) return -99;
    return 1;
}

int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if(ktE(e1)==1){
    ktexp(exp1);
    ktexp(exp2);
    if((e1>=0)&&(e1<=3)){
        int D;
        if( e1 == 0) {
            exp2= exp2 + 29;
            ktexp(exp2);
        }
        if( e1 == 1) {
            exp2= exp2 + 45;
            ktexp(exp2);
        }
        if( e1 == 2) {
            exp2= exp2 + 75;
            ktexp(exp2);
        }
        if( e1 == 3) {
            exp2= exp2 + 29 + 45 + 75;
            ktexp(exp2);
        }
        D=e1*3+exp1*7;
        if((D%2)==0) exp1 = exp1 + (float)D/200 +0.9999;
        else exp1 = exp1 - (float)D/100 +0.9999;
       
        ktexp(exp1);
        ktexp(exp2);
    }
    if((e1>=4)&&(e1<=99)){
        if((e1>=4)&&(e1<=19)) {
            exp2=exp2 + (float)e1/4 +19 +0.9999;
            ktexp(exp2);
        }
        if((e1>=20)&&(e1<=49)) {
            exp2= exp2 + (float)e1/9 + 21 + 0.9999;
            ktexp(exp2);
        }
        if((e1>=50)&&(e1<=65)) {
            exp2=exp2 + (float)e1/16 +17+0.9999;
            ktexp(exp2);
        }
        if((e1>=66)&&(e1<=79)) {
            exp2=exp2 + (float)e1/4 +19+0.9999;
            if(exp2>200) {
                exp2=exp2 + (float)e1/9 +21+0.9999;
            }
            ktexp(exp2);
        }
        ktexp(exp1);
    ktexp(exp2);
        if((e1>=80)&&(e1<=99)) {
            exp2=exp2 + (float)e1/4 +19+0.9999;
            exp2=exp2 + (float)e1/9 +21+0.9999;
            if(exp2>400) {
                exp2=exp2 + (float)e1/16 +17 +0.9999;
                exp2=(float)exp2 * 1.15 +0.9999;
            }
            ktexp(exp2);
        }
        exp1=exp1 - e1 + 0.9999;
        ktexp(exp1);
    }
    ktexp(exp1);
    ktexp(exp2);
    
    return exp1 + exp2;
    }
    return -99;
}

// Task 2
int traceLuggage(int & HP1, int & exp1, int & M1, int e2) {
    // TODO: Complete this function
    if(ktE(e2)==1) {
    ktHP(HP1);
    ktexp(exp1);
    ktM(M1);
    int S, a, b, c;
    float P1, P2, P3;
    a=round(sqrt(exp1));
    S=a*a;
    if(exp1>=S) P1=100;
    else P1=(exp1/S + 80.0)/1.23;
    //Con duong 2
    b= M1/2;
    c=0;
    if((e2%2)==1) {
        if(c<=b) {
            if(HP1<200) {
                HP1= (float) (1.3* HP1) +0.9999;
                M1-= 150;
                c+=150;
            }
            else {
                HP1= (float)(1.1*HP1)+0.9999;
                M1-=70;
                c+=70;
            }
            ktM(M1);
            ktHP(HP1);
        }
        if (c<=b) {
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1 <400) {
                M1-=200;
                c+=200;
            }
            else {
                M1-=120;
                c+=120;
            }
            ktM(M1);
            exp1=(float)(1.13*exp1)+0.9999;
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            }
        if (c<=b) {
           
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1<300) {
                M1-=100;
                c+=100;
            }
            else {
                M1-=120;
                c+=120;
            }
        exp1=(float)(0.9*exp1)+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
            }
        
        if(c<=b) {
            if(HP1<200) {
                HP1= (float)1.3* HP1+0.9999;
                M1-= 150;
                c+=150;
            }
            else {
                HP1= (float)1.1*HP1+0.9999;
                M1-=70;
                c+=70;
            }
            ktM(M1);
            ktHP(HP1);
        }
        if (c<=b) {
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1 <400) {
                M1-=200;
                c+=200;
            }
            else {
                M1-=120;
                c+=120;
            }
            ktM(M1);
            exp1=(float)1.13*exp1+0.9999;
            ktexp(exp1);
            }
        if (c<=b) {
           
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1<300) {
                M1-=100;
                c+=100;
            }
            else {
                M1-=120;
                c+=120;
            }
        exp1=(float)0.9*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
            }
          
        if(c<=b) {
            if(HP1<200) {
                HP1= (float)1.3* HP1+0.9999;
                M1-= 150;
                c+=150;
            }
            else {
                HP1= (float)1.1*HP1+0.9999;
                M1-=70;
                c+=70;
            }
            ktM(M1);
            ktHP(HP1);
        }
        if (c<=b) {
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1 <400) {
                M1-=200;
                c+=200;
            }
            else {
                M1-=120;
                c+=120;
            }
            ktM(M1);
            exp1=(float)1.13*exp1+0.9999;
            ktexp(exp1);
            }
        if (c<=b) {
           
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1<300) {
                M1-=100;
                c+=100;
            }
            else {
                M1-=120;
                c+=120;
            }
        exp1=(float)0.9*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
            }
        
        if(c<=b) {
            if(HP1<200) {
                HP1= (float)1.3* HP1+0.9999;
                M1-= 150;
                c+=150;
            }
            else {
                HP1= (float)1.1*HP1+0.9999;
                M1-=70;
                c+=70;
            }
            ktM(M1);
            ktHP(HP1);
            
        }
        if (c<=b) {
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1 <400) {
                M1-=200;
                c+=200;
            }
            else {
                M1-=120;
                c+=120;
            }
            ktM(M1);
            exp1=(float)1.13*exp1+0.9999;
            ktexp(exp1);
            }
        if (c<=b) {
           
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1<300) {
                M1-=100;
                c+=100;
            }
            else {
                M1-=120;
                c+=120;
            }
        exp1=(float)0.9*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
            }
        
        if(c<=b) {
            if(HP1<200) {
                HP1= (float)1.3* HP1+0.9999;
                M1-= 150;
                c+=150;
            }
            else {
                HP1= (float)1.1*HP1+0.9999;
                M1-=70;
                c+=70;
            }
            ktM(M1);
            ktHP(HP1);
        }
        if (c<=b) {
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1 <400) {
                M1-=200;
                c+=200;
            }
            else {
                M1-=120;
                c+=120;
            }
            ktM(M1);
            exp1=(float)1.13*exp1+0.9999;
            ktexp(exp1);
            }
        if (c<=b) {
           
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1<300) {
                M1-=100;
                c+=100;
            }
            else {
                M1-=120;
                c+=120;
            }
        exp1=(float)0.9*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
            }

        if(c<=b) {
            if(HP1<200) {
                HP1=(float) 1.3* HP1+0.9999;
                M1-= 150;
                c+=150;
            }
            else {
                HP1= (float)1.1*HP1+0.9999;
                M1-=70;
                c+=70;
            }
            ktM(M1);
            ktHP(HP1);
        }
        if (c<=b) {
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1 <400) {
                M1-=200;
                c+=200;
            }
            else {
                M1-=120;
                c+=120;
            }
            ktM(M1);
            exp1=(float)1.13*exp1+0.9999;
            ktexp(exp1);
            }
        if (c<=b) {
           
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1<300) {
                M1-=100;
                c+=100;
            }
            else {
                M1-=120;
                c+=120;
            }
        exp1=(float)0.9*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
            }
        
        
        HP1=(float)0.83*HP1+0.9999;
        exp1=(float)1.17*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
    
        
    }
    
    /////////////////////////////////////
    ////////////////////////////////////
    else { 
        
        if(M1>0) {
            if(HP1<200) {
                HP1=(float) 1.3* HP1+0.9999;
                M1-= 150;
                
                ktM(M1);
                ktHP(HP1);
            }
            else {
                HP1= (float)1.1*HP1+0.9999;
                M1-=70;
               
                ktM(M1);
                ktHP(HP1);
            }
        }
        if (M1>0) {
            
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            if(exp1 <400) {
                M1-=200;
                ktM(M1);
            }
            else {
                M1-=120;
                ktM(M1);
            }
            exp1=(float)1.13*exp1+0.9999;
            ktexp(exp1);
            ktM(M1);
            ktHP(HP1);
            }
        if (M1>0) {
            if(exp1<300) {
                M1-=100;
                
            }
            else {
                M1-=120;
                
            }
        exp1=(float)0.9*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
            }
        
        HP1=(float)0.83*HP1+0.9999;
        exp1=(float)1.17*exp1+0.9999;
        ktexp(exp1);
        ktM(M1);
        ktHP(HP1);
        
    }
    //////////////
    a=round(sqrt(exp1));
    S=a*a;
    if(exp1>=S) P2=100;
    else P2=(exp1/S + 80.0)/1.23;
    ///////////// CON DUONG 3 ////////////////////
    int P[10]={32, 47, 28, 79, 100,50, 22, 83, 64, 11};
    int i;
    if(e2<10) i=e2;
    else {
        i= e2/10 + e2%10;
        i= i%10;
    }
    P3=P[i];
    if((P1+P2+P3)==300) exp1 = 0.75*exp1+0.9999;
    else {
        float avr=(P1+P2+P3)/3.0;
        if(avr>= 50) {
            HP1=(float)0.9*HP1+0.9999;
            exp1=(float)1.2*exp1+0.9999;
        }
        else {
        HP1=(float)0.85*HP1+0.9999;
        exp1=(float)1.15*exp1+0.9999;
        }
    }
    ktexp(exp1);
    ktM(M1);
    ktHP(HP1);
    
    return HP1 + exp1 + M1;
}
return -99;
}
// Task 3
int chaseTaxi(int & HP1, int & exp1, int & HP2, int & exp2, int e3) {
    // TODO: Complete this function
    if(ktE(e3)==1) {
    int map[10][10]={0};
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            map[i][j]=(( e3*j)+(i*2))*(i-j);
        }
    }
    
    int m=0, n=0;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if((map[i][j]>0)&&(map[i][j]>( e3*2))) m+=1;
            if(((map[i][j])<0)&&(map[i][j]<(- e3))) n+=1;
            
        }
    }
    m=m/10+m%10;
    m=m/10+m%10;
    n=n/10+n%10;
    n=n/10+n%10;
   
    int Max= map[m][n];
    
    int z=n, x=n, c=n, v=n;
 
    for(int i=(m+1); i<10; i++){ 
        if(z>0) {
            z--;
        
            if (map[i][z] > Max)  {
                Max = map[i][z];
                
            }
        }
        if(x<9) {
            x++;
           
            if (map[i][x] > Max)  {
                Max = map[i][x];
                
            }
        }
        
    } 
    for(int i=(m-1); i>(-1); i--){ 
        if(c>0) {
            c--;
            
            if (map[i][c] > Max)  {
                Max = map[i][c];
                
            }
            
        }
        if(v<9) {
            v++;
            
            if (map[i][v] > Max)  {
                Max = map[i][v];
                
            }
            
        }
        
    }
    if( abs(map[m][n]) > Max) {
        exp1= (float)0.88* exp1+0.99999;
        exp2= (float)0.88* exp2+0.99999;
        HP1= (float)0.9* HP1+0.99999;
        HP2= (float)0.9* HP2+0.99999;
        ktexp(exp1);
    ktHP(HP1);
    ktexp(exp2);
    ktHP(HP2);
        return map[m][n];
    }
    
    else {
        exp1= (float)1.12* exp1+0.99999;
        exp2= (float)1.12* exp2+0.99999;
        HP1= (float)1.1* HP1+0.99999;
        HP2= (float)1.1* HP2+0.99999;
        ktexp(exp1);
    ktHP(HP1);
    ktexp(exp2);
    ktHP(HP2);
        return Max;
    }
    
    ktexp(exp1);
    ktHP(HP1);
    ktexp(exp2);
    ktHP(HP2);
    return 0;
    

}
ktexp(exp1);
ktHP(HP1);
ktexp(exp2);
ktHP(HP2);
return -99;
}

// Task 4
int checkPassword(const char * s, const char * email)
{
    //TODO: implement task
    int n,a;
    char se[100];
    int q=0; 
    //Lấy độ dài s
    n=strlen(s);
    //Kiểm tra nếu vượt quá độ dài cho phép 
    if(n<8) return -1;
    if(n>20) return -2;
    //Gán chuỗi đằng trước kí tự @ trong email cho biến se
    for( int i=0; i< strlen(email); i++) {
        //Gán số nguyên a bằng kí tự email[i]
         a=email[i];
         if(a==64) break; //Nếu là kí tự @ thì int a = 64 thì vòng lặp dừng
         else {
            se[i]=email[i];
            q=1+q;
    }
    }
    //Kiểm tra nếu có chuỗi se trong s
    int dem=0, vitri=0, move=0, mem=0, wrong=0;
    for (int i=move ; i<q;i++) {
        for (int j=vitri; j<strlen(s);j++) {
            
            if(s[j]==se[i]) {
                dem++;
                vitri=j+1; 
                if (dem==q) mem=j-q+1;               
                break;
            }
            else {
                
                if(dem>0) {
                vitri=j-1;
                wrong ++;
                dem=0;
                i=-1;
                if(wrong>1) {
                    vitri=j;
                    wrong =0;
                }
                break;
                }              
            }
        }
    }
        if(dem==q) return -(300+mem);
    
    
    
    
    /*if (strstr(s, se) != NULL) {
        //bbbabaobi
        //012345678
        //babao
        //01234
        char *p;
        p = strstr(s, se);
        int k=0;
        k=strlen(s)-strlen(p);
        return -(300+ k);
    }
    */
//Kiểm tra có lớn hơn 2 kí tự liên tiếp có giống nhau ko
    for(int i=0; i<strlen(s)-2; i++) {
        if((s[i]==s[i+1])&&(s[i]==s[i+2])) {
            return -(400+i);
    }
    }
    int c=0;
    //Kiểm tra không nếu có kí tự @ # % ! $ 
    for(int i=0; i<strlen(s); i++) {
        int j= s[i];
        if(j==64 || j==35 || j==37 || j==33 || j==36) c=c+1;
        }
        if(c==0) return -5;
    

    //Kiểm tra các trường hợp còn lại là nếu có kí tự khác @ # % ! $ , khác a->z, khác A->Z, khác 0->9
    for(int i=0; i<strlen(s); i++) {
        int j= s[i];
        if(!((j==64 || j==35 || j==37 || j==33 || j==36) || (j>64 && j< 91)|| (j>96 && j<123)||(j>47 && j<58))) return i;
    }

    //Các hàm kiểm tra đều sai thì MK hợp lệ 
    return -10;

}
// Task 5
/*int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    
    //TODO: implement task
int cnt ;
int max =0;
int n=0;
for(int i=0;i<num_pwds; i++){
     cnt=0;
    for(int j=i+1; j<num_pwds;j++) {
        
         if(arr_pwds[i] == arr_pwds[j])  ++cnt;
    }
    if(cnt>max) {
        max = cnt;
        n=i;
    }
    if(max==cnt){ 
        int r=strlen(arr_pwds[i]);
        int l=strlen(arr_pwds[n]);
        if(r>l) n=i;  
    }
    

}
    return 0;

}*/
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {
    int cnt = 0, leng=0, rst=-1;
 if (num_pwds <= 0 || arr_pwds == nullptr) return -1; 
    for (int i = 0; i < num_pwds; ++i) {
        const char* stopwds = arr_pwds[i];
        int stoleng = std::strlen(stopwds);
        int stocnt= 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (i != j && std::strcmp(stopwds, arr_pwds[j]) == 0) stocnt++;   
        }
        if (stocnt> cnt || (stocnt== cnt && stoleng > leng)) {
            cnt = stocnt;
            leng = stoleng;
            rst= i;
        }
    }
    return rst;
}



////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////