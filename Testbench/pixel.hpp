#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

using namespace std;
typedef ap_int<32> apint;
typedef ap_axis<32,1,1,1> pkt_t;


typedef hls::stream< pkt_t > stream;

void pixel(apint &in_decimal,
	        apint selector,
			apint stream_count,
			stream &din,
			stream &dout
	);

long long convert(int n);
int convertBinInt(long long n);
void decode(int data);
int getDecimal(int n);
