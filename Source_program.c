#include <math.h>
#include <stdio.h>

static int count_streams = 0;
static long long charIn=0;
int arr[8]={255,254,253,252,251,250,249,248};

long long convert(int n);

long long toAscii(char c);
int convertBinInt(long long n);
void stegno(char c);
char stegnoDcrypt(int arr[]);


void main() {
    
    stegno('c');
    printf("%c \n",stegnoDcrypt(arr));
    
	
}

void stegno(char c){
    
    charIn=toAscii(c);
    int addNum;
    
    for(int i=0; i<8;i++){
    
    addNum=charIn%10;
    
    charIn=(int)charIn/10; 
    
    arr[i]= convertBinInt((convert(arr[i])/10)*10+addNum);
    
    printf("%d \n",arr[i]);
    
    }
    
    
}

char stegnoDcrypt(int arr[]){
    int decrpyt=0;
    long long asciiNum=0;
	int asciiVal=0;
	
    //int arr[8]={255,254,253,252,251,250,249,248};
    
    for(int i=7; i>=0;i--){
    
    decrpyt=convert(arr[i])%10;
    printf("%d\n",decrpyt);
    
    asciiNum=asciiNum*10+decrpyt;
	
	// ascii=> ascii*10 + lsb
    
    }
	
	asciiVal= convertBinInt(asciiNum);
	printf("%d\n",asciiVal);
    return (char)asciiVal;
    
}

long long convert(int n) {
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

int convertBinInt(long long n) {
    int dec = 0, i = 0, rem;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}

long long toAscii(char c) {
    int n=(int)c;
    long long bin = convert(n);
    return bin;     
}



