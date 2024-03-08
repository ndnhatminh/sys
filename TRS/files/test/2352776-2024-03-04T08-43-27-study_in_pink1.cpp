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
    if(!checkEvent(e1)){
        return -99;
    }
    checkExp(exp1,exp2);
    // TODO: Truong hop 1
    if(e1 >=0 && e1 <=3){
        switch (e1)
        {
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
            exp2+=(29+45+75);
            
            break;       
        default:
            break;
        }
        checkExp(exp2, exp2);

        const int D = e1*3 + exp1*7;
        if( D % 2 ==0 ){
            exp1=ceil(exp1 + float(D)/200);
            
        }
        else if( D % 2 !=0){
            exp1=ceil(exp1 - float(D)/100);
            
        }
        checkExp(exp1,exp2);
    }
    // Truong hop 2
    else if ( e1 >=4 && e1 <=99){
        float infor1 = float(e1)/4+19;
        float infor2 = float(e1)/9+21;
        float infor3 = float(e1)/16+17;
        switch (e1)
        {
        case 4 ... 19:
            exp2= ceil(exp2 + infor1);
            
            break;
        case 20 ... 49:
            exp2=ceil(exp2 + infor2);
            
            break;
        case 50 ... 65:
            exp2=ceil(exp2 + infor3);
            
            break;
        case 66 ... 79:
            exp2+=ceil(infor1);
            
            if(exp2 > 200){
                exp2 += ceil(infor2);
                
            }
            break;
        case 80 ... 99:
            exp2= ceil(exp2 + infor1);
            checkExp(exp2,exp2);
            exp2=ceil(exp2 + infor2);
            checkExp(exp2,exp2);
            if(exp2 > 400){
                exp2=ceil(exp2 + infor3);
                checkExp(exp2,exp2);
                exp2 = ceil(exp2 *1.15);
                checkExp(exp2,exp2);
            } 
                
            break;
        default:
            break;
        }
        exp1 -= e1;

    }
    checkExp(exp1, exp2);
    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {

    // TODO: Complete this function
    //check event first
    if(!checkEvent(E2)){
        return -99;
    }
    checkHP(HP1, HP1);
    checkExp(EXP1, EXP1);
    checkM(M1,M1);
    // Start first way
    float P1 = probabilityCalculator(EXP1); // Xac suat duong 1


    //start second way
    int paidMoney = 0;
    float halfM1 = static_cast<float>(M1)/2;
    if(E2 % 2 !=0){
        while(paidMoney <= halfM1){
            if(halfM1 == 0) break;
            if(checkOutOfMoney(halfM1 - paidMoney) == 1 || checkOutOfMoney(halfM1 - paidMoney) == 0){ // Tiền còn lại = tiền dc tiêu - tiền đã tiêu, TH nay tieu du thi ms bi
                paidMoney+=event1Path2(HP1, M1); 
            }
            else{
                break;
            }
            if(checkOutOfMoney(halfM1 - paidMoney)== 1 || checkOutOfMoney(halfM1 - paidMoney) == 0){
                paidMoney+=event2Path2(EXP1, M1);
            }
            else{
                break;
            }
            if(checkOutOfMoney(halfM1 -paidMoney)== 1 || checkOutOfMoney(halfM1 - paidMoney) == 0){
                paidMoney+=event3Path2(EXP1, M1);
            }
            else{
                break;
            }
        }
        HP1 = ceil(HP1 - HP1*0.17);
        EXP1 = ceil(EXP1 + EXP1*0.17);
        checkHP(HP1,HP1);
        checkExp(EXP1, EXP1);
    }
    else{
            if(checkOutOfMoney(M1) == 1){
                event1Path2(HP1, M1);
            }
            if(checkOutOfMoney(M1) == 1){
                event2Path2(EXP1, M1);
            }
            if(checkOutOfMoney(M1) == 1){
                event3Path2(EXP1, M1);
            }
        HP1 = ceil(HP1 - HP1*0.17);
        EXP1 = ceil(EXP1 + EXP1*0.17);
        checkHP(HP1,HP1);
        checkExp(EXP1, EXP1);
        }
    float P2 = probabilityCalculator(EXP1);


    // Start Path 3

    int P[10] =  {32,47,28,79,100,50,22,83,64,11};
    int i = 0;
    float P3 = 0;
    if(E2 >= 10){
        int tmp = E2;
        while(tmp >0){
            i = i + tmp %10;
            tmp /=10;
            
        }
        P3 = static_cast<float>(P[i%10])/100;
    }
    else {
        i = E2;
        P3 = static_cast<float>(P[i])/100;
    }
    
    if( P1 == 1 && P2 == 1 && P3 == 1){
        EXP1 = ceil(EXP1 - 0.25*EXP1);
        checkExp(EXP1,EXP1);
    }
    else{
        float aveP = static_cast<float>(P1+P2+P3)/3;
        if(aveP < 0.5){
            HP1 = ceil(HP1 - HP1*0.15);
            EXP1 = ceil(EXP1 + EXP1*0.15);
            checkHP(HP1,HP1);
            checkExp(EXP1,EXP1);
        }
        else{
            HP1 = ceil(HP1 - HP1*0.10);
            EXP1 = ceil(EXP1 + EXP1*0.20);
            checkHP(HP1,HP1);
            checkExp(EXP1,EXP1);
        }
    }
    checkExp(EXP1,EXP1);
    checkHP(HP1,HP1);
    checkM(M1,M1);

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    if(!checkEvent(E3)){
        return -99;
    }
    checkHP(HP1, HP2);
    checkExp(EXP1, EXP2);
    // TODO: Complete this function
    int theMap[10][10];
    for(int i =0 ; i < 10; i++ ){
        for(int j =0 ; j < 10; j++){
            theMap[i][j]= ((E3*j)+(i*2))*(i-j);
        }
    }
    int iMeet = 0;
    int jMeet = 0;
    for(int i =0 ; i < 10; i++ ){
        for(int j =0 ; j < 10; j++){
            if( theMap[i][j] > (E3 *2)){
                iMeet++;
            }
            else if(theMap[i][j] < (-E3) ){
                jMeet++;
            }

            ;}}
    while(jMeet >=10 || iMeet >=10){
    iMeet = getIndex(iMeet);
    jMeet = getIndex(jMeet);

    }

    // Multiply by vector
    int result[100]= {};
    result[0]= theMap[iMeet][jMeet];
    int count = 1;
    int arrVectorDir[2] = {-1,1}; // init direction {(1,1)(1,-1)(-1,-1)(-1,1)}
    for(int i =0 ; i <2 ; i++){
        for(int j= 0; j< 2; j++){
        int iCoor = iMeet;
        int jCoor = jMeet;
        while((iCoor+arrVectorDir[i]) >= 0 && (iCoor+arrVectorDir[i]) <=9 && (jCoor+arrVectorDir[j]) >= 0 && (jCoor+arrVectorDir[j]) <=9){
        findCoorByVector(iCoor, jCoor, arrVectorDir[i],arrVectorDir[j] );
        result[count]= theMap[iCoor][jCoor];
        count++;
        }
        }
    }

    int sherlockLocation = result[0];
    for(int i=1 ; i <= count; i++){
        if( sherlockLocation < result[i-1]){
            sherlockLocation = result[i-1];
        }
    }
    if(abs(theMap[iMeet][jMeet]) > abs(sherlockLocation)){
        EXP1 = ceil(EXP1 - EXP1*0.12);
        EXP2 = ceil(EXP2 - EXP2*0.12);
        HP1 = ceil(HP1 - HP1*0.1);
        HP2 = ceil(HP2 - HP2*0.1);
        checkExp(EXP1,EXP2);
        checkHP(HP1, HP2);
    }
    else{

        EXP1 = ceil(EXP1 + EXP1*0.12);
        EXP2 = ceil(EXP2 + EXP2*0.12);
        HP1 = ceil(HP1 + HP1*0.1);
        HP2 = ceil(HP2 + HP2*0.1);
        checkExp(EXP1,EXP2);
        checkHP(HP1, HP2);

    }
    


    return (abs(theMap[iMeet][jMeet])>abs(sherlockLocation))? theMap[iMeet][jMeet]: sherlockLocation;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    //TODO: fix lai thu tu checker.
        int seIndex=0;
        // find index of @ sign
        while(*(email+seIndex) !='\0' && *(email+seIndex) !='@' ){
            seIndex++;
            }

        //get the texxt before @ sign
        char *se = new char[seIndex + 1];
        strncpy(se, email, seIndex);
        se[seIndex] = '\0'; 
        // finding length of S
        int sLength = 0;
        while(*(s+sLength) != '\0' ){
            
            sLength++;
        }

        // check length
        if( !(sLength >= 8 && sLength <=20)){
            if(sLength < 8){
                return -1;
            }
            else if(sLength > 20){
                return -2;
            }
        }
                // check substring 

        if(*(se) == '\0'){ // de phong truong họp email = "@gmail.com" thay vi "abc@gmail.com"
            return -300;
        }
        int SEI = isSubstring(se, s);
        if(SEI != std::string::npos){
            return -(300+SEI);
            }
        //check Duplicate
        int SCI = isDuplicate(s);
        if(SCI != -1){
            return -(400+SCI);
        }

        // check khong chua ki tu dac biet
        if(!isContainNonAlpha(s)){
            return -5;
        }
        // checkCharValid
        int tmp=0;
            while(*(s+tmp) != '\0' ){
            
            if(!(checkCharValid(*(s+tmp)))){
                return tmp;
            }
            tmp++;
        }
 
        return -10;
    }

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    string subArr[199] ={""};
    int countArr[199*3] ={0};
    int searchIndex =0; // For searching news string count.
    int addIndex = 0; // for adding news string to array,
    int subArrIndex =0 ;
    while( searchIndex < num_pwds){
        bool isExist = false; // check if is element have existed or not
        for(int i=0; i < subArrIndex +1 ; i++){
             if(arr_pwds[searchIndex] ==  subArr[i]){
                isExist = true;
            }
        }
        if(!isExist){
            subArr[subArrIndex] = arr_pwds[searchIndex];
                    // counting
            int count = 0;
            for(int j = 0; j < num_pwds; j++){
                if(arr_pwds[j] == subArr[subArrIndex]){
                    count++;
                }
            }
            countArr[addIndex+1] = count; // mảng chẵn = index , lẻ = sl
            countArr[addIndex] = searchIndex; 
            subArrIndex++;
            addIndex+=2; //+ 2 vì có lioeen hệ với count array
            searchIndex++;
        }
        else{
            searchIndex++;
        }


    }
    int maxIndex =countArr[0];
    int max=countArr[1];
    for(int i = 0; i < addIndex; i=i+2 )
    {   
        if(max < countArr[i+1]){
            max = countArr[i+1];
            maxIndex = countArr[i];
        }
        else if( max == countArr[i+1]){

            if( strlen(arr_pwds[maxIndex]) < strlen(arr_pwds[countArr[i]])  ) 
            {
                

                maxIndex = countArr[i];


            }
            
            }
    }
    return maxIndex;
}
void checkHP(int & HP1, int & HP2){
    if (HP1 > 666) {
        HP1 = 666;
    } else if (HP1 < 0) {
        HP1 = 0;
    }
    if (HP2 > 666) {
        HP2 = 666;
    } else if (HP2 < 0) {
        HP2 = 0;
    }
}
void checkExp(int & EXP1 , int & EXP2){
    if (EXP1 > 600) {
        EXP1 = 600;
    } else if (EXP1 < 0) {
        EXP1 = 0;
    }

    if (EXP2 > 600) {
        EXP2 = 600;
    } else if (EXP2 < 0) {
        EXP2 = 0;
    }

}
void checkM(int & M1, int & M2){
    if (M1 > 3000) {
        M1 = 3000;
    } else if (M1 < 0) {
        M1 = 0;
    }

    if (M2 > 3000) {
        M2 = 3000;
    } else if (M2 < 0) {
        M2 = 0;
    }

}
bool checkEvent(int e){
    if( e >= 0 && e <=99){
        return true;
    }
    else{
        return false;
    }
}

//task 2 function
int nearestSquaredNumber(int P){
    int S= sqrt(P);
    if( S*S == P){
        return P;
    }
    else{
        return (abs((S*S - P)) < abs(((S+1)*(S+1) - P)))? S*S : (S+1)*(S+1);
        }
     
}
int event1Path2(int & HP1, int & M1){
    if(HP1 < 200){
        HP1 = ceil(HP1 + 0.3*HP1);
        M1 -= 150;
        checkHP(HP1,HP1);
        return 150;
    }
    else{
        HP1 = ceil(HP1 + 0.1*HP1);
        M1 -= 70;
        checkHP(HP1,HP1);
        return 70;
    }
    return 0;
}

int event2Path2(int & EXP1, int & M1){
    int costTaxi = 200;
    int costHorse = 120;
    
    if( EXP1 < 400){
        M1 -= costTaxi;
        EXP1 = ceil(EXP1+ static_cast<float>(EXP1)*0.13);
        checkM(M1,M1);
        checkExp(EXP1, EXP1);
        return costTaxi;
    }
    else{
        M1 -= costHorse;
        EXP1 = ceil(EXP1+ static_cast<float>(EXP1)*0.13);
        checkM(M1,M1);
        checkExp(EXP1, EXP1);
        return costHorse;
    }
    return 0;
}
int event3Path2(int & EXP1, int & M1){
    if(EXP1 < 300){
        M1 -= 100;
        EXP1 = ceil(EXP1 -static_cast<float>(EXP1)*0.1);
        checkM(M1,M1);
        checkExp(EXP1, EXP1);
        return 100;
    }
    else if( EXP1 >= 300){
        M1 -= 120;
        EXP1 = ceil(EXP1 - static_cast<float>(EXP1)*0.1);
        checkM(M1,M1);
        checkExp(EXP1, EXP1);
        return 120;
    }
return 0;
    
}
int checkOutOfMoney(float M1){
    if( M1 < 0){
        return -1;
    }
    else if( M1 == 0){
        return 0;
    }
    else return 1;
}
float probabilityCalculator(int EXP1){
    int S= nearestSquaredNumber(EXP1);
    float P1= 0.0f;
    if( EXP1 >= S){
        P1 = static_cast<float>(1.0);
    }
    else{
        P1 = (static_cast<float>(EXP1)/S+80)/123;
    } 
    return P1;
}

// Task 3 function

int getIndex(int coordinate){
    int tmp=0;
    if(coordinate >=10){
        while(coordinate > 0){
        tmp+= coordinate % 10;
        coordinate/=10;

        }
    }
    else{
        return coordinate;
    }
    return tmp;
}

void findCoorByVector(int & x , int & y, int xDir, int yDir){
    x+=xDir;
    y+=yDir;
}

// task 4 function


bool checkCharValid(char s){
    if( !( (s >= '0' && s <= '9') ||(s >= 'A' && s <= 'Z') || (s >='a' && s <='z') || s == '@'|| s == '%'|| s == '#'|| s == '$'|| s == '!')){
        return false;
    }
    else{
        return true;
    }
}
int isSubstring(const char * substring, const char * strings){
    string password = strings;
    std::size_t result = password.find(substring);
    if(result != std::string::npos){ // neu ko trung find tra ve -1
        return result;
    }
    return result;
    
    
}

int isDuplicate(const char * password){
    int i=0;
    /// check xem 3 pass co trung nhau ko
    while(*(password+i+2) != '\0'){
        if(*(password+i) == *(password+i+1) &&*(password+i) ==   *(password+i+2)){
            return i;
        }
        i++;
    }
    return -1;
}
bool isContainNonAlpha(const char * s){
    int i=0;
    while(*(s+i) != '\0'){
        if(*(s+i) == '@'|| *(s+i) == '#'|| *(s+i) == '$'|| *(s+i) == '!'|| *(s+i) == '%'){
            return true;
        }
        i++;
    }
    return false;
}

// task 5 function





////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////