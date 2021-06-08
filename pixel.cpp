//TODO : Add 2 modes, one for making fpga manipulate pixels and one mode for read out the steganographic charachter
#include <iostream>
#include <hls_stream.h>
#include <ap_axi_sdata.h>
#include <cmath>

#define ull unsigned long long int

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count_streams = 0;
static char s[2] = {"a","b"};
static string l = "";
static string s12 = "";
static string jj = "";
static string jjj = "";
static string arr[4];
static string v = "";
static string vv = "";
static string vvv = "";
static int cnnt = 0;

// // int decimalToBinary(int N);
// // string DecToHex(int decimalNum);
// // void hexToBin(string hexa);




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
		
		// DecToHex(charachter_in_decimal);
		jj = s[1];
		jjj = s[0];
		// s12 = jj + jjj;

		// hexToBin(s12);


    // for (int z=0 ; z<8; z+=2){
       
    //     v = l[z];
    //     vv = l[z+1];
    //     vvv = v+vv;
    //     arr[cnnt] = vvv;
    //     cnnt++; 
    // }


	}
	
	
	// if(count_streams <= 4){
	// 	for (int g=0; g<4 ; g++){
	// 		if(arr[count_streams] == "01"){
	// 			pkt.data -= 1;             //must check if rgbr value is zero // add another condition
	// 		}else if(arr[count_streams] == "10"){
	// 			pkt.data -= 2;
	// 		}else if(arr[count_streams] == "11"){
	// 			pkt.data -= 3;
	// 		}
    // 	}
		
	// }
	count_streams++;

	dout.write(pkt);

}
//****************************************************************************************************
// int decimalToBinary(int N)
// {
 
//     // To store the binary number
//     ull B_Number = 0;
//     int cnt = 0;
//     while (N != 0) {
//         int rem = N % 2;
//         ull c = pow(10, cnt);
//         B_Number += rem * c;
//         N /= 2;
//         // Count used to store exponent value
//         cnt++;
//     }
 
//     return B_Number;
// }

// string DecToHex(int decimalNum)
// {
//      int rem, i=0;
//     char hexaDecimalNum[2];
    
//     while(decimalNum!=0)
//     {
//         rem = decimalNum%16;
//         if(rem<10)
//             rem = rem+48;
//         else
//             rem = rem+55;
//         hexaDecimalNum[i] = rem;
//         i++;
//         decimalNum = decimalNum/16;
//     }
    
//     for(i=i-1; i>=0; i--)
//         s[i] = hexaDecimalNum[i];
    
//     return hexaDecimalNum;
// }

// void hexToBin(string hexa){ 
//     long int i = 0;
    
//    while (hexa[i]){
//       switch (hexa[i]){
//       case '0':
//          l +=  "0000";
//          break;
//       case '1':
//          l +=  "0001";
//          break;
//       case '2':
//          l +=  "0010";
//          break;
//       case '3':
//          l +=  "0011";
//          break;
//       case '4':
//          l +=  "0100";
//          break;
//       case '5':
//          l +=  "0101";
//          break;
//       case '6':
//          l +=  "0110";
//          break;
//       case '7':
//          l +=  "0111";
//          break;
//       case '8':
//          l +=  "1000";
//          break;
//       case '9':
//          l +=  "1001";
//          break;
//       case 'A':
//       case 'a':
//          l +=  "1010";
//          break;
//       case 'B':
//       case 'b':
//          l +=  "1011";
//          break;
//       case 'C':
//       case 'c':
//          l +=  "1100";
//          break;
//       case 'D':
//       case 'd':
//          l +=  "1101";
//          break;
//       case 'E':
//       case 'e':
//          l +=  "1110";
//          break;
//       case 'F':
//       case 'f':
//          l +=  "1111";
//          break;
//       default:
//         cout<<"S";
         
//       }
//    i++;
//    }

// }
//********************************************************************************************
























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
