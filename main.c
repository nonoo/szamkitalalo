#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>

static char *readline(void) {
	static char line[100];
	int linep = 0;
	char c;

	do {
        c = fgetc(stdin);
        if (c == EOF)
            break;

		if (c == '\n')
			break;

		line[linep++] = c;
    } while (linep < sizeof(line)-1);

    line[linep] = 0;

    return line;
}

int main(int argc, char **argv) {
	char *line;
	int max_num;
	char *endptr;
	int guess;
	int num;
	int tries;

	printf("szamkitalalo v0.1\n\n");

	printf("max. szam? ");
	line = readline();
	errno = 0;
	max_num = strtol(line, &endptr, 10);
	if (*endptr != 0 || errno) {
		fprintf(stderr, "hiba: nem szamot adtal meg!\n");
		return 1;
	}

	srand(time(NULL));
	num = rand() % max_num;
	tries = 1;

	for (;;) {
		printf("tipp: ");
		line = readline();
		errno = 0;
		guess = strtol(line, &endptr, 10);
		if (*endptr != 0 || errno) {
			fprintf(stderr, "hiba: nem szamot adtal meg!\n");
			continue;
		}

		if (guess == num) {
			printf("gratulalok, eltalaltad %u probalkozasbol!\n", tries);
			break;
		} else if (guess < num)
			printf("a kitalalando szam nagyobb!\n");
		else
			printf("a kitalalando szam kisebb!\n");

		tries++;
	}

	return 0;
}
