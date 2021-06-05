//TODO : Add 2 modes, one for making fpga manipulate pixels and one mode for read out the steganographic charachter
#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count_streams = 0;

void pixel(
		ap_int<32> position,
		ap_int<32> stream_count,
		hls::stream< pkt_t > &din,
		hls::stream< pkt_t > &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=position
	#pragma HLS INTERFACE s_axilite port=stream_count
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

	pkt_t pkt=din.read();
	count_streams++;
	
	if(count_streams > 3 * (position - 1) && count_streams <= 3 * (position)){
		pkt.data -= 1;
	}

	if (count_streams == stream_count){
		count_streams = 0;
		
	}

	dout.write(pkt);

}
