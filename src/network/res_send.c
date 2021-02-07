#include <resolv.h>

int __res_send(const unsigned char *msg, int msglen, unsigned char *answer, int anslen)
{
	int nsend, nrecv;
	int r = __res_msend(1, &msg, &msglen, &answer, &anslen, anslen, &nsend, &nrecv);
	return r<0 || !anslen ? -1 : anslen;
}

weak_alias(__res_send, res_send);
