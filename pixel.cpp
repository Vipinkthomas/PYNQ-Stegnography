#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int counter = 0;
static bool flag=false;


void pixel(
		ap_int<32> w,
		hls::stream< pkt_t > &din,
		hls::stream< pkt_t > &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=w
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

	pkt_t pkt=din.read();


	if(counter==w){
		pkt.data*=2;
		flag=true;
		counter=0;

	}
	else if(!flag){
	counter++;
	}
	// pending: have to make count=0 when TLAST signal is active -  for w not in the range of 0 to n(size of the array) 


	dout.write(pkt);

}
