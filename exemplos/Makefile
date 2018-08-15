CFLAGS=-Wall -Werror -lm

%: %.c
	gcc $(CFLAGS) $@.c -o exe_$@
	./$@

clean:
	rm -rf exe_*