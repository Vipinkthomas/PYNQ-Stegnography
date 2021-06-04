#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;



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
	static int count=0;

	

	if(counter==w){
		pkt.data*=2;
	}
	else if(counter< w){
		count++;
	}
	else{
		counter=0;
	}
	


	dout.write(pkt);

}
