#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

template <class T>	
struct Node_base {

	// ------------------------------------------------------------------

	Node_base()
	: next(0),
	  prev(0)
	{}

	//--------------------------------------------------------------------

	Node_base(const T &val)
	: next(0),
	  prev(0),
	  data(val)
	{}

	//--------------------------------------------------------------------
	
	~Node_base()
	{}

	// -------------------------------------------------------------------

	Node_base *next;
	Node_base *prev;
	T         data;

	// -------------------------------------------------------------------

}; // end Node_base

template<class T>
class List {
public:

	//--------------------------------------------------------------------

	List()
	: len (0),
	  head(0),
	  tail(0)
	{}

	//-------------------------------------------------------------------	

	~List()
	{
		clear();
	};

	//--------------------------------------------------------------------

	bool empty  (void)
	{ return (len == 0); }

	//--------------------------------------------------------------------

	void append (const T &val)
	{
		Node_base<T> *node = new Node_base<T>(val);

		if (len == 0) {
			tail = node;
			head = node;
			len += 1;
			return;
		}

		tail->next = node;
		node->prev = tail;
		tail       = node;
		this->len  +=  1;
	}


	//---------------------------------------------------------------------

	T    pop    (void)
	{
		T copy;
		copy = tail->data;
		remove(len - 1);

		return copy;
	}

	//---------------------------------------------------------------------

	T    *at    (unsigned int index)
	{
		Node_base<T> *base = _node_at(index);
		return &base->data;
	}

	//--------------------------------------------------------------------

	void  insert (unsigned int index, const T &val)
	{
		Node_base<T> *newbase = new Node_base<T>(val); 
		Node_base<T> *base    = _node_at(index);

		if (base->prev != 0) {
			newbase->prev    = base->prev;	
			base->prev->next = newbase;

		} else {

			head = newbase;
		}

		newbase->next = base;
		base->prev    = newbase;

		len += 1;
	}

	//--------------------------------------------------------------------
	
	void   remove (unsigned int index)
	{
		Node_base<T> *base = _node_at(index);

		_glue(base);

		delete base;

		len -= 1;

	}

	//--------------------------------------------------------------------

	void    clear  (void)
	{
		_delete_nodes();
	}

	// -------------------------------------------------------------------

	// TODO: sort
	// void             sort   (int (*compar)(const T &a, const T &b));

	//--------------------------------------------------------------------

	unsigned int  len;
	Node_base<T>  *head;
	Node_base<T>  *tail;

	//--------------------------------------------------------------------

private:

	inline void          _glue   (Node_base<T> *base)
	{
		if (base->prev != 0) 
			base->prev->next = base->next;
		else
			head = head->next;

		if (base->next != 0)
			base->next->prev = base->prev;
		else
			tail = tail->prev;
	}
	
	inline Node_base<T> *_node_at(unsigned int index)
	{
		Node_base<T> *current = head;		

		for (unsigned int i=0; i<index; i++) {
			current = current->next;
		}

		return current;
	}

	inline void _delete_nodes()
	{
		Node_base<T> *base = head;
		while (base != 0) {
			Node_base<T> *next = base->next;
			delete(base);
			base = next;
		}
	}
};

#endif // LIST_H_INCLUDED
