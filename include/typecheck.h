/* typecheck.h
 * Typechecking of abstract syntax tree and symbol table.
 * by Ryan Wilson-Perkin
 * for CIS4650W15 Compilers: Cflat Assignment
 */
#ifndef CFLAT_TYPECHECK_H
#define CFLAT_TYPECHECK_H

#include "ast.h"
#include "symbol.h"

void type_check_program(struct symbol_table *, struct program *);
void type_check_function_def_list(struct symbol_table *, struct function_def_list *);
void type_check_function_def(struct symbol_table *, struct function_def *);
void type_check_function_body(struct symbol_table *, struct symbol_table *, struct function_body *);
void type_check_function_body(struct symbol_table *, struct symbol_table *, struct function_body *);
void type_check_stmt_list(struct symbol_table *, struct symbol_table *, struct stmt_list *);
void type_check_stmt(struct symbol_table *, struct symbol_table *, struct stmt *);
void type_check_expr_stmt(struct symbol_table *, struct symbol_table *, struct expr_stmt *);
void type_check_compound_stmt(struct symbol_table *, struct symbol_table *, struct compound_stmt *);
void type_check_select_stmt(struct symbol_table *, struct symbol_table *, struct select_stmt *);
void type_check_iter_stmt(struct symbol_table *, struct symbol_table *, struct iter_stmt *);
void type_check_return_stmt(struct symbol_table *, struct symbol_table *, struct return_stmt *);
void type_check_function_arg_list(struct symbol_table *, struct symbol_table *, struct symbol_table *, struct function_arg_list *, struct function_param_list *);

#endif  /* CFLAT_TYPECHECK_H */
