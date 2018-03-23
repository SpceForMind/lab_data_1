
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 16


int CorrectIpNode(int node)
{
	if(node > 0 && node <255)
		return 1;
	else
		return 0;
}

int CorrectMaskNode(int node)
{
	
	if(node < 255 && node > 0)
		return 0;

	int mask = 255;
	int null_flag = 0;

	for(int i = 0; i < 8; ++i)
	{
		if((node & mask)!= mask)
			null_flag = 1;
	
		if(null_flag == 1 && (node & mask) == 1)
			return 0;

		mask >>= 1;
	}
	
	return 1;
}


int CorrectIp(int *ip_arr)
{
	for(int i = 0; i < 4; ++i)
		if(CorrectIpNode(ip_arr[i]) == 0)
			return 0;

	return 1;
}


int CorrectMask(int *mask_arr)
{
	for(int i = 0; i < 5; ++i)
		if(CorrectMaskNode(mask_arr[i]) == 0)
			return 0;

	return 1;
}


void NetworkAdress(int *arr_ip, int *arr_mask)
{
	for(int i = 0; i < 4; ++i)
		arr_ip[i] &= arr_mask[i];
}



int main()
{
	char ip[STRSIZE];
	char mask[STRSIZE];

	fgets(ip, STRSIZE, stdin);
	fgets(mask, STRSIZE, stdin);

	if(strstr(ip, "\n")!= NULL)
		(*strstr(ip, "\n")) = '\0';
	if(strstr(mask, "\n")!= NULL)
		(*strstr(mask, "\n")) = '\0';

	char *tok_ip = strtok(ip, ".");
	char *tok_mask = strtok(mask, ".");
	int arr_ip[4];
	int arr_mask[4];

	for(int i = 0; tok_ip!= NULL; ++i)
	{
		printf("%d\n%d\n", atoi(tok_ip), atoi(tok_mask));

		arr_ip[i] = atoi(tok_ip);
		arr_mask[i] = atoi(tok_mask);
		tok_ip = strtok(NULL, ".\0");
		tok_mask = strtok(NULL, ".\0");
	}
	
	if(CorrectIp(arr_ip) == 0)
	{
		printf("wrong IP");
		return 0;
	}

	if(CorrectMask(arr_mask) == 0)
	{
		printf("wrong MASK");
		return 0;
	}

	NetworkAdress(arr_ip, arr_mask);

	printf("%d.%d.%d.%d", arr_ip[0], arr_ip[1], arr_ip[2], arr_ip[3]);
	

	return 0;
}
