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

int rnd(int ans, int a, bool tr)
{
	int k=int(ans/a);
	if(ans%a==0||!tr)
	return k;
	return k+1;
}
int check(int & ansep)
{
	if(ansep>600) ansep=600;
	if(ansep<0) ansep=0;
	return ansep;
}
// Task 1
int firstMeet(int & exp1, int & ex2, int e1) {
    // TODO: Complete this function
    if(e1>99||e1<0) return -99;
    check(exp1);
    check(ex2);	
    if(e1<=3)
   { if(e1==0) ex2=ex2+29;
    else if(e1==1) ex2=ex2+45;
    else if(e1==2) ex2=ex2+75;
    else if(e1==3) ex2=ex2+149;
    int d=e1*3+exp1*7;
    //cout<<d<<'\n';
    if(d%2) exp1=exp1-rnd(d,100,0);
    else exp1=exp1+rnd(d,200,1);
   }
   else 
   {
     //cout<<ceil(e1/7)<<'\n';
   	 if(e1<=19) ex2+=rnd(e1,4,1)+  19;
   	 else if(e1<=49) ex2+=rnd(e1,9,1) + 21;
   	 else if(e1<=65) ex2+=rnd(e1,16,1) + 17;
   	 else if(e1<=79) 
   	 {
   	 	ex2+=rnd(e1,4,1)+19;
   	 	if(ex2>200) ex2+=rnd(e1,9,1)+21;
   	 }
   	 else if(e1<=99) 
   	 {
   	 	ex2+=rnd(e1,4,1)+19+rnd(e1,9,1)+21;
   	 	if(ex2>400)
   	 	{ ex2+=rnd(e1,16,1)+17;
   	 	  ex2+=rnd(ex2*15,100,1);
   	 	}
   	 }	
   	 exp1-=e1;
   }
   check(exp1);
    check(ex2);
   // cout<<exp1<<" "<<ex2;
    return exp1 + ex2;
}

// Task 2
int findsquare(int num)
{
	int tmp=sqrt(num);
	if(num-tmp*tmp>(tmp+1)*(tmp+1)-num)
	return (tmp+1)*(tmp+1);
	return tmp*tmp;
}
int findp(int EXP1)
{
  int P;
  int s=findsquare(EXP1);
  if(EXP1>=s) return 100;
  P=rnd((rnd(EXP1,s,1)+80)*100,123,1);
  return P;
}
int checkm(int & ansm)
{
	if(ansm>3000) ansm=3000;
	if(ansm<0) ansm=0;
	return ansm;
}
int checkhp(int & anshp)
{
	if(anshp>666) anshp=666;
	if(anshp<0) anshp=0;
	return anshp;
}
int P[15] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
int traceLuggage(int & HP1, int & EXP1, int & M1, int E3) {
    // TODO: Complete this function
  // cout<<findsquare(EXP1);
  if(E3>99||E3<0) return -99;
  checkm(M1);
  	check(EXP1);
  	checkhp(HP1);
  int P1=findp(EXP1);
  double money=M1/2;
  int tmp=0;
  if(E3%2)
  {
  	while(tmp<=money)
  	{
  		if(HP1<200)
  		{
  			HP1=rnd(HP1*13,10,1);
  			M1-=150;
  			tmp+=150;
  		}
  		else
  		{
  			HP1=rnd(HP1*11,10,1);
  			M1-=70;
  			tmp+=70;
  		}
  		check(EXP1);
  	checkhp(HP1);
  	checkm(M1);
  		if(tmp<=money)
  		{
  			if(EXP1<400)
  			{	
  				M1-=200;
  				tmp+=200;
  			}
  			else
  			{
  			M1-=120;
  			tmp+=120;
  			}
  		   EXP1=rnd(EXP1*113,100,1);
  		   check(EXP1);
  	checkhp(HP1);
  	checkm(M1);
  //	cout<<tmp<<" "<<money<<" "<<M1<<endl;
  		   if(tmp<=money)
  		   {//cout<<M1<<endl;
  		   	if(EXP1<300)
  		   	{
  		   		M1-=100;
  		   		tmp+=100;
  		   		
  		   	}
  		   	else
  		   	{
  		   		M1-=120;
  		   		tmp+=120;
  		   	}
  		   	EXP1=rnd(EXP1*9,10,1);
  		   	check(EXP1);
  	checkhp(HP1);
  	checkm(M1);
  		   }
  		}
  	}
  }
  else
  {
  	if(HP1<200)
  		{
  			HP1=rnd(HP1*13,10,1);
  			M1-=150;
  			tmp+=150;
  		}
  		else
  		{
  			HP1=rnd(HP1*11,10,1);
  			M1-=70;
  			tmp+=70;
  		//	cout<<HP1<<endl;
  		}
  		check(EXP1);
  	checkhp(HP1);
  	checkm(M1);
  		if(M1>0)
  		{
  			if(EXP1<400)
  			{	
  				M1-=200;
  				tmp+=200;
  			}
  			else
  			{
  			M1-=120;
  			tmp+=120;
  			}
  		   EXP1=rnd(EXP1*113,100,1);
  		   checkm(M1);
  		   checkhp(HP1);
  	check(EXP1);
  //	cout<<tmp<<" "<<money<<" "<<M1<<endl;
  		   if(M1>0)
  		   {//cout<<M1<<endl;
  		   	if(EXP1<300)
  		   	{
  		   		M1-=100;
  		   		tmp+=100;
  		   		
  		   	}
  		   	else
  		   	{
  		   		M1-=120;
  		   		tmp+=120;
  		   	}
  		   	EXP1=rnd(EXP1*9,10,1);
  		   	checkm(M1);
  		   	checkhp(HP1);
  	check(EXP1);
  		   }
  		}
  	
  }
  HP1=rnd(HP1*83,100,1);
  	EXP1=rnd(EXP1*117,100,1);
  	check(EXP1);
  	checkhp(HP1);
  	checkm(M1);
  	int P2=findp(EXP1);
  	int vali, E2;
  	E2=E3;
  	if(E2>=10)
  	vali=E2/10+E2%10;
  	else vali=E2;
  	vali=vali%10;
  	int P3=P[vali];
  	if(P1==P2&&P2==P3&&P3==100)
  	{ EXP1=rnd(EXP1*75,100,1);
  	check(EXP1);
  	checkm(M1);
  	check(EXP1);
  	checkhp(HP1);
  	return HP1 + EXP1 + M1;}
  	int avP=rnd((P1+P2+P3),3,1);
  	if(avP>50)
  	{
  		HP1=rnd(HP1*9,10,1);
  		EXP1=rnd(EXP1*12,10,1);
  	}
  	else 
  	{
  		HP1=rnd(HP1*85,100,1);
  		EXP1=rnd(EXP1*115,100,1);
  	}
  	checkm(M1);
  	check(EXP1);
  	checkhp(HP1);  
  //	cout<<HP1<<" "<< EXP1<<" "<<M1<<endl;
 // cout<<P1<<" "<<EXP1<<" "<<P2;
    return HP1 + EXP1 + M1;
 
}

// Task 3
int taximark[15][15];
int taxi[300];
int to1num( int number)
{
	int k1=number, k2;
	k2=k1/10+k1%10;
	k1=k2/10+k2%10;
	return k1;
}
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3) {
    // TODO: Complete this function
    if(E3>99||E3<0) return -99;
  	check(EXP1);
  	checkhp(HP1);
  	check(EXP2);
  	checkhp(HP2);
    int i1=0, j1=0;
    for(int i=0;i<=9;i++)
	for(int j=0;j<=9;j++)
	{
		taximark[i][j]= ((E3*j) + (i*2))*(i - j);
		if(taximark[i][j]>2*E3)
		++i1;
		if(taximark[i][j]<(-1)*E3)
		++j1;
	}
	int ita=to1num(i1);
	int jta=to1num(j1);
	int maxr=-1e6;
	for(int i=0;i<=min(jta, 9-ita);i++)
	maxr=max(maxr, taximark[ita+i][jta-i]);
	for(int i=0;i<=min(ita, 9-jta);i++)
	maxr=max(maxr, taximark[ita-i][jta+i]);
	for(int i=0;i<=min(jta,ita);i++)
	maxr=max(maxr, taximark[ita-i][jta-i]);
	for(int i=0;i<=min(9-jta,9-ita);i++)
	maxr=max(maxr, taximark[ita+i][jta+i]);
	//cout<<E3<<" "<<HP1<<" "<<EXP1<<" "<<HP2<<" "<<EXP2<<'\n';
	if(abs(maxr)<abs(taximark[ita][jta]))
	{
		//	cout<<maxr;
		//cout<<(EXP1*88)%100<<'\n';
		EXP1=rnd(EXP1*88,100,1);
		EXP2=rnd(EXP2*88,100,1);
		HP1=rnd(HP1*9,10,1);
		HP2=rnd(HP2*9,10,1);
		check(EXP1);
  	checkhp(HP1);
  	check(EXP2);
  	checkhp(HP2);
		//cout<<taximark[ita][jta];
		
		
		//cout<<E3<<" "<<HP1<<" "<<EXP1<<" "<<HP2<<" "<<EXP2<<'\n';
	return taximark[ita][jta];
	}
	else
	{
		EXP1=rnd(EXP1*112,100,1);
		EXP2=rnd(EXP2*112,100,1);
		HP1=rnd(HP1*11,10,1);
		HP2=rnd(HP2*11,10,1);
		check(EXP1);
  	checkhp(HP1);
  	check(EXP2);
  	checkhp(HP2);
  	//cout<<E3<<" "<<HP1<<" "<<EXP1<<" "<<HP2<<" "<<EXP2<<'\n';
return maxr;
	}
	
//	cout<<jta<<" "<<ita<<'\n';
    
/*	for(int i=0;i<=9;i++)
	{for(int j=0;j<=9;j++)
	cout<<taximark[i][j]<<" ";
	cout<<'\n';
	}*/
    return -1;
}
int checkin(const char * s, string se)
{
if(strlen(s)<se.size()) return -1;
	for(int i=0;i<strlen(s)-se.size()+1;i++)
	{
		if(s[i]==se[0])
		{
			int si=0;
			for(int j=0;j<se.size();j++)
			{
				if(s[i+j]!=se[j])
				break;
				++si;
			}
			if(si==se.size())
			return i;
		}
	}
	return -1;
}
int checkconsecchar(const char * s)
{
	for(int i=0;i<strlen(s)-2;i++)
	{
		if(s[i]==s[i+1]&&s[i+1]==s[i+2])
		return i;
	}
	return -1;
}
bool checkspechar(const char * s)
{
	for(int i=0;i<strlen(s);i++)
	if(s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='!')
	return 1;
	return 0;
}
int checkwrocha(const char * s)
{
	for(int i=0;i<strlen(s);i++)
	{
		if((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57)||s[i]=='@'||s[i]=='#'||s[i]=='$'||s[i]=='%'||s[i]=='!')
		continue;
		else return i;
	}
	return -1;
}
// Task 4
int checkPassword(const char * s, const char * email) {
    // TODO: Complete this function
   // cout<<s<<" "<<email<<'\n';
if(strlen(s)<8) return -1;
    if(strlen(s)>20) return -2;
    string se="";
    int chek=-1;
    int ck=0;
    for(int i=0;i<strlen(email);i++)
    {
    	if(email[i]=='@')
    	break;
    se+=email[i];
++ck;
    }
   
    int fs1, fs2, fs3;
    if(strlen(s)<8) chek=2;
    if(strlen(s)>20) chek=3;
    if(checkin(s, se)!=-1)
    {chek=4; fs1=checkin(s, se);}
  //  cout<<checkin(s, se);
    if(checkconsecchar(s)!=-1)
    {
    	chek=5; fs2=checkconsecchar(s);
    }
    if(!checkspechar(s)) chek=6;
    if(checkwrocha(s)!=-1) chek=7, fs3=checkwrocha(s);
    if(chek==-1) return -10; 
    if(ck==0) return -300;
    if(checkin(s, se)!=-1) return -(300+fs1);
    if(checkconsecchar(s)!=-1) return -(400+fs2);
    if(!checkspechar(s)) return -5;
    if(checkwrocha(s)!=-1) return fs3;
    //int a='9';
   // cout<<a;
   // cout<<se;
    return -99;
}

// Task 5
struct value
{
	int wid;
	int lange;
	bool check;
};
value *arr;
int findCorrectPassword(const char * arr_pwds[], int num_pwds) {
    // TODO: Complete this function
arr=new value[1000];
//memset(arr,0, sizeof(arr));
   // if(comp(arr_pwds[40],arr_pwds[41])) cout<<"appect"<<'\n';
   // cout<<num_pwds<<endl;
for(int i=0;i<num_pwds;i++)
arr[i].check=0;
    for(int i=0;i<num_pwds;i++)
    {
    //	cout<<arr_pwds[i]<<'\n';
    	if(!arr[i].check)
    	{
    		arr[i].check=1;
    		int lange=0;
    		for(int j=i;j<num_pwds;j++)
    		{
    		  	if(strcmp(arr_pwds[i],arr_pwds[j])==0)
    	{//	cout<<arr_pwds[i]<<" "<<arr_pwds[j]<<'\n';
    		arr[j].check=1;
    		++lange;
    	}
    		}
    
    	arr[i].wid=lange;
    	
    	}
else arr[i].wid=-1;
    }
    int maxwid=-1;
    for(int i=0;i<num_pwds;i++)
    maxwid=max(maxwid,arr[i].wid);
   // cout<<maxwid<<'\n';
    for(int i=0;i<num_pwds;i++)
    if(arr[i].wid==maxwid)
    { int siz=strlen(arr_pwds[i]);
    	arr[i].lange=siz;
    }
else arr[i].lange=-1;
    int maxl=-1;
    for(int i=0;i<num_pwds;i++)
    maxl=max(maxl, 	arr[i].lange);
//return maxl;
//return maxwid;
int ans;
    for(int i=0;i<num_pwds;i++)
    if(arr[i].lange==maxl)
    {
    	ans=i;
break;
    }
 delete arr;
return ans;
    return -1;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////