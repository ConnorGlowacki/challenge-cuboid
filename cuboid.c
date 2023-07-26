// Program: Take in 4 inputs.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

void generate_cuboid(char cuboid[], int x_len, int y_len, int z_len);

void main(int argc, char **argv)
{
	// Check to make sure user passes three arguments:
	// argc includes binary name, therefore check should be at 4
	if (argc != 4)
	{
		printf("Please pass the following three arguments: x, y, z\n");
		return;
	}

	char *ep;
	errno = 0;

	// Print out and store cuboid dimensions
	printf("Cuboid length: ");
	printf(argv[1]);
	long x = strtol(argv[1], &ep, 10);
	printf("\n");

	if (errno != 0 || *ep != '\0')
	{
		perror("Error in conversion");
		return;
	}

	printf("Cuboid width: ");
	printf(argv[2]);
	long y = strtol(argv[2], &ep, 10);
	printf("\n");

	printf("Cuboid height: ");
	printf(argv[3]);
	long z = strtol(argv[3], &ep, 10);
	printf("\n");

	// Allocate memory to store cuboid shape characters. Multiple by
	// 2 because that will probably be enough space
	char *cuboid;
	// CASTING AS CHAR *
	cuboid = (char *) malloc(x * y * z * 2);

	// Generate the cuboid output we can pass to printf to print cuboid.
	generate_cuboid(cuboid, x, y, z);

	printf("%s", cuboid);
	printf("\n");
}

/*
Cuboid length: 3
Cuboid width: 3
Cuboid height: 3
	_  _  _
  /_ /_ /_ /\
 /_ /_ /_ /\/\
/_ /_ /_ /\/\/\
\ _\ _\ _\/\/\/
 \ _\ _\ _\/\/
  \ _\ _\ _\/
*/
/*
Notes on above:
length X is this way <->
width Y is this way //
height Z is this way \\
# of console lines is y + z + 1
Underscores hug the front slash above middle edge (0 <= # console lines - height = 4 = width + 1)
Underscores hug the back slack below middle edge (# console lines - height > 4 = width + 1 )
When line # = 0, spaces = 4
But when 0 < line # < # console lines - height, then spaces = 3 - line #
Alternatively, when # console lines - height < line # < # console lines, then spaces = line # - 4
YZ plane consists of /\ and \/ repeats (n)
When 0 < line # < # console lines - height, then n = line # for /\
# console lines - height < line # < # console lines, then n = # console lines - line # for \/
*/

void generate_cuboid(char cuboid[], int x_len, int y_len, int z_len)
{
	int lines = y_len + z_len + 1;
	int i;
	int k = 0;
	for (i = 0; i < lines; i++)
	{

		// Calculate number of spaces for this line
		int spaces = y_len - i;
		spaces = abs(spaces);
		if (i >= y_len) {
			spaces--;
		}
		
		while (spaces > 0)
		{
			cuboid[k++] = ' ';
			spaces--;
		}
		// Insert first edge on each line
		if ((i <= y_len) && i != 0)
		{
			cuboid[k++] = '/';
		}
		else if (i > y_len)
		{
			cuboid[k++] = '\\';
		}

		// Calculate underscores
		int m;
		for (m = 0; m < x_len; m++)
		{
			if (i == 0)
			{
				cuboid[k++] = ' ';
				cuboid[k++] = '_';
				cuboid[k++] = ' ';
			}
			if ((i <= y_len) && i != 0)
			{
				cuboid[k++] = '_';
				cuboid[k++] = ' ';
				cuboid[k++] = '/';
			}
			else if (i > y_len)
			{
				cuboid[k++] = ' ';
				cuboid[k++] = '_';
				cuboid[k++] = '\\';
			}
		}

		// Calculate remaining edges
		int side_chars;
		if (i <= z_len)
		{
			side_chars = i;
		}
		else
		{
			side_chars = lines - i;
		}

		for (m = 0; m < side_chars; m++)
		{
			if (i <= y_len && i != 0)
			{
				if (m == 0)
				{
					cuboid[k++] = '\\';
				}
				else
				{
					cuboid[k++] = '/';
					if (m < y_len && m < z_len) {
						cuboid[k++] = '\\';
					}
				}
			}
			else if (i > y_len)
			{
				if (m == 0)
				{
					cuboid[k++] = '/';
				}
				else
				{
					cuboid[k++] = '\\';
					if (m < y_len && m < z_len) {
						cuboid[k++] = '/';
					}
				}
			}
		}
		cuboid[k++] = '\n';
	}
}