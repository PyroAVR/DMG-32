EXECS = retrogame gamera pixel
CC    = gcc $(CFLAGS) -Wall -O3 -fomit-frame-pointer -funroll-loops -s

all: $(EXECS)

retrogame: retrogame.c
	$(CC) $< -o $@
	strip $@

gamera: gamera.c
	$(CC) $< -lncurses -lmenu -lexpat -o $@
	strip $@

install:
	mkdir -p /opt/init
	mv retrogame /opt/init
	cp retrogame.sh /etc/init.d/retrogame

clean:
	rm -f $(EXECS)

pixel: px_retrogame.c
		$(CC) $< -o $@
		strip $@
