#include "ch.h"
#include "hal.h"

#include <r2p/Middleware.hpp>

/*
 * Led publisher node
 */
void ledpub_node(void * arg) {
	Node node("pubnode");
	Publisher<LedMsg> led_pub;
	bool state = 0;

	node.advertise(led_pub, "led");

	for (;;) {
		LedMsg *msgp;
		if (led_pub.alloc(msgp)) {
			msgp->led = 1;
			msgp->value = state;
			state = !state;
			led_pub.publish(msgp);
		}

		chThdSleepMilliseconds(500);
	}

}
