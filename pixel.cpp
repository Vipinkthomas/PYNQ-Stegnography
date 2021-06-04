//TODO -- Add mode 1 to modify pixels , 2 to read out the steganographic charachter

#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count = 0;
static int count_streams = 0;
static bool flag = false;

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
	// if(count == position){
	// 	pkt.data -= 1;
	// 	flag = true;
	// 	count = 0;
		

	// }else if(!flag){
	// 	count++;
	// }
	
	if (count_streams == stream_count){
		count_streams = 0;
		//flag = false;
	}

	// pending: have to make count=0 when TLAST signal is active -  for w not in the range of 0 to n(size of the array) 


	dout.write(pkt);

}
