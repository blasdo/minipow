#include "minipow.h"

static void	print_byte(unsigned char byte)
{
	unsigned char	hex_byte[2];
	char	*base = "0123456789ABCDEF";

	hex_byte[1] = base[byte % 16];
	byte /= 16;
	hex_byte[0] = base[byte % 16];
	write(1, hex_byte, 2);
}
void	print_hash(unsigned char *hash)
{
	size_t	len = SHA256_DIGEST_LENGTH;
	size_t	i = 0;

	write(1, "0x", 2);
	while (i < len)
	{
		print_byte(hash[i++]);
	}
	write(1, "\n", 1);
}
