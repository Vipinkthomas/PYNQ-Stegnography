#include <stdio.h>
#include<math.h>
#include <string.h>

using namespace std;

typedef ap_axis<32,0,0,0> pkt_t;
static int count_streams = 0;
static long long charIn=0;
static long long final_char=0;
int addNum=0;

long long convert(int n);
int convertBinInt(long long n);
void decrypt(int data);
