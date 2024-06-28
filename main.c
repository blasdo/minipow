#include "minipow.h"

void proof_of_work(unsigned char *raw, int difficulty, size_t *ptr)
{
	const int		complete_bytes = difficulty / 8;
	const int		bits = difficulty % 8;
	unsigned  char	hash[SHA256_DIGEST_LENGTH];
	const char		zero = 0;

	memset(hash, 0, SHA256_DIGEST_LENGTH);
	SHA256(raw, strlen((char *)raw) + sizeof(size_t) + 1, hash);
	while (memcmp(hash, &zero, complete_bytes) ||
		hash[complete_bytes] >> ( 8 - bits))
	{
		SHA256(raw, strlen((char *)raw) + sizeof(size_t) + 1, hash);
		print_hash(hash);
		*(ptr) += 1;
		if (*ptr == SIZE_MAX)
		{
			printf("CANNOT CREATE A VALID PROOF\n");
			exit (2);
		}
	}
	write(1, "FINAL HASH\n", 11);
	print_hash(hash);
	printf("EXTRA DATA: %ld\n", *ptr);
}

int main(int argc, char *argv[])
{
	char	*raw;
	void	*number;

	if (argc < 3)
		return (printf("TOO FEW ARGS\n"), 1);
	if (argc > 3)
		return (printf("TOO MANY ARGS\n"), 1);
	raw = calloc(strlen(argv[1]) + sizeof(size_t) + 1, 1);
	strcpy(raw, argv[1]);
	number = raw + strlen(argv[1]) + 1;
	proof_of_work((unsigned char *)raw, atoi(argv[2]), number);
	return (0);
}
