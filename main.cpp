#include <pixel.hpp>


int main() {

	stream streamIn;
	stream streamOut;


	for (int y = 0; y < 2; y++) {
	    for (int x = 0; x < 2; x++) {
	    	for (int z = 0;z < 2; z++){
	    	pkt_t tmp;
	        tmp.data = 255;
	        tmp.user = (x == 0) && (y == 0)&&(z==0);
	        tmp.last = (x == 26);
	        streamIn.write(tmp);
	    	}
	    }
	}
	ap_int<32> a;
    ap_int<32> selector,position1,position2,stream_count;
    selector=0;
    position1=1;
    position2=1;
    stream_count=1;
    a=50;
    pixel(selector,position1,position2,stream_count,a,streamIn,streamOut);

    for (int y = 0; y < 2; y++) {
    	    for (int x = 0; x < 2; x++) {
    	    	for (int z = 0;z < 2; z++){
            pkt_t tmp = streamOut.read();
            printf("%d",tmp.data);
        }
    }
    }


    return 0;

}




