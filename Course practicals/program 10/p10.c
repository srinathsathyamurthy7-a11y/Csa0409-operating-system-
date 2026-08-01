
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

struct message
{
	long type;
	char text[100];
};

int main()
{
	struct message msg;
	key_t key = 1234;

	int msgid = msgget(key, 0666 | IPC_CREAT);

	msg.type = 1;

	printf("Enter message: ");
	scanf(" %[^
]", msg.text);

	msgsnd(msgid, &msg, sizeof(msg.text), 0);

	printf("Message sent successfully.\n");

	msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

	printf("Received Message: %s\n", msg.text);

	return 0;
}
