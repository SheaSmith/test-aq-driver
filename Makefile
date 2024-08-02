# $FreeBSD$

.PATH:  ./

KMOD=	if_atlantic
SRCS=	if_atlantic.c

CFLAGS+= -DIFLIB -ferror-limit=1 -I/usr/include

.include <bsd.kmod.mk>
