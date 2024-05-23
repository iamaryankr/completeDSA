#include<iostream>
#include<cstring>  //for functions
#include<string.h>   //for class of string
using namespace std;
int main(){
    char S1[50]="Hello",S2[50]="hello";
    string str="aryan";
    string str5="";
    //string class
    cout<<str.length();
    cout<<str.append("hi");
    cout<<str.insert(3,"k");
    cout<<str.replace(3,4,"k");
    str.push_back('K');
    str.pop_back();
    str.swap(str5);
    cout<<str.find("a");
    cout<<str.rfind("r");


   //string operations
   string s1= "Hello", s2="_World";
   string s3=s1+s2; 
   cout<<s3;
   s2=s1;
   cout<<s2;


string::iterator it;
for(it=str.begin(); it!=str.end();it++){
    cout<<*it;
}
cout<<endl;
string::reverse_iterator rit;
for(rit=str.rbegin();rit!=str.rend();rit++){
    cout<<*rit;
}
//changing case
for(int i=0;str[i]!=0;i++){
    str[i]-=32;
}
cout<<str;

//counting vowels
string str1="HowmanyVowels";
int vowels=0,space=0,consonants=0;
for(int i=0; str1[i]!=0;i++){
    if(str1[i]=='A'||str1[i]=='E'||str1[i]=='I'||str1[i]=='O'||str1[i]=='U'
    ||str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u')
                    vowels++;
    else if(str[i]==' '){
        space++;
    }
    else
        consonants++;
}
cout<<vowels<<endl<<space<<endl<<consonants;

//palindrome 
string str2="madam";
string rev="";
int len=str2.length();
rev.resize(len);
for(int i=0, j=len-1;i<len; i++,j--){
    rev[i]=str2[j];
}
rev[len]='\0';
if(str2.compare(rev)==0) cout<<"Palindrome";
else cout<<"not a palindrome";

//string functions
    cout<<strlen(S1)+strlen(S2);
    cout<<strncat(S1,S2,4);
    cout<<strcpy(S1,S2);
    cout<<strstr(S1,S2);
    cout<<strcmp(S1,S2);

//strtok()
    char S[50]="x=10;y=20;z=30";
    char *token= strtok(S,"=;");
    while(token!=NULL){
        cout<<token<<endl;
        token=strtok(NULL,"=;");
    }
return 0;
}