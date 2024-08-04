#include "if.h"

u_int
if_rxr_get(struct if_rxring *rxr, u_int max)
{
	extern int ticks;
	u_int diff;

	if (ticks - rxr->rxr_adjusted >= 1) {
		/* we're free to try for an adjustment */
		if_rxr_adjust_cwm(rxr);
	}

	if (rxr->rxr_alive >= rxr->rxr_cwm)
		return (0);

	diff = min(rxr->rxr_cwm - rxr->rxr_alive, max);
	rxr->rxr_alive += diff;

	return (diff);
}

void
if_rxr_init(struct if_rxring *rxr, u_int lwm, u_int hwm)
{
	extern int ticks;

	memset(rxr, 0, sizeof(*rxr));

	rxr->rxr_adjusted = ticks;
	rxr->rxr_cwm = rxr->rxr_lwm = lwm;
	rxr->rxr_hwm = hwm;
}

void
if_rxr_livelocked(struct if_rxring *rxr)
{
	extern int ticks;

	if (ticks - rxr->rxr_adjusted >= 1) {
		if (rxr->rxr_cwm > rxr->rxr_lwm)
			rxr->rxr_cwm--;

		rxr->rxr_adjusted = ticks;
	}
}