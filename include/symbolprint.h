/* symbolprint.h
 * Print representation of symbol table.
 * by Ryan Wilson-Perkin
 * for CIS4650W15 Compilers: Cflat Assignment
 */
#ifndef CFLAT_SYMBOLPRINT_H
#define CFLAT_SYMBOLPRINT_H

void print_symbol_table(FILE *, struct symbol_table *, int);
void print_symbol_table_item(FILE *, struct symbol_table_item *, int);
void print_symbol(FILE *, char *, struct symbol *, int);

#endif  /* CFLAT_SYMBOLPRINT_H */
