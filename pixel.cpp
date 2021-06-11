#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <cmath>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count_streams = 0;
static long long charIn=0;
static int addNum=0;
static int decrpyt=0;
static long long asciiNum=0;
static int asciiVal=0;

long long convert(int n); 
long long toAscii(chr number);
int convertBinInt(long long n);
char stegnoDcrypt(int data);
void stegno(char c);

void pixel(
		ap_int<32> position1,
		ap_int<32> position2,
		ap_int<32> w,
		ap_int<32> h,
		ap_int<32> character,
        ap_int<32> selector,
		hls::stream< pkt_t > &din,
		hls::stream< pkt_t > &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=position1
	#pragma HLS INTERFACE s_axilite port=position2
	#pragma HLS INTERFACE s_axilite port=w
	#pragma HLS INTERFACE s_axilite port=h
	#pragma HLS INTERFACE s_axilite port=character
	#pragma HLS INTERFACE s_axilite port=selector  //switch for encrypt and decrypt
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

	pkt_t pkt=din.read();

	switch(selector)
    {
        case 0:
            stegno(character);
            break;

        case 1:
            stegnoDecrypt(pkt.data);
            break;

        default:
            break;
    }

	count_streams++;

	if (count_streams == w*h*3){
		count_streams = 0;
        asciiVal= convertBinInt(asciiNum);
        pkt.data=asciiVal
        dout.write(pkt);
	}

	// pending: have to make count=0 when TLAST signal is active -  for w not in the range of 0 to n(size of the array)
	//(count_streams==(position1+3*count_streams*w))&&((position1+3*count_streams*w) < position2) || (count_streams2==(position1
	//+3*count_streams*w)) && ((position2-3*count_streams*w) > position1)

    dout.write(pkt);
}

void stegno(char c){
    
    // to check
	charIn=toAscii(c);
	if(count_streams > 3 * (position1 - 1) && count_streams < 3 * (position2)){
		addNum=charIn%10;
		charIn=(int)charIn/10;
		pkt.data=convertBinInt((convert(pkt.data)/10)*10+addNum);
		
	}
    
}

long long stegnoDcrypt(int data){

    decrpyt=convert(data)%10;

    asciiNum=asciiNum*10+decrpyt;
	
}
    

long long convert(int n) {
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

int convertBinInt(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

long long toAscii(char c) {
    int n=(int)c;
    long long bin = convert(n);
    return bin;     
}
