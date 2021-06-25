#include "pixel.hpp"
#include <iostream>

int main() {

	stream streamIn;
	stream streamOut;

	pkt_t tmp;
	ap_int<32> a;
	ap_int<32> selector,position1,position2,stream_count;
		selector=0;
	    position1=1;
	    position2=3;
	    stream_count=27;
	    a=50;

	for (int y = 0; y < 3; y++) {
	    for (int x = 0; x < 3; x++) {
	    	for (int z = 0;z < 3; z++){

	        tmp.data = 255;
	        tmp.user = (x == 0) && (y == 0)&&(z==0);
	        tmp.last = (y == 2);
	        streamIn.write(tmp);
	        std::cout << "input: " << tmp.data << std::endl;

	        pixel(selector,position1,position2,stream_count,a,streamIn,streamOut);

	        tmp = streamOut.read();
	        std::cout << "Output: " << tmp.data << std::endl;
	    	}
	    }
	}


    return 0;

}
