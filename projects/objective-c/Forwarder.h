#import <objc/Object.h>

@interface Forwarder : Object
{
	id recipient;
}

- (id)recipient;
- (id)setRecipient:(id)_recipient;

@end


