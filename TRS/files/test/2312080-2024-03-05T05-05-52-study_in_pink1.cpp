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

	// id = 0: hp, id = 1: exp, id = 2: m
int standard(int id, int x) {
    x = max(0, x);

    switch (id)
    {
    // hp
    case 0:
        x = min(x, 666);
        break;
    
    case 1:
        x = min(x, 600);
        break;

    case 2:
        x = min(x, 3000);
        break;
    }
    return x ; 
}


// Task 1
int firstMeet(int& EXP1, int& EXP2, int E1) {
    if (E1 < 0 || E1 > 99)
        return -99;

    EXP1 = standard(1, EXP1);
    EXP2 = standard(1, EXP2);

    if ( E1 >= 0 && E1 <=3 ) {
        int exp[] = {29, 45, 75, 149} ;
        EXP2 = standard(1, EXP2 + exp[E1]);
        int D = E1*3 + EXP1*7 ; 
        if (D % 2 == 0) 
            EXP1 = standard(1, ceil(EXP1 + D/200.00)); 
        else 
            EXP1 = standard(1, ceil(EXP1 - D/100.00)); 

    }        
    if ( E1 >=4 && E1 <= 99) {
        if ( E1 >= 4 && E1 <= 19) {
            EXP2 = standard(1, ceil(EXP2 + (E1/4.00 + 19))) ;
        }
        if ( E1 >= 20 && E1 <= 49) {
            EXP2 = standard(1, ceil(EXP2 + (E1/9.00 + 21))) ;
        }
        if ( E1 >= 50 && E1 <= 65) {
            EXP2 = standard(1, ceil(EXP2 + (E1/16.00 + 17))) ;
        }
        if ( E1 >= 66 && E1 <= 79) {
            EXP2 = standard(1, ceil(EXP2 + (E1/4.00 + 19))) ;
            if (EXP2 > 200 )
                EXP2 = standard(1, ceil(EXP2 + (E1/9.00 + 21))) ;
        }
        if ( E1 >= 80 && E1 <= 99) {
            EXP2 = standard(1, ceil(EXP2 + (E1/4.00 + 19)));
            EXP2 = standard(1, ceil(EXP2 + (E1/9.00 + 21)));
            if (EXP2 > 400 ) {
                EXP2 = standard(1, ceil(EXP2 + (E1/16.00 + 17))) ;
                EXP2 = standard(1, ceil(EXP2 + 0.15*EXP2));
            }
        }
        EXP1 = standard(1, EXP1 - E1) ; 
    }
    return EXP1 + EXP2 ;
}


// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    if (E2 < 0 || E2 > 99)
        return -99;

    HP1 = standard(0, HP1);
    EXP1 = standard(1, EXP1);
    M1 = standard(2, M1);

    double S, P1, P2 ; 
    double p3[] = {0.32, 0.47, 0.28, 0.79, 1.00, 0.50, 0.22, 0.83, 0.64, 0.11} ;
    int m = 0 ; 
    // ** CON DUONG 1  
    S = round(sqrt(EXP1)) ; 
    S = S*S ; 
    if ( EXP1 >= S )
        P1 = 1 ; 
    else 
        P1 = ( EXP1 / (S*1.00) + 80 ) / 123.00 ; 
    
    // ** CON DUONG 2
    // if E2 la so le 
    if ( E2%2 == 1 ){
        double M1_50 = M1*0.50 ; 
        while ( true ) {
            // mua nuoc hoac thuc an
            
            if ( HP1 < 200 ) {
                HP1 = standard(0, ceil(HP1 + 0.30 * HP1)) ; 
                m += 150 ; 
                M1 = standard(2, M1 - 150) ; 
            }
            else {
                HP1 = standard(0, ceil(HP1 + 0.10 * HP1)) ;
                m += 70 ;  
                M1 = standard(2, M1 - 70 ); 
            }  
            
            if ( m > M1_50 ) {
                
                HP1 = standard(0, ceil(HP1 - 0.17*HP1)) ; 
                EXP1 = standard(1, ceil(EXP1 + 0.17*EXP1)) ; 
                
                S = round(sqrt(EXP1)) ; 
                S = S*S ; 
                if ( EXP1 >= S )
                    P2 = 1 ; 
                else 
                    P2 = ( EXP1 / (S*1.00) + 80 ) / 123.00 ;  
                break ;
            }
            // di taxi hoac xe ngua
            if ( EXP1 < 400 ) {
                m += 200 ; 
                EXP1 = standard(1, ceil(EXP1 + 0.13 * EXP1)) ;
                M1 = standard(2, M1 - 200) ; 
            }
            else {
                m += 120 ; 
                EXP1 = standard(1, ceil(EXP1 + 0.13 * EXP1)) ;
                M1 = standard(2, M1 - 120) ; 
            }
            if ( m > M1_50 ) {
                
                HP1 = standard(0, ceil(HP1 - 0.17*HP1)) ; 
                EXP1 = standard(1, ceil(EXP1 + 0.17*EXP1)) ; 
                
                S = round(sqrt(EXP1)) ; 
                S = S*S ; 
                if ( EXP1 >= S )
                    P2 = 1 ; 
                else 
                    P2 = ( EXP1 / (S*1.00) + 80 ) / 123.00 ;  
                break ;
            }
            
            // nghe loi nguoi vo gia cu 
            if ( EXP1 < 300 ) {
                m += 100 ;
                EXP1 = standard(1, ceil(0.9 * EXP1)) ;
                M1 = standard(2, M1 - 100) ; 
            }
            else {
                m += 120 ; 
                EXP1 = standard(1, ceil(0.9 * EXP1)) ;
                M1 = standard(2, M1 - 120) ; 
            }
            if ( m > M1_50 ) {
                
                HP1 = standard(0, ceil(0.83*HP1)    ) ; 
                EXP1 = standard(1, ceil(1.17*EXP1)) ; 
                
                S = round(sqrt(EXP1)) ; 
                S = S*S ; 
                if ( EXP1 >= S )
                    P2 = 1 ; 
                else 
                    P2 = ( EXP1 / (S*1.00) + 80 ) / 123.00 ;  
                break ;
            }
        }  
    }
    else { // E2 la so chan
        // mua nuoc hoac thuc an
        while ( m < M1 ) {
            if ( HP1 < 200 ) {
                HP1 = standard(0, ceil(HP1 + 0.3 * HP1)) ; 
                m += 150 ; 
                M1 = standard(2, M1 - 150) ; 
            } else {
                HP1 = standard(0, ceil(HP1 + 0.1 * HP1)) ;
                m += 70; 
                M1 = standard(2, M1 - 70); 
            }  

            if ( M1 == 0 ) {                
                break ;
            }
            // di taxi hoac xe ngua
            if ( EXP1 < 400 ) {
                m += 200 ; 
                M1 = standard(2, M1 - 200) ; 
                EXP1 = standard(1, ceil(EXP1 + 0.13 * EXP1)) ;
            }
            else {
                m += 120 ; 
                M1 = standard(2, M1 - 120) ; 
                EXP1 = standard(1, ceil(EXP1 + 0.13 * EXP1)) ;
            }
            if ( M1 == 0 ) {
                break ;
            }
            // nghe loi nguoi vo gia cu 
            if ( EXP1 < 300 ) {
                m += 100 ;
                M1 = standard(2, M1 - 100) ; 
                EXP1 = standard(1, ceil(EXP1 - 0.1 * EXP1)) ;
            }
            else {
                m += 120 ; 
                M1 = standard(2, M1 - 120) ; 
                EXP1 = standard(1, ceil(EXP1 - 0.1 * EXP1)) ;
            }
            if ( M1 == 0 ) {
                break ;
            }
            break ; 
        }
        HP1 = standard(0, ceil(HP1 - 0.17*HP1)) ; 
        EXP1 = standard(1, ceil(EXP1 + 0.17*EXP1)) ;
        S = round(sqrt(EXP1)) ; 
        S = S*S ; 
        if ( EXP1 >= S )
            P2 = 1 ; 
        else 
            P2 = ( EXP1 / (S*1.00) + 80 ) / 123.00 ;     

    }  
    
    // **CON DUONG 3 
    int i, a, b ;
    double P3 ; 
    if ( E2 <= 9 )
        P3 = p3[E2] ; 
    else {
        a = E2 / 10 ;
        b = E2 % 10 ; 
        i = a+b ; 
        P3 = p3[i%10] ; 
    }
    
    // ** P1, P2, P3 SAU 3 CON DUONG
    if ( P1 == 1 && P2 == 1 && P3 == 1)
        EXP1 = standard(1, ceil(EXP1 - 0.25 * EXP1)) ; 
    else {
        double p = (P1 + P2 + P3) / 3.00 ;
        
        if ( p < 0.50 ) {
            HP1 = standard(0, ceil(HP1 - 0.15* HP1)) ;
            EXP1 = standard(1, ceil(EXP1 + 0.15* EXP1)) ;
        }
        else {
            HP1 = standard(0, ceil(HP1 - 0.1* HP1)) ;
            EXP1 = standard(1, ceil(EXP1 + 0.2* EXP1)) ;
        }
    }
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {

    if (E3 < 0 || E3 > 99)
        return -99;

    HP1 = standard(0, HP1);
    EXP1 = standard(1, EXP1);
    HP2 = standard(0, HP2);
    EXP2 = standard(1, EXP2);

    int matrix[10][10] ; 
    int itaxi, jtaxi ; 
    // TẠO MA TRẬN
    for (int i = 0 ; i < 10 ; i++){
        for (int j = 0 ; j < 10 ; j++){
            matrix[i][j] = ((E3*j) + (i*2)) * (i-j) ; // Giá trị của mỗi tọa độ
        }
    }
    // TÌM VỊ TRỊ CỦA TAXI DỰA TRÊN E3, i, j
    int countgreater = 0 , countleast = 0 ; // Tạo 2 biến đếm ban đầu
    for ( int i = 0 ; i < 10 ; i++ ){
        for ( int j = 0 ; j < 10 ; j++){
            if ( matrix[i][j] > E3*2 ) // Nếu giá trị tại tọa độ i, j của ma trận lớn hơn 2*E3
                countgreater ++ ; // Biến đếm số grater tăng 1 
        }
    }

    for ( int i = 0 ; i < 10 ; i++){
        for ( int j = 0 ; j < 10 ; j++){
            if ( matrix[i][j] < 0 && matrix[i][j] < -1 * E3 ) // Nếu giá trị tại tọa độ i, j của ma trận là số âm (< 0) và nhỏ hơn - E3 
                countleast ++ ; // Biến đếm số least tăng 1 
        }
    }

    
    while ( countgreater > 9 ) // Khi biến đếm số greater là số chục 
        countgreater = countgreater / 10 + countgreater % 10 ; // Lấy hàng chục + hàng đơn vị
    itaxi = countgreater ; // Tọa độ i của taxi = biến số đếm greater sau khi xử lý 
    
    
    while ( countleast > 9 ) // Khi biến đếm số least là số chục
        countleast = countleast / 10 + countleast % 10 ; // Lấy hàng chục + hàng đơn vị
    jtaxi = countleast ; // Tọa độ j của taxi = biến số đếm least sau khi xử lý 
    
    
    // SO SÁNH CÁC PHẦN TỬ TRÊN ĐƯỜNG CHÉO TRÁI VÀ PHẢI KHI CÓ i, j CỦA TAXI
    int maxvalueofmatrixcross ; 
    maxvalueofmatrixcross = matrix[itaxi][jtaxi] ; // Đặt giá trị tại tọa độ ban đầu là giá trị lớn nhất
    for ( int m = 0 ; m <= 9 ; m ++ ){ // Tạo vòng for tăng/ giảm i, j để so sánhh các phần tử thuộc đường chéo
        if ( itaxi + m <= 9 && jtaxi + m <= 9 ){
            if ( matrix[ itaxi + m][ jtaxi + m] > maxvalueofmatrixcross) // So sánh các phần tử trên đường chéo chính theo thứ tự tăng dần
                maxvalueofmatrixcross = matrix[ itaxi + m][ jtaxi + m] ; // Nếu tồn tại giá trị tại tọa độ khác nằm trên đường chéo chính mà lớn hơn giá trị lớn nhất ban đầu, thế giá trị đó vào
        }
    }
    
    for ( int m = 0 ; m <= 9 ; m ++ ){ // Tạo vòng for tăng/ giảm i, j để so sánhh các phần tử thuộc đường chéo
        if ( itaxi - m <= 0 && jtaxi - m >= 9 ){
            if ( matrix[ itaxi - m][ jtaxi - m] > maxvalueofmatrixcross) // So sánh các phần tử trên đường chéo chính theo thứ tự giảm dần
                maxvalueofmatrixcross = matrix[ itaxi - m][ jtaxi - m] ; // Nếu tồn tại giá trị tại tọa độ khác nằm trên đường chéo chính mà lớn hơn giá trị lớn nhất ban đầu, thế giá trị đó vào
        }
    }    
    for ( int m = 0 ; m <= 9 ; m ++ ){ // Tạo vòng for tăng/ giảm i, j để so sánhh các phần tử thuộc đường chéo
        if ( itaxi + m <= 9 && jtaxi - m >= 0 ){
            if ( matrix[ itaxi + m][ jtaxi - m] > maxvalueofmatrixcross)  // So sánh các phần tử trên đường chéo phụ theo i tăng, j giảm
                maxvalueofmatrixcross = matrix[ itaxi + m][ jtaxi - m] ; // Nếu tồn tại giá trị tại tọa độ khác nằm trên đường chéo chính mà lớn hơn giá trị lớn nhất ban đầu, thế giá trị đó vào
        }
    }
    
    for ( int m = 0 ; m <= 9 ; m ++ ){ // Tạo vòng for tăng/ giảm i, j để so sánhh các phần tử thuộc đường chéo
        if ( itaxi - m >= 0 && jtaxi + m <= 9 ){
            if ( matrix[ itaxi - m][ jtaxi + m] > maxvalueofmatrixcross)  // So sánh các phần tử trên đường chéo phụ theo i giảm, j tăng
                maxvalueofmatrixcross = matrix[ itaxi - m][ jtaxi + m] ; // Nếu tồn tại giá trị tại tọa độ khác nằm trên đường chéo chính mà lớn hơn giá trị lớn nhất ban đầu, thế giá trị đó vào
        }
    }
    
    // So sánh giá trị tuyệt đối của Taxi và giá trị lớn nhất trong 2 đường chéo
    if ( abs(matrix[itaxi][jtaxi]) > maxvalueofmatrixcross ){ // Nếu giá trị tuyệt đối của Taxi lớn hơn
        EXP1 = standard(1, ceil(EXP1 - EXP1 * 0.12)) ; 
        HP1 = standard(0, ceil(HP1 - HP1 * 0.1)) ;
        EXP2 = standard(1,ceil(EXP2 - EXP2 * 0.12)) ;
        HP2 = standard(0,ceil(HP2 - HP2 * 0.1)) ;
        return matrix[itaxi][jtaxi] ; // Trả về giá trị của Taxi
    }
    else { // Nếu giá trị tuyệt đối của taxi nhỏ hơn
        EXP1 = standard(1, ceil(EXP1 + EXP1 * 0.12)) ; 
        HP1 = standard(0, ceil(HP1 + HP1 * 0.1)) ;
        EXP2 = standard(1,ceil(EXP2 + EXP2 * 0.12)) ;
        HP2 = standard(0,ceil(HP2 + HP2 * 0.1)) ;
        return maxvalueofmatrixcross ; // Trả về giá trị của giá trị lớn nhất
    }
}

// Task 4
// NOTE: s và email là 2 biến char -> sử dụng str.len()
//       password và se là 2 biến string -> sử dụng "ten_bien".length() 
int checkPassword(const char * s, const char * email) {
    string password = "" , se = "" ; 
    for ( int i = 0 ; i < strlen(s) ; i++ )
        password += s[i] ; 
    
    for ( int i = 0 ; i < strlen(email) ; i ++){
        if ( email[i] == '@' )
            break ;
        se += email[i] ;
         
    }
    
    // Kiem tra chieu dai mat khau 
    if ( password.length() < 8 )
        return -1 ; 
    if ( password.length() > 20 )
        return -2 ; 
    
    if (se.length() == 0)
        return -300;

    // Kiem tra mat khau co chua 'se' khong
    for ( int i = 0 ; i < password.length() ; i ++ ){
        if ( password[i] == se[0] ){
            if ( password.substr(i, se.length()) == se )
                return -(300 + i ) ;
        }
    }
    
    // Kiem tra so ki tu lap lai >2
    int repeat = 0 ;
    for ( int i = 0 ; i < password.length() ; i ++ ){
        if ( password[i - 1] == password[i] && i > 0 ){
            repeat ++ ;
            if ( repeat == 2 )
                return -(400 + (i - 2)) ; 
    
        } else repeat = 0;
    }
    
    // Kiem tra mat khau co chua ki tu dac biet khong
    int special_char = 0 ; 
    for ( int i = 0 ; i < password.length() ; i++ ){
        if ( password[i] == '@' || password[i] == '#' || password[i] == '%' || password[i] == '$' || password[i] == '!' )
            special_char ++ ; 
    }
    if ( special_char == 0 )
        return -5 ; 
    
    // Kiem tra su hop le cua tat ca cac ki tu
    int first_violate = 0 ; 
    for ( int i = 0 ; i < password.length() ; i++ ){
        if (password[i] != '@' && password[i] != '#' && password[i] != '%' && password[i] != '$' && password[i] != '!' &&
        !isalpha(password[i]) && !isdigit(password[i]))
            return i ;

    }
    return - 10 ; 

}

// Task 5
int findCorrectPassword(const char* arr_pwds[], int num_pwds) {

    int count[100] = {} ;
    for ( int i = 0 ; i < num_pwds ; i ++ ) {
        for (int m = 0 ; m < num_pwds ; m ++)
            if (!strcmp(arr_pwds[i], arr_pwds[m]))
                count[i] ++ ;
    }
    
    int index = 0 ;
    for ( int i = 1 ; i < num_pwds ; i ++ ) 
        if ( (count[i] > count[index]) || count[i] == count[index] && strlen(arr_pwds[i]) > strlen(arr_pwds[index]) )
            index = i ;
    
    return index;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////