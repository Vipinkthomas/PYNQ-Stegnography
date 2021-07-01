#include "pixel.hpp"
#include <iostream>

int main() {

	stream streamIn;
	stream streamOut;
	pkt_t tmp;
	ap_int<32> indecimal;
	ap_int<32> a;
	ap_int<32> selector,position1,position2,stream_count;
		selector=0; //encode
		//selector=1; //decode
		stream_count=8;
	    indecimal=72;

	for (int y = 0; y < stream_count; y++) {

	        tmp.data = 255;
	        tmp.user = (y == 0);
//	        tmp.last = (y == position2);
	        streamIn.write(tmp);
	        std::cout << "input: " << tmp.data << std::endl;

	        pixel(indecimal,selector,stream_count,streamIn,streamOut);

	        tmp = streamOut.read();
	        std::cout << "Output: " << tmp.data << std::endl;
	    	}


	if(selector==1){
		std::cout << "Value decoded: " << indecimal << std::endl;
	}
	else if(selector==0){
		std::cout << "Value encoded: " << indecimal << std::endl;
	}

    return 0;

}


