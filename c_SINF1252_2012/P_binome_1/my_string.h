/* 
 * string -- A string representation without the need for a \0 to indicate the
 *	     end of a string.
 */
#ifndef __MY_STRING_H__
#define __MY_STRING_H__

#include <stdbool.h>
#include <stdlib.h>

struct string {
	char	*str;
	size_t	len;
};

/**
 * string_alloc_str - Allocate a string and fill it with str
 * @str: a string in standard representation
 * @return: Buffer to the string or %NULL on failure
 */
struct string *string_alloc_str(const char *str);

/**
 * string_alloc_substr - Allocate a string and fill it with the first
 *                        str_len characters of str
 * @str: a string
 * @str_len: the number of bytes of str to copy in the buffer
 *           (< str length)
 * @return: Buffer to the string or %NULL on failure
 */
struct string *string_alloc_substr(const char *str, size_t str_len);

/**
 * string_free - Free a string
 * @buf: string buffer
 */
void  string_free(struct string *buf);

/**
 * string_len - Get the current length of a string buffer
 * @buf: string buffer
 * @return: Current length of the string in the buffer
 */
size_t string_len(struct string *buf);

/**
 * string_concat - Concatenate two string buffers
 * @buf1, buf2: string buffers
 * @return: string with concatenated buf1 + buf2 strings or NULL on failure.
 * 	    buf1 holds this concatenation.
 *
 * buf2 can be NULL which is interpreted as an empty buffer.
 * If buf1 is NULL, nothing will be done and NULL will be returned.
 */
struct string *string_concat(struct string * buf1, struct string * buf2);

/**
 * string_equals - Return whether two buffers are equals
 * @buf1, buf2: string buffers (not NULL)
 * @return: 1 if the string content of both buffers are
 *          exactly the same, returns 0 otherwise.
 */
bool string_equals(struct string *buf1, struct string *buf2);

/**
 * string_printf - prints the string to stdout
 * @str: The string to print.
 * @return: The number of characters printed to stdout.
 */
int string_printf(struct string *str);

#endif /* __MY_STRING_H__ */
