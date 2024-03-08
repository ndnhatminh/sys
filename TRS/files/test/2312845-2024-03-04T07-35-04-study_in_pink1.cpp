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

//! Task 1
int firstMeet(int &EXP1, int &EXP2, int E1)
{
if (E1 < 0 || E1 > 99) return -99;
    //------Truong hop 1-------
    if(E1<=3){
      int arr[]={29,45,75,29+45+75};
      EXP2=EXP2+arr[E1];
      int D=E1*3+EXP1*7;
      if(D%2) EXP1=ceil(EXP1-(1.0*D/100));
      else EXP1=ceil(EXP1+(1.0*D/200));
      if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
    if(EXP2>600) EXP2=600;
    if(EXP2<0) EXP2=0;
    //------ Truong hop 2---------
    } else if(E1<=99){ 
        EXP1=EXP1-E1;
        if(E1<=65){
        EXP2=ceil((E1<=19)*(EXP2+(1.0*E1/4+19))+(E1>=20&&E1<=49)*(EXP2+(1.0*E1/9+21))+(E1>=50&&E1<=65)*(EXP2+(1.0*E1/16+17)));
    }else if(E1<=79){
        EXP2=ceil(EXP2+(1.0*E1/4+19));
        if(EXP2>200) EXP2=ceil(EXP2+(1.0*E1/9+21));
    }else 
    {
        EXP2=ceil(EXP2+(1.0*E1/4+19));
        EXP2=ceil(EXP2+(1.0*E1/9+21));
    if(EXP2>400) {EXP2=ceil(EXP2+(1.0*E1/16+17));
     EXP2=ceil(EXP2*1.15);
    }
    }
    }
    if(EXP1>600) EXP1=600;
    if(EXP1<0) EXP1=0;
    if(EXP2>600) EXP2=600;
    if(EXP2<0) EXP2=0;

    return EXP1 + EXP2;
    
}
// task 2
int Find_S(int EXP1){
    float S=sqrt(EXP1);
    S=round(S)*round(S);
    return S;}
int traceLuggage(int &HP1, int &EXP1, int &M1, int E2)
{

    if (E2 > 99 || E2 < 0)
        return -99;
        //--------CON DUONG 1------------
    int S=Find_S(EXP1);
    float p1=0;
    if(EXP1>=S) p1=1;
    else p1=(1.0*EXP1/S+80)*1.0/123;
    // --------------CON DUONG 2------------
    float p2=0;
    if(E2%2){
        float m=5.0/10*M1;
        while((M1>=m)&&(M1!=0)){
            M1=(HP1<200)*(M1-150)+(HP1>=200)*(M1-70);
            HP1=(HP1<200)*ceil(HP1*13.0/10)+(HP1>=200)*ceil(HP1*11.0/10);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
            
            if(M1<m) break;
            M1=(EXP1<400)*(M1-200)+(EXP1>=400)*(M1-120);
            EXP1=ceil(113.0/100*EXP1);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
            if(M1<m) break;
            M1=(EXP1<300)*(M1-100)+(EXP1>=300)*(M1-120);
            EXP1=ceil(9.0/10*EXP1);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
            if(M1<m) break;
        }
        HP1=ceil(HP1*83.0/100);
        EXP1=ceil(117.0/100*EXP1);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
         S=Find_S(EXP1);
    
    if(EXP1>=S) p2=1;
    else p2=(1.0*EXP1/S+80)*1.0/123;
    } else {
        if(M1>0){
           M1=(HP1<200)*(M1-150)+(HP1>=200)*(M1-70); 
           HP1=(HP1<200)*ceil(HP1*13.0/10)+(HP1>=200)*ceil(HP1*11.0/10);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;    
        }
        if(M1>0){
           M1=(EXP1<400)*(M1-200)+(EXP1>=400)*(M1-120);
           EXP1=ceil(113.0/100*EXP1);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
        }
        if(M1>0){
           M1=(EXP1<300)*(M1-100)+(EXP1>=300)*(M1-120);
           EXP1=ceil(9.0/10*EXP1);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
        }
        HP1=ceil(HP1*0.83);
        EXP1=ceil(117.0/100*EXP1);
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
         S=Find_S(EXP1);
         
    if(EXP1>=S) p2=1;
    else p2=(1.0*EXP1/S+80)*1.0/123;
    }
    //---------- CON DUONG 3---------------
    float p3=0;
    int i=0;
    int p[]={32,47,28,79,100,50,22,83,64,11};
    if(E2<10) p3=p[E2]*1.0/100;
    else {i=((E2%10)+(E2-(E2%10))/10)%10;
    p3=p[i]*1.0/100;
    }
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
    if(p1==p2==p3==1) EXP1=ceil(EXP1*75.0/100);
    else{
        float p_trungbinh=(p1+p2+p3)*1.0/3;
        HP1=(p_trungbinh<(5.0/10))*ceil(HP1*85.0/100)+(p_trungbinh>=(5.0/10))*ceil(HP1*9.0/10);
        EXP1=(p_trungbinh<(5.0/10))*ceil(115.0/100*EXP1)+(p_trungbinh>=(5.0/10))*ceil(12.0/10*EXP1);
    }
    if(EXP1<0) EXP1=0;
    if(EXP1>600) EXP1=600;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(M1<0) M1=0;
    if(M1>3000) M1=3000;
    return EXP1+HP1+M1;
}

int chaseTaxi(int &HP1, int &EXP1, int &HP2, int &EXP2, int E3)
{
    if((E3<0)||(E3>99))
    return -99;
    int map[10][10]={0};
    int so_lon=0;
    int so_be=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            map[i][j]=((E3*j)+(i*2))*(i-j);
            if(map[i][j]>(E3*2)) so_lon+=1;
            if(map[i][j]<(-E3)) so_be+=1;
        }
    }
    //---------------- tim vi tri gap nhau------------------
    int hang_gap_nhau=0;
    int cot_gap_nhau=0;
    while(so_lon>9){
        so_lon=(so_lon%10)+(so_lon/10);

    }
    hang_gap_nhau=so_lon;
    while(so_be>9){
        so_be=(so_be%10)+(so_be/10);

    }
    cot_gap_nhau=so_be;
    int max_score=map[hang_gap_nhau][cot_gap_nhau];
    // tim score cua sherlock------------
    //huong cheo 1-------------------
    int j=cot_gap_nhau;
    for(int i=hang_gap_nhau;i<10;i++){
        if(((i>=0)&&(i<=9))&&((j>=0)&&(j<=9))){
            if(map[i][j]>max_score) max_score=map[i][j];
        } else break;
        j++;
    }
    
    //huong cheo 2---------------------
    int q=cot_gap_nhau;
    for(int i=hang_gap_nhau;i<10;i++){
        if(((i>=0)&&(i<=9))&&((q>=0)&&(q<=9))){
            if(map[i][q]>max_score) max_score=map[i][q];
        } else break;
        q--;
    }
   
    //huong cheo 3------------------------
    int k=cot_gap_nhau;
    for(int i=hang_gap_nhau;i>=0;i--){
        if(((i>=0)&&(i<=9))&&((k>=0)&&(k<=9))){
            if(map[i][k]>max_score) max_score=map[i][k];
        } else break;
        k--;
    }
   if(max_score<0) max_score=abs(max_score);
   //huong cheo 4 -----------------
   int x=cot_gap_nhau;
    for(int i=hang_gap_nhau;i>=0;i--){
        if(((i>=0)&&(i<=9))&&((x>=0)&&(x<=9))){
            if(map[i][x]>max_score) max_score=map[i][x];
        } else break;
        x++;
    }
   if(max_score<0) max_score=abs(max_score);
   if(abs(map[hang_gap_nhau][cot_gap_nhau])>max_score){
      
      EXP1=ceil(EXP1*88.0/100);
      EXP2=ceil(EXP2*88.0/100);
      HP1=ceil(HP1*9.0/10);
      HP2=ceil(HP2*9.0/10);
      if(EXP1<0) EXP1=0;
  if(EXP1>600) EXP1=600; 
  if(EXP2<0) EXP2=0;
  if(EXP2>600) EXP2=600; 
  if(HP1<0) HP1=0;
  if(HP1>666) HP1=666;
  if(HP2<0) HP2=0;
  if(HP2>666) HP2=666;
      return map[hang_gap_nhau][cot_gap_nhau];
   }
else{
    
    EXP1=ceil(EXP1*112.0/100);
      EXP2=ceil(EXP2*112.0/100);
      HP1=ceil(HP1*11.0/10);
      HP2=ceil(HP2*11.0/10);
      if(EXP1<0) EXP1=0;
  if(EXP1>600) EXP1=600; 
  if(EXP2<0) EXP2=0;
  if(EXP2>600) EXP2=600; 
  if(HP1<0) HP1=0;
  if(HP1>666) HP1=666;
  if(HP2<0) HP2=0;
  if(HP2>666) HP2=666;
    return max_score;
}
  
}

int checkPassword(const char *s, const char *email)
{
    char se[101];
    int count=0;
    for(count;email[count]!='@';count++){
        se[count]=email[count];
    }
    se[count]='\0';
    int so_ki_tu_cua_s=0;
    for(int i=0;s[i]!='\0';i++){
       so_ki_tu_cua_s+=1;
    }
    // dieu kien 1
    if(so_ki_tu_cua_s<8) return -1;
    // dieu kien 2
    if(so_ki_tu_cua_s>20) return -2;
    // dieu kien 3
    const char* ketqua=strstr(s,se);
    if(ketqua!= nullptr) {
        int sei= ketqua-s;
        return -(300+sei);
    }
    if(se[0]=='\0') return -300;
   // dieu kien 4
   for(int i=0;s[i]!='\0';i++){
    if((s[i]==s[i+1])&&(s[i]==s[i+2])) {
        return -(400+i);
        break; 
   } else continue;
   }
   // dieu kien 5
   
   for(int i=0;s[i]!='\0';i++){
    if(s[i]=='@'||s[i]=='#'||s[i]=='%'||s[i]=='$'||s[i]=='!'){
        break;
    } else if(i==(so_ki_tu_cua_s-1)) return -5;
    
   }
   // dieu kien 6
    for(int i=0;s[i]!='\0';i++){
       if(((s[i]>='0')&&(s[i]<='9'))||((s[i]>='a')&&(s[i]<='z'))||((s[i]>='A')&&(s[i]<='Z'))||(s[i]=='@')||(s[i]=='!')||((s[i]>='#')&&(s[i]<='%')))
       continue;
       else return i;
   }   
   return -10;
}

int findCorrectPassword(const char *arr_pwds[], int num_pwds)
{
    int vi_tri=0,tan_suat=1,max=0,so_luong_ki_tu=0;
    for(int i=0;i<num_pwds;i++){
        tan_suat=1;
        for(int j=i+1;j<num_pwds;j++){
            if(strcmp(arr_pwds[i],arr_pwds[j])==0){
                tan_suat+=1;
            }
        }

        if(tan_suat>max){
        max=tan_suat;
        vi_tri=i;
        so_luong_ki_tu=strlen(arr_pwds[vi_tri]);
    } else if(tan_suat==max){
        if(strlen(arr_pwds[i])>strlen(arr_pwds[vi_tri])){
            vi_tri=i;
            so_luong_ki_tu=strlen(arr_pwds[vi_tri]);
        }
    }
    
}
return vi_tri;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////