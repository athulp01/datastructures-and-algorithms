#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 100000

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	FILE *data;
	data = fopen("./data","w");
	for (int i = 0; i < SIZE; ++i)
	{
		fprintf(data,"%d ",rand()%100000 );
	}
	int num=0;
	fclose(data);
	return 0;
}