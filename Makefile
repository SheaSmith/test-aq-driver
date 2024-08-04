# $FreeBSD$

.PATH:  ./

KMOD=	if_atlantic
SRCS=	device_if.h bus_if.h pci_if.h ifdi_if.h
SRCS+=	opt_inet.h opt_inet6.h opt_rss.h
SRCS+=	if_atlantic.c

CFLAGS+= -DIFLIB -I/usr/include -Werror

.include <bsd.kmod.mk>
