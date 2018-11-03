#import "Forwarder.h"

@implementation Forwarder

- (retval_t) forward: (SEL)sel args:(arglist_t) args
{
	if ([recipient respondsToSelector:sel])
		return [recipient performv:sel args:args];
	else
		return [sef error:"Recipient does not respond"];
}

-(id)setRecipient:(id)_recipient
{
	[recipient autorealease]
	recipient = [_recipient retain];
	return self;
}

- (id) recipient
{
	return recipient;
}
@end
