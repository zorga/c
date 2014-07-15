#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
// #include <string.h> we can't use it...


static size_t strlen (const char *s)
{
	if (!s)
		return 0;

	size_t i;
	for (i = 0; s[i] != '\0'; i++);
	return i;
}


struct string* string_alloc_str (const char *str)
{
	return string_alloc_substr (str, strlen (str));
}


struct string* string_alloc_substr (const char *str, size_t str_len)
{
	struct string *sString = (struct string*) malloc (sizeof (struct string));
	if (! sString)
		return NULL;

	// we create a new char[]...
	char *sBuf = (char*) malloc (str_len);
	if (! sBuf)
	{
		free (sString);
		return NULL;
	}

	int i;
	for (i = 0; i < str_len; i++)
		sBuf [i] = str [i];

	sString->str = sBuf;
	sString->len = str_len;
	return sString;
}


void string_free (struct string *buf)
{
	if (! buf)
		return;

	free (buf->str);
	free (buf);
}


size_t string_len (struct string *buf)
{
	if (! buf)
		return 0;

	return buf->len;
}


struct string *string_concat (struct string *buf1, struct string *buf2)
{
	if (! buf1)
		return NULL;

	// maybe we can use string_alloc_str and strcat but it's faster like that:
	struct string* result =  (struct string*) malloc (sizeof (struct string));
	if (! result)
		return NULL;

	size_t sizeTot = string_len (buf1) + string_len (buf2);
	char* str_res = (char*) malloc (sizeof (char [sizeTot])); // or malloc (sizeTot); => the same
	if (! str_res)
		return NULL;

	result->len = sizeTot;

	int i;
	for (i = 0; i < string_len (buf1); i++)
		str_res [i] = buf1->str [i];

	for (i = 0; i < string_len (buf2); i++)
		str_res [string_len (buf1) + i] = buf2->str [i];

	result->str = str_res;
	
	return result;
}

bool string_equals (struct string *buf1, struct string *buf2)
{
	if (buf1->len != buf2->len) // buf1 and buf2 not null
		return false;

	if (buf1 == buf2) // same pointer
		return true;

	int i;
	for (i = 0 ; i < buf1->len ; i++)
	{
		if (buf1->str [i] != buf2->str [i])
			return false;
	}
	return true;
}

int string_printf (struct string *str)
{
	if (! str)
		return 0;

	int i;
	for (i = 0; i < str->len; i++)
		printf ("%c", str->str [i]);

	return i;
}
