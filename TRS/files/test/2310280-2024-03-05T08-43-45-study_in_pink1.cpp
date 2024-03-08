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
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    /*172␣172
          400␣300
          450␣450
          3␣1␣0*/
         // %%
    if(e1>99||e1<0) return -99;
              else switch(e1){
                  
                  case 0:
                  exp2+=29;
                      if((e1 * 3 + exp1 * 7)%2) exp1=ceil(exp1-(e1 * 3 + exp1 * 7)*1.0/100);
                  else exp1=ceil(exp1+(e1 * 3 + exp1 * 7)*1.0/200);
                  break;
                  
                  case 1:
                  exp2+=45;
                      if((e1 * 3 + exp1 * 7)%2) exp1=ceil(exp1-(e1 * 3 + exp1 * 7)*1.0/100);
                  else exp1=ceil(exp1+(e1 * 3 + exp1 * 7)*1.0/200);
                  break;
                  
                  case 2:
                  exp2+=75;
                      if((e1 * 3 + exp1 * 7)%2) exp1=ceil(exp1-(e1 * 3 + exp1 * 7)*1.0/100);
                  else exp1=ceil(exp1+(e1 * 3 + exp1 * 7)*1.0/200);
                  break;
                  
                  case 3:
                  exp2+=(29+45+75);
                  if((e1 * 3 + exp1 * 7)%2) exp1=ceil(exp1-(e1 * 3 + exp1 * 7)*1.0/100);
                  else exp1=ceil(exp1+(e1 * 3 + exp1 * 7)*1.0/200);
                  break;
                  
                  default:
           //thông tin 1
                   if(e1>=4&&e1<=19){
                                   exp2=ceil(exp2+(e1*1.0 /4 + 19));
                  }
                  //thông tin 2
                   else if(e1<=49){
                                   exp2=ceil(exp2+(e1*1.0 /9 + 21));
                  }
           //thông tin 3
                                   else if(e1<=65){
                                                   exp2=ceil(exp2+(e1*1.0 /16 + 17));
                                   }
           //thông tin 1 thoả exp2 thì + Thông tin 2
                                                   else if(e1<=79){
                                                                   exp2=ceil(exp2+(e1*1.0 /4 + 19));
                                                                   if(exp2>200)  {exp2=ceil(exp2+(e1*1.0 /9 + 21));}
                                                   }
           //thông tin 1+ thông tin 2 nếu exp2 thoả + Thông tin 3
                                                                   else {
                                                                       exp2=ceil(exp2+(e1*1.0 /4 + 19));
                                                                       exp2=ceil(exp2+(e1*1.0 /9 + 21));
                                                                       if(exp2>400) {
                                                                                   exp2=ceil(exp2+(e1*1.0 /16 + 17));
                                                                                   exp2=ceil(exp2*1.15);
                                                                       }
                                                                   }
               exp1-=e1;
              }
           
           
           
           if(exp1<0) exp1=0;
           if(exp2<0) exp2=0;
           if(exp2>600) exp2=600;
           if(exp1>600) exp1=600;
    //end
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    //thiết lập lại input
    
    if(EXP1<0) EXP1=0;
            if(HP1<0) HP1=0;
            if(HP1>666) HP1=666;
            if(EXP1>600) EXP1=600;
                //xét điều kiện vật chứng
            if(E3>99||E3<0) return -99;
            else{
            float P1,P2,P3,M1_bd=M1;

            //con đường 01
            if(abs(pow(int(sqrt(EXP1)+1),2)-EXP1)>abs(pow(int(sqrt(EXP1)),2)-EXP1))
            P1=1;
            else P1=(EXP1/pow(int(sqrt(EXP1)+1),2)+80)/123;
            //con đường 02
            do{
                //bổ sung sinh lực
            if(HP1 < 200) {HP1=(0.999+1.3*HP1);  M1-=150;}
                else { HP1=(0.999+HP1*1.1);    M1-=70;}
                //thiết lập lại
            if(HP1<0) HP1=0;
            if(HP1>666) HP1=666;
            //điều kiện thoát
            if(M1<=0) {M1=0; break;}
            if((E3%2==1)&&M1<(M1_bd*0.5)) break;

                //chọn phương tiện
            if(EXP1<400) M1-=200;
                else M1-=120;
            EXP1=(0.999+1.13*EXP1);
            //thiết lập lại
               if(EXP1<0) EXP1=0;
               if(EXP1>600) EXP1=600;
               
            //điều kiện thoát
            if(M1<=0) {M1=0; break;}
            if((E3%2==1)&&M1<(M1_bd*0.5)) break;

                //manh mối tình nghi?
            if(EXP1<300) M1-=100;
                else M1-=120;
            EXP1=(0.999+0.9*EXP1);
            //thiết lập lại
            if(EXP1<0) EXP1=0;
            if(EXP1>600) EXP1=600;
            //điều kiện thoát
            if(M1<=0) {M1=0; break;}
            if((E3%2==1)&&M1<(M1_bd*0.5)) break;
            }
            while((E3%2==1)&&M1>=(M1_bd*0.5));
            EXP1=(0.999+EXP1*1.17);
            HP1=(0.999+HP1*0.83);
            //thiết lập lại
            if(EXP1<0) EXP1=0;
            if(HP1<0) HP1=0;
            if(HP1>666) HP1=666;
            if(EXP1>600) EXP1=600;
            //xét P2
            if(abs(pow(int(sqrt(EXP1)+1),2)-EXP1)>abs(pow(int(sqrt(EXP1)),2)-EXP1))
            P2=1;
            else P2=(EXP1/pow(int(sqrt(EXP1)+1),2)+80)/123;
            //con đường 03
            int P[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11} ;
            P3=P[(E3%10+E3/10)%10]*1.0/100;
        if(P1+P2+P3==3) {EXP1=(0.999+EXP1*0.75);}
            else if(P1+P2+P3<1.5) {
                HP1=(0.999+HP1*0.85);
                EXP1=(0.999+EXP1*1.15);
            }
            else{
                HP1=(0.999+HP1*0.9);
                EXP1=(0.999+EXP1*1.2);
            }
            if(EXP1<0) EXP1=0;
            if(HP1<0) HP1=0;
            if(HP1>666) HP1=666;
            if(EXP1>600) EXP1=600;
        }
    // TODO: Complete this function

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    long double matrix[10][10];
        if(E3<0||E3>99) return -99;
        else{
        int count_x=0,count_y=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                matrix[i][j]=(E3*j+i*2)*(i-j);
                    if(matrix[i][j]>(E3*2)) count_x+=1;
                    if(matrix[i][j]<(-E3)) count_y+=1;
            }
        }
    int i,j,
        mtr_x=(count_x)/10+count_x%10,
        mtr_y=(count_y)/10+count_y%10, max_point=matrix[mtr_x][mtr_y];
        mtr_x=mtr_x/10+mtr_x%10;
        mtr_y=mtr_y/10+mtr_y%10;
    int hieu=mtr_x-mtr_y,
        tong=mtr_x+mtr_y;
        // tăng i và j
        if(hieu<0) {i=0;    j=abs(hieu);}
            else {i=hieu;   j=0;}
do{
        if(max_point<matrix[i][j]) max_point=int(matrix[i][j]);
        i+=1;
        j+=1;
    }
    while((i!=9)&&(j!=9)&&(i!=10)&&(j!=10));
       // giảm i tăng j
       if(tong<9)   {i=tong;    j=0;}
            else    {i=9;       j=tong-9;}
        do{
            if(max_point<matrix[i][j]) max_point=int(matrix[i][j]);
            i--;
            j++;
        }
            while((i!=0)&&(j!=9)&&(i!=-1)&&(j!=10));
if(abs(max_point)>=abs(matrix[mtr_x][mtr_y])){
        EXP1 = 0.999+EXP1 * 1.12    ;
        HP1  = 0.999+HP1  * 1.1       ;
        EXP2 = 0.999+EXP2 * 1.12    ;
        HP2  = 0.999+HP2  * 1.1       ;
    if(EXP1<0) EXP1=0;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(EXP1>600) EXP1=600;
    if(EXP2<0) EXP2=0;
    if(HP2<0) HP2=0;
    if(HP2>666) HP2=666;
    if(EXP2>600) EXP2=600;
        return max_point;
}
else {
        EXP1 = 0.999+EXP1 * 0.88    ;
        HP1  = 0.999+HP1  * 0.9       ;
        EXP2 = 0.999+EXP2 * 0.88    ;
        HP2  = 0.999+HP2  * 0.9       ;
    if(EXP1<0) EXP1=0;
    if(HP1<0) HP1=0;
    if(HP1>666) HP1=666;
    if(EXP1>600) EXP1=600;
    if(EXP2<0) EXP2=0;
    if(HP2<0) HP2=0;
    if(HP2>666) HP2=666;
    if(EXP2>600) EXP2=600;
        return matrix[mtr_x][mtr_y];
}
        }
   // return -1;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    string S=string(s),Email=string(email);
    int i=Email.find('@',0),    checker=0,  dem_kt=0;
    string se=Email.substr(0,i);
    // kiểm tra độ dài xâu
    if(S.length()<=20&&S.length()>=8)
    {
        // kiểm tra xâu con
        if(S.find(se,0)<S.length())
            return -(300+int(S.find(se,0)));
        else{
            //quét xâu
            for(int j=0;j<S.length();j++){
                //kiểm tra kt liên tiếp
                if(j!=S.length()-1)
                {if (checker==0&&S[j]==S[j+1]) checker++;
                else if(checker==1&&S[j]==S[j+1]) {return -(400+j-1);  break;}
                else checker=0;
                }
                //đếm kt đặc biệt
                if((S[j]==33)||S[j]==35||S[j]==36||S[j]==37||(S[j]==64))    {dem_kt ++;}
            }
                if(dem_kt==0) return -5;
            for(int j=0;j<S.length();j++)
            {if(!((S[j]==33)||S[j]==35||S[j]==36||S[j]==37||(S[j]==64)||
                  
                  (S[j]>=48&&S[j]<=57)||(S[j]>=65&&S[j]<=90)||(S[j]>=97&&S[j]<=122)))
             {return j; break;}}
        }
    }
    else if(S.length()>20) return -2;
    else {return -1;}
    return -10;
    // TODO: Complete this function

}
// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    string key[50],Arr_pwds[num_pwds];
    //nhập vào mảng xâu
            for(int i=0;i<num_pwds;i++){
                if(arr_pwds==NULL) break;
                Arr_pwds[i]=arr_pwds[i];
            }
    double cont[50],pos[50];
    //
    int j=0;
    int sl_mk_ref=0;
    //quét hai mảng
        while(sl_mk_ref!=num_pwds){
            for(int i=0;i<num_pwds;i++){
                if(Arr_pwds[i].find("Dummy")!=0&&key[j].length()==0)
                {
                    key[j]=Arr_pwds[i];
                    pos[j]=i;
                    cont[j]+=1;
                    Arr_pwds[i].insert(0,"Dummy");
                    sl_mk_ref++;
                }
                else if(Arr_pwds[i].find("Dummy")==0) continue;
                else if(Arr_pwds[i]==key[j]){
                    cont[j]+=1;
                    Arr_pwds[i].insert(0,"Dummy");
                    sl_mk_ref++;
                }
            }
            j++;
            
        }
        // phần xử lý số liệu cuối
   /* for (j=0;key[j].length()!=0;j++){
        cout<<key[j]<<'\t'<<cont[j]<<endl;
    }*/
    int vi_tri_trong_key=0;
    for (j=0;key[j].length()!=0;j++){
        if(cont[j]>cont[vi_tri_trong_key])
        {vi_tri_trong_key=j;}
        else if((key[vi_tri_trong_key].length()<key[j].length())&&cont[j]==cont[vi_tri_trong_key])
        vi_tri_trong_key=j;
    }
    return pos[vi_tri_trong_key];
    
    // TODO: Complete this function
    //return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
