#define Disable_Default_Constructor(Class) \
	private:\
	Class();

#define Disable_Copy_Constructor(Class) \
	private:\
	Class(const Class &c);

#define Disable_Copy_Object(Class) \
	private:\
	Class &operator=(const Class &c);

class Class {
public:
	Class() {}
	Disable_Copy_Constructor(Class);
	Disable_Copy_Object(Class);
	
};

int main()
{
	Class c;
}
