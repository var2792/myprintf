
#include "ft_printf.h"

int main(void)
{
	char *p = "asfghk";

	/*ft_printf("Print it my c = |%c|\n", 'c');
	printf("Print it re c = |%c|\n", 'c');
	ft_printf("Print it my s = |%s|\n", "sss");
	printf("Print it re s = |%s|\n", "sss");
	ft_printf("Print it my p = |%p|\n", p);
	printf("Print it re p = |%p|\n", p);
	ft_printf("Print it my i = |%i|\n", -1024);
	printf("Print it re i = |%i|\n", -1024);
	ft_printf("Print it my u = |%u|\n", 2048);
	printf("Print it re u = |%u|\n", 2048);
	ft_printf("Print it my x = |%x|\n", 27);
	printf("Print it re x = |%x|\n", 27);
	ft_printf("Print it my X = |%X|\n", 27);
	printf("Print it re X = |%X|\n", 27);
	ft_printf("Print it my d = |%d|\n", 4096);
	printf("Print it re d = |%d|\n", 4096);

	ft_printf("\nPrint it my 010   =  |%010d|\n", 1);
	printf("Print it re  010  =  |%010d|\n", 1);
	ft_printf("Print it my .010  =  |%.010d|\n", 1);
	printf("Print it re .010  =  |%.010d|\n", 1);
	ft_printf("Print it my -20.10 = |%-20.10d|\n", 1);
	printf("Print it re -20.10 = |%-20.10d|\n", 1);
	ft_printf("Print it my  -10  =  |%-10d|\n", 1);
	printf("Print it re  -10  =  |%-10d|\n", 1);
	ft_printf("Print it my   10  =  |%10d|\n", 1);
	printf("Print it re   10  =  |%10d|\n", 1);
	ft_printf("Print it my   -   =  |%-d|\n", 1);
	printf("Print it re   -   =  |%-d|\n", 1);
	ft_printf("\nPrint it my  10c  = |%10c|\n", 'c');
	printf("Print it re  10c  = |%10c|\n", 'c');
	ft_printf("Print it my  10s  = |%10s|\n", "sss");
	printf("Print it re  10s  = |%10s|\n", "sss");

	ft_printf("\nPrint it my .*  =  |%.*d|\n", 15, 1234567890);
	printf("Print it re .*  =  |%.*d|\n", 15, 1234567890);
	ft_printf("Print it my  -*  =  |%-*d|\n", 15, 1234567890);
	printf("Print it re  -*  =  |%-*d|\n", 15, 1234567890);*/

	/*ft_printf("Print it my %s = |%%|\n", "%%");
	printf("Print it re %s = |%%|\n", "%%");
	ft_printf("Print it my %s = |%-5%|\n", "%-5%");
	printf("Print it re %s = |%-5%|\n", "%-5%");
	ft_printf("Print it my %s = |%05%|\n", "%05%");
	printf("Print it re %s = |%05%|\n", "%05%");*/

	ft_printf("Print it my uni = |%c|\n", '\x00');
	printf("Print it re uni = |%c|\n", '\x00');
	//printf("%i %i\n", nm, nr);
}
/*
0 & num - minim lenght with null, if longer - just num
. & num - same, after must be number '010' or '10'. if no number, it's zero
- & num - number in left and next is to lenght of ' ', after must be number '010' or '10'. if no number, it's zero

. | 0 - not with s and c
when warning - ignore 0
*/
