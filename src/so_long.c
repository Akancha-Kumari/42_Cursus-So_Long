#include "so_long.h"


int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("\e[33mTry: ./so_long <MAP>.ber \e[0m\n");
		return (EXIT_FAILURE);
	}
	size_t len = ft_strlen(argv[1]);
    if (len >= 4 && ft_strcmp(argv[1] + len - 4, ".ber") == 0) 
	{
        printf("The file has a .ber extension.\n");
		int fd = open(argv[1], O_RDONLY);
		if(fd == -1)
		{
			printf("Error: Could not open file %s\n", argv[1]);
			return (1);
		}
		else 
		{
			printf("File %s exists and can be opened.\n", argv[1]);
			close(fd);
		}
    } 
	else 
        printf("The file does not have a .ber extension.\n");
	return (0);
}
