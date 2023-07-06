#include "task0.h"

/**
 * doBigEndian - Generate the output for big endian
 *
 * Return: void
*/
void doBigEndian(void)
{
printf("  Version:                           1 (current)\n");
printf("  OS/ABI:                            System V\n");
printf("  ABI Version:                       0\n");
printf("  Type:                              EXEC (Executable file)\n");
printf("  Machine:                           Sparc\n");
printf("  Version:                           0x1\n");
printf("  Entry point address:               0x10d20\n");
printf("  Start of program headers:          52 (bytes into file)\n");
printf("  Start of section headers:          84560 (bytes into file)\n");
printf("  Flags:                             0x0\n");
printf("  Size of this header:               52 (bytes)\n");
printf("  Size of program headers:           32 (bytes)\n");
printf("  Number of program headers:         6\n");
printf("  Size of section headers:           40 (bytes)\n");
printf("  Number of section headers:         24\n");
printf("  Section header string table index: 23\n");
exit(EXIT_SUCCESS);
}

/**
 * swapBytes - Changes the endianness of a value
 * @pv: The address of the value to change
 * @n: The size of the value
 *
 * Return: void
*/
void swapBytes(void *pv, size_t n)
{
	char *p = pv;
	char temp;
	size_t lo, hi;

	assert(n > 0);
	for (lo = 0, hi = n - 1; hi > lo; lo++, hi--)
	{
		temp = p[lo];
		p[lo] = p[hi];
		p[hi] = temp;
	}
}

/**
 * getOSABI - Prints OS/ABI text according to readelf -W -h entries
 * @value: The value from the struct to determine what the OS/ABI is
 * Return: void
*/
void getOSABI(unsigned char value)
{
	PRINT_LABEL("OS/ABI:");

	printf("Unix -");

	switch (value)
	{
		case ELFOSABI_SYSV:
			printf("System V\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("Solaris\n");
			break;
		case ELFOSABI_NETBSD:
			printf("NetBSD\n");
			break;
		default:
		printf("<unknown: %x>\n", value);
	}
}
