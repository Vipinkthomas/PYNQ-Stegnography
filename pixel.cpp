#include <stdio.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include<math.h>
#include <string.h>

using namespace std;
typedef ap_int<32> apint;
typedef ap_axis<32,0,0,0> pkt_t;
typedef hls::stream< pkt_t > stream;

//Initializations
static int count_streams = 0;    //counter of data input streams
static long long charIn=0;       // to store binary values for each charachter decimal val
static long long final_char=0;   // binary value of decoded data
int addNum=0;                    // holds lsb of CharIn
static int decNum = 0;           //holds the decimal value for all characters
static int decimalCounter = 0;   //used to shift to other charachter decimal value
static int decimalOut = 0;       // holds the decimal value of the characters (decoding)
int lastDecimalVal;              //holds decimal value of one character

long long convert(int n);
int convertBinInt(long long n);
void decrypt(int data);
void toAscii(char *c);
int getDecimal(int n);
pkt_t tmpA;

void pixel(apint &in_decimal,
        apint selector,
		apint stream_count,
		stream &din,
		stream &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE s_axilite port=in_decimal
    #pragma HLS INTERFACE s_axilite port=selector
	#pragma HLS INTERFACE s_axilite port=stream_count
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

    din >> tmpA;

    switch(selector)
    {
        case 0:
            
            if (count_streams == 0){
                final_char=0;
                decNum = in_decimal;
            }

                addNum=0;
                if(decimalCounter % 8 == 0){
                    lastDecimalVal = getDecimal(decNum);
                    decNum /= 100;
                    charIn=convert(lastDecimalVal);
                    
                }
                addNum=charIn%10;
		        charIn=(int)charIn/10;

                if(tmpA.data % 2 == 0 && addNum == 1){
                    tmpA.data += 1;
                    
                }else if(tmpA.data % 2 != 0 && addNum == 0){
                    tmpA.data -= 1;
                    
                }
                decimalCounter++;

            break;

        case 1:
                
                
                decrypt(tmpA.data);
                decimalCounter++;
                if(decimalCounter == 8){
                    decimalOut=decimalOut*100+convertBinInt(final_char);  
                    decimalCounter=0;
                    final_char=0;   
                }
            
                
            break;

        default:
            break;
    }
	
	count_streams++;

	if (count_streams == stream_count){
		count_streams = 0;
        charIn=0;
        addNum=0;
        decimalCounter=0;
        if(selector == 1){
            final_char=0;
            in_decimal=decimalOut;
            decimalOut=0;
        }

	}

    if(count_streams == stream_count){
	        tmpA.last = 1;
	    }
	    tmpA.strb = 0xf;

	    dout << tmpA;

}


long long convert(int n) {
    /**/
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

void decrypt(int data) {
    /**/
int bit;
if(data % 2 == 0){
   bit = 0;
}else if(data % 2 != 0){
    bit=1;
}
final_char= final_char*10+bit;

}

int convertBinInt(long long n) {
    /**/
int dec = 0, i = 7, b=0,rem=0;
    while (n != 0) {
        b=pow(10,i);
        rem = n / b;
        n =n % b;
        dec += rem * pow(2, 7-i);
        --i;
    }
    return dec;
}

int getDecimal(int n) {
    /**/
    int num = 0;
    num = n % 100;
    return num;
    }

