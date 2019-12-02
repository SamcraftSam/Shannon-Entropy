
#define _CRT_SECURE_NO_WARNINGS
#define NUM 128

#include <stdio.h>
#include <conio.h>
#include <iostream>


int main() {

	FILE* f; 

	int buffer[256];
	unsigned short int c = 0;
	double H = 0;

	memset(buffer, 0, NUM*4);
	
	f = fopen("intro1.exe", "rb");

	if (f == NULL) {
		perror("Error: ");
		return -1;
	}
	//find the size of the file
	fseek(f, 0, SEEK_END);
	int fileLen = ftell(f);
	fseek(f, 0, SEEK_SET);

	//get the character frequency
	for (int i = 0;i < fileLen;i++) {
		c = fgetc(f);
		buffer[c]++;
	}
	//calculate  Shannon Entropy 
	for (int i = 0;i < NUM;i++)
		H = H - (double)buffer[i] / fileLen * log2((double)buffer[i] / fileLen);

	printf("entropy is : %lf\n", H);

	return 0;

}
