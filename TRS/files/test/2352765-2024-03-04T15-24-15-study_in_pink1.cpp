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

// in all cases Holmes is 1 and 2 is Watson // hp from 0 666 // exp 0 600 // m 0 3000 // e 0 99

// Task 1

int calculate_exp2_case1(int E1, int& exp2);
int calculate_exp2_case2(int E1, int& exp2);
void maximum_is_600_minimum_is_0(int& exp1, int& exp2);

int firstMeet(int& exp1, int& exp2, int E1) {
    // TODO: Complete this function
    if(E1 > 99 || E1 < 0){
        return -99;
    }
    maximum_is_600_minimum_is_0(exp1, exp2);
    
    if(E1 >= 0 && E1 <= 3){
        int D = E1 * 3 + exp1 * 7;
        double exp1after;
        if(D % 2 == 0){
            exp1after = ceil(exp1 + D/200.0);
            exp1 = exp1after;
        }
        else{
            exp1after = ceil(exp1 - D/100.0);
            exp1 = exp1after;
        }
        calculate_exp2_case1(E1, exp2);
        maximum_is_600_minimum_is_0(exp1, exp2);
    }
    else if(E1 >= 4 && E1 <= 99){
        calculate_exp2_case2(E1, exp2);
        exp1 -= E1;
        maximum_is_600_minimum_is_0(exp1, exp2);
    }
    
    maximum_is_600_minimum_is_0(exp1, exp2);
    
    return exp1 + exp2;
}

int calculate_exp2_case1(int E1, int& exp2){
    if(E1 == 0){
        exp2 += 29;
    }
    else if(E1 == 1){
        exp2 += 45;
    }
    else if(E1 == 2){
        exp2 += 75;
    }
    else if(E1 == 3){
        exp2 = exp2 + 29 + 45 + 75;
    }
        
    return exp2;
}

int calculate_exp2_case2(int E1, int& exp2){
    double exp2after;
    if((E1 >= 4 && E1 <= 19) || (E1 >= 66 && E1 <= 79)){
        exp2after = exp2 + E1/4.0 + 19;
        exp2 = ceil(exp2after);
        if(E1 >= 66 && E1 <= 79 && exp2 > 200){
            exp2after = exp2 + E1/9.0 + 21;
            exp2 = ceil(exp2after);
        }
    }
    else if(E1 >= 20 && E1 <= 49){
        exp2after = exp2 + E1/9.0 + 21;
        exp2 = ceil(exp2after);
    }
    else if(E1 >= 50 && E1 <= 65){
        exp2after = exp2 + E1/16.0 + 17;
        exp2 = ceil(exp2after);
    }
    else if(E1 >= 80 && E1 <= 99){
        exp2after = exp2 + E1/4.0 + 19;
        exp2 = ceil(exp2after);
        
        exp2after = exp2 + E1/9.0 + 21;
        exp2 = ceil(exp2after);
        if(exp2 > 400){
            exp2after = exp2 + E1/16.0 + 17;
            exp2 = ceil(exp2after);
            
            exp2 += ceil(0.15*exp2);
        }
    }
    return exp2;
}

void maximum_is_600_minimum_is_0(int& exp1, int& exp2){
    if(exp1 > 600){
        exp1 = 600;
    }
    else if(exp1 < 0){
        exp1 = 0;
    }
    
    if(exp2 > 600){
        exp2 = 600;
    }
    else if(exp2 < 0){
        exp2 = 0;
    }
}

// Task 2

int perfect_square(int EXP1);
double calculateP1(int S, int EXP1, double& P1);
void maximum_is_666_minimum_is_0(int& HP1, int& HP2);
void maximum_is_3000_minimum_is_0(int& M1, int& M2);
void foodAndBeverage(double& dhp1, double& dm1);
void taxiOrCarriage(double& dexp1, double& dm1);
void homelessInstruction(double& dexp1, double& dm1);
int roundUp(double& expression);
int summation(int E2);

int traceLuggage(int& HP1, int& EXP1, int& M1, int E2){
    // TODO: Complete this function
    
    if(E2 > 99 || E2 < 0){
        return -99;
    }
    maximum_is_3000_minimum_is_0(M1, M1);
    maximum_is_666_minimum_is_0(HP1, HP1);
    maximum_is_600_minimum_is_0(EXP1, EXP1);
    
    double P1, P2, P3, finalP;
    double dexp1 = EXP1, dm1 = M1, dhp1 = HP1;
    const int MM1 = M1;
    
    // Calculate P1
    int S = perfect_square(EXP1);
    calculateP1(S, EXP1, P1);
    
    // Calculate P2
    if(E2 % 2 != 0){
        
        while(M1 >= 0.5 * MM1 && M1 != 0){
            foodAndBeverage(dhp1, dm1);
            
                HP1 = roundUp(dhp1);
                M1 = roundUp(dm1);
            
                maximum_is_3000_minimum_is_0(M1, M1);
                maximum_is_666_minimum_is_0(HP1, HP1);
            
                dm1 = static_cast<double>(M1);
                dhp1 = static_cast<double>(HP1);
                
            if(M1 < 0.5 * MM1 ) break;
                
            taxiOrCarriage(dexp1, dm1);
            
                EXP1 = roundUp(dexp1);
                M1 = roundUp(dm1);
            
                maximum_is_3000_minimum_is_0(M1, M1);
                maximum_is_600_minimum_is_0(EXP1, EXP1);
            
                dexp1 = static_cast<double>(EXP1);
                dm1 = static_cast<double>(M1);
            
            if(M1 < 0.5 * MM1 ) break;
            
            homelessInstruction(dexp1, dm1);
            
                EXP1 = roundUp(dexp1);
                M1 = roundUp(dm1);
            
                maximum_is_3000_minimum_is_0(M1, M1);
                maximum_is_600_minimum_is_0(EXP1, EXP1);
            
                dexp1 = static_cast<double>(EXP1);
                dm1 = static_cast<double>(M1);
            
            if(M1 < 0.5 * MM1 ) break;
        }
        dhp1 -= 0.17 * dhp1;
        dexp1 += 0.17 * dexp1;
        
        HP1 = roundUp(dhp1);
        EXP1 = roundUp(dexp1);
        
        maximum_is_3000_minimum_is_0(M1, M1);
        maximum_is_666_minimum_is_0(HP1, HP1);
        maximum_is_600_minimum_is_0(EXP1, EXP1);
        
        dhp1 = static_cast<double>(HP1);
        dexp1 = static_cast<double>(EXP1);
        
    }
    else{
        for(int i = 0; i < 1; i++){
            if(M1 == 0) break;
            
            foodAndBeverage(dhp1, dm1);
            
                HP1 = roundUp(dhp1);
                M1 = roundUp(dm1);
            
                maximum_is_3000_minimum_is_0(M1, M1);
                maximum_is_666_minimum_is_0(HP1, HP1);
            
                dm1 = static_cast<double>(M1);
                dhp1 = static_cast<double>(HP1);
            
            if(M1 == 0) break;
            
            taxiOrCarriage(dexp1, dm1);
            
                EXP1 = roundUp(dexp1);
                M1 = roundUp(dm1);
            
                maximum_is_3000_minimum_is_0(M1, M1);
                maximum_is_600_minimum_is_0(EXP1, EXP1);
            
                dexp1 = static_cast<double>(EXP1);
                dm1 = static_cast<double>(M1);
            
            if(M1 == 0) break;
            
            homelessInstruction(dexp1, dm1);
            
                EXP1 = roundUp(dexp1);
                M1 = roundUp(dm1);
            
                maximum_is_3000_minimum_is_0(M1, M1);
                maximum_is_600_minimum_is_0(EXP1, EXP1);
            
                dexp1 = static_cast<double>(EXP1);
                dm1 = static_cast<double>(M1);
            
            if(M1 == 0) break;

        }
        dhp1 -= 0.17 * dhp1;
        dexp1 += 0.17 * dexp1;
        
        HP1 = roundUp(dhp1);
        EXP1 = roundUp(dexp1);
        
        maximum_is_3000_minimum_is_0(M1, M1);
        maximum_is_666_minimum_is_0(HP1, HP1);
        maximum_is_600_minimum_is_0(EXP1, EXP1);
        
        dhp1 = static_cast<double>(HP1);
        dexp1 = static_cast<double>(EXP1);
    }
    int S2 = perfect_square(EXP1);
    calculateP1(S2, EXP1, P2);
    
    // Calculate P3
    int Probability[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
    P3 = Probability[summation(E2)] / 100.0;
    
    
    if(abs(P1 - 1) <= pow(10, -4) && abs(P2 - 1) <= pow(10, -4) && abs(P3 - 1) <= pow(10, -4)){
        dexp1 -= 0.25 * dexp1;
    }
    else{
        finalP = (P1 + P2 + P3) / 3;
        if(finalP < 0.5){
            dhp1 -= 0.15 * dhp1;
            dexp1 += 0.15 * dexp1;
        }
        else{
            dhp1 -= 0.1 * dhp1;
            dexp1 += 0.2 * dexp1;
        }
    }
    HP1 = roundUp(dhp1);
    EXP1 = roundUp(dexp1);

    maximum_is_600_minimum_is_0(EXP1, EXP1);
    maximum_is_666_minimum_is_0(HP1, HP1);

    dexp1 = static_cast<double>(EXP1);
    dhp1 = static_cast<double>(HP1);
    
    return HP1 + EXP1 + M1;
}

int perfect_square(int EXP1){
    int S;
    if(abs( ceil(sqrt(EXP1)) - sqrt(EXP1) ) <= abs( floor(sqrt(EXP1)) - sqrt(EXP1)) ){
        S = pow(ceil(sqrt(EXP1)), 2);
    }
    else{
        S = pow(floor(sqrt(EXP1)), 2);
    }
    return S;
}

double calculateP1(int S, int EXP1, double& P1){
    if(EXP1 >= S){
        P1 = 1.0;
    }
    else{
        P1 = (EXP1/(S*1.0) + 80.0)/123.0;
    }
    return P1;
}

void maximum_is_666_minimum_is_0(int& HP1, int& HP2){
    if(HP1 > 666){
        HP1  = 666;
    }
    else if(HP1 < 0){
        HP1 = 0;
    }
    if(HP2 > 666){
        HP2  = 666;
    }
    else if(HP2 < 0){
        HP2 = 0;
    }
}

void maximum_is_3000_minimum_is_0(int& M1, int& M2){
    if(M1 > 3000){
        M1 = 3000;
    }
    else if(M1 < 0){
        M1 = 0;
    }
    if(M2 > 3000){
        M2 = 3000;
    }
    else if(M2 < 0){
        M2 = 0;
    }
}

void foodAndBeverage(double& dhp1, double& dm1){
    if(dhp1 < 200){
        dhp1 += 0.3 * dhp1;
        dm1 -= 150;
    }
    else{
        dhp1 += 0.1 * dhp1;
        dm1 -= 70;
    }
}

void taxiOrCarriage(double& dexp1, double& dm1){
    if(dexp1 < 400){
        dm1 -= 200;
    }
    else{
        dm1 -= 120;
    }
    dexp1 += 0.13 * dexp1;

}

void homelessInstruction(double& dexp1, double& dm1){
    if(dexp1 < 300){
        dm1 -= 100;
    }
    else{
        dm1 -= 120;
    }
    dexp1 -= 0.1 * dexp1;
}

int roundUp(double& expression){
    int expressionAfter;
    expressionAfter = ceil(expression);
    expression = expressionAfter;
    return expressionAfter;
}

int summation(int E2){
    int unit, index;
    unit = E2 % 10;
    E2 = E2/10;
    if(unit + E2 < 10){
        index = unit + E2;
    }
    else{
        E2 = unit + E2;
        unit = E2 % 10;
        index = unit;
    }
    return index;
}

// Task 3
const int columnSize = 10;
const int rowSize = 10;
void conditionedPoints(int& posi);

int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    
    if(E3 > 99 || E3 < 0){
        return -99;
    }
    
    maximum_is_600_minimum_is_0(EXP1, EXP2);
    maximum_is_666_minimum_is_0(HP1, HP2);
    
    double dhp1 = HP1, dexp1 = EXP1, dhp2 = HP2, dexp2 = EXP2;
    
    // Calculate points of taxi
    int valuesInPoints;
    int taxiRoutes[rowSize][columnSize];
    
    for(int row = 0; row < 10; row++){
        for(int column = 0; column < 10; column++){
            valuesInPoints = (E3 * column + 2 * row) * (row - column);
            taxiRoutes[row][column] = valuesInPoints;
        }
    }
    
    // Calculate Sherlock and Watson
    int sherlockAndWatson[rowSize][columnSize];
    
    int maxValuesByDiagonal[2][20]; maxValuesByDiagonal[0][0] = 0; maxValuesByDiagonal[1][0] = 0;
    
    // main
    int maxpointLeft = -2147483648;
    for(int i = 0; i < 10; i++){
        int j = i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][10] = maxpointLeft;
    }
    
    // main + 1
    maxpointLeft = -2147483648;
    for(int i = 0; i < 9; i++){
        int j;
        j = i + 1;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][11] = maxpointLeft;
    }
    
    // main + 2
    maxpointLeft = -2147483648;
    for(int i = 0; i < 8; i++){
        int j;
        j = i + 2;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][12] = maxpointLeft;
    }
    
    // main + 3
    maxpointLeft = -2147483648;
    for(int i = 0; i < 7; i++){
        int j;
        j = i + 3;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][13] = maxpointLeft;
    }
    
    // main + 4
    maxpointLeft = -2147483648;
    for(int i = 0; i < 6; i++){
        int j;
        j = i + 4;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][14] = maxpointLeft;
    }
    
    // main + 5
    maxpointLeft = -2147483648;
    for(int i = 0; i < 5; i++){
        int j;
        j = i + 5;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][15] = maxpointLeft;
    }
    
    // main + 6
    maxpointLeft = -2147483648;
    for(int i = 0; i < 4; i++){
        int j;
        j = i + 6;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][16] = maxpointLeft;
    }
    
    // main + 7
    maxpointLeft = -2147483648;
    for(int i = 0; i < 3; i++){
        int j;
        j = i + 7;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][17] = maxpointLeft;
    }
    
    // main + 8
    maxpointLeft = -2147483648;
    for(int i = 0; i < 2; i++){
        int j;
        j = i + 8;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][18] = maxpointLeft;
    }
    
    // main + 9
    maxpointLeft = -2147483648;
    for(int i = 0; i < 1; i++){
        int j;
        j = i + 9;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][19] = maxpointLeft;
    }
    
    // main - 1
    maxpointLeft = -2147483648;
    for(int i = 1; i < 10; i++){
        int j;
        j = i - 1;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][9] = maxpointLeft;
    }
    
    // main - 2
    maxpointLeft = -2147483648;
    for(int i = 2; i < 10; i++){
        int j;
        j = i - 2;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][8] = maxpointLeft;
    }
    
    // main - 3
    maxpointLeft = -2147483648;
    for(int i = 3; i < 10; i++){
        int j;
        j = i - 3;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][7] = maxpointLeft;
    }
    
    // main - 4
    maxpointLeft = -2147483648;
    for(int i = 4; i < 10; i++){
        int j;
        j = i - 4;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][6] = maxpointLeft;
    }
    
    // main - 5
    maxpointLeft = -2147483648;
    for(int i = 5; i < 10; i++){
        int j;
        j = i - 5;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][5] = maxpointLeft;
    }
    
    // main - 6
    maxpointLeft = -2147483648;
    for(int i = 6; i < 10; i++){
        int j;
        j = i - 6;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][4] = maxpointLeft;
    }
    
    // main - 7
    maxpointLeft = -2147483648;
    for(int i = 7; i < 10; i++){
        int j;
        j = i - 7;
      
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][3] = maxpointLeft;
    }
    
    // main - 8
    maxpointLeft = -2147483648;
    for(int i = 8; i < 10; i++){
        int j;
        j = i - 8;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][2] = maxpointLeft;
    }
    
    // main - 9
    maxpointLeft = -2147483648;
    for(int i = 9; i < 10; i++){
        int j;
        j = i - 9;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[0][1] = maxpointLeft;
    }
    
    // main
    maxpointLeft = -2147483648;
    for(int i = 0; i < 10; i++){
        int j = 9 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][10] = maxpointLeft;
    }
    
    // main + 1
    maxpointLeft = -2147483648;
    for(int i = 0; i < 9; i++){
        int j;
        j = 8 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][11] = maxpointLeft;
    }
    
    // main + 2
    maxpointLeft = -2147483648;
    for(int i = 0; i < 8; i++){
        int j;
        j = 7 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][12] = maxpointLeft;
    }
    
    // main + 3
    maxpointLeft = -2147483648;
    for(int i = 0; i < 7; i++){
        int j;
        j = 6 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][13] = maxpointLeft;
    }
    
    // main + 4
    maxpointLeft = -2147483648;
    for(int i = 0; i < 6; i++){
        int j;
        j = 5 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][14] = maxpointLeft;
    }
    
    // main + 5
    maxpointLeft = -2147483648;
    for(int i = 0; i < 5; i++){
        int j;
        j = 4 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][15] = maxpointLeft;
    }
    
    // main + 6
    maxpointLeft = -2147483648;
    for(int i = 0; i < 4; i++){
        int j;
        j = 3 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][16] = maxpointLeft;
    }
    
    // main + 7
    maxpointLeft = -2147483648;
    for(int i = 0; i < 3; i++){
        int j;
        j = 2 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][17] = maxpointLeft;
    }
    
    // main + 8
    maxpointLeft = -2147483648;
    for(int i = 0; i < 2; i++){
        int j;
        j = 1 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][18] = maxpointLeft;
    }
    
    // main + 9
    maxpointLeft = -2147483648;
    for(int i = 0; i < 1; i++){
        int j;
        j = 0 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][19] = maxpointLeft;
    }
    
    // main - 1
    maxpointLeft = -2147483648;
    for(int i = 1; i < 10; i++){
        int j;
        j = 10 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][9] = maxpointLeft;
    }
    
    // main - 2
    maxpointLeft = -2147483648;
    for(int i = 2; i < 10; i++){
        int j;
        j = 11 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][8] = maxpointLeft;
    }
    
    // main - 3
    maxpointLeft = -2147483648;
    for(int i = 3; i < 10; i++){
        int j;
        j = 12 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][7] = maxpointLeft;
    }
    
    // main - 4
    maxpointLeft = -2147483648;
    for(int i = 4; i < 10; i++){
        int j;
        j = 13 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][6] = maxpointLeft;
    }
    
    // main - 5
    maxpointLeft = -2147483648;
    for(int i = 5; i < 10; i++){
        int j;
        j = 14 - i;
        
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][5] = maxpointLeft;
    }
    
    // main - 6
    maxpointLeft = -2147483648;
    for(int i = 6; i < 10; i++){
        int j;
        j = 15 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][4] = maxpointLeft;
    }
    
    // main - 7
    maxpointLeft = -2147483648;
    for(int i = 7; i < 10; i++){
        int j;
        j = 16 - i;
      
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][3] = maxpointLeft;
    }
    
    // main - 8
    maxpointLeft = -2147483648;
    for(int i = 8; i < 10; i++){
        int j;
        j = 17 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][2] = maxpointLeft;
    }
    
    // main - 9
    maxpointLeft = -2147483648;
    for(int i = 9; i < 10; i++){
        int j;
        j = 18 - i;
       
        if(maxpointLeft < taxiRoutes[i][j]){
            maxpointLeft = taxiRoutes[i][j];
        }
        maxValuesByDiagonal[1][1] = maxpointLeft;
    }
    
    //Pass values to sherlockaAndWatson
   
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[0][j] = max(maxValuesByDiagonal[0][j + 10], maxValuesByDiagonal[1][19 - j]);
    }
    
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[1][j] = max(maxValuesByDiagonal[0][j + 9], maxValuesByDiagonal[1][-j + 18]);
    }
       
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[2][j] = max(maxValuesByDiagonal[0][j + 8], maxValuesByDiagonal[1][-j + 17]);
    }
        
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[3][j] = max(maxValuesByDiagonal[0][j + 7], maxValuesByDiagonal[1][-j + 16]);
    }
         
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[4][j] = max(maxValuesByDiagonal[0][j + 6], maxValuesByDiagonal[1][-j + 15]);
    }
    
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[5][j] = max(maxValuesByDiagonal[0][j + 5], maxValuesByDiagonal[1][-j + 14]);
    }

    for(int j = 0; j < 10; j++){
        sherlockAndWatson[6][j] = max(maxValuesByDiagonal[0][j + 4], maxValuesByDiagonal[1][-j + 13]);
    }
  
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[7][j] = max(maxValuesByDiagonal[0][j + 3], maxValuesByDiagonal[1][-j + 12]);
    }
 
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[8][j] = max(maxValuesByDiagonal[0][j + 2], maxValuesByDiagonal[1][-j + 11]);
    }
  
    for(int j = 0; j < 10; j++){
        sherlockAndWatson[9][j] = max(maxValuesByDiagonal[0][j + 1], maxValuesByDiagonal[1][-j + 10]);
    }
    
    // Taking Absolute
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(sherlockAndWatson[i][j] < 0){
                sherlockAndWatson[i][j] = abs(sherlockAndWatson[i][j]);
            }
        }
    }
    
    // Calculate conditioned points
    int posi = 0, negav = 0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(taxiRoutes[i][j] > 2 * E3){
                posi += 1;
            }
            else if(taxiRoutes[i][j] < -E3){
                negav += 1;
            }
        }
    }
    
    conditionedPoints(posi);
    conditionedPoints(negav); // meeting point will be (posi, negav)
    
    if(abs(taxiRoutes[posi][negav]) > sherlockAndWatson[posi][negav]){
        dexp1 -= 0.12 * dexp1;
        dexp2 -= 0.12 * dexp2;
        dhp1 -= 0.1 * dhp1;
        dhp2 -= 0.1 * dhp2;
    }
    else{
        dexp1 += 0.12 * dexp1;
        dexp2 += 0.12 * dexp2;
        dhp1 += 0.1 * dhp1;
        dhp2 += 0.1 * dhp2;
    }
    
    EXP1 = roundUp(dexp1);
    EXP2 = roundUp(dexp2);
    HP1 = roundUp(dhp1);
    HP2 = roundUp(dhp2);
    
    maximum_is_600_minimum_is_0(EXP1, EXP2);
    maximum_is_666_minimum_is_0(HP1,  HP2);
    
    dexp1 = static_cast<double>(EXP1);
    dexp2 = static_cast<double>(EXP2);
    dhp1 = static_cast<double>(HP1);
    dhp2 = static_cast<double>(HP2);
    
    if(abs(taxiRoutes[posi][negav]) > sherlockAndWatson[posi][negav]){
        return taxiRoutes[posi][negav];
    }
    else return sherlockAndWatson[posi][negav];
}

void conditionedPoints(int& posi){
    int unit, tens;
    
    unit = posi % 10;
    tens = posi / 10;
    posi = tens + unit;
    
    if(posi >= 10){
        unit = posi % 10;
        tens = posi / 10;
        posi = tens + unit;
    }
}

// Task 4

void checkLengthOfS(const char * s, int& lengthOfS);
int checkConditionsStringS(int lengthOfS);
void getStringse(const char * email, string& se);
int findFirstOccurrence(const char *s, string se);
int comparing2(const char * s, string se, int lengthOfS);
int moreThanTwo(const char * s, int lengthOfS);
int specialCharacters(const char * s, int lengthOfS);
int delimitCharacter(const char * s, int lengthOfS);

int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
    
    int lengthOfS = 0; string se;
    checkLengthOfS(s, lengthOfS); getStringse(email, se);
    
    if(checkConditionsStringS(lengthOfS) != 0){
        return checkConditionsStringS(lengthOfS);
    }
    else if(comparing2(s, se, lengthOfS) != 0){
        return comparing2(s, se, lengthOfS);
    }
    else if(moreThanTwo(s, lengthOfS) != 0){
        return moreThanTwo(s, lengthOfS);
    }
    else if(specialCharacters(s, lengthOfS) != 0){
        return specialCharacters(s, lengthOfS);
    }
    else if(delimitCharacter(s, lengthOfS) != 1000){
        return delimitCharacter(s, lengthOfS);
    }
    else{
        return -10;
    }
}

void checkLengthOfS(const char * s, int& lengthOfS){
    while(s[lengthOfS] != '\0'){
        lengthOfS++;
    }
}

void getStringse(const char * email, string& se){
    int i = 0;
    
    while(email[i] != '@'){
        se += email[i];
        i++;
    }
}

int checkConditionsStringS(int lengthOfS){
    int result = 0;
    
    if(lengthOfS < 8){
        result = -1;
    }
    else if(lengthOfS > 20){
        result = -2;
    }
    
    return result;
}

int comparing(const char * s, string se, int lengthOfS){
    int result = 0;
    if(se.length() > lengthOfS){
        return result;
    }
    else{
        int i = 0, j = 0;
        while(i <= lengthOfS && j <= (se.length() - 1) ){
            if(se[j] == s[i]){
                i++;
                j++;
                result = 0;
                result = static_cast<int>(-(300 + i - se.length() ) );
            }
            else{
                j = 0; i++;
                
                if(se[j] == s[i - 1] && i != 0){
                    i--;
                }
                
                result = 0;
            }
        }
        return result;
    }
}

int comparing2(const char * s, string se, int lengthOfS){
    int result = 0;
    
    if(se.length() == lengthOfS){
        for(int i = 0; i < se.length(); i++){
            if(s[i] != se[i]){
                result = 0;
                break;
            }
            else{
                result = 0;
                result = static_cast<int>(-300);
            }
        }
    }
    
    else if(se.length() > lengthOfS){
        return result;
    }
    
    else if(se.length() == 1){
        for(int i = 0; i < lengthOfS; i++){
            if(se[0] == s[i]){
                return -(300 + i);
            }
        }
    }
    
    else if(se.length() == 2){
        for(int i = 0; i < lengthOfS - 1; i++){
            if(se[0] == s[i] && se[1] == s[i + 1]){
                return -(300 + i);
            }
        }
    }
    
    else if(se.length() == 3){
        for(int i = 0; i < lengthOfS - 2; i++){
            if(se[0] == s[i] && se[1] == s[i + 1] && se[2] == s[i + 2]){
                return -(300 + i);
            }
        }
    }
    
    else{
        int i = 0, j = 0;
        for(i = 0; i < lengthOfS; i++){
            for(j = 0; j < se.length(); j++){
                if(i + j > lengthOfS){
                    break;
                }
                if(s[i + j] == se[j] ){
                    result = 0;
                    result = static_cast<int>(-(300 + i) );
                    if(j == (se.length() - 1) ){ break;}
                }
                else{
                    result = 0;
                    break;
                }
                
            }
            
            if(j == (se.length() - 1) ){break;}
        }
    }
    return result;
}

int moreThanTwo(const char * s, int lengthOfS){
    for(int i = 0; i < lengthOfS - 2; i++){
        if(s[i] == s[i + 1] && s[i + 1] == s[i + 2]){
            return -(400 + i);
        }
    }
    return 0;
}

int specialCharacters(const char * s, int lengthOfS){
    for(int i = 0; i < lengthOfS; i++){
        if(s[i] == '@' || s[i] == '#' || s[i] == '%' || s[i] == '$' || s[i] == '!'){
            return 0;
        }
    }
    return -5;
}

int delimitCharacter(const char * s, int lengthOfS){
    for(int i = 0; i < lengthOfS; i++){
        if(s[i] <= 'z' && s[i] >= 'a'){
            continue;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z'){
            continue;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            continue;
        }
        else if(s[i] == '!' || s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%'){
            continue;
        }
        else return i;
    }
    return 1000;
}

// Task 5

int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
    
    const int num_pwdss = num_pwds;
    
    int numberEachPass[num_pwdss];
    
    for(int i = 0; i < num_pwds; i++){
        numberEachPass[i] = 1;
    }
  
    
    for(int i = 0; i < num_pwds; i++){
        for(int j = i + 1; j <= num_pwds; j++){
            if(arr_pwds[i] == arr_pwds[j]){
                numberEachPass[i] += 1;
            }
        }
        
    }
   
    
    int lengthEachPass[num_pwdss];
    for(int i = 0; i < num_pwds; i++){
        string reference;
        reference += arr_pwds[i];
        lengthEachPass[i] = static_cast<int>(reference.length() );
    }
   
    
    for(int i = 0; i < num_pwds; i++){
        for(int j = i + 1; j <= num_pwds; j++){
            if(arr_pwds[i] == arr_pwds[j]){
                numberEachPass[j] = 0;
            }
            
        }
    }
    
    
    
    int max = 0;
    int maxLength = 0;
    int index = 0;
    
    for(int i = 0; i < num_pwds; i++){
        if(max < numberEachPass[i]){
            max = numberEachPass[i];
            
        }
    }
   
    
    for(int i = 0; i < num_pwds; i++){
        if(numberEachPass[i] < max){
            numberEachPass[i] = 0;
        }
    }
    
    
    
    for(int i = 0; i < num_pwds; i++){
        if(max == numberEachPass[i] && maxLength < lengthEachPass[i] ){
            maxLength = lengthEachPass[i];
            index = i;
        }
    }
    
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
