
#include "ft_printf.h"
#include "format/format_specifier.h"

int main(void)
{
	ft_printf("Print it my |%d|\n", 1);
	printf("Print it re |%0*d|\n",5, -1);
}
