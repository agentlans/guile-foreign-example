#include <math.h>
#include <libguile.h>

// Returns value of j0 Bessel function. This will be called from Guile Scheme.
SCM
j0_wrapper (SCM x)
{
	return scm_from_double (j0 (scm_to_double (x)));
}

// A C struct that can hold any Guile Scheme object
struct foo
{
	SCM x;
};

// Represents the foo type in Scheme
static SCM foo_type;

// Declarations needed for foo structs to be usable in Scheme
void init_foo_type()
{
	SCM name = scm_from_utf8_symbol("foo");
	SCM slots = scm_list_1(scm_from_utf8_symbol("x"));
	foo_type = scm_make_foreign_object_type(name, slots, NULL); // NULL finalizer
}

// Creates a new foo struct containing the given Scheme object
SCM make_foo(SCM obj)
{
	struct foo *foo_obj = scm_gc_malloc(sizeof(struct foo), "foo");
	foo_obj->x = obj;
	return scm_make_foreign_object_1(foo_type, foo_obj);
}

// Returns the Scheme object inside the foo struct
SCM get_foo(SCM foo_obj)
{
	scm_assert_foreign_object_type(foo_type, foo_obj);
	return ((struct foo *) scm_foreign_object_ref(foo_obj, 0))->x;
}

// Initializes the functions exposed in this Guile extension
void
init_bessel ()
{
	scm_c_define_gsubr ("j0", 1, 0, 0, j0_wrapper);

	init_foo_type();
	scm_c_define_gsubr("make-foo", 1, 0, 0, make_foo);
	scm_c_define_gsubr("get-foo", 1, 0, 0, get_foo);
}

