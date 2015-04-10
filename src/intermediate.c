#include <stdlib.h>

#include "intermediate.h"

struct instructions *create_instructions
()
{
        struct instructions *this = malloc(sizeof(struct instructions));
        this->quads = NULL;
        this->n_quads = 0;
        this->n_labels = 0;
        return this;
}

struct quad *create_quad_binary_assign
(struct quad_address *arg1, struct quad_address *arg2, struct quad_address *result, enum quad_op op)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_BINARY_ASSIGN;
        this->val.binary_assign.arg1 = arg1;
        this->val.binary_assign.arg2 = arg2;
        this->val.binary_assign.result = result;
        this->val.binary_assign.op = op;
        return this;
}

struct quad *create_quad_unary_assign
(struct quad_address *arg, struct quad_address *result, enum quad_op op)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_UNARY_ASSIGN;
        this->val.unary_assign.arg = arg;
        this->val.unary_assign.result = result;
        this->val.unary_assign.op = op;
        return this;
}

struct quad *create_quad_copy
(struct quad_address *arg, struct quad_address *result)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_COPY;
        this->val.copy.arg = arg;
        this->val.copy.result = result;
        return this;
}

struct quad *create_quad_label
(char *label)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_LABEL;
        this->val.label.label = label;
        return this;
}

struct quad *create_quad_unconditional_jump
(char *label)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_UNCONDITIONAL_JUMP;
        this->val.unconditional_jump.label = label;
        return this;
}

struct quad *create_quad_conditional_jump
(struct quad_address *arg, char *label)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_CONDITIONAL_JUMP;
        this->val.conditional_jump.arg = arg;
        this->val.conditional_jump.label = label;
        return this;
}

struct quad *create_quad_relational_jump
(struct quad_address *arg1, struct quad_address *arg2, enum quad_op op, char *label)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_RELATIONAL_JUMP;
        this->val.relational_jump.arg1 = arg1;
        this->val.relational_jump.arg2 = arg2;
        this->val.relational_jump.op = op;
        this->val.relational_jump.label = label;
        return this;
}

struct quad *create_quad_procedure_param
(struct quad_address *arg)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_PROCEDURE_PARAM;
        this->val.procedure_param.arg = arg;
        return this;
}

struct quad *create_quad_procedure_call
(char *label, unsigned int n_params)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_PROCEDURE_CALL;
        this->val.procedure_call.label = label;
        this->val.procedure_call.n_params = n_params;
        return this;
}

struct quad *create_quad_procedure_return
(struct quad_address *result)
{
        struct quad *this = malloc(sizeof(struct quad));
        this->type = QUAD_PROCEDURE_RETURN;
        this->val.procedure_return.result = result;
        return this;
}

struct quad_address *create_quad_address_name
(char *id)
{
        struct quad_address *this = malloc(sizeof(struct quad_address));
        this->type = ADDRESS_NAME;
        this->val.id = id;
        return this;
}

struct quad_address *create_quad_address_constant
(struct constant *constant)
{
        struct quad_address *this = malloc(sizeof(struct quad_address));
        this->type = ADDRESS_CONSTANT;
        this->val.constant = constant;
        return this;
}

struct quad_address *create_quad_address_temp
()
{
        static unsigned int n_temps = 0;
        struct quad_address *this = malloc(sizeof(struct quad_address));
        this->type = ADDRESS_TEMP;
        this->val.temp = ++n_temps;
        return this;
}

void add_instruction
(struct instructions *instructions, struct quad *quad)
{
        instructions->n_quads++;
        instructions->quads = realloc(instructions->quads, sizeof(struct quad *) * instructions->n_quads);
        instructions->quads[instructions->n_quads - 1] = quad;
}
