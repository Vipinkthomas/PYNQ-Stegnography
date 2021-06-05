#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count_streams = 0;


void pixel(
		ap_int<32> position1,
		ap_int<32> position2,
		ap_int<32> w,
		ap_int<32> h,
		hls::stream< pkt_t > &din,
		hls::stream< pkt_t > &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=position1
	#pragma HLS INTERFACE s_axilite port=position2
	#pragma HLS INTERFACE s_axilite port=w
	#pragma HLS INTERFACE s_axilite port=h
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

	pkt_t pkt=din.read();

	
	if((position1+3*count_streams*w) < position2 || (position2-3*count_streams*w) > position1){
		pkt.data -= 1;
	}
	
	count_streams++;

	if (count_streams == w*h*3){
		count_streams = 0;
	}

	// pending: have to make count=0 when TLAST signal is active -  for w not in the range of 0 to n(size of the array)


	dout.write(pkt);

}

