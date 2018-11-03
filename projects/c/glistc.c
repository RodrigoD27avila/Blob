#include <glib.h>

int
main (int argc, char **argv)
{
	GList *lista;
	lista = g_list_append (lista, "1");
	lista = g_list_append (lista, "2");
	lista = g_list_append (lista, "3");
	lista = g_list_append (lista, "4");
	lista = g_list_append (lista, "5");

	g_list_free (lista);

	
}
