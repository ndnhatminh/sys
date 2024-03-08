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
    // DO NOT MODIFY THIS FUNCTION
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

// Reset stats
void resethp(int &hp){
    if (hp<0){hp=0;}
    else if (hp>666){hp=666;}
    return;
}
void resetxp(int &exp){
    if (exp<0){exp=0;}
    if (exp>600){exp=600;}
    return;
}
void resetm(int &m){
    if (m<0){m=0;}
    if (m>3000){m=3000;}
    return;
}

// Task 1 (completed)
int firstMeet(int & exp1, int & exp2, int e1) {
    if (!(0<=e1 && e1<=99)){return -99;}
    resetxp(exp1); resetxp(exp2);
    int d=0;
    if (0<=e1 && e1<=3){
        if (e1==0){exp2+=29;}
        else if (e1==1){exp2+=45;}
        else if (e1==2){exp2+=75;}
        else {exp2+=149;}
        resetxp(exp2);
        d=e1*3+exp1*7;
        if (d%2==0){exp1=ceil(exp1+(double)d/200);}
        else {exp1=ceil(exp1-(double)d/100);}
        resetxp(exp1);
    }
    else if (4<=e1 && e1<=99){
        if (4<=e1 && e1<=19){exp2=ceil(exp2+(double)e1/4+19);}
        else if (20<=e1 && e1<=49){exp2=ceil(exp2+(double)e1/9+21);}
        else if (50<=e1 && e1<=65){exp2=ceil(exp2+(double)e1/16+17);}
        else if (66<=e1 && e1<=79){
            exp2=ceil(exp2+(double)e1/4+19); resetxp(exp2);
            if (exp2>200){exp2=ceil(exp2+(double)e1/9+21);}
        }
        else {
            exp2=ceil(exp2+(double)e1/4+19); resetxp(exp2);
            exp2=ceil(exp2+(double)e1/9+21); resetxp(exp2);
            if (exp2>400){
                exp2=ceil(exp2+(double)e1/16+17);
                resetxp(exp2);
                exp2=ceil(exp2*1.15);// cộng thêm 0.15 lần xp2
                }
        }
        resetxp(exp2);
        exp1-=e1; resetxp(exp1);
    }
    return exp1 + exp2;
}

// Task 2 [completed]
double path1(int & EXP1){
    int s,s1,s2;
    // Find closest sq num to exp1
    int i=1;
    double p1;
    // path 1
    while (true){ // generate sq nums
        if (i*i==EXP1){
            s=i*i;
            break;}
        else if (i*i>EXP1){
            s1=(i-1)*(i-1); s2=i*i;
            if (EXP1-s1 > s2-EXP1){s=s2;}
            else {s=s1;}
            break;
        }
        else i+=1;
    }
    if (EXP1>=s){p1=1;}
    else {p1=((double)EXP1/s + 80)/123;}
    return p1;
}
void event1(int & HP1, int & M1, int &spent){
    if (HP1<200){
        HP1=ceil(HP1+HP1*0.3); resethp(HP1);
        spent+=150; M1-=150; resetm(M1);
    } else {
        HP1=ceil(HP1+HP1*0.1); resethp(HP1);
        spent+=70; M1-=70; resetm(M1);
    }
    return;
}
void event2(int & EXP1, int & M1, int &spent){
    if (EXP1<400){M1-=200; spent+=200; resetm(M1);}
    else {M1-=120; spent+=120; resetm(M1);}
    EXP1=ceil(EXP1+EXP1*0.13); resetxp(EXP1);
    return;
}
void event3(int & EXP1, int & M1, int &spent){
    if (EXP1<300){M1-=100; spent+=100; resetm(M1);}
    else {M1-=120; spent+=120; resetm(M1);}
    EXP1=ceil(EXP1-EXP1*0.1); resetxp(EXP1); // exp1 giảm 10%
}
double path2(int & HP1, int & EXP1, int & M1, int E2){
    double init50=M1*0.5;
    int spent = 0;
    double p2;
    if (E2%2!=0){
        while (true){
            event1(HP1,M1,spent);
            if ((double)spent>init50){break;}
            event2(EXP1,M1,spent);
            if ((double)spent>init50){break;}
            event3(EXP1,M1,spent);
            if ((double)spent>init50){break;}
        }
        
    } else {
        event1(HP1,M1,spent);
        if (M1==0){goto lb;}
        event2(EXP1,M1,spent);
        if (M1==0){goto lb;}
        event3(EXP1,M1,spent);
    }
    lb:HP1=ceil(HP1-HP1*0.17); resethp(HP1); // trừ 0.17
    EXP1=ceil(EXP1+EXP1*0.17); resetxp(EXP1); // tăng 0.17
    p2 = path1(EXP1);
    return p2;
}
double path3(int &e2){
    double p3=100;
    int sum;
    int p[10]={32,47,28,79,100,50,22,83,64,11};
    if (e2<10){p3=p[e2]/p3;}
    else {
        sum=e2/10 + e2%10; //cộng 2 chữ số của e2
        sum=sum%10;        // lấy hàng đv của tổng
        p3=(double)p[sum]/p3;
    }
    return p3;
}

int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (!(0<=E2 && E2<=99)){return -99;}
    resethp(HP1); resetxp(EXP1); resetm(M1);
    double p1,p2,p3,finalp;
    p1=path1(EXP1);
    p2=path2(HP1,EXP1,M1,E2);
    p3=path3(E2);

    if (p1==1 && p2==1 && p3==1){
        EXP1=ceil(EXP1-EXP1*0.25); resetxp(EXP1);// exp1 giảm 0.25
        return HP1 + EXP1 + M1;
    }
    finalp=(p1+p2+p3)/3;
    if (finalp<0.5){
        HP1=ceil(HP1-HP1*0.15); resethp(HP1);      // hp1 giảm 0.15
        EXP1=ceil(EXP1+EXP1*0.15); resetxp(EXP1);   // exp1 tăng 0.15
    } else {
        HP1=ceil(HP1-HP1*0.1); resethp(HP1);       // hp1 giảm 0.1
        EXP1=ceil(EXP1+EXP1*0.2); resetxp(EXP1);    // exp1 tăng 0.2
    }
    return HP1 + EXP1 + M1;
}

// Task 3 [completed, tested]
int diagmax(int mtr[10][10], int &a, int &b){
    int i,j,max;
    max=-9999;
    // left diag
    i=a; j=b;
    while (i>=0 && j>=0){
        if (mtr[i][j]>max){max=mtr[i][j];}
        i-=1; j-=1;
    }
    i=a; j=b;
    while (i<=9 && j<=9){
        if (mtr[i][j]>max){max=mtr[i][j];}
        i+=1; j+=1;
    }
    // right diag
    i=a; j=b;
    while (i>=0 && j<=9){
        if (mtr[i][j]>max){max=mtr[i][j];}
        i-=1; j+=1;
    }
    i=a; j=b;
    while (i<=9 && j>=0){
        if (mtr[i][j]>max){max=mtr[i][j];}
        i+=1; j-=1;
    }
    return max;
}

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if (!(0<=E3 && E3<=99)){return -99;}
    resethp(HP1); resethp(HP2); resetxp(EXP1); resetxp(EXP2);
    int taxiMtr[10][10] = {0};
    int sumi=0; int sumj=0;
    int shPt; // Sherlock Holmes's pt
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            taxiMtr[i][j]=((E3*j)+(i*2))*(i-j);
            //shMtr[i][j]=diagmax(taxiMtr,i,j);
            if (taxiMtr[i][j]>E3*2){sumi+=1;}
            if (taxiMtr[i][j]<-E3){sumj+=1;}
        }
    }

    while (sumi>9){sumi=sumi/10+sumi%10;}
    while (sumj>9){sumj=sumj/10+sumj%10;}
    shPt=diagmax(taxiMtr,sumi,sumj);
    if (abs(taxiMtr[sumi][sumj])>shPt){
        // ko đuổi kịp
        EXP1=ceil(EXP1-EXP1*0.12); resetxp(EXP1);
        EXP2=ceil(EXP2-EXP2*0.12); resetxp(EXP2);
        HP1=ceil(HP1-HP1*0.1); resethp(HP1);
        HP2=ceil(HP2-HP2*0.1); resethp(HP2); 
        return taxiMtr[sumi][sumj];
    } else {
        // đuổi kịp
        EXP1=ceil(EXP1+EXP1*0.12); resetxp(EXP1);
        EXP2=ceil(EXP2+EXP2*0.12); resetxp(EXP2);
        HP1=ceil(HP1+HP1*0.1); resethp(HP1);
        HP2=ceil(HP2+HP2*0.1); resethp(HP2);
        return shPt;
    }
}

// Task 4 [completed, tested]
int ctnch(const string &s){ // continuous chars
    int l=s.size();
    for (int i=0;i<l-2;i++){
        if (s[i+1]==s[i]){
            if (s[i+2]==s[i]){
                return i;
            }
        }
    }
    return -1;
}
bool isSpecial(char ch){
    if (ch=='@' || ch=='#' || ch=='%' || ch=='$' || ch=='!'){return true;}
    else {return false;}
}
bool spch(const string &s){ // special char
    for (int i=0;i<s.size();i++){
        if (isSpecial(s[i])){return true;}
    }
    return false;
}
int illegalch(const string &s){
    int c;
    for (int i=0;i<s.size();i++){
        c=int(s[i]);
        if (! ((48<=c && c<=57) || (65<=c && c<=90) || (97<=c && c<=122) || isSpecial(c))){return i;}
    }
    return -1;
}

int checkPassword(const char * s, const char * email) {
    string se, mail = email;
    string pw=s;
    se = "";
    int lmail=mail.size(); // lmail = length of mailress
    int lpw=pw.size();
    // Get se
    for (int i=0;i<lmail;i++){
        if (mail[i]!='@'){se+=mail[i];}
        else break;
    }
    // Check requirements
    if (lpw<8){return -1;}
    else if (lpw>20){return -2;}

    size_t sei=pw.find(se);
    if (sei!=string::npos){return -(300+sei);}

    int sci=ctnch(pw);
    if (sci!=-1){return -(400+sci);}

    if(spch(pw)==false){return -5;}

    int lg=illegalch(pw);
    if (lg!=-1){return lg;}

    return -10;
}

// Task 5 [completed, tested]
// Linked list
#include <iostream>
using namespace std;
class Node{
public:
    string key;
    int count;
    Node* next;
    // constructor
    Node(string key){
        this->key=key;
        this->count=1;
        this->next=NULL;
    }

};
class LinkedList{
public:
    Node* head;
    // constructor
    LinkedList(){head=NULL;}

    void insertNode(string key){
        Node* newNode = new Node(key);
        if (head==NULL){
            head=newNode;
            return;
        }
        Node* temp = head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        return;
    }
    void printList(){
        Node* temp = head;
        if (head==NULL){
            cout << "List empty!";
            return;
        }
        while (temp!=NULL){
            cout << temp->key << ": " << temp->count << "\n";
            temp=temp->next;
        }
        return;
    }
    int getListSize(){
        if (head==NULL){return 0;}
        int size=1;
        Node* temp=head;
        while (temp->next!=NULL){
            size++;
            temp=temp->next;
        }
        return size;
    }
    void deleteList(){
        Node* temp=head;
        Node* nextemp=temp->next;
        while (nextemp!=NULL){
            delete temp;
            temp=nextemp;
            nextemp=nextemp->next;
        }
        return;
    }
    int searchList(string key){
        if (head==NULL){return -1;}
        Node* temp=head;
        int pos=0;
        while (temp->next!=NULL){
            if (temp->key!=key){
                pos++;
                temp=temp->next;
            } else break;
        }
        return pos;
    }
    void countOn(string key){
        if (head==NULL){
            insertNode(key);
            return;}
        Node* temp = head;       
            while (temp->next!=NULL){
            if (temp->key==key){
                temp->count++;
                return;
            }
            temp=temp->next;
        }
        // temp is at the end of list, but key is still not found
        // so create new node for this key
        if (temp->key==key){
                temp->count++;
                return;
        }
        Node* newNode = new Node(key);
        temp->next=newNode;
    }
    string maxCountedStr(){
        if (head==NULL){return "List is Empty!";}
        Node* temp=head;
        int maxCount=0;
        string maxStr="";
        while (temp!=NULL){
            if (temp->count>maxCount){
                maxCount=temp->count;
                maxStr=temp->key;
            } else if (temp->count==maxCount && temp->key.size()>maxStr.size()){maxStr=temp->key;}
            temp=temp->next;
        }
        return maxStr;
    }
};
// End linked list

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    LinkedList list;
    string pws[num_pwds];
    for (int i=0;i<num_pwds;i++){
        pws[i]=arr_pwds[i];
        list.countOn(pws[i]);
    }
    string resultstr=list.maxCountedStr();
    // search list
    //int sz=pws.size();
    int resultpos;
    for (int i=0;i<num_pwds;i++){
        if (pws[i]==resultstr){
            resultpos=i;
            break;
        }
    }
    //int resultpos=list.searchList(resultstr);
    return resultpos;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////