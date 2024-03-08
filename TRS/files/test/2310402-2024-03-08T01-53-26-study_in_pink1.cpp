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
    int checkHP(int HP){
        if(HP<0) HP=0;
        else if(HP>666) HP=666;
        else;
        return HP;
    }
    int checkEXP(int EXP){
        if(EXP<0) EXP=0;
        else if(EXP>600) EXP=600;
        else;
        return EXP;
    }
    int checkM(int M){
        
        if(M<0) M=0;
        else if(M>3000) M=3000;
        else;
        return M;
    }
    double sochinhphuong(int EXP1){
        double a,b;
        double S;
        if(EXP1==0) S=0;
        else if(EXP1!=0){
        a=ceil(sqrt(EXP1));
        b=floor(sqrt(EXP1));
        if(abs(a*a-EXP1)<abs(b*b-EXP1)) S=a*a;
        else if(abs(a*a-EXP1)>abs(b*b-EXP1)) S=b*b;
        }
        return S;
    }
    bool soluong(int n) {
        if (n >= 8 && n <= 20) return true;
        else return false;
    }
    bool kitu(string s) {
        int t = 0;
        char ch[100] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
            ,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
            '@','#','%','$','!','1','2','3','4','5','6','7','8','9','0'};
        for (int i = 0; i < s.size(); i++) {
            for (int a = 0; a <= 67; a++) {
                if (s[i] == ch[a]) {
                    t++;
                    break;
                }
                else;
            }
        }
        if (t == s.size()) return true;
        else return false;
    }
    int kitu_pos(string s){
        int t = 0,dem=0,pos;
        string ch="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz@#%$!1234567890";
        for (int i = 0; i < s.size(); i++) {
            t=0;
            for (int a = 0; a < ch.size(); a++) {
                if (s[i] == ch[a]) {
                    t++;
                }
            }
            if(t==0 && dem==0){
                dem++;
                pos=i;
            } 
        }
        return pos;
    }
    bool chua_se(string s, string se) {
        string a, b;
        int t = 0, k, kq = 0, n;
        n = se.size();
        for (int i = 0; i < s.size(); i++) {
                a = s.substr(i, n);
                b = se;
                if (a == b && kq == 0) {
                    kq++;
                }
        }
        if (kq > 0) return true;
        else return false;
    }
    int tinh_sei(string s, string se) {
        string a, b;
        int t = 0, k, kq = 0, n,sei=0;
        n = se.size();
        for (int i = 0; i < s.size(); i++) {
            a = s.substr(i, n);
            b = se;
            if (a == b && kq == 0) {
                sei = i;
                kq++;
            }
        }
        return sei;
    }
    bool lientiep(string s) {
        int t = 0, r, l,k, kq = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) continue;
            else if(i!=0 && i<s.size()-1) {
                l = i - 1;
                r = i;
                k=i+1;
                if (s[l] == s[r] && s[r]==s[k]) kq++;
                else;
            }
        }
        if (kq != 0) return true;
        else return false;
    }int tinh_sci(string s) {
        int t = 0, r, l,k, kq = 0,sci=0;
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) continue;
            else if(i!=0 && i<s.size()-1) {
                l = i;
                r = i+1;
                k = i+2;
                if (s[l] == s[r] && s[r]==s[k]){
                    if (kq == 0) {
                        kq++;
                      sci = i;
                    }
                }
                else;
            }
        }  
        return sci;
    }
    bool ktdb(string s) {
        int t = 0;
        string ch="@#%$!";
        for (int i = 0; i < s.size(); i++) {
            for (int a = 0; a < 5; a++)
                if (s[i] == ch[a]) t++;
        }
        if (t > 0) return true;
        else return false;
    }
    int length(const char* pwds) {
        string s(pwds);
        int t = 0;
        char ch[100] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'
            ,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
            '@','#','%','$','!','1','2','3','4','5','6','7','8','9','0' };
        for (int i = 0; i < s.size(); i++) {
            for (int a = 0; a <= 67; a++) {
                if (s[i] == ch[a]) {
                    t++;
                    break;
                }
                else;
            }
        }
        return t;
    }
    //Task 1
    int firstMeet(int & exp1, int & exp2, int e1){ 
        exp1=checkEXP(exp1);
        exp2=checkEXP(exp2);
        double EXP1=exp1, EXP2=exp2, E1=e1;
        if(e1<0 || e1>99) return -99;
        if(e1>=0 && e1<=99){
        if(e1>=0 && e1<=3){
        if(E1==0) EXP2+=29;
        else if(E1==1) EXP2+=45;
        else if(E1==2) EXP2+=75;
        else if(E1==3) EXP2+=29+45+75;
        int d=E1*3+exp1*7;
        double D=d;
        if(d%2==0){
                EXP1=ceil(EXP1+D/200);
        }
        else if(d%2!=0){
                EXP1=ceil(EXP1-D/100);
        }
        EXP1=checkEXP(EXP1);
        EXP2=checkEXP(EXP2);
        exp1=EXP1;
        exp2=EXP2;
        }
        if(E1>=4 && E1<=99){
            if(E1>=4 && E1<=19) EXP2=ceil(EXP2+E1/4+19);
            else if (E1>=20 && E1<=49) EXP2=ceil(EXP2+E1/9+21);
            else if (E1>=50 && E1<=65) EXP2=ceil(EXP2+E1/16+17);
            else if (E1>=66 && E1<=79){
                EXP2=ceil(EXP2+E1/4+19);
                if(EXP2>200) EXP2=ceil(EXP2+E1/9+21);
            }
            else if (E1>=80 && E1<=99){
                EXP2=ceil(EXP2 + E1/4+19);
                EXP2=ceil(EXP2+ E1/9+21);
                if(EXP2 > 400){
                    EXP2=ceil(EXP2+E1/16+17);
                    EXP2=ceil(EXP2*1.15);
                }
                else;
            }
            EXP1-=E1;
            EXP1=checkEXP(EXP1);
            EXP2=checkEXP(EXP2);
            exp1=EXP1;
            exp2=EXP2;
        }
        }
        return exp1 + exp2;
    }
    // Task 2

    int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
        int pay=0,e2;
        double S,mang[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11},hp1=HP1, exp1=EXP1,m1=M1,P1,P2,P3,P;
        if(E2<0 || E2>99) return -99;
        else if(E2>=0 && E2<=99){
        //Con duong 01
        S=sochinhphuong(EXP1);
        //<<"S1= "<<S<<endl;
        if(EXP1>=S) P1=1;
        else if(EXP1<S) P1=((exp1/S)+80)/123;
        //<<"P1: "<<P1<<endl;
        //Con duong 02
        if(E2%2!=0){
            while(pay<=m1/2){
                if(hp1<200){
                    hp1=ceil(hp1*130/100);
                    pay+=150;
                }
                else if(hp1>=200){
                    hp1=ceil(hp1*110/100);
                    pay+=70;
                }
                hp1=checkHP(hp1);
                //<<hp1<<"-"<<pay<<endl;
                if(pay<=m1/2){
                    if(exp1<400) pay+=200;
                    else if(exp1>=400) pay+=120;
                    exp1=ceil(exp1*113/100);
                    exp1=checkEXP(exp1);
                    //<<exp1<<"-"<<pay<<endl;
                }
                if(pay<=m1/2){
                        if(exp1<300) pay+=100;
                        if(exp1>=300) pay+=120;
                        exp1=ceil(exp1*90/100);
                        exp1=checkEXP(exp1);
                        //<<exp1<<"-"<<pay<<endl;
                }
            }
        }
        if(E2%2==0){
                if(hp1<200){
                    hp1=ceil(hp1*1.3);
                    pay+=150;
                }
                else if(hp1>=200){
                    hp1=ceil(hp1*110/100);
                    pay+=70;
                }
                hp1=checkHP(hp1);
                //<<hp1<<endl;
                if(pay<m1){
                    if(exp1<400) pay+=200;
                    else if(exp1>=400) pay+=120;
                    exp1=ceil(exp1*113/100);
                    exp1=checkEXP(exp1);
                }
                if(pay<m1){
                    if(exp1<300) pay+=100;
                    if(exp1>=300) pay+=120;
                    exp1=ceil(exp1*90/100);
                    exp1=checkEXP(exp1);
            }
            }
            //<<hp1<<"---"<<exp1<<endl;
            hp1=ceil(hp1*83/100);
            exp1=ceil(exp1*117/100);
            exp1=checkEXP(exp1);
            hp1=checkHP(hp1);
            S=sochinhphuong(exp1);
            //<<"S2= "<<S<<endl;
            //<<hp1<<"---"<<exp1<<endl;
            if(exp1>=S) P2=1;
            else if(exp1<S) P2=((exp1/S)+80)/123;
            //<<"P2: "<<P2<<endl;
            //Con duong 03
            if(E2<10) P3=mang[E2]/100;
            else if(E2>=10){
                e2=(E2/10+E2%10)%10;
                //<<e2<<"{}"<<endl;
                P3=mang[e2]/100;
            }
            //<<"P3= "<<P3<<endl;
            P=(P1+P2+P3)/3;
            if(P==1) exp1=ceil(exp1*75/100);
            else if(P!=1){
                //<<P<<endl;
                if(P<0.5){
                    hp1=ceil(hp1*85/100);
                    exp1=ceil(exp1*115/100);
                }
                else if(P>=0.5){
                    hp1=ceil(hp1*90/100);
                    exp1=ceil(exp1*120/100);
                }
            }
            //<<hp1<<" "<<exp1<<endl;
            hp1=checkHP(hp1);
            exp1=checkEXP(exp1);
            HP1=hp1;
            EXP1=exp1;
            M1=checkM(M1-pay);
        }
        return HP1 + EXP1 + M1;
    }
    //Task 3
    int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
        int taxi[10][10] = {}, SW[10][10] = {},so_duong = 0, so_am = 0, a, b, max_cheophai, max_cheotrai,maxf;
        double hp1 = HP1, exp1 = EXP1, hp2 = HP2, exp2 = EXP2;
        if(E3<0||E3>99) return -99;
        else if(E3>=0&&E3<=99){
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                taxi[i][j] = ((E3 * j) + (i * 2)) * (i - j);
                if (taxi[i][j] > E3 * 2) so_duong++;
                else if (taxi[i][j] < -E3) so_am++;
            }
        }
        while (so_duong >= 10) so_duong = so_duong / 10 + so_duong % 10;
        while (so_am >= 10) so_am = so_am / 10 + so_am % 10;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                max_cheotrai = 0;
                max_cheophai = 0;
                //cheophai_xuong
                a = i;
                b = j;
                while (a >= 0 && b >= 0 && a<10 && b<10) {
                    if (taxi[a][b] > max_cheophai)
                        max_cheophai = taxi[a][b];
                    a++;
                    b--;
                }
                //cheophai_len
                a = i;
                b = j;
                while (a >= 0 && b >= 0 && a < 10 && b < 10) {
                    if (taxi[a][b] > max_cheophai)
                        max_cheophai = taxi[a][b];
                    a--;
                    b++;
                }
                //cheotrai_len
                a = i;
                b = j;
                while (a >= 0 && b >= 0 && a < 10 && b < 10) {
                    if (taxi[a][b] > max_cheotrai)
                        max_cheotrai = taxi[a][b];
                    a--;
                    b--;
                }
                //cheophai_len
                a = i;
                b = j;
                while (a >= 0 && b >= 0 && a < 10 && b < 10) {
                    if (taxi[a][b] > max_cheotrai)
                        max_cheotrai = taxi[a][b];
                    a++;
                    b++;
                }
                SW[i][j] = max(max_cheophai, max_cheotrai);
            }
        }
        if (abs(taxi[so_duong][so_am]) > SW[so_duong][so_am]) {
            maxf = taxi[so_duong][so_am];
            exp1 = checkEXP(ceil(exp1 * 88/100));
            hp1 = checkHP(ceil(hp1 * 90/100));
            exp2 = checkEXP(ceil(exp2 * 88/100));
            hp2 = checkHP(ceil(hp2 * 90/100));
        }
        else if (abs(taxi[so_duong][so_am]) <= SW[so_duong][so_am]) {
            maxf = SW[so_duong][so_am];
            exp1 = checkEXP(ceil(exp1 * 112/100));
            hp1 = checkHP(ceil(hp1 * 110/100));
            exp2 = checkEXP(ceil(exp2 * 112/100));
            hp2 = checkHP(ceil(hp2 * 110/100));
        }
        HP1=hp1;
        HP2=hp2;
        EXP1=exp1;
        EXP2=exp2;
        }
        return maxf;
    }

    // Task 4
    int checkPassword(const char * S, const char * EMAIL) {
    string email(EMAIL);
    string s(S);
    string se="";
    int n = s.size(), k = 0,kq=0, sei = 0, sci;
    for (int i = 0; i < email.size(); i++) {
        if (email[i] != '@')
           se+=email[i];
        else if(email[i]=='@')
            break;
    }
    if(!kitu(s))
    kq=kitu_pos(s);
    if(!ktdb(s)) kq=-5;
    if(lientiep(s)){
        sci=tinh_sci(s);
        kq=-(400+sci);
    }
    if(chua_se(s,se)){
        sei=tinh_sei(s,se);
        kq=-(300+sei);
    }
    if(n>20) kq=-2;
    if(n<8) kq=-1;
    if(soluong(n) && kitu(s) && !chua_se(s,se) && !lientiep(s) && ktdb(s)) kq=-10;
    return kq;
    }
    // Task 5
    int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
        char* ch[30] = {};
        int	mang[30]={}, pos[30][30] = {}, pos_max = 0, k = 0, s = 0, max, max_len = 0;
        //<<endl<<num_pwds<<"-"<<pos_max<<endl;
        for (int i = 0; i < num_pwds; i++){
        //<<arr_pwds[i]<<" ";
        mang[i] = 1;
        }
        //<<endl<<"---"<<endl;
        for (int i = 0; i < num_pwds; i++){
            for(int a=i+1;a<num_pwds;a++){
                string t=arr_pwds[i], c=arr_pwds[a];
                if(t==c && mang[i]!=0){
                    mang[i]++;
                    mang[a]=0;
                }
            }
        }
        max=mang[0];
        for (int i = 0; i < num_pwds; i++){
            //<<mang[i]<<" ";
            if(mang[i]>max) max=mang[i];
        };
        //<<endl;
        for (int i = 0; i < num_pwds; i++){
            if(mang[i]==max){
                pos[0][k]=i;
                pos[1][k]=strlen(arr_pwds[i]);
                //<<pos[0][k]<<"---"<<pos[1][k]<<" ";
                k++;
            }
        }
        //<<"k= "<<k<<endl;
        //<<endl;
        if(k==1) pos_max=pos[0][0];
        else if(k!=1){
            //<<"true"<<endl;
            max_len=pos[1][0];
            for(int i = 0;i<k;i++){
                if(pos[1][i]>max_len)
                    max_len=pos[1][i];
                else if(pos[1][i]<max_len)
                    max_len=max_len;
            }
            for(int i = 0;i<k;i++){
                if(pos[1][i]==max_len){
                    pos_max=pos[0][i];
                    break;
                }
            }
            //<<max_len<<endl;
        }
        //<<pos_max<<"<>"<<endl;
        return pos_max;
    }

    ////////////////////////////////////////////////
    /// END OF STUDENT'S ANSWER
    ////////////////////////////////////////////////