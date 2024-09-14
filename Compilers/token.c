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
//lets dont change any logic and now just sort the input such that the multiply and divide will
//will be in the leftmost side
int main() {
	char input[] = "4/2*2*2";
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

	if (parsePrimaryExpression(&tzer, &left)) {
		while (1) {
			binaryOperator op;
			if (!parseBinaryOperator(&tzer, &op)) {
				break;
			}
			if (op == binaryOperator_Sub) {
				subexp++;
				sign = -1;
			}
			else if(op == binaryOperator_Add) {
				subexp++;
				sign = 1;
			}
			if (op == binaryOperator_Mul || op == binaryOperator_Div) {
				//what the  fuck should I right here 
				// when there is multiply or divide in the input then the code comes here
				//and i just wanted to caculate that statement and put in the right and after 
				// and then the operator will be parsed again so I will put the value of the 
				//the right in the left and then command will flow as usual.
				tzer.pos = tzer.pos - 2;
				if (!parseOperand(&tzer, &right)) {
					break;
				}
				if (subexp) {
					left = left - sign * right;
				}
				else {
					left = 0;
				}
				hold = right;
				tzer.pos++;
				if (!parseOperand(&tzer, &right)) {
					break;
				}
				hold = sign * evaluateExpression(hold, op, right);
				left = left + hold;
				continue;
			}
			if (!parseOperand(&tzer, &right)) {
				printf("expected primary expression\n");
				exit(1);
			}

			left = evaluateExpression(left, op, right);
		}
	} else {
		printf("empty input\n");
	}

	printf("result: %d\n", left);
}

