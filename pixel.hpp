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
void decode(int data);
void toAscii(char *c);
int getDecimal(int n);
pkt_t tmpA;

