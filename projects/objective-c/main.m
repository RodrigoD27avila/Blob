#import "Forwarder.h"
#import "Recipient.h"

int main (void)
{
	Forwarder *forwarder = [Forwarder new];
	Recipient *recipient = [Recipient new];

	[forwarder setRecipient:recipient];
	[forwarder hello];

	[recipient release];
	[forwarder release];

	return 0;
}
