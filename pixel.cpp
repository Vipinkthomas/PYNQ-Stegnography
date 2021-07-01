#include "pixel.hpp"

void pixel(apint &in_decimal,
           apint selector,
		   apint stream_count,
		   stream &din,
		   stream &dout
) {
	#pragma HLS INTERFACE ap_ctrl_none port=return
    #pragma HLS INTERFACE s_axilite port=in_decimal     // ascii values for the characters(word)
    #pragma HLS INTERFACE s_axilite port=selector       // to select the mode (encoding or decoding)
	#pragma HLS INTERFACE s_axilite port=stream_count   // size of data stream 
	#pragma HLS INTERFACE axis port=din
	#pragma HLS INTERFACE axis port=dout

    din >> tmpA;  //input data

    switch(selector)
    {   
        // case 0 is for encoding
        case 0:
            
            if (count_streams == 0){
                
                final_char=0;             
                decNum = in_decimal;      //getting the ascii values of the word from the register
            }

                addNum=0;

                if(decimalCounter % 8 == 0){
                    /*checking if the counter is 8 which means the process reached the 8th bit*/
                    lastDecimalVal = getDecimal(decNum);
                    decNum /= 100;                       //to delete the processed ascii value and get the next one
                    charIn=convert(lastDecimalVal);      //to find the binary of the next ascii value
                    
                }
                addNum=charIn%10;                   //LSB of charIn
		        charIn=(int)charIn/10;              //deleting lsb and get the next bit(lsb)

                //updating the input data according to addNum and lsb of the input data.
                //if addNum is equal to 1 and input data is even , 1 will be added to input data which turns to odd
                //otherwise no action needed
                if(tmpA.data % 2 == 0 && addNum == 1){
                    
                    tmpA.data += 1;
                    
                }
                
                //if addNum is equal to 0, input data is odd, 1 will be subtracted fro the input data which will turn it to even
                //otherwise no action needed
                else if(tmpA.data % 2 != 0 && addNum == 0){
                    tmpA.data -= 1;
                    
                }

                decimalCounter++;

            break;

        //case 1 is for decoding
        case 1:
                
                decode(tmpA.data);    //getting decoded binary value bit by bit for every character
                decimalCounter++;
                if(decimalCounter == 8){
                    //after processing 8 bits, the ascii value will be returned by the convertBinInt
                    decimalOut=decimalOut*100+convertBinInt(final_char);  
                    decimalCounter=0;
                    final_char=0;   
                }
            
                
            break;

        default:
            break;
    }
	
	count_streams++;

	if (count_streams == stream_count){
        //resetting variables
		count_streams = 0;
        charIn=0;
        addNum=0;
        decimalCounter=0;
        if(selector == 1){
            final_char=0;
            in_decimal=decimalOut;
            decimalOut=0;
        }

	}

    if(count_streams == stream_count){
        //setting TLAST signal to 1 
	        tmpA.last = 1;              

	    }

	    dout << tmpA;
}


long long convert(int n) {
    /*
    This function converts a decimal number to a Binary number and returns it
    */
    long long bin = 0;
    int rem, i = 1, step = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}

void decode(int data) {
    /*
    get the binary value of the embedded ascii values by combining the LSBs.
    */
    int bit;
    if(data % 2 == 0){
    bit = 0;
    }else if(data % 2 != 0){
        bit=1;
    }
    final_char= final_char*10+bit;

}

int convertBinInt(long long n) {
    /*
    This function returns decimal value from a binary number
    */
    int dec = 0, i = 7, b=0,rem=0;

        while (n != 0) {
            b=pow(10,i);
            rem = n / b;
            n =n % b;
            dec += rem * pow(2, 7-i);
            --i;
        }
    return dec;
}

int getDecimal(int n) {
    /*
    returns the last two digits (which represents one character) of the corresponding ascii values passed to this function.
    */
    int num = 0;
    num = n % 100;
    return num;
    }

