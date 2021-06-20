//TODO : Add 2 modes, one for making fpga manipulate pixels and one mode for read out the steganographic charachter
#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <cmath>


#define ull unsigned long long int

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count_streams = 0;
static char s[2];
static char x[2];
static char hexbin[8]={'0','0','0','0','0','0','0','0'};

static int cnnt = 0;


void DecToHex(int decimalNum);
void hexToBin(char hexa[2]);
void setBin(int i, char a, char b, char c, char d);




void pixel(
		ap_int<32> position,
		ap_int<32> charachter_in_decimal,
		ap_int<32> stream_count,
		hls::stream< pkt_t > &din,
		hls::stream< pkt_t > &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
	#pragma HLS INTERFACE s_axilite port=position
	#pragma HLS INTERFACE s_axilite port=charachter_in_decimal
	#pragma HLS INTERFACE s_axilite port=stream_count
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

	pkt_t pkt=din.read();

	if(count_streams == 0){

		DecToHex(charachter_in_decimal);
		x[0] = s[1];
   		x[1] = s[0];
		
		hexToBin(x);

	}
	
	// if(count_streams > 3 * (position - 1) && count_streams <= 3 * (position) + 1){
// 		pkt.data -= 1;
// 	}
//count_streams < 4

	if(count_streams >= 3 * (position - 1) && count_streams < ( 3 * position) + 1){

       
        if(hexbin[cnnt] == '0' && hexbin[cnnt+1] == '1'){
           if(pkt.data >= 1){
               pkt.data -= 1;
           }else{
              pkt.data += 1;
           }
                         
        }else if(hexbin[cnnt] == '1' && hexbin[cnnt+1] == '0'){
           if(pkt.data >= 2){
               pkt.data -= 2;
           }else{
              pkt.data += 2;
           }
            
        }else if(hexbin[cnnt] == '1' && hexbin[cnnt+1] == '1'){
           if(pkt.data >= 3){
               pkt.data -= 3;
           }else{
              pkt.data += 3;
           }
            
        }
        cnnt += 2;   
    }


	
	count_streams++;

   if (count_streams == stream_count){
		count_streams = 0;
      
      cnnt = 0;


		
	}
   

	dout.write(pkt);

}


void DecToHex(int decimalNum)
{
     int rem, i=0;
    char hexaDecimalNum[2];
    
    while(decimalNum!=0)
    {
        rem = decimalNum%16;
        if(rem<10)
            rem = rem+48;
        else
            rem = rem+55;
        hexaDecimalNum[i] = rem;
        i++;
        decimalNum = decimalNum/16;
    }
    
    for(i=i-1; i>=0; i--)
        s[i] = hexaDecimalNum[i];
    
   //  return hexaDecimalNum;
}


void setBin(int i, char a, char b, char c, char d){
   if(i == 0){
	hexbin[0] = a;
	hexbin[1] = b;
	hexbin[2] = c;
	hexbin[3] = d;
   }else{
      hexbin[4] = a;
      hexbin[5] = b;
      hexbin[6] = c;
      hexbin[7] = d;
   }

}
void hexToBin(char hexa[2]){ 
   cout<<"yes"<<endl;
   long int i = 0;
   while(i < 2){
   if(hexa[i] == '0'){
      setBin(i,'0','0','0','0');
   }else if(hexa[i] == '1'){
      setBin(i,'0','0','0','1');
   }else if(hexa[i] == '2'){
      setBin(i,'0','0','1','0');
   }else if(hexa[i] == '3'){
      setBin(i,'0','0','1','1');
   }else if(hexa[i] == '4'){
      setBin(i,'0','1','0','0');
   }else if(hexa[i] == '5'){
      setBin(i,'0','1','0','1');
   }else if(hexa[i] == '6'){
      setBin(i,'0','1','1','0');
   }else if(hexa[i] == '7'){
      setBin(i,'0','1','1','1');
   }else if(hexa[i] == '8'){
      setBin(i,'1','0','0','0');
   }else if(hexa[i] == '9'){
      setBin(i,'1','0','0','1');
   }else if(hexa[i] == 'a' || hexa[i] == 'A'){
      setBin(i,'1','0','1','0');
   }else if(hexa[i] == 'b' || hexa[i] == 'B'){
      setBin(i,'1','0','1','1');
   }else if(hexa[i] == 'c' || hexa[i] == 'C'){
      setBin(i,'1','1','0','0');
   }else if(hexa[i] == 'd' || hexa[i] == 'D'){
      setBin(i,'1','1','0','1');
   }else if(hexa[i] == 'e' || hexa[i] == 'E'){
      setBin(i,'1','1','1','0');
   }else if(hexa[i] == 'f' || hexa[i] == 'F'){
      setBin(i,'1','1','1','1');
   }
   
   i++;
   }
   }

//    void LSB(int num)
// {   
//       // cout<<(num & (1 << 1));
//       if (num & (1 << 1)){
//          hexbin[c] = '1';
//       }else{
//          hexbin[c] = '0';
//       }

//       if (num & (1 << 0)){
//          hexbin[c+1] = '1';
//       }else{
//          hexbin[c+1] = '0';
//       }

//       c+=2;  
    
// }

// int binToDecimal(char arr[8]){
//    int v = 0;
//    if (arr[7] == '1'){
//       v += 1;
//    }
//    if (arr[6] == '1'){
//       v += 2;
//    }
//    if (arr[5] == '1'){
//       v += 4;
//    }
//    if (arr[4] == '1'){
//       v += 8;
//    }
//    if (arr[3] == '1'){
//       v += 16;
//    }
//    if (arr[2] == '1'){
//       v += 32;
//    }
//    if (arr[1] == '1'){
//       v += 64;
//    }
//    if (arr[0] == '1'){
//       v += 128;
//    }

//    return v;


// }
























///////////////////////
// #include <iostream>
// #include <hls_stream.h>
// #include <ap_axi_sdata.h>

// using namespace std;

// typedef ap_axis<32,0,0,0> pkt_t;
// static int count_streams = 0;

// void pixel(
// 		ap_int<32> position,
// 		ap_int<32> stream_count,
// 		hls::stream< pkt_t > &din,
// 		hls::stream< pkt_t > &dout
// ) {
// 	#pragma HLS INTERFACE ap_ctrl_none port=return
// 	#pragma HLS INTERFACE s_axilite port=position
// 	#pragma HLS INTERFACE s_axilite port=stream_count
// 	#pragma HLS INTERFACE axis port=din
// 	#pragma HLS INTERFACE axis port=dout

// 	pkt_t pkt=din.read();
// 	count_streams++;
	
// 	if(count_streams > 3 * (position - 1) && count_streams <= 3 * (position)){
// 		pkt.data -= 1;
// 	}

// 	if (count_streams == stream_count){
// 		count_streams = 0;
		
// 	}

// 	dout.write(pkt);

// }