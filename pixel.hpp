#include <stdio.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include<math.h>
#include <string.h>

using namespace std;
typedef ap_int<32> apint;
typedef ap_axis<32,0,0,0> pkt_t;
typedef hls::stream< pkt_t > stream;

/*Initializations*/
static int count_streams = 0;    //counter of data input streams
static long long charIn=0;       // to store binary values for each charachter decimal val
static long long final_char=0;   // binary value of decoded data
int addNum=0;                    // holds lsb of CharIn
static int decNum = 0;           //holds the decimal value for all characters
static int decimalCounter = 0;   //used to shift to other charachter decimal value
static int decimalOut = 0;       // holds the decimal value of the characters (decoding)
int lastDecimalVal;              //holds decimal value of one character

long long convert(int n);       //This function converts a decimal number to a Binary number and returns it
int convertBinInt(long long n); //This function returns decimal value from a binary number
void decode(int data);          //get the binary value of the embedded ascii values by combining the LSBs.
int getDecimal(int n);          //returns the last two digits (which represents one character) of the corresponding ascii values passed to this function.
pkt_t tmpA;

