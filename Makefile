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

#Different name to differentiate from the original, just in case it's desired to have both.
pixel: px_retrogame.c
		$(CC) $< -o $@
		strip $@

install-pixel: pixel
	mkdir -p /opt/system
	mv pixel /opt/system/retrogame
	cp retrogame.sh /etc/init.d/retrogame
	chmod a+x /etc/init.d/retrogame
	insserv /etc/init.d/retrogame

#Just an alias
pixel-install: install-pixel
