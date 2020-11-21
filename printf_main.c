
#include "ft_printf.h"

int main(void)
{
	char *p = "asfghk";
	int nm = 0;
	int nr = 0;

	/*nm += ft_printf("Print it my c = |%c|\n", 'c');
	nr += printf("Print it re c = |%c|\n", 'c');
	nm += ft_printf("Print it my s = |%s|\n", "sss");
	nr += printf("Print it re s = |%s|\n", "sss");
	nm += ft_printf("Print it my p = |%p|\n", p);
	nr += printf("Print it re p = |%p|\n", p);
	nm += ft_printf("Print it my i = |%i|\n", -1024);
	nr += printf("Print it re i = |%i|\n", -1024);
	nm += ft_printf("Print it my u = |%u|\n", 2048);
	nr += printf("Print it re u = |%u|\n", 2048);
	nm += ft_printf("Print it my x = |%x|\n", 27);
	nr += printf("Print it re x = |%x|\n", 27);
	nm += ft_printf("Print it my X = |%X|\n", 27);
	nr += printf("Print it re X = |%X|\n", 27);
	nm += ft_printf("Print it my d = |%d|\n", 4096);
	nr += printf("Print it re d = |%d|\n", 4096);
	//nm += ft_printf("Print it my null-p = |%p|\n", NULL);
	//nr += printf("Print it re null-p = |%p|\n", NULL);
	printf("\n");
	nm += ft_printf("Print it my 010d   =  |%010d|\n", 1);
	nr += printf("Print it re  010d  =  |%010d|\n", 1);
	nm += ft_printf("Print it my .010d  =  |%.010d|\n", 1);
	nr += printf("Print it re .010d  =  |%.010d|\n", 1);
	nm += ft_printf("Print it my -20.10d = |%-20.10d|\n", 1);
	nr += printf("Print it re -20.10d = |%-20.10d|\n", 1);
	nm += ft_printf("Print it my  -10d  =  |%-10d|\n", 1);
	nr += printf("Print it re  -10d  =  |%-10d|\n", 1);
	nm += ft_printf("Print it my   10d  =  |%10d|\n", 1);
	nr += printf("Print it re   10d  =  |%10d|\n", 1);
	nm += ft_printf("Print it my   -d   =  |%-d|\n", 1);
	nr += printf("Print it re   -d   =  |%-d|\n", 1);
	nm += ft_printf("Print it my -7.5d   =  |%-7.5d|\n", 12);
	nr += printf("Print it re -7.5d   =  |%-7.5d|\n", 12);
	nm += ft_printf("Print it my 7.5d   =  |%7.5d|\n", 12);
	nr += printf("Print it re 7.5d   =  |%7.5d|\n", 12);
	printf("\n");
	nm += ft_printf("Print it my  10c  = |%10c|\n", 'c');
	nr += printf("Print it re  10c  = |%10c|\n", 'c');
	nm += ft_printf("Print it my  10s  = |%10s|\n", "sss");
	nr += printf("Print it re  10s  = |%10s|\n", "sss");
	printf("\n");
	nm += ft_printf("Print it my .*  =  |%.*d|\n", 15, 1234567890);
	nr += printf("Print it re .*  =  |%.*d|\n", 15, 1234567890);
	nm += ft_printf("Print it my  -* =  |%-*d|\n", 15, 1234567890);
	nr += printf("Print it re  -* =  |%-*d|\n", 15, 1234567890);
	printf("\n");
	nm += ft_printf("Print it my uni = |%c|\n", '\x00');
	nr += printf("Print it re uni = |%c|\n", '\x00');
	nm += ft_printf("Print it my uni = |%5c|\n", '\x00');
	nr += printf("Print it re uni = |%5c|\n", '\x00');
	nm += ft_printf("Print it my uni = |%s|\n", "\x00");
	nr += printf("Print it re uni = |%s|\n", "\x00");
	nm += ft_printf("Print it my uni = |%-5s|\n", "\x00");
	nr += printf("Print it re uni = |%-5s|\n", "\x00");
	printf("\n");
	nm += ft_printf("Print it my .06s = |%.06s|\n", "hello");
	nr += printf("Print it re .06s = |%.06s|\n", "hello");
	nm += ft_printf("Print it my .3s = |%.3s|\n", "hello");
	nr += printf("Print it re .3s = |%.3s|\n", "hello");
	nm += ft_printf("Print it my .s = |%.s|\n", "hello");
	nr += printf("Print it re .s = |%.s|\n", "hello");
	nm += ft_printf("Print it my .0s = |%.0s|\n", "hello");
	nr += printf("Print it re .0s = |%.0s|\n", "hello");
	nm += ft_printf("Print it my .3s .2s = |%.3s%.2s|\n", "holla", "bitch");
	nr += printf("Print it re .3s .2s = |%.3s%.2s|\n", "holla", "bitch");
	nm += ft_printf("Print it my -7.5s = |%-7.5s|\n", "yolo");
	nr += printf("Print it re -7.5s = |%-7.5s|\n", "yolo");
	nm += ft_printf("Print it my 7.5s = |%7.5s|\n", "bombastic");
	nr += printf("Print it re 7.5s = |%7.5s|\n", "bombastic");
	nm += ft_printf("Print it my 7.3s 7.7s = |%7.3s%7.7s|\n", "hello", "world");
	nr += printf("Print it re 7.3s 7.7s = |%7.3s%7.7s|\n", "hello", "world");
	nm += ft_printf("Print it my 3.03s 7.7s = |%3.03s%7.7s|\n", "hello", "world");
	nr += printf("Print it re 3.03s 7.7s = |%3.03s%7.7s|\n", "hello", "world");*/
	/*printf("\n");
	nm += ft_printf("Print it my %s = |%%|\n", "%%");
	nr += printf("Print it re %s = |%%|\n", "%%");
	nm += ft_printf("Print it my %s = |%5%|\n", "%5%");
	nr += printf("Print it re %s = |%5%|\n", "%5%");
	nm += ft_printf("Print it my %s = |%-5%|\n", "%-5%");
	nr += printf("Print it re %s = |%-5%|\n", "%-5%");
	nm += ft_printf("Print it my %s  = |%05%|\n", "%05%");
	nr += printf("Print it re %s  = |%05%|\n", "%05%");
	nm += ft_printf("Print it my %s  = |%-05%|\n", "%-05%");
	nr += printf("Print it re %s  = |%-05%|\n", "%-05%");
	printf("\n");
	nm += ft_printf("Print it my  s  = |%s.|\n", NULL);
	nr += printf("Print it re  s  = |%s.|\n", NULL);
	nm += ft_printf("Print it my  .02s  = |%.02s|\n", NULL);
	nr += printf("Print it re  .02s  = |%.02s|\n", NULL);
	nm += ft_printf("Print it my  .02s  = |%.02s|\n", NULL);
	nr += printf("Print it re  .02s  = |%.02s|\n", NULL);
	nm += ft_printf("Print it my  10s  = |%10s|\n", NULL);
	nr += printf("Print it re  10s  = |%10s|\n", NULL);
	nm += ft_printf("Print it my  -10s  = |%-10s|\n", NULL);
	nr += printf("Print it re  -10s  = |%-10s|\n", NULL);*/
	/*printf("\n");
	nm += ft_printf("Print it my .*(-1)s = |%.*s|\n", -1, "ssssss");
	nr += printf("Print it re .*(-1)s = |%.*s|\n", -1, "ssssss");
	nm += ft_printf("Print it my .*(-1)p = |%.*p|\n", -1, p);
	nr += printf("Print it re .*(-1)p = |%.*p|\n", -1, p);
	nm += ft_printf("Print it my .*(-1)X = |%.*X|\n", -1, 12345);
	nr += printf("Print it re .*(-1)X = |%.*X|\n", -1, 12345);
	nm += ft_printf("Print it my .*(-1)u = |%.*u|\n",  -1, 0);
	nr += printf("Print it re .*(-1)u = |%.*u|\n",  -1, 0);
	printf("\n");
	nm += ft_printf("Print it my .s = |%.s|\n", "");
	nr += printf("Print it re .s = |%.s|\n", "");
	nm += ft_printf("Print it my .10s = |%.10s|\n", "");
	nr += printf("Print it re .10s = |%.10s|\n", "");
	nm += ft_printf("Print it my .X = |%.X|\n", 0);
	nr += printf("Print it re .X = |%.X|\n", 0);
	printf("\n");
	nm += ft_printf("Print it my 0-3.3X = |%0-3.3X|\n", 6935);
	nr += printf("Print it re 0-3.3X = |%0-3.3X|\n", 6935);
	nm += ft_printf("Print it my .6d = |%.6d|\n", -3);
	nr += printf("Print it re .6d = |%.6d|\n", -3);
	nm += ft_printf("Print it my .0d = |%.0d|\n", 0);
	nr += printf("Print it re .0d = |%.0d|\n", 0);
	nm += ft_printf("Print it my 0*(-7)i = |%0*i|\n", -7, 123);
	nr += printf("Print it re 0*(-7)i = |%0*i|\n", -7, 123);
	nm += ft_printf("Print it my -*(-7)i = |%-*i|\n", -7, 123);
	nr += printf("Print it re -*(-7)i = |%-*i|\n", -7, 123);
	nm += ft_printf("Print it my -*(7)i = |%-*i|\n", 7, 123);
	nr += printf("Print it re -*(7)i = |%-*i|\n", 7, 123);*/
	printf("\n");
	//nm += ft_printf("Print it my 3.3s 3.7s = |%3.3s%3.7s|\n", "hello", "world");//result.c связь c19 c25
	//nr += printf("Print it re 3.3s 3.7s = |%3.3s%3.7s|\n", "hello", "world");
	char *pull = "Print it my = |%.*p|\n";
	nm += ft_printf(pull, -3, 0);
	nr += printf(pull, -3, 0);
	printf("Numbers are %i %i\n", nm, nr);
}
/*
0 & num - minim lenght with null, if longer - just num
. & num - same, after must be number '010' or '10'. if no number, it's zero
- & num - number in left and next is to lenght of ' ', after must be number '010' or '10'. if no number, it's zero

. | 0 - not with s and c
when warning - ignore 0
*/
