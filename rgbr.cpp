#include  <iostream>
#include <cmath>
#define ull unsigned long long int
using namespace std;
char s[2];
string l;
int decimalToBinary(int N)
{
 
    // To store the binary number
    ull B_Number = 0;
    int cnt = 0;
    while (N != 0) {
        int rem = N % 2;
        ull c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
 
        // Count used to store exponent value
        cnt++;
    }
 
    return B_Number;
}

string DecToHex(int decimalNum)
{
     int rem, i=0;
    char hexaDecimalNum[2];
    
    while(decimalNum!=0)
    {
        rem = decimalNum%16;
        if(rem<10)
            rem = rem+48;
        else
            rem = rem+55;
        hexaDecimalNum[i] = rem;
        i++;
        decimalNum = decimalNum/16;
    }
    // cout<<"\nEquivalent Hexadecimal Value: ";
    for(i=i-1; i>=0; i--)
        s[i] = hexaDecimalNum[i];
    // cout<<endl;
    return hexaDecimalNum;
}

void hexToBin(string hexa){ 
    long int i = 0;
    
   while (hexa[i]){
      switch (hexa[i]){
      case '0':
         l +=  "0000";
         break;
      case '1':
         l +=  "0001";
         break;
      case '2':
         l +=  "0010";
         break;
      case '3':
         l +=  "0011";
         break;
      case '4':
         l +=  "0100";
         break;
      case '5':
         l +=  "0101";
         break;
      case '6':
         l +=  "0110";
         break;
      case '7':
         l +=  "0111";
         break;
      case '8':
         l +=  "1000";
         break;
      case '9':
         l +=  "1001";
         break;
      case 'A':
      case 'a':
         l +=  "1010";
         break;
      case 'B':
      case 'b':
         l +=  "1011";
         break;
      case 'C':
      case 'c':
         l +=  "1100";
         break;
      case 'D':
      case 'd':
         l +=  "1101";
         break;
      case 'E':
      case 'e':
         l +=  "1110";
         break;
      case 'F':
      case 'f':
         l +=  "1111";
         break;
      default:
        cout<<"S";
         
      }
   i++;
   }
//    return l;
}

int main(){

    char c = 'a';

    int R1 = 200;
    int G1 = 70;
    int B1 = 90;
    int R2 = 230;

    // cout<<int(c)<<endl;
    
    // int dec_num, r;
    // string hexdec_num="";
    // char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	// dec_num = 220;
		
    //     while(dec_num>0)
    //     {
    //         r = dec_num % 16;
    //         hexdec_num = hex[r] + hexdec_num;
    //         dec_num = dec_num/16;
    //     }
    //     cout<<" The hexadecimal number is : "<<hexdec_num[0]<<"\n";
 
    // cout << decimalToBinary(N) <<endl;
    // hexToBin("a");
    // char s[2];
    // s = DecToHex(33);
    string cc = s;
    cout<<DecToHex(61)<<endl;
    // hexToBin(h);
    // cout<<s[0]<<endl;
    std::string s12{s[1], s[0]};
    
    cout<<s12<<endl;

    hexToBin(s12);
    cout<<l<<endl;
    return 0;
}
