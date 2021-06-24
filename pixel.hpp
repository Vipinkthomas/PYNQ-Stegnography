#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

using namespace std;
typedef ap_axis<32,0,0,0> pkt_t;
typedef hls::stream< pkt_t > stream;
void pixel(ap_int<32> selector,
		ap_int<32> position1,
		ap_int<32> position2,
		ap_int<32> stream_count,
		ap_int<32> ascii,
		stream &din,
		stream &dout

);

long long convert(int n);
int convertBinInt(long long n);
void decrypt(int data);
