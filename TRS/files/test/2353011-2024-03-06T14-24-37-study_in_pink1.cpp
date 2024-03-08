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
int exp(int & exp1, int & exp2) {
        if (exp1 > 600 || exp2 > 600) {
            return 600;
        } else if (exp1 < 0 || exp2 < 0) {
            return 0;
        } else {
            return exp1;
        } 
    } 
int e1(int & e1) {
         if (e1 < 0 || e1 > 99) {
        return -99;
    } else {
        return e1; 
    } 
}
int firstMeet(int & exp1, int & exp2, int e1) {
    if (e1 >= 0 && e1 <= 99) {
    if (e1>=0 && e1<=3){
        exp1=exp(exp1, exp1);
        exp2=exp(exp2, exp2);        
	switch(e1) {
    	case 0:
    		exp2+=29;
    		break;
    	case 1:
    		exp2+=45;
    		break;
    	case 2:
    		exp2+=75;
    		break;
    	case 3:
    		exp2+=29+45+75;
    		break;
	}
	int D = e1 * 3 + exp1 * 7;
    if (D%2==0)
    {
    	exp1=ceil(float(exp1) + ceil(D)/200);
        exp1=exp(exp1, exp1);
        exp2=exp(exp2, exp2);
    }
    else {
    	exp1 = ceil(float(exp1) - ceil(D)/100);
        exp1=exp(exp1, exp1);
        exp2=exp(exp2, exp2);
	}
 ;}
   else {
    if (e1 >=4 && e1 <= 19 ){
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2);         
        exp2 = exp2 + (ceil(double(e1)/4) + 19);
        exp1 = exp1 -  e1;
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2);
        return exp1 + exp2;
    } 
    else { if (e1 >=20 && e1 <= 49 ){
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2);       
        exp2 = exp2 + (ceil(double(e1)/9) + 21);
        exp1 = exp1 - e1;       
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2);
        return exp1 + exp2;
    } else { if (e1 >=50 && e1 <= 65 ){
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2); 
        exp2 = exp2 + (ceil(double(e1)/16) + 17);
        exp1 = exp1 - e1;
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2);
        } else { if (e1 >=66 && e1 <= 79 ){
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2); 
            exp2 = exp2 + (ceil(double(e1)/4) + 19);
                 if (exp2 >200) {
                 exp2 = exp2 + (ceil(double(e1)/9) + 21);
        exp1=exp(exp1, exp1);
        exp2=exp(exp2, exp2);
                 }
        exp1 = exp1 - e1;
    exp1=exp(exp1, exp1);
    exp2=exp(exp2, exp2);;}
         else { if (e1 >=80 && e1 <= 99 ){        
        exp1=exp(exp1, exp1);
        exp2=exp(exp2, exp2);
        exp2 = exp2 + (ceil(double(e1)/4) + 19) + (ceil(double(e1)/9) + 21);
                 if (exp2 >400) {
                 exp2 = ceil((exp2 + (ceil(double(e1)/16) + 17))*1.15);
        exp1=exp(exp1, exp1);
        exp2=exp(exp2, exp2);
                 }
        exp1 = exp1 - e1;
        exp1=exp(exp1, exp1);
        exp2=exp(exp2, exp2);                 
        }}}
}}}return exp1 + exp2;} else {return -99;} }

// Task 2
int e2(int & e2) {
         if (e2 < 0 || e2 > 99) {
        return -99;
    } else {
        return e2; 
    } 
}
int hp(int & hp1, int & hp2) {
    if (hp1>666 || hp2>666) {
        return 666;
    } else if (hp1 <0 || hp2 < 0) { 
        return 0;
    } else { return hp1;}
}
int m(int & m1, int & m2) {
    if (m1>3000 || m2>3000) {
        return 3000;
    } else if (m1<0 || m2<0) { 
        return 0;
    } else { return m1;}
}
int soCP(int exp1) {
    int CPgannhat = 0;
    int chenhlechNN = INT_MAX; 
    for (int i = 0; i <=600 ; ++i) {
        int binhphuong = i * i;
        int chenhlech = abs(exp1 - binhphuong);
        if (chenhlech < chenhlechNN) {
            chenhlechNN = chenhlech;
            CPgannhat = binhphuong;
        }
    }
    return CPgannhat;
}
int traceLuggage(int & hp1, int & exp1, int & m1, int e2) { 
    if (e2 < 0 || e2 > 99){return -99;} else {
                    //ROAD 1
                if ( (e2%2) == 0 || e2 == 0) { int a=0;double p,p1, p2, p3;
        exp1=exp(exp1,exp1);
        hp1=hp(hp1,hp1);
        m1=m(m1,m1);
        if (4>3){  
int CPgannhat = soCP(exp1);
    if (exp1 >= CPgannhat ) {
        p1 = 1;
    } else {exp1=exp(exp1, exp1);
        p1 = round(((((exp1 * 1.0) / CPgannhat) + 80) / 123)*100)/100;  
    };  };//ROAD 2
                while (a<m1) { if ( hp1 < 200) 
                {m1 = m(m1, m1);
                a+=150; 
                hp1=ceil(ceil(hp1)*1.3);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>m1) {break;}; } else {
                m1 = m(m1, m1);
                a+=70; 
                hp1=ceil(ceil(hp1)*1.1);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>m1) { break;};}
                    if ( exp1 < 400) 
                {m1 = m(m1, m1);
                a+=200; 
                exp1=ceil(ceil(exp1)*1.13);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>m1) { break;}; } else {
                m1 = m(m1, m1);
                a+=120; 
                exp1=ceil(ceil(exp1)*1.13);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>m1) { break;};}
                    if ( exp1 < 300) 
                {m1 = m(m1, m1);
                a+=100; 
                exp1=ceil(ceil(exp1)*0.9);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>m1) { break;}; } else {
                m1 = m(m1, m1);
                a+=120; 
                exp1=ceil(ceil(exp1)*0.9);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>m1) { break;};}
                break;};  m1=m1-a; m1 = m(m1, m1);
                hp1=ceil(ceil(hp1)*0.83); exp1=ceil(ceil(exp1)*1.17);
        hp1=hp(hp1,hp1);exp1=exp(exp1, exp1);    
        if (exp1 >= soCP(exp1)){
                            p2 = 1;
                            } else {p2=(((exp1*1.0/soCP(exp1))+80)/123);} 
                           
                           // ROAD 3
            int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
            if (e2/10 < 1)
               {  p3=(P[e2])*1.0/100;}
            else {  int i = (e2%10) + (e2/10);
                    if (i>10) { p3=(P[(i%10)])*1.0/100;}
                    else { p3=(P[(i)])*1.0/100;}};

            //total
            p=(p1+p2+p3)/3;
            if (p >=0.5 && p<1)   {
            hp1=ceil(ceil(hp1) * 0.9);
            exp1=ceil(ceil(exp1)*1.2);
            exp1=exp(exp1, exp1);  
            hp1=hp(hp1,hp1); }
            else { if (p<0.5){
            hp1=ceil(ceil(hp1)*0.85);
            exp1=ceil(ceil(exp1)*1.15);
            exp1=exp(exp1, exp1);
            hp1=hp(hp1,hp1);
            } else {exp1=ceil(ceil(exp1)*0.75);
                    exp1=exp(exp1, exp1);  }
                    }}       
                    
        else {int a=0;   double p,p1, p2, p3; 
        exp1=exp(exp1,exp1);
        hp1=hp(hp1,hp1);
        m1=m(m1,m1); int b=m1/2;
        if (4>3){  
        int CPgannhat = soCP(exp1);
        if (exp1 >= CPgannhat ) {
        p1 = 1;
        } else {exp1=exp(exp1, exp1);
        p1 = round(((((exp1 * 1.0) / CPgannhat) + 80) / 123)*100)/100;  
        }; };
                while (a<b) { if ( hp1 < 200) 
                {m1 = m(m1, m1);
                a+=150; 
                hp1=ceil(ceil(hp1)*1.3);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>b) { break;}; } else {
                m1 = m(m1, m1);
                a+=70; 
                hp1=ceil(ceil(hp1)*1.1);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>b) { break;};}
                    if ( exp1 < 400) 
                {m1 = m(m1, m1);
                a+=200; 
                exp1=ceil(ceil(exp1)*1.13);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>b) { break;}; } else {
                m1 = m(m1, m1);
                a+=120; 
                exp1=ceil(ceil(exp1)*1.13);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>b) { break;};}
                    if ( exp1 < 300) 
                {m1 = m(m1, m1);
                a+=100; 
                exp1=ceil(ceil(exp1)*0.9);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>b) {break;}; } else {
                m1 = m(m1, m1);
                a+=120; 
                exp1=ceil(ceil(exp1)*0.9);  
                exp1=exp(exp1, exp1); 
                hp1=hp(hp1,hp1);
                if (a>b) { break;};};};
                if(a>m1) {m1=0;} else {m1=m1-a;}
                m1 = m(m1, m1);hp1=ceil(ceil(hp1)*0.83); exp1=ceil(ceil(exp1)*1.17);
        hp1=hp(hp1,hp1);exp1=exp(exp1, exp1);    
        if (exp1 >= soCP(exp1)){
                            p2 = 1;
                            } else {p2=(((exp1*1.0/soCP(exp1))+80)/123);}
                            
                            // ROAD 3
            int P[] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
            if (e2/10 < 1)
               {  p3=(P[e2])*1.0/100;}
            else {  int i = (e2%10) + (e2/10);
                    if (i>10) { p3=(P[(i%10)])*1.0/100;}
                    else { p3=(P[(i)])*1.0/100;}};

            //total
            p=(p1+p2+p3)/3;
            if (p >=0.5 && p<1)   {
            hp1=ceil(ceil(hp1) * 0.9);
            exp1=ceil(ceil(exp1)*1.2);
            exp1=exp(exp1, exp1);  
            hp1=hp(hp1,hp1); }
            else { if (p<0.5){
            hp1=ceil(ceil(hp1)*0.85);
            exp1=ceil(ceil(exp1)*1.15);
            exp1=exp(exp1, exp1);
            hp1=hp(hp1,hp1);
            } else {exp1=ceil(ceil(exp1)*0.75);
                    exp1=exp(exp1, exp1);  }
                    }
             }}return hp1+exp1+m1; }

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    //TODO: implement task
    return -1;
} //Task 4
int checkPassword(const char *s, const char *email) {
     int emailLength = strlen(email);
    char se[101];
    int i;
    for (i = 0; i < emailLength; ++i) {
        if (email[i] == '@') {
            break;
        }
        se[i] = email[i];
    }
    se[i] = '\0';
    int sLength = strlen(s);
    if (sLength < 8)
        return -1;
    if (sLength > 20)
        return -2;
    if (strstr(s, se) != NULL)
        return -(300 + (int)(strstr(s, se) - s));
    for (int i = 0; i < sLength - 2; i++) {
        if (s[i] == s[i + 1] && s[i] == s[i + 2])
            return -(400 + i);
    }
    bool kitudb = false;
    for (int i = 0; i < sLength; i++) {
        if (!(('a' <= s[i] && s[i] <= 'z') ||
              ('A' <= s[i] && s[i] <= 'Z') ||
              ('0' <= s[i] && s[i] <= '9') ||
              s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            kitudb = true;
            break;
        }
    }
    if (!kitudb)
        return -5;
    for (int i = 0; i < sLength; i++) {
        if (!(('a' <= s[i] && s[i] <= 'z') ||
              ('A' <= s[i] && s[i] <= 'Z') ||
              ('0' <= s[i] && s[i] <= '9') ||
              s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!')) {
            return i;
        }
    }
    return -10;
    char password[100]; 
    int result = checkPassword(password, email);  
    return result;
}

        // Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    const char* max_freq_pwd = nullptr;
    int max_freq = 0;
    int max_length = 0;
    int max_digit_count = 0;
    int result_index = -1;
    for (int i = 0; i < num_pwds; ++i) {
        const char* pwd = arr_pwds[i];
        int freq = 0;
        for (int j = 0; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[j], pwd) == 0) {
                freq++;
            }
        }
        int length = strlen(pwd);
        int digit_count = 0;
        for (int k = 0; k < length; ++k) {
            if (isdigit(pwd[k])) {
                digit_count++;
            }
        }
        if (freq > max_freq || (freq == max_freq && (length > max_length || (length == max_length && digit_count > max_digit_count)))) {
            max_freq = freq;
            max_length = length;
            max_digit_count = digit_count;
            max_freq_pwd = pwd;
            result_index = i; 
        }
    }
    return result_index;
    for (int i = 0; i < num_pwds; ++i) {
        char password[100];
        arr_pwds[i] = strdup(password); 
    }
    int result = findCorrectPassword(arr_pwds, num_pwds);
    return  result;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////