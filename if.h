typedef unsigned int u_int;

struct if_rxring {
	int     rxr_adjusted;
	u_int	rxr_alive;
	u_int	rxr_cwm;
	u_int	rxr_lwm;
	u_int	rxr_hwm;
};

#define if_rxr_put(_r, _c)	do { (_r)->rxr_alive -= (_c); } while (0)
#define if_rxr_needrefill(_r)	((_r)->rxr_alive < (_r)->rxr_lwm)
#define if_rxr_inuse(_r)	((_r)->rxr_alive)
#define if_rxr_cwm(_r)		((_r)->rxr_cwm)

void	if_rxr_livelocked(struct if_rxring *);
void	if_rxr_init(struct if_rxring *, u_int, u_int);
u_int	if_rxr_get(struct if_rxring *, u_int);