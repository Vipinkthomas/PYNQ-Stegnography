#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <hls_stream.h>
#include <ap_axi_sdata.h>

//#include <string.h>
//#include <array>

//const auto N = 1<<2;  // array size
//using vec_t = std::array<char, N>;

using namespace std;
typedef ap_axis<32,1,1,1> pkt_t;


typedef hls::stream< pkt_t > stream;

void pixel(ap_int<32> &in_decimal,
	        ap_int<32> selector,
			ap_int<32> position1,
			ap_int<32> position2,
			hls::stream< pkt_t > &din,
			hls::stream< pkt_t > &dout

	);

long long convert(int n);
int convertBinInt(long long n);
void decrypt(int data);
int getDecimal(int n);
