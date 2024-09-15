#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "token.h"

int stringToNum(char* string) {
	int value = 0;
	int iter;
	int times = 1;
	for (iter = 0; string[iter] != '\0'; iter++) {
	} 
	for (int i = iter - 1; i >= 0; i--) {
		value = value + (((int)string[i]) - '0') * times;
		times = times * 10;
	}
	return value;
}

int parseOperand(tokenizer* tzer, int *result) {
	token t;
	if (tokenize(tzer, &t)) {
		if (t.token_type == tokentype_Num) {
			printf("number: %s\n", t.text);
			*result = stringToNum(t.text);
		}
		else if (t.token_type == tokentype_Var) {
			printf("var: %s\n", t.text);
			*result = 0; // unsupported
		}
		else {
			printf("expected number/var/unary operator");
			exit(1);
		}
		return 1;
	}
	return 0;
}

int parsePrimaryExpression(tokenizer *tzer, int *result) {
	token t;
	if (tokenize(tzer, &t)) {
		int sign = 1;

		if (t.token_type == tokentype_Add) {
			printf("unary: %s\n", t.text);
			if (!tokenize(tzer, &t)) {
				printf("expected operand\n");
				exit(1);
			}
		}
		else if (t.token_type == tokentype_Sub) {
			sign = -1;
			printf("unary: %s\n", t.text);
			if (!tokenize(tzer, &t)) {
				printf("expected operand\n");
				exit(1);
			}
		}

		if (t.token_type == tokentype_Num) {
			printf("number: %s\n", t.text);
			*result = sign * stringToNum(t.text);
		}
		else if (t.token_type == tokentype_Var) {
			printf("var: %s\n", t.text);
			*result = 0; // unsupported
		}
		else {
			printf("expected number/var/unary operator");
			exit(1);
		}
		return 1;
	}
	return 0;
}

typedef enum binaryOperator {
	binaryOperator_Add,
	binaryOperator_Sub,
	binaryOperator_Mul,
	binaryOperator_Div,
}binaryOperator;

int parseBinaryOperator(tokenizer *tzer, binaryOperator *op) {
	token t;
	if (tokenize(tzer, &t)) {
		if (t.token_type == tokentype_Add) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Add;
		}
		else if (t.token_type == tokentype_Sub) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Sub;
		}
		else if (t.token_type == tokentype_Mul) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Mul;
		}
		else if (t.token_type == tokentype_Div) {
			printf("binary: %s\n", t.text);
			*op = binaryOperator_Div;
		}
		else {
			printf("expected binary operator");
			exit(1);
		}
		return 1;
	}
	return 0;
}

int evaluateExpression(int left, binaryOperator op, int right) {
	switch (op)
	{
		case binaryOperator_Add: return left + right;
		case binaryOperator_Sub: return left - right;
		case binaryOperator_Mul: return left * right;
		case binaryOperator_Div: return left / right;
	}
	return 0;
}

void subexpression() {


}

int main() {
	char input[] = "4*2-4/2/2-4";
	tokenizer tzer;
	token t;
	int left = 0;
	int size = strlen(input);
	char* input1 = input;
	tzer.start = input1;
	tzer.pos = 0;
	int right = 0;
	int hold = 1;
	int sign = 1;
	int subexp = 0;

	
}

