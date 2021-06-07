#include  <iostream>
#include <cmath>
#define ull unsigned long long int
using namespace std;

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

int main(){

    char c = 'a';

    int R1 = 200;
    int G1 = 70;
    int B1 = 90;
    int R2 = 230;

    cout<<int(c)<<endl;
    
    int dec_num, r;
    string hexdec_num="";
    char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	dec_num = 220;
		
        while(dec_num>0)
        {
            r = dec_num % 16;
            hexdec_num = hex[r] + hexdec_num;
            dec_num = dec_num/16;
        }
        cout<<" The hexadecimal number is : "<<hexdec_num[0]<<"\n";
 
    // cout << decimalToBinary(N) <<endl;
 
    return 0;
}
