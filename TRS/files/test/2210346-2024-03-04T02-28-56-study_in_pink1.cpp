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
int check_HP(int a){
	return (a < 0) ? 0 : ((a > 666) ? 666 : a);
}
int check_EXP(int a){
    return (a < 0) ? 0 : ((a > 600) ? 600 : a);
}
int check_M(int a){
    return (a < 0) ? 0 : ((a > 3000) ? 3000 : a);
}
// Task 1
int firstMeet(int & exp1, int & exp2, int e1) {
    // TODO: Complete this function
    if((e1 < 0) || (e1 > 99)) return -99;
    exp1 = check_EXP(exp1);
    exp2 = check_EXP(exp2); 
   
    
    if((e1>=0)&&(e1<=3)){
        int expToAdd[] = {29, 45, 75, 149};
        exp2 += expToAdd[e1]; exp2 = check_EXP(exp2); //Kiem tra lai exp2
        int D = 3 * e1 + 7 * exp1;
        float temp = (D % 2 == 0) ? exp1 + D / 200.0 : exp1 - D / 100.0;
        exp1 = check_EXP(static_cast<int>(ceil(temp)));
	}
	if((e1 >= 4)&&(e1 <= 99)){	
		float temp1 = e1/4.0 + 19;
		float temp2 = e1/9.0 + 21;
		float temp3 = e1/16.0 + 17;
		
		if((e1 >= 4) && (e1 <= 19)){ //giai thich tt1
			exp2 = check_EXP(static_cast<int>(ceil(exp2 + temp1)));// exp2 = check_EXP(exp2); //kiem tra lai exp2
		}
		else if((e1 >= 20) && (e1 <= 49)){ //giai thich tt2
			exp2 = check_EXP(static_cast<int>(ceil(exp2+ temp2))); //exp2 = check_EXP(exp2); //kiem tra lai exp2
		}
		else if((e1 >= 50) && (e1 <= 65)){ //giai thich tt3
			exp2 = check_EXP(static_cast<int>(ceil(exp2 + temp3))); //exp2 = check_EXP(exp2); //kiem tra lai exp2
		}
		else if((e1 >= 66) && (e1 <= 79)){
			//giai thich tt1
			exp2 = check_EXP(static_cast<int>(ceil(exp2 + temp1))); //exp2 = check_EXP(exp2); //kiem tra lai exp2
			if (exp2 > 200){	//giai thich tt2
				exp2 = check_EXP(static_cast<int>(ceil(exp2 + temp2))); //exp2 = check_EXP(exp2); //kiem tra lai exp2
			}
		}
		else{
			//giai thich tt1
			exp2 = check_EXP(static_cast<int>(ceil(exp2 + temp1))); //exp2 = check_EXP(exp2);
			//giai thich tt2
			exp2 = check_EXP(static_cast<int>(ceil(exp2 + temp2))); //exp2 = check_EXP(exp2);
			if(exp2 > 400){
				//giai thich tt3
				exp2 = check_EXP(static_cast<int>(ceil(exp2 + temp3))); //exp2 = check_EXP(exp2);
				// exp cong them 15%
				exp2 = check_EXP(static_cast<int>(ceil(1.15*exp2)));// exp2 = exp2);
			}
		}
		exp1 -=e1;exp1 = check_EXP(exp1); //kiem tra lai exp1
	}

	return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) {
    // TODO: Complete this function: HP, EXP, M lam tron len ngay
    if((E2 < 0) || (E2 > 99)) return -99;
    HP1 = check_HP(HP1);    // HP = 500
    EXP1 = check_EXP(EXP1); // EXP1 = 225
    M1 = check_M(M1);       // M1 =3000
    
    
    //Road 01
	int sqrtEXP1_R1 = sqrt(EXP1), lowerSquare_R1 = sqrtEXP1_R1 * sqrtEXP1_R1, upperSquare_R1 = (sqrtEXP1_R1 + 1) * (sqrtEXP1_R1 + 1);
	int S_R1 = ((EXP1 - lowerSquare_R1 < upperSquare_R1 - EXP1) ? lowerSquare_R1 : upperSquare_R1);		//S_R1 : S in Road 01
	float P_R1 = (EXP1 >= S_R1) ? 1 : (static_cast<float>(EXP1) / S_R1 + 80.0) / 123.0; //khong lam tron! //P_R1 : S in Road 01
    
	//Road 02		
	switch(E2 % 2){
		case 1: {
			int M1_start = M1;
			while(true){
				//Event 01
				if(HP1 < 200){
					HP1 = check_HP(static_cast<int>(ceil(HP1*1.3))); // da lam tron!
					M1 = check_M(M1 - 150);
					if (150 > 0.5*M1_start) break;
				}
				else{
					HP1 = check_HP(static_cast<int>(ceil(HP1*1.1))); // da lam tron!
					M1 = check_M(M1 - 70);
					if (70 > 0.5*M1_start) break;
					
				}
				//Event 02
				M1 = (EXP1 < 400) ? check_M(M1 - 200) : check_M(M1 - 120); 
				EXP1 = check_EXP(static_cast<int>(ceil(EXP1*1.13))); // da lam tron!
				if (M1_start - M1 > 0.5*M1_start) break;

				//Event 03
				M1 = (EXP1 < 300) ? check_M(M1 - 100) : check_M(M1 - 120); 
				EXP1 = check_EXP(static_cast<int>(ceil(EXP1*0.9))); // da lam tron!
				if (M1_start - M1 > 0.5*M1_start) break;
			}
			HP1 = check_HP(static_cast<int>(ceil(HP1*0.83))); // da lam tron!
			EXP1 = check_EXP(static_cast<int>(ceil(EXP1*1.17)));
		}
		break;
		case 0: {
			do{
				//Event 01
				if(HP1 < 200){
					HP1 = check_HP(static_cast<int>(ceil(HP1*1.3))); // da lam tron!
					M1 = check_M(M1 - 150);
					if (M1 == 0) break;
				}
				else{
					HP1 = check_HP(static_cast<int>(ceil(HP1*1.1))); // da lam tron!
					M1 = check_M(M1 - 70);
					if (M1 == 0) break;
				}

				//Event 02
				M1 = (EXP1 < 400) ? check_M(M1 - 200) : check_M(M1 - 120);
				EXP1 = check_EXP(static_cast<int>(ceil(EXP1*1.13))); // da lam tron!
				if (M1 == 0) break;

				//Event 03
				M1 = (EXP1 < 300) ? check_M(M1 - 100) : check_M(M1 - 120);
				EXP1 = check_EXP(static_cast<int>(ceil(EXP1*0.9))); // da lam tron!
				if (M1 == 0) break;

			} while(false);
			HP1 = check_HP(static_cast<int>(ceil(HP1*0.83))); // da lam tron!
			EXP1 = check_EXP(static_cast<int>(ceil(HP1*1.17)));
		}
        break;
	}
	int sqrtEXP1_R2 = sqrt(EXP1), lowerSquare_R2 = sqrtEXP1_R2 * sqrtEXP1_R2, upperSquare_R2 = (sqrtEXP1_R2 + 1) * (sqrtEXP1_R2 + 1);
	int S_R2 = ((EXP1 - lowerSquare_R2 < upperSquare_R2 - EXP1) ? lowerSquare_R2 : upperSquare_R2);			//S_R2 : S in Road 02
	float P_R2 = (EXP1 >= S_R2) ? 1 : (static_cast<float>(EXP1) / S_R2 + 80.0) / 123.0; //khong lam tron!		//P_R2 : P in Road 02
	
    //Road 03
	float a[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
	int i;
  	if (E2 < 10) {
    	i = E2;
  	} else {
    	i = (E2 / 10) + (E2 % 10);	//E1 trong doan [0,99]
        if (i >= 10) i %= 10;        //vd: 8 + 7 = 15; 15%10 = 5
  	}
  	float P_R3 = 0.01*a[i];	//vi xac suat P trong mang a[] la % nen nhan 0.01
	
    //
	if((P_R1 == 1) && (P_R2 == 1) && (P_R3 == 1)) EXP1 = check_EXP(static_cast<int>(ceil(EXP1*0.75)));
	else {
		float averageP = (P_R1 + P_R2 + P_R3)/3.0;
		if (averageP < 0.5){
			HP1 = check_HP(static_cast<int>(ceil(HP1*0.85)));
			EXP1 = check_EXP(static_cast<int>(ceil(EXP1*1.15)));
			//cout << "HP1_final = " << HP1 << " , " << "EXP1_final = " << EXP1 << endl;
		}
		else{
			HP1 = check_HP(static_cast<int>(ceil(HP1*0.9))); //HP1 *=0.9;
			EXP1 = check_EXP(static_cast<int>(ceil(EXP1*1.2))); //EXP1 *=1.2;
		}
	}
	
    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if((E3 < 0) || (E3 > 99)) return -99;
    HP1 = check_HP(HP1);
    EXP1 = check_EXP(EXP1);
    HP2 = check_HP(HP2);
    EXP2 = check_EXP(EXP2);
    
    //Tao ma tran 10x10 va nhap gia tri cho ma tran
    int taxi_score[10][10], i, j;
    for(i = 0; i < 10; i++){
    	for(j = 0; j < 10; j++){
    		taxi_score[i][j] = ((E3 * j) + (i * 2)) * (i - j);
		}
	}
	
	int counter_greater_2E3 = 0; int counter_smaller_E3 = 0;
	for(i = 0; i < 10; i++){
		for(j = 0; j < 10; j++){
			if(taxi_score[i][j] > 2*E3) counter_greater_2E3++;
			if(taxi_score[i][j] < -E3) counter_smaller_E3++;
		}
	}
	
	i = counter_greater_2E3;
	j = counter_smaller_E3;

  	if (i >= 10){		//
	 	while (i >= 10){
		  	int temp = i;
		  	int sum = 0;
		 	while (temp > 0){
			  	sum += temp % 10;
			  	temp /= 10;
			}
		  	i = sum;
		}
	}
  	if (j >= 10){
	  	while (j >= 10){
		  	int temp = j;
		  	int sum = 0;
		  	while (temp > 0){
			  	sum += temp % 10;
			  	temp /= 10;
			}
		  	j = sum;
		}
	}
    
    
    //tim duong cheo trai
    int i_temp, j_temp, arr[20], number = 1;
    arr[0] = taxi_score[i][j];
    i_temp = i;
    j_temp = j;
    while(true){
        i_temp++;
        j_temp++;
        if(i_temp >= 10 || j_temp >= 10) break;
        arr[number] = taxi_score[i_temp][j_temp];
        number++;
    }
    
    i_temp = i;
    j_temp = j;
    while(true){
        i_temp--;
        j_temp--;
        if((i_temp < 0) || (j_temp < 0)) break;
        arr[number] = taxi_score[i_temp][j_temp];
        number++;
    }
    //cout <<  i_temp << " " << j_temp <<" " <<number<<endl;

    //tim duong cheo phai
    i_temp = i;
    j_temp = j;
    while(true){
        i_temp++;
        j_temp--;
        if((i_temp >= 10) || (j_temp < 0)) break;
        arr[number] = taxi_score[i_temp][j_temp];
        number++;
    }
    //cout <<  i_temp << " " << j_temp <<" " <<number<<endl;
    i_temp = i;
    j_temp = j;
    while(true){
        i_temp--;
        j_temp++;
        if(i_temp < 0 || j_temp >= 10) break;
        arr[number] = taxi_score[i_temp][j_temp];
        number++;
    }
    
    int SherlockWatson_score = arr[0];
    for(int idx = 0; idx < 20; idx++){
        if(SherlockWatson_score < arr[idx]) SherlockWatson_score = arr[idx];
    }
    
    int result;
    if(abs(SherlockWatson_score) < abs(taxi_score[i][j])){
    	result = taxi_score[i][j];
        EXP1 = check_EXP(static_cast<int>(ceil(EXP1*0.88)));
		EXP2 = check_EXP(static_cast<int>(ceil(EXP2*0.88)));
        HP1 = check_HP(static_cast<int>(ceil(HP1*0.9)));
		HP2 = check_HP(static_cast<int>(ceil(HP1*0.9)));
    }
    else{
    	result = SherlockWatson_score;
        EXP1 = check_EXP(static_cast<int>(ceil(EXP1*1.12)));
		EXP2 = check_EXP(static_cast<int>(ceil(EXP2*1.12)));
        HP1 = check_HP(static_cast<int>(ceil(HP1*1.1)));
		HP2 = check_HP(static_cast<int>(ceil(HP1*1.1)));
    }
    return result;
}

// Task 4
int checkPassword(const char * s, const char * email) {
    // Xac dinh length cua email
	int idx1 = 0, idx2 = 0, length_email = 0, length_s = 0;
	while(email[idx1] != '\0'){
	    length_email++;
	    idx1++;
	}

	// Xac dinh length cua s
	while(s[idx2] != '\0'){
	    length_s++;
	    idx2++;
	}

	
	// Xac dinh chuoi ky tu(se) truoc '@' trong dia chi email
	string se = "";          // first@...
    for(int idx = 0; idx < length_email; idx++){
        if(email[idx] == '@') break;
        se +=email[idx];
    }
	//cout << se << endl;
	
	// Yeu cau ve do dai
    if(length_s < 8) return -1;
    else if (length_s > 20) return -2;
    
    
    char special_char[5] = {'@', '#', '%', '$', '!'}; 
    
    
    int pstn, j = 0;
    // Yeu cau khong chua se
    for(int i = 0; i < length_s; i++){
        if(s[i] == se[j]){
            pstn = i;
            while(s[i] == se[j]){
               i++;
               j++;
               if(j > length_s) break;
            }
            return -(300 + pstn);
        }
        // Yeu cau khong chua nhieu hon 2 ky tu lien tiep giong nhau
        else if(s[i+1] == s[i]){
            pstn = i;
            i++;
            if(s[i+1] == s[i]) return -(400+ pstn);
        }
    }
    
    // Yeu cau phai chua it nhat 1 ky tu dac biet
    for(int i = 0; i < length_s; i++){
        for(int j = 0; j < 5; j++){
            if(s[i] != special_char[j]) continue;
            else return -10;    // Mat khau hop le thì tra ve -10
        }
    }
	return -5;
	
	
    //return -99;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
	
	// TODO: Complete this function
	
	int max_count = 0;
    int max_length = 0;
    const char* most_frequent_password = nullptr;
    int first_occurrence_index;  // Ð? luu tr? v? trí xu?t hi?n d?u tiên

    for (int i = 0; i < num_pwds; ++i) {
        int current_count = 1;  // Ð?t s? l?n xu?t hi?n cho m?i m?t kh?u là 1 (chính nó)
        
        for (int j = i + 1; j < num_pwds; ++j) {
            if (strcmp(arr_pwds[i], arr_pwds[j]) == 0) {
                ++current_count;
            }
        }

        if (current_count > max_count || (current_count == max_count && strlen(arr_pwds[i]) > max_length)) {
            max_count = current_count;
            max_length = strlen(arr_pwds[i]);
            most_frequent_password = arr_pwds[i];
            first_occurrence_index = i;  // C?p nh?t v? trí xu?t hi?n d?u tiên
        }
    }
    
    
	//cout << "first_occurrence_index = " << first_occurrence_index << endl;
	return first_occurrence_index;
	
    //return -1;
}

////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////
