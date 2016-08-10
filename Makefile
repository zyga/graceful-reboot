CFLAGS += -Wall
.PHONY: all
all: graceful-reboot
.PHONY: clean
clean:
	rm -f graceful-reboot
graceful-reboot: graceful-reboot.c
.PHONY: install
install: graceful-reboot
	install -d $(DESTDIR)/usr/bin
	install -m 0755 graceful-reboot $(DESTDIR)/usr/bin/graceful-reboot
