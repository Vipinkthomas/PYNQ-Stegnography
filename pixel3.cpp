#include <stdio.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include<math.h>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count_streams = 0;
static long long charIn1=0;
static long long charIn2=0;
static long long charIn3=0;
int addNum1=0;
int addNum2=0;
int addNum3=0;
static int cnt=0;

long long toAscii(int number);
long long convert(int n);
int convertBinInt(long long n);


void pixel(
		ap_int<32> position1,
		ap_int<32> position2,
		ap_int<32> stream_count,
		ap_int<32> ascii1,
        ap_int<32> ascii2,
        ap_int<32> ascii3,
		hls::stream< pkt_t > &din,
		hls::stream< pkt_t > &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=position1
	#pragma HLS INTERFACE s_axilite port=position2
	#pragma HLS INTERFACE s_axilite port=stream_count
	#pragma HLS INTERFACE s_axilite port=ascii1
    #pragma HLS INTERFACE s_axilite port=ascii2
    #pragma HLS INTERFACE s_axilite port=ascii3
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

	pkt_t pkt=din.read();
    if (count_streams == 0){
        charIn1=toAscii(ascii1);
        charIn2=toAscii(ascii2);
        charIn3=toAscii(ascii3);
    }

    if((count_streams >= 3 * (position1 - 1)) && (count_streams < 3 * (position2)) && (charIn1!=0) && (charIn2!=0) && (charIn3!=0)){
        
        if(cnt <= 7){
            addNum1=charIn1%10;
            pkt.data = convertBinInt((convert(pkt.data)/10)*10+addNum1);
            charIn1=(int)charIn1/10;
        }else if(cnt > 7 && cnt <= 15){
            addNum2=charIn2%10;
            pkt.data = convertBinInt((convert(pkt.data)/10)*10+addNum2);
            charIn2=(int)charIn2/10;
        }else if(cnt >15 && cnt <= 23){
            addNum3=charIn3%10;
            pkt.data = convertBinInt((convert(pkt.data)/10)*10+addNum3);
            charIn3=(int)charIn3/10;

        }

        cnt++;

    }


	count_streams++;

	if (count_streams == stream_count){
		count_streams = 0;
        charIn1=0;
        addNum1=0;
        charIn2=0;
        addNum2=0;
        charIn3=0;
        addNum4=0;
        cnt = 0;

	}

    dout.write(pkt);
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


long long toAscii(int c) {
    long long bin = convert(c);
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
