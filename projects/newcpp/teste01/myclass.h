#ifndef MyClass_H_Included
#define MyClass_H_Included

// private
class MyClassPrivate;

class MyClass {
public:
	MyClass();
	~MyClass();

	void print();

private:
	MyClassPrivate *priv;
};

#endif // MyClass_H_Included
